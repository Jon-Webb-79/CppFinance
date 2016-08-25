//
//  main.cpp
//  Econ_Test
//
//  Created by Jon Webb on 2/4/15.
//  Copyright (c) 2015 Jon Webb. All rights reserved.
//
#include "Data_Parser.h"
#include "PDF_and_CDF.h"
#include "Random_NUmber_Generator.h"
#include "Algorithm.h"
#include "Statistics.h"
#include "Calendar.h"
#include "Output_Files.h"

#include <iostream>
#include <vector>

#define EQ ==
#define AND &&
#define OR ||

int main(int argc, const char * argv[]) {
  
        float start_time,end_time;
    start_time = clock();

/*
***********************************************************************************
***********************************************************************************
***************************                              **************************
***************************    INPUT FILE READER BLOCK   **************************
***************************                              **************************
***********************************************************************************
***********************************************************************************
*/
/* - This section reads in all of the general financial data from the primary
     input file.  The template function Line_Parser is used and stored in the file
     "Data_Parser.h"
*/
    
    int sample_size,BEG_DAY,BEG_MONTH,BEG_YR,END_DAY,END_MONTH,END_YR;
    int Rent_Pay_Date,Car_Pay_Date,Phone_Pay_Date,Loan_Pay_Date;
    int Ains_Pay_Date,Internet_Pay_Date,Utility_Pay_Date,Transfer_Date;
    int PAY_MONTH, PAY_DAY, PAY_YR;
    
    float CHECKING,SAVINGS,FONEK,SALLARY,Krate,FED_TAX,STATE_TAX;
    float SOCIAL_SECURITY,MEDICARE,DENTAL,HEALTH,W2GRP,RENT,CAR;
    float PHONE,LOANS,AINS,INTERNET,UTILITY,Transfer_to_Savings;
    
    // Input file name
    std::string Input_File("../Files.d/Input.txt");
    
    /* - Opening in binary mode prevents carriage return issues, which
     are frequently encountered in cross platform (windows, dos, UNIX)
     code use.  The file opened is titled "Input.txt"
     */
    std::ifstream inp(Input_File, std::ios::in | std::ios::binary);
    if(!inp){
        std::cout << "Cannot Open " << Input_File << std::endl;
        return 1;
    }
    
    /* - This section reads in all financial data that is static from month
     to month.  The names are self explanitory.  The Line_Parse function
     is stored in Line_Parser.h
     */
    std::string integer("integer");
    std::string real("float");
    std::string character("character");
    std::string dispersement;
    
    Line_Parser(inp, 1, integer, sample_size);
    Line_Parser(inp, 1, integer, BEG_DAY);
    Line_Parser(inp, 1, integer, BEG_MONTH);
    Line_Parser(inp, 1, integer, BEG_YR);
    Line_Parser(inp, 1, integer, END_DAY);
    Line_Parser(inp, 1, integer, END_MONTH);
    Line_Parser(inp, 1, integer, END_YR);
    Line_Parser(inp, 1, integer, PAY_MONTH);
    Line_Parser(inp, 1, integer, PAY_DAY);
    Line_Parser(inp, 1, integer, PAY_YR);
    Line_Parser(inp, 1, real, CHECKING);
    Line_Parser(inp, 1, real, SAVINGS);
    Line_Parser(inp, 1, real, FONEK);
    Line_Parser(inp, 1, real, SALLARY);
    String_Line_Parser(inp, 1, dispersement);
    Line_Parser(inp, 1, real, Krate);
    Line_Parser(inp, 1, real, FED_TAX);
    Line_Parser(inp, 1, real, STATE_TAX);
    Line_Parser(inp, 1, real, SOCIAL_SECURITY);
    Line_Parser(inp, 1, real, MEDICARE);
    Line_Parser(inp, 1, real, DENTAL);
    Line_Parser(inp, 1, real, HEALTH);
    Line_Parser(inp, 1, real, W2GRP);
    Skip_Lines(inp);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    RENT,Rent_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    CAR,Car_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    PHONE,Phone_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    LOANS,Loan_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    AINS,Ains_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    INTERNET,Internet_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    UTILITY,Utility_Pay_Date);
    Two_Line_Parser(inp, 1, 2,real,integer,
                    Transfer_to_Savings,Transfer_Date);

    Skip_Lines(inp);
    Skip_Lines(inp);
    
    /* - This section reads in large planned purchases (EX) as an
     vector array along with the month (MT), day (DY) and
     the year (YR) of the purchase, also as vector arrays
     */
    int   Column1,Column2,Column3;
    float Column4;
    std::string Column5;
    
    std::vector<int> MT;
    std::vector<int> DY;
    std::vector<int> YR;
    std::vector<float> EX;
    int counter = 0;  // - Number of large purchases developed in
    //   a running counter
    while (!inp.eof())
    {
        inp >> Column1 >> Column2 >> Column3 >> Column4;
        getline(inp,Column5);
        MT.push_back(Column1), DY.push_back(Column2),
        YR.push_back(Column3), EX.push_back(Column4);
        
        if(inp.fail()) break; // if no data is left, break
        counter++;
    }
    inp.close();
    counter = counter - 1;    // counter incriments by one before exiting
