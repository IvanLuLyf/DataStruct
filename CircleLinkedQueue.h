//
// Created by IvanLu on 2017/10/21.
//

#ifndef CIRCLELINKEDQUEUE_H
#define CIRCLELINKEDQUEUE_H

#include "Queue.h"

template<class T>
class CircleLinkedQueue : public Queue<T> {
private:
    struct LinkNode {
        T data;
        LinkNode *next;

        LinkNode(LinkNode *ptr = NULL) {
            next = ptr;
        }

        LinkNode(const T &x, LinkNode *ptr = NULL) {
            data = x;
            next = ptr;
        }
    };

protected:
    LinkNode *rear;
public:
    CircleLinkedQueue() : rear(NULL) {}

    ~CircleLinkedQueue() { Clear(); }

    bool Push(const T &x);//入队

    bool Pop(T &x);//出队

    bool getFront(T &x);//获取队首元素

    void Clear();//清空队列

    bool isEmpty() const {//队列是否空
        return (rear == NULL);
    }

    bool isFull() const {//队列是否满
        return false;
    }

    int Size() const;//队列大小

    friend ostream &operator<<(ostream &os, CircleLinkedQueue<T> &q) {  //友元函数，输出队列内容
        os << "Queue Size:" << q.Size() << endl;
        if (q.isEmpty()) {
            return os;
        }
        LinkNode *p = q.rear->next;
        int i = 0;
        while (p != q.rear) {
            os << i++ << ":" << p->data << endl;
            p = p->next;
        }
        os << i++ << ":" << p->data << endl;
        return os;
    }
};

template<class T>
bool CircleLinkedQueue<T>::Push(const T &x) {
    if (rear == NULL) { //若尾节点为空，则给尾节点赋值
        rear = new LinkNode(x);
        if (rear == NULL)
            return false;
        rear->next = rear;  //将next设为本身
    } else {//其他情况
        LinkNode *p = new LinkNode(x, rear->next);  //申请内存
        if (p == NULL) {
            return false;
        }
        rear->next = p; //插入节点
        rear = rear->next;  //移动尾节点
    }
    return true;
}

template<class T>
bool CircleLinkedQueue<T>::Pop(T &x) {
    if (isEmpty())  //若队列空返回false
        return false;
    if (rear == rear->next) {//若只剩一个节点
        x = rear->data;//返回数据
        delete rear;
        rear = NULL;//标记为空
        return true;
    }
    LinkNode *p = rear->next;   //获取头结点
    x = p->data;   //返回数据
    rear->next = p->next; //头节点出队列
    delete p;
    return true;
}

template<class T>
bool CircleLinkedQueue<T>::getFront(T &x) {
    if (isEmpty())  //若队列为空返回false
        return false;
    x = rear->next->data;   //返回头结点数据
    return true;
}

template<class T>
void CircleLinkedQueue<T>::Clear() {    //清空队列
    if (isEmpty())  //若队列空则不需要清理
        return;
    LinkNode *p = rear->next, *q = NULL;
    while (p != rear) {
        q = p;
        p = p->next;
        delete q;
    }
    delete rear;    //处理尾节点
    rear = NULL;
}

template<class T>
int CircleLinkedQueue<T>::Size() const {
    if (isEmpty()) {
        return 0;
    }
    LinkNode *p = rear->next;
    int k = 0;
    while (p != rear) {
        p = p->next;
        k++;
    }
    return k + 1;
}

#endif //CIRCLELINKEDQUEUE_H
