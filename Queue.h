//
// Created by IvanLu on 2017/10/11.
//

#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue {
public:
    virtual bool Push(const T &x) = 0;  //入队

    virtual bool Pop(T &x) = 0; //出队

    virtual bool getFront(T &x) = 0;    //获取队首元素

    virtual void Clear() = 0;   //清空队列

    virtual bool isEmpty() const = 0;   //队列是否空

    virtual bool isFull() const = 0;    //队列是否满

    virtual int Size() const = 0;   //队列大小
};

#endif //QUEUE_H
