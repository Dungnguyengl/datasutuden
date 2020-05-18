#include "Manager.h"

Manager::Manager(){
    read_data();
}

Manager::~Manager(){
    write_data();
}

bool Manager ::search(const std::string &ID)
{
    for (auto &&item : this->IFM)
    {
        if (item.ID == ID)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Manager ::add_data()
{
    std::string ID = "";
    Infomation IFM;
again:
    std::cout << "=================================================" << std::endl;
    std::cout << "Nhap id sv:";
    std::cin >> ID;
    if (search(ID) == true)
    {
        std::cout << "ID da ton tai!" << std::endl;
        goto again;
    }
    IFM.ID = ID;
    std::cout << "nhap ten: ";
    std::cin.ignore();
    getline(std::cin, IFM.Name);
    std::cout << "\nnhap tuoi: ";
    std::cin >> IFM.Age;
    std::cout << "\nnhap gioi tinh: ";
    std::cin >> IFM.Sex;
    IFM.Status = true;
    this->IFM.push_back(IFM);
}

void Manager::delete_data()
{
    std::string ID = "";
    std::cout << "nhap id sinh vien can xoa: ";
    std::cin >> ID;
    std::cout << std::endl;
    if (this->search(ID))
    {
        this->IFM.erase(std::find(this->IFM.begin(), this->IFM.end(), ID));
        std::cout << "!!! Da xoa sinh vien !!!" << std::endl;
    }
    else
    {
        std::cout << "!!!ID sinh vien khong ton tai!!!" << std::endl;
        ;
    }
}

void Manager::up_date()
{
    std::string ID = "";
again:
    std::cout << "nhap ID ban muon cap nhat: ";
    std::cin >> ID;
    if (!search(ID))
    {
        std::cout << "ID khong ton tai!" << std::endl;
        goto again;
    }
    std::cout << "\nchon truong muon cap nhat: " << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << "1. >>>ID<<<" << std::endl;
    std::cout << "2. >>>Ten<<<" << std::endl;
    std::cout << "3. >>>Tuoi<<<" << std::endl;
    std::cout << "4. >>>Gioi tinh<<<" << std::endl;
    std::cout << "=================================================" << std::endl;
    int cache;
    std::cin >> cache;
    switch (cache)
    {
    case 1:
    {
        std::string newID = "";
        std::cout << "nhap ID moi: ";
        std::cin >> newID;
        for (auto &&item : this->IFM)
        {
            if (item.ID == ID)
            {
                item.ID = newID;
                break;
            }
        }
        std::cout << std::endl;
    }
    break;
    case 2:
    {
        std::string newName = "";
        std::cout << "nhap ten moi: ";
        std::cin.ignore();
        getline(std::cin, newName);
        for (auto &&item : this->IFM)
        {
            if (item.ID == ID)
            {
                item.Name = newName;
                break;
            }
        }
        std::cout << std::endl;
    }
    break;
    case 3:
    {
        int newAge = 0;
        std::cout << "nhap tuoi moi: ";
        std::cin >> newAge;
        for (auto &&item : this->IFM)
        {
            if (item.ID == ID)
            {
                item.Age = newAge;
                break;
            }
        }
        std::cout << std::endl;
    }
    break;
    case 4:
    {
        std::string newSex;
        std::cout << "nhap gioi tinh moi: ";
        std::cin >> newSex;
        for (auto &&item : this->IFM)
        {
            if (item.ID == ID)
            {
                item.Sex = newSex;
                break;
            }
        }
        std::cout << std::endl;
    }
    break;
    default:
        std::cout << "!!! Nhap sai !!!" << std::endl;
        break;
    }
}

void Manager::show()
{
    std::cout << "=================================================" << std::endl;
    std::cout << std::setw(5) << "ID"
              << "|" << std::setw(20) << "Ten"
              << "|" << std::setw(4) << "Tuoi"
              << "|" << std::setw(5) << "gioi tinh" << std::endl;
    for (auto &&item : this -> IFM)
    {
        std::cout << std::setw(5) << item.ID << "|"
                  << std::setw(20) << item.Name << "|"
                  << std::setw(4) << item.Age << "|"
                  << std::setw(5) << item.Sex << std::endl;
    }
}
