//
//  Algorithm.h
//  Monte_Economix
//
//  Created by Jon Webb on 12/22/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//

#ifndef __Monte_Economix__Algorithm__
#define __Monte_Economix__Algorithm__

#include <stdio.h>
#include <vector>
#include <iostream>

float Update_Checking_Account(int days,float CHECKING,float RENT,
                              float PAY,float LOANS,float CAR,
                              float INTERNET,float PHONE,float AINS,
                              float UTILITY,int length,int Rent_Pay_Date,
                              int Loan_Pay_Date,int Car_Pay_Date,
                              int Internet_Pay_Date,int Phone_Pay_Date,
                              int Ains_Pay_Date,int Utility_Pay_Date,
                              float Transfer_to_Savings,int Transfer_Date,
                              std::string& dispersement,int week_counter);
float Update_Savings_Account(int days,float SAVINGS,
                             float Transfer_to_Savings,int Transfer_Date);
float Expected_Purchases(float CHECKING,int counter,int year,
                         std::vector<int>& YR,int days,std::vector<int>& DY,
                         int month,std::vector<int>& MT,std::vector<float>& EX);
float Pre_Interpolator(double Interpolate_Point,std::vector<float>& Y_Value,
                       std::vector<float>& X_Value,int number);
float Interpolate(double Interpolate_Point,float X_Transfer1,
                  float X_Transfer2, float Y_Transfer1,
                  float Y_Transfer2);
float Paycheck(float SALLARY,float FED_TAX,float STATE_TAX,
               float SOCIAL_SECURITY,float MEDICARE,float DENTAL,
               float HEALTH,float W2GRP,std::string& dispersement);

#endif /* defined(__Monte_Economix__Algorithm__) */
