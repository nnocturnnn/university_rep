package packlib.scenes;

import javafx.scene.Scene;
import javafx.stage.Stage;
import packlib.LibMain;

public abstract class AbstractScene implements InterfaceScene {
    protected Scene scene = null;

    public void setScene() {
        Stage primaryStage = LibMain.getPrimaryStage();
        primaryStage.setScene(scene);
    }

    public Scene getScene() {
        return scene;
    }
}