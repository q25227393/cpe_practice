#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num;
    while(cin >> num){
        if(num > 1 && num <= 1000000){
            for(int i=2; i <= sqrt(num); i++){
                if(num % i == 0)//print num
                    cout << i ;
                int count = 0;//num of n 
                while(num % i == 0){
                    count++;
                    num /= i;
                }
                if(num == 1)
                    cout << "^" << count << endl;
                else if(count > 1)
                    cout << "^" << count << " * ";
                else if(count == 1 && num > 1)
                    cout << " * ";
            }
            if(num > 1)
                cout << num << endl;
        }
    }
}
