/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Tiago Moore
 * This is a test class for the stock portfolio class
 */
import javax.swing.JOptionPane; // for input 

public class StockPortFolioTest
{
    
    public static void main(String args[])
    {
       String name = "";
       int shares = 0;
       int dollar = 0;
       int eights = 0;
       
       name = JOptionPane.showInputDialog("Enter the name of the company : ");

       
       String out = JOptionPane.showInputDialog("Enter the amount of shares:  ");
       
       shares = Integer.parseInt(out);
       
       out = JOptionPane.showInputDialog("Enter the dollar amount of the share : ");

         dollar = Integer.parseInt(out);
         
       out = JOptionPane.showInputDialog("Enter the eighths amount of the share : ");

         eights = Integer.parseInt(out);
         
         
       StockPortfolio MyPortfolio = new StockPortfolio(name,shares,dollar,eights);
       
        
        System.out.print("Company:"+MyPortfolio.getname() +"\n\n");
        
        System.out.print("Shares held:"+MyPortfolio.shareNum +"\n\n");
          
        System.out.print("Opening Price per Share: "+MyPortfolio.dollarShare +" "+ MyPortfolio.geteshares()+"/8\n\n" );  
        
        
        System.out.printf("Opening Portfolio value: $%.2f",MyPortfolio.computeFolio());
        
        out = JOptionPane.showInputDialog("Enter the  change in share price(Dollars) : ");
        
        dollar = Integer.parseInt(out);
        
        out = JOptionPane.showInputDialog("Enter the change in share price (eighths)");
        
        
          eights = Integer.parseInt(out);
       
       
        MyPortfolio.modifyprice(dollar,eights);
        
        System.out.print("\n\nChange in share price:  "+dollar+" "+eights+"/8\n\n");
        
         System.out.print("Closing Price per Share: "+MyPortfolio.getdshares()+" "+MyPortfolio.geteshares()+"/8\n\n");
        
        System.out.printf("Closing Portfolio Value : $%.2f\n\n",MyPortfolio.computeFolio());
        
      
        
        
        out = JOptionPane.showInputDialog("Enter the  change in share price(Dollars) : ");
        
        dollar = Integer.parseInt(out);
        
        out = JOptionPane.showInputDialog("Enter the change in share price (eighths)");
        
        
          eights = Integer.parseInt(out);
       
       
        MyPortfolio.modifyprice(dollar,eights);
        
 
            
        System.out.print("Change in share price:  "+dollar+" "+eights+"/8\n\n");
        
        System.out.print("Closing Price per Share:  "+MyPortfolio.getdshares()+" "+MyPortfolio.geteshares()+"/8\n\n");
        
        System.out.printf("Closing Portfolio Value : $%.2f\n\n",MyPortfolio.computeFolio());
        
        
        
        System.exit(0);
        
        
    }
    
    
    
    
    
    
}
