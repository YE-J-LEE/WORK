#include "ArtistType.h"

// 아티스트의 모든 정보 저장
void ArtistType::setInfo(string art, string comp, string songwri, string bir)
{
	artist = art;
	composer = comp;
	songwriter = songwri;
	birth = bir;
}

// 대입연산자, 복사생성자 오버로딩
ArtistType& ArtistType::operator=(ArtistType& ar)
{
	artist = ar.artist;
	composer = ar.composer;
	songwriter = ar.songwriter;
	birth = ar.birth;

	return *this;
}