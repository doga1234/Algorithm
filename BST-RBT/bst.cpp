
// Implementing Binary Search Tree in C++

#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

namespace BST
{
  struct Node
  {
    int data;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;
  };
}

class BinarySearchTree
{
private:
  BST::Node *root;

public:
  BinarySearchTree()
  {
  }
  void inorder(std::pair<std::string, int> data[], int dataLength)
  {
    inorder_helper(root, data, dataLength); // since I need to use root for recursion,I call helper
  }
  void preorder(std::pair<std::string, int> data[], int dataLength)
  {
    preorder_helper(root, data, dataLength); // since I need to use root for recursion,I call helper
  }
  void potorder(std::pair<std::string, int> data[], int dataLength)
  {
    postorder_helper(root, data, dataLength); // since I need to use root for recursion,I call helper
  }

  void preorder_helper(BST::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // visit the current node, then traverse left and right subtrees
    {
      data[dataLength++] = std::make_pair(node->name, node->data);
      preorder_helper(node->left, data, dataLength);
      preorder_helper(node->right, data, dataLength);
    }
  };

  void inorder_helper(BST::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // it will fill data[] till the last node
    {
      inorder_helper(node->left, data, dataLength);
      data[dataLength++] = std::make_pair(node->name, node->data);
      inorder_helper(node->right, data, dataLength);
    }
  };

  void postorder_helper(BST::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // it will fill data[] till the last node
    {
      postorder_helper(node->left, data, dataLength);
      postorder_helper(node->right, data, dataLength);
      data[dataLength++] = std::make_pair(node->name, node->data);
    }
  };

  BST::Node *searchTree(int key) // Search for a node with a specific key in the tree
  {
    searchTree(key, root);
  }

  BST::Node *searchTree(int key, BST::Node *node)
  {
    if (node == nullptr || node->data == key)
    {
      return node;
    }

    if (key > node->data) // key's greater than the root's key so key is on the right subtree
    {
      return searchTree(key, node->right);
    }

    return searchTree(key, node->left); // key's smaller than the root's key so key is on th left subtree
  }

  BST::Node *findMin(BST::Node *node) // finding minimum
  {
    while (node->left != nullptr) // since left node is always smaller
    {
      node = node->left;
    }
    return node;
  }

  BST::Node *findMax(BST::Node *node)
  {
    while (node->right != nullptr) // since right node is always smaller
    {
      node = node->right;
    }
    return node;
  }

  BST::Node *successor(BST::Node *target) // finds minimum value bigger than target
  {
    if (target->right != nullptr)
    {
      return findMin(target->right);
    }

    BST::Node *p = target->parent;
    while (p != NULL && target == p->right)
    {
      target = p;
      p = p->parent;
    }
    return p;
    /*
    BST::Node* successor = nullptr;
    BST::Node* temp=root;
    while (temp != nullptr) {
        if (target->data < temp->data) {
            successor = temp;
            temp = temp->left;
        } else if (target->data > temp->data) {
            temp = temp->right;
        } else {
            break;  // Target node found; no successor in this case
        }
    }

    return successor;
    */
  }

  BST::Node *predecessor(BST::Node *target)
  {
    if (target->left != nullptr)
    {
      return findMax(target->left); // predecessor is the rightmost node in the left subtree
    }

    BST::Node *predecessor = target->parent;
    while (predecessor != nullptr && target == predecessor->left)
    {
      // traversing up the tree till finding a node whose right child is also an ancestor of the target
      target = predecessor;
      predecessor = predecessor->parent;
    }

    return predecessor;
  }

  BST::Node *insert(std::string city, int key)
  {
    // when the tree is empty, it creates a new node (as the root)
    if (root == nullptr)
    {
      BST::Node *newNode = new BST::Node();
      newNode->data = key;
      newNode->name = city;
      root = newNode;
      return newNode;
    }
    BST::Node *currentNode = root;
    BST::Node *parent = nullptr;

    while (currentNode != nullptr)
    {
      parent = currentNode;

      if (key < currentNode->data)
      {
        currentNode = currentNode->left;
      }
      else
      {
        currentNode = currentNode->right;
      }
    }
    BST::Node *newNode = new BST::Node();
    newNode->data = key;
    newNode->name = city;
    newNode->parent = parent;

    if (key < parent->data)
    { // inserting the newNode (left or right child of its parent)
      parent->left = newNode;
    }
    else
    {
      parent->right = newNode;
    }

    return root;
  }

  BST::Node *deleteNode(int target)
  {
    deleteNode(root, target);
  }

  BST::Node *deleteNode(BST::Node *root, int target) // after deleting the key,it returns the new root
  {
    if (root == nullptr)
    {
      return root;
    }

    // Search for the node to be deleted

    if (root->data > target)
    {
      root->left = deleteNode(root->left, target);
      return root;
    }
    else if (root->data < target)
    {
      root->right = deleteNode(root->right, target);
      return root;
    }

    if (root->left == NULL)
    {
      BST::Node *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == NULL)
    {
      BST::Node *temp = root->left;
      delete root;
      return temp;
    }
    else
    {

      BST::Node *succParent = root;

      BST::Node *succ = root->right;
      BST::Node *succes = successor(root);
      BST::Node *parent = succes->parent;

      while (succ->left != NULL)
      {
        succParent = succ;
        succ = succ->left;
      }

      if (succParent != root)
        succParent->left = succ->right;
      else
        succParent->right = succ->right;

      // Copy Successor Data to root
      root->data = succ->data;

      // Delete Successor and return root
      delete succ;
      return root;
    }
  }

  int getHeight(BST::Node *root)
  {

    if (root == nullptr)
    { // empty tree
      return -1;
    }
    else
    {
      int leftHeight = getHeight(root->left);
      int rightHeight = getHeight(root->right);

      return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
  }

  int getHeight()
  {
    return getHeight(root);
  }

  BST::Node *getMaximum()
  {
    return findMax(root);
  }

  BST::Node *getMinimum()
  {
    return findMin(root);
  }

  int getTotalNodes(BST::Node *root)
  {
    if (root == NULL)
      return 0;

    int l = getTotalNodes(root->left);
    int r = getTotalNodes(root->right);

    return 1 + l + r;
  }
  int getTotalNodes()
  {
    return getTotalNodes(root);
  }
};