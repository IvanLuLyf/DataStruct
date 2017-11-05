#include <iostream>
using namespace std;

#include "BinaryTree.h"

template <class T>
void visit(T data){
    cout << data << " ";
}

void menu(){
    cout << "1.Init Tree" << endl;
    cout << "2.PreOrder" << endl;
    cout << "3.InOrder" << endl;
    cout << "4.PostOrder" << endl;
    cout << "5.PreOrder(Non Recursive)" << endl;
    cout << "6.InOrder(Non Recursive)" << endl;
    cout << "7.PostOrder(Non Recursive)" << endl;
    cout << "8.LevelOrder(Non Recursive)" << endl;
    cout << "9.Size" << endl;
    cout << "10.Height" << endl;
    cout << "0.Exit" << endl;
}

int main() {
    int sel,func;
    while(true) {
        cout << "1.Binary Tree" << endl;
        cout << "0.Exit" << endl;
        cin >> func;
        if(func == 0){
            break;
        }else if(func == 1){
            BinaryTree<char> binaryTree('#');
            while(true){
                menu();
                cin >> sel;
                switch (sel){
                    case 1:
                        if(binaryTree.isEmpty())
                            cin >> binaryTree;
                        else
                            cout << "Binary Tree Already Had Elements" << endl;
                        break;
                    case 2:
                        binaryTree.preOrder(visit);
                        cout << endl;
                        break;
                    case 3:
                        binaryTree.inOrder(visit);
                        cout << endl;
                        break;
                    case 4:
                        binaryTree.postOrder(visit);
                        cout << endl;
                        break;
                    case 5:
                        binaryTree.PreOrder(visit);
                        cout << endl;
                        break;
                    case 6:
                        binaryTree.InOrder(visit);
                        cout << endl;
                        break;
                    case 7:
                        binaryTree.PostOrder(visit);
                        cout << endl;
                        break;
                    case 8:
                        binaryTree.LevelOrder(visit);
                        cout << endl;
                        break;
                    case 9:
                        cout << "Binary Tree Size: " << binaryTree.Size() << endl;
                        break;
                    case 10:
                        cout << "Binary Tree Height: " << binaryTree.Height() << endl;
                        break;
                }
                if(sel == 0)
                    break;
            }
        }
    }
    return 0;
}