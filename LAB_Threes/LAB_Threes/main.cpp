#include <iostream>
#include "BinaryThree.h"
#include "Treap.h"
#include <string>

using namespace std;

/// <summary>
/// �� ���� ������� ����� � int ����������
/// </summary>
/// <returns>��������</returns>
int GetInteger(string messege)
{
	cout << messege;
	int value;
	while (!(cin >> value))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "������� �����, � �� ������" << endl;
	}
	return value;
}

/// <summary>
/// �������� ��������� �����
/// </summary>
/// <returns>��������� �����</returns>
int GetRand()
{
	srand(time(nullptr));
	int value = rand() % 100;
	return value;
}

/// <summary>
/// ����� �������� ������
/// </summary>
/// <param name="nodeTree">����</param>
/// <param name="tabCount">���������� ��������</param>
void ShowTreeNew(BinaryTreeNode* nodeTree, int tabCount)
{
	if (nodeTree != nullptr)
	{
		ShowTreeNew(nodeTree->Right, tabCount + 1);
		cout << string(tabCount, '\t') << nodeTree->Data << endl;
		ShowTreeNew(nodeTree->Left, tabCount + 1);
	}
	else
	{
		cout << string(tabCount, '\t') << '_' << endl;
	}
}

/// <summary>
/// ����� ����������� ������
/// </summary>
/// <param name="node">����</param>
/// <param name="tabCount">���������� ��������</param>
void PrintTreapNew(TreapNode* node, int tabCount)
{
	if (node != nullptr)
	{
		
		PrintTreapNew(node->Right, tabCount + 1);
		cout << string(tabCount, '\t') << node->Key << "(" << node->Priority << ")" << endl;
		PrintTreapNew(node->Left, tabCount + 1);
	}
	else
	{
		cout << string(tabCount, '\t') << '_' << endl;
	}
}

/// <summary>
/// ��������� ������� ������ ��������
/// </summary>
/// <param name="searh">������</param>
/// <param name="key">����</param>
/// <param name="command">�������� ������� � case</param>
/// <returns>true or false</returns>
bool MainSearhElement(Treap* searh, int key, int command)
{
	TreapNode* answer = nullptr;
	answer = SearhElementInTreap(searh->Root, key);
	if (answer == nullptr)
	{
		cout << "������ �������� � ������ ���! " << endl;
		return false;
	}
	else
	{
		if (command == 4)
		{
			cout << "������� � ������ " << answer->Key << " ����� ��������� " << answer->Priority << endl;
			return true;
		}
		return true;
	}
}

void MenuBinaryTree()
{
	
	BinaryTree* newTree = new BinaryTree();
	cout << "1 - �������� ��������� ������" << endl;
	cout << "2 - ���������� �������� � �������� ������" << endl;
	cout << "3 - �������� �������� ��������� ������" << endl;
	cout << "4 - ����� ������������ �������� � ������" << endl;
	cout << "5 - ����� ������������� �������� � ������" << endl;
	cout << "6 - ����� �������� � ������" << endl;
	cout << "7 - �������� ��������� ������" << endl;


	while(true)
	{
		
		int command = GetInteger("������� �������: ");
		switch (command)
		{
			case 1:
			{
				int element = GetInteger("������� ������ ������: ");
				newTree->Root = CreateTree(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;

			}

			case 2:
			{
				int element = GetInteger("������� �������, ������� ������ ��������: ");
				AddElement(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 3:
			{
				int element = GetInteger("������� �������, ������� ������ �������: ");
				BinaryTreeNode* deleteNode = DeleteElement(newTree->Root, element);
				cout << "������� ������" << endl;
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 4:
			{
				BinaryTreeNode* minElement = MinimumElement(newTree->Root);
				cout << "����������� ������� � ������: " << minElement->Data << endl;
				break;
			}

			case 5:
			{
				BinaryTreeNode* maxElement = MaximumElement(newTree->Root);
				cout << "������������ ������� � ������: " << maxElement->Data << endl;
				break;
			}

			case 6:
			{
				int element = GetInteger("������� �������, ������� ������ �����: ");
				BinaryTreeNode* search = SearchElement(newTree->Root, element);
				if (search == nullptr)
				{
					cout << "������ �������� ���" << endl;
				}
				else
				{
					cout << "����� ������� ����" << endl;
				}
				break;
			}

			case 7:
			{
				DeleteBinaryTree(newTree->Root);
				cout << "������ �������" << endl;
				return;
			}

			default:
			{
				cout << "������� ����� �� 1 �� 7" << endl;
				break;
			}

		}
	}
}

void MenuTreap()
{
	Treap* newTreap = new Treap();
	cout << "1 - �������� ����������� ������" << endl;
	cout << "2 - ���������� � ���������� ������ (������������������)" << endl;
	cout << "3 - ���������� � ���������� ������ (���������������)" << endl;
	cout << "4 - ����� �������� � ������" << endl;
	cout << "5 - �������� �������� (�����������������)" << endl;
	cout << "6 - �������� �������� (��������������)" << endl;
	cout << "10 - �������� ������" << endl;

	while(true)
	{
		int command = GetInteger("������� �������: ");

		switch (command)
		{
			case 1:
			{
				int key = GetInteger("������� ���� ����� ������: ");
				int priority = GetRand();
				newTreap->Root = CreationOfTreap(newTreap->Root, key, priority, nullptr, nullptr);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 2:
			{
				int key = GetInteger("������� ���� ������� ������ ��������: ");
				int priority = GetRand();
				AddInTreapUnoptimised(newTreap, key, priority);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 3:
			{
				int key = GetInteger("������� ���� ������� ������ ��������: ");
				int priority = GetRand();
				AddInTreapOptomised(newTreap, newTreap->Root, nullptr, key, priority);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 4:
			{
				int key = GetInteger("������� ���� �������� ��������: ");
				MainSearhElement(newTreap, key, 4);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 5:
			{
				int key = GetInteger("������� ���� ��������: ");
				if (MainSearhElement(newTreap, key, 5))
				{
					DeleteTreapUnoptimised(newTreap, key);
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 6:
			{
				int key = GetInteger("������� ���� ���������� ��������: ");
				if (MainSearhElement(newTreap, key, 6))
				{
					DeleteTreapOptimised(newTreap, newTreap->Root, nullptr, key);
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 10:
			{
				DeleteTreap(newTreap->Root);
				cout << "������ �������!" << endl;
				return;
			}

			default:
			{
				cout << "������� ����� �� 1 �� 10" << endl;
				break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	while(true)
	{
		cout << "1 - ���� ������ � �������� �������" << endl;
		cout << "2 - ���� ������ � ���������� �������" << endl;
		cout << "3 - ����� � �� ���������" << endl;

		int command = GetInteger("������� �������: ");
		switch (command)
		{
			case 1:
			{
				MenuBinaryTree();
				break;
			}

			case 2:
			{
				MenuTreap();
				break;
			}

			case 3:
			{
				return 0;
			}

			default:
			{
				cout << "������� ����� �� 1 �� 3" << endl;
				break;
			}
		}
	}

	return 0;
}
