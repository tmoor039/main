/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tmoore
 */
public class BottledWaterCalculator
{
    
    private String countryn;
    private int pop;
    private double numbottle;
    private double averagelength;
    private double averagevolume;
    
    
    
    
    //constructor
    public BottledWaterCalculator(String n, int p, double nb, double l , double v)
    {
        countryn= n;
        pop = p;
        numbottle = nb;
        averagelength = l;
        averagevolume = v ; 
        
    }
    
    
    //accessors
    public String getname()
    {
        return countryn; 
    }
    
    
    public int getpopulation()
    {
        return pop;
    }
    
    
    public double getbottlenumber()
    {
        return numbottle;
    }
    
    public double getlength()
    {
        return averagelength;
    }
    
    public double getvolume()
    {
        return averagevolume;
    }
    
    
 
    
    //mutators
  public void setlength(double l)
  {
      averagelength = l;

  }
  
  public void setvolume(double v)
  {
      averagevolume = v;
      
  }
    
    
   //methods
    public double calctotal()
    {
        double totalDistance = 0.0;
        double totalBottles = 0.0;
        
        totalDistance = numbottle *24902;
        
        totalBottles = totalDistance/averagelength;
        
        
        return totalBottles;
        
      
    }
    
     public double calcvolume() 
             {
                 double x =0.0;
                 
                 x = calctotal()*getvolume();
                         
                 
       return x/pop;
       
             }       

    
    
}
