#ifndef APPLICATION_H
#define APPLICATION_H

#include <Windows.h>
#include <mmsystem.h>
#include <string>
#include <iostream>
#pragma comment(lib, "winmm.lib")
using namespace std;

#include "MasterType.h"
#include "GenreType.h"
#include "ArtistType.h"
#include "AlbumType.h"
#include "SimpleType.h"
#include "BinarySearchTree.h"
#include "FolderType.h"
#include "DoublyIterator.h"

/**
*	@class	Application
*	@author	이예준
*	@brief	Application class for the music player.
*/
class Application
{
public:
	/**
	*	기본 생성자
	*/
	Application();

	/**
	*	소멸자
	*/
	~Application();

	/**
	*	@brief	프로그램 드라이버
	*	@pre	프로그램 실행상태
	*	@post	프로그램 종료
	*/
	void Run();

	/**
	*	@brief	검색 드라이버
	*	@pre	검색 실행상태
	*	@post	검색 종료
	*/
	void Search_Run();

	/**
	*	@brief	폴더관리 드라이버
	*	@pre	폴더관리 실행상태
	*	@post	폴더관리 종료
	*/
	void Folder_Run(); 

	/**
	*	@brief	음악재생 드라이버
	*	@pre	음악재생 실행상태
	*	@post	음악재생 종료
	*/
	void Play_Run();

	/**
	*	@brief	메인명령어를 화면에 출력, 키보드로 입력
	*	@pre	none.
	*	@post	none.
	*	@return	사용자 입력 명령어
	*/
	int GetCommand();

	/**
	*	@brief	검색명령어를 화면에 출력, 키보드로 입력
	*	@pre	none.
	*	@post	none.
	*	@return	사용자 입력 명령어
	*/
	int GetSearchCommand();

	/**
	*	@brief	폴더관리명령어를 화면에 출력, 키보드로 입력
	*	@pre	none.
	*	@post	none.
	*	@return	사용자 입력 명령어
	*/
	int GetFolderCommand();

	/**
	*	@brief	음악재생명령어를 화면에 출력, 키보드로 입력
	*	@pre	none.
	*	@post	none.
	*	@return	사용자 입력 명령어
	*/
	int GetPlayCommand();
	
	/**
	*	@brief	리스트에 새로운 Music 추가
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 새로운 Music 추가
	*	@return	Run -> 1, No -> 0 리턴
	*/
	int AddMusic();

	/**
	*	@brief	파일에서 받아온 정보로 음악 추가
	*	@pre	리스트 초기화 상태
	*	@post	파일에서 받아온 정보로 음악 추가
	*/
	void AddFromFile(MasterType music);

	/**
	*	@brief	리스트에서 Music 하나 삭제
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 일치하는 Music이 있으면 삭제
	*	@return	삭제 했으면 1, 없어서 못했으면 0 리턴
	*/
	int DeleteMusic();

	/**
	*	@brief	리스트에서 하나의 Music 정보 갱신
	*	@pre	리스트 초기화 상태
	*	@post	리스트에 일치하는 Music이 있으면 데이터 갱신
	*	@return	갱신 -> 1, No -> 0 리턴
	*/
	int ReplaceMusic();

	/**
	*	@brief	리스트에서 곡명으로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByName();

	/**
	*	@brief	리스트에서 가사으로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByLyrics();

	/**
	*	@brief	리스트에서 아티스트명으로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByArtist();

	/**
	*	@brief	리스트에서 앨범으로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByAlbum();

	/**
	*	@brief	리스트에서 장르로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	int SearchByGenre();

	/**
	*	@brief	리스트에서 고유값으로 Music 정보 서치
	*	@pre	none
	*	@return	출력되었으면 1, 출력안되면 0 리턴
	*/
	void SearchByPrimaryKey();

	/**
	*	@brief	장르명과 가사가 일치하는 음악정보 출력
	*	@pre	뮤직리스트 초기화 상태
	*	@post	none
	*/
	void RetrieveByGenreNLyrics();

	/**
	*	@brief	앨범명과 가사가 일치하는 음악정보 출력
	*	@pre	뮤직리스트 초기화 상태
	*	@post	none
	*/
	void RetrieveByAlbumNLyrics();
	
	/**
	*	@brief	모든 Music 정보 출력
	*	@pre	none.
	*	@post	none.
	*	@return	Run -> 1, No -> 0 리턴
	*/
	int DisplayAllMusic();

	/**
	*	@brief	읽기 모드로 파일 오픈, 파일에서 모든 데이터 읽기, 데이터로부터 리스트 설정
	*	@pre	파일 닫힌 상태
	*	@post	파일에서 모든 데이터 읽기
	*	@return	Run -> 1, No -> 0 리턴
	*/
	int ReadDataFromFile();

