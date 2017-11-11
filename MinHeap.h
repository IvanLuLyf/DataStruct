//
// Created by IvanLu on 2017/11/5.
//

#ifndef MINHEAP_H
#define MINHEAP_H

template<class T>
class MinHeap {
public:
    MinHeap(int size = 20);

    MinHeap(T arr[], int n);

    ~MinHeap() { delete[]heap; }

    bool Push(const T &x);

    bool Pop(T &x);

    bool isEmpty() const { return size == 0; }

    bool isFull() const { return size == maxSize; }

    void Clear() { size = 0; }

private:
    T *heap;
    int size;
    int maxSize;

    void siftDown(int start, int m);

    void siftUp(int start);
};

template<class T>
MinHeap<T>::MinHeap(int sz):maxSize(sz) {
    heap = new T[maxSize];
    if (heap == NULL) {
        cerr << "No Enough Memory" << endl;
    }
    size = 0;
}

template<class T>
MinHeap<T>::MinHeap(T arr[], int n):maxSize(n) {
    heap = new T[maxSize];
    if (heap == NULL) {
        cerr << "No Enough Memory" << endl;
    }
    for (int i = 0; i < n; i++)
        heap[i] = arr[i];
    size = n;
    int currentPos = (size - 2) / 2;
    while (currentPos >= 0) {
        siftDown(currentPos, size - 1);
        currentPos--;
    }
}

template<class T>
void MinHeap<T>::siftDown(int start, int m) {
    int i = start, j = 2 * i + 1;
    T temp = heap[i];
    while (j <= m) {
        if (j < m && heap[j] > heap[j + 1])
            j++;
        if (temp <= heap[j])
            break;
        else {
            heap[i] = heap[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    heap[i] = temp;
}

template<class T>
void MinHeap<T>::siftUp(int start) {
    int j = start, i = (j - 1) / 2;
    T temp = heap[j];
    while (j > 0) {
        if (heap[i] <= temp)
            break;
        else {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    heap[j] = temp;
}

template<class T>
bool MinHeap<T>::Push(const T &x) {
    if (&x == NULL) {
        return false;
    }
    if (size == maxSize) {
        return false;
    }
    heap[size] = x;
    siftUp(size);
    size++;
    return true;
}

template<class T>
bool MinHeap<T>::Pop(T &x) {
    if (size == 0) {
        return false;
    }
    x = heap[0];
    heap[0] = heap[size - 1];
    size--;
    siftDown(0, size - 1);
    return true;
}

#endif //MINHEAP_H
