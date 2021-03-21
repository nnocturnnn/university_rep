package first;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;



public class Main {

	public static void main(String[] args) {
		LocalDate d=null;
		
		ProgramGuide programGuide = new ProgramGuide(d.now());
		
		programGuide.createTvChannel("1", LocalTime.of(8, 00), "New ");
		programGuide.createTvChannel("1", LocalTime.of(8, 00), "Ukraine");
		programGuide.createTvChannel("1", LocalTime.of(8, 30), "5C");
	
		programGuide.receiveProgram("1", programGuide.getTvChannel());
	}

}