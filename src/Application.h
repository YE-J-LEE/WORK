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
*	@author	�̿���
*	@brief	Application class for the music player.
*/
class Application
{
public:
	/**
	*	�⺻ ������
	*/
	Application();

	/**
	*	�Ҹ���
	*/
	~Application();

	/**
	*	@brief	���α׷� ����̹�
	*	@pre	���α׷� �������
	*	@post	���α׷� ����
	*/
	void Run();

	/**
	*	@brief	�˻� ����̹�
	*	@pre	�˻� �������
	*	@post	�˻� ����
	*/
	void Search_Run();

	/**
	*	@brief	�������� ����̹�
	*	@pre	�������� �������
	*	@post	�������� ����
	*/
	void Folder_Run(); 

	/**
	*	@brief	������� ����̹�
	*	@pre	������� �������
	*	@post	������� ����
	*/
	void Play_Run();

	/**
	*	@brief	���θ�ɾ ȭ�鿡 ���, Ű����� �Է�
	*	@pre	none.
	*	@post	none.
	*	@return	����� �Է� ��ɾ�
	*/
	int GetCommand();

	/**
	*	@brief	�˻���ɾ ȭ�鿡 ���, Ű����� �Է�
	*	@pre	none.
	*	@post	none.
	*	@return	����� �Է� ��ɾ�
	*/
	int GetSearchCommand();

	/**
	*	@brief	����������ɾ ȭ�鿡 ���, Ű����� �Է�
	*	@pre	none.
	*	@post	none.
	*	@return	����� �Է� ��ɾ�
	*/
	int GetFolderCommand();

	/**
	*	@brief	���������ɾ ȭ�鿡 ���, Ű����� �Է�
	*	@pre	none.
	*	@post	none.
	*	@return	����� �Է� ��ɾ�
	*/
	int GetPlayCommand();
	
	/**
	*	@brief	����Ʈ�� ���ο� Music �߰�
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ���ο� Music �߰�
	*	@return	Run -> 1, No -> 0 ����
	*/
	int AddMusic();

	/**
	*	@brief	���Ͽ��� �޾ƿ� ������ ���� �߰�
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	���Ͽ��� �޾ƿ� ������ ���� �߰�
	*/
	void AddFromFile(MasterType music);

	/**
	*	@brief	����Ʈ���� Music �ϳ� ����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ��ġ�ϴ� Music�� ������ ����
	*	@return	���� ������ 1, ��� �������� 0 ����
	*/
	int DeleteMusic();

	/**
	*	@brief	����Ʈ���� �ϳ��� Music ���� ����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	����Ʈ�� ��ġ�ϴ� Music�� ������ ������ ����
	*	@return	���� -> 1, No -> 0 ����
	*/
	int ReplaceMusic();

	/**
	*	@brief	����Ʈ���� ������� Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByName();

	/**
	*	@brief	����Ʈ���� �������� Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByLyrics();

	/**
	*	@brief	����Ʈ���� ��Ƽ��Ʈ������ Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByArtist();

	/**
	*	@brief	����Ʈ���� �ٹ����� Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByAlbum();

	/**
	*	@brief	����Ʈ���� �帣�� Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	int SearchByGenre();

	/**
	*	@brief	����Ʈ���� ���������� Music ���� ��ġ
	*	@pre	none
	*	@return	��µǾ����� 1, ��¾ȵǸ� 0 ����
	*/
	void SearchByPrimaryKey();

	/**
	*	@brief	�帣��� ���簡 ��ġ�ϴ� �������� ���
	*	@pre	��������Ʈ �ʱ�ȭ ����
	*	@post	none
	*/
	void RetrieveByGenreNLyrics();

	/**
	*	@brief	�ٹ���� ���簡 ��ġ�ϴ� �������� ���
	*	@pre	��������Ʈ �ʱ�ȭ ����
	*	@post	none
	*/
	void RetrieveByAlbumNLyrics();
	
	/**
	*	@brief	��� Music ���� ���
	*	@pre	none.
	*	@post	none.
	*	@return	Run -> 1, No -> 0 ����
	*/
	int DisplayAllMusic();

