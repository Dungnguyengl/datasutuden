#include<iostream>
#include<iomanip>
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
    void soft_data(std::string id);
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
    void delete_data();
    void up_date();
    void show();

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

void Manager::soft_data(std::string id)
{
    search(id);
    for (int i = bien_dem; i <= STDN; i++)
    {
        IFM[i] = IFM[i+1];
    }
}

void Manager::delete_data()
{
    std::string id;
    std::cout << "nhap id sinh vien can xoa: " ;
    std::cin >> id;
    std::cout << std::endl;
    search(id);
    IFM[bien_dem].ID = "";
    IFM[bien_dem].Name = "";
    IFM[bien_dem].Sex = "";
    IFM[bien_dem].diem = 0;
    IFM[bien_dem].status = 0;
    soft_data(id);
    STDN--;
}

void Manager::up_date()
{
    std::string id;
    again:
    std::cout << "nhap id ban muon cap nhat: ";
    std::cin >> id;
    if (search(id) == -1)
    {
        std::cout << "id khong ton tai!" << std::endl;
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
            std::cout << "nhap ID moi: ";
            std::cin >> IFM[bien_dem].ID;
            std::cout << std::endl;
        }
        break;
    case 2:
        {
            std::cout << "nhap ten moi: ";
            std::cin >> IFM[bien_dem].Name;
            std::cout << std::endl;
        }
        break;
    case 3:
        {
            std::cout << "nhap tuoi moi: ";
            std::cin >> IFM[bien_dem].Age;
            std::cout << std::endl;
        }
        break;
    case 4:
        {
            std::cout << "nhap gioi tinh moi: ";
            std::cin >> IFM[bien_dem].Sex;
            std::cout << std::endl;
        }
        break;

    default:
        break;
    }
}

void Manager::show()
{
    std::cout << "=================================================" << std::endl;
    std::cout << std::setw(5) << "ID"  << "|" << std::setw(10) << "Ten" << "|" << std::setw(4) << "Tuoi" << "|" << std::setw(5) << "gioi tinh" << std::endl;
    for(int i = 0; i < STDN; i++)
    {
        std::cout << std::setw(5) << IFM[i].ID << "|" << std::setw(10) << IFM[i].Name  << "|" << std::setw(4) << IFM[i].Age << "|" << std::setw(5) << IFM[i].Sex << std::endl;
    }
}

int main()
{
    int which;
    char i;
    General general;
    Manager manager;
    do
    {
        general.displaymenu();
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
        
        default: std::cout << "nhap sai" << std::endl;
        }
        std::cout << "ban co muon tiep tuc! (y/n)" << std::endl;
        std::cin >> i;
    } while (i=='y' || i=='Y');
    return 0;
}

