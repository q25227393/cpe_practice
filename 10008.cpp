#include<iostream>
using namespace std;
int main()
{
    int n;
    char str[1000];
    cin >> n;
    while(n--){
        int a[26] = {0}, total = 0;
        cin >> str;
        for(int i=0; i < sizeof(str); i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                a[str[i] - 'a']++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                a[str[i] - 'A']++;
            }
            total++;
        }
        for(int i=total; i >= 1; i--)
            for(int j=0; j < 26; j++)
                if(a[j] == i)
                    cout << a[j]+'A' << ' ' << i <<endl;
    }
}
