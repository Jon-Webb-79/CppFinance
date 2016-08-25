//
//  Program: Line_Parser.h
//  Created by Jon Webb on 12/19/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
/*
    Purpose: This code allows a user to either read on line of a data file at a
             time or read in an entire data file at once.  The program reads in
             each line as a character string and transforms each word in the string
             into a token.  The user can specify which token is to be transformed
             into an integer, float or double precision float.  The user can also
             use these functions to skip lines in an input file
*/
#ifndef Monte_Economix_Line_Parser_h
#define Monte_Economix_Line_Parser_h

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
//======================================================================
// - This function reads in one line of an input file and tokenizes
//   the words in the line.  Within the main program the user must input
//   the name of the opened file "inp", the position (position) in the
//   line of the value to be transformed into an "integer", "float" or
//   "double" and what data-type the variable is to be transformed into
//   "data_type".
template <class Type> void Line_Parser(std::ifstream& inp,int position,
                                       std::string& data_type,Type &output)
{
    std::string line;
    std::string buf;
    std::getline(inp,line);
    std::stringstream tokens(line);
    
    std::vector<std::string> tokenizer;
    std::string data1("integer");
    std::string data2("float");
    std::string data3("double");
    
    while(tokens >> buf) tokenizer.push_back(buf);
    
    if(data_type == data1) output = stoi(tokenizer[position-1]);
    else if(data_type == data2) output = stof(tokenizer[position-1]);
    else output = stod(tokenizer[position-1]);

}
//======================================================================
// - This templated function reads in a single line from an input file
//   as a character string and allows the user to select two words from
//   the string to transform into either a float, double precision float
//   or an integer
template <class Type1,class Type2>
void Two_Line_Parser(std::ifstream& inp,int position1,
                     int position2,std::string& data_type1,
                     std::string& data_type2,
                     Type1 &output1,Type2 &output2)
{
    std::string line;
    std::string buf;
    std::getline(inp,line);
    std::stringstream tokens(line);
    
    std::vector<std::string> tokenizer;
    std::string data1("integer");
    std::string data2("float");
    std::string data3("double");
    
    
    while(tokens >> buf) tokenizer.push_back(buf);
    
    if(data_type1 == data1) output1 = stoi(tokenizer[position1-1]);
    else if(data_type1 == data2) output1 = stof(tokenizer[position1-1]);
    else output1 = stod(tokenizer[position1-1]);
    
    if(data_type2 == data1) output2 = stoi(tokenizer[position2-1]);
    else if(data_type2 == data2) output2 = stof(tokenizer[position2-1]);
    else output2 = stod(tokenizer[position2-1]);
    
}
//======================================================================
// - This function reads in a single line from an input file and
//   transforms each word into a character string.  The user can choose
//   a word that they want passed back to the main program as a
//   character string
void String_Line_Parser(std::ifstream& inp,int position,
                        std::string& output)
{
    std::string line;
    std::string buf;
    std::getline(inp,line);
    std::stringstream tokens(line);
    
    std::vector<std::string> tokenizer;
    std::string data1("integer");
    std::string data2("float");
    std::string data3("double");
    
    while(tokens >> buf) tokenizer.push_back(buf);
    output = tokenizer[position - 1];
}
//======================================================================
// - This function allows a user to skip a line on an input file.
//   This function provdes no feedback and only requires that the
//   user pass the file name "inp" in the function call
void Skip_Lines(std::ifstream& inp)
{
    std::string line;
    std::getline(inp,line);
}
//======================================================================
// - This function opens an input file and reads all of the lines.
//   Each line is read as a character string and then a user specified
//   word is transformed either into an integer, a float or a double
//   precision float based on the users specifications in the funciton
//   call.
template <class Type> void File_Parser(const std::string& file_name,
                                       int position,std::vector<Type>& output,
                                       std::string& data_type)
{
    Type array;
    std::ifstream inp(file_name,std::ios::in | std::ios::binary);
    std::string line;
    std::string buf;

    if(inp.is_open()){
        while(!inp.eof()){
            std::getline(inp,line);
            std::stringstream tokens(line);
            
            std::vector<std::string> tokenizer;
            
            while(tokens >> buf) tokenizer.push_back(buf);
            if(data_type == "float")array = stof(tokenizer[position-1]);
            if(data_type == "integer")array = stoi(tokenizer[position-1]);
            else
                array = stod(tokenizer[position-1]);
            output.push_back(array);
        }
    }
    else std::cout << "Cannot Open " << file_name << std::endl;
}
//======================================================================
//******************************************************************
//******************************************************************
//****************                              ********************
//****************     VARIABLE DEFINITIONS     ********************
//****************                              ********************
//******************************************************************
//******************************************************************
// line      = A character string that reads in an entire line    **
//             from the input file                                **
// output    = The converted data string                          **
// position  = An integer that represents the position within a   **
//             data stream that is to be transfomred into a float,**
//             integer or a double                                **
// tokens    = Charater strings for each token in a data stream   **
// tokenizer = The specific data point that is to be transformed  **
//******************************************************************
//******************************************************************
#endif
