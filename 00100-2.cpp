#include<iostream>
using namespace std;
int main()
{
    int i, j, temp_i, temp_j;
    while(cin >> i >> j){
        temp_i=i;
        temp_j=j;
        if(i>j){
            int buffer=i;
            i=j;
            j=buffer;
        }
        int cycle,sum=0;
        while(i<=j){
            cycle=1;
            int z=i;
            while(z>1){
                if(z%2==0)
                    z /= 2;
                else
                    z = 3*z+1;
                cycle++;
            }
            if(cycle>=sum)
                sum=cycle;
            i++;
        }
        cout<<temp_i<<" "<<temp_j<<" "<<sum<<endl;
    }
}
