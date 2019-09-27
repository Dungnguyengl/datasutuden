#include<iostream>
#include<fstream>


class General
{
protected:
    int STDN=0;
    struct Infomation
    {
        std::string ID;
        std::string Name;
        std::string Sex;
        int Age;
        float diem;
        int status =0;
    } ;
    std::ofstream outfile;
    std::ifstream infile;
public:
    void displaymenu();
    General();
    ~General();
};

General::General()
{
    displaymenu();
}

General::~General()
{
    std::cout << "tam biet!" << std::endl;
}

void General::displaymenu()
{
    std::cout << "=====================MENU========================" << std::endl;
    std::cout << "1. Them sinh vien!" << std::endl;
    std::cout << "2. Xoa sinh vien!" << std::endl;
    std::cout << "3. Cap nhat ban ghi!" << std::endl;
    std::cout << "4. Xem toan bo sinh vien!" << std::endl;
    std::cout << "5. Tinh diem tb sinh vien chon" << std::endl;
    std::cout << "6. Sinh vien diem cao nhat" << std::endl;
    std::cout << "7. Vien vien diem thap nhat" << std::endl;
    std::cout << "8. Tim ban ghi sinh vien bang id" << std::endl;
    std::cout << "9. Sap xep ban gi theo diem" << std::endl;
    std::cout << std::endl;
}

class Manager : public General
{
private:
    int search(std::string id);
    int bien_dem = 0;
    std::ofstream outfile;
    std::ifstream infile;
protected:
    Infomation IFM[10];
public:
    Manager();
    ~Manager();
    void read_data();
    void write_data();
    void add_data(void);
};

Manager::Manager()
{
    infile.open("data.txt");
    read_data();
    outfile.open("data.txt");
}

Manager::~Manager()
{
    infile.close();
    write_data();
    outfile.close();
}

int Manager :: search(std::string id)
{
    int found = -1;
    int i;
    for ( i = 0; i < STDN && found ==-1; i++)
    {
        if (IFM[i].ID==id)
        {
            found = 1;
            bien_dem = i;
        }
        else 
        {
            found = -1;
        }
    }
    return found;
}

void Manager :: read_data()
{
    infile >> STDN;
    for (int i = 0; i <= STDN; i++)
    {
        infile >> IFM[i].ID;
        infile >> IFM[i].Name;
        infile >> IFM[i].Age;
        infile >> IFM[i].Sex;
        infile >> IFM[i].status;
    }
}
void Manager :: write_data()
{
    outfile << STDN << std::endl;
    for(int i = 0; i <= STDN; i++)
    {
        outfile << IFM[i].ID << std::endl;
        outfile << IFM[i].Name << std::endl;
        outfile << IFM[i].Age << std::endl;
        outfile << IFM[i].Sex << std::endl;
        outfile << IFM[i].status << std::endl;
    }
}

void Manager :: add_data(void)
{
    again:
    std::cout << "=================================================" << std::endl;
    std::cout << "Nhap id sv:" ;
    std::cin >> IFM[STDN].ID;
    if (search(IFM[STDN].ID)!=-1)
    {
        std::cout << "ID da ton tai!" << std::endl;
        goto again;
    }
    std::cout << "nhap ten: " ;
    std::cin >> IFM[STDN].Name;
    std::cout << "\nnhap tuoi: ";
    std::cin >> IFM[STDN].Age;
    std::cout << "\nnhap gioi tinh: ";
    std::cin >> IFM[STDN].Sex;
    IFM[STDN].status = 1;
    STDN++;
}

int main()
{
    General general;
    Manager manager;
    do
    {
    manager.add_data();
    } while ("y"!="y");
    return 0;
}
