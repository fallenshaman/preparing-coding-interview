#pragma once 

class BinarySearchTree
{
public:
    struct Node
    {
        int value;
        Node* left;
        Node* right;
        
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
        ~Node()
        {
            delete left;
            delete right;
        }
    };
    
    
private:
    Node* root;
    
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    
    void impl_insert(Node* node, int value);
    int impl_getNodeCount(Node* node);
    bool impl_isExist(Node* node, int value);
    int impl_getHeight(Node* node);
    Node* impl_deleteValue(Node* node, int value);
    
    Node* getMinNode(Node* node);
    
public:
    BinarySearchTree():root(nullptr) { }
    ~BinarySearchTree() { delete root; }
    
    void insert(int value);
    int getNodeCount();
    bool isExist(int value);
    int getHeight();
    
    int getMin();
    int getMax();
    
    void deleteValue(int value);
    void clear();
    
    void print();        // print values in tree, from min to to max.
};
