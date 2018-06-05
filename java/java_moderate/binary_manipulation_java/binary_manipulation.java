

/**
 *Created by Tiago Moore on Jan 15, 2014.
Program # : Manipulate binary numbers , hexadecimal, and decimal . 
Due Date : 01/27/2014 
Last review : 1/29/2018
* TODO: Line 140: Make recursive solutions
**/

import java.io.*;
import java.util.*;

public class MooreTpgm1 
{
    
  private static char firstBinaryArray[] ;
  private static char secondBinaryArray[];
  private int sizeOfFirstLine;
  private int sizeOfSecondLine;
  private int x =  0;
  private int InputArray1[] = new int[4];
  private int InputArray2[] = new int[4];
  private String  HexaNumb = "";
  private boolean zerocarry = false;
  private boolean firstcarry = false;
  private boolean secondcarry = false;
  private boolean thirdcarry = false;
  private boolean forthcarry = false;
  private boolean fithcarry = false;
  private boolean sixthcarry = false;
  private boolean seventhcarry=false;
      
  
  public static void main(String[] args) throws IOException
  {
       //create homework 1 object 
      MooreTpgm1 hw = new MooreTpgm1();
      // read in values from text file 
      hw.createFile();
      //chages it so that we can subract with position 0 in the array first
      hw.fixPositions();
      // add one to the second array  to get the twos complement 
      hw.addOne();
      // adds the two binary arrays and displays the result
      hw.printFinalResult();
      // prints and or nand and nor with the steps
      hw.printNorNAnd();
      // prints demorags table from the book with the given inputs 
      hw.printDemorgans();
      //prits the hexadecimal in binary
      hw.printDeciFromHexa(hw.hexaToDeci());
  
  }
    
  public void createFile() throws IOException
  {
    // Note: The scanner way to do the same thing is commented out for development purposes.

    //create file
       File textFile = new File("TextFile.txt");
    
    // BufferedReader 
        BufferedReader input = new BufferedReader(new FileReader(textFile));

     //create a scanner object to read from textFile
     //Scanner reader = new Scanner(textFile);
    
     // get size of first 
     String firstLine = input.readLine();
    // String firstLine = reader.next();
      sizeOfFirstLine = firstLine.length();
     // get size of second line
    // String secondLine = reader.next();
      String secondLine  = input.readLine();
      sizeOfSecondLine = secondLine.length();
    
     // now create  and fill an array with the size of the first binary number
      firstBinaryArray = new char[sizeOfFirstLine];
      for(int i = sizeOfFirstLine-1 ; i > -1 ; i --)
      {
       firstBinaryArray[i] = firstLine.charAt(i);

      }
    // create and fill an char array with the size of the second binary number 
      secondBinaryArray = new char[sizeOfSecondLine];
      for(int i = 0 ; i < sizeOfSecondLine ; i ++)
      {
       secondBinaryArray[i] = secondLine.charAt(i);

      }
       
     // populate the arrays with the inputs for the next 4 lines 
     for( int i = 0 ; i < 4 ; i ++)
     {
      // InputArray1[i]= reader.nextInt();
       //InputArray2[i]= reader.nextInt(); have to convert ascii value
       do
       {
         InputArray1[i] = Character.getNumericValue(input.read());
         if(InputArray1[i]!= 1 && InputArray1[i] != 0)
         {
           InputArray1[i] = Character.getNumericValue(input.read());// convert next char to int
         }
       }while((InputArray1[i]!= 1 &&InputArray1[i] != 0));// do while the next char is not binary
         
        // if there is a blank space, skip
        do
       {
         InputArray2[i] = Character.getNumericValue(input.read());
         if(InputArray2[i]!= 1 &&InputArray2[i] != 0)
         {
           InputArray2[i] = Character.getNumericValue(input.read());// convert next char to int
         }
       }while((InputArray2[i]!= 1 &&InputArray2[i] != 0));// do while next char is not binary
     }
    
      input.skip(1);// go to the next line 
      HexaNumb = input.readLine(); //get the hexadecimal number
  }
  

