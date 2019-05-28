#include "Application.h"
#include <string>
using namespace std;

// 기본설정 생성자
Application::Application()
{
	m_Command = -1;	// 메인 커맨드값 초기화
	s_Command = -1; // 검색 커맨드값 초기화
	f_Command = -1; // 폴더 커맨드값 초기화
	p_Command = -1; // 재생 커맨드값 초기화
	curindex = -1; // 재생 인덱스 초기화
}

// 소멸자
Application::~Application()
{
	SongList.MakeEmpty();	//리스트 비우기
}

// 프로그램 드라이버
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:	 // 음악 추가 및 정렬
			AddMusic();
			break;
		case 2:	 // 리스트에서 음악 삭제
			DeleteMusic();
			break;
		case 3:	 // 리스트에 있는 음악 갱신 - 삭제 후 추가
			ReplaceMusic();
			break;
		case 4:	 // 리스트에 있는 음악 정보 검색
			cout << "\t 음악검색으로 넘어갑니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Search_Run();
			break;
		case 5:	 // 폴더 관리
			cout << "\t 폴더관리로 넘어갑니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Folder_Run();
			break;
		case 6:	 // 음악 재생
			cout << "\t 음악재생으로 넘어갑니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Play_Run();
			break;
		case 7:	 // 파일에 음악정보 입력
			WriteDataToFile();
			break;
		case 8:	 // 파일에서 음악정보 받아오기
			ReadDataFromFile();
			break;
		case 0: // 프로그램 종료
			system("pause");
			exit(0);
			break;
		default: // 예외 처리
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 검색 드라이버
void Application::Search_Run()
{
	while (1)
	{
		s_Command = GetSearchCommand();

		switch (s_Command)
		{
		case 1:	 // 곡명으로 검색
			SearchByName();
			break;
		case 2:	 // 가사로 검색
			SearchByLyrics();
			break;
		case 3:	 // 아티스트명으로 검색
			SearchByArtist();
			break;
		case 4:	 // 앨범명으로 검색
			SearchByAlbum();
			break;
		case 5:	 // 장르명으로 검색
			SearchByGenre();
			break;
		case 6:	 // 고유값으로 검색
			SearchByPrimaryKey();
			break;
		case 7:	 // 장르 + 가사로 검색
			RetrieveByGenreNLyrics();
			break;
		case 8:	 // 앨범 + 가사로 검색
			RetrieveByAlbumNLyrics();
			break;
		case 0: // 메인 드라이버으로 이동
			system("CLS");
			Run();
			break;
		default: // 예외처리
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 폴더관리 드라이버
void Application::Folder_Run()
{
	while (1)
	{
		f_Command = GetFolderCommand();

		switch (f_Command)
		{
		case 1:	 // 폴더 생성
			AddFolder();
			break;
		case 2:	 // 폴더 삭제
			DeleteFolder();
			break;
		case 3:	 // 폴더에 음악 추가
			AddMusicInFolder();
			break;
		case 4:	 // 폴더에서 음악 삭제
			DeleteMusicInFolder();
			break;
		case 5:	 // 음악 재생 드라이버로 이동
			cout << "\t 음악재생으로 넘어갑니다." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Play_Run();
			break;
		case 6:	 // 폴더별 음악 화면에 출력
			DisplayMusicInFolder();
			break;
		case 0: // 메인 드라이버로 이동
			system("CLS");
			Run();
			break;
		default: // 예외 처리
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 음악재생 드라이버
void Application::Play_Run()
{
	while (1)
	{
		p_Command = GetPlayCommand();

		switch (p_Command)
		{
		case 1:	 // 곡명으로 음악 재생
			PlayByName();
			break;
		case 2:	 // 다음 곡 재생
			PlayNext();
			break;
		case 3:	 // 이전 곡 재생
			PlayPost();
			break;
		case 4:	 // 곡 재생 중지
			PlayStop();
			break;
		case 5:	 // Top 30 출력
			DisplayTop30();
			break;
		case 0: // 메인 드라이버로 이동
			PlaySound(NULL, NULL, NULL);
			system("CLS");
			Run();
			break;
		default: // 예외 처리
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 메인 명령어 출력 후 입력 받기
int Application::GetCommand()
{
	int command;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << endl << endl;
	cout << "      ■■■■■ ♪♬ Music Player ♪♬ ■■■■■" << endl;
	cout << "      ■                                        ■" << endl;
	cout << "      ■    1 : 음악 추가                       ■" << endl;
	cout << "      ■    2 : 음악 삭제                       ■" << endl;
	cout << "      ■    3 : 음악 갱신                       ■" << endl;
	cout << "      ■    4 : 음악 검색                       ■" << endl;
	cout << "      ■    5 : 폴더 관리                       ■" << endl;
	cout << "      ■    6 : 음악 재생                       ■" << endl;
	cout << "      ■    7 : 파일에 저장                     ■" << endl;
	cout << "      ■    8 : 파일에서 불러오기               ■" << endl;
	cout << "      ■    0 : 프로그램 종료                   ■" << endl;
	cout << "      ■                                        ■" << endl;
	cout << "      ■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// 검색 명령어 출력 후 입력 받기
int Application::GetSearchCommand()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	int command;
	cout << endl << endl;
	cout << "      ■■■■■ ♪♬ Music Search ♪♬ ■■■■■" << endl;
	cout << "      ■                                        ■" << endl;
	cout << "      ■    1 : 곡명으로 검색                   ■" << endl;
	cout << "      ■    2 : 가사로 검색                     ■" << endl;
	cout << "      ■    3 : 아티스트로 검색                 ■" << endl;
	cout << "      ■    4 : 앨범으로 검색                   ■" << endl;
	cout << "      ■    5 : 장르로 검색                     ■" << endl;
	cout << "      ■    6 : 고유값으로 검색                 ■" << endl;
	cout << "      ■    7 : 장르 + 가사로 검색              ■" << endl;
	cout << "      ■    8 : 앨범 + 가사로 검색              ■" << endl;
	cout << "      ■    0 : 이 창 나가기                    ■" << endl;
	cout << "      ■                                        ■" << endl;
	cout << "      ■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// 폴더 명령어 출력 후 입력 받기
int Application::GetFolderCommand()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	int command;
	cout << endl << endl;
	cout << "      ■■■■■  ♪♬ Folder Management ♪♬ ■■■■■" << endl;
	cout << "      ■                                              ■" << endl;
	cout << "      ■         1 : 폴더 생성                        ■" << endl;
	cout << "      ■         2 : 폴더 삭제                        ■" << endl;
	cout << "      ■         3 : 폴더에 음악 추가                 ■" << endl;
	cout << "      ■         4 : 폴더에서 음악 삭제               ■" << endl;
	cout << "      ■         5 : 폴더에서 음악 재생               ■" << endl;
	cout << "      ■         6 : 폴더별 음악 출력                 ■" << endl;
	cout << "      ■         0 : 이 창 나가기                     ■"  << endl;
	cout << "      ■                                              ■" << endl;
	cout << "      ■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// 재생 명령어 출력 후 입력 받기
int Application::GetPlayCommand()
{
	int command;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "\n\t=============== Play List ============== " << endl;
	string name;
	DoublyIterator<SimpleType> iter(PlayList);
	iter.Next();
	int length = PlayList.GetLength();
	for (int i = 0; i < length; i++)
	{
		cout << " \n\t " << i + 1 << ". " <<
			iter.GetCurrentNode()->data.getName();
		cout << endl;
		iter.Next();
	}
	cout << "\t========================================" << endl;
	cout << "\n\t========================================" << endl;
	cout << "\t           1. 곡명 재생      ▶           " << endl;
	cout << "\t           2. 다음 곡 재생  ▶▶          " << endl;
	cout << "\t           3. 이전 곡 재생  ◀◀          " << endl;
	cout << "\t           4. 재생 정지      ■           " << endl;
	cout << "\t           5. Top 30                      " << endl;
	cout << "\t           0. 이 창 나가기                " << endl;
	cout << "\t========================================" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// 음악 추가
int Application::AddMusic()
{
	MasterType music; // 모든 음악정보를 담는 객체
	bool found = false; // Retrieve에 필요한 bool 선언

	// 중복검사를 위한 while문
	while (1)
	{
		music.setRecordFromKB(); // 키보드로부터 모든 음악정보 입력받기
		
		SongList.RetrieveItem(music, found); // 중복 여부 판단
		if (found) // 중복될 경우
		{
			cout << "Primary key값이 중복됩니다." << endl;
			continue;
		}
		else // 중복되지 않는 경우 while문 빠져나가기
			break;
	}

	SongList.Add(music); // 중복되지 않는 음악정보를 마스터리스트에 추가
	SimpleType simple; // 간단한 음악정보를 담는 객체
	GenreType data1; // 장르리스트에 추가할 객체
	ArtistType data2; // 아티스트리스트에 추가할 객체
	AlbumType data3; // 앨범리스트에 추가할 객체

	simple.setInfo(music.getId(), music.getName(), music.getLyrics()); // 모든 정보가 있는 music 객체에서 간단한 정보 가져오기
	PlayList.Add(simple); // 재생리스트에 음악 추가
	data1.setGenre(music.getGenre()); // 장르명 가져오기
	data2.setInfo(music.getArtist(), music.getComposer(), music.getSongwriter(), music.getBirth()); // 아티스트 관련 정보 가져오기
	data3.setInfo(music.getAlbum(), music.getArtist(), music.getCompany()); // 앨범 관련 정보 가져오기

	Node<GenreType>* glink = NULL; // 특정 장르객체에 접근하기 위한 포인터
	Node<ArtistType>* arlink = NULL; // 특정 아티스트객체에 접근하기 위한 포인터
	Node<AlbumType>* allink = NULL; // 특정 앨범객체에 접근하기 위한 포인터

	found = false; // false로 초기화

	GenreList.RetrieveItem(data1, found); // 장르 존재 여부
	if (found == true) // 장르리스트에 이미 존재하는 경우
	{
		GenreList.GetPoint(data1, found, glink); // 해당 장르객체에 접근
		glink->data.AddToGenreMusicList(simple); // 장르 안 리스트에 추가
	}
	else if(found == false || GenreList.IsEmpty()) // 장르리스트에 존재하지 않는 경우
	{
		GenreList.Add(data1); // 새로운 장르 추가
		GenreList.GetPoint(data1, found, glink); // 해당 장르객체에 접근
		glink->data.AddToGenreMusicList(simple); // 장르 안 리스트에 추가
	}

	ArtistType dummy; // 동명이인을 위한 더미 객체 선언
	dummy.setArtist(music.getArtist()); // 아티스트명 설정

	ArtistList.RetrieveItem(dummy, found);
	if (found == true) // 아티스트리스트에 이미 존재하는 경우
	{
		if (dummy.getBirth() != data2.getBirth()) // 생년월일이 다르다면 동명이인
		{
			string New = data2.getArtist() + "(동명이인)"; // 동명이인 설정
			dummy.setArtist(New);
			ArtistList.RetrieveItem(dummy, found);
			if (found == true)
				cout << "\t 동명이인이 많아 작업을 진행하기 힘듭니다." << endl; // 동명이인이 많은 경우 프로그램 종료
			else if (found == false) // 또 동명이인인 경우
			{
				data2.setArtist(New);
				ArtistList.Add(data2); // 동명이인으로 새롭게 아티스트 추가
				ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
				arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
			}
		}
		else // 생년월일도 같다면 같은 아티스트
		{
			ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
			arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
		}
	}
	else if (found == false || ArtistList.IsEmpty()) // 아티스트리스트에 존재하지 않는 경우 (새로운 아티스트)
	{
		ArtistList.Add(data2); // 새로운 아티스트 추가
		ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
		arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
	}

	AlbumList.RetrieveItem(data3, found);
	if (found == true) // 앨범리스트에 이미 존재하는 경우
	{
		AlbumList.GetPoint(data3, found, allink); // 해당 앨범객체에 접근
		allink->data.AddToAlbumMusicList(simple); // 앨범 안 리스트에 추가
	}
	else if (found == false || ArtistList.IsEmpty()) // 앨범리스트에 존재하지 않는 경우
	{
		AlbumList.Add(data3); // 새로운 앨범 추가
		AlbumList.GetPoint(data3, found, allink); // 해당 앨범객체에 접근
		allink->data.AddToAlbumMusicList(simple); // 앨범 안 리스트에 추가
	}


	DisplayAllMusic(); // current list 출력

	system("pause");
	cout << endl;
	system("CLS");

	return 1;
}

// 리스트에서 음악 삭제
int Application::DeleteMusic()
{
	if (!SongList.IsEmpty()) // 삭제 이전에 곡이 존재해야 한다
	{
		MasterType music; // 삭제할 마스터리스트 객체
		GenreType data1; // 삭제할 장르리스트 객체
		ArtistType data2; // 삭제할 아티스트리스트 객체
		AlbumType data3; // 삭제할 앨범리스트 객체
		SimpleType simple; // 삭제할 간단한리스트 객체
		Node<GenreType>* glink = NULL; // 특정 장르객체에 접근하기 위한 포인터
		Node<ArtistType>* arlink = NULL; // 특정 아티스트객체에 접근하기 위한 포인터
		Node<AlbumType>* allink = NULL; // 특정 앨범객체에 접근하기 위한 포인터
		string AlbumKey; // 앨범 고유값 설정을 위한 임시변수 선언

		cout << "\t 삭제할 곡의 고유값(ID)을 입력해주세요" << endl;
		music.setIdFromKB(); // 삭제할 고유값 입력받기
		simple.setId(music.getId()); // 간단한 정보에 곡번호 넘겨주기

		bool found = false; // Retrieve를 위한 bool 초기화
		SongList.RetrieveItem(music, found);
		if (found == true) // 해당 곡번호와 일치하는 음악이 존재하는 경우
		{
			SongList.DeleteItem(music); // 마스터리스트에서 삭제
			PlayList.Delete(simple); // 재생리스트에서 삭제

			data1.setGenre(music.getGenre()); // 장르명 넘겨주기
			GenreList.RetrieveItem(data1, found); // 장르 깊은 복사
			GenreList.GetPoint(data1, found, glink); // 해당 장르 객체에 접근

			if (data1.getSimpleLength() == 1) // 만약 장르에 하나밖에 없다면 
				GenreList.DeleteItem(data1); // 아예 장르객체 자체를 삭제
			else // 하나 이상이라면
				glink->data.DeleteInGenreMusicList(simple); // 직접 해당 장르 안의 리스트에서 삭제

			data2.setArtist(music.getArtist()); // 아티스트명 넘겨주기
			ArtistList.RetrieveItem(data2, found); // 아티스트 깊은 복사
			ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근

			if (data2.getSimpleLength() == 1) // 만약 아티스트에 하나밖에 없다면 
				ArtistList.DeleteItem(data2); // 아예 아티스트객체 자체를 삭제
			else // 하나 이상이라면
				arlink->data.DeleteInArtistMusicList(simple); // 직접 해당 아티스트 안의 리스트에서 삭제

			AlbumKey = music.getArtist() + "-" + music.getAlbum(); // 앨범 고유값 생성

			data3.setKey(AlbumKey);// 앨범명 넘겨주기
			AlbumList.RetrieveItem(data3, found); // 앨범 깊은 복사
			AlbumList.GetPoint(data3, found, allink); // 해당 앨범 객체에 접근

			if (data3.getSimpleLength() == 1) // 만약 앨범에 하나밖에 없다면
				AlbumList.DeleteItem(data3); // 아예 앨범객체 자체를 삭제
			else // 하나 이상이라면
				allink->data.DeleteInAlbumMusicList(simple); // 직접 해당 앨범 안의 리스트에서 삭제

			cout << "\t 삭제가 완료되었습니다!!!" << endl;

			// current list 출력
			DisplayAllMusic();
		}
		else if (found == false) // 해당 고유값과 일치하는 음악이 없는 경우
			cout << "\t 해당 고유값은 존재하지 않습니다." << endl;

		system("pause");
		cout << endl;
		system("CLS");

		return 1;
	}
	else // 아예 곡이 존재하지 않는 경우
	{
		cout << "\t 삭제할 음악이 없습니다." << endl;
		system("pause");
		cout << endl;
		system("CLS");

		return 0;
	}
}

// 리스트에서 음악정보 갱신
int Application::ReplaceMusic()
{
	// 어차피 다시 정렬되기 때문에 삭제 후에 추가하는 것과 같다
	DeleteMusic();
	cout << "새로 추가할 곡의 정보를 입력해주세요" << endl;
	AddMusic();
	
	system("CLS");


	return 1;
}

// 마스터리스트에서 해당 곡명이 포함되는 음악정보 나열
int Application::SearchByName()
{
	string name; // 곡명 입력받을 임시변수
	cout << "\t 찾고싶은 곡명을 입력해주세요" << endl;
	cout << "\t Name : ";
	cin >> name;
	MasterType dummy; // 자세한 정보 출력을 위한 더미 객체 선언
	DoublyIterator<SimpleType> iter(PlayList); // 간단한 정보가 있는 플레이리스트를 위한 반복자 선언
	bool found = false; // Retrieve를 위한 bool변수 초기화선언
	iter.Next();
	int length = PlayList.GetLength(); 
	cout << "\n\t====== Search By Name=====" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		// 곡명의 일부가 포함되어도 출력한다
		if ((iter.GetCurrentNode()->data.getName()).find(name) != -1)
		{
			dummy.setId(iter.GetCurrentNode()->data.getPrimaryKey());
			SongList.RetrieveItem(dummy, found);
			dummy.DisplayAllRecord();
			cout << endl;
		}
		iter.Next();
	}

	system("pause");
	cout << endl;
	system("CLS");

	
	return 1;
}

// 마스터리스트에서 해당 가사 한 소절이 포함되는 음악정보 나열
int Application::SearchByLyrics()
{
	string lyrics; // 가사 입력받을 임시변수
	cout << "\t 찾고싶은 가사 한 소절을 입력해주세요" << endl;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	MasterType dummy; // 자세한 정보 출력을 위한 더미 객체 선언
	DoublyIterator<SimpleType> iter(PlayList); // 간단한 정보가 있는 플레이리스트를 위한 반복자 선언
	bool found = false; // Retrieve를 위한 bool변수 초기화선언
	iter.Next();
	int length = PlayList.GetLength();
	cout << "\n\t====== Search By Lyrics=====" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		// 가사의 일부가 포함되어도 출력한다
		if ((iter.GetCurrentNode()->data.getLyrics()).find(lyrics) != -1)
		{
			dummy.setId(iter.GetCurrentNode()->data.getPrimaryKey());
			SongList.RetrieveItem(dummy, found);
			dummy.DisplayAllRecord();
			cout << endl;
		}
		iter.Next();
	}

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// 아티스트리스트 안 리스트에서의 고유값을 바탕으로
// 마스터리스트에서 해당 아티스트의 음악들의 자세한 정보 출력
int Application::SearchByArtist()
{
	cout << "\n\t====== Current Artist ===== " << endl << endl;
	ArtistList.PrintTree(cout); // 화면에 현재 존재하는 아티스트 출력
	string artist; // 아티스트명을 입력받을 임시변수
	bool found = false; // Retrieve를 위한 bool 초기화
	cout << "\n\t 찾고싶은 아티스트를 정확하게 입력해주세요" << endl;
	cout << "\t Artist : ";
	cin >> artist;
	ArtistType dummy; // 아티스트를 찾기 위한 더미 객체 선언
	dummy.setArtist(artist); // 아티스트 설정
	ArtistList.RetrieveItem(dummy, found); // 검색과 동시에 깊은 복사
	Node<ArtistType>* point = NULL; // 특정 아티스트객체에 접근하기 위한 포인터 변수
	DoublySortedLinkedList<SimpleType>* list = NULL; // 아티스트 안 리스트를 받아올 포인터 변수
	MasterType detail; // 자세한 정보를 담을 더미 객체
	
	if (found == true) // 해당 아티스트가 있는 경우
	{
		cout << "\n\t====== Search By Artist=====" << endl << endl;
		ArtistList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // 아티스트 안 리스트 받아오기
		DoublyIterator<SimpleType> iter(*list); // 간단한 리스트의 반복자 선언
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 간단한 리스트 안의 고유값을 바탕으로
			SongList.RetrieveItem(detail, found); // 마스터리스트에서 깊은 복사를 통해
			detail.DisplayAllRecord(); // 화면에 출력한다
			cout << endl;
			iter.Next();
		}
	}
	else // 해당 아티스트가 없는 경우
	{
		cout << "\t 해당 아티스트는 존재하지 않습니다." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// 앨범리스트 안 리스트에서의 고유값을 바탕으로
// 마스터리스트에서 해당 앨범의 음악들의 자세한 음악정보를 출력
int Application::SearchByAlbum()
{
	cout << "\n\t====== Current Album ===== " << endl << endl;
	AlbumList.PrintTree(cout); // 화면에 현재 존재하는 앨범 출력
	string AlbumKey; // 앨범 고유값을 입력받을 임시변수
	bool found = false; // Retrieve를 위한 bool 초기화
	cout << "\n\t 찾고싶은 앨범의 고유값을 정확하게 입력해주세요" << endl;
	cout << "\t Album Key : ";
	cin >> AlbumKey;
	AlbumType dummy; // 앨범을 찾기 위한 더미 객체 선언
	dummy.setKey(AlbumKey); // 앨범키 설정
	AlbumList.RetrieveItem(dummy, found); // 검색과 동시에 깊은 복사
	Node<AlbumType>* point = NULL; // 특정 앨범객체에 접근하기 위한 포인터 변수
	DoublySortedLinkedList<SimpleType>* list = NULL; // 앨범 안 수록곡 리스트를 받아올 포인터 변수
	MasterType detail; // 자세한 정보를 담을 더미 객체

	if (found == true) // 해당 앨범이 있는 경우
	{
		cout << "\n\t====== Search By Album=====" << endl << endl;
		AlbumList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // 앨범 안 리스트 받아오기
		DoublyIterator<SimpleType> iter(*list); // 간단한 리스트의 반복자 선언
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 간단한 리스트 안의 고유값을 바탕으로
			SongList.RetrieveItem(detail, found); // 마스터리스트에서 깊은 복사를 통해
			detail.DisplayAllRecord(); // 화면에 출력한다
			cout << endl;
			iter.Next();
		}
	}
	else if (found == false) // 해당 앨범이 없는 경우
	{
		cout << "\t 해당 앨범은 존재하지 않습니다." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");

	return 1;
}

// 장르리스트 안 리스트에서의 장르명을 바탕으로
// 마스터리스트에서 해당 장르 안의 음악의 자세한 정보를 출력
int Application::SearchByGenre()
{
	cout << "\n\t====== Current Genre ===== " << endl << endl;
	GenreList.PrintTree(cout); // 화면에 현재 존재하는 장르 출력
	string genre; // 장르명을 입력받을 임시변수
	bool found = false; // Retrieve를 위한 bool 초기화
	cout << "\n\t 찾고싶은 장르명을 입력해주세요" << endl;
	cout << "\t Genre : ";
	cin >> genre;
	GenreType dummy; // 장르를 찾기 위한 더미 객체 선언
	dummy.setGenre(genre); // 장르 설정
	GenreList.RetrieveItem(dummy, found); // 검색과 동시에 깊은 복사
	Node<GenreType>* point = NULL; // 특정 장르객체에 접근하기 위한 포인터 변수
	DoublySortedLinkedList<SimpleType>* list = NULL; // 장르 안 수록곡 리스트를 받아올 포인터 변수
	MasterType detail; // 자세한 정보를 담을 더미 객체

	if (found == true) // 해당 장르가 있는 경우
	{
		cout << "\n\t====== Search By Genre=====" << endl << endl;
		GenreList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // 장르 안 리스트 받아오기
		DoublyIterator<SimpleType> iter(*list); // 간단한 리스트의 반복자 선언
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 간단한 리스트 안의 고유값을 바탕으로
			SongList.RetrieveItem(detail, found); // 마스터리스트에서 깊은 복사를 통해
			detail.DisplayAllRecord(); // 화면에 출력한다
			cout << endl;
			iter.Next();
		}
	}
	else if (found == false) // 해당 장르가 없는 경우
	{
		cout << "\t 해당 앨범은 존재하지 않습니다." << endl;
	}
	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// 고유값을 바탕으로 자세한 정보 출력
void Application::SearchByPrimaryKey()
{
	DisplayAllMusic(); // 현재 존재하는 간단한 음악 정보 출력
	string key; // 고유값을 받기 위한 임시 변수 선언
	bool found = false; //Retrieve를 위한 bool 변수 초기화 선언
	MasterType dummy; // 자세한 정보를 담을 더미 객체
	cout << "\n\t 찾고싶은 곡의 고유값을 입력해주세요" << endl;
	cout << "\t ID : ";
	cin >> key;
	dummy.setId(key);
	SongList.RetrieveItem(dummy, found);
	if (found == true)
	{
		cout << "\n\t====== Search By Primary Key =====" << endl << endl;
		dummy.DisplayAllRecord();
		cout << endl;
	}
	else if (found == false)
		cout << "\n\t 해당 곡이 존재하지 않습니다." << endl;

	system("pause");
	cout << endl;
	system("CLS");

}

// 마스터리스트에서 해당 장르와 가사 한 소절을 바탕으로 검색
void Application::RetrieveByGenreNLyrics()
{
	cout << "\n\t====== Current Genre ===== " << endl << endl;
	GenreList.PrintTree(cout); // 현재 존재하는 장르 화면에 출력
	string genre; // 장르 입력받을 임시변수
	string lyrics; // 가사 입력받을 임시변수
	bool found = false; // Retrieve를 위한 bool변수 초기화 선언
	cout << "\n\t 찾고싶은 장르명과 가사 한 소절을 입력해주세요" << endl;
	cout << "\t Genre : ";
	cin >> genre;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	DoublySortedLinkedList<SimpleType>* list = NULL; // 간단한 리스트를 받을 포인터 변수
	Node<GenreType>* point = NULL; // 장르객체에 접근하기 위한 포인터 변수
	int count = 0; // 검색 성공여부를 위한 카운트
	GenreType gen; // 장르명을 담을 장르객체
	gen.setGenre(genre);
	GenreList.RetrieveItem(gen, found);

	if (found == true) // 해당 장르가 존재하는 경우
	{
		GenreList.GetPoint(gen, found, point); // 장르객체에 접근
		list = point->data.getSimpleList(); // 해당 장르 안의 간단한 리스트 넘겨받기
		DoublyIterator<SimpleType> iter(*list); // 간단한 리스트를 위한 반복자 선언
		iter.Next();
		int length = list->GetLength();
		cout << "\n\t====== Search By Genre and Lyrics=====" << endl << endl;
		for (int i = 0; i < length; i++)
		{
			// 가사 한 소절이 포함되는 경우
			if ((iter.GetCurrentNode()->data.getLyrics()).find(lyrics) != -1)
			{
				// 프로그램의 효율성을 고려하여 재생횟수는 감춘다
				iter.GetCurrentNode()->data.DisplayShallowSimpleRecord();
				cout << endl;
				count++;
			}
			iter.Next();
		}
		if (count == 0)
			cout << "\t 해당장르와 가사가 일치하는 곡이 없습니다." << endl;
	}
	else if (found == false) // 장르가 존재하지 않는 경우
	{
		cout << "\t 해당장르가 존재하지 않습니다." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


}

// 마스터리스트에서 해당 앨범과 가사 한 소절을 바탕으로 검색
void Application::RetrieveByAlbumNLyrics()
{
	cout << "\n\t====== Current Album ===== " << endl << endl;
	AlbumList.PrintTree(cout); // 현재 존재하는 앨범 화면에 출력
	string albumkey; // 앨범 고유값 입력받을 임시변수
	string lyrics; // 가사 입력받을 임시변수
	bool found = false; // Retrieve를 위한 bool변수 초기화 선언
	cout << "\n\t 찾고싶은 앨범 고유값과 가사 한 소절을 입력해주세요" << endl;
	cout << "\t Album : ";
	cin >> albumkey;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	DoublySortedLinkedList<SimpleType>* list = NULL; // 간단한 리스트를 받을 포인터 변수
	Node<AlbumType>* point = NULL; // 앨범객체에 접근하기 위한 포인터 변수
	int count = 0; // 검색 성공여부를 위한 카운트
	AlbumType al; // 앨범 고유값을 담을 앨범객체
	al.setKey(albumkey);
	AlbumList.RetrieveItem(al, found);
	if (found == true) // 해당 앨범이 존재하는 경우
	{
		AlbumList.GetPoint(al, found, point); // 앨범객체에 접근
		list = point->data.getSimpleList(); // 해당 앨범 안의 간단한 리스트 넘겨받기
		DoublyIterator<SimpleType> iter(*list); // 간단한 리스트를 위한 반복자 선언
		iter.Next();
		int length = list->GetLength();
		cout << "\n\t====== Search By Album and Lyrics=====" << endl << endl;
		for (int i = 0; i < length; i++)
		{
			// 가사 한 소절이 포함되는 경우
			if ((iter.GetCurrentNode()->data.getLyrics()).find(lyrics) != -1)
			{
				// 프로그램의 효율성을 고려하여 재생횟수는 감춘다
				iter.GetCurrentNode()->data.DisplayShallowSimpleRecord();
				cout << endl;
				count++;
			}
			iter.Next();
		}
		if (count == 0)
			cout << "\t 해당앨범와 가사가 일치하는 곡이 없습니다." << endl;
	}
	else if (found == false) // 앨범이 존재하지 않는 경우
	{
		cout << "\t 해당앨범이 존재하지 않습니다." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


}

// 리스트에 있는 모든 간단한 음악정보 출력
int Application::DisplayAllMusic()
{
	cout << "\n\t====== Current List ===== " << endl << endl;

	DoublyIterator<SimpleType> iter(PlayList); // 플레이리스트를 탐색하기 위한 반복자 선언
	iter.Next();
	int length = PlayList.GetLength();
	for (int i = 0; i < length; i++)
	{
		// 간단한 정보를 차례대로 출력
		iter.GetCurrentNode()->data.DisplaySimpleRecord();
		cout << endl;
		iter.Next();
	}


	return 1;
}

// 읽기 파일 오픈 후 모든 데이터를  뮤직리스트에 추가
int Application::ReadDataFromFile()
{
	MasterType data; // 파일의 정보를 담을 임시 객체
	string filename; // 읽을 파일명
	cout << "\n\t Enter File Name For Reading : ";
	cin >> filename;

	// 파일이 제대로 열렸는지 확인
	if (!OpenReadFile(filename))
		return 0;

	// 파일의 모든 데이터를 마스터리스트에 추가
	while (1)
	{
		data.ReadDataFromFile(fin);
		AddFromFile(data);
		if (fin.eof()) // 마지막 줄 끝으로 인해 정지
			break;
	}
	fin.close(); // 파일 닫기

	// current list 출력
	DisplayAllMusic();

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// 쓰기 파일 오픈 후 모든 테이터를 파일에 저장
int Application::WriteDataToFile()
{
	MasterType data; // 마스터리스트의 정보를 담을 임시 객체
	string filename; // 쓰기용 파일명
	cout << "\n\t Enter File Name For Writing : ";
	cin >> filename;

	// 파일이 제대로 열렸는지 확인
	if (!OpenWriteFile(filename))
		return 0;
	Node<MasterType>* dummy = NULL; // 마스터리스트의 뿌리를 받아올 더미포인터
	SongList.GetRoot(dummy); // 마스터리스트의 뿌리 받아오기
	PrintToFile(dummy, fout); // 파일에 출력하기

	fout.close(); // 파일 닫기

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// 음악정보가 담긴 파일을 읽기 파일로 열기
int Application::OpenReadFile(string& filename)
{
	fin.open(filename); // 읽기 파일 오픈
	if (!fin) { return 0; } // 오픈 실패
	else { return 1; } // 오픈 성공
}

// 음악정보를 담기 위한 쓰기 파일 열기
int Application::OpenWriteFile(string& filename)
{
	fout.open(filename); // 쓰기 파일 오픈
	if (!fout) { return 0; } // 오픈 실패
	else { return 1; } // 오픈 성공
}

// 파일에 출력하기
void Application::PrintToFile(Node<MasterType>* root, ofstream& fout)
{
	if (root != NULL) // root가 존재하는 경우
	{
		PrintToFile(root->left, fout); // root의 왼쪽으로 가서 다시 PrintToFile 함수 호출
		root->data.WriteDataToFile(fout);
		PrintToFile(root->right, fout); // root의 오른쪽으로 가서 다시 PrintToFile 함수 호출
	}
}

// 파일에서 읽어온 정보를 리스트에 추가
void Application::AddFromFile(MasterType music)
{
	bool found;
	SongList.Add(music); // 중복되지 않는 음악정보를 마스터리스트에 추가
	SimpleType simple; // 간단한 음악정보를 담는 객체
	GenreType data1; // 장르리스트에 추가할 객체
	ArtistType data2; // 아티스트리스트에 추가할 객체
	AlbumType data3; // 앨범리스트에 추가할 객체

	simple.setInfo(music.getId(), music.getName(), music.getLyrics()); // 모든 정보가 있는 music 객체에서 간단한 정보 가져오기
	PlayList.Add(simple); // 재생리스트에 음악 추가
	data1.setGenre(music.getGenre()); // 장르명 가져오기
	data2.setInfo(music.getArtist(), music.getComposer(), music.getSongwriter(), music.getBirth()); // 아티스트 관련 정보 가져오기
	data3.setInfo(music.getAlbum(), music.getArtist(), music.getCompany()); // 앨범 관련 정보 가져오기

	Node<GenreType>* glink = NULL; // 특정 장르객체에 접근하기 위한 포인터
	Node<ArtistType>* arlink = NULL; // 특정 아티스트객체에 접근하기 위한 포인터
	Node<AlbumType>* allink = NULL; // 특정 앨범객체에 접근하기 위한 포인터

	found = false; // false로 초기화

	GenreList.RetrieveItem(data1, found); // 장르 존재 여부
	if (found == true) // 장르리스트에 이미 존재하는 경우
	{
		GenreList.GetPoint(data1, found, glink); // 해당 장르객체에 접근
		glink->data.AddToGenreMusicList(simple); // 장르 안 리스트에 추가
	}
	else if (found == false || GenreList.IsEmpty()) // 장르리스트에 존재하지 않는 경우
	{
		GenreList.Add(data1); // 새로운 장르 추가
		GenreList.GetPoint(data1, found, glink); // 해당 장르객체에 접근
		glink->data.AddToGenreMusicList(simple); // 장르 안 리스트에 추가
	}

	ArtistType dummy; // 동명이인을 위한 더미 객체 선언
	dummy.setArtist(music.getArtist()); // 아티스트명 설정

	ArtistList.RetrieveItem(dummy, found);
	if (found == true) // 아티스트리스트에 이미 존재하는 경우
	{
		if (dummy.getBirth() != data2.getBirth()) // 생년월일이 다르다면 동명이인
		{
			string New = data2.getArtist() + "(동명이인)"; // 동명이인 설정
			dummy.setArtist(New);
			ArtistList.RetrieveItem(dummy, found);
			if (found == true)
				cout << "\t 동명이인이 많아 작업을 진행하기 힘듭니다." << endl; // 동명이인이 많은 경우 프로그램 종료
			else if (found == false) // 또 동명이인인 경우
			{
				data2.setArtist(New);
				ArtistList.Add(data2); // 동명이인으로 새롭게 아티스트 추가
				ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
				arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
			}
		}
		else // 생년월일도 같다면 같은 아티스트
		{
			ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
			arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
		}
	}
	else if (found == false || ArtistList.IsEmpty()) // 아티스트리스트에 존재하지 않는 경우 (새로운 아티스트)
	{
		ArtistList.Add(data2); // 새로운 아티스트 추가
		ArtistList.GetPoint(data2, found, arlink); // 해당 아티스트 객체에 접근
		arlink->data.AddToArtistMusicList(simple); // 아티스트 안 리스트에 추가
	}

	AlbumList.RetrieveItem(data3, found);
	if (found == true) // 앨범리스트에 이미 존재하는 경우
	{
		AlbumList.GetPoint(data3, found, allink); // 해당 앨범객체에 접근
		allink->data.AddToAlbumMusicList(simple); // 앨범 안 리스트에 추가
	}
	else if (found == false || ArtistList.IsEmpty()) // 앨범리스트에 존재하지 않는 경우
	{
		AlbumList.Add(data3); // 새로운 앨범 추가
		AlbumList.GetPoint(data3, found, allink); // 해당 앨범객체에 접근
		allink->data.AddToAlbumMusicList(simple); // 앨범 안 리스트에 추가
	}
}


//========================================================================================================================

// 폴더 생성
void Application::AddFolder()
{
	cout << "\n\t 추가할 폴더 이름을 지정해주세요" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // 중복되지 않는 경우
		{
			FolderList.Add(fol); // 폴더리스트에 새로운 폴더 추가
			break;
		}
		else // 중복되는 경우
		{
			cout << "\t 폴더명이 중복됩니다 다시 설정해주세요" << endl;
			continue;
		}
	}
	cout << endl;
	DisplayFolder();

	system("pause");
	cout << endl;
	system("CLS");

}

// 폴더 삭제
void Application::DeleteFolder()
{
	cout << "\n\t 삭제할 폴더 이름을 지정해주세요" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // 폴더가 존재하지 않는 경우
		{
			cout << "\t 폴더명이 존재하지 않습니다 다시 설정해주세요" << endl;
			continue;
		}
		else // 존재하는 경우
		{
			FolderList.Delete(fol); // 폴더리스트에 새로운 폴더 추가
			cout << "\n\t 성공적으로 삭제되었습니다!!!" << endl;
			break;
		}
	}
	cout << endl;
	DisplayFolder();

	system("pause");
	cout << endl;
	system("CLS");

}

// 현재 존재하는 폴더 출력
void Application::DisplayFolder()
{
	cout << "\n\tCurrent Folder list" << endl;
	DoublyIterator<FolderType> iter(FolderList); // 폴더리스트의 반복자 선언
	iter.Next();
	int length = FolderList.GetLength();
	for (int i = 0; i < length; i++)
	{
		// 차례대로 화면에 출력
		iter.GetCurrentNode()->data.DisplayFolder();
		iter.Next();
	}
}

// 폴더 안의 음악들을 화면에 출력
void Application::DisplayMusicInFolder()
{
	DisplayFolder();
	cout << "\n\t 검색할 폴더 이름을 지정해주세요" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // 폴더가 존재하지 않는 경우
		{
			cout << "\t 폴더명이 존재하지 않습니다 다시 설정해주세요" << endl;
			continue;
		}
		else // 존재하는 경우
			break;
	}
	DoublySortedLinkedList<SimpleType> *list = NULL; // 폴더 안의 음악리스트를 받기 위한 포인터 변수
	DoublyIterator<FolderType> iter(FolderList); // 폴더리스트를 위한 반복자 선언
	iter.Next();
	int length = FolderList.GetLength(); // 폴더리스트의 길이
	int slen; // 폴더 안의 음악리스트의 길이를 받기 위한 임시 변수
	int count = 0;
	cout << "\n\tCurrent " << fol.getFolder() << " list" << endl;
	for (int i = 0; i < length; i++)
	{
		// 해당 폴더명과 같은 폴더를 찾은 경우
		if (iter.GetCurrentNode()->data == fol)
		{
			slen = iter.GetCurrentNode()->data.getSimpleLength(); // 음악리스트의 길이
			list = iter.GetCurrentNode()->data.getSimpleList(); // 음악리스트 받아오기
			DoublyIterator<SimpleType> siter(*list); // 음악리스트를 위한 반복자 선언
			siter.Next();
			for (int j = 0; j < slen; j++)
			{
				// 프로그램의 효율성을 위해 재생횟수를 제외한 정보 출력
				siter.GetCurrentNode()->data.DisplayShallowSimpleRecord();
				cout << endl;
				siter.Next();
			}
			count++;
		}
		iter.Next();
	}
	if (count == 0)
	{
		cout << "\t 해당 폴더가 존재하지 않습니다." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");

}

// 폴더 안에 음악 추가
void Application::AddMusicInFolder()
{
	DisplayFolder();
	if (FolderList.GetLength() != 0) // 폴더가 하나 이상 존재해야 한다
	{
		cout << "\n\t 음악을 추가할 폴더 이름을 지정해주세요" << endl;
		FolderType fol;
		fol.setFolderNameFromKB();
		string key;
		cout << "\t 추가할 음악의 고유값을 입력해주세요" << endl;
		cout << "\t ID : ";
		cin >> key;
		SimpleType dummy;
		dummy.setId(key);
		if (PlayList.Get(dummy) == 1) // 제대로 된 고유값이 입력된 경우
		{
			int count = 0;
			DoublyIterator<FolderType> iter(FolderList); // 폴더리스트 탐색을 위한 반복자 선언
			iter.Next();
			int length = FolderList.GetLength();
			for (int i = 0; i < length; i++)
			{
				if (iter.GetCurrentNode()->data == fol) // 해당 폴더에
				{
					iter.GetCurrentNode()->data.AddToFolderMusicList(dummy); // 음악 추가
					cout << "\n\t 성공적으로 음악을 추가하였습니다!!!" << endl;
					count++;
				}
				iter.Next();
			}
			if (count == 0)
				cout << "\t 폴더명이 잘못되었습니다." << endl;
		}
		else if (PlayList.Get(dummy) == 0) // 고유값 입력이 잘못된 경우
			cout << "\t 고유값 입력이 잘못되었습니다." << endl;
	}
	else // 폴더 자체가 없는 경우
		cout << "\t 폴더가 존재하지 않습니다." << endl;

	system("pause");
	cout << endl;
	system("CLS");

}

// 폴더 안의 음악 삭제
void Application::DeleteMusicInFolder()
{
	string key;
	cout << "\t 삭제할 음악의 고유값을 입력해주세요" << endl;
	cout << "\t ID : ";
	cin >> key;
	SimpleType dummy;
	dummy.setId(key);
	DoublyIterator<FolderType> iter(FolderList);
	iter.Next();
	int count = 0;
	int flen = FolderList.GetLength();
	for (int i = 0; i < flen; i++)
	{
		int slen = iter.GetCurrentNode()->data.getSimpleLength(); // 폴더 안 리스트 길이
		DoublySortedLinkedList<SimpleType> *list = iter.GetCurrentNode()->data.getSimpleList(); // 폴더 안 리스트
		if (list->Get(dummy))
		{
			list->Delete(dummy);
			cout << "\n\t 성공적으로 음악을 삭제하였습니다!!!" << endl;
			count++;
			break;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "해당 곡이 존재하지 않습니다." << endl;

	system("pause");
	cout << endl;
	system("CLS");


}



//========================================================================================================================

// 곡명으로 재생
void Application::PlayByName()
{
	string name;
	cout << endl << "\t 재생할 곡명을 입력해주세요--> ";
	cin >> name;
	int count = 0; // 곡명 존재 여부
	int length = PlayList.GetLength(); // 플레이리스트 길이 받기
	MasterType mas; // 마스터리스트의 재생횟수 증가를 위한 객체
	Node<MasterType>* point = NULL; // 마스터리스트에 접근하기 위한 포인터 변수
	bool found = false; // Retrieve를 위한 bool변수 선언
	DoublyIterator<SimpleType> iter(PlayList); // 플레이리스트를 위한 반복자 선언
	iter.Next();
	for (int i = 0; i < length; i++)
	{
		// 곡명이 일치하는 경우
		if (iter.GetCurrentNode()->data.getName() == name)
		{
			curindex = i; // 현재 재생 인덱스를 초기화
			string sum = address + name + wave; // 재생을 위한 재설정
			char* a = (char*)sum.c_str();
			a[sum.size()] = '\0';
			PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
			iter.GetCurrentNode()->data.UpPlayCount(); // 플레이리스트의 재생횟수 증가
			mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 고유값을 넘겨준 뒤에
			SongList.GetPoint(mas, found, point); // 마스터리스트에서 해당 고유값 곡에 접근
			point->data.UpPlayCount(); // 후에 재생횟수 증가
			count++;
			break;
		}
		iter.Next();
	}
	if (count == 0)
	{
		cout << "해당 곡명이 존재하지 않습니다." << endl;
	}

	system("CLS");
}

// 다음 곡 재생
void Application::PlayNext()
{
	if (curindex != -1) // 곡을 재생한 경우
	{
		PlaySound(NULL, NULL, NULL); // 재생중인 곡 정지
		MasterType mas; // 재생횟수 증가를 위한 객체
		Node<MasterType>* point = NULL; // 마스터리스트에 접근하기 위한 포인터 변수
		bool found = false; // Retrieve를 위한 bool변수 선언
		int length = PlayList.GetLength();
		int next;
		if (curindex == length - 1) // 현재 인덱스가 마지막이라면
		{
			next = 0; // 그 다음은 처음이다
		}
		else // 마지막이 아니라면
			next = curindex + 1; // 현재 인덱스에 1 추가

		DoublyIterator<SimpleType> iter(PlayList); // 플레이리스트를 위한 반복자 선언
		iter.Next();
		for (int i = 0; i < length; i++)
		{
			if (i == next) // 다음 인덱스와 맞다면
			{
				curindex = i; // 현재 인덱스를 재설정
				string sum = address + (iter.GetCurrentNode()->data.getName()) + wave; // 재생할 곡 재설정
				char* a = (char*)sum.c_str();
				a[sum.size()] = '\0';
				PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
				iter.GetCurrentNode()->data.UpPlayCount(); // 플레이리스트에서 재생횟수 증가
				mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 고유값을 넘겨준 뒤에
				SongList.GetPoint(mas, found, point); // 마스터리스트에서
				point->data.UpPlayCount(); // 재생횟수 증가
				break;
			}
			iter.Next();
		}
	}
	else // 한 번도 재생한 적이 없는 경우
		cout << "현재 재생되고 있는 곡이 없습니다." << endl;
	system("CLS");

}

// 이전 곡 재생
void Application::PlayPost()
{
	if (curindex != -1) // 곡을 재생한 경우
	{
		PlaySound(NULL, NULL, NULL); // 재생중인 곡 정지
		MasterType mas; // 재생횟수 증가를 위한 객체
		Node<MasterType>* point = NULL; // 마스터리스트에 접근하기 위한 포인터 변수
		bool found = false; // Retrieve를 위한 bool변수 선언
		int length = PlayList.GetLength();
		int post;
		if (curindex == 0) // 현재 인덱스가 처음이라면
		{
			post = length - 1; // 그 이전은 마지막이다
		}
		else // 처음이 아니라면
			post = curindex - 1; // 현재 인덱스에서 -1

		DoublyIterator<SimpleType> iter(PlayList); // 플레이리스트를 위한 반복자 선언
		iter.Next();
		for (int i = 0; i < length; i++)
		{
			if (i == post) // 이전 인덱스와 맞다면
			{
				curindex = i; // 현재 인덱스를 재설정
				string sum = address + (iter.GetCurrentNode()->data.getName()) + wave; // 재생할 곡 재설정
				char* a = (char*)sum.c_str();
				a[sum.size()] = '\0';
				PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
				iter.GetCurrentNode()->data.UpPlayCount(); // 플레이리스트에서 재생횟수 증가
				mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // 고유값을 넘겨준 뒤에
				SongList.GetPoint(mas, found, point); // 마스터리스트에서
				point->data.UpPlayCount(); // 재생횟수 증가
				break;
			}
			iter.Next();
		}
	}
	else // 한 번도 재생한 적이 없는 경우
		cout << "현재 재생되고 있는 곡이 없습니다." << endl;

	system("CLS");
}

// 곡 재생 중지
void Application::PlayStop()
{
	PlaySound(NULL, NULL, NULL);
	system("CLS");
}

// 재생횟수 기준 TOP 30 설정 후 출력
void Application::DisplayTop30()
{
	SimpleType* top = new SimpleType[30]; // 30개의 음악정보를 담을 임시 동적 배열 선언
	int length = 0; // 처음 배열의 길이는 0
	DoublyIterator<SimpleType> iter(PlayList); // 플레이리스트 탐색을 위한 반복자 선언
	iter.Next();
	for (int i = 0; i < PlayList.GetLength(); i++)
	{
		AddToTop(top, iter.GetCurrentNode()->data, length); // 하나씩 배열에 추가
		iter.Next();
	}
	cout << "\n\t =========== TOP 30 =============" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << top[i] << endl << endl;
	}
	delete[] top; // 동적 배열 삭제
	
	system("pause");
	cout << endl;
	system("CLS");

}

// TOP30 동적배열에 추가하기 위한 함수
void Application::AddToTop(SimpleType*& top, SimpleType data, int& length)
{
	int m_cur; // 추가할 위치를 제공
	if (length == 0)
	{
		top[0] = data;
		length++;
	}
	else
	{
		BinarySearch(top, data, 0, length - 1, m_cur); // 바이너리서치를 통해 추가할 위치 받기
		for (int a = length; a > m_cur; a--) // 추가하는 위치에 따라 밀어주기
		{
			top[a] = top[a - 1];
		}
		top[m_cur] = data;
		length++; // 길이 증가
	}

}

// 재생횟수 기준의 바이너리서치
bool Application::BinarySearch(SimpleType*& info, SimpleType item, int fromLocation, int toLocation, int& m_cur)
{
	int midPoint;
	midPoint = (fromLocation + toLocation) / 2;
	if (fromLocation > toLocation) // Base case 1
	{
		m_cur = fromLocation;
		return false;
	}
	else
	{
		midPoint = (fromLocation + toLocation) / 2;
		if (-item.getPlayCount() < -info[midPoint].getPlayCount()) // 추가할 재생횟수와 midPoint에서의 재생횟수 비교
			return BinarySearch(info, item, fromLocation, midPoint - 1, m_cur); //같은 조건에서 midPoint -1 한번 더
		else if (item.getPlayCount() == info[midPoint].getPlayCount()) // 재생횟수 중복
		{
			m_cur = midPoint + 1;
			return true;
		}
		else
			return BinarySearch(info, item, midPoint + 1, toLocation, m_cur); //같은 조건에서 midPoint +1 한번 더
	}
}

