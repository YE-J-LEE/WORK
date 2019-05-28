#pragma once
#include <iostream>
#include <string>
using namespace std;

#include "SimpleType.h"
#include "DoublySortedLinkedList.h"

/**
*	@class	FolderType
*	@author	이예준
*	@brief	Manages a folder type and music list which belongs to the folder.
*/
class FolderType
{
public:

	/**
	*	기본 생성자
	*/
	FolderType()
	{
		foldername = "";
	}

	/**
	*	소멸자
	*/
	~FolderType() {}

	/**
	*	@brief	키보드로 폴더명 입력받기
	*	@pre	none.
	*	@post	폴더명 설정
	*/
	void setFolderNameFromKB()
	{
		cout << "\t Folder Name : ";
		cin >> foldername;
	}

	/**
	*	@brief	폴더명 가져오기
	*	@return	폴더명
	*/
	string getFolder()
	{
		return foldername;
	}

	/**
	*	@brief	현재 폴더명 출력
	*	@post	폴더명 출력
	*/
	void DisplayFolder()
	{
		cout << "\t Folder Name : " << foldername << endl << endl;
	}

	/**
	*	@brief	간단한 음악정보를 해당 폴더 안의 리스트에 추가
	*	@param	간단한 음악정보
	*/
	void AddToFolderMusicList(SimpleType data)
	{
		m_List.Add(data);
	}

	/**
	*	@brief	간단한 음악정보를 해당 폴더 안의 리스트에서 삭제
	*	@param	간단한 음악정보
	*/
	void DeleteInFolderMusicList(SimpleType data)
	{
		m_List.Delete(data);
	}

	// 연산자 == 오버로딩
	bool operator == (FolderType& obj)
	{
		return (foldername == obj.foldername);
	}

	// 연산자 < 오버로딩
	bool operator < (FolderType& obj)
	{
		return (foldername < obj.foldername);
	}

	// 연산자 > 오버로딩
	bool operator > (FolderType& obj)
	{
		return (foldername > obj.foldername);
	}

	// 대입연산자, 복사생성자 오버로딩
	FolderType& operator=(FolderType& fol)
	{
		foldername = fol.foldername;
		m_List = fol.m_List;

		return *this;
	}

	/**
	*	@brief	폴더 안의 심플리스트를 애플리케이션 단계로 넘겨주기
	*	@return	심플리스트의 주소값
	*/
	DoublySortedLinkedList<SimpleType>* getSimpleList()
	{
		return &m_List;
	}

	/**
	*	@brief	폴더리스트 안의 리스트의 길이 넘겨주기
	*	@return	리스트의 길이
	*/
	int getSimpleLength()
	{
		return m_List.GetLength();
	}

private:
	string foldername; // 폴더명
	DoublySortedLinkedList<SimpleType> m_List; // 폴더리스트 안의 간단한 음악리스트
};
