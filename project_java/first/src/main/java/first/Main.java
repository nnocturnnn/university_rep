package first;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent parent = FXMLLoader.load(this.getClass().getResource("/Main.fxml"));
		Scene scene = new Scene(parent);
		primaryStage.show();
		primaryStage.setScene(scene);
		primaryStage.setTitle("First");
		primaryStage.centerOnScreen();
		primaryStage.resizableProperty();
	}
}

//public class Main {
//
//	public static void main(String[] args) {
//		LocalDate d=null;
//
//		ProgramGuide programGuide = new ProgramGuide(d.now());
//
//		programGuide.createTvChannel("1", LocalTime.of(8, 00), "New ");
//		programGuide.createTvChannel("1", LocalTime.of(8, 00), "Ukraine");
//		programGuide.createTvChannel("1", LocalTime.of(8, 30), "5C");
//
//		programGuide.receiveProgram("1", programGuide.getTvChannel());
//	}
//
//}