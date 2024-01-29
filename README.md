# Tree_Exercises_In_Cpp
In this repository, I wrote some important codes of the tree in C++.


## binary_tree:
This C++ program implements various operations on a binary tree. The program defines a `node` class representing a binary tree node and provides functionalities such as creating a new node, calculating the height of the tree, counting leaves and nodes, deleting the entire tree, finding the maximum value, and performing three types of tree traversals (preorder, inorder, and postorder).

## How to Use
1. **Create a New Node:**
   - Choose option 1.
   - Enter the data for the new node.

2. **Calculate Height:**
   - Choose option 2.
   - The program will display the height of the tree.

3. **Count Leaves:**
   - Choose option 3.
   - The program will display the number of leaves in the tree.

4. **Count Nodes:**
   - Choose option 4.
   - The program will display the total number of nodes in the tree.

5. **Delete Tree:**
   - Choose option 5.
   - The program will delete the entire tree and display a success message.

6. **Find Maximum Value:**
   - Choose option 6.
   - The program will display the maximum value present in the tree.

7. **Preorder Traversal:**
   - Choose option 7.
   - The program will display the elements of the tree using preorder traversal.

8. **Inorder Traversal:**
   - Choose option 8.
   - The program will display the elements of the tree using inorder traversal.

9. **Postorder Traversal:**
   - Choose option 9.
   - The program will display the elements of the tree using postorder traversal.

0. **Exit:**
   - Choose option 0 to exit the program.

## Notes
- The program uses a class named `node` to define the structure of each node in the binary tree.
- The main function allows users to interactively perform operations on the binary tree.
- The program supports dynamic memory allocation and handles the deletion of the entire tree to prevent memory leaks.


## AVL_tree:
This C++ program implements an AVL tree, a self-balancing binary search tree. The AVL tree ensures that the tree remains balanced, minimizing the height difference between the left and right subtrees for each node.

## Features
- **Insertion:**
  - Option 1 allows you to insert an item into the AVL tree.
  - The tree automatically performs rotations to maintain balance.

- **Preorder Traversal:**
  - Option 2 displays the items in the AVL tree using preorder traversal.

- **Deletion:**
  - Option 3 enables you to remove a node from the AVL tree.
  - The tree automatically rebalances after deletion.

- **Exit:**
  - Option 0 exits the program.

## How to Use
1. **Insert Item:**
   - Choose option 1.
   - Enter the item you want to insert into the AVL tree.

2. **Show Preorder Tree:**
   - Choose option 2.
   - The program displays the items in the AVL tree using preorder traversal.

3. **Remove Node:**
   - Choose option 3.
   - Enter the item you want to remove from the AVL tree.

4. **Exit:**
   - Choose option 0 to exit the program.

## AVL Tree Operations
- The AVL tree class (`node`) includes methods for:
  - Creating a new node.
  - Performing left and right rotations for balancing.
  - Calculating the height of a node.
  - Calculating the balance factor of a node.

- The `insert` and `remove` methods ensure that the AVL tree remains balanced by performing rotations as needed.

## Notes
- This program provides a basic interface for interacting with the AVL tree through the command line.
- Users can insert items, visualize the tree, and remove nodes while the AVL tree automatically maintains balance.


## BST_tree:
This C++ program implements basic operations on a binary search tree (BST). The program defines a `node` class representing a node in the tree and provides functionalities such as insertion, deletion, searching, and three different tree traversals (inorder, postorder, and preorder).

## Features
- **Insertion:**
  - Option 1 allows you to insert an item into the BST.

- **Searching:**
  - Option 2 enables you to search for an item in the BST.

- **Tree Traversals:**
  - Options 3, 4, and 5 display the items in the BST using inorder, postorder, and preorder traversals, respectively.

- **Deletion:**
  - Option 6 allows you to delete a node from the BST.

- **Exit:**
  - Option 0 exits the program.

## How to Use
1. **Insert Item:**
   - Choose option 1.
   - Enter the item you want to insert into the BST.

2. **Search Item:**
   - Choose option 2.
   - Enter the item you want to search for in the BST.
   - The program indicates whether the item is found or not.

3. **Show Inorder Tree:**
   - Choose option 3.
   - The program displays the items in the BST using inorder traversal.

4. **Show Postorder Tree:**
   - Choose option 4.
   - The program displays the items in the BST using postorder traversal.

5. **Show Preorder Tree:**
   - Choose option 5.
   - The program displays the items in the BST using preorder traversal.

6. **Delete Node:**
   - Choose option 6.
   - Enter the item you want to delete from the BST.

7. **Exit:**
   - Choose option 0 to exit the program.

## BST Operations
- The `node` class includes methods for creating a new node, inserting a node into the BST, searching for a node, and performing three types of tree traversals.

- The `insert` method inserts a node into the BST while maintaining its binary search tree properties.

- The `search` method searches for a specific item in the BST.

- The `remove` method deletes a node from the BST, adjusting the tree structure accordingly.

- The program provides options to interactively perform these operations on the BST.
