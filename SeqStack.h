//
// Created by IvanLu on 2017/10/21.
//

#ifndef SEQSTACK_H
#define SEQSTACK_H

#include "Stack.h"

template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);

    ~SeqStack() { delete[] data; }

    void Push(const T &x);  //入栈

    bool Pop(T &x);     //出栈

    bool getTop(T &x);  //获取栈顶元素

    void Clear() { top = -1; }  //清空栈

    bool isEmpty() const { return top == -1; }  //栈是否空

    bool isFull() const { return top == maxSize - 1; }  //栈是否满

    int Size() const { return top + 1; }    //栈大小

    friend ostream &operator<<(ostream &os, SeqStack<T> &s){    //友元函数，输出栈内容
        os << "Stack Size:" << s.top+1 << endl;
        os << "Top=" << s.top << endl;
        for (int i = 0; i <= s.top; i++) {
            os << i << ":" << s.data[i] << endl;
        }
        return os;
    }

private:
    const int increment = 20;
    T *data;    //数据域
    int top;    //栈顶下标
    int maxSize;    //栈最大容量

    void overflowProcess();
};

template<class T>
SeqStack<T>::SeqStack(int sz):top(-1), maxSize(sz) {
    data = new T[maxSize];  //申请内存
    if (data == NULL) {
        cerr << "No Enough Memory." << endl;
    }
}

template<class T>
void SeqStack<T>::Push(const T &x) {
    if (isFull()) { //若栈满，扩容
        overflowProcess();
    }
    data[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T &x) {
    if (isEmpty()) { //若栈空返回false
        return false;
    }
    x = data[top--]; //取值
    return true;
}

template<class T>
bool SeqStack<T>::getTop(T &x) {
    if (isEmpty()) {    //若栈空返回false
        return false;
    }
    x = data[top];  //取值
    return true;
}

template<class T>
void SeqStack<T>::overflowProcess() {
    T *tmp = new T[maxSize + increment];    //申请新空间
    if (tmp == NULL) {
        cerr << "No Enough Memory." << endl;
        return;
    }
    for (int i = 0; i <= top; i++) { //赋值数据
        tmp[i] = data[i];
    }
    maxSize += increment;
    delete[]data;   //清理旧空间
    data = tmp;
}

#endif //SEQSTACK_H
