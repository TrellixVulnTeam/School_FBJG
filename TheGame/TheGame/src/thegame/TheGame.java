/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thegame;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Button;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class TheGame extends Application {

    private Model model;
    private View view;
    private Controller controller;


    
    public TheGame() {
        model = new Model();
    }
        
    @Override
    public void start(Stage primaryStage) {

        AnchorPane basePane = new AnchorPane();
        Button btnStart = new Button();
        Button btnMaxMin = new Button();
        Button btnClose = new Button();
        btnStart.setText("Start game");
        btnMaxMin.setText("M");
        btnClose.setText("X");
        btnStart.setOnAction((ActionEvent event) -> {
            if (controller.isRunning()) {
                //action.stop();
                controller.stop();
                btnStart.setText("Start game");
            } else {
                model.initGame();
                controller.start();
                btnStart.setText("Stop game");
            }
        });
        
        btnMaxMin.setOnAction((ActionEvent event) -> {
            if (primaryStage.isFullScreen() == false) {
                primaryStage.setFullScreen(true);
                
            } else {
                primaryStage.setFullScreen(false);
            }
        });

        btnClose.setOnAction((ActionEvent event) -> {
            primaryStage.close();
        });
        
        basePane.getChildren().add(btnStart);
        AnchorPane.setTopAnchor(btnStart, 0.0);
        AnchorPane.setLeftAnchor(btnStart, 5.0);
        AnchorPane.setRightAnchor(btnStart, 62.0);
        
        basePane.getChildren().add(btnMaxMin);
        AnchorPane.setTopAnchor(btnMaxMin, 0.0);
        AnchorPane.setRightAnchor(btnMaxMin, 32.0);
        
        basePane.getChildren().add(btnClose);
        AnchorPane.setTopAnchor(btnClose, 0.0);
        AnchorPane.setRightAnchor(btnClose, 5.0);
        
        Pane root = new Pane();
        Canvas canvas = new Canvas(View.WIDTH, View.HEIGHT);
        root.getChildren().add(canvas);
        //canvas.scaleXProperty().bind(root.widthProperty().multiply(1.0 / View.WIDTH));
        //canvas.scaleYProperty().bind(root.heightProperty().multiply(1.0 / View.HEIGHT));
        canvas.translateXProperty().bind(root.widthProperty().subtract(View.WIDTH).divide(2));
        canvas.translateYProperty().bind(root.heightProperty().subtract(View.HEIGHT).divide(2));

        view = new View(canvas.getGraphicsContext2D(), model);
        
        canvas.addEventHandler(MouseEvent.MOUSE_MOVED, (MouseEvent event) -> {
            model.setCursor(event.getX(), event.getY());
            view.update();
        });
        
        canvas.addEventHandler(MouseEvent.MOUSE_PRESSED, (MouseEvent event) -> {
            if(event.getButton() == MouseButton.PRIMARY){
                model.fire(event.getX(), event.getY());
                view.update();    
            }
            if(event.getButton() == MouseButton.SECONDARY){
                
            }
        });

        canvas.addEventHandler(MouseEvent.MOUSE_DRAGGED, (MouseEvent event) -> {
            model.setCursor(event.getX(), event.getY());
            view.update();
        });

        basePane.getChildren().add(root);
        AnchorPane.setBottomAnchor(root, 0.0);
        AnchorPane.setLeftAnchor(root, 0.0);
        AnchorPane.setRightAnchor(root, 0.0);
        AnchorPane.setTopAnchor(root, 30.0);

        Scene scene = new Scene(basePane, 720, 720);
        primaryStage.setTitle("The Game");
        primaryStage.setScene(scene);
        primaryStage.setFullScreen(true);
        //primaryStage.setResizable(false);
        primaryStage.setFullScreenExitHint("");
        primaryStage.show();
        controller = new Controller(scene, view, model);
        
/*        
        scene.addEventHandler(KeyEvent.KEY_PRESSED , (KeyEvent event) ->{
                switch (event.getCode()) {
                    case W:
                        up = true;
                        view.update();
                        break;
                    case S: 
                        model.move(0, 5);
                        break;
                    case A:  
                        model.move(-5, 0);
                        break;
                    case D: 
                        model.move(5, 0);
                        break;
                }
        });

         scene.addEventHandler(KeyEvent.KEY_RELEASED , (KeyEvent event) ->{
                up = false;
        });
*/
        
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}
