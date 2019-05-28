#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "BinarySearchTree.h"
#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	GenreType
*	@author	�̿���
*	@brief	Manages a genre type and music list which belongs to the genre.
*/
class GenreType
{
public:

	/**
	*	�⺻ ������
	*/
	GenreType()
	{
		genre = "";
	}

	/**
	*	�Ҹ���
	*/
	~GenreType() {}

	/**
	*	@brief	�帣�� ����
	*	@pre	none.
	*	@post	�帣�� ����
	*	@param	�帣��
	*/
	void setGenre(string gen)
	{
		genre = gen;
	}

	/**
	*	@brief	�帣�� ��������
	*	@return	�帣��
	*/
	string getGenre()
	{
		return genre;
	}

	/**
	*	@brief	������ ���������� �ش� �帣 ���� ����Ʈ�� �߰�
	*	@param	������ ��������
	*/
	void AddToGenreMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	������ ���������� �ش� �帣 ���� ����Ʈ���� ����
	*	@param	������ ��������
	*/
	void DeleteInGenreMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// ������ == �����ε�
	bool operator == (GenreType& obj)
	{
		return (genre == obj.genre);
	}

	// ������ < �����ε�
	bool operator < (GenreType& obj)
	{
		return (genre < obj.genre);
	}

	// ������ > �����ε�
	bool operator > (GenreType& obj)
	{
		return (genre > obj.genre);
	}

	// ���Կ�����, ��������� �����ε�
	GenreType& operator=(GenreType& gen)
	{
		genre = gen.genre;
		m_List = gen.m_List;

		return *this;
	}

	// ����Ʈ������ �����ε�
	friend ostream& operator << (ostream& out, GenreType& item)
	{
		out << "\t Genre : " << item.getGenre() << endl;

		return out;
	}

	/**
	*	@brief	�帣 ���� ���ø���Ʈ�� ���ø����̼� �ܰ�� �Ѱ��ֱ�
	*	@return	���ø���Ʈ�� �ּҰ�
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	�帣����Ʈ ���� ����Ʈ�� ���� �Ѱ��ֱ�
	*	@return	����Ʈ�� ����
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string genre; // �帣��
	DoublySortedLinkedList<SimpleType> m_List; // �帣����Ʈ ���� ������ ���Ǹ���Ʈ
};