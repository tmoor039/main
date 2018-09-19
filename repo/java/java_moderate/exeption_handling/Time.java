/**
 * A class to store the Time in military format (i.e., a 24-hour clock)
 * @author shawg
 */
public class Time 
{
    // instance vars store time in military format
    private int hour;		// 0..23
    private int minute;		// 0..59
    private int second;		// 0..59

    /*
     * Create a Time object
     * @param hr the hour portion
     * @param min the minute portion
     * @param sec the second portion
     */
    public Time(int hr, int min, int sec)
    {
        // eliminate duplicate code by passing param's to "set" methods
        this.setHour(hr);
        this.setMinute(min);
        this.setSecond(sec);
    }

    /*
     * Convert a Time object to A.M./P.M. and return it
     * @return a String containing the time as hh:mm:ss a.m. or p.m.
     */
    public String toString() 
    {
        String out = "";	

        if (hour == 0) {
            out += "12";
        } else if (hour <= 12) {
            out += hour;
        } else {
            out += hour % 12;
        }

        // assure two-digit minute
        if (minute <= 9) {
            out += ":0" + minute;
        } else {
            out += ":" + minute;
        }

        // assure two-digit second
        if (second <= 9) {
            out += ":0" + second;
        } else {
            out += ":" + second;
        }

        // a.m. or p.m.?
        if (hour <= 11) {
            out += " A.M.";
        } else {
            out += " P.M.";
        }

        return out;
    }

    /**
     * Set a Time object to a specified hour, minute, and second, 
     * and return a reference to that object
     * @param hr the hour 
     * @param min the minute
     * @param sec the second 
     * @return a reference to the object for which the method was called
     */
    public Time setTime(int hr, int min, int sec) 
    {
        // pass parameters to "set" methods to save code
        this.setHour(hr);		
        this.setMinute(min);
        this.setSecond(sec);
        return this;            //the object for which the method was called
    }

    /**
     * Set the hour part of a Time object and return a reference to
     * that object
     * @param hour the new hour
     * @return a reference to the object for which the method was called
     */
    public Time setHour(int hour)
    {
        this.hour = (hour >= 0 && hour <= 23) ? hour : 0 ;
        return this ;
    }

    /**
     * Set the minute part of a Time object and return a reference to
     * that object
     * @param minute the new minute
     * @return a reference to the object for which the method was called
     */
    public Time setMinute(int minute)
    {
        this.minute = (minute >= 0 && minute <= 59) ? minute : 0 ;
        return this ;
    }

    /**
     * Set the second part of a Time object and return a reference to
     * that object
     * @param second the new second
     * @return a reference to the object for which the method was called
     */
    public Time setSecond(int second)
    {
        this.second = (second >= 0 && second <= 59) ? second : 0 ;
        return this ;
    }
}