/*
***********************************************************************************
***********************************************************************************
***************************                              **************************
***************************      EXPENSE READER BLOCK    **************************
***************************                              **************************
***********************************************************************************
***********************************************************************************
*/
/*
 - This section reads in data from all of the variable expense sheets.  This section
   uses the File_Parser function stored in "Data_Parser.h"
*/
    // - Reads in miscellaneous spending data from an input
    std::vector<float> MISC_DATA;
    std::string File1("../Files.d/Misc.txt");
    File_Parser(File1,1,MISC_DATA,real);
    
    // - Reads in grocery spending data from an input file
    std::vector<float> GROC_DATA;
    std::string File2("../Files.d/Groceries.txt");
    File_Parser(File2,1,GROC_DATA,real);
    
    // - Reads in restaraunt spending data from an input file
    std::vector<float> REST_DATA;
    std::string File3("../Files.d/Rest.txt");
    File_Parser(File3,1,REST_DATA,real);
    
    // - Reads in restaraunt spending data from an input file
    std::vector<float> BAR_DATA;
    std::string File4("../Files.d/Bar.txt");
    File_Parser(File4,1,BAR_DATA,real);
    
    // - Reads in gas spending data from an input file
    std::vector<float> GAS_DATA;
    std::string File5("../Files.d/Gas.txt");
    File_Parser(File5,1,GAS_DATA,real);
/*
***********************************************************************************
***********************************************************************************
***************************                              **************************
***************************          PDF AND CDF         **************************
***************************        CREATION BLOCK        **************************
***************************                              **************************
***********************************************************************************
***********************************************************************************
*/
/*
 - This section transforms the std::vector blocks into probability density functions
   and then transforms them into cumulative density functions for Monte Carlo sampling.
   This section uses template functions from PDF_and_CDF.h
*/
    int Num_Hist_Bins = 60;
    
    // Creating object for CDF creation
    PDF_and_CDF<float> Misc(MISC_DATA);
    PDF_and_CDF<float> Groc(GROC_DATA);
    PDF_and_CDF<float> Rest(REST_DATA);
    PDF_and_CDF<float> Bar(BAR_DATA);
    PDF_and_CDF<float> Gas(GAS_DATA);
 
    // - This block creates a CDF and Bin_Center array for each variable
    //   spending item
    Misc.Create_CDF( Num_Hist_Bins );
    Misc.Create_Bin_Center( Num_Hist_Bins );
    
    Groc.Create_CDF( Num_Hist_Bins );
    Groc.Create_Bin_Center( Num_Hist_Bins );
    
    Rest.Create_CDF( Num_Hist_Bins );
    Rest.Create_Bin_Center( Num_Hist_Bins );
    
    Bar.Create_CDF( Num_Hist_Bins );
    Bar.Create_Bin_Center( Num_Hist_Bins );
    
    Gas.Create_CDF( Num_Hist_Bins );
    Gas.Create_Bin_Center( Num_Hist_Bins );
    
/*
***********************************************************************************
***********************************************************************************
***************************                              **************************
***************************          INITIALIZE          **************************
***************************            PROGRAM           **************************
***************************                              **************************
***********************************************************************************
***********************************************************************************
*/
    std::vector<float> Account_Tally;
    float PAY=0.0;

    files Output;   // links to routine to create output file
    
    // The next two lines are initialization parameters for RN_init_problem()
    // which is stored in Random_Number_Generator.cpp and .h
    int gen = 2,prnt = 1;
    unsigned long long seed = 1234567, zero = 0;
    RN_init_problem (&gen, &seed, &zero, &zero, &prnt );
    
    // Creates output file
    Output.check_open();
    
    // - Paycheck() is stored in Initialize.h and determines the
    //   bi-monthly paycheck amount
    PAY = Paycheck(SALLARY,FED_TAX,STATE_TAX,SOCIAL_SECURITY,
                   MEDICARE,DENTAL,HEALTH,W2GRP,dispersement);
/*
***********************************************************************************
***********************************************************************************
***************************                              **************************
***************************         MONTE CARLO          **************************
***************************           PROGRAM            **************************
***************************                              **************************
***********************************************************************************
***********************************************************************************
*/
     int year = BEG_YR; int length = 0;
     int week_counter = 0;
     std::string count("NO");
