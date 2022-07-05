#include <iostream>
#include <string>
using namespace std;

// https://programgenjin.hatenablog.com/entry/2019/02/27/082442
struct Node {
  int key;
  Node *parent, *left, *right;
};

Node *NIL, *root;

void insert(int key) {
  Node *x, *y, *z;

  // initialize
  z = new Node;  // 新しい要素のメモリ確保
  z->key = key;
  z->left = NIL;
  z->right = NIL;
  y = NIL;
  x = root;

  // rootから適切な位置まで二分木をたどる
  while (x != NIL) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  // 新しい要素を配置する場所を決定
  z->parent = y;
  if (y == NIL)
    root = z;  // もともと木が存在しなかった場合
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

// 先行順巡回
void preorder(Node *node) {
  if (node == NIL) return;
  cout << " " << node->key;
  if (node->left != NIL) preorder(node->left);
  if (node->right != NIL) preorder(node->right);
}

// 中間順巡回
void inorder(Node *node) {
  if (node == NIL) return;
  if (node->left != NIL) inorder(node->left);
  cout << " " << node->key;
  if (node->right != NIL) inorder(node->right);
}

void print() {
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
}

int main() {
  int i, m, key;
  string command;

  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> command;
    if (command[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      print();
    }
  }

  return 0;
}
