#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "SimpleType.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"

/**
*	@class	AlbumType
*	@author	이예준
*	@brief	Manages a album type and music list which belongs to the album.
*/
class AlbumType
{
public:

	/**
	*	기본 생성자
	*/
	AlbumType()
	{
		primarykey = "";
		album = "";
		artist = "";
		company = "";
	}

	/**
	*	소멸자
	*/
	~AlbumType() {}

	/**
	*	@brief	앨범정보 설정
	*	@pre	none.
	*	@post	앨범정보 설정
	*	@param	앨범정보
	*/
	void setInfo(string al, string art, string comp);

	/**
	*	@brief	앨범고유값 설정
	*	@pre	none.
	*	@post	앨범고유값 설정
	*	@param	앨범고유값
	*/
	void setKey(string key)
	{
		primarykey = key;
	}

	/**
	*	@brief	앨범명 가져오기
	*	@return	앨범명
	*/
	string getAlbum()
	{
		return album;
	}

	/**
	*	@brief	앨범고유값 가져오기
	*	@return	앨범고유값
	*/
	string getAlbumKey()
	{
		return primarykey;
	}

	/**
	*	@brief	아티스트명 가져오기
	*	@return	아티스트명
	*/
	string getArtist()
	{
		return artist;
	}

	/**
	*	@brief	소속사명 가져오기
	*	@return	소속사명
	*/
	string getCompany()
	{
		return company;
	}

	/**
	*	@brief	간단한 음악정보를 해당 앨범 안의 리스트에 추가
	*	@param	간단한 음악정보
	*/
	void AddToAlbumMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	간단한 음악정보를 해당 앨범 안의 리스트에서 삭제
	*	@param	간단한 음악정보
	*/
	void DeleteInAlbumMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// 연산자 == 오버로딩
	bool operator == (AlbumType& obj)
	{
		return (primarykey == obj.primarykey);
	}

	// 연산자 < 오버로딩
	bool operator < (AlbumType& obj)
	{
		return (primarykey < obj.primarykey);
	}

	// 연산자 > 오버로딩
	bool operator > (AlbumType& obj)
	{
		return (primarykey > obj.primarykey);
	}

	// 대입연산자, 복사생성자 오버로딩
	AlbumType& operator=(AlbumType& al);
	
	// 쉬프트연산자 오버로딩
	friend ostream& operator << (ostream& out, AlbumType& item)
	{
		out << "\t AlbumKey : " << item.getAlbumKey() << endl;
		out << "\t Album : " << item.getAlbum() << endl;
		out << "\t Artist : " << item.getArtist() << endl;
		out << "\t Company : " << item.getCompany() << endl << endl;

		return out;
	}
	
	/**
	*	@brief	앨범 안의 심플리스트를 애플리케이션 단계로 넘겨주기
	*	@return	심플리스트의 주소값
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	앨범리스트 안의 리스트의 길이 넘겨주기
	*	@return	리스트의 길이
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string primarykey; // 앨범 고유값
	string album; // 앨범명
	string artist; // 아티스트명
	string company; // 소속사명
	DoublySortedLinkedList<SimpleType> m_List; // 앨범리스트 안의 간단한 음악리스트
};
