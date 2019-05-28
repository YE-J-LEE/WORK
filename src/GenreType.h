#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "BinarySearchTree.h"
#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	GenreType
*	@author	이예준
*	@brief	Manages a genre type and music list which belongs to the genre.
*/
class GenreType
{
public:

	/**
	*	기본 생성자
	*/
	GenreType()
	{
		genre = "";
	}

	/**
	*	소멸자
	*/
	~GenreType() {}

	/**
	*	@brief	장르명 설정
	*	@pre	none.
	*	@post	장르명 설정
	*	@param	장르명
	*/
	void setGenre(string gen)
	{
		genre = gen;
	}

	/**
	*	@brief	장르명 가져오기
	*	@return	장르명
	*/
	string getGenre()
	{
		return genre;
	}

	/**
	*	@brief	간단한 음악정보를 해당 장르 안의 리스트에 추가
	*	@param	간단한 음악정보
	*/
	void AddToGenreMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	간단한 음악정보를 해당 장르 안의 리스트에서 삭제
	*	@param	간단한 음악정보
	*/
	void DeleteInGenreMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// 연산자 == 오버로딩
	bool operator == (GenreType& obj)
	{
		return (genre == obj.genre);
	}

	// 연산자 < 오버로딩
	bool operator < (GenreType& obj)
	{
		return (genre < obj.genre);
	}

	// 연산자 > 오버로딩
	bool operator > (GenreType& obj)
	{
		return (genre > obj.genre);
	}

	// 대입연산자, 복사생성자 오버로딩
	GenreType& operator=(GenreType& gen)
	{
		genre = gen.genre;
		m_List = gen.m_List;

		return *this;
	}

	// 쉬프트연산자 오버로딩
	friend ostream& operator << (ostream& out, GenreType& item)
	{
		out << "\t Genre : " << item.getGenre() << endl;

		return out;
	}

	/**
	*	@brief	장르 안의 심플리스트를 애플리케이션 단계로 넘겨주기
	*	@return	심플리스트의 주소값
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	장르리스트 안의 리스트의 길이 넘겨주기
	*	@return	리스트의 길이
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string genre; // 장르명
	DoublySortedLinkedList<SimpleType> m_List; // 장르리스트 안의 간단한 음악리스트
};