//
//  Header.h
//  Lab2
//  Created T 9/30/12.
//  Reviewed 8/30/18 
//

#ifndef HEADER_H
#define HEADER_H

using namespace std;


class NumberArray
{
private:
    float *numbers ;
    int size;
    int number;
    int location;
    
    int highest;
    int lowest;
    int average;
  
    
public:
    
    //deconstructor
    ~NumberArray();
    
    //constructor
    NumberArray(int size);
    
    
    //member functions
    void fillScores();

    //accessors
    float getretreiveNumber(int location);
    float getminvalue();
    float getmaxvalue();
    float getaverage();
    
    //mutators
   
    

};

#endif
