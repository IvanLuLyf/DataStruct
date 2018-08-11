//
// Created by IvanLu on 2017/10/22.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "LinkedStack.h"
#include "LinkedQueue.h"

template<class T>
class BinaryTree {
private:
    //树节点
    struct Node {
        T data;     //数据域
        Node *left, *right;     //左右子树

        Node() : left(NULL), right(NULL) {}

        Node(T x, Node *l = NULL, Node *r = NULL) : data(x), left(NULL), right(NULL) {}
    };

    //后序遍历辅助节点
    struct pNode {
        Node *ptr;
        enum tag {
            L, R
        } tag;

        pNode(Node *N = NULL) : ptr(N), tag(L) {}
    };

public:

    BinaryTree() : root(NULL) {}

    BinaryTree(T v) : root(NULL), EndValue(v) {}

    BinaryTree(const BinaryTree<T> &tree);

    ~BinaryTree() { Destory(root); }

    bool isEmpty() { return root == NULL; }     //树是否为空

    int Height() { return Height(root); }       //树高度

    int Size() { return Size(root); }       //树元素个数

    void preOrder(void(*v)(T x)) { preOrder(root, v); }     //前序遍历

    void inOrder(void(*v)(T x)) { inOrder(root, v); }       //中序遍历

    void postOrder(void(*v)(T x)) { postOrder(root, v); }   //后序遍历

    void PreOrder(void(*v)(T x));   //前序遍历(非递归)

    void InOrder(void(*v)(T x));    //中序遍历(非递归)

    void PostOrder(void(*v)(T x));  //后序遍历(非递归)

    void LevelOrder(void(*v)(T x)); //层序遍历(非递归)

    friend istream &operator>>(istream &in, BinaryTree<T> &Tree) {    //输入函数
        Tree.CreateTree(in, Tree.root);
        return in;
    }

    friend ostream &operator<<(ostream &out, BinaryTree<T> &Tree) {   //输出函数
        out << "Binary Preorder:" << endl;
        Tree.Traverse(Tree.root, out);
        out << endl;
        return out;
    }

protected:
    Node *root; //根节点
    T EndValue; //终结符

    void CreateTree(istream &in, Node *&sub);   //建立树

    void Destory(Node *sub);    //清理树

    int Height(Node *sub) const;    //递归获取子树高度

    int Size(Node *sub) const;      //递归获取子树元素个数

    void Traverse(Node *sub, ostream &out);     //递归遍历树

    void preOrder(Node *sub, void(*v)(T x));    //递归前序遍历

    void inOrder(Node *sub, void(*v)(T x));     //递归中序遍历

    void postOrder(Node *sub, void(*v)(T x));   //递归后序遍历

    Node *Copy(Node *src) {     //递归复制函数
        if (src == NULL) {
            return NULL;
        }
        Node *tmp = new Node;
        tmp->data = src->data;
        tmp->left = Copy(src->left);
        tmp->right = Copy(src->right);
        return tmp;
    }

};

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree) {  //复制构造函数
    root = Copy(tree.root);
}

template<class T>
void BinaryTree<T>::CreateTree(istream &in, Node *&sub) {   //递归，前序，构造树
    T item;
    if (!in.eof()) {
        in >> item;
        if (item != EndValue) {
            sub = new Node(item);
            if (sub == NULL) {
                cerr << "No Enough Memory." << endl;
                return;
            }
            CreateTree(in, sub->left);
            CreateTree(in, sub->right);
        }
    }
}

template<class T>
void BinaryTree<T>::Destory(Node *sub) {    //递归释放树内存
    if (sub != NULL) {
        Destory(sub->left);
        Destory(sub->right);
        delete (sub);
    }
}

template<class T>
int BinaryTree<T>::Height(Node *sub) const {    //递归计算树高度，取左右子树最大高度
    if (sub == NULL) {
        return 0;
    } else {
        int i = Height(sub->left);
        int j = Height(sub->right);
        return (i < j) ? j + 1 : i + 1;
    }
}

