#include "SimpleType.h"

// ������ �������� ����
void SimpleType::setInfo(string _key, string _name, string _lyrics)
{
	PrimaryKey = _key;
	Name = _name;
	Lyrics = _lyrics;
}

// ���Կ�����, ��������� �����ε�
SimpleType& SimpleType::operator=(SimpleType& sim)
{
	PrimaryKey = sim.PrimaryKey;
	Name = sim.Name;
	Lyrics = sim.Lyrics;
	PlayCount = sim.PlayCount;

	return *this;
}

// ������ �������� ���
void SimpleType::DisplaySimpleRecord()
{
	cout << "\t ID : " << PrimaryKey << endl;
	cout << "\t Name : " << Name << endl;
	cout << "\t Lyrics : " << Lyrics << endl;
	cout << "\t PlayCount : " << PlayCount << endl << endl;
}

// ������ �������� ��� (���Ƚ�� ����)
void SimpleType::DisplayShallowSimpleRecord()
{
	cout << "\t ID : " << PrimaryKey << endl;
	cout << "\t Name : " << Name << endl;
	cout << "\t Lyrics : " << Lyrics << endl << endl;
}