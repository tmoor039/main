My Hash Functions works as follows:

I have the simple standard hash function that simply takes the value of the 
the string and mods it by the size of the table accordingly. This distribution 
works however there are a decent amount of colissions. 

My second hash function produces a simular result, but it hashes to different indexes
because of the fact that it squares each of the characters in the string. By squaring
the characters of the string and moding it by the table size, the function will map to
different indexes than the original function, however the distribution is not much more 
efficient because the strings will get the amount of time a collision will happen with 
the square of a number, is the same as the collision will happen with the square root
of a number since it is working with the same number.On the other hand, if more arithmetic
was done to the square of the number such as dividing by an integer, the distribution would
be different from the original simple string function.