template<class T>
int BinaryTree<T>::Size(Node *sub) const {    //递归计算树元素个数，取左右子树元素个数之和+1
    if (sub == NULL) {
        return 0;
    } else {
        return 1 + Size(sub->left) + Size(sub->right);
    }
}

template<class T>
void BinaryTree<T>::Traverse(Node *sub, ostream &out) { //前序遍历输出
    if (sub != NULL) {
        cout << sub->data << ' ';
        Traverse(sub->left, out);
        Traverse(sub->right, out);
    }
}

template<class T>
void BinaryTree<T>::preOrder(Node *sub, void(*v)(T x)) {    //前序遍历（递归）
    if (sub != NULL) {
        v(sub->data);
        preOrder(sub->left, v);
        preOrder(sub->right, v);
    }
}

template<class T>
void BinaryTree<T>::inOrder(Node *sub, void(*v)(T x)) {    //中序遍历（递归）
    if (sub != NULL) {
        inOrder(sub->left, v);
        v(sub->data);
        inOrder(sub->right, v);
    }
}

template<class T>
void BinaryTree<T>::postOrder(Node *sub, void(*v)(T x)) {    //后序遍历（递归）
    if (sub != NULL) {
        postOrder(sub->left, v);
        postOrder(sub->right, v);
        v(sub->data);
    }
}

template<class T>
void BinaryTree<T>::PreOrder(void (*v)(T x)) {
    LinkedStack<Node *> stack;
    Node *p = root;
    stack.Push(NULL);
    while (p != NULL) {
        v(p->data);     //访问节点
        if (p->right != NULL) {
            stack.Push(p->right);   //将右子树入栈
        }
        if (p->left != NULL) {
            p = p->left;    //进入左子树
        } else {
            stack.Pop(p);   //没有左子树则出栈得到右子树
        }
    }
}

template<class T>
void BinaryTree<T>::InOrder(void (*v)(T x)) {
    LinkedStack<Node *> stack;
    Node *p = root;
    do {
        while (p != NULL) {     //寻找最左节点，并入栈
            stack.Push(p);
            p = p->left;
        }
        if (!stack.isEmpty()) {     //栈不空时出栈，访问节点，并访问右子树
            stack.Pop(p);
            v(p->data);
            p = p->right;
        }
    } while (p != NULL || !stack.isEmpty());
}

template<class T>
void BinaryTree<T>::PostOrder(void (*v)(T x)) {
    LinkedStack<pNode> stack;
    pNode w;
    Node *p = root;
    do {
        while (p != NULL) { //寻找最左节点，并入栈
            w.ptr = p;
            w.tag = pNode::L;
            stack.Push(w);
            p = p->left;
        }
        bool flag = true;   //循环终止标志
        while (flag && !stack.isEmpty()) {
            stack.Pop(w);   //出栈
            p = w.ptr;
            switch (w.tag) {    //判断元素类型
                case pNode::L:  //左子树则修改标志，进入右子树
                    w.tag = pNode::R;
                    stack.Push(w);
                    flag = false;
                    p = p->right;
                    break;
                case pNode::R:  //从右子树返回父节点
                    v(p->data);
                    break;
            }
        }
    } while (!stack.isEmpty());
}

template<class T>
void BinaryTree<T>::LevelOrder(void (*v)(T x)) {
    LinkedQueue<Node *> queue;
    Node *p = root;
    queue.Push(p);
    while (!queue.isEmpty()) {  //若队列不空
        queue.Pop(p);   //出队
        v(p->data);     //访问节点
        if (p->left != NULL) {
            queue.Push(p->left);    //左子树进队列
        }
        if (p->right != NULL) {
            queue.Push(p->right);   //右子树进队列
        }
    }
}

#endif //BINARYTREE_H

