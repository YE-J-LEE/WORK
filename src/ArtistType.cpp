#include "ArtistType.h"

// ��Ƽ��Ʈ�� ��� ���� ����
void ArtistType::setInfo(string art, string comp, string songwri, string bir)
{
	artist = art;
	composer = comp;
	songwriter = songwri;
	birth = bir;
}

// ���Կ�����, ��������� �����ε�
ArtistType& ArtistType::operator=(ArtistType& ar)
{
	artist = ar.artist;
	composer = ar.composer;
	songwriter = ar.songwriter;
	birth = ar.birth;

	return *this;
}