/**
   A triangular shape composed of stacked unit squares like this:
   []
   [][]
   [][][]
   . . .
*/
public class Triangle
{
   private int width ;     // width (in number of boxes) of the base

   /**
      Constructs a triangular shape.
      @param aWidth the width (and height) of the triangle
   */
   public Triangle(int aWidth)
   {
      width = aWidth;
   }

   /**
      Computes the area of the triangle.
      @return the area
   */
   public int getArea()
   {
      if (width == 1)      // trivial case
      { 
         return 1 ; 
      }
      if (width <= 0)      // another trivial case (for error-checking)
      { 
         return 0 ;
      }

      // create a maller triangle - a "reduced case" of the problem
      Triangle smallerTriangle = new Triangle(width - 1) ;
      
      // recursive call with "reduced case"
      int smallerArea = smallerTriangle.getArea() ;
      
      // area of larger triangle is area of smaller plus width of larger!
      return smallerArea + width ;
   }
}