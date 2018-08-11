//
// Created by IvanLu on 2017/10/21.
//

#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
public:
    virtual void Push(const T &x) = 0;  //入栈

    virtual bool Pop(T &x) = 0;     //出栈

    virtual bool getTop(T &x) = 0;  //获取栈顶元素

    virtual void Clear() = 0;   //清空栈

    virtual bool isEmpty() const = 0;   //栈是否空

    virtual bool isFull() const = 0;    //栈是否满

    virtual int Size() const = 0;   //栈大小
};

#endif //STACK_H
