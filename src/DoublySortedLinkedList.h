#pragma once
#ifndef DOUBLY_SORTED_LINKED_LIST_H
#define DOUBLY_SORTED_LINKED_LIST_H

#include "DoublyIterator.h"

/**
*	@class	Doubly Sorted Linked List
*	@author	�̿���
*	@brief	Manages the list by using doubly node maintaining sorting statement
*/

template <typename T>
struct DoublyNodeType
{
	T data;	///< A data for each node.
	DoublyNodeType* pre;	///< A node pointer to point previous node.
	DoublyNodeType* next;	///< A node pointer to point succeed node.
};

template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;	//Iterator Ŭ������ friend class�� ����
public:

	/**
	*	�⺻ ������
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���
	*/
	~DoublySortedLinkedList() {}

	/**
	*	@brief	����Ʈ ����
	*	@pre	none
	*	@post	����Ʈ ����
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���� �ҷ�����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ���� �ҷ�����
	*	@return	����Ʈ�� ����
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� �߰��ϱ�
	*	@pre	none
	*	@post	����Ʈ�� �߰�
	*/
	void Add(T& item);

	/**
	*	@brief	����Ʈ�� ���ڵ� ����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ���ڵ� ����
	*	@return	������ ��� 1�� ��ȯ
	*/
	int Delete(T item);

	/**
	*	@brief	����Ʈ�� ���ڵ� ���� ��������
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� �ִ� �ش� ���ڵ� ���� ����
	*	@return	������ ��� 1�� ��ȯ
	*/
	int Get(T& item);

	/**
	*	@brief	����Ʈ�� ���ڵ� ������ ��������
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� �ִ� �ش� ���ڵ带 ����Ű�� ������ �ޱ�
	*	@return	������ ��� 1�� ��ȯ
	*/
	int GetPoint(T& item, DoublyNodeType<T>*& point);

	/**
	*	@brief	����Ʈ�� ���ڵ� ���� ����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ���ڵ� ������ �����Ѵ�
	*	@return	������ ��� 1�� ��ȯ
	*/
	int Replace(T item);	//���� ���ڵ� ����

private:
	DoublyNodeType<T>* m_pFirst;	//����Ʈ�� ù��° ��� ����Ű�� ������
	DoublyNodeType<T>* m_pLast;	//����Ʈ�� ������ ��� ����Ű�� ������
	int m_nLength;	//�ش� �ڷᱸ���� ����� �������� ����
};


// Class constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_nLength = 0;
	//m_pFirst�� �Ҵ��Ŵ
	m_pFirst = new DoublyNodeType<T>;
	//m_pLast�� �Ҵ��Ŵ
	m_pLast = new DoublyNodeType<T>;
	//ù��° ��带 ����Ű�� �������� next�� prev���� ����
	m_pFirst->next = m_pLast;
	m_pFirst->pre = NULL;
	//������ ��带 ����Ű�� �������� next�� prev���� ����
	m_pLast->next = NULL;
	m_pLast->pre = m_pFirst;
}

// Initialize list to empty state.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyIterator<T> Itor(*this);
	Itor.Next();
	while (m_nLength > 0)
	{
		node = Itor.m_pCurPointer;	//node�� �ش� itorator�� ���� �����Ͱ��� ����
		Itor.Next();
		Itor.m_pCurPointer->pre = node->pre;
		node->pre->next = Itor.m_pCurPointer;
		delete node;	//�ش� ��� �Ҵ� ����
		m_nLength--;
	}
	m_pFirst = m_pLast = NULL;
}

// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// Add item into this list.
template <typename T>
void DoublySortedLinkedList<T>::Add(T& item)
{
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyIterator<T> Itor(*this);	//���ͷ����� Itor
	node->data = item;
	// ����Ʈ�� �ƹ� �͵� ���� ���
	if (m_nLength == 0)
	{
		node->pre = m_pFirst;
		node->next = m_pLast;
		m_pFirst->next = node;
		m_pLast->pre = node;
		m_nLength++;
	}
	// ����Ʈ�� ������� ���� ���
	else
	{
		for (int i = 0; i < m_nLength; i++)
			Itor.Next();
		//���ο� �����Ͱ� ���� �������� ���� ū �����ͺ��ٵ� ū ���
		if (Itor.GetCurrentNode()->data < node->data)
		{
			node->pre = m_pLast->pre;
			node->next = m_pLast;
			m_pLast->pre->next = node;
			m_pLast->pre = node;
			m_nLength++;
		}
		//���ο� �����Ͱ� ���� �����ͺ��� ���� ���
		else
		{
			Itor.First();	//itorator�� ó������ ���ư�
			for (int i = 0; i < m_nLength; i++)
			{
				Itor.Next();
				if (node->data < Itor.m_pCurPointer->data)
				{
					node->pre = Itor.m_pCurPointer->pre;
					node->next = Itor.m_pCurPointer;
					Itor.m_pCurPointer->pre->next = node;
					Itor.m_pCurPointer->pre = node;
					m_nLength++;
					break; // �߰� �Ŀ� �ݺ��� ����������
				}
			}

		}
	}

}

//Ư�� ������ ����
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyNodeType<T> *node = new DoublyNodeType<T>;
	DoublyIterator<T> Itor(*this);
	for (int i = 0; i < m_nLength; i++)
	{
		Itor.Next();
		if (item == Itor.m_pCurPointer->data)	//����� ���� ã�� �������̸�
		{
			node = Itor.m_pCurPointer;
			Itor.Next();
			Itor.m_pCurPointer->pre = node->pre;
			node->pre->next = Itor.m_pCurPointer;
			delete node;
			m_nLength--;
			return 1;
		}
	}
	return 0;	//������ 0����
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> Itor(*this);
	for (int i = 0; i < m_nLength; i++)
	{
		Itor.Next();
		if (item == Itor.m_pCurPointer->data)
		{
			item = Itor.m_pCurPointer->data;
			return 1;
		}
	}
	return 0;
}

template <typename T>
int DoublySortedLinkedList<T>::GetPoint(T& item, DoublyNodeType<T>*& point)
{
	DoublyIterator<T> Itor(*this);
	for (int i = 0; i < m_nLength; i++)
	{
		Itor.Next();
		if (item == Itor.m_pCurPointer->data)
		{
			point = Itor.m_pCurPointer;
			return 1;
		}
	}
	return 0;
}

//Ư�� ������ ����
template <typename T>
int DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> Itor(*this);
	for (int i = 0; i < m_nLength; i++)
	{
		Itor.Next();
		if (item == Itor.m_pCurPointer->data)
		{
			Itor.m_pCurPointer->data = item;
			return 1;
		}
	}
	return 0;
}

#endif