
import java.util.ArrayList;
import java.util.List;
import java.util.Calendar;
import java.util.Objects;

import static java.util.stream.Collectors.toList;

public class Runner {
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

public class CarBuilder {

    private Car car = new Car();

    private String brand = "";
    private String model = "";
    private int yearOfIssue = 0;
    private String color = "";
    private double price = 0;
    private String registrationNumber = "";

    private static long idCounter = 0;

    public CarBuilder withBrand(String brand){
        this.brand = brand;
        return this;
    }

    public CarBuilder withModel(String model){
        this.model = model;
        return this;
    }

    public CarBuilder withYearOfIssue(int yearOfIssue){
        this.yearOfIssue = yearOfIssue;
        return this;
    }

    public CarBuilder withColor(String color){
        this.color = color;
        return this;
    }

    public CarBuilder withPrice(double price){
        this.price = price;
        return this;
    }

    public CarBuilder withRegistrationNumber(String registrationNumber){
        this.registrationNumber = registrationNumber;
        return this;
    }

    public Car build(){
        car.setId(idCounter++);
        car.setBrand(brand);
        car.setModel(model);
        car.setColor(color);
        car.setYearOfIssue(yearOfIssue);
        car.setPrice(price);
        car.setRegistrationNumber(registrationNumber);
        return car;
    }

}

import java.util.Objects;

public class Car {

    private long id;
    private String brand;
    private String model;
    private int yearOfIssue;
    private String color;
    private double price;
    private String registrationNumber;

    public Car() {
    }

    public Car(String brand, String model, int yearOfIssue, String color, double price, String registrationNumber) {
        this.brand = brand;
        this.model = model;
        this.yearOfIssue = yearOfIssue;
        this.color = color;
        this.price = price;
        this.registrationNumber = registrationNumber;
    }

    public Car(String brand, String model, double price) {
        this.brand = brand;
        this.model = model;
        this.price = price;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getYearOfIssue() {
        return yearOfIssue;
    }

    public void setYearOfIssue(int yearOfIssue) {
        this.yearOfIssue = yearOfIssue;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getRegistrationNumber() {
        return registrationNumber;
    }

    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Car car = (Car) o;
        return id == car.id &&
                yearOfIssue == car.yearOfIssue &&
                Double.compare(car.price, price) == 0 &&
                Objects.equals(brand, car.brand) &&
                Objects.equals(model, car.model) &&
                Objects.equals(color, car.color) &&
                Objects.equals(registrationNumber, car.registrationNumber);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, brand, model, yearOfIssue, color, price, registrationNumber);
    }

    @Override
    public String toString() {
        return "Car{" +
                "id=" + id +
                ", brand='" + brand + '\'' +
                ", model='" + model + '\'' +
                ", yearOfIssue=" + yearOfIssue +
                ", color='" + color + '\'' +
                ", price=" + price +
                ", registrationNumber='" + registrationNumber + '\'' +
                '}';
    }
}