#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/**
*	@class	MasterType
*	@author	이예준
*	@brief	Manages a master type and music list which belongs to the master.
*/
class MasterType
{
public:

	/**
	*	기본 생성자
	*/
	MasterType()
	{
		mPrimaryKey = "";
		mName = "";  ///< 곡명
		mArtist = "";  ///< 아티스트
		mAlbum = "";	  ///< 앨범
		mGenre = "";	  ///< 장르
		mLyrics = "";
		mPlayCount = 0;
		mCompany = "";
		mComposer = "";
		mSongwriter = "";
		mBirth = "";
	}

	/**
	*	소멸자
	*/
	~MasterType() {}

	/**
	*	@brief	고유값 가져오기
	*	@return	고유값
	*/
	string getId()
	{
		return mPrimaryKey;
	}

	/**
	*	@brief	곡명 가져오기
	*	@return	곡명
	*/
	string getName()
	{
		return mName;
	}

	/**
	*	@brief	아티스트명 가져오기
	*	@return	아티스트명
	*/
	string getArtist()
	{
		return mArtist;
	}

	/**
	*	@brief	앨범명 가져오기
	*	@return	앨범명
	*/
	string getAlbum()
	{
		return mAlbum;
	}

	/**
	*	@brief	장르명 가져오기
	*	@return	장르명
	*/
	string getGenre()
	{
		return mGenre;
	}

	/**
	*	@brief	작곡가 가져오기
	*	@return	작곡가
	*/
	string getComposer()
	{
		return mComposer;
	}

	/**
	*	@brief	작사가 가져오기
	*	@return	작사가
	*/
	string getSongwriter()
	{
		return mSongwriter;
	}

	/**
	*	@brief	소속사 가져오기
	*	@return	소속사
	*/
	string getCompany()
	{
		return mCompany;
	}

	/**
	*	@brief	재생횟수 가져오기
	*	@return	재생횟수
	*/
	int getPlayCount()
	{
		return mPlayCount;
	}

	/**
	*	@brief	생년월일 가져오기
	*	@return	생년월일
	*/
	string getBirth()
	{
		return mBirth;
	}

	/**
	*	@brief	가사 가져오기
	*	@return	가사
	*/
	string getLyrics()
	{
		return mLyrics;
	}

	/**
	*	@brief	키보드로 노래 정보 설정
	*	@pre	none.
	*	@post	키보드로 노래 정보 설정
	*/
	void setRecordFromKB();

	/**
	*	@brief	고유값 설정
	*	@pre	none.
	*	@param	고유값
	*	@post	고유값 설정
	*/
	void setId(string key)
	{
		mPrimaryKey = key;
	}

	/**
	*	@brief	키보드로 고유값 설정
	*	@pre	none.
	*	@post	고유값 설정
	*/
	void setIdFromKB()
	{
		cout << "ID : ";
		cin >> mPrimaryKey;
	}

	/**
	*	@brief	키보드로 곡명 설정
	*	@pre	none.
	*	@post	곡명 설정
	*/
	void setNameFromKB()
	{
		cout << "Name : ";
		cin >> mName;
	}

	/**
	*	@brief	키보드로 아티스트명 설정
	*	@pre	none.
	*	@post	아티스트 설정
	*/
	void setArtistFromKB()
	{
		cout << "Artist : ";
		cin >> mArtist;
	}

	/**
	*	@brief	키보드로 앨범명 설정
	*	@pre	none.
	*	@post	앨범 설정
	*/
	void setAlbumFromKB()
	{
		cout << "Album : ";
		cin >> mAlbum;
	}

	/**
	*	@brief	키보드로 장르명 설정
	*	@pre	none.
	*	@post	장르명 설정
	*/
	void setGenreFromKB()
	{
		cout << "Genre : ";
		cin >> mGenre;
	}

	/**
	*	@brief	키보드로 작사가명 설정
	*	@pre	none.
	*	@post	작사가명 설정
	*/
	void setSongwriterFromKB()
	{
		cout << "Songwriter : ";
		cin >> mSongwriter;
	}

