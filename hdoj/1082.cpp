#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

struct matrix {
    int row;
    int col;
};

//falg来确定E的初始值, flag = 0的时候，将第一次的策划你
long result = 0;
bool error=false;

int main(){
    map<char, matrix> mmp;
    int n;
    char name;
    stack<char> stack_for_char;
    stack<matrix> stack_for_matrix;
    while( cin >> n ){
        for( int i=0; i<n; i++ ){
            cin >> name;
            matrix tmp;
            cin >> tmp.row;
            cin >> tmp.col;
            mmp[name] = tmp;
        }
        string syntax;
        while( cin >> syntax ){
            if ( syntax.size() == 1 ){
                cout << "0" << endl;
            }else{
                error = false;
                result = 0;
                for( unsigned int i=0; i<syntax.size(); i++ ){
                    if( syntax[i] == '('){
                        stack_for_char.push(syntax[i]);
                    }
                    else if ( syntax[i] == ')' ){
                        //出栈并计算
                        stack_for_char.pop();
                        matrix m1 = stack_for_matrix.top();
                        stack_for_matrix.pop();
                        matrix m2 = stack_for_matrix.top();
                        stack_for_matrix.pop();
                        if ( m2.col != m1.row ){
                            error = true;
                            break;
                        }
                        else{
                                result += (m2.row * m2.col * m1.col);
                                m2.col = m1.col;
                                stack_for_matrix.push(m2);
                        }
                    }else{
                        stack_for_matrix.push(mmp[syntax[i]]);
                    }
                }
                if ( error )
                    cout << "error" << endl;
                else
                    cout << result << endl;
            }
        }
    }
    return 0;
}
