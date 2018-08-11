#ifndef LINEARLIST_H
#define LINEARLIST_H

template<class T>
class LinearList {
public:
    virtual int Length() = 0;    //���Ա���

    virtual bool getData(int i, T &x) = 0;    //��ȡ�±�Ϊi��Ԫ�ص�����
    virtual bool setData(int i, const T &x) = 0;    //�����±�Ϊi��Ԫ�ص�����

    virtual int Find(const T &x) = 0;    //����ֵΪx��Ԫ�ص��±� �������ڷ���-1
    virtual bool Insert(int i, const T &x) = 0;    //��iλ�ò���һ��Ԫ��
    virtual bool Remove(int i, T &x) = 0;    //ɾ��iλ�õ�Ԫ��

    virtual void Clear() = 0; //������Ա�
    virtual bool isEmpty() = 0;    //���Ա��Ƿ�Ϊ��

    virtual void Output() = 0;    //������Ա�
    virtual T &operator[](int i) = 0;    //����[]����� //����������ɾ��
};


#endif
