package tetris;

import java.awt.Point;
import java.util.Random;
import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.beans.binding.NumberBinding;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;
import javafx.util.Duration;

/**
 *
 * @author beh01
 */
public class Tetris extends Application {
    
    private final int grid_x = 18; //number of rows
    private final int grid_y = 23; //number of columns
    private final int msec = 100;
    private Timeline action;
    private int check = 0, end = 0;
    private int starter = 0, object = 0, nObject = 0, rObject = 0, rotation = 0, rotationCheck = 0, rotationChanged = 0;
    private Paint cLine, color, nColor, rColor;
    private Rectangle[][] grid;    
    private final Point point, direction;
    
    public Tetris() {
        point = new Point(((grid_x-6)/2)+6, 0);
        direction = new Point();
    }
    
    public Paint randomColor(){
            Random random = new Random();

            int number;
            number = random.nextInt((8 - 1) + 1) + 1;
            switch(number){
                    
                        case 1:
                            rColor = Color.RED;
                            break;
                        case 2:
                            rColor = Color.GREEN;
                            break;
                        case 3:
                            rColor = Color.BLUE;
                            break;
                        case 4:
                            rColor = Color.YELLOW;
                            break;
                        case 5:
                            rColor = Color.AQUA;
                            break;
                        case 6:
                            rColor = Color.BLUEVIOLET;
                            break;
                        case 7:
                            rColor = Color.CHARTREUSE;
                            break;
                        case 8:
                            rColor = Color.DARKRED;
                            break;
                        case 9:
                            rColor = Color.CRIMSON;
                            break;
                        case 10:
                            rColor = Color.DARKSLATEBLUE;
                            break;    
                        default:
                            break;
                    }
            return rColor;
        }
    
    public void oneLine(){
        int line = 0;
        for(int y = 0; y < grid_y; y++){
            for(int x = 7; x < grid_x-1; x++){
                if(grid[x][y].getFill() != Color.BLACK){
                    //grid[x][y].setFill(Color.BLUE);
                    line++; 
                    if(line == grid_x-8){
                       //grid[x][y].setFill(Color.YELLOW);
                       for(int i = y; i > 0; i--){
                           for(int j = 7; j < grid_x-1; j++ ){
                               cLine = grid[j][i-1].getFill();
                               grid[j][i-1].setFill(Color.BLACK);
                               grid[j][i].setFill(cLine);
                           }
                       }
                   }
                }
            }
            line = 0;
        }
    }
    
    public void checkWalls(int number, int rot){
            switch(number){
            case 1:
                //for(int i = 0; i < 2; i++){
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+2][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            check = 3;
                        }
                    } 
                //}
                break;
            case 2:
                if(rotation == 0){
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        rotationCheck = 1;
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    } 
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                    if(point.y-4>0){
                        if(grid[point.x-1][point.y-4].getFill() != Color.BLACK || grid[point.x-1][point.y-3].getFill() != Color.BLACK || grid[point.x-1][point.y-2].getFill() != Color.BLACK){
                        check = 2;
                        }else if(grid[point.x-1][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }
                        
                        if(grid[point.x+1][point.y-4].getFill() != Color.BLACK || grid[point.x+1][point.y-3].getFill() != Color.BLACK || grid[point.x+1][point.y-2].getFill() != Color.BLACK){
                            check = 1;
                        }else if(grid[point.x+1][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-1][point.y-4].getFill() != Color.BLACK && grid[point.x+1][point.y-4].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                    if(point.x > grid_x-3 || grid[point.x+1][point.y].getFill() != Color.BLACK || grid[point.x+2][point.y].getFill() != Color.BLACK || grid[point.x+3][point.y].getFill() != Color.BLACK /*|| grid[point.x+4][point.y].getFill() != Color.BLACK*/){
                        rotationCheck = 1;
                    }
                }else{
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+4][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+4][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 1;
                            check = 1;
                        }
                    } 
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+4][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    if(point.y < 3 || grid[point.x][point.y-1].getFill() != Color.BLACK || grid[point.x][point.y-2].getFill() != Color.BLACK || grid[point.x][point.y-3].getFill() != Color.BLACK || grid[point.x][point.y-3].getFill() != Color.BLACK){
                        rotationCheck = 1;
                    }                   
                }
                