  public char getComplement(char x)
  {
    // returns the complement of the character binary value 
        if (x == '0')
        {
            return '1';
        }
        
        else if( x == '1')
        {
            return '0';
        }
        
        else
        {
            System.out.println("Warning! Invalid Data, the number is not binary.");
            System.exit(0);
            return 0;
        }
      }
    
    
  public int add(int pos1, char x, char y)
  {
    // passes in the position of the binary array thats being subtracted
      
        if(firstcarry)// if you are subtracting one, you will need to carry 8 times
         {
        firstcarry = false;
        return 1;
          }
        else if(secondcarry)
        {
          secondcarry = false;
         return 1;
        }
        else if(thirdcarry)
        {
         thirdcarry = false;
         return 1;
        }
        else if(forthcarry)
        {
          forthcarry = false;
         return 1;
        }
        else if(fithcarry)
        {
          fithcarry = false;
         return 1;
        }
        else if(sixthcarry)
        {
          sixthcarry = false;
         return 1;
        }
        else if(seventhcarry)
        {
          seventhcarry = false;
         return 1;
        }
   
        else if ( x== '0' && y == '0')
        {
            return 0;
        }
        else if ((x == '1' &&y == '0') || x == '0' && y == '1')
        {
            return 1;
        }
        
        else if( x == '1' && y =='1')
        {
            carry(pos1); // change arrays
            return 0;
        }
        else
        {
          System.out.println("Error in add method.");

          return 0;
        }
        
      
        
        
    }

  public void carry( int x)
  {
    // this method is a nested if structure to implement a carry
    // it tries to change the position in front of the carry to a 1 , if it cant it carrys on
    // the carry method will only implement a carry of up to one byte (8positions)
      boolean changed = false;
      
      if(x<8)//make sure you dont go out of bounds of the array
      {         
      if( firstBinaryArray[x+1]== '0')
      {
        changed = true;
        firstBinaryArray[x+1]= '1';
        
      }
      else if( secondBinaryArray[x+1] == '0'&& !changed)
      {
        secondBinaryArray[x+1] = '1';
      }
      
      else if (firstBinaryArray[x+1]=='1' && secondBinaryArray[x+1] == '1'&&x <7 )
      {
        //this.x = 1;
       // boolean changed = false;
        firstcarry = true;
   
        if (firstBinaryArray[x+2]=='0')
           {
             changed = true;
             firstBinaryArray[x+2]='1';
           }  
        
        if(secondBinaryArray[x+2]=='0'&& !changed)
        {
          changed = true;
          secondBinaryArray[x+2]= '1';
        }
        
        if(firstBinaryArray[x+2]=='1' && secondBinaryArray[x+2] == '1'&& !changed&& x < 5)
        {
          secondcarry = true;
          if(firstBinaryArray[x+3]=='0')
          {
            changed = true;
            firstBinaryArray[x+3] = '1';
          }
          if(secondBinaryArray[x+3]=='0'&& !changed)
        {
          changed = true;
          secondBinaryArray[x+3]= '1';
        }
          
           if(firstBinaryArray[x+3]=='1' && secondBinaryArray[x+3] == '1'&& !changed&& x < 4)
           {
             thirdcarry = true;
             
             if(firstBinaryArray[x+4]=='0')
          {
            changed = true;
            firstBinaryArray[x+4] = '1';
          }
          if(secondBinaryArray[x+4]=='0'&& !changed)
           {
            changed = true;
            secondBinaryArray[x+4]= '1';
           }
             
             if(firstBinaryArray[x+4]=='1' && secondBinaryArray[x+4] == '1'&& !changed&& x < 3)
           {
             forthcarry = true;
             
             if(firstBinaryArray[x+5]=='0')
          {
            changed = true;
            firstBinaryArray[x+5] = '1';
          }
          if(secondBinaryArray[x+5]=='0'&& !changed)
           {
            changed = true;
            secondBinaryArray[x+5]= '1';
           }
          
          if(firstBinaryArray[x+5]=='1' && secondBinaryArray[x+5] == '1'&& !changed&& x < 2)
           {
             fithcarry = true;
             
             if(firstBinaryArray[x+6]=='0')
          {
            changed = true;
            firstBinaryArray[x+6] = '1';
          }
          if(secondBinaryArray[x+6]=='0'&& !changed)
           {
            changed = true;
            secondBinaryArray[x+6]= '1';
           }
          
          if(firstBinaryArray[x+6]=='1' && secondBinaryArray[x+6] == '1'&& !changed&& x < 1)
           {
             sixthcarry = true;
             
             if(firstBinaryArray[x+7]=='0')
          {
            changed = true;
            firstBinaryArray[x+7] = '1';
          }
          if(secondBinaryArray[x+7]=='0'&& !changed)
           {
            changed = true;
            secondBinaryArray[x+7]= '1';
           }
          
          if(firstBinaryArray[x+7]=='1' && secondBinaryArray[x+7] == '1'&& !changed&& x == 0)
           {
             seventhcarry = true;
             
             if(firstBinaryArray[x+8]=='0')
          {
            changed = true;
            firstBinaryArray[x+8] = '1';
          }
          if(secondBinaryArray[x+8]=='0'&& !changed)
           {
            changed = true;
            secondBinaryArray[x+8]= '1';
           }}}}}}}}// end of all 8 if structures
       }
            
           
           
           
           
           
    }
    
