/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tmoore
 */
public class BottleTester
{

    
    public static void main(String args[])
    {
        double total  = 0.0, average = 0.0;
        
         BottledWaterCalculator NewBottle = new BottledWaterCalculator("USA",
                 350000000,190,8.5,12);
    
         total = NewBottle.calctotal();
         average = NewBottle.calcvolume();
         
         
         System.out.print("Country: "+NewBottle.getname()+"\nPopulation: "+ 
                 NewBottle.getpopulation()+"\nNumber of Circumferences: "+
                 NewBottle.getbottlenumber()+ "\nLength of an average Bottle: "+
                 NewBottle.getlength()+"\nVolume of an average Bottle: "+ 
                 NewBottle.getvolume());
         
         
         
         System.out.println("\n\nThe total number of bottles consumed in the "+ NewBottle.getname()
                 +" are: "+ total+ "bottles.");
         
         System.out.println("The average amount of water consumed per person is: "+ 
               average +"ounzes." );
                 
                 System.out.print("\n\nThe new values are as follows : \n\n");
                 
                 NewBottle.setlength(100.5);
                 NewBottle.setvolume(67.2);
                 
                 System.out.println("\nLength of an average Bottle: "+
                 NewBottle.getlength()+"\nVolume of an average Bottle: "+ 
                 NewBottle.getvolume());
         
         
         
       
         
        
         
         
         
         
         
         
         
         
         
         
    }
   
    
    
    
}
