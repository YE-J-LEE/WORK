#include "AlbumType.h"

// 앨범타입에 정보 받아오기
void AlbumType::setInfo(string al, string art, string comp)
{
	album = al;
	artist = art;
	company = comp;
	primarykey = art + "-" + al;
}

// 대입연산자, 복사생성자 오버로딩
AlbumType& AlbumType::operator=(AlbumType& al)
{
	album = al.album;
	m_List = al.m_List;
	artist = al.artist;
	company = al.company;
	primarykey = al.primarykey;

	return *this;
}
