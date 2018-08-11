//
// Created by IvanLu on 2017/10/11.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Queue.h"

template<class T>
class LinkedQueue : public Queue<T> {
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

protected:
    LinkNode *rear, *front; //头节点，尾节点
public:
    LinkedQueue() : rear(NULL), front(NULL) {};

    ~LinkedQueue() {
        Clear();
    }

    bool Push(const T &x);//入队

    bool Pop(T &x);//出队

    bool getFront(T &x);//获取队首元素

    void Clear();//清空队列

    bool isEmpty() const {//队列是否空
        return (front == NULL);
    }

    bool isFull() const {//队列是否满
        return false;
    }

    int Size() const;//队列大小

    friend ostream &operator<<(ostream &os, LinkedQueue<T> &q) {    //友元函数，输出队列内容
        os << "Queue Size:" << q.Size() << endl;
        LinkNode *p = q.front;
        int i = 0;
        while (p != NULL) {
            os << i++ << ":" << p->data << endl;
            p = p->next;
        }
        return os;
    }
};

template<class T>
void LinkedQueue<T>::Clear() {  //清空队列
    LinkNode *p;
    while (front != NULL) {
        p = front;
        front = front->next;
        delete p;
    }
}

template<class T>
bool LinkedQueue<T>::Push(const T &x) {
    if (front == NULL) {//若头节点为空，则给头结点赋值
        front = rear = new LinkNode(x);
        if (front == NULL)
            return false;
    } else {
        rear->next = new LinkNode(x);   //插入新节点
        if (rear->next == NULL)
            return false;
        rear = rear->next;  //移动尾节点
    }
    return true;
}

template<class T>
bool LinkedQueue<T>::Pop(T &x) {
    if (isEmpty())//若队列空返回false
        return false;
    LinkNode *p = front;   //获取头结点
    x = front->data;    //发挥数据
    front = front->next;    //头结点出队列
    delete p;
    return true;
}

template<class T>
bool LinkedQueue<T>::getFront(T &x) {
    if (isEmpty())//若队列为空返回false
        return false;
    x = front->data;//返回头结点数据
    return true;
}

template<class T>
int LinkedQueue<T>::Size() const {
    LinkNode *p = front;
    int k = 0;
    while (p != NULL) {
        p = p->next;
        k++;
    }
    return k;
}

#endif //LINKEDQUEUE_H
