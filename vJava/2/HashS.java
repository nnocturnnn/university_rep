


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.ArrayList;


public class ReadFileLineByLineUsingBufferedReader {

    public static void main(String[] args) {
        BufferedReader reader;
        System.out.print("Print file name: ");

        Scanner scan = new Scanner(System.in); // read file name
        String myFile = scan.nextLine();
        HashSet<String> h = new HashSet<String>(); // create HashSet
        try {
            reader = new BufferedReader(new FileReader(myFile));
            String line = reader.readLine(); // read file by line
            while (line != null) {
                String [] arrline = line.split(" "); // split line on wold
                for(String l : arrline) { // add word in hashset
                    h.add(l);
                }
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        for(String lin : h) { // print hashset
            System.out.print(lin + "   ");
        }

    }
}