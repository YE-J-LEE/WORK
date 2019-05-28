#include "MasterType.h"

// 키보드로 음악 정보 설정
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

// 대입연산자, 복사생성자 오버로딩
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

// 모든 음악정보 화면에 출력
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

// 파일에서 음악정보 읽어오기
void MasterType::ReadDataFromFile(ifstream& fin)
{
	fin >> mName >> mArtist >> mAlbum >> mGenre >> mComposer >> mSongwriter
		>> mCompany >> mBirth;
	makeId(mName, mArtist);
	getline(fin, mLyrics);
}

// 파일에 음악정보 쓰기
void MasterType::WriteDataToFile(ofstream& fout)
{
	fout << mName << " " << mArtist << " " << mAlbum << " " << mGenre << " " << mComposer << " " << mSongwriter <<
		" " << mCompany << " " << mBirth << " ";
	fout << mLyrics << endl;
}