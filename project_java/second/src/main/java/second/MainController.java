package second;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import java.io.IOException;
import java.io.*;
import java.util.Random;

public class MainController  {
    String[] arry = {String.valueOf(getRandomNumberInRange(0, 1000)),String.valueOf(getRandomNumberInRange(0, 1000000)),String.valueOf(getRandomNumberInRange(0, 100000)),String.valueOf(getRandomNumberInRange(0, 100)),String.valueOf(getRandomNumberInRange(0, 1000000))};
    @FXML public Label arr;
    @FXML public Label arr2;
    String stri = "finish\n";
    @FXML
    public void print() throws IOException{
        int size = arry.length;
        int midl = 0;
        String stri2 = "start\n";
        for (String arg : arry) {
            midl += arg.length();
        }
        midl = midl / size;
        for (String str : arry) {
            if (str.length() > midl) {
                stri += str + " - " + Integer.toString(str.length()) + "\n";
            }
            stri2 +=  str + " - " + Integer.toString(str.length()) + "\n";
        }
        OutputStream os = new FileOutputStream(new File("db.txt"), true);
        os.write(stri.getBytes(), 0, stri.length());
        os.close();
        arr.setText(stri2);
        arr2.setText(stri);
    }

    private static int getRandomNumberInRange(int min, int max) {

        if (min >= max) {
            throw new IllegalArgumentException("max must be greater than min");
        }

        Random r = new Random();
        return r.nextInt((max - min) + 1) + min;
    }
}