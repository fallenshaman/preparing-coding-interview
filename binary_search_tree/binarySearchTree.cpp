#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

void BinarySearchTree::insert(int value)
{
    if(nullptr == root)
    {
        root = new Node(value);
        return;
    }
    
    return impl_insert(root, value);
}

void BinarySearchTree::impl_insert(Node* node, int value)
{
    if(value <= node->value)
    {
        if(nullptr == node->left)
        {
            node->left = new Node(value);
            return;
        }
        else
        {
            impl_insert(node->left, value);
        }
    }
    else
    {
        if(nullptr == node->right)
        {
            node->right = new Node(value);
            return;
        }
        else
        {
            impl_insert(node->right, value);
        }
    }
}

void BinarySearchTree::print()
{
    inorder(root);
    cout << endl;
}

int BinarySearchTree::getNodeCount()
{
    return impl_getNodeCount(root);
}

int BinarySearchTree::impl_getNodeCount(Node* node)
{
    if(nullptr == node)
        return 0;
    
    return 1 + impl_getNodeCount(node->left) + impl_getNodeCount(node->right);
}

bool BinarySearchTree::isExist(int value)
{
    return impl_isExist(root, value);
}

bool BinarySearchTree::impl_isExist(Node* node, int value)
{
    if(nullptr == node)
        return false;
    
    if(node->value == value)
    {
        return true;
    }
    else if(value < node->value)
    {
        return impl_isExist(node->left, value);
    }
    else
    {
        return impl_isExist(node->right, value);
    }
}

int BinarySearchTree::getHeight()
{
    return impl_getHeight(root);
}

int BinarySearchTree::impl_getHeight(Node* node)
{
    if(nullptr == node)
        return 0;
    
    return 1 + max(impl_getHeight(node->left), impl_getHeight(node->right));
}

int BinarySearchTree::getMin()
{
    if(nullptr == root)
    {
        cout << "Tree is empty!!" << endl;
        return -1;
    }
    
    Node* node = root;
    
    while(nullptr != node->left)
    {
        node = node->left;
    }
    
    return node->value;
}

BinarySearchTree::Node* BinarySearchTree::getMinNode(Node* node)
{
    Node* minNode = node;
    
    while(nullptr != minNode->left)
    {
        minNode = minNode->left;
    }
    
    return minNode;
}

int BinarySearchTree::getMax()
{
    if(nullptr == root)
    {
        cout << "Tree is empty!!" << endl;
        return -1;
    }
    
    Node* node = root;
    
    while(nullptr != node->right)
    {
        node = node->right;
    }
    
    return node->value;
}

void BinarySearchTree::deleteValue(int value)
{
    root = impl_deleteValue(root, value);
}

BinarySearchTree::Node* BinarySearchTree::impl_deleteValue(Node* node, int value)
{
    if(nullptr == node)
        return nullptr;
    
    if(node->value == value)
    {
        if(nullptr == node->left && nullptr == node->right)
        {
            // both nodes are null.
            delete node;
            node = nullptr;
        }
        else if(nullptr != node->left && nullptr != node->right)
        {
            // both nodes are not null.
            Node* minNode = getMinNode(node->right);
            
            node->value = minNode->value;
            node->right = impl_deleteValue(node->right, minNode->value);
        }
        else if(nullptr == node->left)
        {
            Node* temp = node;
            node = node->right;
            temp->right = nullptr;
            delete temp;
        }
        else{
            Node* temp = node;
            node = node->left;
            temp->left = nullptr;
            delete temp;
        }
    }
    else if(value < node->value)
    {
        node->left = impl_deleteValue(node->left, value);
    }
    else
    {
        node->right = impl_deleteValue(node->right, value);
    }
    
    return node;
}

void BinarySearchTree::clear()
{
    delete root;
    root = nullptr;
}

void BinarySearchTree::inorder(Node* node)
{
    if(nullptr == node)
        return;
    
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void BinarySearchTree::preorder(Node* node)
{
    if(nullptr == node)
        return;
    
    cout << node->value << " ";
    inorder(node->left);
    inorder(node->right);
}

void BinarySearchTree::postorder(Node* node)
{
    if(nullptr == node)
        return;
    
    inorder(node->left);
    inorder(node->right);
    cout << node->value << " ";
}
