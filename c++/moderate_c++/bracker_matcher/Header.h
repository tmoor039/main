//
//  Header.h
//  practicestacks
//
//  Created by James Moore on 10/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef practicestacks_Header_h
#define practicestacks_Header_h


class characterStack
{
    private:
    
    char *stacks;
                
    int arraysize;
    
    int arraytop;
    
    public:
    
    //constructor
    characterStack(int);// parameter taking the size
    
   
    characterStack(const characterStack & );
    
     //deconstructor
    ~characterStack();
    
    
    //stack functions
    
    void push(char);
    void pop(char &);
    bool isFull() const;
    bool isEmpty() const;
    
};


#endif
