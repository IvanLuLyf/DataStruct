//
// Created by IvanLu on 2017/11/11.
//

#ifndef THREADTREE_H
#define THREADTREE_H

template<class T>
struct ThreadNode {
    bool lTag, rTag;        //线索标志
    ThreadNode<T> *left, *right;    //线索或子女指针
    T data;                 //节点数据

    ThreadNode(const T item) : data(item), left(NULL), right(NULL), lTag(false), rTag(false) {}
};

template<class T>
class ThreadTree {
protected:
    T EndValue;
    ThreadNode<T> *root;

    void createInThread(ThreadNode<T> *current, ThreadNode<T> *&pre);

    void CreateTree(istream &in, ThreadNode<T> *&subTree);

    void Destory(ThreadNode<T> *sub);    //清理树

    ThreadNode<T> *Parent(ThreadNode<T> *t);    //寻找当前节点的父节点

    void InsertRight(ThreadNode<T> *s, ThreadNode<T> *r);

    void InsertLeft(ThreadNode<T> *s, ThreadNode<T> *l);

    ThreadNode<T> *Search(ThreadNode<T> *p, T value);

public:
    ThreadTree() : root(NULL) {}

    ThreadTree(T value) : EndValue(value), root(NULL) {}

    ~ThreadTree() { Destory(root); }

    void createInThread();

    bool isEmpty() { return root == NULL; }     //树是否为空

    ThreadNode<T> *First(ThreadNode<T> *current);   //寻找当前节点在线索二叉树中序下第一个节点

    ThreadNode<T> *Last(ThreadNode<T> *current);    //寻找当前节点在线索二叉树中序下最后一个节点

    ThreadNode<T> *Next(ThreadNode<T> *current);    //寻找当前节点在线索二叉树中序下下一个节点

    ThreadNode<T> *Prior(ThreadNode<T> *current);   //寻找当前节点在线索二叉树中序下前一个节点

    void InOrder(void(*visit)(T x));    //前序遍历

    void PreOrder(void(*visit)(T x));   //中序遍历

    void PostOrder(void(*visit)(T x));  //后序遍历

    ThreadNode<T> *Search(T value);

    void Insert(ThreadNode<T> *s, ThreadNode<T> *i, bool IsLeft = true);

    friend istream &operator>>(istream &in, ThreadTree<T> &Tree) {
        Tree.CreateTree(in, Tree.root);
        return in;
    }
};

template<class T>
void ThreadTree<T>::CreateTree(istream &in, ThreadNode<T> *&subTree) {
    T item;
    if (!in.eof()) {
        in >> item;
        if (item != EndValue) {
            subTree = new ThreadNode<T>(item);
            if (subTree == NULL) {
                cerr << "No Enough Memory." << endl;
                return;
            }
            CreateTree(in, subTree->left);
            CreateTree(in, subTree->right);
        } else {
            subTree = NULL;
        }
    }
}

template<class T>
void ThreadTree<T>::createInThread() {
    ThreadNode<T> *pre = NULL;  //前驱节点指针
    if (root != NULL) {
        createInThread(root, pre);  //中序遍历线索化
        pre->right = NULL;
        pre->rTag = true;
    }
}

