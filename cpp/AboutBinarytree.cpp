#include<iostream>
using namespace std;

template<class T>
class arrStack{
private:
    int mSize;
    int top;
    T* st;
public:
    arrStack()
    {
        top = -1;
    }
    arrStack(int size)
    {
        mSize = size;
        top = -1;
        st = new T[mSize];
    }
    ~arrStack()
    {
        delete [] st;
    }
    void clear()
    {
        top = -1;
    }
    bool push(const T item)
    {
        if(top == mSize - 1)
        {
            T * newSt = new T[mSize * 2];
            for(int i = 0; i <= top; i++)
            {
                newSt[i] = st[i];
            }
            delete [] st;
            st = newSt;
            mSize = mSize * 2;
        }
        st[++top] = item;
        return true;
    }
    bool pop(T & item)
    {
        if(-1 == top)
        {
            cout<<"栈为空，不能执行出栈操作"<<endl;
            return false;
        }
        else
        {
            item = st[top--];
            return true;
        }
    }
    bool top(T & item)
    {
        if(-1 == top)
        {
            cout<<"栈为空，不能读取栈顶元素"<<endl;
            return false;
        }
        else
        {
            item = st[top];
            return true;
        }
    }
    bool isEmpty()
    {
        if(-1 == top)
            return true;
        else
            return false;
     }
    bool isFull()
    {
        if(mSize - 1 == top)
            return true;
        else
            return false;
    }
};

/***************************************************************************
template<class T>
class link{
private:
    T value;
    link<T> * next;
public:
    bool setValue(T item)
    {
        value = item;
        return true;
    }
    bool setNext(link<T> * p)
    {
        next = p;
        return true;
    }
    T retvalue()
    {
        return value;
    }
    link<T> * retnext()
    {
        return next;
    }
};

template<class T>
class linkStack:public Stack<T>{
private:
    link<T> * top;
    int size;
public:
    linkStack()
    {
        top = NULL;
        size = 0;
    }
    linkStack(link<T> head)
    {
        top = &head;
        size = 1;
    }
    linkStack(link<T> * phead)
    {
        top = phead;
        size = 1;
    }
    ~linkStack()
    {
        clear();
    }
    bool clear()
    {
        link<T> * detop
        while(top != NULL)
        {
            detop = top;
            top = top -> retnext();
            delete detop;
        }
    }
};
***************************************************************************/

template< class T >
class BinaryTreeNode{
friend class BinaryTreeNode<T>;
private:
    T info;
public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
    T value() const;
    BinaryTreeNode<T>* leftchild() const;
    BinaryTreeNode<T>* rightchild() const;
    void setLeftchild(BinaryTreeNode<T>* l);
    void setRightchild(BinaryTreeNode<T>* r);
    void setValue(const T& val);
    bool isLeaf() const;
    BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node);
};



template< class T >
class BinaryTree{
private:
    BinaryTreeNode<T>* root;
pubilc:
    BinaryTree(){ root = NULL; }
    ~BinaryTree(){ DeleteBinaryTree(root); }
    bool isEmpty() const; //判断二叉树是否为空树，这个有用吗？
    BinaryTreeNode<T>* Root(){ return root; }
    BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* LeftSibiling(BinaryTreeNode<T>* current);
    BinaryTreeNode<T>* RightSibiling(BinaryTreeNode<T>* current);
    void CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);
    void PreOrder(BinaryTreeNode<T>* root);
    void InOrder(BinaryTreeNode<T>* root);
    void PostOrder(BinaryTreeNode<T>* root);
    void PreOrderRecursion(BinaryTreeNode<T>* root);
    void InOrderRecursion(BinaryTreeNode<T>* root);
    void PostOrderRecursion(BInaryTreeNode<T>* root);
    void LevelOrder(BinaryTreeNode<T>* root);
    void DeleteBinaryTree(BinaryTreeNode<T>* root);
};

int main()
{
    return 0;
}
