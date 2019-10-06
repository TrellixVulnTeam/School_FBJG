/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thegame;

import java.util.ArrayList;
import javafx.geometry.Point2D;

/**
 *
 * @author beh01
 */
public class Model {

    private final ArrayList<ModelObject> objects = new ArrayList<>();
    private ModelObject tank;

    public ArrayList<ModelObject> getObjects() {
        return this.objects;
    }

    public Model() {

    }

    public synchronized void setCursor(double x, double y) {
        Point2D mousePoint = new Point2D(x, y);
        if (tank != null) {
            tank.setDirectionToPoint(mousePoint);
        }
    }

    public synchronized void move(double x, double y) {
        Point2D mousePoint = new Point2D(x, y);
        if (tank != null) {
            tank.move(x, y);
        }
    }
    
    public synchronized int border(){
        Point2D position;
        position = tank.getPosition();
        if(position.getX() > View.WIDTH-50){
            return 1;
        }else if(position.getX() < 50){
            return 2;
        }else{
            return 3;
        }
            
    }
    
    public synchronized void initGame() {
        objects.clear();
        Point2D center = new Point2D(View.WIDTH / 2, View.HEIGHT/1.2);
        tank = new Tank(center, new Point2D(100, 0));
        objects.add(tank);
    }

    public synchronized void fire(double x, double y) {
        if (tank != null) {
            Point2D mousePoint = new Point2D(x, y);
            Point2D tankPosition = tank.getPosition();
            Point2D speed = mousePoint.subtract(tankPosition);
            speed = speed.normalize();
            speed = speed.multiply(30);
            Point2D bombStartPosition = tankPosition.add(speed.multiply(2));
            
            Bomb bomb = new Bomb(bombStartPosition, new Point2D(100, 0), speed);
            bomb.setDirectionToPoint(bombStartPosition.add(speed.multiply(10)));
            objects.add(bomb);
        }
    }

}
