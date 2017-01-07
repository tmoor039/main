/**
 * Computes the area of a triangle using Heron's formula
 */
public class Heron
{
    // instance variable
    private double side1;	// lengths of the 3 sides
    private double side2;
    private double side3;

    /**
     * Create a triangle, given the lengths of the sides
     * @param side1 length of a side
     * @param side2 length of another side
     * @param side3 length of the other side
     */
    public Heron(double side1, double side2, double side3)
    {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    /**
     * Compute and return the area using Heron's formula:
     *  
     * area = the square root of ( s * (s - a) * (s - b) * (s - c) )
     *      where s = 1/2 the perimeter, and 
     *            a, b, c are the side lengths
     *
     * @return the area of the triangle
     */
    public double getArea()
    {
        // replace the 0.0 in the variable declaration below with a
        // formula that computes half of the perimeter (the perimeter
        // is the sum of the lengths of the sides)

        double halfPerim = (side1+side2+side3)/2;



        // replace the 0.0 in the declaration below with Heron's formula

        double area = Math.sqrt( halfPerim * (halfPerim - side1) * (halfPerim - side2) 
                * (halfPerim - side3));
        
        
        

        return area;
    }

    /**
     * Return a string containing the lengths of the 3 sides
     * @return the lengths of the 3 sides, as a String
     */
    public String toString()
    {
        return side1 + ", " + side2 + ", " + side3;
    }
}