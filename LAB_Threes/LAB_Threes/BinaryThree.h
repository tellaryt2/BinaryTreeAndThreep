#pragma once
/// <summary>
/// структура узла бинарного дерева
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// данные узла
	/// </summary>
	int Data = 0;
	/// <summary>
	/// указатель на левый узел
	/// </summary>
	BinaryTreeNode* Left = nullptr;
	/// <summary>
	/// указатель на правый узел
	/// </summary>
	BinaryTreeNode* Right = nullptr;
};

/// <summary>
/// структура бинарного дерева
/// </summary>
struct BinaryTree
{
	/// <summary>
	/// корень бинарного дерева
	/// </summary>
	BinaryTreeNode* Root;
};

/// <summary>
/// создание бинарного дерева
/// </summary>
/// <param name="nodeTree">корень дерева</param>
/// <param name="element">добавляемый элемент</param>
/// <returns>корень дерева</returns>
BinaryTreeNode* CreateTree(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// Добавление элемента в дерево
/// </summary>
/// <param name="nodeTree">узел</param>
/// <param name="element">элемент</param>
/// <returns>узел</returns>
BinaryTreeNode* AddElement(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// поиск элемента
/// </summary>
/// <param name="nodeTree">узел</param>
/// <param name="element">элемент</param>
/// <returns>найденный узел</returns>
BinaryTreeNode* SearchElement(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// удаление элемента
/// </summary>
/// <param name="nodeTree">узел</param>
/// <param name="element">элемент</param>
/// <returns>узел</returns>
BinaryTreeNode* DeleteElement(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// поиск максимального элемента в дереве
/// </summary>
/// <param name="nodeTree">узел</param>
/// <returns>узел</returns>
BinaryTreeNode* MaximumElement(BinaryTreeNode* nodeTree);

/// <summary>
/// поиск минимального элемента в дереве
/// </summary>
/// <param name="nodeTree">узел</param>
/// <returns>узел</returns>
BinaryTreeNode* MinimumElement(BinaryTreeNode* nodeTree);

/// <summary>
/// удаление дерева
/// </summary>
/// <param name="nodeTree">узел</param>
void DeleteBinaryTree(BinaryTreeNode* nodeTree);