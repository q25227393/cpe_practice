#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char num[100];
    while(cin.getline(num,100)){
        for(int i=0; i < strlen(num); i++){
            num[i] -= 7;
        }
        cout << num << endl;
    }
}