	/**
	*	@brief	�б� ���� ���� ����, ���Ͽ��� ��� ������ �б�, �����ͷκ��� ����Ʈ ����
	*	@pre	���� ���� ����
	*	@post	���Ͽ��� ��� ������ �б�
	*	@return	Run -> 1, No -> 0 ����
	*/
	int ReadDataFromFile();

	/**
	*	@brief	���� ���� ���� Open, ��� �����͸� ���Ͽ� ����
	*	@pre	������ �������� �ʾƾ� ��
	*	@post	���Ͽ� ����Ʈ ������ ����
	*	@return	Run -> 1, No -> 0 ����																																																																																																																																																							``
	*/
	int WriteDataToFile();

	/**
	*	@brief	���� �����ں� ������ �Է� ���Ϸ� ����
	*	@pre	�б� ���� ���� ����
	*	@post	�б� ���� ���� ����
	*	@param	fileName	�б� ���� ������ �̸�
	*	@return	Run -> 1, No -> 0 ����
	*/
	int OpenReadFile(string& filename);

	/**
	*	@brief	���� �����ں� ������ ��� ���Ϸ� ����
	*	@pre	����Ʈ �ʱ�ȭ ����
	*	@post	���� ���� ���� ����
	*	@param	fileName	���� ���� ������ �̸�
	*	@return	Run -> 1, No -> 0 ����
	*/
	int OpenWriteFile(string& fileName);
	
	/**
	*	@brief	�������Ͽ� �����͸���Ʈ�� ��� �������� ����
	*	@pre	���������� ���� ����
	*	@post	�������Ͽ� �������� ����
	*	@param	�����͸���Ʈ�� �Ѹ�, ofstream�� fout
	*/
	void PrintToFile(Node<MasterType>* root, ofstream& fout);

    // =========================================== �������� �Լ� ==============================================

	/**
	*	@brief	���� ����
	*	@pre	none
	*/
	void AddFolder();

	/**
	*	@brief	���� ����
	*	@pre	none
	*/
	void DeleteFolder();

	/**
	*	@brief	���� ���
	*	@pre	none
	*/
	void DisplayFolder();

	/**
	*	@brief	������ ���� ���
	*	@pre	none
	*/
	void DisplayMusicInFolder();

	/**
	*	@brief	���� �ȿ� ���� �߰�
	*	@pre	none
	*/
	void AddMusicInFolder();

	/**
	*	@brief	���� �ȿ� ���� ����
	*	@pre	none
	*/
	void DeleteMusicInFolder();
	// ======================================== ��������� ���� �Լ� =========================================

	/**
	*	@brief	������� ���� ���
	*	@pre	none
	*	@post	������� ���� ���
	*/
	void PlayByName();

	/**
	*	@brief	���� ����� �������� ������ ���
	*	@pre	���� ���� �����
	*	@post	������ ���
	*/
	void PlayNext();

	/**
	*	@brief	���� ����� �������� ������ ���
	*	@pre	���� ���� �����
	*	@post	������ ���
	*/
	void PlayPost();

	/**
	*	@brief	���� �� ��� ����
	*	@pre	���� ���� �����
	*	@post	��� ����
	*/
	void PlayStop();

	/**
	*	@brief	�����迭 ���� �� �÷��̸���Ʈ���� ���� �� ���
	*	@pre	�÷��̸���Ʈ�� �ϳ� �̻� ���� ����
	*	@post	�����迭 delete
	*/
	void DisplayTop30();

	/**
	*	@brief	�����迭�� �������� �߰�
	*	@pre	�÷��̸���Ʈ�� �ϳ� �̻� ���� ����
	*	@param	�����迭, �߰��� ������, �迭�� ����
	*	@post	�������� �߰� �� ���۷����� ����
	*/
	void AddToTop(SimpleType*& top, SimpleType data, int& length);

	/**
	*	@brief	�����迭�� ���Ƚ���� �������� �߰��ϱ� ���� ��ġ
	*	@pre	none
	*	@param	�����迭, �߰��� ������, �迭�� ���۰� �� �ε���, �߰��� ��ġ
	*	@post	��ġ �� ���۷����� ����
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
	const string wave = ".wav"; ///< default wave ���� Ȯ���ڸ�
	int curindex; ///< Play list ����ϴ� ���� �־ �ε����� �ο�
};


#endif // APPLICATION_H