	/**
	*	@brief	쓰기 모드로 파일 Open, 모든 데이터를 파일에 쓰기
	*	@pre	파일이 열려있지 않아야 함
	*	@post	파일에 리스트 데이터 저장
	*	@return	Run -> 1, No -> 0 리턴																																																																																																																																																							``
	*/
	int WriteDataToFile();

	/**
	*	@brief	파일 설명자별 파일을 입력 파일로 열기
	*	@pre	읽기 위한 파일 존재
	*	@post	읽기 위한 파일 오픈
	*	@param	fileName	읽기 위한 파일의 이름
	*	@return	Run -> 1, No -> 0 리턴
	*/
	int OpenReadFile(string& filename);

	/**
	*	@brief	파일 설명자별 파일을 출력 파일로 열기
	*	@pre	리스트 초기화 상태
	*	@post	쓰기 위한 파일 오픈
	*	@param	fileName	쓰기 위한 파일의 이름
	*	@return	Run -> 1, No -> 0 리턴
	*/
	int OpenWriteFile(string& fileName);
	
	/**
	*	@brief	쓰기파일에 마스터리스트의 모든 음악정보 쓰기
	*	@pre	쓰기파일이 열린 상태
	*	@post	쓰기파일에 음악정보 쓰기
	*	@param	마스터리스트의 뿌리, ofstream의 fout
	*/
	void PrintToFile(Node<MasterType>* root, ofstream& fout);

    // =========================================== 폴더관리 함수 ==============================================

	/**
	*	@brief	폴더 생성
	*	@pre	none
	*/
	void AddFolder();

	/**
	*	@brief	폴더 삭제
	*	@pre	none
	*/
	void DeleteFolder();

	/**
	*	@brief	폴더 출력
	*	@pre	none
	*/
	void DisplayFolder();

	/**
	*	@brief	폴더별 음악 출력
	*	@pre	none
	*/
	void DisplayMusicInFolder();

	/**
	*	@brief	폴더 안에 음악 추가
	*	@pre	none
	*/
	void AddMusicInFolder();

	/**
	*	@brief	폴더 안에 음악 삭제
	*	@pre	none
	*/
	void DeleteMusicInFolder();
	// ======================================== 음악재생을 위한 함수 =========================================

	/**
	*	@brief	곡명으로 음악 재생
	*	@pre	none
	*	@post	곡명으로 음악 재생
	*/
	void PlayByName();

	/**
	*	@brief	현재 재생곡 기준으로 다음곡 재생
	*	@pre	현재 곡을 재생중
	*	@post	다음곡 재생
	*/
	void PlayNext();

	/**
	*	@brief	현재 재생곡 기준으로 이전곡 재생
	*	@pre	현재 곡을 재생중
	*	@post	이전곡 재생
	*/
	void PlayPost();

	/**
	*	@brief	현재 곡 재생 중지
	*	@pre	현재 곡을 재생중
	*	@post	재생 중지
	*/
	void PlayStop();

	/**
	*	@brief	동적배열 생성 후 플레이리스트에서 삽입 후 출력
	*	@pre	플레이리스트에 하나 이상 곡이 존재
	*	@post	동적배열 delete
	*/
	void DisplayTop30();

	/**
	*	@brief	동적배열에 음악정보 추가
	*	@pre	플레이리스트에 하나 이상 곡이 존재
	*	@param	동적배열, 추가할 데이터, 배열의 길이
	*	@post	음악정보 추가 후 레퍼런스로 전달
	*/
	void AddToTop(SimpleType*& top, SimpleType data, int& length);

	/**
	*	@brief	동적배열에 재생횟수를 기준으로 추가하기 위한 서치
	*	@pre	none
	*	@param	동적배열, 추가할 데이터, 배열의 시작과 끝 인덱스, 추가할 위치
	*	@post	서치 후 레퍼런스로 전달
	*/
	bool BinarySearch(SimpleType*& info, SimpleType item, int fromLocation, int toLocation, int& m_cur);


private:
	BinarySearchTree<MasterType> SongList;	///< Song List
	DoublySortedLinkedList<SimpleType> PlayList;	///< Play List
	BinarySearchTree<GenreType> GenreList;	///< Genre List
	BinarySearchTree<ArtistType> ArtistList;	///< Artist List
	BinarySearchTree<AlbumType> AlbumList;	///< Album List
	DoublySortedLinkedList<FolderType> FolderList;	///< Folder List
	
	ifstream fin;	///< input file descriptor.
	ofstream fout;	///< output file descriptor.
	int m_Command;	///< current master command number.
	int s_Command;	///< current search command number.
	int f_Command;	///< current folder command number.
	int p_Command;	///< current play command number.
	const string address = ".\\"; ///< default address
	const string wave = ".wav"; ///< default wave 파일 확장자명
	int curindex; ///< Play list 재생하는 데에 있어서 인덱스값 부여
};


#endif // APPLICATION_H

