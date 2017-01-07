/**
 *  A class to represent a circle.
 */
public class Circle
{
	// instance variables
	private double x ;			// x-coordinate of center
	private double y ;			// y-coordinate of center
	private double radius ;		// radius of circle
	
	/**
	 * Create a circle object with center at point 
	 * x,y and a given radius.
	 * @param x the x-coordinate of the center
	 * @param y the y-coordinate of the center
	 * @param radius the radius
	 */
	public Circle (double x, double y, double radius)
	{
		this.x = x ;
		this.y = y ;
		this.radius = radius ;
	}
	
	/**
	 * Get the x-coordinate of the center.
	 * @return the x-coordinate of the center
	 */
	public double getX()
	{
		return x ;
	}
	
	/**
	 * Get the y-coordinate of the center.
	 * @return the y-coordinate of the center
	 */
	public double getY()
	{
		return y ;
	}
	
	/**
	 * Get the radius.
	 * @return the radius
	 */
	public double getRadius()
	{
		return radius ;
	}
	
	/**
	 * Reset the radius to a specified value.
	 * @param newRadius the new radius of the circle
	 */
	public void setRadius(double newRadius)
	{
		this.radius = newRadius ;
	}
	
	/**
	 * Move a circle object to a specified point.
	 * @param newX the new x-coordinate of the center
	 * @param newY the new y-coordinate of the center
	 */
	public void move(double newX, double newY)
	{
		this.x = newX ;
		this.y = newY ;
	}
        
        
        
}