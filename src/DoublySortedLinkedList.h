#pragma once
#ifndef DOUBLY_SORTED_LINKED_LIST_H
#define DOUBLY_SORTED_LINKED_LIST_H

#include "DoublyIterator.h"

/**
*	@class	Doubly Sorted Linked List
*	@author	이예준
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
	friend class DoublyIterator<T>;	//Iterator 클래스를 friend class로 설정
public:

	/**
	*	기본 생성자
	*/
	DoublySortedLinkedList();

	/**
	*	소멸자
	*/
	~DoublySortedLinkedList() {}

	/**
	*	@brief	리스트 비우기
	*	@pre	none
	*	@post	리스트 비우기
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이 불러오기
	*	@pre	리스트 초기화 상태
	*	@post	리스트의 길이 불러오기
	*	@return	리스트의 길이
	*/
	int GetLength() const;

	/**
	*	@brief	리스트에 추가하기
	*	@pre	none
	*	@post	리스트에 추가
	*/
	void Add(T& item);

	/**
	*	@brief	리스트에 레코드 제거
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 레코드 제거
	*	@return	성공할 경우 1을 반환
	*/
	int Delete(T item);

	/**
	*	@brief	리스트에 레코드 정보 가져오기
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 있는 해당 레코드 정보 복사
	*	@return	성공할 경우 1을 반환
	*/
	int Get(T& item);

	/**
	*	@brief	리스트에 레코드 포인터 가져오기
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 있는 해당 레코드를 가리키는 포인터 받기
	*	@return	성공할 경우 1을 반환
	*/
	int GetPoint(T& item, DoublyNodeType<T>*& point);

	/**
	*	@brief	리스트에 레코드 정보 갱신
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 레코드 정보를 갱신한다
	*	@return	성공할 경우 1을 반환
	*/
	int Replace(T item);	//기존 레코드 갱신

private:
	DoublyNodeType<T>* m_pFirst;	//리스트의 첫번째 노드 가리키는 포인터
	DoublyNodeType<T>* m_pLast;	//리스트의 마지막 노드 가리키는 포인터
	int m_nLength;	//해당 자료구조에 저장된 데이터의 갯수
};


// Class constructor
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_nLength = 0;
	//m_pFirst를 할당시킴
	m_pFirst = new DoublyNodeType<T>;
	//m_pLast를 할당시킴
	m_pLast = new DoublyNodeType<T>;
	//첫번째 노드를 가리키는 포인터의 next와 prev값을 설정
	m_pFirst->next = m_pLast;
	m_pFirst->pre = NULL;
	//마지막 노드를 가리키는 포인터의 next와 prev값을 설정
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
		node = Itor.m_pCurPointer;	//node에 해당 itorator의 현재 포인터값을 넣음
		Itor.Next();
		Itor.m_pCurPointer->pre = node->pre;
		node->pre->next = Itor.m_pCurPointer;
		delete node;	//해당 노드 할당 해제
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
	DoublyIterator<T> Itor(*this);	//이터레이터 Itor
	node->data = item;
	// 리스트에 아무 것도 없는 경우
	if (m_nLength == 0)
	{
		node->pre = m_pFirst;
		node->next = m_pLast;
		m_pFirst->next = node;
		m_pLast->pre = node;
		m_nLength++;
	}
	// 리스트가 비어있지 않은 경우
	else
	{
		for (int i = 0; i < m_nLength; i++)
			Itor.Next();
		//새로운 데이터가 기존 데이터의 가장 큰 데이터보다도 큰 경우
		if (Itor.GetCurrentNode()->data < node->data)
		{
			node->pre = m_pLast->pre;
			node->next = m_pLast;
			m_pLast->pre->next = node;
			m_pLast->pre = node;
			m_nLength++;
		}
		//새로운 데이터가 기존 데이터보다 작은 경우
		else
		{
			Itor.First();	//itorator를 처음으로 돌아감
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
					break; // 추가 후에 반복문 빠져나가기
				}
			}

		}
	}

}

//특정 데이터 삭제
template <typename T>
int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyNodeType<T> *node = new DoublyNodeType<T>;
	DoublyIterator<T> Itor(*this);
	for (int i = 0; i < m_nLength; i++)
	{
		Itor.Next();
		if (item == Itor.m_pCurPointer->data)	//지우기 위해 찾던 데이터이면
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
	return 0;	//없으면 0리턴
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

//특정 데이터 갱신
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