  public void addOne()
  {
   // takes the first complement of the second line 
  char ComplementArray[] = new char[sizeOfSecondLine];
  MooreTpgm1 home = new MooreTpgm1();

  for (int i = 0; i < sizeOfSecondLine; i ++)
  {
    ComplementArray[i] = home.getComplement(secondBinaryArray[i]);
  }
  
    // fill an entire char arrays with 0 to add with compelment
 
  if(ComplementArray[0]=='0')
  {
    ComplementArray[0] = '1';
  }
  else if(ComplementArray[0]=='1')
  {
    int spot = 1;
   ComplementArray[0]='0';

   for (int i = 1 ; i < sizeOfSecondLine&&ComplementArray[i]=='1'; i ++)
   {
     
     ComplementArray[i]='0';    
     spot ++;
   }
   // implement the carry  to the ones complement
   ComplementArray[spot]= '1';
   
  
  }
  
  else// make sure it worked
  {
    System.out.println("Error in Compliment method.");
  }
  
 secondBinaryArray = ComplementArray;
  }
  
  public void fixPositions()     
  {
    // reverses the positions in the arrays 
    char TempArray[] = new char[sizeOfFirstLine];
    
    for( int i = sizeOfFirstLine-1; i > -1 ; i--)
    {
      TempArray[sizeOfFirstLine-i-1] = firstBinaryArray[i];
    }
    firstBinaryArray = TempArray;
    
    char TempArray2[] = new char[sizeOfSecondLine];
    
     for( int i = sizeOfSecondLine-1; i > -1 ; i--)
    {
      TempArray2[sizeOfSecondLine-i-1] = secondBinaryArray[i];
    }
    secondBinaryArray = TempArray2;
  }
 
  public void printFinalResult()
  {
    MooreTpgm1 hw = new MooreTpgm1();
    //create final array to display the computation
      int FinalResut[] = new int[sizeOfSecondLine];
   
     // do the addition of the twos compliment
      for(int i = 0; i < sizeOfSecondLine; i ++)
      {
      // call the add method for the first two lines, and put the returned value in  a final array
      FinalResut[i] = hw.add(i,firstBinaryArray[i],secondBinaryArray[i]);

      }
    
      System.out.print("\n\nThe binary subtration of line 2 from line 1 of the text file is: ");
      
      // print the final binary number
       for(int i = sizeOfSecondLine-1; i >-1; i --)
      {
      
        System.out.print(FinalResut[i]);
      }
       
       // print the number in decimal and hexadecimal
       System.out.println("\nThe decimal equivalent is : "+ hw.toDecimal(FinalResut));
       System.out.println("The Hexadecimal equivalent is : "+ hw.toHexadecimal(FinalResut));
  }
  
  public int toDecimal(int binaryArray[])
  {
    int acummulator = 0;
    
    // for the size of the array, or line
    for ( int i = 0; i < binaryArray.length; i ++)
    {
      // if its a 1, then return 2 to the position 
      if(binaryArray[i]==1)
      {
      acummulator += Math.pow(2, i);
      }
    }
    
    return acummulator;
  }
  
  public String toHexadecimal(int binaryArray[])
  {
    //declare and initialize variables. 
    int arrayInDecimal = 0;
    String hexNumber="";
    int adder = 0;
    // create a homework object to use the toDecimal method
    MooreTpgm1 calc = new MooreTpgm1();
    
    arrayInDecimal = calc.toDecimal(binaryArray);
    
    while(arrayInDecimal!= 0)
    {
     adder = (arrayInDecimal%16);// devide by 16 and keep track of the remainder
     arrayInDecimal = arrayInDecimal/16; // update the devided number
     
      if (adder == 10)
      {
        hexNumber += "A";
      }
      else if (adder == 11)
      {
         hexNumber += "B";
      }
      else if (adder == 12)
      {
         hexNumber += "C";
      }
     else if (adder == 13)
      {
         hexNumber += "D";
      }
     else if (adder == 14)
      {
         hexNumber += "E";
      }
     else if (adder == 15)
      {
         hexNumber += "F";
      }

     else
      {
         hexNumber += Integer.toString(adder); // convert number to a string
      }
    
    }
    // print the string in reverse to show the proper Hexadecimal number
    String reverse = new StringBuffer(hexNumber).reverse().toString();
    //return the reversed string 
    return reverse;
  }

