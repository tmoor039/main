

import javax.swing.JOptionPane ; 



public class PaymentCalculatorTest
{
    public static void main(String[] args)
    {
        // local vars (NOTE: initial values necessary only to make
        // unfinished program compile and run!)
        int amountBorrowed = 0;
        double interestRate = 0.0;
        int years = 0;

        // insert statements to do input here
        // ----------------------------------
        
        String display = JOptionPane.showInputDialog("Enter the amount borrowed : ");
        
        amountBorrowed = Integer.parseInt(display);
        
        display = JOptionPane.showInputDialog("Enter the interest rate: ");
        
        interestRate = Double.parseDouble(display);
        
         display = JOptionPane.showInputDialog("Enter the amount of years  : ");
        
        years = Integer.parseInt(display);
        
        


        // create PaymentCalculator object using input values
        PaymentCalculator myCalc = new PaymentCalculator
                                   (amountBorrowed, interestRate, years);

        
        
           PaymentCalculator xCalc = new PaymentCalculator
                                   (amountBorrowed, interestRate, 15);
              PaymentCalculator yCalc = new PaymentCalculator
                                   (amountBorrowed, interestRate, 30);
              
              double a = xCalc.computePayment();
             double b = yCalc.computePayment();
              
              double total = Math.abs(a-b);
              
              System.out.println("DIFFERENCE   Payment: $" + total + "\n");


        // print loan data
        System.out.println(myCalc.getData());

        // get payment amount
        double payment = myCalc.computePayment();

        // print payment amount
        System.out.println("Monthly Payment: $" + payment + "\n");
    }
}	// 	end of PaymentCalculatorTest class definition