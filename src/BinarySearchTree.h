#pragma once
#include <iostream>
using namespace std;

// Tree�� �����ϴ� Node (node data, left ������, right ������)
template<class T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

// Binary Search Tree 
template<class T>
class BinarySearchTree
{
public:
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree() { }

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(T item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	void DeleteItem(T item);

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	void RetrieveItem(T& item, bool &found)const;

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	�ش� node�� ����Ű�� �����͸� ��������
	*/
	void GetPoint(T& item, bool &found, Node<T>*& point)const;

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out)const;

	/**
	*	@brief	Tree�� root �����͸� �����Ѵ�.
	*	@pre	none
	*	@post	Tree�� root �����͸� pointer�Ű��������� �������ش�.
	*/
	void GetRoot(Node<T>*& pointer);

private:
	Node<T>* root;		// Node Ÿ���� root
};

template<class T>
void BinarySearchTree<T>::GetRoot(Node<T>*& pointer)
{
	pointer = root;
}

// ������
template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

// Tree�� ����ִ��� Ȯ��
template<class T>
bool BinarySearchTree<T>::IsEmpty()const
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<class T>
bool BinarySearchTree<T>::IsFull()const
{
	Node* room;					// �ӽ��� node�� �����
	try
	{
		room = new Node;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

// Tree�� ���
template<class T>
void BinarySearchTree<T>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree �ʱ�ȭ �Լ� ȣ��
}

// Tree�� node������ �˷���
template<class T>
int BinarySearchTree<T>::GetLength()const
{
	return CountNodes(root);			// node ������ ���� �Լ� ȣ��
}

// Tree�� ���ο� node �߰�
template<class T>
void BinarySearchTree<T>::Add(T item)
{
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
}

// Tree�� node�� ����
template<class T>
void BinarySearchTree<T>::DeleteItem(T item)
{
	Delete(root, item);					// �����ϴ� node �����ϴ� �Լ��� ȣ��
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class T>
void BinarySearchTree<T>::RetrieveItem(T& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class T>
void BinarySearchTree<T>::GetPoint(T& item, bool &found, Node<T>*& point)const
{
	GetPointing(root, item, found, point);		// Tree �˻� �Լ� ȣ��
}

// Tree�� node�� ������ ������ �����
template<class T>
void BinarySearchTree<T>::PrintTree(ostream &out)const
{
	cout << endl;
	PrintInOrderTraversal(root, out);			// InOrder ������� ���
	
}

/////////////////////////////Global functions//////////////////////////
// Tree�� �ʱ�ȭ�ϴ� �Լ�
template<class T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

// Tree�� node ������ ���� �Լ�
template<class T>
int CountNodes(Node<T>* root)
{
	if (root == NULL)		// root ��尡 null�ϰ�� 0�� ����
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// ����� ����, �����ʿ� ���� ����� ȣ��� root�� �ش��ϴ� 1�� ���ؼ� ���� ����
}

// BinarySearchTree�� ���ο� ��� �߰�
template<class T>
void Insert(Node<T>*& root, T item)
{
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new Node<T>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
	}
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
		Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
		Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
}

// ���� ū ���� ã�� �Լ� 
template<class T>
void GetPredecessor(Node<T> *root, T& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<class T>
void DeleteNode(Node<T> *&root)
{
	T item;
	Node<T>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó�� ������
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<class T>
void Delete(Node<T> *&root, T item)
{
	if (item < root->data)				// root��尪���� item��尡 ���� ��
		Delete(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		Delete(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
}

// Tree���� node�� �˻��ϴ� �Լ�
template<class T>
void Retrieve(Node<T> *root, T& item, bool &found)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Retrieve(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Retrieve(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}

// node�� �˻� �� �ش� node�� ����Ű�� �����͸� �����Ѵ�
template<class T>
void GetPointing(Node<T> *root, T& item, bool &found, Node<T>*& point)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		GetPointing(root->left, item, found, point);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		GetPointing(root->right, item, found, point);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		point = root;					// point�� root�� ����Ű�� ���� ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}

// InOrder ������� ����ϴ� �Լ� 
template<class T>
void PrintInOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversal(root->left, out);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		out << root->data;							// root ���
		PrintInOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}


// PreOrder ������� ����ϴ� �Լ�
template<class T>
void PrintPreOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		out << root->data;							// root�� ���� ���
		PrintPreOrderTraversal(root->left, out);	// root�� �������� ���� PreOrder �Լ� �ٽ� ȣ��
		PrintPreOrderTraversal(root->right, out);	// root�� ���������� ���� PreOrder �Լ� �ٽ� ȣ��
	}
}

// PostOrder ������� ����ϴ� �Լ�
template<class T>
void PrintPostOrderTraversal(Node<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintPostOrderTraversal(root->left, out);	// root�� �������� ���� �ٽ� PostOrder �Լ� ȣ��
		PrintPostOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� PostOrder �Լ� ȣ��
		out << root->data;							// root�� �� ���
	}
}