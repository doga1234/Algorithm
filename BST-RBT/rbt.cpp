// EB
// Implementing Red-Black Tree in C++

#include <iostream>
#include <stdlib.h>
#include <cassert>

namespace RBT
{
  struct Node
  {
    int data;
    std::string name;
    Node *parent;
    Node *left;
    Node *right;
    int color;
  };
}

class RedBlackTree
{
private:
  RBT::Node *root;
  RBT::Node *TNULL;

public:
  RedBlackTree()
  {
    RBT::Node *nil = new RBT::Node();
    nil->color = 0;
    nil->data = 0;
    TNULL = nil;
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

  void preorder_helper(RBT::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // it will fill data[] till the last node
    {
      data[dataLength++] = std::make_pair(node->name, node->data);
      preorder_helper(node->left, data, dataLength);
      preorder_helper(node->right, data, dataLength);
    }
  };

  void inorder_helper(RBT::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // left subtree, root,right subtree
    {
      inorder_helper(node->left, data, dataLength);
      data[dataLength++] = std::make_pair(node->name, node->data);
      inorder_helper(node->right, data, dataLength);
    }
  };

  void postorder_helper(RBT::Node *node, std::pair<std::string, int> data[], int &dataLength)
  {
    if (node != nullptr) // left subtree, right subtree,root
    {
      postorder_helper(node->left, data, dataLength);
      postorder_helper(node->right, data, dataLength);
      data[dataLength++] = std::make_pair(node->name, node->data);
    }
  };

  RBT::Node *searchTree(int key, RBT::Node *node) // searching through tree
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

  RBT::Node *searchTree(int key)
  {
    return searchTree(key, root); // I need to send node for recursion so I use helper
  }

  RBT::Node *findMin(RBT::Node *node)
  {
    while (node->left != nullptr) // since left node is always smaller
    {
      node = node->left;
    }
    return node;
  }

  RBT::Node *findMax(RBT::Node *node)
  {
    while (node->right != nullptr) // since right node is always smaller
    {
      node = node->right;
    }
    return node;
  }

  RBT::Node *successor(RBT::Node *target) // finds minimum value bigger than target
  {
    if (target->right != nullptr)
    {
      return findMin(target->right);
    }

    RBT::Node *p = target->parent;
    while (p != NULL && target == p->right)
    {
      target = p;
      p = p->parent;
    }
    return p;
  }

  RBT::Node *predecessor(RBT::Node *target) // finds maximum value smaller than target
  {

    if (target->left != nullptr)
    {

      return findMax(target->left); // predecessor is the rightmost node in the left subtree
    }

    RBT::Node *predecessor = target->parent;
    // traversing up the tree till finding a node whose right child is also an ancestor of the target
    while (predecessor != nullptr && target == predecessor->left)
    {
      target = predecessor;
      predecessor = predecessor->parent;
    }

    return predecessor;
  }

  void rotateToLeft(RBT::Node *x)
  {
    RBT::Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
      y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == nullptr)
    {
      this->root = y;
    }
    else if (x == x->parent->left)
    {
      x->parent->left = y;
    }
    else
    {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rotateToRight(RBT::Node *x)
  {
    RBT::Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr) // check for the null
    {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) // check for the null
    {
      this->root = y;
    }
    else if (x == x->parent->right)
    {
      x->parent->right = y;
    }
    else //(x->parent->left==x)
    {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  void insert_fix(RBT::Node *k) // Fix the Red-Black Tree after insertion
  {
    RBT::Node *u;
    while (k->parent->color == 1) // red
    {
      if (k->parent == k->parent->parent->right)
      {
        u = k->parent->parent->left;
        if (u != nullptr && u->color == 1)
        {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->left)
          {
            k = k->parent;
            rotateToRight(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rotateToLeft(k->parent->parent);
        }
      }
      else
      {
        u = k->parent->parent->right;

        if (u != nullptr && u->color == 1)
        {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->right)
          {
            k = k->parent;
            rotateToLeft(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rotateToRight(k->parent->parent);
        }
      }
      if (k == root)
      {
        break;
      }
    }
    root->color = 0;
  }

  void insert(std::string city, int key)
  {
    RBT::Node *node = new RBT::Node();
    node->parent = nullptr; // setting
    node->name = city;
    node->data = key;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 1;

    RBT::Node *y = nullptr;
    RBT::Node *x = this->root;

    while (x != nullptr)
    {
      y = x;
      if (node->data < x->data)
      {
        x = x->left;
      }
      else
      {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr)
    {
      root = node;
    }
    else if (node->data < y->data)
    {
      y->left = node;
    }
    else
    {
      y->right = node;
    }

    if (node->parent == nullptr)
    {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr)
    {
      return;
    }

    insert_fix(node);
  }

  // Public insertion function

  void rbTransplant(RBT::Node *u, RBT::Node *v)
  {
    if (u->parent == nullptr) // root
    {
      root = v;
    }
    else if (u == u->parent->left) // left child
    {
      u->parent->left = v;
    }
    else
    { // right child
      u->parent->right = v;
    }
    v->parent = u->parent;
  }
  void delete_fix(RBT::Node *x)
  {
    RBT::Node *s;
    while (x != root && x->color == 0) // when x is not root and its color is red
    {
      if (x == x->parent->left)
      {
        s = x->parent->right;
        if (s->color == 1)
        {
          s->color = 0;
          x->parent->color = 1;
          rotateToLeft(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0)
        {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->right->color == 0)
          {
            s->left->color = 0;
            s->color = 1;
            rotateToRight(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          rotateToLeft(x->parent);
          x = root;
        }
      }
      else
      {
        s = x->parent->left;
        if (s->color == 1)
        {
          s->color = 0;
          x->parent->color = 1;
          rotateToRight(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0)
        {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->left->color == 0)
          {
            s->right->color = 0;
            s->color = 1;
            rotateToLeft(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rotateToRight(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }

  void deleteNode(int value)
  {
    RBT::Node *z = root;
    while (z != nullptr) // find the place
    {
      if (value == z->data)
      {
        break;
      }
      else if (value < z->data)
      {
        z = z->left;
      }
      else
      {
        z = z->right;
      }
    }

    if (z == nullptr)
    {
      // Node with the given value not found
      return;
    }

    RBT::Node *y = z;
    RBT::Node *x;
    int originalColorForY = y->color;

    if (z->left == nullptr) // no left child
    {
      x = z->right;
      rbTransplant(z, z->right);
    }
    else if (z->right == nullptr) // no right child
    {
      x = z->left;
      rbTransplant(z, z->left);
    }
    else
    {
      y = findMin(z->right);
      originalColorForY = y->color;

      if (y->right == nullptr)
      {
        x->parent = y;
        x->right = nullptr;
        y->left = nullptr;
      }
      else
      {
        x = y->right;
      }

      if (y->parent == z) // y is direct child of z
      {
        x->parent = z;
      }
      else
      {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }

    delete z;

    if (originalColorForY == 0)
    {
      delete_fix(x);
    }
  }

  int getHeight(RBT::Node *root)
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

  RBT::Node *getMaximum()
  {
    return findMax(root);
  }

  RBT::Node *getMinimum()
  {
    return findMin(root);
  }

  int getTotalNodes(RBT::Node *root)
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