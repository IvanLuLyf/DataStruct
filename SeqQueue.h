//
// Created by IvanLu on 2017/10/11.
//

#ifndef SEQQUEUE_H
#define SEQQUEUE_H

#include "Queue.h"

template<class T>
class SeqQueue : public Queue<T> {
protected:
    int rear, front;    //队首，队尾下标
    T *data;    //数据域
    int maxSize;    //队列最大容量
public:
    SeqQueue(int sz = 10);

    ~SeqQueue() {
        delete[] data;
    }

    bool Push(const T &x);  //入队

    bool Pop(T &x); //出队

    bool getFront(T &x);    //获取队首元素

    void Clear() {  //清空队列
        front = rear = 0;
    }

    bool isEmpty() const {  //队列是否空
        return (front == rear);
    }

    bool isFull() const {   //队列是否满
        return ((rear + 1) % maxSize == front);
    }

    int Size() const {  //队列大小
        return (rear - front + maxSize) % maxSize;
    }

    friend ostream &operator<<(ostream &os, SeqQueue<T> &q) {   //友元函数，输出队列内容
        os << "Queue Size:" << q.Size() << endl;
        os << "front=" << q.front << ",rear=" << q.rear << endl;
        for (int i = q.front; i != q.rear; i = (i + 1) % q.maxSize)
            os << i << ":" << q.data[i] << endl;
        return os;
    }
};

template<class T>
SeqQueue<T>::SeqQueue(int sz) :front(0), rear(0), maxSize(sz) {
    data = new T[maxSize];  //申请内存
    if (data == NULL)
        cerr << "No Enough Memory." << endl;
}

template<class T>
bool SeqQueue<T>::Push(const T &x) {
    if (isFull())  //队列满无法插入
        return false;
    data[rear] = x; //插入元素
    rear = (rear + 1) % maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::Pop(T &x) {
    if (isEmpty())  //队列空返回false
        return false;
    x = data[front];    //取值
    front = (front + 1) % maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::getFront(T &x) {
    if (isEmpty())  //队列空返回false
        return false;
    x = data[front];    //取值
    return true;
}

#endif //SEQQUEUE_H
