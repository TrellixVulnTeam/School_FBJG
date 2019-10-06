/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thegame;

import javafx.geometry.Point2D;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.transform.Rotate;

/**
 *
 * @author beh01
 */
public final class View {

    public final static int HEIGHT = 1004;
    public final static int WIDTH = 1024;

    private final GraphicsContext context;
    private final Image backgroud, tank, tankBody, bomb, plane;

    private final Model model;
    
    View(GraphicsContext context, Model model) {
        this.context = context;
        backgroud = new Image("file:src/thegame/image/Grass.jpg");
        tank = new Image("file:src/thegame/image/player.gif");
        tankBody = new Image("file:src/thegame/image/tank_body.png");
        bomb = new Image("file:src/thegame/image/bomb.png");
        plane = new Image("file:src/thegame/image/plane.png");
        this.model = model;
        update();
    }

    private void drawImage(Image image, Point2D point) {
        context.drawImage(image, point.getX() - image.getWidth() / 2, point.getY() - image.getHeight() / 2);
    }
    
    private void rotate(double angle, Point2D center) {
        Rotate r = new Rotate(angle, center.getX(), center.getY());
        context.setTransform(r.getMxx(), r.getMyx(), r.getMxy(), r.getMyy(), r.getTx(), r.getTy());
    }

    public void update() {
        context.drawImage(backgroud, 0, 0, WIDTH, HEIGHT);
        //context.setStroke(Color.BLACK);
        //context.setLineWidth(20);
        //context.strokeRect(0, 0, context.getCanvas().getWidth(), context.getCanvas().getHeight());
        
        synchronized (model) {
            
            for (ModelObject object : model.getObjects()) {
                context.save();
                
                rotate(object.getDirection(), object.getPosition());
                if (object instanceof Tank) {
                    drawImage(tank, object.getPosition());
                }else {
                    drawImage(bomb, object.getPosition());
                }
                context.restore();
            }
        }
    }
}
