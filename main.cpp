#include <iostream>

using namespace std;

#include "Queue.h"
#include "SeqQueue.h"
#include "LinkedQueue.h"
#include "CircleLinkedQueue.h"

void Menu() {
    cout << "Select a Function." << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.GetFront" << endl;
    cout << "4.Output" << endl;
    cout << "0.Exit" << endl;
}

int main() {
    int sel, func;
    int x;
    while (true) {
        cout << "Select a Function." << endl;
        cout << "1.Sequence Queue" << endl;
        cout << "2.Linked Queue" << endl;
        cout << "3.Circle Linked Queue" << endl;
        cout << "0.Exit" << endl;
        cin >> sel;
        if (sel == 1) {
            SeqQueue<int> stack;
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
                            cout << "Queue is Empty" << endl;
                        }
                        break;
                    case 3:
                        if (stack.getFront(x)) {
                            cout << "Front Data is " << x << endl;
                        } else {
                            cout << "Queue is Empty" << endl;
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
            LinkedQueue<int> stack;
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
                            cout << "Queue is Empty" << endl;
                        }
                        break;
                    case 3:
                        if (stack.getFront(x)) {
                            cout << "Front Data is " << x << endl;
                        } else {
                            cout << "Queue is Empty" << endl;
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
            CircleLinkedQueue<int> stack;
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
                            cout << "Queue is Empty" << endl;
                        }
                        break;
                    case 3:
                        if (stack.getFront(x)) {
                            cout << "Front Data is " << x << endl;
                        } else {
                            cout << "Queue is Empty" << endl;
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
        } else if (sel == 0) {
            break;
        }
    }
    return 0;
}