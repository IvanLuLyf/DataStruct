#include <iostream>
#include <string>

using namespace std;

#include "SeqStack.h"
#include "LinkedStack.h"
#include "Calculator.h"

void Menu() {
    cout << "Select a Function." << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.GetTop" << endl;
    cout << "4.Output" << endl;
    cout << "0.Exit" << endl;
}

int main() {
    int sel, func;
    int x;
    while (true) {
        cout << "Select a Function." << endl;
        cout << "1.Sequence Stack" << endl;
        cout << "2.Linked Stack" << endl;
        cout << "3.Symmetrical String" << endl;
        cout << "4.Postfix Expression" << endl;
        cout << "0.Exit" << endl;
        cin >> sel;
        if (sel == 1) {
            SeqStack<int> stack;
            while (true) {
                Menu();
                cin >> func;
                switch (func) {
                    case 1:
                        cout << "Input Data X:" << endl;
                        cin >> x;
                        stack.Push(x);
                        break;
                    case 2:
                        if (stack.Pop(x)) {
                            cout << "Pop Data is " << x << endl;
                        } else {
                            cout << "Stack is Empty" << endl;
                        }
                        break;
                    case 3:
                        if (stack.getTop(x)) {
                            cout << "Top Data is " << x << endl;
                        } else {
                            cout << "Stack is Empty" << endl;
                        }
                        break;
                    case 4:
                        cout << stack << endl;
                        break;
                }
                if (func == 0) {
                    break;
                }
            }
        } else if (sel == 2) {
            LinkedStack<int> stack;
            while (true) {
                Menu();
                cin >> func;
                switch (func) {
                    case 1:
                        cout << "Input Data X:" << endl;
                        cin >> x;
                        stack.Push(x);
                        break;
                    case 2:
                        if (stack.Pop(x)) {
                            cout << "Pop Data is " << x << endl;
                        } else {
                            cout << "Stack is Empty" << endl;
                        }
                        break;
                    case 3:
                        if (stack.getTop(x)) {
                            cout << "Top Data is " << x << endl;
                        } else {
                            cout << "Stack is Empty" << endl;
                        }
                        break;
                    case 4:
                        cout << stack << endl;
                        break;
                }
                if (func == 0) {
                    break;
                }
            }
        } else if (sel == 3) {
            string s;
            char c;
            bool flag = true;
            SeqStack<char> stack;
            cout << "Input a String" << endl;
            cin >> s;
            for (int i = 0; i < s.length(); i++) {
                stack.Push(s[i]);
            }
            for (int i = 0; i < s.length(); i++) {
                stack.Pop(c);
                if (c != s[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "String is Symmetrical" << endl;
            } else {
                cout << "String is not Symmetrical" << endl;
            }
        } else if (sel == 4) {
            Calculator calculator;
            string expresstion;
            cout << "Input expression:" << endl;
            cin >> expresstion;
            cout << "Postfix Exp:" << endl;
            cout << calculator.toPostfix(expresstion) << endl;
            cout << expresstion << "=" << calculator.Eval(expresstion) << endl;
        } else if (sel == 0) {
            break;
        }
    }
    return 0;
}