	/**
	*	@brief	키보드로 소속사 설정
	*	@pre	none.
	*	@post	소속사 설정
	*/
	void setCompanyFromKB()
	{
		cout << "Company : ";
		cin >> mCompany;
	}

	/**
	*	@brief	키보드로 작곡가명 설정
	*	@pre	none.
	*	@post	작곡가명 설정
	*/
	void setComposerFromKB()
	{
		cout << "Composer : ";
		cin >> mComposer;
	}

	/**
	*	@brief	키보드로 생년월일 설정
	*	@pre	none.
	*	@post	생년월일 설정
	*/
	void setBirthFromKB()
	{
		cout << "Birth : ";
		cin >> mBirth;
	}

	/**
	*	@brief	키보드로 가사 설정
	*	@pre	none.
	*	@post	가사 설정
	*/
	void setLyricsFromKB()
	{
		string remainder;
		cout << "Lyrics : "; // 앞의 \n 지워주기
		getline(cin, remainder);
		getline(cin, mLyrics);
	}

	/**
	*	@brief	고유값 만들기
	*	@pre	none.
	*	@post	고유값 (곡명 + 아티스트명) 설정
	*/
	void makeId(string name, string artist)
	{
		mPrimaryKey = name + "-" + artist;
	}

	/**
	*	@brief	재생횟수 증가
	*	@pre	none.
	*	@post	재생횟수 증가
	*/
	void UpPlayCount()
	{
		mPlayCount = mPlayCount + 1;
	}

	// 연산자 == 오버로딩
	bool operator == (MasterType& obj)
	{
		return (mPrimaryKey == obj.mPrimaryKey);
	}

	// 연산자 < 오버로딩
	bool operator < (MasterType& obj)
	{
		return (mPrimaryKey < obj.mPrimaryKey);
	}

	// 연산자 > 오버로딩
	bool operator > (MasterType& obj)
	{
		return (mPrimaryKey > obj.mPrimaryKey);
	}

	// 대입연산자, 복사생성자 오버로딩
	MasterType& operator=(MasterType& mas);

	/**
	*	@brief	모든 음악정보 화면에 출력
	*/
	void DisplayAllRecord();

	/**
	*	@brief	파일에서 레코드 읽어오기
	*	@pre	목표 파일 오픈상태
	*	@post	마스터리스트에 음악정보 추가
	*	@param	fin	파일 설명자
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 음악정보 쓰기
	*	@pre	목표 파일이 오픈상태, 리스트 초기화 상태
	*	@post	목표 파일에 새로운 음악 정보가 입력된다
	*	@param	fout 파일 설명자
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void WriteDataToFile(ofstream& fout);

	// 쉬프트연산자 오버로딩
	friend ostream& operator << (ostream& out, MasterType& item)
	{
		out << "\t ID : " << item.getId() << endl;
		out << "\t Name : " << item.getName() << endl;
		out << "\t Artist : " << item.getArtist() << endl;
		out << "\t Album : " << item.getAlbum() << endl;
		out << "\t Genre : " << item.getGenre() << endl;
		out << "\t Composer : " << item.getComposer() << endl;
		out << "\t Songwriter : " << item.getSongwriter() << endl;
		out << "\t Company : " << item.getCompany() << endl;
		out << "\t Birth : " << item.getBirth() << endl;
		out << "\t PlayCount : " << item.getPlayCount() << endl;
		out << "\t Lyrics : " << item.getLyrics() << endl;

		return out;
	}

private:
	string mPrimaryKey;	///< 곡번호 Primary key
	string mName; ///< 곡명
	string mArtist; ///< 아티스트
	string mAlbum; ///< 앨범
	string mGenre; ///< 장르
	string mComposer; ///< 작곡가
	string mSongwriter; ///< 작사가
	string mCompany; ///< 소속사
	int mPlayCount; ///< 재생횟수
	string mBirth; ///< 생년월일
	string mLyrics;  ///< 가사
};