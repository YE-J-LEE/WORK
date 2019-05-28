#include "Application.h"
#include <string>
using namespace std;

// �⺻���� ������
Application::Application()
{
	m_Command = -1;	// ���� Ŀ�ǵ尪 �ʱ�ȭ
	s_Command = -1; // �˻� Ŀ�ǵ尪 �ʱ�ȭ
	f_Command = -1; // ���� Ŀ�ǵ尪 �ʱ�ȭ
	p_Command = -1; // ��� Ŀ�ǵ尪 �ʱ�ȭ
	curindex = -1; // ��� �ε��� �ʱ�ȭ
}

// �Ҹ���
Application::~Application()
{
	SongList.MakeEmpty();	//����Ʈ ����
}

// ���α׷� ����̹�
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:	 // ���� �߰� �� ����
			AddMusic();
			break;
		case 2:	 // ����Ʈ���� ���� ����
			DeleteMusic();
			break;
		case 3:	 // ����Ʈ�� �ִ� ���� ���� - ���� �� �߰�
			ReplaceMusic();
			break;
		case 4:	 // ����Ʈ�� �ִ� ���� ���� �˻�
			cout << "\t ���ǰ˻����� �Ѿ�ϴ�." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Search_Run();
			break;
		case 5:	 // ���� ����
			cout << "\t ���������� �Ѿ�ϴ�." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Folder_Run();
			break;
		case 6:	 // ���� ���
			cout << "\t ����������� �Ѿ�ϴ�." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Play_Run();
			break;
		case 7:	 // ���Ͽ� �������� �Է�
			WriteDataToFile();
			break;
		case 8:	 // ���Ͽ��� �������� �޾ƿ���
			ReadDataFromFile();
			break;
		case 0: // ���α׷� ����
			system("pause");
			exit(0);
			break;
		default: // ���� ó��
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// �˻� ����̹�
void Application::Search_Run()
{
	while (1)
	{
		s_Command = GetSearchCommand();

		switch (s_Command)
		{
		case 1:	 // ������� �˻�
			SearchByName();
			break;
		case 2:	 // ����� �˻�
			SearchByLyrics();
			break;
		case 3:	 // ��Ƽ��Ʈ������ �˻�
			SearchByArtist();
			break;
		case 4:	 // �ٹ������� �˻�
			SearchByAlbum();
			break;
		case 5:	 // �帣������ �˻�
			SearchByGenre();
			break;
		case 6:	 // ���������� �˻�
			SearchByPrimaryKey();
			break;
		case 7:	 // �帣 + ����� �˻�
			RetrieveByGenreNLyrics();
			break;
		case 8:	 // �ٹ� + ����� �˻�
			RetrieveByAlbumNLyrics();
			break;
		case 0: // ���� ����̹����� �̵�
			system("CLS");
			Run();
			break;
		default: // ����ó��
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// �������� ����̹�
void Application::Folder_Run()
{
	while (1)
	{
		f_Command = GetFolderCommand();

		switch (f_Command)
		{
		case 1:	 // ���� ����
			AddFolder();
			break;
		case 2:	 // ���� ����
			DeleteFolder();
			break;
		case 3:	 // ������ ���� �߰�
			AddMusicInFolder();
			break;
		case 4:	 // �������� ���� ����
			DeleteMusicInFolder();
			break;
		case 5:	 // ���� ��� ����̹��� �̵�
			cout << "\t ����������� �Ѿ�ϴ�." << endl;
			system("pause");
			cout << endl;
			system("CLS");
			Play_Run();
			break;
		case 6:	 // ������ ���� ȭ�鿡 ���
			DisplayMusicInFolder();
			break;
		case 0: // ���� ����̹��� �̵�
			system("CLS");
			Run();
			break;
		default: // ���� ó��
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// ������� ����̹�
void Application::Play_Run()
{
	while (1)
	{
		p_Command = GetPlayCommand();

		switch (p_Command)
		{
		case 1:	 // ������� ���� ���
			PlayByName();
			break;
		case 2:	 // ���� �� ���
			PlayNext();
			break;
		case 3:	 // ���� �� ���
			PlayPost();
			break;
		case 4:	 // �� ��� ����
			PlayStop();
			break;
		case 5:	 // Top 30 ���
			DisplayTop30();
			break;
		case 0: // ���� ����̹��� �̵�
			PlaySound(NULL, NULL, NULL);
			system("CLS");
			Run();
			break;
		default: // ���� ó��
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// ���� ��ɾ� ��� �� �Է� �ޱ�
int Application::GetCommand()
{
	int command;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << endl << endl;
	cout << "      ������ �ܢ� Music Player �ܢ� ������" << endl;
	cout << "      ��                                        ��" << endl;
	cout << "      ��    1 : ���� �߰�                       ��" << endl;
	cout << "      ��    2 : ���� ����                       ��" << endl;
	cout << "      ��    3 : ���� ����                       ��" << endl;
	cout << "      ��    4 : ���� �˻�                       ��" << endl;
	cout << "      ��    5 : ���� ����                       ��" << endl;
	cout << "      ��    6 : ���� ���                       ��" << endl;
	cout << "      ��    7 : ���Ͽ� ����                     ��" << endl;
	cout << "      ��    8 : ���Ͽ��� �ҷ�����               ��" << endl;
	cout << "      ��    0 : ���α׷� ����                   ��" << endl;
	cout << "      ��                                        ��" << endl;
	cout << "      �����������������������" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// �˻� ��ɾ� ��� �� �Է� �ޱ�
int Application::GetSearchCommand()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	int command;
	cout << endl << endl;
	cout << "      ������ �ܢ� Music Search �ܢ� ������" << endl;
	cout << "      ��                                        ��" << endl;
	cout << "      ��    1 : ������� �˻�                   ��" << endl;
	cout << "      ��    2 : ����� �˻�                     ��" << endl;
	cout << "      ��    3 : ��Ƽ��Ʈ�� �˻�                 ��" << endl;
	cout << "      ��    4 : �ٹ����� �˻�                   ��" << endl;
	cout << "      ��    5 : �帣�� �˻�                     ��" << endl;
	cout << "      ��    6 : ���������� �˻�                 ��" << endl;
	cout << "      ��    7 : �帣 + ����� �˻�              ��" << endl;
	cout << "      ��    8 : �ٹ� + ����� �˻�              ��" << endl;
	cout << "      ��    0 : �� â ������                    ��" << endl;
	cout << "      ��                                        ��" << endl;
	cout << "      �����������������������" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// ���� ��ɾ� ��� �� �Է� �ޱ�
int Application::GetFolderCommand()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	int command;
	cout << endl << endl;
	cout << "      ������  �ܢ� Folder Management �ܢ� ������" << endl;
	cout << "      ��                                              ��" << endl;
	cout << "      ��         1 : ���� ����                        ��" << endl;
	cout << "      ��         2 : ���� ����                        ��" << endl;
	cout << "      ��         3 : ������ ���� �߰�                 ��" << endl;
	cout << "      ��         4 : �������� ���� ����               ��" << endl;
	cout << "      ��         5 : �������� ���� ���               ��" << endl;
	cout << "      ��         6 : ������ ���� ���                 ��" << endl;
	cout << "      ��         0 : �� â ������                     ��"  << endl;
	cout << "      ��                                              ��" << endl;
	cout << "      ��������������������������" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return command;
}

// ��� ��ɾ� ��� �� �Է� �ޱ�
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
	cout << "\t           1. ��� ���      ��           " << endl;
	cout << "\t           2. ���� �� ���  ����          " << endl;
	cout << "\t           3. ���� �� ���  ����          " << endl;
	cout << "\t           4. ��� ����      ��           " << endl;
	cout << "\t           5. Top 30                      " << endl;
	cout << "\t           0. �� â ������                " << endl;
	cout << "\t========================================" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

// ���� �߰�
int Application::AddMusic()
{
	MasterType music; // ��� ���������� ��� ��ü
	bool found = false; // Retrieve�� �ʿ��� bool ����

	// �ߺ��˻縦 ���� while��
	while (1)
	{
		music.setRecordFromKB(); // Ű����κ��� ��� �������� �Է¹ޱ�
		
		SongList.RetrieveItem(music, found); // �ߺ� ���� �Ǵ�
		if (found) // �ߺ��� ���
		{
			cout << "Primary key���� �ߺ��˴ϴ�." << endl;
			continue;
		}
		else // �ߺ����� �ʴ� ��� while�� ����������
			break;
	}

	SongList.Add(music); // �ߺ����� �ʴ� ���������� �����͸���Ʈ�� �߰�
	SimpleType simple; // ������ ���������� ��� ��ü
	GenreType data1; // �帣����Ʈ�� �߰��� ��ü
	ArtistType data2; // ��Ƽ��Ʈ����Ʈ�� �߰��� ��ü
	AlbumType data3; // �ٹ�����Ʈ�� �߰��� ��ü

	simple.setInfo(music.getId(), music.getName(), music.getLyrics()); // ��� ������ �ִ� music ��ü���� ������ ���� ��������
	PlayList.Add(simple); // �������Ʈ�� ���� �߰�
	data1.setGenre(music.getGenre()); // �帣�� ��������
	data2.setInfo(music.getArtist(), music.getComposer(), music.getSongwriter(), music.getBirth()); // ��Ƽ��Ʈ ���� ���� ��������
	data3.setInfo(music.getAlbum(), music.getArtist(), music.getCompany()); // �ٹ� ���� ���� ��������

	Node<GenreType>* glink = NULL; // Ư�� �帣��ü�� �����ϱ� ���� ������
	Node<ArtistType>* arlink = NULL; // Ư�� ��Ƽ��Ʈ��ü�� �����ϱ� ���� ������
	Node<AlbumType>* allink = NULL; // Ư�� �ٹ���ü�� �����ϱ� ���� ������

	found = false; // false�� �ʱ�ȭ

	GenreList.RetrieveItem(data1, found); // �帣 ���� ����
	if (found == true) // �帣����Ʈ�� �̹� �����ϴ� ���
	{
		GenreList.GetPoint(data1, found, glink); // �ش� �帣��ü�� ����
		glink->data.AddToGenreMusicList(simple); // �帣 �� ����Ʈ�� �߰�
	}
	else if(found == false || GenreList.IsEmpty()) // �帣����Ʈ�� �������� �ʴ� ���
	{
		GenreList.Add(data1); // ���ο� �帣 �߰�
		GenreList.GetPoint(data1, found, glink); // �ش� �帣��ü�� ����
		glink->data.AddToGenreMusicList(simple); // �帣 �� ����Ʈ�� �߰�
	}

	ArtistType dummy; // ���������� ���� ���� ��ü ����
	dummy.setArtist(music.getArtist()); // ��Ƽ��Ʈ�� ����

	ArtistList.RetrieveItem(dummy, found);
	if (found == true) // ��Ƽ��Ʈ����Ʈ�� �̹� �����ϴ� ���
	{
		if (dummy.getBirth() != data2.getBirth()) // ��������� �ٸ��ٸ� ��������
		{
			string New = data2.getArtist() + "(��������)"; // �������� ����
			dummy.setArtist(New);
			ArtistList.RetrieveItem(dummy, found);
			if (found == true)
				cout << "\t ���������� ���� �۾��� �����ϱ� ����ϴ�." << endl; // ���������� ���� ��� ���α׷� ����
			else if (found == false) // �� ���������� ���
			{
				data2.setArtist(New);
				ArtistList.Add(data2); // ������������ ���Ӱ� ��Ƽ��Ʈ �߰�
				ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
				arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
			}
		}
		else // ������ϵ� ���ٸ� ���� ��Ƽ��Ʈ
		{
			ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
			arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
		}
	}
	else if (found == false || ArtistList.IsEmpty()) // ��Ƽ��Ʈ����Ʈ�� �������� �ʴ� ��� (���ο� ��Ƽ��Ʈ)
	{
		ArtistList.Add(data2); // ���ο� ��Ƽ��Ʈ �߰�
		ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
		arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
	}

	AlbumList.RetrieveItem(data3, found);
	if (found == true) // �ٹ�����Ʈ�� �̹� �����ϴ� ���
	{
		AlbumList.GetPoint(data3, found, allink); // �ش� �ٹ���ü�� ����
		allink->data.AddToAlbumMusicList(simple); // �ٹ� �� ����Ʈ�� �߰�
	}
	else if (found == false || ArtistList.IsEmpty()) // �ٹ�����Ʈ�� �������� �ʴ� ���
	{
		AlbumList.Add(data3); // ���ο� �ٹ� �߰�
		AlbumList.GetPoint(data3, found, allink); // �ش� �ٹ���ü�� ����
		allink->data.AddToAlbumMusicList(simple); // �ٹ� �� ����Ʈ�� �߰�
	}


	DisplayAllMusic(); // current list ���

	system("pause");
	cout << endl;
	system("CLS");

	return 1;
}

// ����Ʈ���� ���� ����
int Application::DeleteMusic()
{
	if (!SongList.IsEmpty()) // ���� ������ ���� �����ؾ� �Ѵ�
	{
		MasterType music; // ������ �����͸���Ʈ ��ü
		GenreType data1; // ������ �帣����Ʈ ��ü
		ArtistType data2; // ������ ��Ƽ��Ʈ����Ʈ ��ü
		AlbumType data3; // ������ �ٹ�����Ʈ ��ü
		SimpleType simple; // ������ �����Ѹ���Ʈ ��ü
		Node<GenreType>* glink = NULL; // Ư�� �帣��ü�� �����ϱ� ���� ������
		Node<ArtistType>* arlink = NULL; // Ư�� ��Ƽ��Ʈ��ü�� �����ϱ� ���� ������
		Node<AlbumType>* allink = NULL; // Ư�� �ٹ���ü�� �����ϱ� ���� ������
		string AlbumKey; // �ٹ� ������ ������ ���� �ӽú��� ����

		cout << "\t ������ ���� ������(ID)�� �Է����ּ���" << endl;
		music.setIdFromKB(); // ������ ������ �Է¹ޱ�
		simple.setId(music.getId()); // ������ ������ ���ȣ �Ѱ��ֱ�

		bool found = false; // Retrieve�� ���� bool �ʱ�ȭ
		SongList.RetrieveItem(music, found);
		if (found == true) // �ش� ���ȣ�� ��ġ�ϴ� ������ �����ϴ� ���
		{
			SongList.DeleteItem(music); // �����͸���Ʈ���� ����
			PlayList.Delete(simple); // �������Ʈ���� ����

			data1.setGenre(music.getGenre()); // �帣�� �Ѱ��ֱ�
			GenreList.RetrieveItem(data1, found); // �帣 ���� ����
			GenreList.GetPoint(data1, found, glink); // �ش� �帣 ��ü�� ����

			if (data1.getSimpleLength() == 1) // ���� �帣�� �ϳ��ۿ� ���ٸ� 
				GenreList.DeleteItem(data1); // �ƿ� �帣��ü ��ü�� ����
			else // �ϳ� �̻��̶��
				glink->data.DeleteInGenreMusicList(simple); // ���� �ش� �帣 ���� ����Ʈ���� ����

			data2.setArtist(music.getArtist()); // ��Ƽ��Ʈ�� �Ѱ��ֱ�
			ArtistList.RetrieveItem(data2, found); // ��Ƽ��Ʈ ���� ����
			ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����

			if (data2.getSimpleLength() == 1) // ���� ��Ƽ��Ʈ�� �ϳ��ۿ� ���ٸ� 
				ArtistList.DeleteItem(data2); // �ƿ� ��Ƽ��Ʈ��ü ��ü�� ����
			else // �ϳ� �̻��̶��
				arlink->data.DeleteInArtistMusicList(simple); // ���� �ش� ��Ƽ��Ʈ ���� ����Ʈ���� ����

			AlbumKey = music.getArtist() + "-" + music.getAlbum(); // �ٹ� ������ ����

			data3.setKey(AlbumKey);// �ٹ��� �Ѱ��ֱ�
			AlbumList.RetrieveItem(data3, found); // �ٹ� ���� ����
			AlbumList.GetPoint(data3, found, allink); // �ش� �ٹ� ��ü�� ����

			if (data3.getSimpleLength() == 1) // ���� �ٹ��� �ϳ��ۿ� ���ٸ�
				AlbumList.DeleteItem(data3); // �ƿ� �ٹ���ü ��ü�� ����
			else // �ϳ� �̻��̶��
				allink->data.DeleteInAlbumMusicList(simple); // ���� �ش� �ٹ� ���� ����Ʈ���� ����

			cout << "\t ������ �Ϸ�Ǿ����ϴ�!!!" << endl;

			// current list ���
			DisplayAllMusic();
		}
		else if (found == false) // �ش� �������� ��ġ�ϴ� ������ ���� ���
			cout << "\t �ش� �������� �������� �ʽ��ϴ�." << endl;

		system("pause");
		cout << endl;
		system("CLS");

		return 1;
	}
	else // �ƿ� ���� �������� �ʴ� ���
	{
		cout << "\t ������ ������ �����ϴ�." << endl;
		system("pause");
		cout << endl;
		system("CLS");

		return 0;
	}
}

// ����Ʈ���� �������� ����
int Application::ReplaceMusic()
{
	// ������ �ٽ� ���ĵǱ� ������ ���� �Ŀ� �߰��ϴ� �Ͱ� ����
	DeleteMusic();
	cout << "���� �߰��� ���� ������ �Է����ּ���" << endl;
	AddMusic();
	
	system("CLS");


	return 1;
}

// �����͸���Ʈ���� �ش� ����� ���ԵǴ� �������� ����
int Application::SearchByName()
{
	string name; // ��� �Է¹��� �ӽú���
	cout << "\t ã����� ����� �Է����ּ���" << endl;
	cout << "\t Name : ";
	cin >> name;
	MasterType dummy; // �ڼ��� ���� ����� ���� ���� ��ü ����
	DoublyIterator<SimpleType> iter(PlayList); // ������ ������ �ִ� �÷��̸���Ʈ�� ���� �ݺ��� ����
	bool found = false; // Retrieve�� ���� bool���� �ʱ�ȭ����
	iter.Next();
	int length = PlayList.GetLength(); 
	cout << "\n\t====== Search By Name=====" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		// ����� �Ϻΰ� ���ԵǾ ����Ѵ�
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

// �����͸���Ʈ���� �ش� ���� �� ������ ���ԵǴ� �������� ����
int Application::SearchByLyrics()
{
	string lyrics; // ���� �Է¹��� �ӽú���
	cout << "\t ã����� ���� �� ������ �Է����ּ���" << endl;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	MasterType dummy; // �ڼ��� ���� ����� ���� ���� ��ü ����
	DoublyIterator<SimpleType> iter(PlayList); // ������ ������ �ִ� �÷��̸���Ʈ�� ���� �ݺ��� ����
	bool found = false; // Retrieve�� ���� bool���� �ʱ�ȭ����
	iter.Next();
	int length = PlayList.GetLength();
	cout << "\n\t====== Search By Lyrics=====" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		// ������ �Ϻΰ� ���ԵǾ ����Ѵ�
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

// ��Ƽ��Ʈ����Ʈ �� ����Ʈ������ �������� ��������
// �����͸���Ʈ���� �ش� ��Ƽ��Ʈ�� ���ǵ��� �ڼ��� ���� ���
int Application::SearchByArtist()
{
	cout << "\n\t====== Current Artist ===== " << endl << endl;
	ArtistList.PrintTree(cout); // ȭ�鿡 ���� �����ϴ� ��Ƽ��Ʈ ���
	string artist; // ��Ƽ��Ʈ���� �Է¹��� �ӽú���
	bool found = false; // Retrieve�� ���� bool �ʱ�ȭ
	cout << "\n\t ã����� ��Ƽ��Ʈ�� ��Ȯ�ϰ� �Է����ּ���" << endl;
	cout << "\t Artist : ";
	cin >> artist;
	ArtistType dummy; // ��Ƽ��Ʈ�� ã�� ���� ���� ��ü ����
	dummy.setArtist(artist); // ��Ƽ��Ʈ ����
	ArtistList.RetrieveItem(dummy, found); // �˻��� ���ÿ� ���� ����
	Node<ArtistType>* point = NULL; // Ư�� ��Ƽ��Ʈ��ü�� �����ϱ� ���� ������ ����
	DoublySortedLinkedList<SimpleType>* list = NULL; // ��Ƽ��Ʈ �� ����Ʈ�� �޾ƿ� ������ ����
	MasterType detail; // �ڼ��� ������ ���� ���� ��ü
	
	if (found == true) // �ش� ��Ƽ��Ʈ�� �ִ� ���
	{
		cout << "\n\t====== Search By Artist=====" << endl << endl;
		ArtistList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // ��Ƽ��Ʈ �� ����Ʈ �޾ƿ���
		DoublyIterator<SimpleType> iter(*list); // ������ ����Ʈ�� �ݺ��� ����
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // ������ ����Ʈ ���� �������� ��������
			SongList.RetrieveItem(detail, found); // �����͸���Ʈ���� ���� ���縦 ����
			detail.DisplayAllRecord(); // ȭ�鿡 ����Ѵ�
			cout << endl;
			iter.Next();
		}
	}
	else // �ش� ��Ƽ��Ʈ�� ���� ���
	{
		cout << "\t �ش� ��Ƽ��Ʈ�� �������� �ʽ��ϴ�." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// �ٹ�����Ʈ �� ����Ʈ������ �������� ��������
// �����͸���Ʈ���� �ش� �ٹ��� ���ǵ��� �ڼ��� ���������� ���
int Application::SearchByAlbum()
{
	cout << "\n\t====== Current Album ===== " << endl << endl;
	AlbumList.PrintTree(cout); // ȭ�鿡 ���� �����ϴ� �ٹ� ���
	string AlbumKey; // �ٹ� �������� �Է¹��� �ӽú���
	bool found = false; // Retrieve�� ���� bool �ʱ�ȭ
	cout << "\n\t ã����� �ٹ��� �������� ��Ȯ�ϰ� �Է����ּ���" << endl;
	cout << "\t Album Key : ";
	cin >> AlbumKey;
	AlbumType dummy; // �ٹ��� ã�� ���� ���� ��ü ����
	dummy.setKey(AlbumKey); // �ٹ�Ű ����
	AlbumList.RetrieveItem(dummy, found); // �˻��� ���ÿ� ���� ����
	Node<AlbumType>* point = NULL; // Ư�� �ٹ���ü�� �����ϱ� ���� ������ ����
	DoublySortedLinkedList<SimpleType>* list = NULL; // �ٹ� �� ���ϰ� ����Ʈ�� �޾ƿ� ������ ����
	MasterType detail; // �ڼ��� ������ ���� ���� ��ü

	if (found == true) // �ش� �ٹ��� �ִ� ���
	{
		cout << "\n\t====== Search By Album=====" << endl << endl;
		AlbumList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // �ٹ� �� ����Ʈ �޾ƿ���
		DoublyIterator<SimpleType> iter(*list); // ������ ����Ʈ�� �ݺ��� ����
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // ������ ����Ʈ ���� �������� ��������
			SongList.RetrieveItem(detail, found); // �����͸���Ʈ���� ���� ���縦 ����
			detail.DisplayAllRecord(); // ȭ�鿡 ����Ѵ�
			cout << endl;
			iter.Next();
		}
	}
	else if (found == false) // �ش� �ٹ��� ���� ���
	{
		cout << "\t �ش� �ٹ��� �������� �ʽ��ϴ�." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");

	return 1;
}

// �帣����Ʈ �� ����Ʈ������ �帣���� ��������
// �����͸���Ʈ���� �ش� �帣 ���� ������ �ڼ��� ������ ���
int Application::SearchByGenre()
{
	cout << "\n\t====== Current Genre ===== " << endl << endl;
	GenreList.PrintTree(cout); // ȭ�鿡 ���� �����ϴ� �帣 ���
	string genre; // �帣���� �Է¹��� �ӽú���
	bool found = false; // Retrieve�� ���� bool �ʱ�ȭ
	cout << "\n\t ã����� �帣���� �Է����ּ���" << endl;
	cout << "\t Genre : ";
	cin >> genre;
	GenreType dummy; // �帣�� ã�� ���� ���� ��ü ����
	dummy.setGenre(genre); // �帣 ����
	GenreList.RetrieveItem(dummy, found); // �˻��� ���ÿ� ���� ����
	Node<GenreType>* point = NULL; // Ư�� �帣��ü�� �����ϱ� ���� ������ ����
	DoublySortedLinkedList<SimpleType>* list = NULL; // �帣 �� ���ϰ� ����Ʈ�� �޾ƿ� ������ ����
	MasterType detail; // �ڼ��� ������ ���� ���� ��ü

	if (found == true) // �ش� �帣�� �ִ� ���
	{
		cout << "\n\t====== Search By Genre=====" << endl << endl;
		GenreList.GetPoint(dummy, found, point);
		list = point->data.getSimpleList(); // �帣 �� ����Ʈ �޾ƿ���
		DoublyIterator<SimpleType> iter(*list); // ������ ����Ʈ�� �ݺ��� ����
		iter.Next();
		int length = list->GetLength();
		for (int i = 0; i < length; i++)
		{
			detail.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // ������ ����Ʈ ���� �������� ��������
			SongList.RetrieveItem(detail, found); // �����͸���Ʈ���� ���� ���縦 ����
			detail.DisplayAllRecord(); // ȭ�鿡 ����Ѵ�
			cout << endl;
			iter.Next();
		}
	}
	else if (found == false) // �ش� �帣�� ���� ���
	{
		cout << "\t �ش� �ٹ��� �������� �ʽ��ϴ�." << endl;
	}
	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// �������� �������� �ڼ��� ���� ���
void Application::SearchByPrimaryKey()
{
	DisplayAllMusic(); // ���� �����ϴ� ������ ���� ���� ���
	string key; // �������� �ޱ� ���� �ӽ� ���� ����
	bool found = false; //Retrieve�� ���� bool ���� �ʱ�ȭ ����
	MasterType dummy; // �ڼ��� ������ ���� ���� ��ü
	cout << "\n\t ã����� ���� �������� �Է����ּ���" << endl;
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
		cout << "\n\t �ش� ���� �������� �ʽ��ϴ�." << endl;

	system("pause");
	cout << endl;
	system("CLS");

}

// �����͸���Ʈ���� �ش� �帣�� ���� �� ������ �������� �˻�
void Application::RetrieveByGenreNLyrics()
{
	cout << "\n\t====== Current Genre ===== " << endl << endl;
	GenreList.PrintTree(cout); // ���� �����ϴ� �帣 ȭ�鿡 ���
	string genre; // �帣 �Է¹��� �ӽú���
	string lyrics; // ���� �Է¹��� �ӽú���
	bool found = false; // Retrieve�� ���� bool���� �ʱ�ȭ ����
	cout << "\n\t ã����� �帣��� ���� �� ������ �Է����ּ���" << endl;
	cout << "\t Genre : ";
	cin >> genre;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	DoublySortedLinkedList<SimpleType>* list = NULL; // ������ ����Ʈ�� ���� ������ ����
	Node<GenreType>* point = NULL; // �帣��ü�� �����ϱ� ���� ������ ����
	int count = 0; // �˻� �������θ� ���� ī��Ʈ
	GenreType gen; // �帣���� ���� �帣��ü
	gen.setGenre(genre);
	GenreList.RetrieveItem(gen, found);

	if (found == true) // �ش� �帣�� �����ϴ� ���
	{
		GenreList.GetPoint(gen, found, point); // �帣��ü�� ����
		list = point->data.getSimpleList(); // �ش� �帣 ���� ������ ����Ʈ �Ѱܹޱ�
		DoublyIterator<SimpleType> iter(*list); // ������ ����Ʈ�� ���� �ݺ��� ����
		iter.Next();
		int length = list->GetLength();
		cout << "\n\t====== Search By Genre and Lyrics=====" << endl << endl;
		for (int i = 0; i < length; i++)
		{
			// ���� �� ������ ���ԵǴ� ���
			if ((iter.GetCurrentNode()->data.getLyrics()).find(lyrics) != -1)
			{
				// ���α׷��� ȿ������ ����Ͽ� ���Ƚ���� �����
				iter.GetCurrentNode()->data.DisplayShallowSimpleRecord();
				cout << endl;
				count++;
			}
			iter.Next();
		}
		if (count == 0)
			cout << "\t �ش��帣�� ���簡 ��ġ�ϴ� ���� �����ϴ�." << endl;
	}
	else if (found == false) // �帣�� �������� �ʴ� ���
	{
		cout << "\t �ش��帣�� �������� �ʽ��ϴ�." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


}

// �����͸���Ʈ���� �ش� �ٹ��� ���� �� ������ �������� �˻�
void Application::RetrieveByAlbumNLyrics()
{
	cout << "\n\t====== Current Album ===== " << endl << endl;
	AlbumList.PrintTree(cout); // ���� �����ϴ� �ٹ� ȭ�鿡 ���
	string albumkey; // �ٹ� ������ �Է¹��� �ӽú���
	string lyrics; // ���� �Է¹��� �ӽú���
	bool found = false; // Retrieve�� ���� bool���� �ʱ�ȭ ����
	cout << "\n\t ã����� �ٹ� �������� ���� �� ������ �Է����ּ���" << endl;
	cout << "\t Album : ";
	cin >> albumkey;
	cout << "\t Lyrics : ";
	cin >> lyrics;
	DoublySortedLinkedList<SimpleType>* list = NULL; // ������ ����Ʈ�� ���� ������ ����
	Node<AlbumType>* point = NULL; // �ٹ���ü�� �����ϱ� ���� ������ ����
	int count = 0; // �˻� �������θ� ���� ī��Ʈ
	AlbumType al; // �ٹ� �������� ���� �ٹ���ü
	al.setKey(albumkey);
	AlbumList.RetrieveItem(al, found);
	if (found == true) // �ش� �ٹ��� �����ϴ� ���
	{
		AlbumList.GetPoint(al, found, point); // �ٹ���ü�� ����
		list = point->data.getSimpleList(); // �ش� �ٹ� ���� ������ ����Ʈ �Ѱܹޱ�
		DoublyIterator<SimpleType> iter(*list); // ������ ����Ʈ�� ���� �ݺ��� ����
		iter.Next();
		int length = list->GetLength();
		cout << "\n\t====== Search By Album and Lyrics=====" << endl << endl;
		for (int i = 0; i < length; i++)
		{
			// ���� �� ������ ���ԵǴ� ���
			if ((iter.GetCurrentNode()->data.getLyrics()).find(lyrics) != -1)
			{
				// ���α׷��� ȿ������ ����Ͽ� ���Ƚ���� �����
				iter.GetCurrentNode()->data.DisplayShallowSimpleRecord();
				cout << endl;
				count++;
			}
			iter.Next();
		}
		if (count == 0)
			cout << "\t �ش�ٹ��� ���簡 ��ġ�ϴ� ���� �����ϴ�." << endl;
	}
	else if (found == false) // �ٹ��� �������� �ʴ� ���
	{
		cout << "\t �ش�ٹ��� �������� �ʽ��ϴ�." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");


}

// ����Ʈ�� �ִ� ��� ������ �������� ���
int Application::DisplayAllMusic()
{
	cout << "\n\t====== Current List ===== " << endl << endl;

	DoublyIterator<SimpleType> iter(PlayList); // �÷��̸���Ʈ�� Ž���ϱ� ���� �ݺ��� ����
	iter.Next();
	int length = PlayList.GetLength();
	for (int i = 0; i < length; i++)
	{
		// ������ ������ ���ʴ�� ���
		iter.GetCurrentNode()->data.DisplaySimpleRecord();
		cout << endl;
		iter.Next();
	}


	return 1;
}

// �б� ���� ���� �� ��� �����͸�  ��������Ʈ�� �߰�
int Application::ReadDataFromFile()
{
	MasterType data; // ������ ������ ���� �ӽ� ��ü
	string filename; // ���� ���ϸ�
	cout << "\n\t Enter File Name For Reading : ";
	cin >> filename;

	// ������ ����� ���ȴ��� Ȯ��
	if (!OpenReadFile(filename))
		return 0;

	// ������ ��� �����͸� �����͸���Ʈ�� �߰�
	while (1)
	{
		data.ReadDataFromFile(fin);
		AddFromFile(data);
		if (fin.eof()) // ������ �� ������ ���� ����
			break;
	}
	fin.close(); // ���� �ݱ�

	// current list ���
	DisplayAllMusic();

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// ���� ���� ���� �� ��� �����͸� ���Ͽ� ����
int Application::WriteDataToFile()
{
	MasterType data; // �����͸���Ʈ�� ������ ���� �ӽ� ��ü
	string filename; // ����� ���ϸ�
	cout << "\n\t Enter File Name For Writing : ";
	cin >> filename;

	// ������ ����� ���ȴ��� Ȯ��
	if (!OpenWriteFile(filename))
		return 0;
	Node<MasterType>* dummy = NULL; // �����͸���Ʈ�� �Ѹ��� �޾ƿ� ����������
	SongList.GetRoot(dummy); // �����͸���Ʈ�� �Ѹ� �޾ƿ���
	PrintToFile(dummy, fout); // ���Ͽ� ����ϱ�

	fout.close(); // ���� �ݱ�

	system("pause");
	cout << endl;
	system("CLS");


	return 1;
}

// ���������� ��� ������ �б� ���Ϸ� ����
int Application::OpenReadFile(string& filename)
{
	fin.open(filename); // �б� ���� ����
	if (!fin) { return 0; } // ���� ����
	else { return 1; } // ���� ����
}

// ���������� ��� ���� ���� ���� ����
int Application::OpenWriteFile(string& filename)
{
	fout.open(filename); // ���� ���� ����
	if (!fout) { return 0; } // ���� ����
	else { return 1; } // ���� ����
}

// ���Ͽ� ����ϱ�
void Application::PrintToFile(Node<MasterType>* root, ofstream& fout)
{
	if (root != NULL) // root�� �����ϴ� ���
	{
		PrintToFile(root->left, fout); // root�� �������� ���� �ٽ� PrintToFile �Լ� ȣ��
		root->data.WriteDataToFile(fout);
		PrintToFile(root->right, fout); // root�� ���������� ���� �ٽ� PrintToFile �Լ� ȣ��
	}
}

// ���Ͽ��� �о�� ������ ����Ʈ�� �߰�
void Application::AddFromFile(MasterType music)
{
	bool found;
	SongList.Add(music); // �ߺ����� �ʴ� ���������� �����͸���Ʈ�� �߰�
	SimpleType simple; // ������ ���������� ��� ��ü
	GenreType data1; // �帣����Ʈ�� �߰��� ��ü
	ArtistType data2; // ��Ƽ��Ʈ����Ʈ�� �߰��� ��ü
	AlbumType data3; // �ٹ�����Ʈ�� �߰��� ��ü

	simple.setInfo(music.getId(), music.getName(), music.getLyrics()); // ��� ������ �ִ� music ��ü���� ������ ���� ��������
	PlayList.Add(simple); // �������Ʈ�� ���� �߰�
	data1.setGenre(music.getGenre()); // �帣�� ��������
	data2.setInfo(music.getArtist(), music.getComposer(), music.getSongwriter(), music.getBirth()); // ��Ƽ��Ʈ ���� ���� ��������
	data3.setInfo(music.getAlbum(), music.getArtist(), music.getCompany()); // �ٹ� ���� ���� ��������

	Node<GenreType>* glink = NULL; // Ư�� �帣��ü�� �����ϱ� ���� ������
	Node<ArtistType>* arlink = NULL; // Ư�� ��Ƽ��Ʈ��ü�� �����ϱ� ���� ������
	Node<AlbumType>* allink = NULL; // Ư�� �ٹ���ü�� �����ϱ� ���� ������

	found = false; // false�� �ʱ�ȭ

	GenreList.RetrieveItem(data1, found); // �帣 ���� ����
	if (found == true) // �帣����Ʈ�� �̹� �����ϴ� ���
	{
		GenreList.GetPoint(data1, found, glink); // �ش� �帣��ü�� ����
		glink->data.AddToGenreMusicList(simple); // �帣 �� ����Ʈ�� �߰�
	}
	else if (found == false || GenreList.IsEmpty()) // �帣����Ʈ�� �������� �ʴ� ���
	{
		GenreList.Add(data1); // ���ο� �帣 �߰�
		GenreList.GetPoint(data1, found, glink); // �ش� �帣��ü�� ����
		glink->data.AddToGenreMusicList(simple); // �帣 �� ����Ʈ�� �߰�
	}

	ArtistType dummy; // ���������� ���� ���� ��ü ����
	dummy.setArtist(music.getArtist()); // ��Ƽ��Ʈ�� ����

	ArtistList.RetrieveItem(dummy, found);
	if (found == true) // ��Ƽ��Ʈ����Ʈ�� �̹� �����ϴ� ���
	{
		if (dummy.getBirth() != data2.getBirth()) // ��������� �ٸ��ٸ� ��������
		{
			string New = data2.getArtist() + "(��������)"; // �������� ����
			dummy.setArtist(New);
			ArtistList.RetrieveItem(dummy, found);
			if (found == true)
				cout << "\t ���������� ���� �۾��� �����ϱ� ����ϴ�." << endl; // ���������� ���� ��� ���α׷� ����
			else if (found == false) // �� ���������� ���
			{
				data2.setArtist(New);
				ArtistList.Add(data2); // ������������ ���Ӱ� ��Ƽ��Ʈ �߰�
				ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
				arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
			}
		}
		else // ������ϵ� ���ٸ� ���� ��Ƽ��Ʈ
		{
			ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
			arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
		}
	}
	else if (found == false || ArtistList.IsEmpty()) // ��Ƽ��Ʈ����Ʈ�� �������� �ʴ� ��� (���ο� ��Ƽ��Ʈ)
	{
		ArtistList.Add(data2); // ���ο� ��Ƽ��Ʈ �߰�
		ArtistList.GetPoint(data2, found, arlink); // �ش� ��Ƽ��Ʈ ��ü�� ����
		arlink->data.AddToArtistMusicList(simple); // ��Ƽ��Ʈ �� ����Ʈ�� �߰�
	}

	AlbumList.RetrieveItem(data3, found);
	if (found == true) // �ٹ�����Ʈ�� �̹� �����ϴ� ���
	{
		AlbumList.GetPoint(data3, found, allink); // �ش� �ٹ���ü�� ����
		allink->data.AddToAlbumMusicList(simple); // �ٹ� �� ����Ʈ�� �߰�
	}
	else if (found == false || ArtistList.IsEmpty()) // �ٹ�����Ʈ�� �������� �ʴ� ���
	{
		AlbumList.Add(data3); // ���ο� �ٹ� �߰�
		AlbumList.GetPoint(data3, found, allink); // �ش� �ٹ���ü�� ����
		allink->data.AddToAlbumMusicList(simple); // �ٹ� �� ����Ʈ�� �߰�
	}
}


//========================================================================================================================

// ���� ����
void Application::AddFolder()
{
	cout << "\n\t �߰��� ���� �̸��� �������ּ���" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // �ߺ����� �ʴ� ���
		{
			FolderList.Add(fol); // ��������Ʈ�� ���ο� ���� �߰�
			break;
		}
		else // �ߺ��Ǵ� ���
		{
			cout << "\t �������� �ߺ��˴ϴ� �ٽ� �������ּ���" << endl;
			continue;
		}
	}
	cout << endl;
	DisplayFolder();

	system("pause");
	cout << endl;
	system("CLS");

}

// ���� ����
void Application::DeleteFolder()
{
	cout << "\n\t ������ ���� �̸��� �������ּ���" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // ������ �������� �ʴ� ���
		{
			cout << "\t �������� �������� �ʽ��ϴ� �ٽ� �������ּ���" << endl;
			continue;
		}
		else // �����ϴ� ���
		{
			FolderList.Delete(fol); // ��������Ʈ�� ���ο� ���� �߰�
			cout << "\n\t ���������� �����Ǿ����ϴ�!!!" << endl;
			break;
		}
	}
	cout << endl;
	DisplayFolder();

	system("pause");
	cout << endl;
	system("CLS");

}

// ���� �����ϴ� ���� ���
void Application::DisplayFolder()
{
	cout << "\n\tCurrent Folder list" << endl;
	DoublyIterator<FolderType> iter(FolderList); // ��������Ʈ�� �ݺ��� ����
	iter.Next();
	int length = FolderList.GetLength();
	for (int i = 0; i < length; i++)
	{
		// ���ʴ�� ȭ�鿡 ���
		iter.GetCurrentNode()->data.DisplayFolder();
		iter.Next();
	}
}

// ���� ���� ���ǵ��� ȭ�鿡 ���
void Application::DisplayMusicInFolder()
{
	DisplayFolder();
	cout << "\n\t �˻��� ���� �̸��� �������ּ���" << endl;
	FolderType fol;
	while (1)
	{
		fol.setFolderNameFromKB();
		if (FolderList.Get(fol) == 0) // ������ �������� �ʴ� ���
		{
			cout << "\t �������� �������� �ʽ��ϴ� �ٽ� �������ּ���" << endl;
			continue;
		}
		else // �����ϴ� ���
			break;
	}
	DoublySortedLinkedList<SimpleType> *list = NULL; // ���� ���� ���Ǹ���Ʈ�� �ޱ� ���� ������ ����
	DoublyIterator<FolderType> iter(FolderList); // ��������Ʈ�� ���� �ݺ��� ����
	iter.Next();
	int length = FolderList.GetLength(); // ��������Ʈ�� ����
	int slen; // ���� ���� ���Ǹ���Ʈ�� ���̸� �ޱ� ���� �ӽ� ����
	int count = 0;
	cout << "\n\tCurrent " << fol.getFolder() << " list" << endl;
	for (int i = 0; i < length; i++)
	{
		// �ش� ������� ���� ������ ã�� ���
		if (iter.GetCurrentNode()->data == fol)
		{
			slen = iter.GetCurrentNode()->data.getSimpleLength(); // ���Ǹ���Ʈ�� ����
			list = iter.GetCurrentNode()->data.getSimpleList(); // ���Ǹ���Ʈ �޾ƿ���
			DoublyIterator<SimpleType> siter(*list); // ���Ǹ���Ʈ�� ���� �ݺ��� ����
			siter.Next();
			for (int j = 0; j < slen; j++)
			{
				// ���α׷��� ȿ������ ���� ���Ƚ���� ������ ���� ���
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
		cout << "\t �ش� ������ �������� �ʽ��ϴ�." << endl;
	}

	system("pause");
	cout << endl;
	system("CLS");

}

// ���� �ȿ� ���� �߰�
void Application::AddMusicInFolder()
{
	DisplayFolder();
	if (FolderList.GetLength() != 0) // ������ �ϳ� �̻� �����ؾ� �Ѵ�
	{
		cout << "\n\t ������ �߰��� ���� �̸��� �������ּ���" << endl;
		FolderType fol;
		fol.setFolderNameFromKB();
		string key;
		cout << "\t �߰��� ������ �������� �Է����ּ���" << endl;
		cout << "\t ID : ";
		cin >> key;
		SimpleType dummy;
		dummy.setId(key);
		if (PlayList.Get(dummy) == 1) // ����� �� �������� �Էµ� ���
		{
			int count = 0;
			DoublyIterator<FolderType> iter(FolderList); // ��������Ʈ Ž���� ���� �ݺ��� ����
			iter.Next();
			int length = FolderList.GetLength();
			for (int i = 0; i < length; i++)
			{
				if (iter.GetCurrentNode()->data == fol) // �ش� ������
				{
					iter.GetCurrentNode()->data.AddToFolderMusicList(dummy); // ���� �߰�
					cout << "\n\t ���������� ������ �߰��Ͽ����ϴ�!!!" << endl;
					count++;
				}
				iter.Next();
			}
			if (count == 0)
				cout << "\t �������� �߸��Ǿ����ϴ�." << endl;
		}
		else if (PlayList.Get(dummy) == 0) // ������ �Է��� �߸��� ���
			cout << "\t ������ �Է��� �߸��Ǿ����ϴ�." << endl;
	}
	else // ���� ��ü�� ���� ���
		cout << "\t ������ �������� �ʽ��ϴ�." << endl;

	system("pause");
	cout << endl;
	system("CLS");

}

// ���� ���� ���� ����
void Application::DeleteMusicInFolder()
{
	string key;
	cout << "\t ������ ������ �������� �Է����ּ���" << endl;
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
		int slen = iter.GetCurrentNode()->data.getSimpleLength(); // ���� �� ����Ʈ ����
		DoublySortedLinkedList<SimpleType> *list = iter.GetCurrentNode()->data.getSimpleList(); // ���� �� ����Ʈ
		if (list->Get(dummy))
		{
			list->Delete(dummy);
			cout << "\n\t ���������� ������ �����Ͽ����ϴ�!!!" << endl;
			count++;
			break;
		}
		iter.Next();
	}
	if (count == 0)
		cout << "�ش� ���� �������� �ʽ��ϴ�." << endl;

	system("pause");
	cout << endl;
	system("CLS");


}



//========================================================================================================================

// ������� ���
void Application::PlayByName()
{
	string name;
	cout << endl << "\t ����� ����� �Է����ּ���--> ";
	cin >> name;
	int count = 0; // ��� ���� ����
	int length = PlayList.GetLength(); // �÷��̸���Ʈ ���� �ޱ�
	MasterType mas; // �����͸���Ʈ�� ���Ƚ�� ������ ���� ��ü
	Node<MasterType>* point = NULL; // �����͸���Ʈ�� �����ϱ� ���� ������ ����
	bool found = false; // Retrieve�� ���� bool���� ����
	DoublyIterator<SimpleType> iter(PlayList); // �÷��̸���Ʈ�� ���� �ݺ��� ����
	iter.Next();
	for (int i = 0; i < length; i++)
	{
		// ����� ��ġ�ϴ� ���
		if (iter.GetCurrentNode()->data.getName() == name)
		{
			curindex = i; // ���� ��� �ε����� �ʱ�ȭ
			string sum = address + name + wave; // ����� ���� �缳��
			char* a = (char*)sum.c_str();
			a[sum.size()] = '\0';
			PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
			iter.GetCurrentNode()->data.UpPlayCount(); // �÷��̸���Ʈ�� ���Ƚ�� ����
			mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // �������� �Ѱ��� �ڿ�
			SongList.GetPoint(mas, found, point); // �����͸���Ʈ���� �ش� ������ � ����
			point->data.UpPlayCount(); // �Ŀ� ���Ƚ�� ����
			count++;
			break;
		}
		iter.Next();
	}
	if (count == 0)
	{
		cout << "�ش� ����� �������� �ʽ��ϴ�." << endl;
	}

	system("CLS");
}

// ���� �� ���
void Application::PlayNext()
{
	if (curindex != -1) // ���� ����� ���
	{
		PlaySound(NULL, NULL, NULL); // ������� �� ����
		MasterType mas; // ���Ƚ�� ������ ���� ��ü
		Node<MasterType>* point = NULL; // �����͸���Ʈ�� �����ϱ� ���� ������ ����
		bool found = false; // Retrieve�� ���� bool���� ����
		int length = PlayList.GetLength();
		int next;
		if (curindex == length - 1) // ���� �ε����� �������̶��
		{
			next = 0; // �� ������ ó���̴�
		}
		else // �������� �ƴ϶��
			next = curindex + 1; // ���� �ε����� 1 �߰�

		DoublyIterator<SimpleType> iter(PlayList); // �÷��̸���Ʈ�� ���� �ݺ��� ����
		iter.Next();
		for (int i = 0; i < length; i++)
		{
			if (i == next) // ���� �ε����� �´ٸ�
			{
				curindex = i; // ���� �ε����� �缳��
				string sum = address + (iter.GetCurrentNode()->data.getName()) + wave; // ����� �� �缳��
				char* a = (char*)sum.c_str();
				a[sum.size()] = '\0';
				PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
				iter.GetCurrentNode()->data.UpPlayCount(); // �÷��̸���Ʈ���� ���Ƚ�� ����
				mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // �������� �Ѱ��� �ڿ�
				SongList.GetPoint(mas, found, point); // �����͸���Ʈ����
				point->data.UpPlayCount(); // ���Ƚ�� ����
				break;
			}
			iter.Next();
		}
	}
	else // �� ���� ����� ���� ���� ���
		cout << "���� ����ǰ� �ִ� ���� �����ϴ�." << endl;
	system("CLS");

}

// ���� �� ���
void Application::PlayPost()
{
	if (curindex != -1) // ���� ����� ���
	{
		PlaySound(NULL, NULL, NULL); // ������� �� ����
		MasterType mas; // ���Ƚ�� ������ ���� ��ü
		Node<MasterType>* point = NULL; // �����͸���Ʈ�� �����ϱ� ���� ������ ����
		bool found = false; // Retrieve�� ���� bool���� ����
		int length = PlayList.GetLength();
		int post;
		if (curindex == 0) // ���� �ε����� ó���̶��
		{
			post = length - 1; // �� ������ �������̴�
		}
		else // ó���� �ƴ϶��
			post = curindex - 1; // ���� �ε������� -1

		DoublyIterator<SimpleType> iter(PlayList); // �÷��̸���Ʈ�� ���� �ݺ��� ����
		iter.Next();
		for (int i = 0; i < length; i++)
		{
			if (i == post) // ���� �ε����� �´ٸ�
			{
				curindex = i; // ���� �ε����� �缳��
				string sum = address + (iter.GetCurrentNode()->data.getName()) + wave; // ����� �� �缳��
				char* a = (char*)sum.c_str();
				a[sum.size()] = '\0';
				PlaySound(a, NULL, SND_ASYNC | SND_LOOP);
				iter.GetCurrentNode()->data.UpPlayCount(); // �÷��̸���Ʈ���� ���Ƚ�� ����
				mas.setId(iter.GetCurrentNode()->data.getPrimaryKey()); // �������� �Ѱ��� �ڿ�
				SongList.GetPoint(mas, found, point); // �����͸���Ʈ����
				point->data.UpPlayCount(); // ���Ƚ�� ����
				break;
			}
			iter.Next();
		}
	}
	else // �� ���� ����� ���� ���� ���
		cout << "���� ����ǰ� �ִ� ���� �����ϴ�." << endl;

	system("CLS");
}

// �� ��� ����
void Application::PlayStop()
{
	PlaySound(NULL, NULL, NULL);
	system("CLS");
}

// ���Ƚ�� ���� TOP 30 ���� �� ���
void Application::DisplayTop30()
{
	SimpleType* top = new SimpleType[30]; // 30���� ���������� ���� �ӽ� ���� �迭 ����
	int length = 0; // ó�� �迭�� ���̴� 0
	DoublyIterator<SimpleType> iter(PlayList); // �÷��̸���Ʈ Ž���� ���� �ݺ��� ����
	iter.Next();
	for (int i = 0; i < PlayList.GetLength(); i++)
	{
		AddToTop(top, iter.GetCurrentNode()->data, length); // �ϳ��� �迭�� �߰�
		iter.Next();
	}
	cout << "\n\t =========== TOP 30 =============" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << top[i] << endl << endl;
	}
	delete[] top; // ���� �迭 ����
	
	system("pause");
	cout << endl;
	system("CLS");

}

// TOP30 �����迭�� �߰��ϱ� ���� �Լ�
void Application::AddToTop(SimpleType*& top, SimpleType data, int& length)
{
	int m_cur; // �߰��� ��ġ�� ����
	if (length == 0)
	{
		top[0] = data;
		length++;
	}
	else
	{
		BinarySearch(top, data, 0, length - 1, m_cur); // ���̳ʸ���ġ�� ���� �߰��� ��ġ �ޱ�
		for (int a = length; a > m_cur; a--) // �߰��ϴ� ��ġ�� ���� �о��ֱ�
		{
			top[a] = top[a - 1];
		}
		top[m_cur] = data;
		length++; // ���� ����
	}

}

// ���Ƚ�� ������ ���̳ʸ���ġ
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
		if (-item.getPlayCount() < -info[midPoint].getPlayCount()) // �߰��� ���Ƚ���� midPoint������ ���Ƚ�� ��
			return BinarySearch(info, item, fromLocation, midPoint - 1, m_cur); //���� ���ǿ��� midPoint -1 �ѹ� ��
		else if (item.getPlayCount() == info[midPoint].getPlayCount()) // ���Ƚ�� �ߺ�
		{
			m_cur = midPoint + 1;
			return true;
		}
		else
			return BinarySearch(info, item, midPoint + 1, toLocation, m_cur); //���� ���ǿ��� midPoint +1 �ѹ� ��
	}
}

