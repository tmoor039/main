
import javax.swing.JOptionPane;	// for showInputDialog

/**
 *  A class to represent a "payment calculator" which computes the "equal 
 *  monthly payment amount" for a fixed-rate loan based on the amount borrowed, 
 *  the annual interest rate, and the number of years in which the loan will be
 *  repaid..
 */
public class PaymentCalculator {
    // instance vars

    int principal;     // the amount borrowed
    double rate;       // annual interest rate, as a percent
    int years;         // term of loan in years

    /**
     * Create a payment calculator object.
     * @param amount the principal (amount borrowed)
     * @param interestRate the annual rate of interest, as a per cent (APR)
     * @param term the number of years to repay the loan
     */
    public PaymentCalculator(int amount, double interestRate, int term)
    {
        principal = amount;
        rate = interestRate;
        years = term;
    }

    /**
     * Computes and returns the equal monthly payment amount on a loan
     *
     *                                            -N
     * uses formula:  Payment = AR / ( 1 - (1 + R)   )
     *
     *     where   A is principal (amount borrowed),
     *			      R is MONTHLY rate -- as a DECIMAL, and
     *             N is term of loan in MONTHS.
     *
     * @return the equal monthly payment amount
     */
    public double computePayment()
    {
        int months = years * 12;    // convert years to months

        // convert rate from annual percent to monthly decimal
        // (divide by 12 for monthly, by 100 for decimal)
        double mRate = rate / 1200;

        // modify the following statement so that the proper value is assigned
        // to variable "payment," instead of 0.0.  The formula appears above...

        double payment = (principal*mRate)/(1-Math.pow((1+mRate),months));
        return payment;
    }

    /**
     * Return a string containing the loan data.
     * @return the principal, annual interest rate, and term, as a string.
     */
    public String getData()
    {
        String output = "\nLoan amount:\t$" + principal
                + "\nInterest rate:\t" + rate + "%"
                + "\nTerm of Loan:\t" + years + " years\n";
        return output;
    }
}	// end of PaymentCalculator class definition