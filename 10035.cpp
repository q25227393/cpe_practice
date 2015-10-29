#include<iostream>
using namespace std;

int main(){
    int add1, add2, carry, count;
    while(cin>>add1>>add2){
        if(add1==0&&add2==0)
              break;
        carry = 0;
        count = 0;
        while( (add1!=0) && (add2!=0) ){
            carry = add1%10 + add2%10 + carry;
            carry /= 10;
            add1 /= 10;
            add2 /= 10;
            if( carry!=0 )
                count++;
        }
        if( count == 1 )
            cout<<"1 carry operation.\n";
        else if( count == 0)
            cout<<"No carry operation.\n";
        else
            cout<<count<<" carry operations.\n";
        }
    }
