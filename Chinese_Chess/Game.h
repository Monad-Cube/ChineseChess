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
	C,					//车
	J,					//将
	M,					//马
	Z,					//卒
	P,					//炮
	X,					//象
	S,					//士
};

typedef enum StatePlayer
{
	Black,				//黑棋玩家
	Red,				//红棋玩家
};


struct Chess
{
	bool isPressed;					//棋子是否被点击移动
	//bool isMoved;					//棋子移动
	bool isEaten;					//棋子被吃掉
	StatePlayer player;				//棋子是哪个玩家,黑红方
	StateDraw state;				//棋子是哪个绘图棋子 
	Vector2i PrePos;				//棋子上一个位置
	Vector2i CurPos;				//棋子当前位置
	IntRect Block;					//棋子的点击判断
};

struct Field
{
	bool isOccupied;				//当前区域是否被棋子占据
	Vector2i Pos;					//当前区域的坐标
	IntRect Block;					//棋子的点击判断
};


class Game
{

public:

	RenderWindow window;

	Game();
	~Game();
	
	//数据

	//舞台设置
	int Window_Height, Window_Width;

	bool isGameStart=false, isGameOver=false, isGameQuit=false,//游戏状态阶段
		isClick, isNextClick, isWin, SoundPaused, isNext;

	//棋子按钮创建
	Texture tLogo, tBackground, tLose, tWin, tRedChess, tBlackChess, tChessBoard, tButtons, tGameQuit, tSoundPause, tSoundContinue, tBackMenu, tGameStart, tGameOver, tGameWin, tChallenge, tBattle, tMore, tRegret, tRestart, tPlayAgain;			 //  创建纹理对象
	Sprite  sLogo, sBackground, sLose, sWin, sRedChess, sBlackChess, sChessBoard, sButtons, sGameQuit, sSoundPause, sSoundContinue, sBackMenu, sGameStart, sGameOver, sGameWin, sButtonRegret, sButtonRestart;								 //  创建精灵对象

	IntRect ButtonGameStart, ButtonGameQuit, ButtonSoundPause, ButtonBack, ButtonStart, ButtonRectQuit, ButtonChallenge, ButtonBattle, ButtonRegret, ButtonRestart, ButtonPlayAgain, ButtonMore;

	Font font;

	//红黑棋
	Chess chess[2][16];// 棋盘总棋子数
	Chess currentChess, nextChess, eatenChess;// 当前棋子、当前棋子下一步、被吃掉棋子

	//区域
	Field Field[10][9];//区域信息

	Music music;	//音乐
	
	StatePlayer Round;//红棋黑棋回合判断
	StatePlayer Winner;//红棋黑棋胜利判断
	
	Event InputEvent;
	int ChessSize = CHESSSIZE * CHESSSCALE;
	Vector2i BlockSize = { CHESSSIZE * CHESSSCALE + CHESSMARGINX, CHESSSIZE * CHESSSCALE + CHESSMARGINY };						//将棋盘分块，每一步象棋移动距离
	Vector2i BoardPoint;				//棋盘左上角位置
	Vector2i ChessPoint;				//第一个棋子位置
	Vector2i MousePosition;				//鼠标位置

	//函数
	void Initial();
	void IniData();                     //游戏数据初始化   
	void LoadMediaData();               //加载媒体素材

	void Input();
	
	void Logic();
	void Interaction();					//鼠标交互
	void NextMove();					//下一步判断，包含BorderHitTest() MoveJudge()函数
	void ChessMove();					//棋子移动
	void ChessEat();					//吃棋子
	void ChessRegret();					//悔棋
	void GameOver();                    //胜负判定
	bool MoveJudge();					//棋子能否移动成功

	void Draw();
	void DrawBG();                      //绘制窗口背景
	void DrawBoard();					//绘制棋盘
	void DrawChess();					//绘制棋子
	void DrawButton();                  //绘制交互按钮
	void DrawGameEnd();                 //绘制游戏结束界面 

	void Run();
};

