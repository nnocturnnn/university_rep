package fif;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import java.io.*;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;

public class MainController {
    public TextField hours;
    public TextField minutes;
    @FXML public Label arr;
    @FXML
    public void add() throws IOException {
        DrawingNotebook dr = new DrawingNotebook();
        dr.setType(hours.getText());
        dr.setCoverColour(minutes.getText());
        String dr_s = dr.toSring();
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(dr_s.getBytes(), 0, dr_s.length());
        os.close();
        arr.setText(dr_s);
    }
}