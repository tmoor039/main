/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Tiago Moore Section 6
 * 
 * This problem calculates total shares for a company and displays it in total 
 * and eighths. 
 */
public class StockPortfolio
{
    //instance variables
    String companyName;
    int shareNum;
    int dollarShare;
    int eightShare;
   
    
public StockPortfolio(String n,int s, int d, int e)
{
    companyName = n;
    shareNum = s;
    dollarShare = d;
    eightShare = e;
}


public String getname()
{
    return companyName;
   
}

public int getnumshares()
{
    return shareNum;
}

public int getdshares()
{
    return dollarShare;
}

public int geteshares()
{
    return eightShare;
}

public void modifyprice(int d, int e)
{
    dollarShare = dollarShare + d +(((eightShare+e)/8)-((eightShare+e)%8)/8);
    eightShare = (eightShare+e)%8;
}


public double computeFolio()
{
  return (double)(dollarShare*shareNum)+(((double)eightShare/8)*shareNum);
  
}      
  
   
}