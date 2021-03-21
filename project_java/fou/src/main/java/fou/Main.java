package fou;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent parent = FXMLLoader.load(this.getClass().getResource("/4.fxml"));
        Scene scene = new Scene(parent);
        primaryStage.show();
        primaryStage.setScene(scene);
        primaryStage.setTitle("Four");
        primaryStage.centerOnScreen();
        primaryStage.resizableProperty();
    }
}