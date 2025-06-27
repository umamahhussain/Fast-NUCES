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
public class Rectangle extends GraphicalElement {
    private double width;
    private double length;

    @Override
    protected double area() {
       area= width*length;
       return area;
    }

    public Rectangle(String ID,double width, double length) {
        this.ID=ID;
        this.width = width;
        this.length = length;
    }
    
}
