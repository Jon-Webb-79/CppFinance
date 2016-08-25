//
//  Algorithm.cpp
//  Created by Jon Webb on 12/22/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//
/*  Purpose:  This code provides routines that are required to run the 
              Monte_Economix software package.
*/

#include "Algorithm.h"
//===========================================================================
// - This function updates the Checking account with planned, monthly
//   spending items.
float Update_Checking_Account(int days,float CHECKING,float RENT,
                              float PAY,float LOANS,float CAR,
                              float INTERNET,float PHONE,float AINS,
                              float UTILITY,int length,int Rent_Pay_Date,
                              int Loan_Pay_Date,int Car_Pay_Date,
                              int Internet_Pay_Date,int Phone_Pay_Date,
                              int Ains_Pay_Date,int Utility_Pay_Date,
                              float Transfer_to_Savings,int Transfer_Date,
                              std::string& dispersement,int week_counter)
{
    float New_Account_Value = CHECKING + 0.0;
    std::string comparison0("Monthly");
    std::string comparison("Bimonthly");
    std::string comparison2("Two_Week");
    
    if(days == Rent_Pay_Date)     New_Account_Value = New_Account_Value - RENT;
    if(days == Loan_Pay_Date)     New_Account_Value = New_Account_Value - LOANS;
    if(days == Car_Pay_Date)      New_Account_Value = New_Account_Value - CAR;
    if(days == Internet_Pay_Date) New_Account_Value = New_Account_Value - INTERNET;
    if(days == Phone_Pay_Date)    New_Account_Value = New_Account_Value - PHONE;
    if(days == Ains_Pay_Date)     New_Account_Value = New_Account_Value - AINS;
    if(days == Utility_Pay_Date)  New_Account_Value = New_Account_Value - UTILITY;
    if(days == Transfer_Date)     New_Account_Value = New_Account_Value - Transfer_to_Savings;

    if(days == 15 && dispersement == comparison) New_Account_Value = New_Account_Value + PAY;
    
    if(dispersement == comparison)
    {
      if(length == 28 && days == 28) New_Account_Value = New_Account_Value + PAY;
      if(length == 29 && days == 29) New_Account_Value = New_Account_Value + PAY;
      if(length > 28 && days == 30)  New_Account_Value = New_Account_Value + PAY;
    }
    if(dispersement == comparison0)
    {
        if(length == 28 && days == 28) New_Account_Value = New_Account_Value + PAY;
        if(length == 29 && days == 29) New_Account_Value = New_Account_Value + PAY;
        if(length > 28 && days == 30)  New_Account_Value = New_Account_Value + PAY;
    }
    
    if(dispersement == comparison2 && week_counter == 14) New_Account_Value = New_Account_Value + PAY;
    
    return(New_Account_Value);
}
//===========================================================================
// - This function updates the Savings account with planned, monthly
//   spending items
float Update_Savings_Account(int days,float SAVINGS,float Transfer_to_Savings,
                             int Transfer_Date)
{
    int New_Savings_Account_Value = SAVINGS + 0.0;
    if(days == Transfer_Date)
        New_Savings_Account_Value = New_Savings_Account_Value + Transfer_to_Savings;
    return(New_Savings_Account_Value);
}
//===========================================================================
// - This function updates the checking account based on planned, large
//   spending items
float Expected_Purchases(float CHECKING,int counter,int year,
                         std::vector<int>& YR,int days,std::vector<int>& DY,
                         int month,std::vector<int>& MT,std::vector<float>& EX)
{
    float New_Account_Value = CHECKING;
    for(int n = 0; n < counter + 1; n++)
        if(year == YR[n] && days == DY[n] &&
           month == MT[n]) New_Account_Value = New_Account_Value - EX[n];
    return(New_Account_Value);
}
//===========================================================================
float Pre_Interpolator(double Interpolate_Point,std::vector<float>& Y_Value,
                       std::vector<float>& X_Value,int number)
{
    float Result = 0.0;
    float X_Transfer1,X_Transfer2;
    float Y_Transfer1,Y_Transfer2;
    
    int i = 1;
    do{
        X_Transfer1 = X_Value[i-1];
        X_Transfer2 = X_Value[i];
        Y_Transfer1 = Y_Value[i-1];
        Y_Transfer2 = Y_Value[i];
        
        if(Interpolate_Point < Y_Value[i])
        {
            Result = Interpolate(Interpolate_Point,X_Transfer1,
                                 X_Transfer2,Y_Transfer1,
                                 Y_Transfer2);
            break;
        }
        i++;
    }while(i < number + 1);
    return(Result);
}
//===========================================================================
float Interpolate(double Interpolate_Point,float X_Transfer1,
                  float X_Transfer2, float Y_Transfer1,
                  float Y_Transfer2)
{
    float Interpolated_Value,slope;
    
    slope = ((X_Transfer2 - X_Transfer1))/((Y_Transfer2-Y_Transfer1));
    Interpolated_Value = ((Interpolate_Point - Y_Transfer1)*slope) + X_Transfer1;
 //   if(Interpolated_Value < 0) Interpolated_Value = 0.0;
    
    return(Interpolated_Value);
}
//==========================================================================
float Paycheck(float SALLARY,float FED_TAX,float STATE_TAX,
               float SOCIAL_SECURITY,float MEDICARE,float DENTAL,
               float HEALTH,float W2GRP,std::string& dispersement)
{
    float PAYCHECK = 0.0;
    float SALLARY1 = SALLARY/12;
    std::string comparison("Bimonthly");
    std::string comparison2("Two_Week");
    PAYCHECK = SALLARY1 - SALLARY1*FED_TAX-SALLARY1*STATE_TAX-
    SALLARY1*SOCIAL_SECURITY-SALLARY1*MEDICARE-
    DENTAL-HEALTH-W2GRP;
    
    if(dispersement == comparison) PAYCHECK = PAYCHECK/2;
    if(dispersement == comparison2) PAYCHECK = PAYCHECK*12/26;
    
    return(PAYCHECK);
}
//==========================================================================