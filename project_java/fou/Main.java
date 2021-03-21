package fou;

public class Main {
    public static void main() {
        Hour hour = new Hour();
        hour.setI_hout(14);
        Minute minute = new Minute();
        minute.setI_minute(24);
        Time time = new Time(hour,minute);
        time.toString();
    }
}