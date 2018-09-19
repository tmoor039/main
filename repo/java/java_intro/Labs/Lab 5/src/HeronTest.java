
import javax.swing.JOptionPane ; 



public class HeronTest
{
    public static void main(String args[])
    {
        double side1 = 0;   // note: initialiazations necessary only
        double side2 = 0;   // to get "skeleton" program to run
        double side3 = 0;

        // insert statements here to get the lengths of the sides
        // from the user and store them in side1, side2, and side2

String display = JOptionPane.showInputDialog("Enter the value of side 1 : ");

side1 = Double.parseDouble(display);

 display = JOptionPane.showInputDialog("Enter the value of side 2 : ");
 
 side2 = Double.parseDouble(display);
 
 
 display = JOptionPane.showInputDialog("Enter the value of side 3 : ");
 
  side3 = Double.parseDouble(display);
 

        Heron heron = new Heron(side1, side2, side3);

        System.out.println("A triangle with sides of " + heron.toString()
                + "...\n...has area of " + heron.getArea());
    }
}
		
		
	