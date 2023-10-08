#include <iostream>
#include <vector>
 
 class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int data) {
            this->data = data;
            this->left = this->right = nullptr;
            // this->right = nullptr;
        }
 };

 TreeNode *createTree(std::vector<int> &treeData, int index = 0)
 {

    if (index >= treeData.size() || treeData[index] == -1)
        return nullptr;
    TreeNode *root = new TreeNode(treeData[index]);
    root->left = createTree(treeData, 2 * index + 1);
    root->right = createTree(treeData, 2 * index + 2);
    return root;
 }

//  Depth First Search (DFS)
//     preorder (root, left, right)
//     inorder (left, root, right)
//     postorder (left, right, root)


void preorderTree(TreeNode *root, std::vector<int> &preorderedTree) {
    if (root == nullptr) return;

    // std::cout << root->data << std::endl;
    preorderedTree.push_back(root->data);
    preorderTree(root->left, preorderedTree);
    preorderTree(root->right, preorderedTree);
}

void inorderTree(TreeNode *root, std::vector<int> &inorderedTree) {
    if (root == nullptr) return;

    inorderTree(root->left, inorderedTree);
    inorderedTree.push_back(root->data);
    inorderTree(root->right, inorderedTree);
}

void postorderTree(TreeNode *root, std::vector<int> &postorderedTree) {
    if (root == nullptr) return;

    postorderTree(root->left, postorderedTree);
    postorderTree(root->right, postorderedTree);
    postorderedTree.push_back(root->data);
}
 