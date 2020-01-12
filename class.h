//class.h

#ifndef _CLASS_
#define _CLASS_

#include <string>
#include <fstream>
#include "struct.h"

class General
{
protected:
    int STDN = 0;
    Infomation IFM[10];
public:
    General();
    void displaymenu();
    void read_data();
    void write_data();
};

class Manager : public General
{
private:
    bool search(const std::string *id);
    void soft_data(const std::string *id);
    int bien_dem = 0;
public:
    void add_data();
    void delete_data();
    void up_date();
    void show();
};

#endif //_CLASS_