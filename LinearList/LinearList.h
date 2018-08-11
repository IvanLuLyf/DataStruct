#ifndef LINEARLIST_H
#define LINEARLIST_H

template<class T>
class LinearList {
public:
    virtual int Length() = 0;    //线性表长度

    virtual bool getData(int i, T &x) = 0;    //获取下标为i的元素的数据
    virtual bool setData(int i, const T &x) = 0;    //设置下标为i的元素的数据

    virtual int Find(const T &x) = 0;    //返回值为x的元素的下标 ，不存在返回-1
    virtual bool Insert(int i, const T &x) = 0;    //在i位置插入一个元素
    virtual bool Remove(int i, T &x) = 0;    //删除i位置的元素

    virtual void Clear() = 0; //清空线性表
    virtual bool isEmpty() = 0;    //线性表是否为空

    virtual void Output() = 0;    //输出线性表
    virtual T &operator[](int i) = 0;    //重载[]运算符 //看不懂可以删掉
};


#endif
