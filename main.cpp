#include <iostream>
#include <vector>

using namespace std;

// Define the structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the binary tree class
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Function to insert a new node
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }
    void preOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        } else {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }


    // Function to perform in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";

        } else {
            return;
        }
    }

    // Helper function to start the insert operation
    void insert(int value) {
        root = insert(root, value);
    }

    // Helper function to start the in-order traversal
    void preOrder() {
        preOrderTraversal(root);
        cout <<endl;
    }
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrder() {
        postOrderTraversal(root);
        cout <<endl;
    }
};

int main() {
    BinaryTree tree;

    // Insert values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Print the in-order traversal of the tree
    cout << "Pre-order Traversal: ";
    tree.preOrder();

    cout << "In-order Traversal: ";
    tree.inOrder();

    cout << "Post-order Traversal: ";
    tree.postOrder();

    return 0;
}

