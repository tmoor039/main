//
//  Header.h
//  practicestacks
//
//  Created on 10/6/12.
//  Reviewed 9/1/2018

#ifndef practicestacks_Header_h
#define practicestacks_Header_h

// declares basic elements for a integer array stack 
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
