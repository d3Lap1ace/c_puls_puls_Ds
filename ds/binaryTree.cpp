#include <iostream>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;


// 声明:二叉树 节点
struct BinTreeNode {
	int data;                                                                                 
	BinTreeNode* leftChild, * rightChild;												
	BinTreeNode():leftChild(nullptr),rightChild(nullptr){}											
	BinTreeNode(int x, BinTreeNode* l = nullptr, BinTreeNode* r = nullptr) : data(x), leftChild(l), rightChild(r) {};
};


// 声明:二叉树 类
class binaryTree {
private:
    BinTreeNode* root; 
public:
	binaryTree() :root(nullptr) {}
    ~binaryTree() { destroy(root); }
    
public:
    void add(int value) {
        root = insert(root, value);
    }
    BinTreeNode* insert(BinTreeNode* node, int value) {
        if (node == nullptr) {
            return new BinTreeNode(value);
        }
        if (value < node->data) {
            node->leftChild = insert(node->leftChild, value);
        }
        else if (value > node->data) {
            node->rightChild = insert(node->rightChild, value);
        }
        return node;
    }

    // 递归前序
    void PreOrder(BinTreeNode* &subTree) { 
        if (subTree != nullptr) {
            cout << subTree->data << " ";
            PreOrder(subTree->leftChild);
            PreOrder(subTree->rightChild);
        }
        PreOrder(root); }

    // 递归中序
    void InOrder(BinTreeNode* &subTree) {
        if (subTree != nullptr) {
            InOrder(subTree->leftChild);
            cout << subTree->data << " ";
            InOrder(subTree->rightChild);
        }
    }

    // 递归后序
    void PostOrder(BinTreeNode*& subTree) {
        if (subTree != nullptr) {
            PostOrder(subTree->leftChild);
            PostOrder(subTree->rightChild);
            cout << subTree->data << " ";
        }
    }
    
    // 前序
    void PreOrder_NoRecurve1() {
        BinTreeNode* p = root;                              
        if (p == nullptr) return;                        
        stack<BinTreeNode*> stack;                          

        if(p!=nullptr){
            stack.push(p);
            while(!stack.empty()){
                p = stack.top();
                stack.pop();
                cout<<p->data<<" ";
                if(p->rightChild!=nullptr){
                    stack.push(p->rightChild);
                }
                if(p->leftChild!=nullptr){
                    stack.push(p->leftChild);
                }
            }
        }
    }

    // 中序
    void InOrder_NoRecurve() {
        BinTreeNode* p = root;
        stack<BinTreeNode*> S;
        do {
            while (p !=nullptr){
                S.push(p);
                p = p->leftChild;
            }
            if (!S.empty()) {
                p = S.top();
                S.pop();
                cout << p->data << " ";
                p = p->rightChild;
            }
        } while (p != nullptr || !S.empty());
    }

    // 后序
    void PostOrder_NoRecurve() {
        BinTreeNode* p = root;
        if (p == nullptr) return;
        stack<BinTreeNode*>stack1;
        stack<BinTreeNode*>stack2;

        stack1.push(p);
        while (!stack1.empty()){
            p = stack1.top();
            stack1.pop();
            stack2.push(p);
            if (p->leftChild)stack1.push(p->leftChild);
            if (p->rightChild)stack1.push(p->rightChild);
        }
        while (!stack2.empty()) {
            p = stack2.top();
            stack2.pop();
            cout << p->data << " ";
        }
    }

    // 层次
    void LevelOrder() {
        BinTreeNode* p = root;
        if (p == nullptr) return;

        queue<BinTreeNode*>queue;
        queue.push(root);
        while (!queue.empty()) {
            BinTreeNode* current = queue.front();
            queue.pop();
            cout << current->data << " ";
            if (current->leftChild != nullptr) {
                queue.push(current->leftChild);
            }
            if (current->rightChild != nullptr) {
                queue.push(current->rightChild);
            }
        }
        cout << endl;
    }


    // 销毁
    void destroy(BinTreeNode*& node) {
        if (node != nullptr) {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
            node = nullptr;
        }
    }

    // 判断是否平衡
    bool isBalanced(BinTreeNode * root){
        return 
    }
    int helper(BinTreeNode * root){
        if(!root) return 0;
        int left = helper(root->leftChild),right = helper(root->rightChild);
    }

    // 



};

int main() {
    
    binaryTree tree;

    tree.add(12);
    tree.add(1);
    tree.add(2);
    tree.add(13);
    tree.add(14);
    tree.add(15);
    tree.add(4);
    tree.add(2);

    tree.InOrder_NoRecurve();
    cout << endl;
    tree.PostOrder_NoRecurve();
    cout << endl;
    tree.PreOrder_NoRecurve1();
    cout << endl;
    tree.LevelOrder();
    
}