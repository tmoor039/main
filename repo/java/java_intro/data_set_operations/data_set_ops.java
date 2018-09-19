
//	File:	LabDataSetTester.java

//	The LabDataSet class computes the average and maximum of any number of 
//  integer test scores.

//	The test class shows how to use a while loop to process a set of data until
//  end-of-file.
//  (To indicate end-of-file using showInputDialog, click Cancel and test 
//  for null)

import javax.swing.JOptionPane;

/**
 * Computes the average and maximum of any number of integer test scores.  
 */
class LabDataSet
{
   private int sum;			// sum of the scores in the set
   private double count;		// number of scores in the set
   private int maximum;		// largest score in the set
   private int low;

   /**
    * Create an empty data set
    */
   public LabDataSet()
   {
      count = 0.0;
      sum = 0;
      maximum = Integer.MIN_VALUE;     // -2,147,483,648
      low = Integer.MAX_VALUE; // maximum vale 
   }

   /**
    * Add a score to the data set
    * @param currentScore the score to be added
    */
   public void add(int currentScore)
   {
      sum = sum + currentScore;     // accumulate sum of scores
      count++;                    // one more score added

      // conditionally update the largest score
      if (currentScore > maximum)	// if current score is largest so far...	
      {
         maximum = currentScore;	// ...save it as new maximum
      }
      
      if (currentScore < low )
      {
          low = currentScore;
      }
   }
   
   /**
    * Compute and return the average of the scores
    * @return the average of the scores
    */
   public double getAverage()
   {
      return sum / count;
   }
   
   /**
    * Is the data set empty?
    * @return true if the set is empty, false if non-empty
    */
   public boolean isEmpty()
   {
      return count == 0 ;
   }
   
   /**
    * Get the largest score
    * @return the largest score
    */
   public int getMaximum()
   {
      return maximum;
   }
   
   public int getlow()
   {
       return low;
   }
}

public class LabDataSetTester
{
   public static void main(String[] args)
   {
      LabDataSet set = new LabDataSet();	// create empty data set

      JOptionPane.showMessageDialog(null, "I will compute the average and "
            + "maximum for any number of integers");
do
{
      // "priming" read
      String input = JOptionPane.showInputDialog("Enter an integer\n" +
                                            "(or click Cancel to quit)");

      while (input != null)      // while not end-of-file
      {
         int score = Integer.parseInt(input);
         System.out.println("You entered: " + score);
         set.add(score);
         input = JOptionPane.showInputDialog("Enter another integer" +
                                         "\n(or click Cancel to quit)");
      }
           
      if(set.isEmpty())
      {
          System.out.print("Error! Must have at least one value!");
      }
}while(set.isEmpty());

      System.out.println("\nThe average is:\t" + set.getAverage() +
                       "\nThe maximum is:\t" + set.getMaximum()+
                         "\nThe minumum is :\t"+ set.getlow());
   }
}