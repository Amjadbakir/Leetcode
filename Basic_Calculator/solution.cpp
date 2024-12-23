#include <string>
#include <stack>
#include <iostream>

using namespace std;

/*This task is about creating a basic calculator that given a string a with different operations, 
*our goal is to parse the string and calculate the expression which consists of only additions and multiplications.
*/


int calculate(string a){
    stack<int> signStack;
    stack<int> stack;

    int result = 0;
    int sign = 1;

    for(int i = 0; i < a.size(); ++i){
        char c = a[i];

        if(c == '('){
            stack.push(result);
            signStack.push(sign);
            result = 0;
            sign = 1;
        }else if(isdigit(c)){

            int num = 0;
            while (i < a.size() && isdigit(a[i])) {
                num = num * 10 + (a[i] - '0');
                i++;
            }
            i--;
            result += sign * num;
        }else if(c == ')'){
            result = result * signStack.top() + stack.top();
            stack.pop();
            signStack.pop();
        }else if(c == '-'){
            sign = -1;
        }else if(c=='+'){
            sign = 1;
        }
    }

    return result;
}

int main(){
    string s = "(1)";
    int result = calculate(s);
    cout << result << endl;
}