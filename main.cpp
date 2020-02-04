#include <iostream>
#include "class.h"
#include "function.h"

using namespace std;

int main()
{
    int which;
    char i;
    Manager manager;
    do
    {
        manager.displaymenu();
        cout << "nhap lua chon: ";
        cin >> which;
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
            cout << "nhap sai" << endl;
        }
        cout << "ban muon tiep tuc: (y/n)" << endl;
        cin >> i;
    } while (i == 'y' || i == 'Y');
    cout << "tam biet!" << endl;
    manager.write_data();
    return 0;
}