//    float Checking_Transfer;
    do{
        // - Initialize_Months_in_Year() is stored in Calendar.cpp and is used to
        //   determine the last month in a year, before the next year is began.
        //   If the programmer chooses to end the iterations in May then the
        //   last month will be 5.
        int Months_in_Year = Initialize_Months_in_Year(year,END_YR,END_MONTH);
        
        // - Initialize_Month_of_Year() is stored in Calendar.cpp and is used to
        //   determine the first month for each year.  If the programmer chooses
        //   to start iteration in March then the first month will be 3.
        int Start_Month = Initialize_Month_of_Year(year,BEG_YR,BEG_MONTH);
        int months = Start_Month;
    
        do{
            // Initialize_Start_Day() is stored in Calendar.cpp and is used to
            // determine the first day in each month.  If the programmer
            // chooses to start iteration on the 3rd of a month, then the
            // first month will be 3.
            int first_day_in_month =
              Initialize_Start_Day(months,BEG_YR,BEG_MONTH,
                                   year,BEG_DAY);
              int days = first_day_in_month;
            // Initializes the number of days in a mont with
            // Initialize_Days_in_Month() which is stored in Calendar.cpp
            if(months EQ END_MONTH AND year EQ END_YR) length = END_DAY;
            else length = Initialize_Days_in_Month(months);

            do{
                
                if(dispersement == "Two_Week" && days == PAY_DAY && months == PAY_MONTH &&
                   year == PAY_YR){
                    count = "YES";
                    week_counter = 14;
                }
                
                if(count == "YES" && week_counter < 14) week_counter = week_counter + 1;
                
                // - Updates the value of the checking account based on planned
                //   monthly spending items.  Stored in Algorithm.cpp
                CHECKING = Update_Checking_Account(days,CHECKING,
                                                   RENT,PAY,LOANS,CAR,INTERNET,
                                                   PHONE,AINS,UTILITY,length,
                                                   Rent_Pay_Date,Loan_Pay_Date,
                                                   Car_Pay_Date,Internet_Pay_Date,
                                                   Phone_Pay_Date,Ains_Pay_Date,
                                                   Utility_Pay_Date,Transfer_to_Savings,
                                                   Transfer_Date,dispersement,week_counter);
                
                if(count == "YES" and week_counter == 14) week_counter = 0;
                
                // - Updates the value of the savings account based on planned
                //   monthly spending items.  Stored in Algorithm.cpp
                SAVINGS = Update_Savings_Account(first_day_in_month,SAVINGS,
                                                 Transfer_to_Savings,Transfer_Date);

               // - Updates the value of the checking account based on planned
               //   large spending items.  Stroed in Algorithm.cpp
                CHECKING = Expected_Purchases(CHECKING,counter,year,YR,
                                              days,DY,months,MT,EX);

                // Running value of checking account used in Monte Carlo iteration
                float Checking_Transfer = CHECKING;

                // Running number of Monte Carlo iterations
                int cycle = 0;
                do{
                    // - Pre_Interpolator sends CDF and a random point data to the
                    //   function that determines a random value of spending.  The
                    //   function is stored in Algorithm.cpp
                    float MISC_EXPENSE =
                     Pre_Interpolator(rang(),Misc.CDF,Misc.Bin_Center,Num_Hist_Bins);
                    float GROC_EXPENSE =
                     Pre_Interpolator(rang(),Groc.CDF,Groc.Bin_Center,Num_Hist_Bins);
                    float REST_EXPENSE =
                     Pre_Interpolator(rang(),Groc.CDF,Groc.Bin_Center,Num_Hist_Bins);
                    float BAR_EXPENSE =
                     Pre_Interpolator(rang(),Bar.CDF,Bar.Bin_Center,Num_Hist_Bins);
                    float GAS_EXPENSE =
                     Pre_Interpolator(rang(),Gas.CDF,Gas.Bin_Center,Num_Hist_Bins);

                    // Subtracts random spending from copy of checking account
                    float total = MISC_EXPENSE + GROC_EXPENSE + REST_EXPENSE + BAR_EXPENSE + GAS_EXPENSE;
                  //  float total  = GAS_EXPENSE;
                    Account_Tally.push_back(Checking_Transfer - total);
                  //  Account_Tally.push_back(total);

                    cycle++;
                }while(cycle LT sample_size );


                Statistics<float> Account(Account_Tally); // Declares Statistics Object
                
                // The next two object calls reference template functions stored in Statistics.h
                //   and are used to determine the average and standard deviaiton of Account_Tally
                Account.Average();
                Account.Standard_Deviation();
               //  std::cout << Account.Mean << std::endl;
                
                // Transferes value of checking account
                CHECKING = Account.Mean;

                Account_Tally.clear();  // Resets the account tally values

                Output.Output_File(CHECKING,Account.Sigma,year,months,days);
                days++;
            }while(days LT length + 1);
            months++;
        }while(months LT Months_in_Year + 1);
        year++;
    }while(year LT END_YR + 1);
    
    
    end_time = clock();
    std::cout << std::endl << "Total Time: " << (end_time-start_time)/CLOCKS_PER_SEC << std::endl;
    
    return 0;
}
