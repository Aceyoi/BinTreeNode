//Сапожников Юрий ИВТ-22
#include<exception>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//Узел дерева
template<typename T>
class TreeNode {  //Название класса
public:
    T value;            // Хранимое значение узла                                                              
    TreeNode<T>* left;  // Указатель на левую ветку
    TreeNode<T>* right; // Указатель на правую ветку

    ///Конструктор без параметров
    TreeNode(T val) : value{ val }, left(nullptr), right(nullptr) {}

    // Удаление всех узлов                                                                                          ///Удаление корня
    void deleteTree() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->deleteTree();  // Рекурсивное удаление левого поддерева
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->deleteTree();  // Рекурсивное удаление правого поддерева
            delete right;
            right = nullptr;
        }
        if (left == nullptr and right == nullptr) {
            value = 0;
        }
    }

    // Симметричный обход (LNR) // Вывод в виде массива
    void traverseInOrder() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->traverseInOrder();  // Левая часть
        }
        cout << value << " ";  // Вывод
        if (right != nullptr) {
            right->traverseInOrder();  // Правая часть
        }
    }

    // Прямой обход (NLR) // Вывод в виде массива
    void traversePreOrder() {
        cout << value << " ";  // Вывод значения текущего узла
        if (left != nullptr) {
            left->traversePreOrder();  // Рекурсивный обход левого поддерева
        }
        if (right != nullptr) {
            right->traversePreOrder();  // Рекурсивный обход правого поддерева
        }
    }

    // Обратный обход (LRN) // Вывод в виде массива
    void traversePostOrder() {
        //if (root == nullptr) return;
        if (left != nullptr) {
            left->traversePostOrder();  // Левая часть
        }
        if (right != nullptr) {
            right->traversePostOrder();  // Правая часть
        }
        cout << value << " ";  // Вывод
    }

    // Подсчёт количества узлов в дереве  
    int countNodes() {
        //if (root == nullptr) return 0;
        int count = 1;  // Считаем корень
        if (left != nullptr) {
            count += left->countNodes();  // Подсчёт в левой части
        }
        if (right != nullptr) {
            count += right->countNodes();  // Подсчёт в правой части
        }
        return count;
    }

    // Определение глубины дерева
    int depth() {
        //if (root == nullptr) return -1;
        int leftDepth = left ? left->depth() : 0;
        int rightDepth = right ? right->depth() : 0;
        return 1 + max(leftDepth, rightDepth);
    }

    // Вспомогательная функция для отображения дерева (Симметричный обход)
    void printTree(int level = 0) const {
        //if (root == nullptr) return;
        if (right != nullptr) {
            right->printTree(level + 1);  // Рекурсивный вывод правого поддерева
        }
        for (int i = 0; i < level; ++i) {
            cout << "    ";  // Отступ для уровня дерева
        }
        cout << value << endl;  // Вывод значения узла
        if (left != nullptr) {
            left->printTree(level + 1);  // Рекурсивный вывод левого поддерева
        }
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//// Вставка значения в дерево  
//template<typename T>
//void popbt(TreeNode<T>* root, T val) {
//    while (TreeNode<T>.empty()) {
//        TreeNode<T>* current = root.front();
//
//        if (root->left == nullptr) {
//            root->left = new TreeNode<T>(val);  // Вставляем в левую ветку
//        }
//        else {
//            popbt(root->left, val);  // Рекурсивная вставка
//        }
//        if (root->right == nullptr) {
//            root->right = new TreeNode<T>(val);  // Вставляем в правую ветку
//        }
//        else {
//            popbt(root->right, val);  // Рекурсивная вставка
//        }
//    }
//}

// Вставка значения в дерево поиска                                                               
template<typename T>
void popbst(TreeNode<T>* root, T val) {
    if (val < root->value) {
        if (root->left == nullptr) {
            root->left = new TreeNode<T>(val);  // Вставляем в левую ветку
        }
        else {
            popbst(root->left, val);  // Рекурсивная вставка
        }
    }
    else {
        if (root->right == nullptr) {
            root->right = new TreeNode<T>(val);  // Вставляем в правую ветку
        }
        else {
            popbst(root->right, val);  // Рекурсивная вставка
        }
    }
}

// Удаление
template<typename T>
void del(TreeNode<T>* root, T val) {
    if (find(root, val) != val) {
        cout << "Не найденно число для удаления" << endl; // Нулевой случай: удаляемый элемент отсутствует
    }
    else {

        // Первый случай: удаляемый элемент не имеет потомков
        // Второй случай: удаляемый элемент имеет одного потомка
        // Третий случай: удаляемый элемент имеет двух потомков


    }
}

// Поиск элемента в дереве
template<typename T>
int find(TreeNode<T>* root, T val){
    if (root == nullptr) {
        return 0;  // Если узел пустой, возвращаем 0 (значение не найдено)
    }
    if (val == root->value) {
        return root->value;  // Если значение найдено, возвращаем текущий значение
    }
    if (val < root->value && root->left != nullptr) {
        return find(root->left, val);  // Ищем в левом поддереве
    }
    if (val > root->value && root->right != nullptr) {
        return find(root->right, val);  // Ищем в правом поддереве
    }
    return 0;  // Значение не найдено
}

// Поверхностное копирование
template<typename T>
TreeNode<T>* easycopy(TreeNode<T>* root) {
    return root;
}

// Поверхностное копирование
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

// Функция для добавления узлов в массив
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
