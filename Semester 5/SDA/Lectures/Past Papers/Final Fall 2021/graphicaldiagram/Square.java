/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphicaldiagram;

/**
 *
 * @author lehmia.kiran
 */
public class Square extends GraphicalElement {
private double side;
    @Override
    protected double area() {
      area= side*side;
      return area;
    }

    public Square(String ID,double side) {
        this.ID=ID;
        this.side = side;
    }
    
    
}
