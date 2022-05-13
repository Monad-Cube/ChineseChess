#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<sstream>
#include<math.h>

#define CHESSSIZE 54
#define CHESSSCALE 0.8 
#define BOARDX 320
#define BOARDY 358
#define BOARDSCALE 1.2
#define BGSCALE 1.4
#define CHESSMARGINX 0.1
#define CHESSMARGINY 0.1
#define LOGOHEIGHT 316
#define LOGOWIDTH 488

using namespace sf;

typedef enum StateDraw
{
	C,					//��
	J,					//��
	M,					//��
	Z,					//��
	P,					//��
	X,					//��
	S,					//ʿ
};

typedef enum StatePlayer
{
	Black,				//�������
	Red,				//�������
};


struct Chess
{
	bool isPressed;					//�����Ƿ񱻵���ƶ�
	//bool isMoved;					//�����ƶ�
	bool isEaten;					//���ӱ��Ե�
	StatePlayer player;				//�������ĸ����,�ں췽
	StateDraw state;				//�������ĸ���ͼ���� 
	Vector2i PrePos;				//������һ��λ��
	Vector2i CurPos;				//���ӵ�ǰλ��
	IntRect Block;					//���ӵĵ���ж�
};

struct Field
{
	bool isOccupied;				//��ǰ�����Ƿ�����ռ��
	Vector2i Pos;					//��ǰ���������
	IntRect Block;					//���ӵĵ���ж�
};


class Game
{

public:

	RenderWindow window;

	Game();
	~Game();
	
	//����

	//��̨����
	int Window_Height, Window_Width;

	bool isGameStart=false, isGameOver=false, isGameQuit=false,//��Ϸ״̬�׶�
		isClick, isNextClick, isWin, SoundPaused, isNext;

	//���Ӱ�ť����
	Texture tLogo, tBackground, tLose, tWin, tRedChess, tBlackChess, tChessBoard, tButtons, tGameQuit, tSoundPause, tSoundContinue, tBackMenu, tGameStart, tGameOver, tGameWin, tChallenge, tBattle, tMore, tRegret, tRestart, tPlayAgain;			 //  �����������
	Sprite  sLogo, sBackground, sLose, sWin, sRedChess, sBlackChess, sChessBoard, sButtons, sGameQuit, sSoundPause, sSoundContinue, sBackMenu, sGameStart, sGameOver, sGameWin, sButtonRegret, sButtonRestart;								 //  �����������

	IntRect ButtonGameStart, ButtonGameQuit, ButtonSoundPause, ButtonBack, ButtonStart, ButtonRectQuit, ButtonChallenge, ButtonBattle, ButtonRegret, ButtonRestart, ButtonPlayAgain, ButtonMore;

	Font font;

	//�����
	Chess chess[2][16];// ������������
	Chess currentChess, nextChess, eatenChess;// ��ǰ���ӡ���ǰ������һ�������Ե�����

	//����
	Field Field[10][9];//������Ϣ

	Music music;	//����
	
	StatePlayer Round;//�������غ��ж�
	StatePlayer Winner;//�������ʤ���ж�
	
	Event InputEvent;
	int ChessSize = CHESSSIZE * CHESSSCALE;
	Vector2i BlockSize = { CHESSSIZE * CHESSSCALE + CHESSMARGINX, CHESSSIZE * CHESSSCALE + CHESSMARGINY };						//�����̷ֿ飬ÿһ�������ƶ�����
	Vector2i BoardPoint;				//�������Ͻ�λ��
	Vector2i ChessPoint;				//��һ������λ��
	Vector2i MousePosition;				//���λ��

	//����
	void Initial();
	void IniData();                     //��Ϸ���ݳ�ʼ��   
	void LoadMediaData();               //����ý���ز�

	void Input();
	
	void Logic();
	void Interaction();					//��꽻��
	void NextMove();					//��һ���жϣ�����BorderHitTest() MoveJudge()����
	void ChessMove();					//�����ƶ�
	void ChessEat();					//������
	void ChessRegret();					//����
	void GameOver();                    //ʤ���ж�
	bool MoveJudge();					//�����ܷ��ƶ��ɹ�

	void Draw();
	void DrawBG();                      //���ƴ��ڱ���
	void DrawBoard();					//��������
	void DrawChess();					//��������
	void DrawButton();                  //���ƽ�����ť
	void DrawGameEnd();                 //������Ϸ�������� 

	void Run();
};

