#ifndef MANAGER_H
#define MANAGER_H

#include "General.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

class Manager : public General
{
private:
    bool search(const std::string &ID);
    int search_index(const std::string &ID);
    void soft_data(const std::string &ID);
public:
    Manager();
    ~Manager();
    void add_data();
    void delete_data();
    void up_date();
    void show();
};

#endif