//
//  Program: Calendar.cpp
//  Created by Jon Webb on 12/22/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//
/*  Purpose: This program determines which day of the month is the correct
             date to start at, what is the correct end date for each month
             and how many days there are in a month
*/

#include "Calendar.h"
#define EQ ==
//===========================================================================
// - This function determines how many months the program will iterate over
//   for the current year
int Initialize_Months_in_Year(int year,int END_YR,int END_MONTH)
{
    int last_month;
    if(year == END_YR) last_month = END_MONTH;
    else last_month = 12;
    return (last_month);
}
#define EQ ==
//===========================================================================
// - This function determines what month will be the first month to be iterated
//   over for a given year
int Initialize_Month_of_Year(int year,int BEG_YR,int BEG_MONTH)
{
    int first_month;
    if(year == BEG_YR) first_month = BEG_MONTH;
    else first_month = 1;
    return (first_month);
}
#define EQ ==
//===========================================================================
// - This function determines what day of the month will be the first day
//   to be iterated over
int Initialize_Start_Day(int months,int BEG_YR,int BEG_MONTH,
                         int year,int BEG_DAY)
{
    int start_day;
    if(months > 12) months = 1;
    if(year == BEG_YR && months == BEG_MONTH) start_day = BEG_DAY;
    else start_day = 1;
    return (start_day);
}
#define EQ ==
//===========================================================================
// - This function determines how many days exist in a month
int Initialize_Days_in_Month(int months)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days_in_month = days[months-1];
    return(days_in_month);
}
//===========================================================================
//******************************************************************
//*******************************************************************
//****************                              *********************
//****************     VARIABLE DEFINITIONS     *********************
//****************                              *********************
//*******************************************************************
//*******************************************************************
// days          = An integer variable represented as an array     **
//                 of values, each representing the number of days **
//                 in a given month                                **
// days_in_month = An integer variable that represents the number  **
//                 of days in the current month                    **
// BEG_DAY       = An integer variable that represents the first   **
//                 day of monte carlo iteration                    **
// BEG_MONTH     = An integer variable that represents the first   **
//                 month of iteration in a given year              **
// BEG_YR        = An integer variable that represents the first   **
//                 year of iteration                               **
// END_MONTH     = An integer variable that represents the last    **
//                 month for iteration                             **
// END_YR        = An integer variable that represents the last    **
//                 year for iteration                              **
// first_month   = An integer variable that represents the first   **
//                 day of iteration                                **
// last_month    = An integer value that represents the last month **
//                 that will be tallied for the current iteration  **
// months        = An integer variable that represents the current **
//                 month of iteration                              **
// start_day     = An integer variable that represents the first   **
//                 day of monte carlo iteration                    **
// year          = An integer value that represents the current    **
//                 year of iteration                               **
//*******************************************************************
//*******************************************************************