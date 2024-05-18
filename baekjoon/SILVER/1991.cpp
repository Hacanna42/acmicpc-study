// 백준: 트리 순회
// https://www.acmicpc.net/problem/1991
// 2024-05-16

/*
트리 구현을 배울 수 있는 교육적인 문제.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {} // unordered_map에서 새로운 키를 생성할 때, 먼저 기본 생성자로 TreeNode를 생성하고 거기에 값을 대입하기 때문에. 기본 생성자 자체를 누락시키면
                                                   // tuple:1811:7: error: no matching constructor for initialization of 'TreeNode' 에러가 남.
};

void preOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->val;
    inOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    unordered_map<char, TreeNode> nodes;
    for (int i = 0; i < N; ++i) {
        char node, left, right;
        cin >> node >> left >> right;
        if (nodes.find(node) == nodes.end()) { // 새로운 노드
            nodes[node] = TreeNode(node);
        }
        if (left != '.' && nodes.find(left) == nodes.end()) {
            nodes[left] = TreeNode(left);
        }
        if (right != '.' && nodes.find(right) == nodes.end()) {
            nodes[right] = TreeNode(right);
        }

        nodes[node].left = (left == '.') ? nullptr : &nodes[left];
        nodes[node].right = (right == '.') ? nullptr : &nodes[right];
    }

    TreeNode *root = &nodes['A'];
    // 순회
    preOrder(root);
    cout << "\n";
    inOrder(root);
    cout << "\n";
    postOrder(root);
    cout << "\n";

    // for (auto &node : nodes) {
    //     delete node.second;
    // }

    return 0;
}