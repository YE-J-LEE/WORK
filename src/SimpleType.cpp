#include "SimpleType.h"

// 간단한 음악정보 설정
void SimpleType::setInfo(string _key, string _name, string _lyrics)
{
	PrimaryKey = _key;
	Name = _name;
	Lyrics = _lyrics;
}

// 대입연산자, 복사생성자 오버로딩
SimpleType& SimpleType::operator=(SimpleType& sim)
{
	PrimaryKey = sim.PrimaryKey;
	Name = sim.Name;
	Lyrics = sim.Lyrics;
	PlayCount = sim.PlayCount;

	return *this;
}

// 간단한 음악정보 출력
void SimpleType::DisplaySimpleRecord()
{
	cout << "\t ID : " << PrimaryKey << endl;
	cout << "\t Name : " << Name << endl;
	cout << "\t Lyrics : " << Lyrics << endl;
	cout << "\t PlayCount : " << PlayCount << endl << endl;
}

// 간단한 음악정보 출력 (재생횟수 제외)
void SimpleType::DisplayShallowSimpleRecord()
{
	cout << "\t ID : " << PrimaryKey << endl;
	cout << "\t Name : " << Name << endl;
	cout << "\t Lyrics : " << Lyrics << endl << endl;
}