  public int andMethod(int x, int y )
  {
    // implements the and method "printing results for each step" as directed in instructions
    if(x == 0 || y == 0)
    {
    
      System.out.println("An input is 0 thefore the AND of " + x+" and "+y+" is 0.");
      return 0;
    }
    else if (x == 1 && y ==1 )
    {
      System.out.println("Both inputs are 1 therefore the AND of "+x+" and "+y+" is 1.");
      return 1;
    }
    else
    {
      System.out.println("Invalid data.");
      System.exit(0);
      return 0;
    }
    
  }
  
  public int orMethod(int x, int y)
  {
     // implements the or method "printing results for each step" as directed in instructions
    if(x == 1 || y == 1)
    {
      System.out.println("An input is 1 thefore the OR of " + x+" and "+y+" is 1.");
      return 1;
    }
    else if (x == 0 && y ==0)
    {
      System.out.println("Both inputs are 0 therefore the AND of "+x+"and "+y+"is 0.");
      return 0;
    }
    else
    {
      System.out.println("Invalid data.");
      System.exit(0);
      return 0;
    }
    
    
  }
  
  public void nandMethod(int method )
  {
     // implements the nand method "printing results for each step" as directed in instructions
   if(method == 0)
   {
     System.out.println("The AND is 0 therefore the NAND is 1.");
     System.out.println("__________________________________________________");
     
   }
   
   else if (method == 1)
    {
      System.out.println("The AND is 1 therefore the NAND is 0");
      System.out.println("__________________________________________________");
      
    }

  }
      
  public void norMethod(int method )
  {
     // implements the nor method "printing results for each step" as directed in instructions
   if(method == 0)
   {

     System.out.println("The OR is 0 therefore the NOR is 1.");
     System.out.println("__________________________________________________");
     
   }
   
   else if (method == 1)
    {
       
      System.out.println("The OR is 1 therefore the NOR is 0.");
      System.out.println("__________________________________________________");
      
    }
   

}   
  
  public void printNorNAnd()
  {
    MooreTpgm1 hw = new MooreTpgm1();// create a dummy object to call methods
    System.out.println("\n\n------------------------------------------------------------------\n\n");
      
   
       //evaluate the NAND method
           for( int i = 0; i < InputArray1.length; i ++)
      {
       
        hw.nandMethod(hw.andMethod(InputArray1[i],InputArray2[i]));
        
      }

   System.out.println("\n\n------------------------------------------------------------------\n\n");
      
     //evaluate the NAND method
           for( int i = 0; i < InputArray1.length; i ++)
      {
       
        hw.norMethod(hw.orMethod(InputArray1[i],InputArray2[i]));
 
      }
   System.out.println("\n\n------------------------------------------------------------------\n\n");
    
  }
  
  public void printDemorgans()
  {
    //create a homework1 method 
    MooreTpgm1 W = new MooreTpgm1();
    System.out.print("The demorgans law table for records 3 4 5 6 :\n\n\n\n");
    System.out.println("A  U|Ā  Ū|AND|C");
    System.out.println("----|----|---|-");
    for( int i = 0; i < InputArray1.length; i++)// for both inputs, calls and and or and inverts 
    {                                           // them as well for the demorgans principle
    System.out.println(InputArray1[i]+"  "+InputArray2[i]+"|"+W.inverter(InputArray1[i])+
     "  "+W.inverter(InputArray2[i])+"|"+" "
     +W.and(W.inverter(InputArray1[i]), W.inverter(InputArray2[i]))
     +" |"+W.or(W.inverter(InputArray1[i]),W.inverter(InputArray2[i])));
    }
   System.out.println("\n\n------------------------------------------------------------------\n\n");
  }
    
