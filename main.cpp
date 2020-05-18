#include <iostream>
#include "function/Manager.h"

int main()
{
    int which;
    char i;
    Manager manager;
    do
    {
        manager.displaymenu();
        std::cout << "nhap lua chon: ";
        std::cin >> which;
        switch (which)
        {
        case 1:
            manager.add_data();
            break;
        case 2:
            manager.delete_data();
            break;
        case 3:
            manager.up_date();
            break;
        case 4:
            manager.show();
            break;

        default:
            std::cout << "nhap sai" << std::endl;
        }
        std::cout << "ban muon tiep tuc: (y/n)" << std::endl;
        std::cin >> i;
    } while (i == 'y' || i == 'Y');
    std::cout << "tam biet!" << std::endl;
    return 0;
}
