#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ispar(string exp) {
    stack<char> s;
    for (char c : exp) {
        if (c=='('||c=='{'||c=='[') {s.push(c);}
        else{
            if (s.empty()) {return false;}
            char t = s.top();
            if ((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[')){return false;}
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter the exp: ";
    cin >> exp;
    if (ispar(exp)) {
        cout << "balanced" << endl;
    } else {
        cout << "not balanced" << endl;
    }
    return 0;
}