  public int inverter(int number)
  {
    //inverts an integer binary value
    if(number == 0)
    {
 return 1;
    }
    else if (number == 1)
    {
      return 0;
    }
    

    else
    {
      System.out.print("Error in inveter method, number not binary.");
      return 0;
     
    }
  }
     
  public int and(int x, int y )
  {
    // implements an add method without printing results for each step
    if(x == 0 || y == 0)
    {
      return 0;
    }
    else if (x == 1 && y ==1 )
    {
      return 1;
    }
    else
    {
      System.out.println("Invalid data.");
      System.exit(0);
      return 0;
    }
    
  }
  
  public int or(int x, int y)
  {
    // implements an or method without printing results for each step
    if(x == 1 || y == 1)
    {
      return 1;
    }
    else if (x == 0 && y ==0)
    {
      return 0;
    }
    else
    {
      System.out.println("Invalid data.");
      System.exit(0);
      return 0;
    }
    
    
  }

  public String hexaToDeci()
  {
      int count = 0;
      int place = 0;
      int adder = 0;
      String backwardsNum =""; 
      String binaryNum = "";
      int hex[] = new int[HexaNumb.length()]; // new array for the hex number
      //
      for(int i = 0; i < HexaNumb.length(); i++)
        {
          if(HexaNumb.charAt(i) == 'A')
          {
            backwardsNum ="";
            place = 10; 
            while( count != 4)
            {
              count++;
              adder = place%2; // same conecept as toHexa, devide by 2 keep track of remainder
              place = place/2;// update the devided value
              Integer.toString(adder); //convert the remainder to a string
              backwardsNum += adder;// update  the result
              String reverse = new StringBuffer(backwardsNum).reverse().toString();
              backwardsNum = reverse;// fixes the result to make sure it updates from right to left
            }
            count = 0;
            //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }
            else if(HexaNumb.charAt(i) == 'B')// repeats for BCDEF
          {
            backwardsNum ="";
            place = 11; 
            while( count != 4)
            {
              count++;
              adder = place%2;
              place = place/2;
              Integer.toString(adder);
              backwardsNum += adder;
            }
              count = 0;
              //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }
          
           else if(HexaNumb.charAt(i) == 'C')
          {
            backwardsNum ="";
            place = 12; 
            while( count != 4)
            {
              count++;
              adder = place%2;
              place = place/2;
              Integer.toString(adder);
              backwardsNum += adder;
             
            }
              count = 0;
              //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }
          
           else if(HexaNumb.charAt(i) == 'D')
          {
            backwardsNum ="";
            place = 13; 
            while( count != 4)
            {
              count++;
              adder = place%2;
              place = place/2;
              Integer.toString(adder);
              backwardsNum += adder;
            }
              
            
              count = 0;
              //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }
          
           else if(HexaNumb.charAt(i) == 'E')
          {
            backwardsNum ="";
            place = 14; 
            while( count != 4)
            {
              count++;
              adder = place%2;
              place = place/2;
              Integer.toString(adder);
              backwardsNum += adder;
            }
              count = 0;
              //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }
          
           else if(HexaNumb.charAt(i) == 'F')
          {
            backwardsNum ="";
            place = 15; 
            while( count != 4)
            {
              count++;
              adder = place%2;
              place = place/2;
              Integer.toString(adder);
              backwardsNum += adder;
            }
              count = 0;
              //flip the binary number
              for (int j = 3; j > -1 ; j--)
              {
                binaryNum += backwardsNum.charAt(j);
                
              }
          }

          }
      
     
          return binaryNum ;
               
        }
  public void printDeciFromHexa(String hexaInDeci)
  {
    MooreTpgm1 hw = new MooreTpgm1();
   System.out.print("The Hexadecimal number in record 7 is: "+hexaInDeci+" in binary.");
   
   int hexaInBinary[] = new int[hexaInDeci.length()];
   int hexInBin = 0;
   
   //put the string in to a different array
   for (int i = hexaInDeci.length()-1; i> -1 ; i --)
   {
     // get the string at the charater at the beggining of the number, makes it a string
     hexInBin = Integer.parseInt(Character.toString(hexaInDeci.charAt(i)));
    //writes it into an array reversed, so that we can put that in the toDecimal method
     hexaInBinary[hexaInDeci.length()-i-1] = hexInBin;
   }
   
   hw.toDecimal(hexaInBinary);
  System.out.println("\n\nThe Hexadecimal number in record 7 is: "+hw.toDecimal(hexaInBinary)+" in "
          + "decimal.");
  }
    
}
