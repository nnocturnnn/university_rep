package thread2;

public class Task { // псевдозадание 
    public Integer timeToComplete; // время его выполнения
    public Integer id;

    Task(Integer id, Integer timeToComplete) {
        this.id = id;
        this.timeToComplete = timeToComplete; 
    }
}