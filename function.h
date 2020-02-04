#ifndef __FUNCTION__
#define __FUNCTION__

#include <iostream>
#include <iomanip>
#include <fstream>

#include "struct.h"
#include "class.h"

using namespace std;

General::General()
{
    read_data();
}

void General ::read_data()
{
    ifstream infile;
    infile.open("data.txt");
    infile >> this -> STDN;
    for (int i = 0; i < this -> STDN; i++)
    {
        infile >> this -> IFM[i].ID;
        getline(infile, this -> IFM[i].Name);
        infile >> this -> IFM[i].Age;
        infile >> this -> IFM[i].Sex;
        infile >> this -> IFM[i].status;
    }
    infile.close();
}

void General ::write_data()
{
    ofstream outfile;
    outfile.open("data.txt");
    outfile << this -> STDN << endl;
    for (int i = 0; i < this -> STDN; i++)
    {
        outfile << this -> IFM[i].ID << " ";
        outfile << this -> IFM[i].Name << "\n";
        outfile << this -> IFM[i].Age << " ";
        outfile << this -> IFM[i].Sex << " ";
        outfile << this -> IFM[i].status << " ";
        outfile << endl;
    }
    outfile.close();
}

void General::displaymenu()
{
    cout << "=====================MENU========================" << endl;
    cout << "1. Them sinh vien!" << endl;
    cout << "2. Xoa sinh vien!" << endl;
    cout << "3. Cap nhat ban ghi!" << endl;
    cout << "4. Xem toan bo sinh vien!" << endl;
    cout << "5. Tinh diem tb sinh vien chon" << endl;
    cout << "6. Sinh vien diem cao nhat" << endl;
    cout << "7. Vien vien diem thap nhat" << endl;
    cout << "8. Tim ban ghi sinh vien bang id" << endl;
    cout << "9. Sap xep ban gi theo diem" << endl;
    cout << endl;
}

bool Manager ::search(const string *id)
{
    bool found = false;
    for (int i = 0; i < this -> STDN && found == false; i++)
    {
        if (this -> IFM[i].ID == *id)
        {
            found = true;
            this -> bien_dem = i;
        }
        else
        {
            found = false;
        }
    }
    return found;
}

void Manager ::add_data()
{
again:
    cout << "=================================================" << endl;
    cout << "Nhap id sv:";
    cin >> this->IFM[STDN].ID;
    if (search(&this->IFM[STDN].ID) == true)
    {
        cout << "ID da ton tai!" << endl;
        goto again;
    }
    cout << "nhap ten: ";
    cin.ignore();
    getline(cin, this -> IFM[STDN].Name);
    cout << "\nnhap tuoi: ";
    cin >> this->IFM[STDN].Age;
    cout << "\nnhap gioi tinh: ";
    cin >> this->IFM[STDN].Sex;
    cout << "\n something";
    this->IFM[STDN].status = true;
    this->STDN++;
}

void Manager::soft_data(const string *id)
{
    search(id);
    for (int i = this -> bien_dem; i <= this -> STDN; i++)
    {
        this -> IFM[i] = this -> IFM[i + 1];
    }
}

void Manager::delete_data()
{
    string *id = new string;
    cout << "nhap id sinh vien can xoa: ";
    cin >> *id;
    cout << endl;
    search(id);
    this->IFM[bien_dem].ID = "";
    this->IFM[bien_dem].Name = "";
    this->IFM[bien_dem].Sex = "";
    this->IFM[bien_dem].diem = 0;
    this->IFM[bien_dem].status = false;
    soft_data(id);
    this->STDN--;
    delete id;
    id = nullptr;
}

void Manager::up_date()
{
    string *id = new string;
again:
    cout << "nhap id ban muon cap nhat: ";
    cin >> *id;
    if (search(id) == -1)
    {
        cout << "id khong ton tai!" << endl;
        goto again;
    }
    cout << "\nchon truong muon cap nhat: " << endl;
    cout << "=================================================" << endl;
    cout << "1. >>>ID<<<" << endl;
    cout << "2. >>>Ten<<<" << endl;
    cout << "3. >>>Tuoi<<<" << endl;
    cout << "4. >>>Gioi tinh<<<" << endl;
    cout << "=================================================" << endl;
    int cache;
    cin >> cache;
    switch (cache)
    {
    case 1:
    {
        cout << "nhap ID moi: ";
        cin >> this->IFM[bien_dem].ID;
        cout << endl;
    }
    break;
    case 2:
    {
        cout << "nhap ten moi: ";
        cin.ignore();
        getline(cin, this->IFM[bien_dem].Name);
        cout << endl;
    }
    break;
    case 3:
    {
        cout << "nhap tuoi moi: ";
        cin >> this->IFM[bien_dem].Age;
        cout << endl;
    }
    break;
    case 4:
    {
        cout << "nhap gioi tinh moi: ";
        cin >> this->IFM[bien_dem].Sex;
        cout << endl;
    }
    break;

    default:
        cout << "nhap lai!" << endl;
        break;
    }
    delete id;
    id = nullptr;
}

void Manager::show()
{
    cout << "=================================================" << endl;
    cout << setw(5) << "ID"
         << "|" << setw(20) << "Ten"
         << "|" << setw(4) << "Tuoi"
         << "|" << setw(5) << "gioi tinh" << endl;
    for (int i = 0; i < STDN; i++)
    {
        cout << setw(5) << this->IFM[i].ID << "|" 
             << setw(20) << this->IFM[i].Name << "|" 
             << setw(4) << this->IFM[i].Age << "|" 
             << setw(5) << this->IFM[i].Sex << endl;
    }
}

#endif //__FUNCTION__