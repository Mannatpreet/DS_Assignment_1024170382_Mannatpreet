#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " => ";
    inorder(node->right);
}

void preorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " => ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " => ";
}

Node *search(Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data < key)
    {
        return search(root->right, key);
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return root;
    }
}

Node* searchParent(Node *root, int key)
{
    if (root == nullptr || root->data == key) {
        return nullptr;
    }

    Node *parent = nullptr;
    Node *child = root;

    while (child != nullptr && child->data != key) 
    {
        parent = child;

        if (key < child->data) {
            child = child->left;
        } else {
            child = child->right;
        }
    }

    return parent;
}



int getMax(Node *root)
{
    if (root->right == nullptr)
    {
        return root->data;
    }
    return getMax(root->right);
}

int getMin(Node *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }
    return getMin(root->left);
}

int inorderSuccessor(Node *root, Node *node)
{

    if (node->right != nullptr)
    {

        Node *curr = node->right;

        while (curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr->data;
    }
    else
    {
        int key = node->data;
        Node *succ = nullptr;
        Node *curr = root;

        while (curr != nullptr)
        {

            if (key < curr->data)
            {

                succ = curr;
                curr = curr->left;
            }
            else if (key > curr->data)
            {

                curr = curr->right;
            }
            else
            {

                break;
            }
        }

        if (succ == nullptr)
        {
            return -1;
        }
        return succ->data;
    }
}

int inorderPredecessor(Node *root, Node *node)
{

    if (node->left != nullptr)
    {

        Node *curr = node->left;

        while (curr->right != nullptr)
        {
            curr = curr->right;
        }
        return curr->data;
    }
    else
    {
        int key = node->data;
        Node *succ = nullptr;
        Node *curr = root;

        while (curr != nullptr)
        {

            if (key > curr->data)
            {
                succ = curr;
                curr = curr->right;
            }
            else if (key < curr->data)
            {
                curr = curr->left;
            }
            else
            {

                break;
            }
        }

        if (succ == nullptr)
        {
            return -1;
        }
        return succ->data;
    }
}

void insert(Node *root, int val)
{

    if (root == nullptr)
    {
        root = new Node(val);
        return;
    }

    if (val < root->data)
    {
        if (root->left == nullptr)
        {
            root->left = new Node(val);
            return;
        }
        else
        {
            insert(root->left, val);
        }
    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new Node(val);
            return;
        }
        else
        {
            insert(root->right, val);
        }
    }
}

void deleteNode(Node *root, int val) 
{
    Node *toDel = search(root, val);
    Node *parent = searchParent(root, val);

    if (toDel->left == nullptr && toDel->right == nullptr)
    {
        if (parent != nullptr) {
            if (parent->left == toDel) parent->left = nullptr;
            else parent->right = nullptr;
        }

        delete toDel;
        return;
    }

    if (toDel->left != nullptr && toDel->right == nullptr)
    {
        if (parent != nullptr) {
            if (parent->left == toDel) parent->left = toDel->left;
            else parent->right = toDel->left;
        }

        delete toDel;
        return;
    }

    if (toDel->left == nullptr && toDel->right != nullptr)
    {
        if (parent != nullptr) {
            if (parent->left == toDel) parent->left = toDel->right;
            else parent->right = toDel->right;
        }

        delete toDel;
        return;
    }

    if (toDel->left != nullptr && toDel->right != nullptr)
    {
        Node* succParent = toDel;
        Node* succ = toDel->right;

        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }

        toDel->data = succ->data;

        if (succParent->left == succ) {
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }

        delete succ;
        return;
    }
}

int findMinDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr) {
        return 1 + findMinDepth(root->right);
    }

    if (root->right == nullptr) {
        return 1 + findMinDepth(root->left);
    }

    return 1 + min(findMinDepth(root->left), findMinDepth(root->right));
}

int findMaxDepth(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(findMaxDepth(root->left), findMaxDepth(root->right));
}








int main()
{

    return 0;
}
