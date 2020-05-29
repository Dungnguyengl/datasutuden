#include "../bin/General.h"

void General ::read_data()
{
    std::ifstream infile;
    infile.open("data/data.txt");
    while (!infile.eof())
    {
        Infomation IFM;

        infile >> IFM.ID;
        getline(infile, IFM.Name);
        infile >> IFM.Age;
        infile >> IFM.Sex;
        infile >> IFM.Status;

        this->IFM.push_back(IFM);
    }
    infile.close();
}

void General ::write_data()
{
    std::ofstream outfile;
    outfile.open("data/data.txt");
    outfile << (int)this -> IFM.size() << std::endl;
    for (auto && item : this -> IFM)
    {
        outfile << item.ID << "\t";
        outfile << item.Name << "\n";
        outfile << item.Age << "\t";
        outfile << item.Sex << "\t";
        outfile << item.Status << "\t";
        outfile << std::endl;
    }
    outfile.close();
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
