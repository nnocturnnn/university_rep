package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageAuthorBO;
import packlib.business.custom.ManageBookBO;
import packlib.dto.AuthorDTO;
import packlib.dto.BookDTO;
import packlib.view.util.BookTM;
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
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.Optional;

public class AddBookController {
    @FXML
    private Button btnSave;
    @FXML
    private Button btnDelete;
    @FXML
    private JFXTextField txtBookID;
    @FXML
    private JFXTextField txtTitle;
    @FXML
    private JFXTextField txtAuthorName;
    @FXML
    private JFXTextField txtAvailable;
    @FXML
    private TableView<BookTM> tblBooks;
    @FXML
    private JFXTextField txtAuthorID;
    @FXML
    private Label lblTitle;

    private ManageBookBO manageBookBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_BOOK);
    private ManageAuthorBO manageAuthorBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_AUTHOR);

    public void initialize() throws SQLException {
        btnDelete.setDisable(true);
        btnSave.setDisable(true);

        txtBookID.setEditable(false);
        txtTitle.setEditable(false);
        txtAuthorID.setEditable(false);
        txtAuthorName.setEditable(false);
        txtAvailable.setEditable(false);

        tblBooks.getColumns().get(0).setCellValueFactory(new PropertyValueFactory<>("book_id"));
        tblBooks.getColumns().get(1).setCellValueFactory(new PropertyValueFactory<>("book_title"));
        tblBooks.getColumns().get(2).setCellValueFactory(new PropertyValueFactory<>("author_id"));
        tblBooks.getColumns().get(3).setCellValueFactory(new PropertyValueFactory<>("book_available"));

        List<BookDTO> bookDB = manageBookBO.getBook();
        ObservableList<BookDTO> bookDTOS = FXCollections.observableArrayList(bookDB);
        ObservableList<BookTM> tblItems = FXCollections.observableArrayList();
        for (BookDTO bookDTO : bookDTOS) {
            tblItems.add(new BookTM(bookDTO.getBook_id(), bookDTO.getBook_title(), bookDTO.getAuthor_id(), bookDTO.getBook_available()));
        }
        tblBooks.setItems(tblItems);

        tblBooks.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<BookTM>() {
            @Override
            public void changed(ObservableValue<? extends BookTM> observable, BookTM oldValue, BookTM selectedBook) {

                if (selectedBook == null) {
                    return;
                }
                btnDelete.setDisable(false);
                btnSave.setDisable(false);
                txtBookID.setEditable(true);
                txtTitle.setEditable(true);
                txtAuthorID.setEditable(true);
                txtAuthorName.setEditable(true);
                txtAvailable.setEditable(true);
                txtBookID.setText(selectedBook.getBook_id());
                txtTitle.setText(selectedBook.getBook_title());
                txtAuthorID.setText(selectedBook.getAuthor_id());
                txtAvailable.setText(selectedBook.getBook_available());
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
    private void clickAddAuthor(ActionEvent actionEvent) throws IOException {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/controls/AddAuthorView.fxml"));
        Scene scene = new Scene(parent);
        Stage primaryStage = (Stage) lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.setTitle("Add Author Form");
        primaryStage.centerOnScreen();
    }

    @FXML
    private void clickSave(ActionEvent actionEvent) throws SQLException {

        if (txtBookID.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Book ID is empty", ButtonType.OK).showAndWait();
            txtBookID.requestFocus();
            return;
        } else if (txtAuthorID.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Author ID is empty", ButtonType.OK).showAndWait();
            txtAuthorID.requestFocus();
            return;
        } else if (txtAuthorName.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Author Name is empty", ButtonType.OK).showAndWait();
            txtAuthorName.requestFocus();
            return;
        } else if(txtAvailable.getText().trim().isEmpty()) {
            new Alert(Alert.AlertType.ERROR, "Available is empty", ButtonType.OK).showAndWait();
            txtAvailable.requestFocus();
            return;
        }

        if(tblBooks.getSelectionModel().isEmpty()) {

            ObservableList<BookTM> items = tblBooks.getItems();
            for (BookTM bookTM : items) {
                if(bookTM.getBook_id().equals(txtBookID.getText())) {
                    new Alert(Alert.AlertType.ERROR, "Duplicate Book IDs are not allowed").showAndWait();
                    txtBookID.requestFocus();
                    return;
                }
            }

            BookTM bookTM = new BookTM(txtBookID.getText(), txtTitle.getText(), txtAuthorID.getText(), txtAvailable.getText());
            tblBooks.getItems().add(bookTM);

            BookDTO bookDTO = new BookDTO(txtBookID.getText(), txtTitle.getText(), txtAuthorID.getText(), txtAvailable.getText());
            boolean result = manageBookBO.createBook(bookDTO);

            if(result) {
                new Alert(Alert.AlertType.INFORMATION, "Book has been saved successfully", ButtonType.OK).showAndWait();
                tblBooks.scrollTo(bookTM);
                reset();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to save the book", ButtonType.OK).showAndWait();
                reset();
            }
        } else {

            BookTM selectedBook = tblBooks.getSelectionModel().getSelectedItem();
            selectedBook.setBook_id(txtBookID.getText());
            selectedBook.setBook_title(txtTitle.getText());
            selectedBook.setAuthor_id(txtAuthorID.getText());
            selectedBook.setBook_available(txtAvailable.getText());
            tblBooks.refresh();

            String selectedBookID = tblBooks.getSelectionModel().getSelectedItem().getBook_id();
            boolean result = manageBookBO.updateBook(new BookDTO(txtBookID.getText(), txtTitle.getText(), txtAuthorID.getText(), txtAvailable.getText()));

            if(result) {
                new Alert(Alert.AlertType.INFORMATION, "Book has been updated successfully", ButtonType.OK).showAndWait();
                reset();
            } else {
                new Alert(Alert.AlertType.ERROR, "Failed to update the book", ButtonType.OK).showAndWait();
                reset();
            }
        }


    }

    @FXML
    private void clickDelete(ActionEvent actionEvent) throws SQLException {

        Alert configMsg = new Alert(Alert.AlertType.INFORMATION, "Are you sure to delete this book?", ButtonType.YES, ButtonType.NO);
        Optional<ButtonType> buttonType = configMsg.showAndWait();

        if(buttonType.get() == ButtonType.YES) {
            String selectedBook = tblBooks.getSelectionModel().getSelectedItem().getBook_id();

            tblBooks.getItems().remove(tblBooks.getSelectionModel().getSelectedItem());
            boolean result = manageBookBO.deleteBook(selectedBook);
            if(!result) {
                new Alert(Alert.AlertType.ERROR, "Failed to delete the book", ButtonType.OK).showAndWait();
            }else{
                tblBooks.getSelectionModel().clearSelection();
            }
        }


    }

    @FXML
    private void clickAuthorID(KeyEvent keyEvent) {
    }

    @FXML
    private void enterAuthorID(ActionEvent actionEvent) throws SQLException {

        String author_id = txtAuthorID.getText();
        AuthorDTO author = manageAuthorBO.findAuthor(author_id);

        if (author == null) {
            new Alert(Alert.AlertType.ERROR, "Invalid author ID", ButtonType.OK).showAndWait();
            txtAuthorID.clear();
            txtAuthorName.clear();
            txtAuthorID.requestFocus();
        } else {
            txtAuthorName.setText(author.getAuthor_name());

        }
    }

    private void reset() {
        txtBookID.clear();
        txtTitle.clear();
        txtAuthorID.clear();
        txtAuthorName.clear();
        txtAvailable.clear();
    }

    @FXML
    private void clickAdd(ActionEvent actionEvent) {
        btnDelete.setDisable(false);
        btnSave.setDisable(false);
        txtBookID.setEditable(true);
        txtTitle.setEditable(true);
        txtAuthorID.setEditable(true);
        txtAuthorName.setEditable(true);
        txtAvailable.setEditable(true);
    }
}
