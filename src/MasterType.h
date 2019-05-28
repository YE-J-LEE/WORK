#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/**
*	@class	MasterType
*	@author	�̿���
*	@brief	Manages a master type and music list which belongs to the master.
*/
class MasterType
{
public:

	/**
	*	�⺻ ������
	*/
	MasterType()
	{
		mPrimaryKey = "";
		mName = "";  ///< ���
		mArtist = "";  ///< ��Ƽ��Ʈ
		mAlbum = "";	  ///< �ٹ�
		mGenre = "";	  ///< �帣
		mLyrics = "";
		mPlayCount = 0;
		mCompany = "";
		mComposer = "";
		mSongwriter = "";
		mBirth = "";
	}

	/**
	*	�Ҹ���
	*/
	~MasterType() {}

	/**
	*	@brief	������ ��������
	*	@return	������
	*/
	string getId()
	{
		return mPrimaryKey;
	}

	/**
	*	@brief	��� ��������
	*	@return	���
	*/
	string getName()
	{
		return mName;
	}

	/**
	*	@brief	��Ƽ��Ʈ�� ��������
	*	@return	��Ƽ��Ʈ��
	*/
	string getArtist()
	{
		return mArtist;
	}

	/**
	*	@brief	�ٹ��� ��������
	*	@return	�ٹ���
	*/
	string getAlbum()
	{
		return mAlbum;
	}

	/**
	*	@brief	�帣�� ��������
	*	@return	�帣��
	*/
	string getGenre()
	{
		return mGenre;
	}

	/**
	*	@brief	�۰ ��������
	*	@return	�۰
	*/
	string getComposer()
	{
		return mComposer;
	}

	/**
	*	@brief	�ۻ簡 ��������
	*	@return	�ۻ簡
	*/
	string getSongwriter()
	{
		return mSongwriter;
	}

	/**
	*	@brief	�Ҽӻ� ��������
	*	@return	�Ҽӻ�
	*/
	string getCompany()
	{
		return mCompany;
	}

	/**
	*	@brief	���Ƚ�� ��������
	*	@return	���Ƚ��
	*/
	int getPlayCount()
	{
		return mPlayCount;
	}

	/**
	*	@brief	������� ��������
	*	@return	�������
	*/
	string getBirth()
	{
		return mBirth;
	}

	/**
	*	@brief	���� ��������
	*	@return	����
	*/
	string getLyrics()
	{
		return mLyrics;
	}

	/**
	*	@brief	Ű����� �뷡 ���� ����
	*	@pre	none.
	*	@post	Ű����� �뷡 ���� ����
	*/
	void setRecordFromKB();

	/**
	*	@brief	������ ����
	*	@pre	none.
	*	@param	������
	*	@post	������ ����
	*/
	void setId(string key)
	{
		mPrimaryKey = key;
	}

	/**
	*	@brief	Ű����� ������ ����
	*	@pre	none.
	*	@post	������ ����
	*/
	void setIdFromKB()
	{
		cout << "ID : ";
		cin >> mPrimaryKey;
	}

	/**
	*	@brief	Ű����� ��� ����
	*	@pre	none.
	*	@post	��� ����
	*/
	void setNameFromKB()
	{
		cout << "Name : ";
		cin >> mName;
	}

	/**
	*	@brief	Ű����� ��Ƽ��Ʈ�� ����
	*	@pre	none.
	*	@post	��Ƽ��Ʈ ����
	*/
	void setArtistFromKB()
	{
		cout << "Artist : ";
		cin >> mArtist;
	}

	/**
	*	@brief	Ű����� �ٹ��� ����
	*	@pre	none.
	*	@post	�ٹ� ����
	*/
	void setAlbumFromKB()
	{
		cout << "Album : ";
		cin >> mAlbum;
	}

	/**
	*	@brief	Ű����� �帣�� ����
	*	@pre	none.
	*	@post	�帣�� ����
	*/
	void setGenreFromKB()
	{
		cout << "Genre : ";
		cin >> mGenre;
	}

	/**
	*	@brief	Ű����� �ۻ簡�� ����
	*	@pre	none.
	*	@post	�ۻ簡�� ����
	*/
	void setSongwriterFromKB()
	{
		cout << "Songwriter : ";
		cin >> mSongwriter;
	}

	/**
	*	@brief	Ű����� �Ҽӻ� ����
	*	@pre	none.
	*	@post	�Ҽӻ� ����
	*/
	void setCompanyFromKB()
	{
		cout << "Company : ";
		cin >> mCompany;
	}

	/**
	*	@brief	Ű����� �۰�� ����
	*	@pre	none.
	*	@post	�۰�� ����
	*/
	void setComposerFromKB()
	{
		cout << "Composer : ";
		cin >> mComposer;
	}

	/**
	*	@brief	Ű����� ������� ����
	*	@pre	none.
	*	@post	������� ����
	*/
	void setBirthFromKB()
	{
		cout << "Birth : ";
		cin >> mBirth;
	}

	/**
	*	@brief	Ű����� ���� ����
	*	@pre	none.
	*	@post	���� ����
	*/
	void setLyricsFromKB()
	{
		string remainder;
		cout << "Lyrics : "; // ���� \n �����ֱ�
		getline(cin, remainder);
		getline(cin, mLyrics);
	}

	/**
	*	@brief	������ �����
	*	@pre	none.
	*	@post	������ (��� + ��Ƽ��Ʈ��) ����
	*/
	void makeId(string name, string artist)
	{
		mPrimaryKey = name + "-" + artist;
	}

	/**
	*	@brief	���Ƚ�� ����
	*	@pre	none.
	*	@post	���Ƚ�� ����
	*/
	void UpPlayCount()
	{
		mPlayCount = mPlayCount + 1;
	}

	// ������ == �����ε�
	bool operator == (MasterType& obj)
	{
		return (mPrimaryKey == obj.mPrimaryKey);
	}

	// ������ < �����ε�
	bool operator < (MasterType& obj)
	{
		return (mPrimaryKey < obj.mPrimaryKey);
	}

	// ������ > �����ε�
	bool operator > (MasterType& obj)
	{
		return (mPrimaryKey > obj.mPrimaryKey);
	}

	// ���Կ�����, ��������� �����ε�
	MasterType& operator=(MasterType& mas);

	/**
	*	@brief	��� �������� ȭ�鿡 ���
	*/
	void DisplayAllRecord();

	/**
	*	@brief	���Ͽ��� ���ڵ� �о����
	*	@pre	��ǥ ���� ���»���
	*	@post	�����͸���Ʈ�� �������� �߰�
	*	@param	fin	���� ������
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� �������� ����
	*	@pre	��ǥ ������ ���»���, ����Ʈ �ʱ�ȭ ����
	*	@post	��ǥ ���Ͽ� ���ο� ���� ������ �Էµȴ�
	*	@param	fout ���� ������
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void WriteDataToFile(ofstream& fout);

	// ����Ʈ������ �����ε�
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
	string mPrimaryKey;	///< ���ȣ Primary key
	string mName; ///< ���
	string mArtist; ///< ��Ƽ��Ʈ
	string mAlbum; ///< �ٹ�
	string mGenre; ///< �帣
	string mComposer; ///< �۰
	string mSongwriter; ///< �ۻ簡
	string mCompany; ///< �Ҽӻ�
	int mPlayCount; ///< ���Ƚ��
	string mBirth; ///< �������
	string mLyrics;  ///< ����
};