                break;
            case 3:
            switch (rotation) {
                case 0:
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        rotationCheck = 1;
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+2][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            check = 3;
                        }
                        if(point.x > grid_x-3 || grid[point.x-1][point.y].getFill() != Color.BLACK || grid[point.x-2][point.y].getFill() != Color.BLACK){
                            rotationCheck = 1;
                        }
                    }
                    if(point.y-3>0){
                        if(grid[point.x-1][point.y-2].getFill() != Color.BLACK){
                            check = 2;
                        }else if(grid[point.x-1][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }

                        if(grid[point.x+2][point.y-2].getFill() != Color.BLACK){
                            check = 1;
                        }else if(grid[point.x+2][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x+1][point.y-3].getFill() != Color.BLACK && grid[point.x-1][point.y-3].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                    break;
                case 1:
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x-3][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-3][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 1;
                            check = 2;
                        }
                    } 
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK && grid[point.x-3][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    if(point.y < 2 || grid[point.x][point.y-2].getFill() != Color.BLACK || grid[point.x][point.y-3].getFill() != Color.BLACK){
                        rotationCheck = 1;
                    }
                    break;
                case 2:
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-2][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK && grid[point.x-2][point.y-1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }                    
                    break;
                case 3:
                    if(grid[point.x-3][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-3][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-3][point.y+1].getFill() != Color.BLACK && grid[point.x+1][point.y].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    break;
                default:
                    break;
            }
                break;                                                
            case 4:
            switch (rotation) {
                case 0:
                    if(grid[point.x-2][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-2][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        rotationCheck = 1;
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-2][point.y+1].getFill() != Color.BLACK && grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 3;
                        }
                        if(point.x > grid_x-2 || grid[point.x+1][point.y].getFill() != Color.BLACK || grid[point.x+2][point.y].getFill() != Color.BLACK){
                            rotationCheck = 1;
                        }
                    }
                    if(point.y-3>0){
                        if(grid[point.x-1][point.y-3].getFill() != Color.BLACK || grid[point.x-1][point.y-2].getFill() != Color.BLACK){
                            check = 2;
                        }else if(grid[point.x-1][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }
                        
                        if(grid[point.x+1][point.y-3].getFill() != Color.BLACK || grid[point.x+1][point.y-2].getFill() != Color.BLACK){
                            check = 1;
                        }else if(grid[point.x+1][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-1][point.y-3].getFill() != Color.BLACK && grid[point.x+1][point.y-4].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                    break;
                case 1:
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+3][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+3][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 1;
                            check = 1;
                        }
                    } 
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+3][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    if(point.y < 2 || grid[point.x][point.y-2].getFill() != Color.BLACK || grid[point.x][point.y-3].getFill() != Color.BLACK){
                        rotationCheck = 1;
                    }
                    break;
                case 2:
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+2][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK && grid[point.x+2][point.y-1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    break;
                case 3:
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+3][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+3][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y].getFill() != Color.BLACK && grid[point.x+3][point.y+1].getFill() != Color.BLACK){
                            rotationCheck = 2;
                            check = 3;
                        }
                    }
                    break;
                default:
                    break;
            }
                break;                
            case 5:
                if(rotation == 0){
                    if(grid[point.x-2][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-2][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                    }
                    if(grid[point.x+2][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y-1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-2][point.y+1].getFill() != Color.BLACK && grid[point.x+2][point.y].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                }else{
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-2][point.y].getFill() != Color.BLACK || grid[point.x-2][point.y-1].getFill() != Color.BLACK ){
                            check = 2;
                        }
                    }
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                        if(grid[point.x-2][point.y].getFill() != Color.BLACK && grid[point.x+1][point.y].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                }    
                break;
            case 6:
                if(rotation == 0){
                    if(grid[point.x+2][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            check = 1;
                        }
                    }
                    if(grid[point.x-2][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-2][point.y-1].getFill() != Color.BLACK){
                            check = 2;
                        }
                        if(grid[point.x+2][point.y+1].getFill() != Color.BLACK && grid[point.x-2][point.y].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                }else{
                    if(grid[point.x+1][point.y].getFill() != Color.BLACK){
                        check = 1;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x+2][point.y].getFill() != Color.BLACK || grid[point.x+2][point.y-1].getFill() != Color.BLACK ){
                            check = 1;
                        }
                    }
                    if(grid[point.x-1][point.y].getFill() != Color.BLACK){
                        check = 2;
                    }else if(grid[point.x][point.y] != grid[point.x][0] && grid[point.x][point.y] != grid[point.x][grid_y-1]){
                        if(grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            check = 2;
                        }
                        if(grid[point.x+2][point.y].getFill() != Color.BLACK && grid[point.x-1][point.y].getFill() != Color.BLACK){
                            check = 3;
                        }
                    }
                }                
                break;    
            default:
                break;
        }

    }
    public int randomObject(){
        
        Random random = new Random();
        rObject = random.nextInt((6 - 1) + 1) + 1;
        //rObject = 6;
        return rObject;
    }
    public void objectType(int number, int rot){
        switch(number){
            case 1:
                for(int i = 0; i < 2; i++){
                    grid[point.x+i][point.y].setFill(color); 
                    if(point.y != 0){
                        grid[point.x+i][point.y-1].setFill(color);    
                    }
                }
                break;
            case 2:
                if(rotation == 0){
                    grid[point.x][point.y].setFill(color); 
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(color); 
                    }
                    if(point.y > 1){
                        grid[point.x][point.y-2].setFill(color); 
                    }
                    if(point.y > 2){
                        grid[point.x][point.y-3].setFill(color); 
                    }
                }else{
                    for(int i = 0; i < 4; i++){
                        grid[point.x+i][point.y].setFill(color); 
                    }
                }
                break;
            case 3:
                switch (rotation) {
                    case 0:
                        for(int i = 0; i < 2; i++){
                            grid[point.x+i][point.y].setFill(color);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(color);
                            }
                            if(point.y > 1){
                            grid[point.x][point.y-2].setFill(color);
                            }
                        }
                        break;
                    case 1:
                        for(int i = 0; i < 3; i++){
                            grid[point.x-i][point.y].setFill(color);
                        }
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(color);
                        }
                        break;
                    case 2:
                        for(int i = 0; i < 2; i++){
                            grid[point.x][point.y].setFill(color);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(color);
                            }
                            if(point.y > 1){
                                grid[point.x][point.y-2].setFill(color);
                                grid[point.x-1][point.y-2].setFill(color);
                            }
                        }                
                        break;
                    case 3:
                        grid[point.x-2][point.y].setFill(color);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(color);
                            grid[point.x-1][point.y-1].setFill(color);
                            grid[point.x-2][point.y-1].setFill(color);
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                switch (rotation) {
                    case 0:
                    for(int i = 0; i < 2; i++){
                        grid[point.x-i][point.y].setFill(color);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(color);
                        }
                        if(point.y > 1){
                            grid[point.x][point.y-2].setFill(color);
                        }
                    }
                    break;
                case 1:
                    for(int i = 0; i < 3; i++){
                        grid[point.x+i][point.y].setFill(color);
                    }
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(color);
                    }
                    break;
                case 2:
                    for(int i = 0; i < 2; i++){
                        grid[point.x][point.y].setFill(color);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(color);
                        }
                        if(point.y > 1){
                            grid[point.x][point.y-2].setFill(color);
                            grid[point.x+1][point.y-2].setFill(color);
                        }
                    }                
                    break;
                case 3:
                    grid[point.x+2][point.y].setFill(color);
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(color);
                        grid[point.x+1][point.y-1].setFill(color);
                        grid[point.x+2][point.y-1].setFill(color);
                    }                
                    break;
                default:
                    break;
                }
                break;        
            case 5:
                if(rotation == 0){
                    for(int i = 0; i < 2; i++){
                        grid[point.x-i][point.y].setFill(color);    
                    
                        if(point.y > 0){
                        grid[point.x+i][point.y-1].setFill(color);    
                        }
                    }
                }else{
                    grid[point.x][point.y].setFill(color);    
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(color);    
                        grid[point.x-1][point.y-1].setFill(color);
                    }
                    if(point.y > 1){
                        grid[point.x-1][point.y-2].setFill(color);
                    }
                }
                break;
            case 6:
                if(rotation == 0){
                    for(int i = 0; i < 2; i++){
                        grid[point.x+i][point.y].setFill(color);    
                    
                        if(point.y > 0){
                        grid[point.x-i][point.y-1].setFill(color);    
                        }
                    }
                }else{
                    grid[point.x][point.y].setFill(color);    
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(color);    
                        grid[point.x+1][point.y-1].setFill(color);
                    }
                    if(point.y > 1){
                        grid[point.x+1][point.y-2].setFill(color);
                    }                    
                }                
                break;    
            default:
                break;
        }
    }

    public void objectTypeBlack(int number, int rot){
        switch(number){
            case 1:
                for(int i = 0; i < 2; i++){
                    grid[point.x+i][point.y].setFill(Color.BLACK);
                    if(point.y != 0){
                        grid[point.x+i][point.y-1].setFill(Color.BLACK);    
                    }
                }
                break;
            case 2:
                if(rotation == 0){
                    grid[point.x][point.y].setFill(Color.BLACK); 
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(Color.BLACK); 
                    }
                    if(point.y > 1){
                        grid[point.x][point.y-2].setFill(Color.BLACK); 
                    }
                    if(point.y > 2){
                        grid[point.x][point.y-3].setFill(Color.BLACK); 
                    }
                    if(rotationChanged == 0){
                    for(int i = 1; i < 4; i++){
                        grid[point.x+i][point.y].setFill(Color.BLACK); 
                    }
                    rotationChanged = 1;
                    }
                }else{
                    if(rotationChanged == 1){
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK); 
                        }
                        if(point.y > 1){
                            grid[point.x][point.y-2].setFill(Color.BLACK); 
                        }
                        if(point.y > 2){
                            grid[point.x][point.y-3].setFill(Color.BLACK); 
                        }
                        rotationChanged = 0;
                    }                    
                    for(int i = 0; i < 4; i++){
                        grid[point.x+i][point.y].setFill(Color.BLACK); 
                    }

                }
                break;
            case 3:
                switch (rotation) {
                    case 0:
                        if(rotationChanged == 0){
                        grid[point.x-2][point.y].setFill(Color.BLACK);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                            grid[point.x-1][point.y-1].setFill(Color.BLACK);
                            grid[point.x-2][point.y-1].setFill(Color.BLACK);
                        }
                        /*if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                        }
                        for(int i = 0; i < 3; i++){
                            grid[point.x-i][point.y].setFill(Color.BLACK);
                        }*/                        
                            rotationChanged = 1;
                        }
                        for(int i = 0; i < 2; i++){
                            grid[point.x+i][point.y].setFill(Color.BLACK);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            if(point.y > 1){
                                grid[point.x][point.y-2].setFill(Color.BLACK);
                            }
                        }
                        break;
                    case 1:
                        if(rotationChanged == 1){
                            for(int i = 0; i < 2; i++){
                                grid[point.x+i][point.y].setFill(Color.BLACK); 
                                if(point.y > 0){
                                    grid[point.x][point.y-1].setFill(Color.BLACK);    
                                }
                                if(point.y > 1){
                                    grid[point.x][point.y-2].setFill(Color.BLACK);    
                                }
                            }
                            rotationChanged = 2;
                        }
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                        }
                        for(int i = 0; i < 3; i++){
                            grid[point.x-i][point.y].setFill(Color.BLACK);
                        }
                        break;
                    case 2:
                        if(rotationChanged == 2){
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            for(int i = 1; i < 3; i++){
                                grid[point.x-i][point.y].setFill(Color.BLACK);
                            }
                            rotationChanged = 3;
                        }                           
                        for(int i = 0; i < 2; i++){
                            grid[point.x][point.y].setFill(Color.BLACK);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            if(point.y > 1){
                                grid[point.x][point.y-2].setFill(Color.BLACK);
                                grid[point.x-1][point.y-2].setFill(Color.BLACK);
                            }
                        }                
                        break;
                    case 3:
                        if(rotationChanged == 3){
                            for(int i = 0; i < 2; i++){
                                grid[point.x][point.y].setFill(Color.BLACK);
                                if(point.y > 0){
                                    grid[point.x][point.y-1].setFill(Color.BLACK);
                                }
                                if(point.y > 1){
                                    grid[point.x][point.y-2].setFill(Color.BLACK);
                                    grid[point.x-1][point.y-2].setFill(Color.BLACK);
                                }
                            }                              
                            rotationChanged = 0;
                        }
                        grid[point.x-2][point.y].setFill(Color.BLACK);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                            grid[point.x-1][point.y-1].setFill(Color.BLACK);
                            grid[point.x-2][point.y-1].setFill(Color.BLACK);
                        }
                    default:
                        break;
                }                
                break;
            case 4:
                switch (rotation) {
                    case 0:
                        if(rotationChanged == 0){
                            grid[point.x+2][point.y].setFill(Color.BLACK);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                                grid[point.x+1][point.y-1].setFill(Color.BLACK);
                                grid[point.x+2][point.y-1].setFill(Color.BLACK);
                            }
                        /*if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                        }
                        for(int i = 0; i < 3; i++){
                            grid[point.x+i][point.y].setFill(Color.BLACK);
                        }*/                            
                            rotationChanged = 1;
                        }                        
                        for(int i = 0; i < 2; i++){
                            grid[point.x-i][point.y].setFill(Color.BLACK);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            if(point.y > 1){
                                grid[point.x][point.y-2].setFill(Color.BLACK);
                            }
                        }
                        break;
                    case 1:
                        if(rotationChanged == 1){
                            for(int i = 0; i < 2; i++){
                                grid[point.x-i][point.y].setFill(Color.BLACK); 
                                if(point.y > 0){
                                    grid[point.x][point.y-1].setFill(Color.BLACK);    
                                }
                                if(point.y > 1){
                                    grid[point.x][point.y-2].setFill(Color.BLACK);    
                                }
                                rotationChanged = 2;
                            }
                        }
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                        }
                        for(int i = 0; i < 3; i++){
                            grid[point.x+i][point.y].setFill(Color.BLACK);
                        }
                        break;
                    case 2:
                        if(rotationChanged == 2){
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            for(int i = 1; i < 3; i++){
                                grid[point.x+i][point.y].setFill(Color.BLACK);
                            }
                            rotationChanged = 3;
                        }                        
                        for(int i = 0; i < 2; i++){
                            grid[point.x][point.y].setFill(Color.BLACK);
                            if(point.y > 0){
                                grid[point.x][point.y-1].setFill(Color.BLACK);
                            }
                            if(point.y > 1){
                                grid[point.x][point.y-2].setFill(Color.BLACK);
                                grid[point.x+1][point.y-2].setFill(Color.BLACK);
                            }
                        }                
                        break;
                    case 3:
                        if(rotationChanged == 3){
                            for(int i = 0; i < 2; i++){
                                grid[point.x][point.y].setFill(Color.BLACK);
                                if(point.y > 0){
                                    grid[point.x][point.y-1].setFill(Color.BLACK);
                                }
                                if(point.y > 1){
                                    grid[point.x][point.y-2].setFill(Color.BLACK);
                                    grid[point.x+1][point.y-2].setFill(Color.BLACK);
                                }
                            }                        
                            rotationChanged = 0;
                        }    
                        grid[point.x+2][point.y].setFill(Color.BLACK);
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);
                            grid[point.x+1][point.y-1].setFill(Color.BLACK);
                            grid[point.x+2][point.y-1].setFill(Color.BLACK);
                        }                
                        break;
                    default:
                        break;
                }
                break;        
            case 5:
                if(rotation == 0){
                    for(int i = 0; i < 2; i++){
                        grid[point.x-i][point.y].setFill(Color.BLACK);    
                    
                        if(point.y > 0){
                        grid[point.x+i][point.y-1].setFill(Color.BLACK);    
                        }
                    }
                    if(rotationChanged == 1){
                    grid[point.x][point.y].setFill(Color.BLACK);    
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(Color.BLACK);    
                        grid[point.x-1][point.y-1].setFill(Color.BLACK);
                    }
                    if(point.y > 1){
                        grid[point.x-1][point.y-2].setFill(Color.BLACK);
                    }
                    rotationChanged = 0;
                    }
                }else{
                    grid[point.x][point.y].setFill(Color.BLACK);    
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(Color.BLACK);    
                        grid[point.x-1][point.y-1].setFill(Color.BLACK);
                    }
                    if(point.y > 1){
                        grid[point.x-1][point.y-2].setFill(Color.BLACK);
                    }
                    if(rotationChanged == 0){
                    for(int i = 0; i < 2; i++){
                        grid[point.x-i][point.y].setFill(Color.BLACK);    
                    
                        if(point.y > 0){
                        grid[point.x+i][point.y-1].setFill(Color.BLACK);    
                        }
                    }
                    rotationChanged = 1;
                    }
                }
                break;
            case 6:
                if(rotation == 0){
                    for(int i = 0; i < 2; i++){
                        grid[point.x+i][point.y].setFill(Color.BLACK);    
                    
                        if(point.y > 0){
                        grid[point.x-i][point.y-1].setFill(Color.BLACK);    
                        }
                    }
                    if(rotationChanged == 1){
                        if(point.y > 0){
                            grid[point.x][point.y-1].setFill(Color.BLACK);    
                            grid[point.x+1][point.y-1].setFill(Color.BLACK);
                        }
                        if(point.y > 1){
                            grid[point.x+1][point.y-2].setFill(Color.BLACK);
                        }
                        rotationChanged = 0; 
                    }
                }else{
                    grid[point.x][point.y].setFill(Color.BLACK);    
                    if(point.y > 0){
                        grid[point.x][point.y-1].setFill(Color.BLACK);    
                        grid[point.x+1][point.y-1].setFill(Color.BLACK);
                    }
                    if(point.y > 1){
                        grid[point.x+1][point.y-2].setFill(Color.BLACK);
                    }
                    if(rotationChanged == 0){
                        for(int i = 0; i < 2; i++){
                            grid[point.x+i][point.y].setFill(Color.BLACK);    
                    
                            if(point.y > 0){
                            grid[point.x-i][point.y-1].setFill(Color.BLACK);    
                            }
                        }
                        rotationChanged = 1;
                    }
                } 
                break;    
            default:
                break;
        }
    }

    public void preview(int number){
        //number = 6;
        switch(number){
            case 1:
                for(int i = 0; i < 2; i++){
                grid[2+i][grid_y-4].setFill(nColor);
                grid[2+i][grid_y-5].setFill(nColor);
                }
                break;
            case 2:
                for(int i = 0; i < 4; i++){
                    grid[3][grid_y-3-i].setFill(nColor); 
                }
                break;
            case 3:
                for(int i = 0; i < 3; i++){
                    grid[3][grid_y-3-i].setFill(nColor); 
                    grid[4][grid_y-3].setFill(nColor); 
                }
                break;
            case 4:
                for(int i = 0; i < 3; i++){
                    grid[3][grid_y-3-i].setFill(nColor); 
                    grid[2][grid_y-3].setFill(nColor); 
                }
                break;    
            case 5:
                for(int i = 0; i < 2; i++){
                    grid[3+i][grid_y-5].setFill(nColor); 
                    grid[2+i][grid_y-4].setFill(nColor); 
                }                
                break;
            case 6:
                for(int i = 0; i < 2; i++){
                    grid[2+i][grid_y-5].setFill(nColor); 
                    grid[3+i][grid_y-4].setFill(nColor); 
                }                
                break;    
            default:
                break;
        }        
    }
    
    public void stopOrGo(int number, int rot, Button bSet){

        switch(number){
            case 1:
                
                if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y+1].getFill() != Color.BLACK){            
                    reset();
                    end(grid[point.x][0].getFill(), bSet);
                
                }else{
                        //grid[point.x][point.y].setFill(Color.BLACK);
                        objectTypeBlack(object, rotation);
                        oneLine();
                }
                
                break;
            case 2:
                if(rotation == 0){
                    if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }
                }else{
                    if(point.y == grid_y-1 || grid[point.x+3][point.y+1].getFill() != Color.BLACK || grid[point.x+2][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y+1].getFill() != Color.BLACK || grid[point.x][point.y+1].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }                    
                }
                break;
            case 3:
                switch (rotation) {
                    case 0:
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y+1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }
                        break;
                    case 1:
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y+1].getFill() != Color.BLACK || grid[point.x-2][point.y+1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }
                        break;
                    case 2:
                        if(rotationChanged == 2){
                        grid[point.x-1][point.y-1].setFill(Color.BLACK);
                        }
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y-1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }                        
                        break;
                    case 3:
                        if(rotationChanged == 3){
                        grid[point.x-1][point.y].setFill(Color.BLACK);
                        grid[point.x][point.y].setFill(Color.BLACK);
                        }
                        if(point.y == grid_y-1 || grid[point.x-2][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y].getFill() != Color.BLACK || grid[point.x][point.y].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }                        
                        break;
                    default:
                        break;
                }                
                break;
            case 4:
                switch (rotation) {
                    case 0:
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y+1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }
                        break;
                    case 1:
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y+1].getFill() != Color.BLACK || grid[point.x+2][point.y+1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }
                        break;
                    case 2:
                        if(rotationChanged == 2){
                        grid[point.x+1][point.y-1].setFill(Color.BLACK);
                        }
                        if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y-1].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }                        
                        break;
                    case 3:
                        if(rotationChanged == 3){
                        grid[point.x+1][point.y].setFill(Color.BLACK);
                        grid[point.x][point.y].setFill(Color.BLACK);
                        }
                        if(point.y == grid_y-1 || grid[point.x+2][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y].getFill() != Color.BLACK || grid[point.x][point.y].getFill() != Color.BLACK){
                            reset();
                            end(grid[point.x][0].getFill(), bSet);
                    
                        }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                        }
                        break;
                    default:
                        break;
                }
                break;        
            case 5:                
                if(rotation == 0){
                    if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }
                }else{
                    if(rotationChanged == 0){
                        grid[point.x-1][point.y].setFill(Color.BLACK);
                    }                    
                    if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }                    
                }
                break;
            case 6:
                if(rotation == 0){
                    if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y+1].getFill() != Color.BLACK || grid[point.x-1][point.y].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }
                }else{
                    if(rotationChanged == 0){
                    grid[point.x+1][point.y].setFill(Color.BLACK);
                    }
                    if(point.y == grid_y-1 || grid[point.x][point.y+1].getFill() != Color.BLACK || grid[point.x+1][point.y].getFill() != Color.BLACK){            
                        reset();
                        end(grid[point.x][0].getFill(), bSet);
                    
                    }else{
                            //grid[point.x][point.y].setFill(Color.BLACK);
                            objectTypeBlack(object, rotation);
                            oneLine();
                    }                    
                }
                break;    
            default:
                break;
        }
            
        

        
    }
    
    public void reset(){
        object = nObject;
        color = nColor;
        rotation = 0;
        rotationChanged = 0;
        point.x = ((grid_x-6)/2)+6;
        point.y = 0;
        nObject = randomObject();
        nColor = randomColor();
        for(int j = 0; j < 6; j++){
            for(int i = 0; i < grid_y; i++){
                    if(j > 0 && j < 6){
                        if(i > grid_y-7 && i < grid_y-2){
                        grid[j][i].setStroke(Color.BLACK);
                        grid[j][i].setFill(Color.BLACK);
                        }
                    }
            }
        }
        preview(nObject);
                
    }
    
    public void clear(){
        for(int x = 7; x < grid_x-1; x++){
            for(int y = 0; y < grid_y; y++){
            grid[x][y].setStroke(Color.BLACK);
            grid[x][y].setFill(Color.BLACK);
            }
        }
        for(int j = 0; j < 6; j++){
            for(int i = 0; i < grid_y; i++){
                    if(j > 0 && j < 6){
                        if(i > grid_y-7 && i < grid_y-2){
                        grid[j][i].setStroke(Color.BLACK);
                        grid[j][i].setFill(Color.BLACK);
                        }
                    }
            }
        }        
    }
    
    public void end(Paint color, Button bSet){
        if(color != Color.BLACK){
            action.stop();
            direction.y = 0;
            starter = 0;
            end = 1;
            bSet.setText("Start game");
        }
    }
    
    @Override
    public void start(Stage primaryStage) {
        AnchorPane basePane = new AnchorPane();
        Button btnStart = new Button();
        
        btnStart.setText("Start game");
        btnStart.setOnAction(new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent event) {
                if (action.getStatus()==Animation.Status.RUNNING) {
                    action.stop();
                    btnStart.setText("Start game");
                }else {
                    action.play();
                    btnStart.setText("Stop game");
                }
            }
        });
        basePane.getChildren().add(btnStart);
        AnchorPane.setTopAnchor(btnStart, 1.0);
        AnchorPane.setLeftAnchor(btnStart, 1.0);
        AnchorPane.setRightAnchor(btnStart, 1.0);
 
        Pane root = new Pane();
        basePane.getChildren().add(root);
        AnchorPane.setBottomAnchor(root, 1.0);
        AnchorPane.setLeftAnchor(root, 1.0);
        AnchorPane.setRightAnchor(root, 1.0);
        AnchorPane.setTopAnchor(root, 30.0);
        
        grid =  new Rectangle[grid_x][grid_y];
        
        // this binding will find out which parameter is smaller: height or width
        NumberBinding rectSize = Bindings.min(root.heightProperty().divide(grid_y), root.widthProperty().divide(grid_x));

        for (int x = 0; x < grid_x; x++) {
            for (int y = 0; y < grid_y; y++) {
                grid[x][y] = new Rectangle();
                grid[x][y].setStroke(Color.BLACK);
                grid[x][y].setFill(Color.BLACK);
                // here we position rects (this depends on pane size as well)
                grid[x][y].xProperty().bind(rectSize.multiply(x));
                grid[x][y].yProperty().bind(rectSize.multiply(y));

                // here we bind rectangle size to pane size 
                grid[x][y].heightProperty().bind(rectSize);
                grid[x][y].widthProperty().bind(grid[x][y].heightProperty());

                root.getChildren().add(grid[x][y]);
            }
        }
        for(int j = 0; j < grid_x; j++){
            for(int i = 0; i < grid_y; i++){
                    grid[6][i].setStroke(Color.WHITE);
                    grid[6][i].setFill(Color.WHITE);
                    grid[0][i].setStroke(Color.WHITE);
                    grid[0][i].setFill(Color.WHITE);
                    grid[grid_x - 1][i].setStroke(Color.WHITE);
                    grid[grid_x - 1][i].setFill(Color.WHITE);
                                        
                    if(j > 0 && j < 6){
                        if(i < grid_y-7 || i > grid_y-2){
                        grid[j][i].setStroke(Color.WHITE);
                        grid[j][i].setFill(Color.WHITE);
                        }
                    }
            }
        }
        Scene scene = new Scene(basePane, 500, 620);
        scene.addEventHandler(KeyEvent.KEY_PRESSED, new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent event) {
                if (event.getCode()==KeyCode.RIGHT && check == 0 || event.getCode()==KeyCode.RIGHT && check == 2) {
                    direction.x = 1;
                }
                if (event.getCode()==KeyCode.LEFT && check == 0 || event.getCode()==KeyCode.LEFT && check == 1) {
                    direction.x = -1;
                }
                if (event.getCode()==KeyCode.UP && rotationCheck == 0) {
                    if(object == 3 || object == 4){
                        switch (rotation) {
                            case 0:
                                rotation++;
                                break;
                            case 1:
                                rotation++;
                                break;
                            case 2:
                                rotation++;
                                break;
                            case 3:
                                rotation = 0;
                                break;
                            default:
                                break;
                        }
                    }else{
                        if(rotation == 0){
                            rotation++;
                        }else{
                            rotation = 0;
                        }
                    }
                }
                if (event.getCode()==KeyCode.DOWN) {
                    direction.x = 0;
                }
            }
            
        });
        
        
        
        action = new Timeline(new KeyFrame(Duration.millis(msec), new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                check = 0;
                rotationCheck = 0;
                if(starter == 0){
                    end = 0;
                    clear();
                    object = randomObject();
                    objectType(object, rotation);
                    nObject = randomObject();
                    //objectType(nObject, rotation);
                    color = randomColor();
                    nColor = randomColor();
                    preview(nObject);
                    starter++;
                }
                
                
                
                if(end == 0){
                    stopOrGo(object, rotation, btnStart);
                    point.x = (point.x+direction.x+grid_x)%grid_x;
                    point.y = (point.y+direction.y+grid_y)%grid_y;
                    
                    objectType(object, rotation);
                    
                    direction.y = 1;
                    direction.x = 0;
                    checkWalls(object, rotation);
                }
                
                
            }
        })); 
        action.setCycleCount(Timeline.INDEFINITE);
        
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}