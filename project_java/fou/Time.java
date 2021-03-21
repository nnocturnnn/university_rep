package fou;

public class Time {
    int hour;
    int minute;


    public Time(Hour hour, Minute minute) {
        if (hour.getI_hout() >= 1 && hour.getI_hout() <= 23)
            this.hour = hour.getI_hout();
        else
            this.hour = 0;
        if (minute.getI_minute() >= 0 && minute.getI_minute() <= 59)
            this.minute = minute.getI_minute();
        else
            this.minute = 0;
    }


    public String toString() {
        String s = "";
        if (hour < 10 && minute < 10)
            s = "0" + hour + "0" + minute;
        else if (hour < 10 && minute > 10)
            s = "0" + hour + minute;
        else if (hour > 10 && minute < 10)
            s = hour + "0" + minute;
        else if (hour > 10 && minute > 10)
            s = hour + "" + minute;
        else if (hour == 0)
            s = "0" + hour + minute;
        else if (minute == 0)
            s = hour + "0" + minute;

        return s;

    }

    public String convert() {
        String c = "";

        if (hour > 11) {
            if (hour == 12) {
                c = hour + ":" + minute + " PM";
            }
            if (hour > 12) {
                c = (hour - 12) + ":" + minute + " PM";
            }
        } else if (hour == 0) {
            c = (hour + 12) + ":" + minute + " AM";
        } else
            c = hour + ":" + minute + " AM";


        if (minute < 10) {
            c = c.substring(0, c.length() - 4) + "0" + minute + " " + c.substring(c.length() - 2, c.length());
        }
        return c;
    }

    public void increment() {
        if (hour == 23 && minute == 59) {
            hour = 0;
            minute = 0;
        } else {
            minute++;
            if (minute == 60) {
                hour++;
                minute = 0;
            } else if (hour == 24)
                hour = 0;
        }
    }
}