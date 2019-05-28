#include "MasterType.h"

// Ű����� ���� ���� ����
void MasterType::setRecordFromKB()
{
	setNameFromKB();
	setArtistFromKB();
	makeId(mName, mArtist);
	setAlbumFromKB();
	setGenreFromKB();
	setBirthFromKB();
	setComposerFromKB();
	setSongwriterFromKB();
	setCompanyFromKB();
	setLyricsFromKB();
}

// ���Կ�����, ��������� �����ε�
MasterType& MasterType::operator=(MasterType& mas)
{
	mPrimaryKey = mas.mPrimaryKey;
	mName = mas.mName;
	mArtist = mas.mArtist;
	mAlbum = mas.mAlbum;
	mGenre = mas.mGenre;
	mComposer = mas.mComposer;
	mSongwriter = mas.mSongwriter;
	mCompany = mas.mCompany;
	mBirth = mas.mBirth;
	mPlayCount = mas.mPlayCount;
	mLyrics = mas.mLyrics;

	return *this;
}

// ��� �������� ȭ�鿡 ���
void MasterType::DisplayAllRecord()
{
	cout << "\t ID : " << mPrimaryKey << endl;
	cout << "\t Name : " << mName << endl;
	cout << "\t Artist : " << mArtist << endl;
	cout << "\t Album : " << mAlbum << endl;
	cout << "\t Genre : " << mGenre << endl;
	cout << "\t Composer : " << mComposer << endl;
	cout << "\t Songwriter : " << mSongwriter << endl;
	cout << "\t Company : " << mCompany << endl;
	cout << "\t Birth : " << mBirth << endl;
	cout << "\t PlayCount : " << mPlayCount << endl;
	cout << "\t Lyrics : " << mLyrics << endl << endl;
}

// ���Ͽ��� �������� �о����
void MasterType::ReadDataFromFile(ifstream& fin)
{
	fin >> mName >> mArtist >> mAlbum >> mGenre >> mComposer >> mSongwriter
		>> mCompany >> mBirth;
	makeId(mName, mArtist);
	getline(fin, mLyrics);
}

// ���Ͽ� �������� ����
void MasterType::WriteDataToFile(ofstream& fout)
{
	fout << mName << " " << mArtist << " " << mAlbum << " " << mGenre << " " << mComposer << " " << mSongwriter <<
		" " << mCompany << " " << mBirth << " ";
	fout << mLyrics << endl;
}