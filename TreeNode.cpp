//Сапожников Юрий ИВТ-22
#include <iostream>
#include <cassert>
#include <vector>
#include "TreeNodeModul.Class.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");


    TreeNode<int>* test = new TreeNode<int>(5);   // Создание дерева для проверки
    popbst(test, 4);
    popbst(test, 6);
	assert(test->countNodes() == 3);
	assert(test->depth() == 2);
	assert(find(test, 4) == 4);
	assert(find(test, 6) == 6);
	assert(find(test, 5) == 5);
	assert(find(test, 7) == 0);
    popbst(test, 7);
    popbst(test, 8);
    popbst(test, 9);
    popbst(test, 10);
	assert(find(test, 10) == 10);
	test->deleteTree();
    delete test;
	


    TreeNode<int>* tree = new TreeNode<int>(10);  // Создаем корень дерева с значением 10
    popbst(tree, 5);
    popbst(tree, 20);
    popbst(tree, 3);
    popbst(tree, 7);
    popbst(tree, 15);
    popbst(tree, 30);

    // Прямой обход
    cout << "Прямой обход (NLR): ";
    tree->traversePreOrder();
    cout << endl;

    // Симметричный обход
    cout << "Симметричный обход (LNR): ";
    tree->traverseInOrder();
    cout << endl;

    // Обратный обход
    cout << "Обратный обход (LRN): ";
    tree->traversePostOrder();  
    cout << endl << endl;

    // Вывод дерева в ввиде массива // Симметричный обход (сортировка)
    
    // Вывод дерева в ввиде массива // Прямой обход

    // Удаление узла

    // Копирование 

    // Копирование глубокое

    // Подсчёт количества узлов
    cout << "Количество узлов: " << tree->countNodes() << endl;

    // Глубина дерева
    cout << "Глубина дерева: " << tree->depth() << endl << endl;

    // Поиск элемента в дереве
    int X = 5; // Число для поиска

    if (find(tree, X) == X) { cout << "Значение " << X << " найдено в дереве." << endl << endl;}
    else { cout << "Значение " << X << " не найдено в дереве." << endl << endl;}

    // Вывод дерева в виде дерева
    cout << "Дерево: " << endl;
    tree->printTree();
    cout << endl;


    tree->deleteTree();
    delete tree;


    // Симметричный обход (LNR) и вывод узлов в массив
    vector<int>* array;
    fillArrayInOrder(tree, array);

    //// Вывод массива
    //cout << "Дерево в виде массива (симметричный обход): ";
    //for (int val : array) {
    //    cout << val << " ";
    //}
    //cout << endl;

    return 0;
}


//Вид дерева
//              root(10)
//            /         \
//           /           \
//          /             \
//       LNode(5)         RNode(20)
//       /    \            /   \
//      /      \          /     \
//     /        \        /       \
//  LNode(3)  RNode(7) LNode(15) RNode(30)
//
// Строгое(Совершенное)