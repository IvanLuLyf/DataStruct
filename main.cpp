#include <iostream>

using namespace std;

#include "HuffmanTree.h"

void Menu() {
    cout << "1.Build Huffman Tree" << endl;
    cout << "2.Encode Message" << endl;
    cout << "3.Decode Message" << endl;
    cout << "4.Clear" << endl;
    cout << "0.Exit" << endl;
}

int main() {
    int sel;
    HuffmanTree tree;
    string message;
    while (true) {
        Menu();
        cin >> sel;
        cin.clear();
        fflush(stdin);
        switch (sel) {
            case 1:
                getline(cin, message, '\n');
                tree.buildTree(message);
                break;
            case 2:
                getline(cin, message, '\n');
                cout << tree.Encode(message) << endl;
                break;
            case 3:
                getline(cin, message, '\n');
                cout << tree.Decode(message) << endl;
                break;
            case 4:
                tree.clearTree();
                break;
        }
        if (sel == 0) {
            break;
        }
    }
    return 0;
}