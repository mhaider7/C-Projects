// Mazin Haider
// CIS 223-401
// December 3, 2023
/* This programs include the template class for the binary tree. It also includes 2 added member functions. The first function returns the height of the tree(the number of level it contains). The second functoin class the first function
 */

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    // Instantiate the BinaryTree class
    BinaryTree<int> tree;
    
    // Insert values into the BinaryTree class
    tree.insertNode(12);
    tree.insertNode(23);
    tree.insertNode(11);
    tree.insertNode(5);
    tree.insertNode(1);
    tree.insertNode(19);
    tree.insertNode(21);
    
    // Display the values in pre order of the binary tree
    cout << "Displaying the values of the binary tree pre-order\n";
    tree.displayPreOrder();
    
    // Delete some of the nodes
    cout << "Deleting nodes.\n";
    tree.remove(5);
    tree.remove(12);
    tree.remove(11);
    
    // Add some nodes
    cout << "Adding nodes.\n";
    tree.insertNode(16);
    tree.insertNode(2);
    tree.insertNode(100);
    
    // Display the values in the tree in order of the binary tree
    cout << "Displaying the values of the binary tree in-order\n";
    tree.displayInOrder();
    
    // Display the number of levels that are in the class
    cout << "The number of levels in the tree are: " << tree.treeHeight() << endl;
    
    
    return 0;
}


/*
            23
         1     100
          19
        16  21
       2
 5 levels
 */
