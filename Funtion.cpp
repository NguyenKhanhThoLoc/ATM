#include <iostream>
using namespace std;
#include "Funtion.h"
long long IDnhap;
long long Count_IDfile()
{
    long long line = 0;
    fstream file("ID.txt");
    long long id;
    while(file >> id)
    {
        line++;
    }
    return line;
}
bool CheckName(string &Name, int dodaiten)// Kiem tra xem ten co dung yeu cau khong
{
    bool success = 1;
    if(dodaiten == 0) success = 0;
    for(int i = 0; i < dodaiten; i++)
    {
        if(!success) break;
        if(Name[i] !=' ' && ('A' > Name[i] || 'Z' < Name[i]) && ('a' > Name[i] || 'z' < Name[i]))
            success = 0;
    }
    if(!success)
    {
        cout << '\n' <<"Ho va ten hoac Mat Khau Khong hop le!!" <<endl;
        cout << "Nhap lai !!" <<endl;
        for(int i = 1 ; i < 3; i++, sleep(1)) cout <<'.';
        cout <<endl;
    }
    return success;
}
bool CheckPass(string &mk, int dodaimk)// kiem tra xem mat khau co sung yeu cau khong
{
    int Count = 0;
    for(int i = 0;i < dodaimk; i++)
    {
        Count++;
    }
    if(Count <= 9)
    {
        return 1;
    }
    else {
        cout << '\n' << "Mat Khau hoac Ho ten khong hop le!!!" << '\n';
        cout << "Moi nhap lai!!!" << '\n';
        cout << "Vui Long Cho!!!";
        for(int i = 1; i < 3; i++, sleep(1)) cout << '.';
        cout << '\n';
        return 0;
    }
}
long long check_balance(long long id)
{
    long long line = 0;
    fstream file("Balance.txt");
    long long Balance;
    while(file >> Balance)
    {
        line++;
        if(line == id)
        {
            return Balance;
        }
    }

}
bool Compare_Pass(string s1, string s2)
{
    bool ktr = 1;
    if(s1.length() != s2.length())
    {
        ktr = 0;
    }
    else
    {
        for(int i = 0 ; i < s1.length();i++)
        {
            if(s1[i] != s2[i])
            {
                ktr = 0;
                break;
            }
        }
    }
    return ktr;
}
void Update_History_And_Balance(char *ntime, long long send , long long withdraw , long long id)
{
    string iD = to_string(id);
    string namefile = "history_" + iD + ".txt";
    ofstream HistoryFile(namefile, ios::app);
    HistoryFile << ntime << "nap vao : " << send << " rut ra : " << withdraw <<"." << endl;
    HistoryFile.close();

    fstream Balancefile("Balance.txt");
    fstream out("Balance.txt");
    int Count = 0;
    long long Balance;
    while(Balancefile >> Balance)
    {
        Count++;
            if( Count == id)
            {
                Balance = Balance + send - withdraw;
            }
            out << Balance <<'\n';
    }
    Balancefile.close();

}

bool ID_In_FileID(long long x)// Kiem tra xem ID co trong FileId khong
{
    bool checkid = 0;
    fstream IDfile("ID.txt");
    long long DemID = Count_IDfile();
    for(int i = 0; i <= DemID; i++)
    {
            long long a;
            IDfile >> a;
            if(IDfile && a == x)
            {
                checkid = 1;
                IDnhap = x;
                break;
            }
    }
	IDfile.close();
	return checkid;
}
bool Pass_In_FilePass(string str, long long n) // neu ID dung thi xem mat khau co dung khong.
{
    bool checkpass = 0;
    fstream PassFile("Pass.txt");
    int Count = 0;
    for(int i = 0; i < n; i++)
    {
        Count++;
            string pass;
            getline(PassFile, pass);
            if(PassFile && Count == n)
            {
                if(Compare_Pass(str, pass))
                {
                    checkpass = 1;
                    break;
                }
            }
    }
	PassFile.close();
    return checkpass;
}
void History(long long idnhap)
{   string id = to_string(idnhap);
    string namefile = "history_" + id + ".txt";
    fstream HistoryFile(namefile);
    while(!HistoryFile.eof())
    {
        string s;
        getline(HistoryFile, s);
        cout << s << endl;
    }
    HistoryFile.close();
}
void Balance(long long idnhap)
{
    fstream BalanceFile("Balance.txt");
    int Count = 0;
    long long balance;
    for(int i = 0 ; i < IDnhap ; i++)
    {
        Count++;
        BalanceFile >> balance;
        if(BalanceFile && Count == idnhap)
        {
            cout << balance <<endl;
        }
    }
}
void History_Balance()
{
    system("cls");
    cout << "Lich su giao dich cua : ";
    History(IDnhap);
    cout << "So tien con lai trong tai khoan: ";
    Balance(IDnhap);
    for(int i = 1; i < 10; i++, sleep(1)) cout << '.';
}
