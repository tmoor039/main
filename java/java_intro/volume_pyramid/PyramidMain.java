/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tmoore
 */
public class PyramidMain
{
    
    double x = 0.0;
    
    public static void main(String args[])
    {
        
       Pyramid Egypt = new Pyramid(100,50);
       
       System.out.print("The values stored in the variables of the pyramid class are: \nBase:"+Egypt.getlength()+"\nHeight:"+Egypt.getheight());
       
       Egypt.resize(10,10);
       
            System.out.print("After resizing The values stored in the variables of the pyramid class are: \nBase:"+Egypt.getlength()+"\nHeight:"+Egypt.getheight());
           
             
  System.out.print( "\n Volume : "+Egypt.volume()+"\n");
   
 
        
    }
    
    
}
