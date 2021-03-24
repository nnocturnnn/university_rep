package  second;

import java.util.ArrayList;
import java.util.List;
import java.util.Calendar;
import java.util.Objects;

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
    public TextField id;
    public TextField price;
    public TextField year;
    public TextField s1;
    public TextField mark;
    public TextField color;
    public TextField model;
    public TextField s2;
    public TextField s3;
    @FXML public Label arr;
    public List<Car> result;
    public List<Car> cars = new ArrayList<>();

    @FXML
    public void add() {
        cars.add(new CarBuilder()
        .withModel(model.getText())
        .withBrand(mark.getText())
        .withPrice(Double.parseDouble(price.getText()))
        .withColor(color.getText())
        .withYearOfIssue(Integer.parseInt(price.getText()))
        .withRegistrationNumber(id.getText())
        .build());
        
    }

    @FXML
    public void search1() throws IOException {
        String stri = "";
        result = CarService.filterByBrand(cars, s1.getText());
        for (Car car : result) {
            stri += car.toString() + "\n";
            OutputStream os = new FileOutputStream(new File("db.txt"), true);
            os.write(car.toString().getBytes(), 0, car.toString().length());
            os.close();
        }
        arr.setText(stri);
    }
    @FXML
    public void search2() {
        String stri = "";
        result = CarService.filterByModelAndLifespan(cars,  s1.getText(), Integer.parseInt(s2.getText()));
        for (Car car : result) {
            stri += car.toString() + "\n";
        }
        arr.setText(stri);
    }

    @FXML
    public void search3() {
        String stri = "";
        result = CarService.filterByYearAndMinPrice(cars, Integer.parseInt(s2.getText()), Double.parseDouble(s3.getText()));
        for (Car car : result) {
            stri += car.toString() + "\n";
        }
        arr.setText(stri);
    }
}
