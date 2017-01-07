//
//  main.cpp
//  Homework
//
//  Created by TJ Moore on 11/6/12.
//  Copyright (c) 2012 TJ Moore. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "Date.h"


using namespace std;

Date::Date()
{
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(int d,int m,int y)
{
    day = d;
    month = m;
    year = y;
}


void Date::setDay(int d)
{
    day = d;
}

void Date::setMonth(int m)
{
    month = m;
}

void Date::setYear(int y)
{
    year = y;
}

int Date::operator - (const Date &right)
{
    
    int tmp = 0, tmp2= 0;
    
    tmp += right.year *365;
    tmp2 += year *365;
    
    switch (right.month) {
        case 1:
            //jan
            tmp+=0;
            
            break;
            
        case 2:
            //feb
            tmp += 31;
            
        case 3:
            //march
            tmp+= 59;
            
            break;
            
        case 4 :
            //april
            tmp += 90;
            
            break;
            
        case 5:
            //may
            tmp += 120;
            break;
            
        case 6:
            //june
            tmp +=151;
            break;
            
        case 7:
            //july
            tmp +=181;
            break;
            
        case 8 :
            //august
            tmp += 212;
            break;
            
        case 9 :
            //september
            tmp +=243;
            break;
            
        case 10:
            //october
            tmp+=273;
            break;
        case 11:
            //november
            tmp += 304;
            break;
        case 12:
            //december
            tmp += 334;
            break;
            
        default:
            break;
    }
    
    tmp += right.day;
    
    switch (month) {
        case 1:
            //jan
            tmp2+=0;
            
            break;
            
        case 2:
            //feb
            tmp2 += 31;
            
        case 3:
            //march
            tmp2+= 59;
            
            break;
            
        case 4 :
            //april
            tmp2 += 90;
            
            break;
            
        case 5:
            //may
            tmp2 += 120;
            break;
            
        case 6:
            //june
            tmp2 +=151;
            break;
            
        case 7:
            //july
            tmp2 +=181;
            break;
            
        case 8 :
            //august
            tmp2 += 212;
            break;
            
        case 9 :
            //september
            tmp2 +=243;
            break;
            
        case 10:
            //october
            tmp2+=273;
            break;
        case 11:
            //november
            tmp2 += 304;
            break;
        case 12:
            //december
            tmp2 += 334;
            break;
            
        default:
            break;
    }
    
    tmp2 += day;
    
    return abs (tmp2-tmp);
    
    
}

Date Date::operator ++ ( )
{
    
    
    
    if(month == 2)
    {
        
        
        if (day == 28)
        {
            month += 1;
            day = 1;
        }
        
        else
        {
            day += 1;
        }
        
        
    }
    
    else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10  )
        
    {
        
        
        if ( day == 31)
        {
            month += 1;
            day = 1;
        }
        
        else
        {
            day +=1;
        }
        
        
        
    }
    
    else if ( month == 4 || month == 6 || month == 9 || month == 11)
    {
        
        if ( day == 30)
        {
            month += 1;
            day  = 1;
        }
        
        else
        {
            day +=1;
        }
        
    }
    
    
    else if ( month == 12)
    {
        
        if (day == 31)
        {
            month = 1;
            day = 1;
            year += 1;
        }
        
        
    }
    
    return *this;
    
}

Date Date:: operator ++ (int d)
{
    
    Date temp(day,month,year);
    
    
    if(month == 2)
    {
        
        
        if (day == 28)
        {
            month += 1;
            day = 1;
        }
        
        else
        {
            day += 1;
        }
        
        
    }
    
    else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10  )
        
    {
        
        
        if ( day == 31)
        {
            month += 1;
            day = 1;
        }
        
        else
        {
            day +=1;
        }
        
        
        
    }
    
    else if ( month == 4 || month == 6 || month == 9 || month == 11)
    {
        
        if ( day == 30)
        {
            month += 1;
            day  = 1;
        }
        
        else
        {
            day +=1;
        }
        
    }
    
    
    else if ( month == 12)
    {
        
        if (day == 31)
        {
            month = 1;
            day = 1;
            year += 1;
        }
        
        
    }
    
    return temp;
    
}


Date Date::operator -- ( )
{
    
    if(month == 3)
    {
        
        
        if (day == 1)
        {
            month -= 1;
            day = 28;
        }
        
        else
        {
            day -= 1;
        }
        
        
    }
    
    else if (  month == 4 || month == 6 || month == 8 || month == 9 || month == 11 )
        
    {
        
        
        if ( day == 1)
        {
            month -= 1;
            day = 31;
        }
        
        else
        {
            day -=1;
        }
        
        
        
    }
    
    else if ( month == 7 || month == 10 || month == 5 || month == 12)
    {
        
        if ( day == 1)
        {
            month -= 1;
            day  = 30;
        }
        
        else
        {
            day -=1;
        }
        
    }
    
    
    else if ( month == 1)
    {
        
        if (day == 1)
        {
            month = 12;
            day = 31;
            year -= 1;
        }
        
        
    }
    
    
    
    return *this;
}

Date Date:: operator -- (int d)
{
    
    Date temp(day,month,year);
    
    
    if(month == 3)
    {
        
        
        if (day == 1)
        {
            month -= 1;
            day = 28;
        }
        
        else
        {
            day -= 1;
        }
        
        
    }
    
    else if (  month == 4 || month == 6 || month == 8 || month == 9 || month == 11 )
        
    {
        
        
        if ( day == 1)
        {
            month -= 1;
            day = 31;
        }
        
        else
        {
            day -=1;
        }
        
        
        
    }
    
    else if ( month == 7 || month == 10 || month == 5 || month == 12)
    {
        
        if ( day == 1)
        {
            month -= 1;
            day  = 30;
        }
        
        else
        {
            day -=1;
        }
        
    }
    
    
    else if ( month == 1)
    {
        
        if (day == 1)
        {
            month = 12;
            day = 31;
            year -= 1;
        }
        
        
    }
    
    return temp;
    
}

ostream & operator <<(ostream &strm, const Date &obj)
{
    //switch with case 1 stm january case 2 strm feb
    switch (obj.month)
    {
        case 1:
            strm<<"January ";
            break;
        case 2:
            strm<<"February ";
            break;
        case 3:
            strm<<"March ";
            break;
        case 4:
            strm<<"April ";
            break;
        case 5:
            strm<<"May ";
            break;
        case 6:
            strm<<"June ";
            break;
        case 7:
            strm<<"July ";
            break;
        case 8:
            strm<<"August ";
            break;
        case 9:
            strm<<"September ";
            break;
        case 10:
            strm<<"October ";
            break;
        case 11:
            strm<<"November ";
            break;
        case 12:
            strm<<"December ";
            break;
            
        default:
            break;
    }
    
    strm<<obj.day<<", "<<obj.year<<endl;
    
    return strm;
    
}


istream & operator >> (istream &strm , Date &obj)
{
    
    cout<<"Day: ";
    strm>>obj.day;
    
    
    cout<<"Month: ";
    strm>>obj.month;
    
    cout<<"Year: ";
    strm>>obj.year;
    
    return strm;
    
    
}

void Date::operator=(const Date &right)
{
    day = right.day;
    month = right.month;
    year = right.year;
    
}


