//
//  CharHeader.h
//  Project1
//
//  Created by James Moore on 10/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Project1_CharHeader_h
#define Project1_CharHeader_h

class CharStack
{
private:
    char  *stack;
    int stacksize, stacktop;
    
public:
    
    
    //constructors
    
    CharStack(int);
    
  CharStack(const CharStack &);
    
    ~CharStack();
    
    
    void push(char);
    void pop(char&);
    bool isEmpty() const;
    bool isFull() const ;

    
    char getbottom();
};



#endif
