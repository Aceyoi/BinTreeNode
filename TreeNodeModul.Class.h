//���������� ���� ���-22
#include<exception>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//���� ������
template<typename T>
class TreeNode {  //�������� ������
public:
    T value;            // �������� �������� ����                                                              
    TreeNode<T>* left;  // ��������� �� ����� �����
    TreeNode<T>* right; // ��������� �� ������ �����

    ///����������� ��� ����������
    TreeNode(T val) : value{ val }, left(nullptr), right(nullptr) {}

    // �������� ���� �����                                                                                          ///�������� �����
    void deleteTree() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->deleteTree();  // ����������� �������� ������ ���������
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->deleteTree();  // ����������� �������� ������� ���������
            delete right;
            right = nullptr;
        }
        if (left == nullptr and right == nullptr) {
            value = 0;
        }
    }

    // ������������ ����� (LNR) // ����� � ���� �������
    void traverseInOrder() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->traverseInOrder();  // ����� �����
        }
        cout << value << " ";  // �����
        if (right != nullptr) {
            right->traverseInOrder();  // ������ �����
        }
    }

    // ������ ����� (NLR) // ����� � ���� �������
    void traversePreOrder() {
        cout << value << " ";  // ����� �������� �������� ����
        if (left != nullptr) {
            left->traversePreOrder();  // ����������� ����� ������ ���������
        }
        if (right != nullptr) {
            right->traversePreOrder();  // ����������� ����� ������� ���������
        }
    }

    // �������� ����� (LRN) // ����� � ���� �������
    void traversePostOrder() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->traversePostOrder();  // ����� �����
        }
        if (right != nullptr) {
            right->traversePostOrder();  // ������ �����
        }
        cout << value << " ";  // �����
    }

    // ������� ���������� ����� � ������  
    int countNodes() {
        //if (root == nullptr) return 0;
        int count = 1;  // ������� ������
        if (left != nullptr) {
            count += left->countNodes();  // ������� � ����� �����
        }
        if (right != nullptr) {
            count += right->countNodes();  // ������� � ������ �����
        }
        return count;
    }

    // ����������� ������� ������
    int depth() {
        //if (root == nullptr) return -1;
        int leftDepth = left ? left->depth() : 0;
        int rightDepth = right ? right->depth() : 0;
        return 1 + max(leftDepth, rightDepth);
    }

    // ��������������� ������� ��� ����������� ������ (������������ �����)
    void printTree(int level = 0) const {
        //if (root == nullptr) return;
        if (right != nullptr) {
            right->printTree(level + 1);  // ����������� ����� ������� ���������
        }
        for (int i = 0; i < level; ++i) {
            cout << "    ";  // ������ ��� ������ ������
        }
        cout << value << endl;  // ����� �������� ����
        if (left != nullptr) {
            left->printTree(level + 1);  // ����������� ����� ������ ���������
        }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// ������� �������� � ������  
//template<typename T>
//void popbt(TreeNode<T>* root, T val) {
//    while (TreeNode<T>.empty()) {
//        TreeNode<T>* current = root.front();
//
//        if (root->left == nullptr) {
//            root->left = new TreeNode<T>(val);  // ��������� � ����� �����
//        }
//        else {
//            popbt(root->left, val);  // ����������� �������
//        }
//        if (root->right == nullptr) {
//            root->right = new TreeNode<T>(val);  // ��������� � ������ �����
//        }
//        else {
//            popbt(root->right, val);  // ����������� �������
//        }
//    }
//}

// ������� �������� � ������ ������                                                               
template<typename T>
void popbst(TreeNode<T>* root, T val) {
    if (val < root->value) {
        if (root->left == nullptr) {
            root->left = new TreeNode<T>(val);  // ��������� � ����� �����
        }
        else {
            popbst(root->left, val);  // ����������� �������
        }
    }
    else {
        if (root->right == nullptr) {
            root->right = new TreeNode<T>(val);  // ��������� � ������ �����
        }
        else {
            popbst(root->right, val);  // ����������� �������
        }
    }
}

// ��������
template<typename T>
void del(TreeNode<T>* root, T val) {
    if (find(root, val) != val) {
        cout << "�� �������� ����� ��� ��������" << endl; // ������� ������: ��������� ������� �����������
    }
    else {

        // ������ ������: ��������� ������� �� ����� ��������
        // ������ ������: ��������� ������� ����� ������ �������
        // ������ ������: ��������� ������� ����� ���� ��������


    }
}

// ����� �������� � ������
template<typename T>
int find(TreeNode<T>* root, T val){
    if (root == nullptr) {
        return 0;  // ���� ���� ������, ���������� 0 (�������� �� �������)
    }
    if (val == root->value) {
        return root->value;  // ���� �������� �������, ���������� ������� ��������
    }
    if (val < root->value && root->left != nullptr) {
        return find(root->left, val);  // ���� � ����� ���������
    }
    if (val > root->value && root->right != nullptr) {
        return find(root->right, val);  // ���� � ������ ���������
    }
    return 0;  // �������� �� �������
}

// ������������� �����������
template<typename T>
TreeNode<T>* easycopy(TreeNode<T>* root) {
    return root;
}

// ������������� �����������
template<typename T>
TreeNode<T>* deepcopy(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode<T>* newTreeNode = new TreeNode(root);
    newTreeNode->left = deepcopy(root->left);
    newTreeNode->right = deepcopy(root->right);
    return newTreeNode;
}

// ������� ��� ���������� ����� � ������
template<typename T>
void fillArrayInOrder(TreeNode<T>* root,vector<T>* arr) {
    if (root->left != nullptr) {
        fillArrayInOrder(root->left, arr);
    }
    arr.push_back(root->value);
    if (root->right != nullptr) {
        fillArrayInOrder(root->right, arr);
    }
}
