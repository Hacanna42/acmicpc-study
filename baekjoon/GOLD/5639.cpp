// 백준: 이진 검색 트리
// https://www.acmicpc.net/problem/5639
// 2024-05-28
// 복습 - 2회차

#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value > root->value) {
        root->right = insert(root->right, value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }

    return root;
}

void postOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->value << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int value;
    cin >> value;
    TreeNode *root = new TreeNode(value);
    while (cin >> value) {
        insert(root, value);
    }
    postOrder(root);
    return 0;
}