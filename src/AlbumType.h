#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "SimpleType.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"

/**
*	@class	AlbumType
*	@author	�̿���
*	@brief	Manages a album type and music list which belongs to the album.
*/
class AlbumType
{
public:

	/**
	*	�⺻ ������
	*/
	AlbumType()
	{
		primarykey = "";
		album = "";
		artist = "";
		company = "";
	}

	/**
	*	�Ҹ���
	*/
	~AlbumType() {}

	/**
	*	@brief	�ٹ����� ����
	*	@pre	none.
	*	@post	�ٹ����� ����
	*	@param	�ٹ�����
	*/
	void setInfo(string al, string art, string comp);

	/**
	*	@brief	�ٹ������� ����
	*	@pre	none.
	*	@post	�ٹ������� ����
	*	@param	�ٹ�������
	*/
	void setKey(string key)
	{
		primarykey = key;
	}

	/**
	*	@brief	�ٹ��� ��������
	*	@return	�ٹ���
	*/
	string getAlbum()
	{
		return album;
	}

	/**
	*	@brief	�ٹ������� ��������
	*	@return	�ٹ�������
	*/
	string getAlbumKey()
	{
		return primarykey;
	}

	/**
	*	@brief	��Ƽ��Ʈ�� ��������
	*	@return	��Ƽ��Ʈ��
	*/
	string getArtist()
	{
		return artist;
	}

	/**
	*	@brief	�Ҽӻ�� ��������
	*	@return	�Ҽӻ��
	*/
	string getCompany()
	{
		return company;
	}

	/**
	*	@brief	������ ���������� �ش� �ٹ� ���� ����Ʈ�� �߰�
	*	@param	������ ��������
	*/
	void AddToAlbumMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	������ ���������� �ش� �ٹ� ���� ����Ʈ���� ����
	*	@param	������ ��������
	*/
	void DeleteInAlbumMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// ������ == �����ε�
	bool operator == (AlbumType& obj)
	{
		return (primarykey == obj.primarykey);
	}

	// ������ < �����ε�
	bool operator < (AlbumType& obj)
	{
		return (primarykey < obj.primarykey);
	}

	// ������ > �����ε�
	bool operator > (AlbumType& obj)
	{
		return (primarykey > obj.primarykey);
	}

	// ���Կ�����, ��������� �����ε�
	AlbumType& operator=(AlbumType& al);
	
	// ����Ʈ������ �����ε�
	friend ostream& operator << (ostream& out, AlbumType& item)
	{
		out << "\t AlbumKey : " << item.getAlbumKey() << endl;
		out << "\t Album : " << item.getAlbum() << endl;
		out << "\t Artist : " << item.getArtist() << endl;
		out << "\t Company : " << item.getCompany() << endl << endl;

		return out;
	}
	
	/**
	*	@brief	�ٹ� ���� ���ø���Ʈ�� ���ø����̼� �ܰ�� �Ѱ��ֱ�
	*	@return	���ø���Ʈ�� �ּҰ�
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	�ٹ�����Ʈ ���� ����Ʈ�� ���� �Ѱ��ֱ�
	*	@return	����Ʈ�� ����
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string primarykey; // �ٹ� ������
	string album; // �ٹ���
	string artist; // ��Ƽ��Ʈ��
	string company; // �Ҽӻ��
	DoublySortedLinkedList<SimpleType> m_List; // �ٹ�����Ʈ ���� ������ ���Ǹ���Ʈ
};
