package  thirst;

import java.util.ArrayList;
import java.util.List;
import java.util.Calendar;
import java.util.Objects;

import static java.util.stream.Collectors.toList;

public class Main {
    public static void main(String[] args) {

        List<Car> cars = new ArrayList<>();

        cars.add(new CarBuilder()
                .withModel("Tiida")
                .withBrand("Nissan")
                .withPrice(3999.90)
                .withColor("black")
                .withYearOfIssue(2008)
                .withRegistrationNumber("5530KT7")
                .build());

        cars.add(new CarBuilder()
                .withModel("Tiida")
                .withBrand("Nissan")
                .withPrice(5694.6)
                .build());

        cars.add(new CarBuilder()
                .withModel("Almera")
                .withBrand("Nissan")
                .withColor("black")
                .withYearOfIssue(1998)
                .build());

        cars.add(new CarBuilder()
                .withBrand("Lexus")
                .withPrice(9999)
                .withColor("white")
                .withYearOfIssue(2010)
                .withRegistrationNumber("5890KT7")
                .build());

        cars.add(new CarBuilder()
                .withBrand("Lexus")
                .withPrice(4500.0)
                .withColor("white")
                .withYearOfIssue(2008)
                .withRegistrationNumber("5890KT7")
                .build());

        List<Car> result;

        System.out.println("a) список автомобилей заданной марки: ");
        result = CarService.filterByBrand(cars, "Nissan");
        printResultList(result);

        System.out.println("b) список автомобилей заданной модели, которые эксплуатируются больше n лет;");
        result = CarService.filterByModelAndLifespan(cars, "Tiida", 5);
        printResultList(result);

        System.out.println("c) список автомобилей заданного года выпуска, цена которых больше указанной.");
        result = CarService.filterByYearAndMinPrice(cars, 2008, 3500.0);
        printResultList(result);
    }

    private static void printResultList(List<Car> result) {
        if (result.isEmpty()) {
            System.out.println("No results");
        } else {
            for (Car car : result) {
                System.out.println(car.toString());
            }
        }
    }
}

