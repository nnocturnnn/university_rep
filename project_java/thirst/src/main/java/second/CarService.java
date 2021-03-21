package thirst;

import java.util.ArrayList;
import java.util.List;
import java.util.Calendar;
import java.util.Objects;

public class CarService {

    private static final int CURRENT_YEAR = Calendar.getInstance().get(Calendar.YEAR);

    public static List<Car> filterByBrand(List<Car> cars, String brand){
        return cars.stream()
                .filter(car -> car.getBrand().equals(brand))
                .collect(toList());
    }

    public static List<Car> filterByModelAndLifespan(List<Car> cars, String model, int lifespan){
        return cars.stream()
                .filter(car -> car.getModel().equals(model))
                .filter(car -> (CURRENT_YEAR - car.getYearOfIssue()) > (lifespan))
                .collect(toList());
    }

    public static List<Car> filterByYearAndMinPrice(List<Car> cars, int year, double minPrice){
        return cars.stream()
                .filter(car -> car.getYearOfIssue() == (year))
                .filter(car -> car.getPrice() > minPrice)
                .collect(toList());
    }

}
