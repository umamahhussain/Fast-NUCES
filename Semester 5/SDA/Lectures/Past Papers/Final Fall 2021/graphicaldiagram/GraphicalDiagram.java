/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package graphicaldiagram;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author lehmia.kiran
 */
public class GraphicalDiagram extends GraphicalElement{
    private List children=new ArrayList();
    
    public GraphicalDiagram(String ID) {
        this.ID=ID;
    }

    public void add(GraphicalElement c)
    {
        children.add(c);
    }
    
  /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

// As nothing is specified in the question, student  answer can vary. 
}

 

    @Override
    protected double area() {
          for(int i=0;i<children.size();i++)
          area+=((GraphicalElement)children.get(i)).area();
          return area;
    }
    
}
