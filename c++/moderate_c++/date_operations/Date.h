//
//  Date.h
//  Homework
//
//  Created by TJ Moore on 11/6/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef Homework_Date_h
#define Homework_Date_h

#include <iostream>

using namespace std;


class Date;

ostream &operator << (ostream & , const Date &);
istream &operator >> (istream & , Date &);



class Date
{
    
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int,int,int);
    
    int getDay() const;
    int getMonth() const;
    int getyear() const;
    
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    
    void displayfunction();
    
    //overloaded operator functions
    int operator - (const Date &);
    Date operator ++();      //Prefix ++
    Date operator ++(int);    //Postfix ++
    Date operator --();      //Prefix ++
    Date operator -- (int);    //Postfix ++
    
    void operator = (const Date &right);
  
    friend ostream &operator << (ostream & , const Date &);
    friend istream &operator >> (istream & , Date &);

    
    
};





#endif
