#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;
long long Count_IDfile();
bool CheckName(string &Name, int dodaiten);
bool CheckPass(string &mk, int dodaimk);
long long check_balance(long long id);
bool Compare_Pass(string s1, string s2);
void Update_History_And_Balance(char *ntime, long long send , long long withdraw , long long id);
bool ID_In_FileID(long long x);
bool Pass_In_FilePass(string str, long long n);
void History(long long idnhap);
void Balance(long long idnhap);
void History_Balance();

