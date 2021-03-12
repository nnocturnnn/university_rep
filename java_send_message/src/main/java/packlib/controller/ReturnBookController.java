package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageIssueBooksBO;
import packlib.dto.IssueBooksDTO;
import com.jfoenix.controls.JFXTextField;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.SQLException;

public class ReturnBookController {
    @FXML
    private JFXTextField txtMemberID;
    @FXML
    private JFXTextField txtBookID;
    @FXML
    private JFXTextField txtIssueDate;
    @FXML
    private JFXTextField txtReturnDate;
    @FXML
    private Label lblTitle;
    private ManageIssueBooksBO manageIssueBooksBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_ISSUEBOOKS);

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
    private void clickSearchDetails(ActionEvent actionEvent) throws SQLException {
        String mem_ID = txtMemberID.getText();
        IssueBooksDTO issueBooks = manageIssueBooksBO.findIssueBooks(mem_ID);

        if (issueBooks == null) {
            new Alert(Alert.AlertType.ERROR, "Invalid member ID", ButtonType.OK).showAndWait();
            txtMemberID.clear();
            txtBookID.clear();
            txtIssueDate.clear();
            txtReturnDate.clear();
        } else {
            txtBookID.setText(issueBooks.getBook_id());
            txtReturnDate.setText(issueBooks.getReturn_date());
            txtIssueDate.setText(issueBooks.getIssue_date());
        }
    }

    @FXML
    private void clickReturn(ActionEvent actionEvent) throws SQLException {

        String mem_id = txtMemberID.getText();
        boolean result = manageIssueBooksBO.deleteIssueBooks(mem_id);
        if (!result) {
            new Alert(Alert.AlertType.ERROR, "Failed to return book", ButtonType.OK).showAndWait();
        } else {
            txtMemberID.clear();
            txtIssueDate.clear();
            txtReturnDate.clear();
            txtBookID.clear();
        }

    }
}
