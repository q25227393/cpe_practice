#include<iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--){
        int num, temp=0, total=0;
        cin >> num;
        if(num != 0){
            total = 1;
            while(num != 0){
                temp = num % 10;
                num /= 10;
                total *= temp;
            }
        }
        else
            total = 0;
        cout << total << endl;
    }
}
