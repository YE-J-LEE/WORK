#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
*	@class	SimpleType
*	@author	�̿���
*	@brief	Manages a simple type and music list which belongs to the simple.
*/
class SimpleType
{
public:

	/**
	*	�⺻ ������
	*/
	SimpleType()
	{
		PrimaryKey = "";
		Name = "";
		Lyrics = "";
		PlayCount = 0;
	}

	/**
	*	�Ҹ���
	*/
	~SimpleType() {}

	/**
	*	@brief	������ ���� ����
	*	@pre	none.
	*	@post	������ ���� ����
	*	@param	������ ����
	*/
	void setInfo(string _key, string _name, string _lyrics);

	/**
	*	@brief	������ ����
	*	@pre	none.
	*	@post	������ ����
	*	@param	������
	*/
	void setId(string key)
	{
		PrimaryKey = key;
	}

	/**
	*	@brief	��� ����
	*	@pre	none.
	*	@post	��� ����
	*	@param	���
	*/
	void setName(string name)
	{
		Name = name;
	}

	/**
	*	@brief	������ ��������
	*	@return	������
	*/
	string getPrimaryKey()
	{
		return PrimaryKey;
	}

	/**
	*	@brief	��� ��������
	*	@return	���
	*/
	string getName()
	{
		return Name;
	}

	/**
	*	@brief	���� ��������
	*	@return	����
	*/
	string getLyrics()
	{
		return Lyrics;
	}

	/**
	*	@brief	���Ƚ�� ��������
	*	@return	���Ƚ��
	*/
	int getPlayCount()
	{
		return PlayCount;
	}

	/**
	*	@brief	���Ƚ�� ����
	*	@pre	none.
	*	@post	���Ƚ�� ����
	*/
	void UpPlayCount()
	{
		PlayCount = PlayCount + 1;
	}

	// ������ == �����ε�
	bool operator == (SimpleType& obj)
	{
		return (PrimaryKey == obj.PrimaryKey);
	}

	// ������ < �����ε�
	bool operator < (SimpleType& obj)
	{
		return (PrimaryKey < obj.PrimaryKey);
	}

	// ������ > �����ε�
	bool operator > (SimpleType& obj)
	{
		return (PrimaryKey > obj.PrimaryKey);
	}

	// ���Կ�����, ��������� �����ε�
	SimpleType& operator=(SimpleType& sim);

	// ����Ʈ������ �����ε�
	friend ostream& operator << (ostream& out, SimpleType& item)
	{
		out << "\t ID : " << item.getPrimaryKey() << endl;
		out << "\t Name : " << item.getName() << endl;
		out << "\t Lyrics : " << item.getLyrics() << endl;
		out << "\t PlayCount : " << item.getPlayCount() << endl;

		return out;
	}

	/**
	*	@brief	������ �������� ȭ�鿡 ���
	*/
	void DisplaySimpleRecord();

	/**
	*	@brief	������ �������� ȭ�鿡 ��� (���Ƚ�� ����)
	*/
	void DisplayShallowSimpleRecord();

private:
	string PrimaryKey;
	string Name;
	string Lyrics;
	int PlayCount;
};