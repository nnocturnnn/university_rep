package second;

public class Numb {
    public void run(String[] args) {
        int size = args.length;
        int midl = 0;
        for (String arg : args) {
            midl += arg.length();
        }
        midl = midl / size;
        for (String arg : args) {
            if (arg.length() > midl) {
                System.out.print(arg + " ");
                System.out.println(arg.length());
            }
        }
    }
}