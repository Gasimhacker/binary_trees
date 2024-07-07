# Binary Trees

This repository contains implementations of various binary tree data structures and algorithms in C. It includes functionalities such as insertion, deletion, traversal methods (inorder, preorder, postorder), and search operations.

## Overview

The Binary Trees project aims to provide a comprehensive collection of binary tree implementations to facilitate learning and usage of fundamental data structures and algorithms. Each implementation is designed to be efficient and robust, showcasing best practices in C programming.

## Features

- **Binary Tree Implementations:** Includes basic binary tree, binary search tree (BST), AVL tree, and more.
- **Core Operations:** Supports common operations such as insertion, deletion, and various traversal methods.
- **Efficient Algorithms:** Algorithms are optimized for performance and adhere to standard data structure principles.
- **Detailed Documentation:** Each function and data structure is thoroughly documented for ease of understanding and usage.

## Usage

To use the binary trees in your projects, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/Gasimhacker/binary_trees.git
   ```
2. Navigate to the directory:
   
   ```bash
   cd binary_trees
   ```

3. Include in Your Project:
   In your project directory, create a new C file and include the header file binary_trees.h to access the functions and data structures from this repository.
   ### Example:
   
    ```C
    #include <stdlib.h>
    #include <stdio.h>
    #include "binary_trees.h"
  
    /**
     * main - Entry point
     *
     * Return: Always 0 (Success)
     */
    int main(void)
    {
        binary_tree_t *root;
    
        root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
        root->right = binary_tree_node(root, 402);
        binary_tree_print(root);
        printf("\n");
        binary_tree_insert_left(root->right, 128);
        binary_tree_insert_left(root, 54);
        binary_tree_print(root);
        return (0);
    }
    ```
4. Compile the code (example using gcc):
   
   ```bash
   gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
   ```
5. Run the executable:
   
   ```bash
   ./1-left
   ```

## Installation
There are no additional dependencies required to run the binary tree implementations other than a standard C compiler (e.g., gcc).

## Contributing
Contributions are welcome! Feel free to fork the repository and submit pull requests with your enhancements.


