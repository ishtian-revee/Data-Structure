#include<iostream>
#include<stack>
#include<string>
#include<math.h>

using namespace std;        // (A-B)/((D+E)*F)  Ans : AB-DE+F*/

bool isOperator( char expression );
bool priorty( char o1 , char o2 );
int priorty_chk( char op );
bool operand( char oprnd );

int main()
{
    stack <char> s;
    string exp;
    string postfix = "";

    cout << endl << "Enter an expression : ";
    cin >> exp;
    cout << endl;

    int n = exp.length();

    for( int i=0; i<n; i++ ){

        if( exp[i] == '(' ){

            s.push( exp[i] );
        }else if( isOperator( exp[i] ) ){

            while( !s.empty() && s.top() != '(' && priorty( s.top() , exp[i] ) ){

                postfix += s.top();
                s.pop();
            }
            s.push( exp[i] );
        }else if( operand( exp[i] ) ){

            postfix += exp[i];
        }else if( exp[i] == ')' ){

            while( !s.empty() && s.top() != '(' ){

                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while( !s.empty() ){

        postfix += s.top();
        s.pop();
    }

    cout << endl << "Postfix : " << postfix << endl;
}

bool isOperator( char expression ){

    if( expression == '^' || expression == '+' || expression == '-' || expression == '*' || expression == '/' ){

        return true;
    }else{

        return false;
    }
}

bool priorty( char o1 , char o2 ){

    int operator1 = priorty_chk(o1);
    int operator2 = priorty_chk(o2);

    if( operator1 == operator2 ){

        return true;
    }else if( operator1 > operator2 ){

        return true;
    }else{

        return false;
    }
}

int priorty_chk( char op ){

    if( op == '+' || op == '-' ){

        return 1;
    }else if( op == '*' || op == '/' ){

        return 2;
    }
}

bool operand( char oprnd ){

    if( oprnd >= '0' && oprnd <= '9' ){

        return true;
    }else if( oprnd >= 'a' && oprnd <= 'z' ){

        return true;
    }else if( oprnd >= 'A' && oprnd <= 'Z' ){

        return true;
    }else{

        return false;
    }
}
