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
    private double laps;
    private double averagelength;
    private double averagevolume;
    
    
    
    
    //constructor
    public BottledWaterCalculator(String n, int p, double nb, double l , double v)
    {
        countryn= n;
        pop = p;
        laps = nb;
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
        return laps;
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
        double totalmiles = 0.0;
        double totalBottles = 0.0;
        double totalinches = 0.0;
        
        totalmiles = laps *24902; // number of miles need to be covered by bottles
        totalinches = totalmiles * 63360; // number of inches in a mile
        
        
        
        totalBottles = totalinches/averagelength;
        
        
        return totalBottles;
        
      
    }
    
     public double calcvolume() 
             {
                 double x =0.0;
                
                 x = calctotal()*getvolume();

                 return ((x/pop)/128);
       
             }       

    
    
}
