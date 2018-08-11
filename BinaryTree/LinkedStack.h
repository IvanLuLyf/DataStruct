//
// Created by IvanLu on 2017/10/21.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Stack.h"

template<class T>
class LinkedStack : public Stack<T> {
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

    LinkNode *top;  //栈顶节点
public:
    LinkedStack() : top(NULL) {}

    ~LinkedStack() {}

    void Push(const T &x);   //入栈

    bool Pop(T &x); //出栈

    bool getTop(T &x);  ////获取栈顶元素

    void Clear();   //清空栈

    bool isEmpty() const { return top == NULL; }    //栈是否空

    bool isFull() const { return false; }   //栈是否满

    int Size() const;   //栈大小

    friend ostream &operator<<(ostream &os, LinkedStack<T> &s) {    //友元函数，输出栈内容
        os << "Stack Size:" << s.Size() << endl;
        LinkNode *p = s.top;
        int i = 0;
        while (p != NULL) {
            os << i++ << ":" << p->data << endl;
            p = p->next;
        }
        return os;
    }
};

template<class T>
void LinkedStack<T>::Push(const T &x) {
    LinkNode *p = new LinkNode(x, top); //申请节点
    if (p != NULL)  //判断是否空
        top = p;
}

template<class T>
bool LinkedStack<T>::Pop(T &x) {
    if (isEmpty())  //若栈空返回false
        return false;
    LinkNode *p = top;
    top = top->next;    //出栈
    x = p->data;       //取值
    delete p;
    return true;
}

template<class T>
bool LinkedStack<T>::getTop(T &x) {
    if (isEmpty())  //若栈空返回false
        return false;
    x = top->data;  //取值
    return true;
}

template<class T>
void LinkedStack<T>::Clear() {
    LinkNode *p = NULL;
    while (top != NULL) {
        p = top;
        top = top->next;
        delete p;
    }
}

template<class T>
int LinkedStack<T>::Size() const {
    LinkNode *p = top;
    int c = 0;
    while (p != NULL) {
        p = p->next;
        c++;
    }
    return c;
}

#endif //LINKEDQUEUE_H
