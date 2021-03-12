package com.ijse.sys.controller;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;

public class MainFormController {
    @FXML
    private Label lblTitle;

    @FXML
    private void btnUser(MouseEvent mouseEvent) {
    }

    @FXML
    private void ClickAddMember(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/com/ijse/sys/view/AddMemberView.fxml"));
        Scene scene = new Scene(parent);

        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.centerOnScreen();
        primaryStage.setTitle("Add Member Form");
    }

    @FXML
    private void ClickAddBook(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/com/ijse/sys/view/AddBookView.fxml"));
        Scene scene = new Scene(parent);

        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.centerOnScreen();
        primaryStage.setTitle("Add Book Form");
    }

    @FXML
    private void ClickBrroweBook(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/com/ijse/sys/view/IssueOFBook.fxml"));
        Scene scene = new Scene(parent);

        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.centerOnScreen();
        primaryStage.setTitle("Issue of Book");
    }

    @FXML
    private void ClickReturnBook(MouseEvent mouseEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/com/ijse/sys/view/ReturnBookView.fxml"));
        Scene scene = new Scene(parent);

        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.centerOnScreen();
        primaryStage.setTitle("Return Book");
    }
}
