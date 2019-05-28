#include "AlbumType.h"

// �ٹ�Ÿ�Կ� ���� �޾ƿ���
void AlbumType::setInfo(string al, string art, string comp)
{
	album = al;
	artist = art;
	company = comp;
	primarykey = art + "-" + al;
}

// ���Կ�����, ��������� �����ε�
AlbumType& AlbumType::operator=(AlbumType& al)
{
	album = al.album;
	m_List = al.m_List;
	artist = al.artist;
	company = al.company;
	primarykey = al.primarykey;

	return *this;
}
