#include <iostream>
#include <string>

using namespace std;

#include "SeqList.h"
#include "LinkedList.h"

void Menu() {
    cout << "选择一个功能." << endl;
    cout << "1.插入" << endl;
    cout << "2.删除" << endl;
    cout << "3.获取" << endl;
    cout << "4.修改" << endl;
    cout << "5.查找" << endl;
    cout << "6.输出" << endl;
    cout << "0.退出" << endl;
}

int main() {
    int sel, func;
    int x, i, pos;
    while (true) {
        cout << "Select a Function." << endl;
        cout << "1.Sequence List" << endl;
        cout << "2.Linked List" << endl;
        cout << "0.Exit" << endl;

        cin >> sel;
        if (sel == 1) {
            SeqList<int> list;
            while (true) {
                Menu();
                cin >> func;
                switch (func) {
                    case 1:
                        cout << "输入下标i和数据x:" << endl;
                        cin >> i >> x;
                        if (list.Insert(i, x) == true) {
                            cout << "插入成功." << endl;
                        } else {
                            cout << "插入失败." << endl;
                        }
                        break;
                    case 2:
                        cout << "输入下标i:" << endl;
                        cin >> i;
                        if (list.Remove(i, x) == true) {
                            cout << "删除成功.被删除元素为" << x << endl;
                        } else {
                            cout << "删除失败." << endl;
                        }
                        break;
                    case 3:
                        cout << "输入下标i:" << endl;
                        cin >> i;
                        if (list.getData(i, x) == true) {
                            cout << "获取成功.数据为" << x << endl;
                        } else {
                            cout << "获取失败." << endl;
                        }
                        break;
                    case 4:
                        cout << "输入下标i和数据x:" << endl;
                        cin >> i >> x;
                        if (list.setData(i, x) == true) {
                            cout << "修改成功" << endl;
                        } else {
                            cout << "修改失败." << endl;
                        }
                        break;
                    case 5:
                        cout << "输入待查找数据x:" << endl;
                        cin >> x;
                        pos = list.Find(x);
                        if (pos > -1) {
                            cout << x << "在" << pos << "号位置" << endl;
                        } else {
                            cout << "未找到." << endl;
                        }
                        break;
                    case 6:
                        list.Output();
                        break;
                }
                if (func == 0) {
                    break;
                }
            }
        } else if (sel == 2) {
            LinkedList<int> list;
            while (true) {
                Menu();
                cin >> func;
                switch (func) {
                    case 1:
                        cout << "Input Position i and Data x:" << endl;
                        cin >> i >> x;
                        if (list.Insert(i, x) == true) {
                            cout << "Insert Success." << endl;
                        } else {
                            cout << "Insert Fail." << endl;
                        }
                        break;
                    case 2:
                        cout << "Input Position i:" << endl;
                        cin >> i;
                        if (list.Remove(i, x) == true) {
                            cout << "Remove Success.Data is " << x << endl;
                        } else {
                            cout << "Remove Fail." << endl;
                        }
                        break;
                    case 3:
                        cout << "Input Position i:" << endl;
                        cin >> i;
                        if (list.getData(i, x) == true) {
                            cout << "Get Success.Data is " << x << endl;
                        } else {
                            cout << "Get Fail." << endl;
                        }
                        break;
                    case 4:
                        cout << "Input Position i and Data x:" << endl;
                        cin >> i >> x;
                        if (list.setData(i, x) == true) {
                            cout << "Set Success." << endl;
                        } else {
                            cout << "Set Fail." << endl;
                        }
                        break;
                    case 5:
                        cout << "Input Data x:" << endl;
                        cin >> x;
                        pos = list.Find(x);
                        if (pos > -1) {
                            cout << x << " in postion " << pos << endl;
                        } else {
                            cout << "Not Found." << endl;
                        }
                        break;
                    case 6:
                        list.Output();
                        break;
                }
                if (func == 0) {
                    break;
                }
            }
        }  else if (sel == 0) {
            break;
        }
    }
    return 0;
}
