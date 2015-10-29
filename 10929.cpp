#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        if((n%11==0)&&(n>0))
            cout<<n<<" is a multiple of 11."<<endl;
        else if(n==0)
            break;
        else 
            cout<<n<<" is not a multiple of 11."<<endl;
    }
}
