/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thegame;

import java.util.ArrayList;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.scene.Scene;
import javafx.scene.input.KeyEvent;
import javafx.util.Duration;

/**
 *
 * @author beh01
 */
public class Controller {

    private Timeline timer;
    private View view;
    private Model model;

    public boolean up, down, left, right;
    
    public Controller(Scene scene, View view, Model model) {
        scene.addEventHandler(KeyEvent.KEY_PRESSED , (KeyEvent event) ->{
                switch (event.getCode()) {
                    case W:
                        up = true;
                        //view.update();
                        break;
                    case S: 
                        down = true;
                        break;
                    case A:  
                        left = true;
                        break;
                    case D: 
                        right = true;
                        break;
                }
        });

         scene.addEventHandler(KeyEvent.KEY_RELEASED , (KeyEvent event) ->{
                switch (event.getCode()) {
                    case W:
                        up = false;
                        view.update();
                        break;
                    case S: 
                        down = false;
                        break;
                    case A:  
                        left = false;
                        break;
                    case D: 
                        right = false;
                        break;
                }
        });
         
        timer = new Timeline(new KeyFrame(Duration.millis(30), (javafx.event.ActionEvent event) -> {
            synchronized (model) {
                
                if(up){
                this.model.move(0, -8);
                }
                if(down){
                this.model.move(0, 8);                           
                }
                if(left && model.border() != 2){    
                this.model.move(-8, 0);             
                }
                if(right && model.border() != 1){
                this.model.move(8, 0);               
                }
                
                ArrayList<ModelObject> toDelete = new ArrayList<>();
                model.getObjects().stream().map((object) -> {
                    object.process();
                    return object;
                }).filter((object) -> (object.isOutOfSpace())).forEachOrdered((object) -> {
                    toDelete.add(object);
                });
                
                
                model.getObjects().removeAll(toDelete);
            }
            view.update();
        }));
        timer.setCycleCount(Timeline.INDEFINITE);
        this.model = model;
        this.view = view;
    }

    public boolean isRunning() {
        return timer.getStatus() == Timeline.Status.RUNNING;
    }

    void stop() {
        timer.stop();
    }

    void start() {
        view.update();
        timer.play();
    }
}
