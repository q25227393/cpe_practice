#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, m, sum=0;
    while(cin >> n >> m){
        int temp_n=n;
        int temp_m=m;
        if( n > m ){
            int buffer = n;
            n = m;
            m = buffer;
        }
        int cycle;
        while(n<=m){
            cycle = 1;
            int j = n;
            while( j > 1 ){
                if(j % 2 == 0)
                    j /= 2;
                else
                    j = 3*j+1;
                cycle++;
            }
            if( cycle > sum )
                sum = cycle;
            n++;
        }
        cout << temp_n << " " << temp_m << " " << sum << endl;
    }
}
