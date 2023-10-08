#include "create.hpp"

int main(int argc, const char** argv) {
    // TreeNode *root = createTree(1);
    // root->left = createTree(2);
    // root->right = createTree(3);
    // root->left->left = createTree(4);
    // root->left->right = createTree(5);
    // root->left->right->left = createTree(9);
    // root->left->right->right = createTree(10);
    // root->right->left = createTree(6);
    // root->right->right = createTree(7);


    // std::cout << root->data << std::endl;
    // std::cout << root->left->data << std::endl;
    std::vector<int> treeData = {1, 2, 3, 4, 5, NULL, 6, NULL, NULL, 7, 8, NULL, NULL, NULL, NULL, 9, 10};
    TreeNode *root = createTree(treeData);

    std::vector<int> treePreorder, treeInorder, treePostorder;
    preorderTree(root, treePreorder);
    inorderTree(root, treeInorder);
    postorderTree(root, treePostorder);
    for (auto i : treePreorder) {
        std::cout << i;
    };
    std::cout << std::endl;
    for (auto i : treeInorder)
    {
        std::cout << i;
    };
    std::cout << std::endl;
    for (auto i : treePostorder)
    {
        std::cout << i;
    }
    return 0;
}
