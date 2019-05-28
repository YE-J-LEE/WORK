#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	ArtistType
*	@author	이예준
*	@brief	Manages a artist type and music list which belongs to the artist.
*/
class ArtistType
{
public:

	/**
	*	기본 생성자
	*/
	ArtistType()
	{
		artist = "";
		birth = "";
		composer = "";
		songwriter = "";
	}

	/**
	*	소멸자
	*/
	~ArtistType() {}

	/**
	*	@brief	아티스트 정보 설정
	*	@pre	none.
	*	@post	아티스트 정보 설정
	*	@param	아티스트 정보
	*/
	void setInfo(string art, string comp, string songwri, string bir);
	
	/**
	*	@brief	아티스트명 설정
	*	@pre	none.
	*	@post	아티스트명 설정
	*	@param	아티스트명
	*/
	void setArtist(string art)
	{
		artist = art;
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
	*	@brief	생년월일 가져오기
	*	@return	생년월일
	*/
	string getBirth()
	{
		return birth;
	}

	/**
	*	@brief	작곡가 가져오기
	*	@return	작곡가
	*/
	string getComposer()
	{
		return composer;
	}

	/**
	*	@brief	작사가 가져오기
	*	@return	작사가
	*/
	string getSongwriter()
	{
		return songwriter;
	}

	// 연산자 == 오버로딩
	bool operator == (ArtistType& obj)
	{
		return (artist == obj.artist);
	}

	// 연산자 < 오버로딩
	bool operator < (ArtistType& obj)
	{
		return (artist < obj.artist);
	}

	// 연산자 > 오버로딩
	bool operator > (ArtistType& obj)
	{
		return (artist > obj.artist);
	}

	// 대입연산자, 복사생성자 오버로딩
	ArtistType& operator=(ArtistType& ar);
	

	// 쉬프트연산자 오버로딩
	friend ostream& operator << (ostream& out, ArtistType& item)
	{
		out << "\t Artist : " << item.getArtist() << endl;
		out << "\t Birthday : " << item.getBirth() << endl;
		out << "\t Composer : " << item.getComposer() << endl;
		out << "\t Songwriter : " << item.getSongwriter() << endl << endl;

		return out;
	}

	/**
	*	@brief	아티스트리스트 안의 심플리스트를 애플리케이션 단계로 넘겨주기
	*	@return	심플리스트의 주소값
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	아티스트리스트 안의 리스트의 길이 넘겨주기
	*	@return	리스트의 길이
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

	/**
	*	@brief	간단한 음악정보를 해당 아티스트 안의 리스트에 추가
	*	@param	간단한 음악정보
	*/
	void AddToArtistMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	간단한 음악정보를 해당 아티스트 안의 리스트에서 삭제
	*	@param	간단한 음악정보
	*/
	void DeleteInArtistMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}


private:
	string artist; // 아티스트명
	string birth; // 생년월일
	string composer; // 작곡가
	string songwriter; // 작사가
	DoublySortedLinkedList<SimpleType> m_List; // 아티스트리스트 안의 간단한 음악리스트
};