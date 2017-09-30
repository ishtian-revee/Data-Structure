#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool are_pair( char opening , char closing );
bool balanced( string exp );

int main()
{
    string expression;

    cout << "Enter the expression : ";
    cin >> expression;

    if( balanced(expression) ){

        cout << endl << "Valid Expression." << endl;
    }else{

        cout << endl << "Invalid expression." << endl;
    }
}

bool are_pair( char opening , char closing ){

    if( opening == '(' && closing == ')' ){

        return true;
    }else if( opening == '{' && closing == '}' ){

        return true;
    }else if( opening == '[' && closing == ']' ){

        return true;
    }else{

        return false;
    }
}

bool balanced( string exp ){

    stack<char> S;

    for( int i=0; i<exp.length(); i++ ){

        if( exp[i] == '[' || exp[i] == '{' || exp[i] == '(' ){

            S.push(exp[i]);
        }else if( exp[i] == ']' || exp[i] == '}' || exp[i] == ')' ){

            if( S.empty() || !are_pair( S.top() , exp[i] ) ){

                return false;
            }else{

                S.pop();
            }
        }
    }

    if( S.empty() ){

        return true;
    }else{

        return false;
    }
}
