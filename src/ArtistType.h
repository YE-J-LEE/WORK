#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	ArtistType
*	@author	�̿���
*	@brief	Manages a artist type and music list which belongs to the artist.
*/
class ArtistType
{
public:

	/**
	*	�⺻ ������
	*/
	ArtistType()
	{
		artist = "";
		birth = "";
		composer = "";
		songwriter = "";
	}

	/**
	*	�Ҹ���
	*/
	~ArtistType() {}

	/**
	*	@brief	��Ƽ��Ʈ ���� ����
	*	@pre	none.
	*	@post	��Ƽ��Ʈ ���� ����
	*	@param	��Ƽ��Ʈ ����
	*/
	void setInfo(string art, string comp, string songwri, string bir);
	
	/**
	*	@brief	��Ƽ��Ʈ�� ����
	*	@pre	none.
	*	@post	��Ƽ��Ʈ�� ����
	*	@param	��Ƽ��Ʈ��
	*/
	void setArtist(string art)
	{
		artist = art;
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
	*	@brief	������� ��������
	*	@return	�������
	*/
	string getBirth()
	{
		return birth;
	}

	/**
	*	@brief	�۰ ��������
	*	@return	�۰
	*/
	string getComposer()
	{
		return composer;
	}

	/**
	*	@brief	�ۻ簡 ��������
	*	@return	�ۻ簡
	*/
	string getSongwriter()
	{
		return songwriter;
	}

	// ������ == �����ε�
	bool operator == (ArtistType& obj)
	{
		return (artist == obj.artist);
	}

	// ������ < �����ε�
	bool operator < (ArtistType& obj)
	{
		return (artist < obj.artist);
	}

	// ������ > �����ε�
	bool operator > (ArtistType& obj)
	{
		return (artist > obj.artist);
	}

	// ���Կ�����, ��������� �����ε�
	ArtistType& operator=(ArtistType& ar);
	

	// ����Ʈ������ �����ε�
	friend ostream& operator << (ostream& out, ArtistType& item)
	{
		out << "\t Artist : " << item.getArtist() << endl;
		out << "\t Birthday : " << item.getBirth() << endl;
		out << "\t Composer : " << item.getComposer() << endl;
		out << "\t Songwriter : " << item.getSongwriter() << endl << endl;

		return out;
	}

	/**
	*	@brief	��Ƽ��Ʈ����Ʈ ���� ���ø���Ʈ�� ���ø����̼� �ܰ�� �Ѱ��ֱ�
	*	@return	���ø���Ʈ�� �ּҰ�
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	��Ƽ��Ʈ����Ʈ ���� ����Ʈ�� ���� �Ѱ��ֱ�
	*	@return	����Ʈ�� ����
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

	/**
	*	@brief	������ ���������� �ش� ��Ƽ��Ʈ ���� ����Ʈ�� �߰�
	*	@param	������ ��������
	*/
	void AddToArtistMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	������ ���������� �ش� ��Ƽ��Ʈ ���� ����Ʈ���� ����
	*	@param	������ ��������
	*/
	void DeleteInArtistMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}


private:
	string artist; // ��Ƽ��Ʈ��
	string birth; // �������
	string composer; // �۰
	string songwriter; // �ۻ簡
	DoublySortedLinkedList<SimpleType> m_List; // ��Ƽ��Ʈ����Ʈ ���� ������ ���Ǹ���Ʈ
};