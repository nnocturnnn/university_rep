package second;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import java.io.IOException;
import java.io.*;
import java.util.Random;

public class MainController  {
    String[] arry = {};
    @FXML public Label arr;
    String stri = "";
    @FXML
    public void print() throws IOException{ 
        for (int i = 0; i < 5; i++) {
            arry[i] = String.valueOf(getRandomNumberInRange(0, 1000000));
        }
        for (String str : arry) {
            stri += str + " - " + Integer.toString(str.length()) + "\n";
        }
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(stri.getBytes(), 0, stri.length());
        os.close();
        arr.setText(stri);
    }

    private static int getRandomNumberInRange(int min, int max) {

        if (min >= max) {
            throw new IllegalArgumentException("max must be greater than min");
        }

        Random r = new Random();
        return r.nextInt((max - min) + 1) + min;
    }
}