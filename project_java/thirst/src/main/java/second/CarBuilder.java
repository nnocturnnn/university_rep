package second;

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
