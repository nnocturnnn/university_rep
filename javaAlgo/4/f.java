import java.util.ArrayList;

public class f {
    public static void main(String[] args) {
        ArrayList<Integer> num = new ArrayList<Integer>();
        num.add(50);
        num.add(23);
        num.add(54);
        num.add(64);
        num.add(123);
        num.add(98);
        System.out.print("Начальный список : ");
        for (int i : num) {
            System.out.print(i);
            System.out.print(" ");
        }
        int last = num.get(num.size()-1);
        int pre_last = num.get(num.size()-2);
        int a = pre_last + last;
        num.set(num.size()-1,a);
        num.set(num.size()-2,a);
        System.out.print("\nФинальный список : ");
        for (int i : num) {
            System.out.print(i);
            System.out.print(" ");
        }
    }
}


a ← list[last]
b ← list[pre-last]
a Σ b
list[last] ← a 
list[pre-last] ← b