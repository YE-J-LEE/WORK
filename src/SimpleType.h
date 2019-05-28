#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
*	@class	SimpleType
*	@author	이예준
*	@brief	Manages a simple type and music list which belongs to the simple.
*/
class SimpleType
{
public:

	/**
	*	기본 생성자
	*/
	SimpleType()
	{
		PrimaryKey = "";
		Name = "";
		Lyrics = "";
		PlayCount = 0;
	}

	/**
	*	소멸자
	*/
	~SimpleType() {}

	/**
	*	@brief	간단한 정보 설정
	*	@pre	none.
	*	@post	간단한 정보 설정
	*	@param	간단한 정보
	*/
	void setInfo(string _key, string _name, string _lyrics);

	/**
	*	@brief	고유값 설정
	*	@pre	none.
	*	@post	고유값 설정
	*	@param	고유값
	*/
	void setId(string key)
	{
		PrimaryKey = key;
	}

	/**
	*	@brief	곡명 설정
	*	@pre	none.
	*	@post	곡명 설정
	*	@param	곡명
	*/
	void setName(string name)
	{
		Name = name;
	}

	/**
	*	@brief	고유값 가져오기
	*	@return	고유값
	*/
	string getPrimaryKey()
	{
		return PrimaryKey;
	}

	/**
	*	@brief	곡명 가져오기
	*	@return	곡명
	*/
	string getName()
	{
		return Name;
	}

	/**
	*	@brief	가사 가져오기
	*	@return	가사
	*/
	string getLyrics()
	{
		return Lyrics;
	}

	/**
	*	@brief	재생횟수 가져오기
	*	@return	재생횟수
	*/
	int getPlayCount()
	{
		return PlayCount;
	}

	/**
	*	@brief	재생횟수 증가
	*	@pre	none.
	*	@post	재생횟수 증가
	*/
	void UpPlayCount()
	{
		PlayCount = PlayCount + 1;
	}

	// 연산자 == 오버로딩
	bool operator == (SimpleType& obj)
	{
		return (PrimaryKey == obj.PrimaryKey);
	}

	// 연산자 < 오버로딩
	bool operator < (SimpleType& obj)
	{
		return (PrimaryKey < obj.PrimaryKey);
	}

	// 연산자 > 오버로딩
	bool operator > (SimpleType& obj)
	{
		return (PrimaryKey > obj.PrimaryKey);
	}

	// 대입연산자, 복사생성자 오버로딩
	SimpleType& operator=(SimpleType& sim);

	// 쉬프트연산자 오버로딩
	friend ostream& operator << (ostream& out, SimpleType& item)
	{
		out << "\t ID : " << item.getPrimaryKey() << endl;
		out << "\t Name : " << item.getName() << endl;
		out << "\t Lyrics : " << item.getLyrics() << endl;
		out << "\t PlayCount : " << item.getPlayCount() << endl;

		return out;
	}

	/**
	*	@brief	간단한 음악정보 화면에 출력
	*/
	void DisplaySimpleRecord();

	/**
	*	@brief	간단한 음악정보 화면에 출력 (재생횟수 제외)
	*/
	void DisplayShallowSimpleRecord();

private:
	string PrimaryKey;
	string Name;
	string Lyrics;
	int PlayCount;
};