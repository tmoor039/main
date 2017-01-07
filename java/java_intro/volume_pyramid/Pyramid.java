/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tmoore
 */
public class Pyramid
{
    //instance variables
    private int length = 0;
    
    private int height = 0;
    

   
    public Pyramid(int length, int height)
    {
        this.length = length;
        this.height = height ;
    }
    
    public double getlength()
    {
        return length;
    }
         
    public double getheight()
    {
        return height ;
    }
    
    
    public void resize(int x, int y)
    {
     length = x ;
     height = y ; 
    }
     
    public double volume()
     {
       return (1/3.0)*length*height;
      
         
     }
        
    
}
