//uva10041
#include<iostream>
#include<algorithm>
#define relative 30001
using namespace std;
int main()
{
    int n,r,s[relative];
    cin >> n;
    while(n--)
    {
        int sum = 0;
        cin >> r;
        for(int i=0; i < r; i++){
            cin >> s[i];
        }
        sort(s, s+r);
        int mid = s[r/2];
        for(int i=0; i < r; i++){
            sum += abs(s[i] - mid);
        }
        cout << sum << endl;
    }
}
