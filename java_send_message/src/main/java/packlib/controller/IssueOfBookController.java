package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageBookBO;
import packlib.business.custom.ManageIssueBooksBO;
import packlib.business.custom.ManageMemberBO;
import packlib.dto.BookDTO;
import packlib.dto.IssueBooksDTO;
import packlib.dto.MemberDTO;
import packlib.view.util.IssueOfBookTM;
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

public class IssueOfBookController {
    @FXML
    private JFXTextField txtMemName;
    @FXML
    private Button btnSave;
    @FXML
    private Button btnDelete;
    @FXML
    private JFXTextField txtIssueDate;
    @FXML
    private JFXTextField txtBookID;
    @FXML
    private JFXTextField txtBookName;
    @FXML
    private JFXTextField txtMemID;
    @FXML
    private JFXTextField txtReturnDate;
    @FXML
    private TableView<IssueOfBookTM> tblIssueBook;
    @FXML
    private Label lblTitle;

    private ManageBookBO manageBookBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_BOOK);
    private ManageMemberBO manageMemberBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_MEMBER);
    private ManageIssueBooksBO manageIssueBooksBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_ISSUEBOOKS);

    public void initialize() throws SQLException {

        tblIssueBook.getColumns().get(0).setCellValueFactory(new PropertyValueFactory<>("book_id"));
        tblIssueBook.getColumns().get(1).setCellValueFactory(new PropertyValueFactory<>("member_id"));
        tblIssueBook.getColumns().get(2).setCellValueFactory(new PropertyValueFactory<>("issue_date"));
        tblIssueBook.getColumns().get(3).setCellValueFactory(new PropertyValueFactory<>("return_date"));

        List<IssueBooksDTO> issueBooksDB = manageIssueBooksBO.getIssueBooks();
        ObservableList<IssueBooksDTO> issueBooksDTOS = FXCollections.observableArrayList(issueBooksDB);
        ObservableList<IssueOfBookTM> tblItems = FXCollections.observableArrayList();
        for (IssueBooksDTO booksDTO : issueBooksDTOS) {
            tblItems.add(new IssueOfBookTM(booksDTO.getBook_id(), booksDTO.getMember_id(), booksDTO.getIssue_date(), booksDTO.getReturn_date()));
        }
        tblIssueBook.setItems(tblItems);

        tblIssueBook.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<IssueOfBookTM>() {
            @Override
            public void changed(ObservableValue<? extends IssueOfBookTM> observable, IssueOfBookTM oldValue, IssueOfBookTM SelectIssue) {
                if (SelectIssue == null) {
                    return;
                }

                txtIssueDate.setText(SelectIssue.getIssue_date());
                txtBookID.setText(SelectIssue.getBook_id());
                txtMemID.setText(SelectIssue.getMember_id());
                txtReturnDate.setText(SelectIssue.getReturn_date());
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
    private void clickSearch(ActionEvent actionEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/controls/SearchView.fxml"));
        Scene scene = new Scene(parent);
        Stage primaryStage = (Stage) lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.setTitle("Main Form");
        primaryStage.centerOnScreen();
    }

    @FXML
    private void ClickSave(ActionEvent actionEvent) throws SQLException {

        if (txtIssueDate.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Issue Date is empty", ButtonType.OK).showAndWait();
            txtIssueDate.requestFocus();
            return;
        } else if (txtBookID.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Book ID is empty", ButtonType.OK).showAndWait();
            txtBookID.requestFocus();
            return;
        } else if (txtBookName.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Book name is empty", ButtonType.OK).showAndWait();
            txtBookName.requestFocus();
            return;
        } else if (txtMemID.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Member ID is empty", ButtonType.OK).showAndWait();
            txtMemID.requestFocus();
            return;
        } else if (txtMemName.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Member name is empty", ButtonType.OK).showAndWait();
            txtMemName.requestFocus();
            return;
        } else if (txtReturnDate.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Return date is empty", ButtonType.OK).showAndWait();
            txtReturnDate.requestFocus();
            return;
        } else if(!isValidDate(txtIssueDate.getText())) {
            new Alert(Alert.AlertType.ERROR, "Invalid issue date", ButtonType.OK).showAndWait();
            txtIssueDate.requestFocus();
        } else if(!isValidDate(txtReturnDate.getText())) {
            new Alert(Alert.AlertType.ERROR, "Invalid return date", ButtonType.OK).showAndWait();
            txtReturnDate.requestFocus();
        }

        if (tblIssueBook.getSelectionModel().isEmpty()) {

            ObservableList<IssueOfBookTM> items = tblIssueBook.getItems();
            for (IssueOfBookTM issueOfBookTM : items) {
                if (issueOfBookTM.getMember_id().equals(txtMemID.getText())) {
                    new Alert(Alert.AlertType.ERROR, "This member have issue member list").showAndWait();
                    txtMemID.requestFocus();
                    return;
                }
            }

            IssueOfBookTM issueOfBookTM = new IssueOfBookTM(txtBookID.getText(), txtMemID.getText(), txtIssueDate.getText(), txtReturnDate.getText());
            tblIssueBook.getItems().add(issueOfBookTM);
            IssueBooksDTO issueBooksDTO = new IssueBooksDTO(txtBookID.getText(), txtMemID.getText(), txtIssueDate.getText(), txtReturnDate.getText());
            boolean result = manageIssueBooksBO.createIssueBooks(issueBooksDTO);

            if (result) {
                new Alert(Alert.AlertType.INFORMATION, "Book has been saved successfully", ButtonType.OK).showAndWait();
                tblIssueBook.scrollTo(issueOfBookTM);
                reset();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to save the book", ButtonType.OK).showAndWait();
            }

        } else {

            IssueOfBookTM selectedBooks = tblIssueBook.getSelectionModel().getSelectedItem();
            selectedBooks.setIssue_date(txtIssueDate.getText());
            selectedBooks.setBook_id(txtBookID.getText());
            selectedBooks.setMember_id(txtMemID.getText());
            selectedBooks.setReturn_date(txtReturnDate.getText());
            tblIssueBook.refresh();

            String member_id = tblIssueBook.getSelectionModel().getSelectedItem().getMember_id();

            boolean result = manageIssueBooksBO.updateIssueBooks(new IssueBooksDTO(txtBookID.getText(), txtMemID.getText(), txtIssueDate.getText(), txtReturnDate.getText()));

            if (result) {
                new Alert(Alert.AlertType.INFORMATION, "Issue details has been updated successfully", ButtonType.OK).showAndWait();
                reset();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to update the issue details", ButtonType.OK).showAndWait();
            }

        }

    }

    @FXML
    private void clickDelete(ActionEvent actionEvent) throws SQLException {

        Alert confirmMsg = new Alert(Alert.AlertType.CONFIRMATION, "Are you sure to delete this Issue details?", ButtonType.YES, ButtonType.NO);
        Optional<ButtonType> buttonType = confirmMsg.showAndWait();

        if (buttonType.get() == ButtonType.YES) {
            String selectedMember = tblIssueBook.getSelectionModel().getSelectedItem().getMember_id();

            tblIssueBook.getItems().remove(tblIssueBook.getSelectionModel().getSelectedItem());
            boolean result = manageIssueBooksBO.deleteIssueBooks(selectedMember);
            if (!result) {
                new Alert(Alert.AlertType.ERROR, "Failed to delete the issue details", ButtonType.OK).showAndWait();
            } else {
                reset();
            }
        }

    }

    public void FindBook(ActionEvent actionEvent) throws SQLException {

        String book_id = txtBookID.getText();
        BookDTO book = manageBookBO.findBook(book_id);

        if (book == null) {
            new Alert(Alert.AlertType.ERROR, "Invalid author ID", ButtonType.OK).showAndWait();
            txtBookID.clear();
            txtBookName.clear();
            txtBookID.requestFocus();
        } else {
            txtBookName.setText(book.getBook_title());
        }

    }

    public void FindMember(ActionEvent actionEvent) throws SQLException {
        String member_id = txtMemID.getText();
        MemberDTO member = manageMemberBO.findMember(member_id);

        if (member == null) {
            new Alert(Alert.AlertType.ERROR, "Invalid member ID", ButtonType.OK).showAndWait();
            txtMemID.clear();
            txtMemName.clear();
            txtMemID.requestFocus();
        } else {
            txtMemName.setText(member.getMember_name());
        }
    }

    public void reset() {
        txtIssueDate.clear();
        txtBookID.clear();
        txtBookName.clear();
        txtMemID.clear();
        txtMemName.clear();
        txtReturnDate.clear();
    }

    private boolean isValidDate(String input) {
        return input.matches("^\\d{4}-\\d{2}-\\d{2}$");
    }
}