template<class T>
void ThreadTree<T>::createInThread(ThreadNode<T> *current, ThreadNode<T> *&pre) {
    if (current == NULL) {
        return;
    }
    createInThread(current->left, pre); //左子树线索化
    if (current->left == NULL) {        //建立当前节点的
        current->left = pre;
        current->lTag = true;
    }
    if (pre != NULL && pre->right == NULL) {    //建立前驱节点的后续线索
        pre->right = current;
        pre->rTag = true;
    }
    pre = current;
    createInThread(current->right, pre);    //右子树线索化
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Parent(ThreadNode<T> *t) {
    ThreadNode<T> *p;
    if (t == root)
        return NULL;
    for (p = t; !p->lTag; p = p->left);
    if (p->left != NULL) {
        for (p = p->left; p != NULL && p->left != t && p->right != t; p = p->right);
    }
    if (p == NULL || p->left == NULL) {
        for (p = t; !p->rTag; p = p->right);
        for (p = p->right; p != NULL && p->left != t && p->right != t; p = p->left);
    }
    return p;
}

template<class T>
void ThreadTree<T>::InsertRight(ThreadNode<T> *s, ThreadNode<T> *r) {
    r->right = s->right;
    r->rTag = s->rTag;
    r->left = s;
    r->lTag = true;
    s->right = r;
    s->rTag = false;
    if (!r->rTag) {
        ThreadNode<T> *temp;
        temp = First(r->right);
        temp->left = r;
    }
}

template<class T>
void ThreadTree<T>::InsertLeft(ThreadNode<T> *s, ThreadNode<T> *l) {
    l->left = s->left;
    l->lTag = s->lTag;
    l->right = s;
    l->rTag = true;
    s->left = l;
    s->lTag = false;
    if (!l->lTag) {
        ThreadNode<T> *temp;
        temp = Next(l->left);
        temp->right = l;
    }
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Search(T value) {
    return Search(root, value);
}

template<class T>
void ThreadTree<T>::Insert(ThreadNode<T> *s, ThreadNode<T> *i, bool IsLeft) {
    if (IsLeft) {
        InsertLeft(s, i);
    } else {
        InsertRight(s, i);
    }
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Search(ThreadNode<T> *p, T value) {
    ThreadNode<T> *find = NULL;
    if (p != NULL) {
        if (p->data == value) {
            return p;
        }
        if (!p->lTag) {
            find = Search(p->left, value);
        }
        if (find == NULL && !p->rTag) {
            find = Search(p->right, value);
        }
    }
    return find;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T> *current) {
    ThreadNode<T> *p = current;
    while (!p->lTag) {  //寻找最左下节点
        p = p->left;
    }
    return p;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T> *current) {
    ThreadNode<T> *p = current;
    while (!p->rTag) {  //寻找最右下节点
        p = p->right;
    }
    return p;
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T> *current) {
    ThreadNode<T> *p = current->right;
    if (!current->rTag) {   //在右子树中找中序线索化下第一个节点
        return First(p);
    } else {
        return p;   //右标记为线索，直接返回
    }
}

template<class T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T> *current) {
    ThreadNode<T> *p = current->left;
    if (!current->lTag) {   //在左子树中找中序线索化下最后一个节点
        return Last(p);
    } else {
        return p;   //左标记为线索，直接返回
    }
}

template<class T>
void ThreadTree<T>::InOrder(void(*visit)(T x)) {
    ThreadNode<T> *p;
    for (p = First(root); p != NULL; p = Next(p)) {
        visit(p->data);
    }
}

template<class T>
void ThreadTree<T>::PreOrder(void(*visit)(T x)) {
    ThreadNode<T> *p = root;
    while (p != NULL) {
        visit(p->data);
        if (!p->lTag) {
            p = p->left;
        } else if (!p->rTag) {
            p = p->right;
        } else {
            while (p != NULL && p->rTag) {
                p = p->right;
            }
            if (p != NULL) {
                p = p->right;
            }
        }
    }
}

template<class T>
void ThreadTree<T>::PostOrder(void(*visit)(T x)) {
    ThreadNode<T> *t = root;
    while (!t->lTag || !t->rTag) {
        if (!t->lTag) {
            t = t->left;
        } else if (!t->rTag) {
            t = t->right;
        }
    }
    visit(t->data);
    ThreadNode<T> *p;
    while ((p = Parent(t)) != NULL) {
        if (p->right == t || p->rTag) {
            t = p;
        } else {
            t = p->right;
            while (!t->lTag || !t->rTag) {
                if (!t->lTag) {
                    t = t->left;
                } else if (!t->rTag) {
                    t = t->right;
                }
            }
        }
        visit(t->data);
    }
}

template<class T>
void ThreadTree<T>::Destory(ThreadNode<T> *sub) {
    ThreadNode<T> *pre = First(sub);
    ThreadNode<T> *p = next(pre);
    for (; p != NULL; pre = p, p = Next(p)) {
        delete (pre);
    }
    delete (pre);
}

#endif //THREADTREE_H
