package Formatted;

/**
 * Created by Tiago Moore on Oct 24, 2013. Copyright (c) 2013 __TJPrograms__.
 * All rights reserved.
 */
/**
 * This problem calculates total shares for a company and displays it in total
 * and eighths.
 */
public class StockPortfolioFormatted
{
    //instance variables

    private String companyName; // name of the company
    private int shareNum;       // number of total shares
    private int dollarShare;    //whole dollar amount 
    private int eightShare;     // eighths amount of share 

    /**
     * Create a Stock with a name, total shares, and share amount in dollar and
     * eighths.
     *
     * @param n name of company
     * @param s total shares of company
     * @param d dollar amount of share
     * @param e eigthts amount of share
     */
    public StockPortfolioFormatted(String n, int s, int d, int e)
    {
        companyName = n; // passes in company name to instance variable 
        shareNum = s;    // passes number of shares to instance variable 
        dollarShare = d; // passes dollar amount to instance variable
        eightShare = e;  // passes eight amount to isntance variable 
    }

    /**
     * Get the name of the company
     *
     * @return the name of the company
     */
    public String getname()
    {
        return companyName;

    }

    /**
     * Get the number of shares
     *
     * @return the total number of shares of the company
     */
    public int getnumshares()
    {
        return shareNum;
    }

    /**
     * Get the dollar amount of the shares
     *
     * @return the dollar amount
     */
    public int getdshares()
    {
        return dollarShare;
    }

    /**
     * Get the eight amount of the stock
     *
     * @return the eight amount
     */
    public int geteshares()
    {
        return eightShare;
    }

    /**
     * Changes the price of the stock
     *
     * @param d The dollar amount to be changed
     * @param e The eigth amount to be changed
     */
    public void modifyprice(int d, int e)
    {
        dollarShare = dollarShare + d + (((eightShare + e) / 8) - ((eightShare
                + e) % 8) / 8); // calcualtes and changes the price of stock 
        eightShare = (eightShare + e) % 8;
    }

    /**
     * Computes the current price of the stock
     *
     * @return the price of the stock
     */
    public double computeFolio()
    {
        //calculates and returns the total value of the share 
        return (double) (dollarShare * shareNum) + (((double) eightShare / 8) * shareNum);

    }

}
