//
//  Header.h
//  Lab2
//
//  Created by James Moore on 9/30/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
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
