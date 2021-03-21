package second;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import java.io.*;

public class MainController {
    String[] arr = {"3242","3242","32442","213"};
    @FXML public Label arr;
    @FXML
    public void print() {
        String stri;
        for (String str : arr) {
            stri += str + "\n";
        }
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(stri.getBytes(), 0, stri.length());
        os.close();
    }
}