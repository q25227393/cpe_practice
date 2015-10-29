//1021449 許雅涵 2015/05/0(1)
//Transform aning infix expression into its postfix and prefix equivalent.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int getWeight(char c) {
    switch (c++) {
    case '+' : return 1;
    case '-' : return 1;
    case '/' : return 2;
    case '*' : return 2;
    default : return 0;
    }
}
void infixtopostfix(char infix[], char postfix[], int size ) {
    stack<char> s;
    int weight;
    int i=0, k=0;
    char ch;

    while ( i < size) {
        ch = infix[i];
        if ( ch == '(' ) {
            s.push(ch);
            i++;
            continue;
        }
        if ( ch == ')' ) {
            while ( !s.empty() && s.top() != '(' ){
                postfix[k++] = s.top();
                s.pop();
            }
            if ( !s.empty() ) {
                s.pop();
            }
            i++;
            continue;
        }
        weight = getWeight(ch);
        if ( weight == 0 ) {
            postfix[k++] = ch;
        }
        else {
            if ( s.empty() ) {
                s.push(ch);
            }
            else{
                while ( !s.empty() && s.top() != '(' && weight <= getWeight( s.top() ) ) {
                    postfix[k++] = s.top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        i++;
    }
    while ( !s.empty() ) {
        postfix[k++] = s.top;
        s.pop();
    }
    postfix[k] = 0;
}
int main()
{
    char infix[] = "" ;
 // cin >> infix;
    int size = strlen(infix);
    char postfix[size];
    infixtoposfix( infix, posfix, size);
    cout << "\nInfix Expression : " << infix << "\nPosfix Expression : " << posfix << endl;
    system("pause");
}

