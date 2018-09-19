
/**
 *Created by Tiago Moore on Oct 15, 2013.
 *  Copyright (c) 2013 __TJPrograms__. All rights reserved.
 * 
 */

import javax.swing.JOptionPane;

class CombinationLockTester
{
public static void main(String args[])
{
    // declare variables 
    String p1,p2,p3,try1,try2,try3;
    
    p1 = JOptionPane.showInputDialog("Enter the first letter of the default password.");
    
    p2 = JOptionPane.showInputDialog("Enter the second letter of the default password.");
    
    p3 = JOptionPane.showInputDialog("Enter the third letter of the default password.");
    // Make all letters uppercase 
   p1 = p1.toUpperCase();
   p2 = p2.toUpperCase();
   p3 = p3.toUpperCase();
   
    
    CombinationLock MyLock = new CombinationLock(p1,p2,p3);
    
    // first attempt invalid password
    try1 = JOptionPane.showInputDialog("Enter the first letter of the  password.");
                            // convert to uppercase letter
                         try1 = try1.toUpperCase();
                            // call method to 
                         MyLock.setPosition(try1);
    
    try2 = JOptionPane.showInputDialog("Enter the second letter of the  password.");
    
                          // convert input to upper case letter
                          try2 = try2.toUpperCase();
                          MyLock.setPosition(try2);
    
    try3 = JOptionPane.showInputDialog("Enter the third letter of the  password.");
  
                           try3 = try3.toUpperCase();
                           MyLock.setPosition(try3);
    
    System.out.print("\nThe original combination lock is : "+p1+" "+p2+" "+p3);
    
    System.out.print("\nThe password you tried to use to open the lock is: "+
            try1+" "+try2+" "+try3);
   
                             MyLock.tryToOpen();
    
    if (MyLock.isOpen())
       
       {
          System.out.println("\nThe combination is correct!. The lock is open.");
                   
       }
       
       else
       {
           System.out.println("\nIncorrect Combination! Lock did not open.");
       }
    
    
    
    
    
    //second attempt ( correct password)
    System.out.print("\n\nEnter the correct combination for the lock: ");
    
       
    try1 = JOptionPane.showInputDialog("Enter the first letter of the correct password.");
    
    
                            //convert to uppercase 
                            try1 = try1.toUpperCase();  
                            MyLock.setPosition(try1);
    
    try2 = JOptionPane.showInputDialog("Enter the second letter of the correct password.");
    
                             try2 = try2.toUpperCase();
                             MyLock.setPosition(try2);
                
    try3 = JOptionPane.showInputDialog("Enter the third letter of the correct password.");
                             try3 = try3.toUpperCase();
                             MyLock.setPosition(try3);
    
    // data user entered
      System.out.print("\nThe original combination lock is : "+p1+" "+p2+" "+p3);
    
    System.out.print("\nThe password you tried to use to open the lock is :"+
            try1+" "+try2+" "+try3);
   
    // try to open lock
     MyLock.tryToOpen();
    
    if (MyLock.isOpen())
       
       {
          System.out.println("\nThe combination is correct!. The lock is open.");
                   
       }
       
       else
       {
           System.out.println("\nIncorrect Combination. Lock did not open.\n");
       }
    
    MyLock.lock();
    
    
    // third attempt. invalid password
    
  
    System.out.print("\n\nEnter another incorrect  combination for the lock: ");
    
       
    try1 = JOptionPane.showInputDialog("Enter the first letter of the  password.");
    
    
     
                    try1 = try1.toUpperCase(); 
                    MyLock.setPosition(try1);
    
    try2 = JOptionPane.showInputDialog("Enter the second letter of the  password.");
                    try2 = try2.toUpperCase();
                    MyLock.setPosition(try2);
     
    try3 = JOptionPane.showInputDialog("Enter the third letter of the  password.");
                    //conver to uppercase 
                    try3 = try3.toUpperCase();
                    MyLock.setPosition(try3);
    
    //data user entered
      System.out.print("\nThe original combination lock is : "+p1+" "+p2+" "+p3);
    
    System.out.print("\nThe password you tried to use to open the lock is :"+
            try1+" "+try2+" "+try3);
   
    
    // try to open lock
     MyLock.tryToOpen();
    
    if (MyLock.isOpen())
       
       {
          System.out.println("\nThe combination is correct!. The lock is open.");
                   
       }
       
       else
       {
           System.out.println("\nIncorrect Combination. Lock did not open.");
       }
    
    
    System.exit(0);
    
    
    
}

}
