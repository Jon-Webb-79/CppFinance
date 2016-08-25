//  Program:  PDF_and_CDF.h
//  Author:   Jonathan A. Webb
//  Date:     January 05, 2014
//  Purpose:  This file contains a class that is used to create Probability
//            Distribution Functions (PDFs) and Cummulative Density Distribution
//            Functions
//==================================================================================
// Pre-compiler section
#include <vector>

#ifndef Test2_PDF_and_CDF_h
#define Test2_PDF_and_CDF_h

#define LT <
#define EQ ==
//==================================================================================
// Decleration of prototypes for class
template <class Data_Type1> class PDF_and_CDF
{
public:
    // - Variables referenceble by dot notation in the
    //   calling program.
    std::vector<Data_Type1> Upper_Limits;
    std::vector<Data_Type1> PDF;
    std::vector<Data_Type1> CDF;
    std::vector<Data_Type1> Bin_Center;
    
    // prototype definitions
    void Histogram_Width( int Number_of_Bins );
    void Histogram_Upper_Limits(int Number_of_Bins);
    void Create_PDF(int Number_of_Bins);
    void Create_CDF( int Number_of_Bins );
    void Create_Bin_Center( int Number_of_Bins );
    
    // This is the constructor
    PDF_and_CDF(std::vector<Data_Type1> &a) {
        Data_Set = a;
    };
    
private:
    std::vector<Data_Type1> Data_Set;
    Data_Type1 Width;
};
//==================================================================================
// - This templated function is used to determine the width of a histogram bin.
//   It imports the data set to be histogramed, determines the largest element in
//   the data set, then divides that by the number of bins to be created to determine
//   the width.  The result "Width" is only visible in the class and cannot be
//   called by the main program.
template <class Data_Type1>
void PDF_and_CDF<Data_Type1>::Histogram_Width( int Number_of_Bins )
{
    auto max_Element_Position = std::max_element(Data_Set.begin(),Data_Set.end());
    
    Data_Type1 Largest_Element = *max_Element_Position;
    
    Width = Largest_Element/Number_of_Bins;
}
//==================================================================================
// - This templated function is used to determine the upper limits of each histogram
//   bin.  The function imports the width of each bin and the number of bins and
//   in a cummulative fashin creates each succesive bin upper limit by addinng the
//   width to the previous upper limit.  The variable is "Upper_Limits" is not
//   expresly passed back to the calling program and is instead passed by the
//   dot notation.
template <class Data_Type1>
void PDF_and_CDF<Data_Type1>::Histogram_Upper_Limits(int Number_of_Bins)
{
    Data_Type1 Upper_Bins = 0.0;
    Upper_Limits.push_back(0);
    
    for(int n = 1; n LT Number_of_Bins + 1; n++)
    {
        if(n EQ Number_of_Bins-1){
            Upper_Bins = Upper_Bins + Width + 1;
            Upper_Limits.push_back(Upper_Bins);
        }
        else {
            Upper_Bins = Upper_Bins + Width;
            Upper_Limits.push_back(Upper_Bins);
        }
    }
}
//==================================================================================
// - This templated function is used to create a Probability Density Function (PDF)
//   from a group of data titled "Data_Set".  The final PDF is normalized to the sum
//   of all the values in "Data_Set".  The function can be called directly without
//   needing to call Histogram_Width() and Histogram_Upper_Limits() first.  However,
//   the final PDF is not directly passed back to the calling program and instead
//   must be referenced using the dot notation.
template <class Data_Type1>
void PDF_and_CDF<Data_Type1>::Create_PDF(int Number_of_Bins)
{
    
    Histogram_Width( Number_of_Bins );
    Histogram_Upper_Limits( Number_of_Bins );
    
    int Array_Sum = 0.0;
    int size = Data_Set.size();
    
    for(int n = 1; n < Number_of_Bins + 1; n++)
    {
        PDF.push_back(0);
    }
    int i = 0;
    while(i < size){
        int j = 1;
        while(j < Number_of_Bins + 1){
            if(Data_Set[i] < Upper_Limits[j] && Data_Set[i] >=
               Upper_Limits[j-1]){
                PDF[j] = PDF[j] + 1;
                break;
            }
            j++;
        }
        i++;
    }
    for (int n = 0; n < Number_of_Bins + 1; n++) Array_Sum = Array_Sum + PDF[n];
    for (int n = 0; n < Number_of_Bins + 1; n++) PDF[n] = PDF[n]/Array_Sum;
}
//==================================================================================
// - This templated function is used to create a Cummulative Density Function (CDF)
//   from an vector array of data titled "Data_Set".  The CDF is normalized to a peak
//   value of 1.0 and is not explicitely passed back to the calling program and instead
//   must be referenced using the dot notation.
template <class Data_Type1>
void PDF_and_CDF<Data_Type1>::Create_CDF( int Number_of_Bins )
{
    Create_PDF( Number_of_Bins );
    CDF.push_back(PDF[0]);
    for(int n = 1; n < Number_of_Bins + 1; n++)
        CDF.push_back(PDF[n] + CDF[n-1]);
}
//==================================================================================
// - This templated function is used to determine the center position of a histogram
//   bin used in producing a PDF or CDF.  The final value can only be referenced in
//   the calling program by a dot notation.
template <class Data_Type1>
void PDF_and_CDF<Data_Type1>::Create_Bin_Center( int Number_of_Bins )
{
    Histogram_Width( Number_of_Bins );
    Histogram_Upper_Limits( Number_of_Bins );
    
    Bin_Center.push_back(0);
    for(int n = 1; n < Number_of_Bins + 1; n++)
        Bin_Center.push_back(((Upper_Limits[n] - Upper_Limits[n-1])/2) +
                             Upper_Limits[n-1]);
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
//== Array_Sum          = The summation of all the values in the vector array    ===
//==                      "Data_Set"                                             ===
//== Bin_Center         = A series of values (real, integer or double) stored in ===
//==                      a vector array that represent the center of a PDF or   ===
//==                      CDF bin                                                ===
//== CDF                = A series of values (real, integer or double) stored in ===
//==                      a vector array that represent the values of a          ===
//==                      Cummulative Density Function                           ===
//== Number_of_Bins     = An integer variable that represents the number of PDF  ===
//==                      or CDF bins                                            ===
//== PDF                = A series of values (real, integer or double) stored in ===
//==                      a vector array that represent the values of a          ===
//==                      Probability Density Function                           ===
//== Upper_Bins         = A real, integer or double value that represents the    ===
//==                      running value for a bins upper limit which is passed   ===
//==                      to the vector array "Upper_Limit"                      ===
//== Upper_Limit        = A series of values (real, integer or double) stored in ===
//==                      a vector array that represent the upper limits of a    ===
//==                      CDF or PDF histogram bin.                              ===
//==================================================================================
//==================================================================================
