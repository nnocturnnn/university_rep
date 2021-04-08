


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
import java.util.ArrayList;


public class ReadFileLineByLineUsingBufferedReader {

    public static void main(String[] args) {
        BufferedReader reader;
        System.out.print("Print file name: ");

        Scanner scan = new Scanner(System.in); // scan name file
        String myFile = scan.nextLine();
        ArrayList<String> lines = new ArrayList<String>(); // create ArList
        try {
            reader = new BufferedReader(new FileReader(myFile)); // create reader
            String line = reader.readLine();
            while (line != null) {  // read 1 line from file while file not end
                lines.add(line); // add line to list
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Not sorted array"); // print not sorted
        for(String lin : lines){
            System.out.print(lin + "   ");
        }
        System.out.println("\nSorted array"); // print sorted
        Collections.sort(lines); // sort list
        for(String lin : lines){
            System.out.print(lin + "   ");
        }

    }
}