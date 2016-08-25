//
//  Output_Files.cpp
//  Monte_Econ
//
//  Created by Jon Webb on 11/16/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//

#include "Output_Files.h"
#include <stdio.h>
void files::check_open()
{
    pFile=fopen ("../Files.d/Checking.csv","w");
}
void files::savings_open()
{
    pFile1=fopen ("../Files.d/Savings.txt","w");
}
void files::total_open()
{
    pFile2=fopen ("../Files.d/Total.txt","w");
}

void files::Output_File(float CHECKING,float Sigma,int years,int months,int days)
{
    std::string month;
    if(months EQ 1) month = "Jan";
    else if(months EQ 2) month = "Feb";
    else if(months EQ 3) month = "Mar";
    else if(months EQ 4) month = "Apr";
    else if(months EQ 5) month = "May";
    else if(months EQ 6) month = "Jun";
    else if(months EQ 7) month = "Jul";
    else if(months EQ 8) month = "Aug";
    else if(months EQ 9) month = "Sep";
    else if(months EQ 10) month = "Oct";
    else if(months EQ 11) month = "Nov";
    else month = "Dec";
    
    fprintf (pFile,"%s%s%d%s%d%s%8.2f%s%8.2f%s%8.2f\n",month.c_str(),
            " ",days," ",years,", ",CHECKING,",",CHECKING+3*Sigma,",",
            CHECKING-3*Sigma);
}

