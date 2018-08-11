#ifndef LINKLIST_H
#define LINKLIST_H

#include "LinearList.h"

template<class T>
class LinkedList : public LinearList<T> {
private:
    //链表节点
    struct LinkNode {
        T data; //数据域
        LinkNode *next; //指针域
        LinkNode(LinkNode *ptr = NULL) {
            next = ptr;
        }

        LinkNode(const T &x, LinkNode *ptr = NULL) {
            data = x;
            next = ptr;
        }
    };

    //链表长度
    int size;
protected:
    LinkNode *head;    //链表头结点
    //获取下标为i的链表节点
    LinkNode *Locate(int i) {
        if (i < -1) {
            return NULL;
        } else if (i == -1) {
            return head;
        } else {
            LinkNode *cur = head->next;
            int c = 0;
            while (cur != NULL && c < i) {
                cur = cur->next;
                c++;
            }
            return cur;
        }
    }

public:
    //构造函数
    LinkedList() {
        head = new LinkNode;
        size = 0;
    }

    //析构函数，清理内存数据
    ~LinkedList() {
        Clear();
        delete head;
    }

    //链表长度
    int Length() {
        return size;
    }

    //获取下标对应元素
    bool getData(int i, T &x) {
        LinkNode *cur = Locate(i);
        if (cur == NULL) {
            return false;
        } else {
            x = cur->data;
            return true;
        }
    }

    //设置下标对应元素的值
    bool setData(int i, const T &x) {
        LinkNode *cur = Locate(i);
        if (cur == NULL) {
            return false;
        } else {
            cur->data = x;
            return true;
        }
    }

    //查找顺序表是否存在元素，存在返回下标，不存在返回-1
    int Find(const T &x) {
        int i = 0;
        LinkNode *cur = head->next;
        while (cur != NULL) {
            if (cur->data == x) {
                return i;
            }
            i++;
            cur = cur->next;
        }
        return -1;
    }

    //在下标i位置插入一个元素，成功返回true，不成功返回false
    bool Insert(int i, const T &x) {
        LinkNode *cur = Locate(i - 1);  //查找插入位置的前继结点
        if (cur == NULL) {  //不存在则无法插入
            return false;
        } else {    //存在则插入节点
            LinkNode *node = new LinkNode(x);
            if (node == NULL) {
                return false;
            } else {
                node->next = cur->next;
                cur->next = node;
                size++;
                return true;
            }
        }
    }

    //删除下标i位置的元素，并通过引用获取，成功返回true，不成功返回false
    bool Remove(int i, T &x) {
        LinkNode *cur = Locate(i - 1);  //查找插入位置的前继结点
        if (cur == NULL || cur->next == NULL) { //如果不存在前继节点或不存在被删除节点则无法删除
            return false;
        } else {
            LinkNode *del = cur->next;
            cur->next = del->next;  //从链表删除节点
            x = del->data;     //取值
            delete del;     //清理内存
            size--;
            return true;
        }
    }

    //清空链表
    void Clear() {
        LinkNode *cur;
        while (head->next != NULL) {
            cur = head->next;
            head->next = cur->next;
            delete cur;
        }
    }

    //判断链表是否为空
    bool isEmpty() {
        return head->next == NULL;
    }

    //输出链表元素
    void Output() {
        LinkNode *cur = head->next;
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    //重载[]运算符 //看不懂可以删掉
    T &operator[](int i) {
        LinkNode *cur = Locate(i);
        if (cur != NULL) {
            return cur->data;
        } else {
            throw "Invalid Position";
        }
    }
};


#endif
