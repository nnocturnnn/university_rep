package first;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;

import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.List;
import java.io.*;
import java.util.*;

public class MainController {
    public TextField chanel;
    public TextField time;
    public TextField program;
    public TextField search_f;
    @FXML public Label arr;
    LocalDate d=null;
    ProgramGuide programGuide = new ProgramGuide(d.now());

    @FXML
    public void add() throws IOException {
        String[] words = time.getText().split(":");
        String str = chanel.getText() + " " + time.getText() + " " + program.getText() + "\n";
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(str.getBytes(), 0, str.length());
        os.close();
        programGuide.createTvChannel(chanel.getText(), LocalTime.of(Integer.parseInt(words[0]),Integer.parseInt(words[1])),program.getText());
    }

    @FXML
    public void search() {
        String stri = "";
        List<String> listy = programGuide.receiveProgram(search_f.getText(), programGuide.getTvChannel());
        for (String str : listy) {
            stri += str + "\n";
        }
        arr.setText(stri);
    }
}