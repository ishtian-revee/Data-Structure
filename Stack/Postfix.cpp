#include<iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;        // 562+*84/-    ans : 38

int main()
{
    string exp;
    int n , a , b , c;

    cout << endl << "Enter the expression : ";
    cin >> exp;
    cout << endl;

    n = exp.length();

    stack <int> s;

    for( int i=0; i<n; i++ ){

        if( exp[i] >= '0' && exp[i] <= '9' ){

            s.push(exp[i] - 48);
            cout << exp[i] - 48 << " is pushed." << endl;
        }else if( exp[i] == '^' ){

            b = s.top();
            s.pop();
            cout << b << " is popped." << endl;
            a = s.top();
            s.pop();
            cout << a << " is popped." << endl;
            c = pow(a , b);
            s.push(c);
            cout << c << " is pushed." << endl;
        }else if( exp[i] == '+' ){

            b = s.top();
            s.pop();
            cout << b << " is popped." << endl;
            a = s.top();
            s.pop();
            cout << a << " is popped." << endl;
            c = a + b;
            s.push(c);
            cout << c << " is pushed." << endl;
        }else if( exp[i] == '-' ){

            b = s.top();
            s.pop();
            cout << b << " is popped." << endl;
            a = s.top();
            s.pop();
            cout << a << " is popped." << endl;
            c = a - b;
            s.push(c);
            cout << c << " is pushed." << endl;
        }else if( exp[i] == '*' ){

            b = s.top();
            s.pop();
            cout << b << " is popped." << endl;
            a = s.top();
            s.pop();
            cout << a << " is popped." << endl;
            c = a * b;
            s.push(c);
            cout << c << " is pushed." << endl;
        }else if( exp[i] == '/' ){

            b = s.top();
            s.pop();
            cout << b << " is popped." << endl;
            a = s.top();
            s.pop();
            cout << a << " is popped." << endl;
            c = a / b;
            s.push(c);
            cout << c << " is pushed." << endl;
        }
    }

    cout << endl << "Final result : " << s.top() << endl;
}
