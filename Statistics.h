//  Program:  PDF_and_CDF.h
//  Author:   Jonathan A. Webb
//  Date:     January 05, 2014
//  Purpose:  This file contains a class that is used to determine the mean, summation
//            and standard deviation of data points in a vector array.
//==================================================================================
// Pre-compiler section
#include <vector>
#include <math.h>

#ifndef Test2_Statistics_h
#define Test2_Statistics_h

#define LT <
#define EQ ==
//==================================================================================
// Decleration of prototypes for class
template <class Data_Type1> class Statistics
{
public:
    // - Variables referenceble by dot notation in the
    //   calling program.
    Data_Type1 Sum;
    Data_Type1 Mean;
    Data_Type1 Sigma;
    
    // prototype definitions
    void Summation();
    void Average();
    void Standard_Deviation();
    
    // This is the constructor
    Statistics(std::vector<float> &a) {
        Data_Set = a;
    };
    
private:
    std::vector<Data_Type1> Data_Set;
};
//==================================================================================
// - This templated function is used to determine the sum of the data points in a
//   vector array titled "Data_Set".  The actual sum is not explicitely passed back
//   to the calling program and can only be accessed by dot notation.
template <class Data_Type1>
void Statistics<Data_Type1>::Summation()
{
    Sum = 0.0;
    int Sample_Size = Data_Set.size();
    for(int n = 0; n LT Sample_Size; n++)
        Sum = Sum + Data_Set[n];
}
//==================================================================================
// - This templated function is used to determine the mean value from a set or
//   data points in a vector array titled "Data_Set".  The variables can only
//   be referenced in the calling program by dot notation.
template <class Data_Type1>
void Statistics<Data_Type1>::Average()
{
    int Sample_Size = Data_Set.size();
    Summation();
    Mean = Sum/Sample_Size;
}
//==================================================================================
// - This templated function is used to determine the standard deviation of a set
//   of data points in a vector array titled "Data_Set".  The variables can only
//   be referenced in the calling program by dot notation.
template <class Data_Type1>
void Statistics<Data_Type1>::Standard_Deviation()
{
    int Sample_Size = Data_Set.size();
    Average();
    Sigma = 0.0;
    for(int i=0; i < Sample_Size ; i++) {
        Sigma = Sigma + pow((Data_Set[i] - Mean),2);
    }
    Sigma  = sqrt(Sigma/Sample_Size);
}
//==================================================================================
#endif
//==================================================================================
//==================================================================================
//==========================                                ========================
//==========================          NOMENCLATURE          ========================
//==========================                                ========================
//==================================================================================
//==================================================================================
//== Data_Set     = A vector array conataining integer, real or double precision ===
//==                data points                                                  ===
//== Mean         = A (real, integer or float) variable that represents the      ===
//==                average of the data points stored in a vector array titled   ===
//==                "Data_Set"                                                   ===
//== Sigma        = A (real, integer or float) variable that represents the      ===
//==                standard deviation of the data points stored in a vector     ===
//==                array titled "Data_Set"                                      ===
//== Sum          = A (real, integer or float) variable that represents the      ===
//==                summation of the data points in a vector array titled        ===
//==                "Data_Set"                                                   ===
//==================================================================================
//==================================================================================
