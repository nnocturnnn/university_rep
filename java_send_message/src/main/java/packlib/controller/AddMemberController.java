package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageMemberBO;
import packlib.dto.MemberDTO;
import packlib.view.util.MemberTM;
import com.jfoenix.controls.JFXTextField;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.Optional;

public class AddMemberController {
    @FXML
    private Button btnSave;
    @FXML
    private Button btnDelete;
    @FXML
    private JFXTextField txtName;
    @FXML
    private JFXTextField txtAddress;
    @FXML
    private JFXTextField txtContactNo;
    @FXML
    private JFXTextField txtMemberID;
    @FXML
    private RadioButton cmbStudent;
    @FXML
    private ToggleGroup Member;
    @FXML
    private RadioButton cmbTeacher;
    @FXML
    private RadioButton cmbOther;
    @FXML
    private TableView<MemberTM> tblMember;
    @FXML
    private Label lblTitle;

    private ManageMemberBO manageMemberBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_MEMBER);

    public void initialize() throws SQLException {
        txtName.setEditable(false);
        txtMemberID.setEditable(false);
        txtAddress.setEditable(false);
        txtContactNo.setEditable(false);
        btnDelete.setDisable(true);
        btnSave.setDisable(true);



        cmbTeacher.setUserData("Teacher");
        cmbStudent.setUserData("Student");
        cmbOther.setUserData("Other");

        tblMember.getColumns().get(0).setCellValueFactory(new PropertyValueFactory<>("member_id"));
        tblMember.getColumns().get(1).setCellValueFactory(new PropertyValueFactory<>("member_name"));
        tblMember.getColumns().get(2).setCellValueFactory(new PropertyValueFactory<>("member_address"));
        tblMember.getColumns().get(3).setCellValueFactory(new PropertyValueFactory<>("member_type"));
        tblMember.getColumns().get(4).setCellValueFactory(new PropertyValueFactory<>("member_contactNo"));

        List<MemberDTO> memberDB = manageMemberBO.getMember();
        ObservableList<MemberDTO> memberDTOS = FXCollections.observableArrayList(memberDB);
        ObservableList<MemberTM> tblItems = FXCollections.observableArrayList();
        for (MemberDTO memberDTO : memberDTOS) {
            tblItems.add(new MemberTM(memberDTO.getMember_id(), memberDTO.getMember_name(), memberDTO.getMember_address(), memberDTO.getMember_type(), memberDTO.getMember_contactNo()));
        }

        tblMember.setItems(tblItems);

        tblMember.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<MemberTM>() {
            @Override
            public void changed(ObservableValue<? extends MemberTM> observable, MemberTM oldValue, MemberTM selectedMember) {
                if (selectedMember == null) {
                    return;
                }

                txtMemberID.setText(selectedMember.getMember_id());
                txtName.setText(selectedMember.getMember_name());
                txtAddress.setText(selectedMember.getMember_address());
                txtContactNo.setText(selectedMember.getMember_contactNo());

                //txtMemberID.setEditable(true);
                txtName.setEditable(true);
                txtAddress.setEditable(true);
                txtContactNo.setEditable(true);

                btnDelete.setDisable(false);
                btnSave.setDisable(false);
            }
        });
    }

    @FXML
    private void clickHome(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/controls/MainFormView.fxml"));
        Scene scene = new Scene(parent);
        Stage primaryStage = (Stage) lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.setTitle("Main Form");
        primaryStage.centerOnScreen();
    }

    @FXML
    private void clickSave(ActionEvent actionEvent) throws SQLException {
        if (txtMemberID.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Member ID is empty!", ButtonType.OK).showAndWait();
            txtMemberID.requestFocus();
            return;
        } else if (txtName.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Name is empty!", ButtonType.OK).showAndWait();
            txtName.requestFocus();
            return;
        } else if (!Member.getSelectedToggle().isSelected()) {
            new Alert(Alert.AlertType.ERROR, "Please select member type!", ButtonType.OK).showAndWait();
            return;
        } else if (txtContactNo.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Contact No is empty!", ButtonType.OK).showAndWait();
            txtContactNo.requestFocus();
            return;
        }

        if (tblMember.getSelectionModel().isEmpty()) {

            ObservableList<MemberTM> items = tblMember.getItems();
            for (MemberTM memberTM : items) {
                if (memberTM.getMember_id().equals(txtMemberID.getText())) {
                    new Alert(Alert.AlertType.ERROR, "Duplicate Customer IDs are not allowed", ButtonType.OK).showAndWait();
                    txtMemberID.requestFocus();
                    return;
                }
            }

            MemberTM memberTM = new MemberTM(txtMemberID.getText(), txtName.getText(), txtAddress.getText(), Member.getSelectedToggle().getUserData().toString(), txtContactNo.getText());
            tblMember.getItems().add(memberTM);
            MemberDTO memberDTO = new MemberDTO(txtMemberID.getText(), txtName.getText(), txtAddress.getText(), Member.getSelectedToggle().getUserData().toString(), txtContactNo.getText());
            boolean result = manageMemberBO.createMember(memberDTO);

            if (result) {
                new Alert(Alert.AlertType.INFORMATION, "Member has been saved successfully", ButtonType.OK).showAndWait();
                txtMemberID.clear();
                txtName.clear();
                txtAddress.clear();
                txtContactNo.clear();
                tblMember.scrollTo(memberTM);
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to save the member", ButtonType.OK).showAndWait();
            }
        } else {
            MemberTM selectedMember = tblMember.getSelectionModel().getSelectedItem();
            selectedMember.setMember_id(txtMemberID.getText());
            selectedMember.setMember_name(txtName.getText());
            selectedMember.setMember_address(txtAddress.getText());
            selectedMember.setMember_type(Member.getSelectedToggle().getUserData().toString());
            selectedMember.setMember_contactNo(txtContactNo.getText());
            tblMember.refresh();

            String selectedMember_id = tblMember.getSelectionModel().getSelectedItem().getMember_id();
            boolean result = manageMemberBO.updateMember(new MemberDTO(txtMemberID.getText(), txtName.getText(), txtAddress.getText(), Member.getSelectedToggle().getUserData().toString(),
                    txtContactNo.getText()));

            if (result) {
                new Alert(Alert.AlertType.INFORMATION, "Member has been updated successfully", ButtonType.OK).showAndWait();
                txtMemberID.clear();
                txtName.clear();
                txtAddress.clear();
                txtContactNo.clear();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to update the member", ButtonType.OK).showAndWait();
            }

        }

    }

    @FXML
    private void clickDelete(ActionEvent actionEvent) throws SQLException {

        if (tblMember.getSelectionModel().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Please select member", ButtonType.OK).showAndWait();
        } else {
            Alert configMsg = new Alert(Alert.AlertType.CONFIRMATION, "Are you sure to delete this member?", ButtonType.YES, ButtonType.NO);
            Optional<ButtonType> buttonType = configMsg.showAndWait();

            if (buttonType.get() == ButtonType.YES) {
                String selectedMember = tblMember.getSelectionModel().getSelectedItem().getMember_id();
                boolean result = manageMemberBO.deleteMember(selectedMember);
                if (!result) {
                    new Alert(Alert.AlertType.ERROR, "Failed to delete the member", ButtonType.OK).showAndWait();
                } else {
                    txtMemberID.clear();
                    txtContactNo.clear();
                    txtName.clear();
                    txtAddress.clear();
                    tblMember.refresh();
                }
            }

        }
    }

    public void clickAdd(ActionEvent actionEvent) {
        txtMemberID.setEditable(true);
        txtName.setEditable(true);
        txtAddress.setEditable(true);
        txtContactNo.setEditable(true);
        txtMemberID.clear();
        txtName.clear();
        txtAddress.clear();
        txtContactNo.clear();
        btnSave.setDisable(false);
        btnDelete.setDisable(false);
    }
}
