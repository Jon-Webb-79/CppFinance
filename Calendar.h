//
//  Calendar.h
//  Monte_Economix
//
//  Created by Jon Webb on 12/22/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//

#ifndef __Monte_Economix__Calendar__
#define __Monte_Economix__Calendar__

#include <stdio.h>

int Initialize_Months_in_Year(int year,int END_YR,int END_MONTH);
int Initialize_Month_of_Year(int year,int BEG_YR,int BEG_MONTH);
int Initialize_Start_Day(int months,int BEG_YR,int BEG_MONTH,
                         int year,int BEG_DAY);
int Initialize_Days_in_Month(int months);

#endif /* defined(__Monte_Economix__Calendar__) */
