#ifndef GENERAL_H
#define GENERAL_H

#include "../struct/struct.h"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class General
{
protected:
    std::vector<Infomation> IFM;
public:
    void displaymenu();
    void read_data();
    void write_data();
};

#endif