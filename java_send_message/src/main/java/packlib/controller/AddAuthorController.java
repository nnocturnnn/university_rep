package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageAuthorBO;
import packlib.dto.AuthorDTO;
import packlib.view.util.AuthorTM;
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

public class AddAuthorController {
    @FXML
    private Button btnSave;
    @FXML
    private Button btnDelete;
    @FXML
    private JFXTextField txtAuthorId;
    @FXML
    private JFXTextField txtAuthorName;
    @FXML
    private TableView<AuthorTM> tblAuthor;
    @FXML
    private Label lblTitle;

    private ManageAuthorBO manageAuthorBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_AUTHOR);


    public void initialize() throws SQLException {

        txtAuthorName.setEditable(false);
        txtAuthorId.setEditable(false);
        btnDelete.setDisable(true);
        btnSave.setDisable(true);


        tblAuthor.getColumns().get(0).setCellValueFactory(new PropertyValueFactory<>("author_id"));
        tblAuthor.getColumns().get(1).setCellValueFactory(new PropertyValueFactory<>("author_name"));


        List<AuthorDTO> authorDB = manageAuthorBO.getAuthor();
        ObservableList<AuthorDTO> authorDTOS = FXCollections.observableArrayList(authorDB);
        ObservableList<AuthorTM> tblItems = FXCollections.observableArrayList();
        for (AuthorDTO authorDTO : authorDTOS) {
            tblItems.add(new AuthorTM(authorDTO.getAuthor_id(), authorDTO.getAuthor_name()));
        }
        tblAuthor.setItems(tblItems);

        tblAuthor.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<AuthorTM>() {
            @Override
            public void changed(ObservableValue<? extends AuthorTM> observable, AuthorTM oldValue, AuthorTM selectAuthor) {
                if(selectAuthor == null) {
                    return;
                }

                btnDelete.setDisable(false);
                btnSave.setDisable(false);
                txtAuthorName.setEditable(true);
                txtAuthorId.setText(selectAuthor.getAuthor_id());
                txtAuthorName.setText(selectAuthor.getAuthor_name());
            }
        });

    }

    @FXML
    private void clickBack(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/controls/AddBookView.fxml"));
        Scene scene = new Scene(parent);
        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.setTitle("Add Book Form");
        primaryStage.centerOnScreen();
    }

    @FXML
    private void clickSave(ActionEvent actionEvent) throws SQLException {

        if(txtAuthorId.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Author ID is empty!", ButtonType.OK).showAndWait();
            txtAuthorId.requestFocus();
            return;
        } else if(txtAuthorName.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Author name is empty!", ButtonType.OK).showAndWait();
            txtAuthorName.requestFocus();
            return;
        }

        if(tblAuthor.getSelectionModel().isEmpty()) {
            ObservableList<AuthorTM> items = tblAuthor.getItems();
            for (AuthorTM authorTM : items) {
                if(authorTM.getAuthor_id().equals(txtAuthorId.getText())) {
                    new Alert(Alert.AlertType.ERROR, "Duplicate Author IDs are not allowed").showAndWait();
                    txtAuthorId.requestFocus();
                    return;
                }
            }

            AuthorTM authorTM = new AuthorTM(txtAuthorId.getText(), txtAuthorName.getText());
            tblAuthor.getItems().add(authorTM);
            AuthorDTO authorDTO = new AuthorDTO(txtAuthorId.getText(), txtAuthorName.getText());
            boolean result = manageAuthorBO.createAuthor(authorDTO);

            if(result) {
                new Alert(Alert.AlertType.INFORMATION, "Author has been saved successfully", ButtonType.OK).showAndWait();
                txtAuthorName.clear();
                txtAuthorId.clear();
                tblAuthor.scrollTo(authorTM);
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to save the customer", ButtonType.OK).showAndWait();
            }
        } else {
            AuthorTM selectedAuthor = tblAuthor.getSelectionModel().getSelectedItem();
            selectedAuthor.setAuthor_id(txtAuthorId.getText());
            selectedAuthor.setAuthor_name(txtAuthorName.getText());
            tblAuthor.refresh();

            String selectedAuthorID = tblAuthor.getSelectionModel().getSelectedItem().getAuthor_id();

            boolean result = manageAuthorBO.updateAuthor(new AuthorDTO(txtAuthorId.getText(),
                    txtAuthorName.getText()));

            if(result) {
                new Alert(Alert.AlertType.INFORMATION, "Author has been updated successfully", ButtonType.OK).showAndWait();
                txtAuthorId.clear();
                txtAuthorName.clear();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to update the author", ButtonType.OK).showAndWait();
            }
        }
    }

    @FXML
    private void clickDelete(ActionEvent actionEvent) throws SQLException {
        Alert confirmMsg = new Alert(Alert.AlertType.CONFIRMATION, "Are you sure to delete this author?", ButtonType.YES, ButtonType.NO);
        Optional<ButtonType> buttonType = confirmMsg.showAndWait();

        if(buttonType.get() == ButtonType.YES) {
            String selectedAuthor = tblAuthor.getSelectionModel().getSelectedItem().getAuthor_id();

            tblAuthor.getItems().remove(tblAuthor.getSelectionModel().getSelectedItem());
            boolean result = manageAuthorBO.deleteAuthor(selectedAuthor);
            if(!result) {
                new Alert(Alert.AlertType.ERROR, "Failed to delete the author", ButtonType.OK).showAndWait();
            }
            else{
                txtAuthorId.clear();
                txtAuthorName.clear();
            }
        }
    }

    @FXML
    private void clickAdd(ActionEvent actionEvent) {
        txtAuthorId.clear();
        txtAuthorName.clear();
        txtAuthorName.setEditable(true);
        txtAuthorId.setEditable(true);
        btnSave.setDisable(false);
        btnDelete.setDisable(false);
    }
}
