C Fundamentals exercise

Purpose of this program:
- Implement functions, if, else if, else, for, printf, 
  primitive types, String class with several functions, single dimension array.
          
1 - Worth 3 points
    In main()  
    - Create a single dimension array containing ONE index,
      which will have ONE string with your full name as follows:
    
         "first name $ middle name % last name and ONE space"
         i.e. "George & Washington % Rodriguez "
         Note: if you do not have a middle name use MN.
     
    - From main call a method named myName passing the previous array

    - In the myName method use the array received and
      using for loop, if, else if, else, ||, &&, printf, and any other 
      command you want that we have learned in class,
      Examine each character in your array and determine if it is:
      - a space, a vowel (a,e,i,o,u,A,E,I,O,U), a consonant (b,w,g, etc), the symbol %
        or the symbol $, and using the current value of x in your for loop print: 

          character [x] located at position x is a consonant   or
          character [x] located at position x is a vowel       or 
          character [x] located at position x is a space       or 
          character [x] located at position x is a symbol

          ie: My name is [George $ Washington % Rodriguez]

          character [G] located at position 0 is a consonant
          character [e] located at position 1 is a vowel
          character [o] located at position 2 is a vowel
          character [r] located at position 3 is a consonant
          character [g] located at position 4 is a consonant
          character [e] located at position 5 is a vowel
          character [ ] located at position 6 is a space
          character [$] located at position 7 is a symbol
          character [ ] located at position 8 is a space
          character [W] located at position 9 is a consonant
          character [a] located at position 10 is a vowel
          character [s] located at position 11 is a consonant
          character [h] located at position 12 is a consonant
          character [i] located at position 13 is a vowel
          character [n] located at position 14 is a consonant
          character [g] located at position 15 is a consonant
          character [t] located at position 16 is a consonant
          character [o] located at position 17 is a vowel
          character [n] located at position 18 is a consonant
          character [ ] located at position 19 is a space
          character [%] located at position 20 is a symbol
          character [ ] located at position 21 is a space
          character [R] located at position 22 is a consonant
          character [o] located at position 23 is a vowel
          character [d] located at position 24 is a consonant
          character [r] located at position 25 is a consonant
          character [i] located at position 26 is a vowel
          character [g] located at position 27 is a consonant
          character [u] located at position 28 is a vowel
          character [e] located at position 29 is a vowel
          character [z] located at position 30 is a consonant
          character [ ] located at position 31 is a space


2 - Worth 3 points 
    From main call a method named pyramid passing the previous array

    - In the pyramid method use the array received
      use a for loop, display to the screen, the string containing your name so that each 
      loop will NOT contain the first and the last character from the previous line, 
      with the length of the string being printed, and the string surrounded by square brackes [] 

      i.e:  32 [George $ Washington % Rodriguez ]
             30 [eorge $ Washington % Rodriguez]
              28 [orge $ Washington % Rodrigue]
               26 [rge $ Washington % Rodrigu]
                24 [ge $ Washington % Rodrig]
                 22 [e $ Washington % Rodri]
                  20 [ $ Washington % Rodr]
                   18 [$ Washington % Rod]
                    16 [ Washington % Ro]
                     14 [Washington % R]
                      12 [ashington % ]
                       10 [shington %]
                         8 [hington ]
                          6 [ington]
                           4 [ngto]
                            2 [gt]
                             0 []


3 - Worth 2 points
    From main call a method named parsing passing the previous arrayN
    - Print your name in upper case letters.
    - Print your name in lower case letters.
    - Print your name taking all spaces out.
    - Print your name with all vowels in upper case, and all consonants in lower case.
    - Print your name backwards.
    - Print your name in ASCII values. 


4 - Worth 2 points
    - Create a two dimensional array of 10 rows by 10 columns
    - Load each index with the multiplication of its x and y location
    - Add all the values in rows 3, 5, and 7, and print the total
    - Add all the values in columns 2, 4, and 6, and print the total
    - Subtract the total values (rows-columns), and print the difference.

