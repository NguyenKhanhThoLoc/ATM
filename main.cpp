#include "Funtion.h"
long long idnhap;
class ATM
{
private:
    long long ID;
    string name;
    string pass;
    long long Balance;
public:
    ATM(string _name = "",string _pass = "", long long _Balance = 0, long long _ID = 0)
{
    name = _name;
    pass = _pass;
    Balance = _Balance;
    ID = _ID;
}
    //void Add_Name_To_File();
    void Add_Pass_To_File();
    void Add_ID_To_File();
    void Add_Balance_To_File();
    void screen();
    void Create();
    void ScreenFuntion();

    void Update_Account();
    bool Sign_up();
    bool Sign_In();
    void Send_money();
    void Withdraw();

};
ATM Account;


void ATM::screen(){
    cout << "CHAO MUNG QUY KHACH DA DEN DICH VU CHUNG TOI" << endl;
    cout << "1. DANG KI TAI KHOAN !!"<< endl;
    cout << "2. DANG NHAP VA THUC HIEN CAC DICH VU" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;

}
void ATM::ScreenFuntion()
{
    cout << "1. NAP TIEN ." << endl;
    cout << "2. RUT TIEN ." << endl;
    cout << "3. KIEM TRA LICH SU VA SO DU TAI KHOAN" <<endl;
    cout << "4. Thoat !" <<endl;
}

void ATM::Create()
{
    cout << "HO VA TEN KHONG CHUA SO VA KI TU DAC BIET"<<endl;
    cout << "MAT KHAU KHONG DUOC QUA 10 KI TU !!"<<endl;
    cout << "Ho Va Ten: ";
    cin.ignore();
    getline(cin,Account.name);
    int lname = Account.name.length();
    cout << endl;
    cout << "Mat Khau: ";
    getline(cin, Account.pass);
    int lpass = Account.pass.length();
    cout << endl;
    if(CheckName(Account.name, lname) && CheckPass(Account.pass, lpass))
    {
        cout << "Ban da dang ki thanh cong !" << endl;
        long long DemID = Count_IDfile();
        DemID = DemID+1;
        Account.ID = DemID;
        cout << "ID cua ban la: " << Account.ID <<endl;
        Add_Pass_To_File();
        Add_ID_To_File();
        Add_Balance_To_File();
        cout << "Phim bat ki de thoat !!" <<endl;

        char key = getch();
        system("cls");

    }
    else
    {
        system("cls");
        Account.Create();
    }
}
//void ATM::Add_Name_To_File()
//{
//    fstream FileName("Name.txt", ios::app);
//    FileName << Account.name <<endl;
//    FileName.close();
//}
void ATM::Add_Pass_To_File()
{
    fstream FilePass("Pass.txt", ios::app);
    FilePass << Account.pass <<endl;
    FilePass.close();
}
void ATM::Add_ID_To_File()
{
    fstream FileID("ID.txt", ios::app);
    FileID << Account.ID <<endl;
    FileID.close();
}
void ATM::Add_Balance_To_File()
{
    fstream FileBalance("Balance.txt", ios::app);
    FileBalance << Account.Balance << endl;
    FileBalance.close();
}

bool ATM::Sign_In()
{
    bool success = 1;
    int dem = 0;
    while(1)
    {
        system("cls");
        long long IDin ;
        cout << "Nhap ID cua ban tai day: " ;
        cin >> IDin;
        if(ID_In_FileID(IDin))
        {
            idnhap = IDin;
            cin.ignore();
            string PassIn;
            cout << "Nhap mat khau cua ban : ";
            getline(cin, PassIn);
            if(Pass_In_FilePass(PassIn, IDin))
            {
                cout << "Dang nhap thanh cong" <<endl;
                cout << "Doi trong giay lat";
                for(int i = 0; i < 3; i++, sleep(1))cout << '.';
                cout << '\n';
                return 1;
            }
            else
                {
                    cout << "Mat Khau da sai !!" <<endl;
                    for(int i = 1; i < 4; i++, sleep(1)) cout << '.';
                    cout << '\n';
                    success = 0;
                    break;
                }
        }
        else
        {
        system("cls");
        cout << "Khong ton tai ID !!!" <<endl;
        cout << "Moi nhap lai ID !!!" <<endl;
        for(int i = 1 ; i < 3; i++, sleep(1)) cout <<'.';
        cout <<endl;
        dem = dem + 1;
            if(dem == 3)
            {
                system("cls");
                cout << "Nhap qua 3 lan !!!" <<endl;
                success = 0;
                break;
            }

        }
    }
    return success;
}
void ATM::Send_money()
{
    cout << "So tien nap vao lon hon 0, it hon 1000000 va chia het cho 1000 !!" << endl;
    cout << "So tien quy khach muon nap : " ;
    long long moneysend;
    while(1)
    {
        long long a;
        cin >> a;
        if(a>0 && a%1000 == 0 && a < 1000000)
        {
            moneysend = a;
            break;
        }
        system("cls");
        cout << "So tien khong hop le !!"<<" Nhap lai: ";
    }
    cout <<"Ban da nap thanh cong: " << moneysend <<endl;
    for(int i = 1; i < 3; i++, sleep(1)) cout << '.';
    time_t hientai = time(0);
    char* dt = ctime(&hientai);
    Update_History_And_Balance(dt, moneysend, 0, idnhap);
}
void ATM::Withdraw()
{
    cout << "So tien quy khach muon rut : " ;
    long long moneyWd;
    cin >> moneyWd;
    cout << "VND.";
    for(int i = 1; i < 3; i++, sleep(1)) cout << '.';
    time_t hientai = time(0);
    char* dt = ctime(&hientai);
    Update_History_And_Balance(dt, 0, moneyWd, idnhap);
}

//void File_Archive()
//{
//    fstream file("file.txt");
//    long long ID;
//    string name;
//    string pass;
//    long long Balance;
//    while(!file.eof())
//    {
//
//    }
//}

int main()
{
        while(1){
            string button;
            Account.screen();
            cin >> button;
            system("cls");
            if(button == "1")
            {
                Account.Create();
            }
            else if(button == "2")
            {
                if(!Account.Sign_In())
                {
                    system("cls");
                    cout << "Dang Nhap That Bai" << endl;
                    cout << "Dang Nhap Lai" << '\n';
                    for(int i = 1; i < 4; i++, sleep(1)) cout << '.';
                    continue;
                }
                    while(1)
                    {
                        system("cls");
                        Account.ScreenFuntion();// MÀN HÌNH CÁC CHỨC NĂNG
                        int funtion;// PHÍM THỰC HIỆN CÁC CHỨC NĂNG KHI ĐÃ ĐĂNG NHẬP THANH CÔNG.
                        cin >> funtion;
                        if(funtion == 1)
                        {
                            Account.Send_money(); // NẠP TIỀN
                        }
                        if(funtion == 2)
                        {
                            Account.Withdraw(); // RÚT TIỀN
                        }

                        if(funtion == 3)
                        {
                            History_Balance(); // KIỂM TRA LỊCH SỦ VÀ SỐ DƯ TÀI KHOẢN cái này lại chia ra trong có 2 hàm in số dư và in lịch sử giao dịch;
                        }
                        if(funtion == 4)
                        {
                            cout << "Tam biet quy khach" << endl;
                            exit(0);
                        }

                    }
                }

            else
            {
                cout << "Khong co lua chon phu hop !!"<<endl;
                cout << "Nhan phim bat ki de thoat ra man hinh chinh !!" << endl;
                char key = getch();
                system("cls");
            }
    }
}
