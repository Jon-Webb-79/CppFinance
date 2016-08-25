//
//  Output_Files.h
//  Monte_Econ
//
//  Created by Jon Webb on 11/16/14.
//  Copyright (c) 2014 Jon Webb. All rights reserved.
//

#ifndef __Monte_Econ__Output_Files__
#define __Monte_Econ__Output_Files__

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

#define EQ ==

class files {
    FILE *pFile, *pFile1, *pFile2;
public:
    void check_open();
    void savings_open();
    void total_open();
    void Output_File(float CHECKING,float Sigma,int years,int months,int days);
};

#endif /* defined(__Monte_Econ__Output_Files__) */
