#ifndef SEQLIST_H
#define SEQLIST_H

#include "LinearList.h"

template<class T>
class SeqList : public LinearList<T> {
protected:
    T *data;   //数组
    int maxSize;    //数组最大容量
    int size;   //当前元素个数
public:
    //默认构造函数
    //sz数组容量，默认为50
    SeqList(int sz = 50) {
        if (sz > 0) {
            maxSize = sz;
            data = new T[maxSize];  //申请内存
            size = 0;
            if (data == NULL) {     //内存不足
                cerr << "No Enough Memory." << endl;
            }
        }
    }

    //拷贝构造函数
    SeqList(const SeqList<T> &L) {
        maxSize = L.maxSize;
        size = L.size;
        if (data != NULL) {
            delete[] data;
        }
        data = new T[maxSize];
        if (data == NULL) {
            return;
        }
        for (int i = 0; i < size; i++) {
            data[i] = L.data[i];
        }
    }

    //析构函数，清理数组
    ~SeqList() {
        delete[]data;
    }

    //顺序表长度
    int Length() {
        return size;
    }

    //获取下标对应元素
    bool getData(int i, T &x) {
        if (i >= 0 && i < size) {   //判断下标是否合法
            x = data[i];
            return true;
        } else {
            return false;
        }
    }

    //设置下标对应元素的值
    bool setData(int i, const T &x) {
        if (i >= 0 && i < size) {   //判断下标是否合法
            data[i] = x;
            return true;
        } else {
            return false;
        }
    }

    //查找顺序表是否存在元素，存在返回下标，不存在返回-1
    int Find(const T &x) {
        for (int i = 0; i < size; i++) {
            if (data[i] == x) {
                return i;
            }
        }
        return -1;
    }

    //在下标i位置插入一个元素，成功返回true，不成功返回false
    bool Insert(int i, const T &x) {
        int j;
        if (i < 0 || i > size) {    //不合法下标位置
            cerr << "Invalid Postion" << endl;
            return false;
        } else if (size > maxSize) {    //超过数组最大容量
            cerr << "Overflow" << endl;
            return false;
        } else {    //可插入
            for (j = size; j >= i; j--) {   //移动i位置之后的元素
                data[j + 1] = data[j];
            }
            data[i] = x;    //赋值
            size++;
            return true;
        }
    }

    //删除下标i位置的元素，并通过引用获取，成功返回true，不成功返回false
    bool Remove(int i, T &x) {
        int j;
        if (i < 0 || i > size - 1) {   //不合法下标位置
            cerr << "Invalid Postion" << endl;
            return false;
        } else {
            //可删除
            x = data[i];    //取值
            for (j = i; j < size; j++) { //移动i位置之后的元素
                data[j] = data[j + 1];
            }
            size--;
            return true;
        }
    }

    //清空顺序表
    void Clear() {
        size = 0;
    }

    //判断顺序表是否为空
    bool isEmpty() {
        return size == 0;
    }

    //输出顺序表内容
    void Output() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    //重载[]运算符//看不懂可以删了这个函数
    //通过[]取得i下标元素的引用
    T &operator[](int i) {
        if (i >= 0 && i < size) {
            return data[i];
        } else {
            throw "Invalid Position";
        }
    }

    //重载+运算符//看不懂可以删了这个函数
    //合并两个顺序表
    SeqList operator+(SeqList &l) {
        SeqList r;
        r.size = size + l.size;
        r.maxSize = maxSize + l.maxSize;
        r.data = new T[r.maxSize];
        for (int i = 0; i < size; i++) {
            r.data[i] = data[i];
        }
        for (int i = 0; i < l.size; i++) {
            r.data[size + i] = l.data[i];
        }
        return r;
    }

    //重载赋值运算
    SeqList &operator=(const SeqList &L) {
        if (this != &L) {
            if (data != NULL) {
                delete[] data;
            }
            maxSize = L.maxSize;
            size = L.size;

            data = new T[maxSize];
            for (int i = 0; i < size; i++) {
                data[i] = L.data[i];
            }

        }
        return *this;
    }

private:
    //调整顺序表容量
    void Resize(int sz) {
        if (sz <= 0) {
            return;
        }
        if (maxSize != sz) {
            T *arr = new T[sz];
            if (arr == NULL) {
                return;
            }
            int n = size;
            T *src = data;
            T *des = arr;
            while (n--) {
                *des++ = *src++;
            }
            delete[] data;
            data = arr;
            maxSize = sz;
        }
    }
};


#endif
