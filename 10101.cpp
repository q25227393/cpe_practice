#include<iostream>
#include<iomanip>
using namespace std;
void math(long long int num)
{
     if(num >= 10000000) {
         math(num/10000000);
         cout << " kuti";
         num %= 10000000;
     }
     if(num >= 100000) {
         math(num / 100000);
         cout << " lakh";
         num %= 100000;
     }
     if(num >= 1000) {
         math(num / 1000);
         cout << " hajar";
         num %= 1000;
     }
     if(num >= 100) {
         math(num / 100);
         cout << " shata";
         num %= 100;
     }
     if(num > 0)
         cout << " " << num;
}
int main()
{
    long long num, count=0;
    while(cin >> num) {
        cout << setw(4) << ++count << ".";
        if(num>0)
            math(num);
        else
            cout << " 0";
        cout << endl;
    }
}
