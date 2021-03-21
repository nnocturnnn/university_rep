package fou;

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
    public void add() {
        Hour hour = new Hour();
        hour.setI_hout(Integer.parseInt(hours.getText()));
        Minute minute = new Minute();
        minute.setI_minute(Integer.parseInt(minutes.getText()));
        Time time = new Time(hour,minute);
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(time.toString().getBytes(), 0, time.toString().length());
        os.close();
        arr.setText(time.toString());
    }
}