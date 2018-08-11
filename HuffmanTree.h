//
// Created by IvanLu on 2017/11/5.
//

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <map>
#include "MinHeap.h"

class HuffmanTree {
    //树节点
    struct Node {
        float weight;   //权值
        char data;      //数据
        char code;      //编码0或1
        Node *left, *right, *parent;    //左子树 右子树 父节点

        Node() : left(NULL), right(NULL), parent(NULL) {}

        Node(float w, Node *l = NULL, Node *r = NULL, Node *p = NULL)
                : weight(w), left(l), right(r), parent(p) {}

        Node(float w, char x, Node *l = NULL, Node *r = NULL, Node *p = NULL)
                : weight(w), data(x), left(l), right(r), parent(p) {}
    };

    //存储最小堆中节点
    struct DataNode {
        Node *ptr;  //树节点指针

        bool operator<=(DataNode &R) { return ptr->weight <= R.ptr->weight; }

        bool operator>(DataNode &R) { return ptr->weight > R.ptr->weight; }
    };

public:
    HuffmanTree(int sz = 127) : heap(sz), maxSize(sz), size(0) {}

    ~HuffmanTree() { deleteTree(root); }

    void buildTree(std::string message);

    void clearTree() { deleteTree(root); }

    std::string Encode(std::string message);

    std::string Decode(std::string code);

protected:
    Node *root; //根节点

    std::map<char, string> mapper;  //字符编码映射

    MinHeap<DataNode> heap;     //最小堆

    int maxSize;    //堆大小

    int size;   //编码字符数量

    void deleteTree(Node *t);

    void mergeTree(Node *l, Node *r, Node *&p);

    void markCode(Node *p, char code);
};

std::string HuffmanTree::Encode(std::string message) {
    string result = "";
    for (int i = 0; i < message.length(); i++) {
        result += mapper[message[i]];
    }
    return result;
}

std::string HuffmanTree::Decode(std::string code) {
    Node *p = root;
    if (root == NULL) return ""; //根节点为空
    std::string result = "";
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == '0') {   //为0进左子树
            p = p->left;
        }
        else if (code[i] == '1') {    //为1进右子树
            p = p->right;
        }
        if (p->left == NULL && p->right == NULL) {  //若节点是叶子节点则获取编码字符
            result += p->data;
            p = root;
        }
    }
    return result;
}

//删除子树
void HuffmanTree::deleteTree(HuffmanTree::Node *t) {
    if (t != NULL) {
        deleteTree(t->left);
        deleteTree(t->right);
        delete (t);
    }
}

//合并子树
void HuffmanTree::mergeTree(HuffmanTree::Node *l, HuffmanTree::Node *r, HuffmanTree::Node *&p) {
    p = new Node;
    p->parent = NULL;
    p->left = l;
    p->right = r;
    p->weight = l->weight + r->weight;
    l->parent = r->parent = p;
}

//标记叶子节点的编码
void HuffmanTree::markCode(HuffmanTree::Node *p, char code) {
    p->code = code;
    if (p->left != NULL && p->right != NULL) {  //节点不是叶子节点，递归进入左右子树
        markCode(p->left, '0');
        markCode(p->right, '1');
    }
    else {    //若是叶子节点
        mapper[p->data] = "";
        Node *q = p;
        while (q != root) {
            mapper[p->data] = q->code + mapper[p->data];    //拼接编码
            q = q->parent;
        }
    }
}

//建立Huffman树
void HuffmanTree::buildTree(std::string message) {
    int *weights = new int[maxSize];
    Node *parent = NULL;
    DataNode left, right, temp;
    for (int i = 0; i < maxSize; i++) {
        weights[i] = 0;
    }
    for (int i = 0; i < message.length(); i++) {    //统计字符出现频率
        weights[message[i]]++;
    }
    for (int i = 0; i < maxSize; i++) {
        if (weights[i] != 0) {
            temp.ptr = new Node(weights[i], (char)i);  //构造初始节点
            heap.Push(temp);
            size++;     //统计编码字符数量
        }
    }
    if (size < 2)return;    //数据量太小
    for (int i = 0; i < size - 1; i++) {
        heap.Pop(left); //弹出权值最小的两个节点
        heap.Pop(right);
        mergeTree(left.ptr, right.ptr, parent); //合并子树
        temp.ptr = parent;
        heap.Push(temp);    //放回堆中
    }
    root = parent;  //根节点
    markCode(root, 0);  //标记节点
}


#endif //HUFFMANTREE_H
