#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	FolderType
*	@author	�̿���
*	@brief	Manages a folder type and music list which belongs to the folder.
*/
class FolderType
{
public:

	/**
	*	�⺻ ������
	*/
	FolderType()
	{
		foldername = "";
	}

	/**
	*	�Ҹ���
	*/
	~FolderType() {}

	/**
	*	@brief	Ű����� ������ �Է¹ޱ�
	*	@pre	none.
	*	@post	������ ����
	*/
	void setFolderNameFromKB()
	{
		cout << "\t Folder Name : ";
		cin >> foldername;
	}

	/**
	*	@brief	������ ��������
	*	@return	������
	*/
	string getFolder()
	{
		return foldername;
	}

	/**
	*	@brief	���� ������ ���
	*	@post	������ ���
	*/
	void DisplayFolder()
	{
		cout << "\t Folder Name : " << foldername << endl << endl;
	}

	/**
	*	@brief	������ ���������� �ش� ���� ���� ����Ʈ�� �߰�
	*	@param	������ ��������
	*/
	void AddToFolderMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	������ ���������� �ش� ���� ���� ����Ʈ���� ����
	*	@param	������ ��������
	*/
	void DeleteInFolderMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// ������ == �����ε�
	bool operator == (FolderType& obj)
	{
		return (foldername == obj.foldername);
	}

	// ������ < �����ε�
	bool operator < (FolderType& obj)
	{
		return (foldername < obj.foldername);
	}

	// ������ > �����ε�
	bool operator > (FolderType& obj)
	{
		return (foldername > obj.foldername);
	}

	// ���Կ�����, ��������� �����ε�
	FolderType& operator=(FolderType& fol)
	{
		foldername = fol.foldername;
		m_List = fol.m_List;

		return *this;
	}

	/**
	*	@brief	���� ���� ���ø���Ʈ�� ���ø����̼� �ܰ�� �Ѱ��ֱ�
	*	@return	���ø���Ʈ�� �ּҰ�
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	��������Ʈ ���� ����Ʈ�� ���� �Ѱ��ֱ�
	*	@return	����Ʈ�� ����
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string foldername; // ������
	DoublySortedLinkedList<SimpleType> m_List; // ��������Ʈ ���� ������ ���Ǹ���Ʈ
};
