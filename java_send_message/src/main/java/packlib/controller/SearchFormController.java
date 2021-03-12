package packlib.controller;

import packlib.business.BOFactory;
import packlib.business.custom.ManageAuthorBO;
import packlib.business.custom.ManageBookBO;
import packlib.dto.BookDTO;
import packlib.view.util.BookTM;
import com.jfoenix.controls.JFXTextField;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

public class SearchFormController {
    public TableView<BookTM> tblSearchBook;
    @FXML
    private Label lblTitle;
    @FXML
    private JFXTextField txtSearch;

    @FXML
    private ObservableList<BookTM> olBooks;

    private ManageBookBO manageBookBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_BOOK);
    private ManageAuthorBO manageAuthorBO = BOFactory.getInstance().getBO(BOFactory.BOTypes.MANAGE_AUTHOR);

    public void initialize() throws SQLException {
        tblSearchBook.getColumns().get(0).setCellValueFactory(new PropertyValueFactory<>("book_id"));
        tblSearchBook.getColumns().get(1).setCellValueFactory(new PropertyValueFactory<>("book_title"));
        tblSearchBook.getColumns().get(2).setCellValueFactory(new PropertyValueFactory<>("author_id"));
        tblSearchBook.getColumns().get(3).setCellValueFactory(new PropertyValueFactory<>("book_available"));



        List<BookDTO> bookDB = manageBookBO.getBook();
        ObservableList<BookDTO> bookDTOS = FXCollections.observableArrayList(bookDB);
        ObservableList<BookTM> tblItems = FXCollections.observableArrayList();
        for (BookDTO bookDTO : bookDTOS) {
            tblItems.add(new BookTM(bookDTO.getBook_id(), bookDTO.getBook_title(), bookDTO.getAuthor_id(), bookDTO.getBook_available()));
        }
        tblSearchBook.setItems(tblItems);

    }

    public void clickHome(MouseEvent mouseEvent) throws IOException {

        Parent parent = FXMLLoader.load(this.getClass().getResource("/controls/IssueOFBook.fxml"));
        Scene scene = new Scene(parent);
        Stage primaryStage = (Stage)lblTitle.getScene().getWindow();
        primaryStage.setScene(scene);
        primaryStage.show();
        primaryStage.setTitle("Main Form");
        primaryStage.centerOnScreen();
    }
    @FXML
    private void clickSearch(KeyEvent keyEvent) {
        ObservableList<BookTM> tempList = FXCollections.observableArrayList();
//        for (OrderTM olOrder : olOrders) {
//            if(olOrder.getOrderId().startsWith(txtSearch.getText())){
//                tempList.add(olOrder);
//            }
//        }
//        tblOrderDetails.setItems(tempList);


        
    }
}
