//
//  Date.h
//  Lab3
//
//  Created by TJ Moore on 11/5/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#ifndef DATE_H
#define DATE_H
// for this homework, assume the data entered by the user will always be valid.
// therefore, no input validation is necessary

//forward declaration of the class Date

#include <iostream>

using namespace std;


class Date;

ostream &operator << (ostream & , const Date &);
istream &operator >> (istream & , Date &);



class Date
{
private:
	int day;    // 1-28 for Feb. ignore leap years
    // 1-31 for Jan. Mar. May, Jul. Aug. Oct. Dec.
    // 1-30 for Apr. Jun. Sep. Nov.
	int month;  // 1-12
	int year;   // positive integer
    
    
public:
    // constructor
	Date();     // initialize to 1/1/1900
	Date(int d, int m, int y);
    
    // getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
    
    
    
    void displayfunction();
    
	// setters
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
    
    
    
    //overloaded operator functions
    int operator - (const Date &);
    Date operator ++();      //Prefix ++
    Date operator ++(int);    //Postfix ++
    Date operator --();      //Prefix ++
    Date operator -- (int);    //Postfix ++
    
    
    
    //declare friend functions
    
    friend ostream &operator << (ostream & , const Date &);
    friend istream &operator >> (istream & , Date &);
    
    
};

#endif