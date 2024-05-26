//
//  BinaryTree.h
//  chapter21HW
//
//  Created by Mazin Haider on 12/3/23.
//

#ifndef BinaryTree_h
#define BinaryTree_h

using namespace std;
// Create the binary tree template class
template <typename T>
class BinaryTree {
private:
    // Create the struct which will be the datatype for the nodes of the binary tree
    struct TreeNode {
        T value;                        // Holds the value
        TreeNode *left;                 // Points to the left subtree node
        TreeNode *right;                // Points to the right subtree node
    };
    
    TreeNode *root;                     // The head pointer of the binary tree
    
    // Create the function prototypes for the functions which will contain the code for manipulating the binary tree
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    int countTreeHeight(TreeNode *);                // Function for calculating the levels to the binary tree
    
public:
    // Create the constructor which assigns the head pointer to null
    BinaryTree() {
        root = nullptr;
    }

    // Create the destructor which will call the private function to delete all the nodes
    ~BinaryTree() {
        destroySubTree(root);
    }
    
    // Create the insert, search, and delete functions for the binary tree
    void insertNode(T);
    bool searchNode(T);
    void remove(T);
    
    // Create the display node function which call the private functions
    void displayInOrder() const {
        displayInOrder(root);
    }
    
    void displayPreOrder() const {
        displayPreOrder(root);
    }
    
    void displayPostOrder() const {
        displayPostOrder(root);
    }
    
    int treeHeight();
    
};

// Define the public function which will call the private counting function for the binary tree levels
template <typename T>
int BinaryTree<T>::treeHeight() {
    return countTreeHeight(root);                       // Pass in the head pointer of the tree to the level counting function
}

// Define the private function which will calculate number of levels to the tree and return the max level of the two subtrees
template <typename T>
int BinaryTree<T>::countTreeHeight(TreeNode *nodePtr) {
    int height, leftHeight = 0, rightHeight = 0;
    
    if (nodePtr) {                                          // If the nodePtr is not null
        leftHeight = countTreeHeight(nodePtr->left);        // Recursively call the left subtree node
        rightHeight = countTreeHeight(nodePtr->right);      // Recursively call the left subtree node
        if (leftHeight > rightHeight)                       // If the left height is greater than right height
            height = leftHeight + 1;                        // Then, Increment the height
        else                                                // If the right height is greater than or equal to the left height
            height = rightHeight + 1;                       // Then, increment the height
    } else {                                                // If the nodePtr is null
        height = 0;                                         // The height of the tree is 0
    }
     
    return height;
}
/*
 First, recursion occurs for each subtree node until nodePtr == null for each path down the tree
 Then, the chain of function calls work backwards in comparing and calculating the heights of the tree
 */


// Private function which inserts at the end of the node in the correct right or left node of the heirarchy
template <typename T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == nullptr) {                       // If the binary tree is empty
        nodePtr = newNode;                          // Then, dd newNode to the tree
    } else if (newNode->value < nodePtr->value) {   // If the newNode's value is less than the existing nodes value
        insert(nodePtr->left, newNode);             // Then, call the function again passing in the left subtree node and the newNode
    } else {                                        // If the newNode's value is greater than the existing node value
        insert(nodePtr->right, newNode);            // Then, call the function again passing in the right subtree node and the newNode
    }
}

// This public function creates the new node and passes it into the above function to insert the node at the end of the binary tree's subtrees
template <typename T>
void BinaryTree<T>::insertNode(T item) {
    TreeNode *newNode = nullptr;                    // Create the node node
    
    newNode = new TreeNode;                         // Allocate memory for the node
    newNode->value = item;                          // Initialize the new node
    newNode->left = newNode->right = nullptr;
    
    insert(root, newNode);                          // Call the function which will insert the node
}

// This is a private function that is called by the deconstructor to delete the nodes in the binary tree
template <typename T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
    // If the binary tree is not empty
    if (nodePtr) {
        if (nodePtr->left)                          // If nodePtr->left != nullptr
            destroySubTree(nodePtr->left);          // Then call the function again to traverse to the next node in the left subtree
        if (nodePtr->right)                         // If nodePtr->right != nullptr
            destroySubTree(nodePtr->right);         // Then, call the function again to traverse to the next node in the left subtree
        delete nodePtr;                             // Delete the nodePtr once the end of the tree is reached
    }
}

// This function searches the binary tree for whether an item exists in the tree
template <typename T>
bool BinaryTree<T>::searchNode(T item) {
    TreeNode *nodePtr = root;                   // Assign the tree address to nodePtr for traversing the binary tree
    
    // while the binary tree is not empty
    while (nodePtr) {
        if (nodePtr->value == item) {               // If the first node in the tree has a value equal to the one being searched for
            return true;                            // Then, return true
        } else if (item < nodePtr->value) {         // If the item is less in value than the current node's value
            nodePtr = nodePtr->left;                // Traverse to the left subtree of the binary tree
        } else {                                    // If the item is greater in value than the current node's value
            nodePtr = nodePtr->right;               // Traverse to the right subtree of the binary tree
        }
    }
    return false;                                   // Return false if all of the nodes have been traversed and the item was not found in the tree
}

// This public function calls the private deleteNode function
template <typename T>
void BinaryTree<T>::remove(T item) {
    deleteNode(item, root);
}

// This private function traverses through the binary tree searching for the item passed in, and deletes it
template <typename T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr) {
    if (item < nodePtr->value)                  // If the item is less than the current node
        deleteNode(item, nodePtr->left);        // Then traverse to the left of the subtree utilizing recursion
    else if (item > nodePtr->value)             // If the item is greater than the current node
        deleteNode(item, nodePtr->right);       // Then traverse to the right of the subtree utilizing recursion
    else                                        // If the item is equal to the current node
        makeDeletion(nodePtr);                  // Call the private function passing in the desired node to delete
}

// This private function takes out the desired node from the tree, reattaches the tree, then deletes the node that was taken out
template <typename T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr) {
    // Create a temporary node which will hold the address of the node to delete
    TreeNode *tempNodePtr = nullptr;
    
    if (nodePtr == nullptr) {
        cout << "Can't delete empty node.\n";
    } else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    } else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    } else {
        tempNodePtr = nodePtr->right;
        
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

// This public recursive function displays the nodes in order
template <typename T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

// This public recursive function displays the nodes pre order
template <typename T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

// This public recursive function displays the nodes post order
template <typename T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
    }
}


#endif /* BinaryTree_h */
