#include <iostream>

using namespace std;

#include "ThreadTree.h"

template<class T>
void visit(T x) {
    cout << x << " ";
}

void menu() {
    cout << "1.Init Tree" << endl;
    cout << "2.PreOrder" << endl;
    cout << "3.InOrder" << endl;
    cout << "4.PostOrder" << endl;
    cout << "5.Insert" << endl;
    cout << "0.Exit" << endl;
}

int main() {
    int sel, pos = 0;
    char c;
    ThreadTree<char> tree('#'); //建立对象
    ThreadNode<char> *p = NULL, *item = NULL;
    while (true) {
        menu();
        cin >> sel;
        switch (sel) {
            case 1:
                if (tree.isEmpty()) {
                    cin >> tree;
                    tree.createInThread();
                } else
                    cout << "Binary Tree Already Had Elements" << endl;
                break;
            case 2:
                tree.PreOrder(visit);
                cout << endl;
                break;
            case 3:
                tree.InOrder(visit);
                cout << endl;
                break;
            case 4:
                tree.PostOrder(visit);
                cout << endl;
                break;
            case 5:
                cout << "Find what?" << endl;
                cin >> c;
                p = tree.Search(c);
                if (p != NULL) {
                    cout << "Insert what?" << endl;
                    cin >> c;
                    cout << "Insert position(0.Left,1.Right)" << endl;
                    cin >> pos;
                    item = new ThreadNode<char>(c);
                    tree.Insert(p, item, (pos == 0));
                } else {
                    cout << "Not Found." << endl;
                }
                break;
        }
        if (sel == 0) {
            break;
        }
    }
    return 0;
}
