#include "Game.h"

Game::Game()
{

	Window_Width = 860;
	Window_Height = 720;

	Uint32 windowStyle = Style::Titlebar | Style::Close;
	window.create(sf::VideoMode(Window_Width, Window_Height), L"Chinese Chess", windowStyle);

}

Game::~Game()
{

}

void Game::Initial()
{
	window.setFramerateLimit(60);

	isGameStart = false;
	isGameOver = false;
	isGameQuit = false;
	isClick = false;
	isWin = false;
	isNext = false;
	SoundPaused = false;
	Round = Red;// 红方先走


	IniData();
	LoadMediaData();
}

void Game::IniData()						//游戏数据初始化
{
	//放置棋盘位置
	BoardPoint.x = (Window_Width - BOARDX) / 2;
	BoardPoint.y = (Window_Height - BOARDY) / 2;

	//第一个棋子位置
	ChessPoint.x = BoardPoint.x + 1;
	ChessPoint.y = BoardPoint.y + 1;

	//设置绘制棋子
	//黑棋
	chess[0][0].state = C;
	chess[0][1].state = M;
	chess[0][2].state = X;
	chess[0][3].state = S;
	chess[0][4].state = J;
	chess[0][5].state = S;
	chess[0][6].state = X;
	chess[0][7].state = M;
	chess[0][8].state = C;
	chess[0][9].state = P;
	chess[0][10].state = P;
	chess[0][11].state = Z;
	chess[0][12].state = Z;
	chess[0][13].state = Z;
	chess[0][14].state = Z;
	chess[0][15].state = Z;
	//红棋
	chess[1][0].state = C;
	chess[1][1].state = M;
	chess[1][2].state = X;
	chess[1][3].state = S;
	chess[1][4].state = J;
	chess[1][5].state = S;
	chess[1][6].state = X;
	chess[1][7].state = M;
	chess[1][8].state = C;
	chess[1][9].state = P;
	chess[1][10].state = P;
	chess[1][11].state = Z;
	chess[1][12].state = Z;
	chess[1][13].state = Z;
	chess[1][14].state = Z;
	chess[1][15].state = Z;
	
	//设置棋子当前坐标和上一步坐标
	//黑棋坐标
	int i, j;
	i = j = 0;
	for (j = 0; j < 9; j++)
	{
		chess[i][j].CurPos.x = ChessPoint.x + j * BlockSize.x;
		chess[i][j].CurPos.y = ChessPoint.y;
		chess[i][j].PrePos.x = chess[i][j].CurPos.x;
		chess[i][j].PrePos.y = chess[i][j].CurPos.y;
		chess[i][j].Block.left = chess[i][j].CurPos.x;
		chess[i][j].Block.top = chess[i][j].CurPos.y;
		chess[i][j].Block.width = ChessSize;
		chess[i][j].Block.height = ChessSize;
	}
	chess[i][j].CurPos.x = ChessPoint.x + 1 * BlockSize.x;
	chess[i][j].CurPos.y = ChessPoint.y + 2 * BlockSize.y;
	chess[i][j].PrePos.x = chess[i][j].CurPos.x;
	chess[i][j].PrePos.y = chess[i][j].CurPos.y;
	chess[i][j].Block.left = chess[i][j].CurPos.x;
	chess[i][j].Block.top = chess[i][j].CurPos.y;
	chess[i][j].Block.width = ChessSize;
	chess[i][j].Block.height = ChessSize;
	j++;
	chess[i][j].CurPos.x = ChessPoint.x + 7 * BlockSize.x;
	chess[i][j].CurPos.y = ChessPoint.y + 2 * BlockSize.y;
	chess[i][j].PrePos.x = chess[i][j].CurPos.x;
	chess[i][j].PrePos.y = chess[i][j].CurPos.y;
	chess[i][j].Block.left = chess[i][j].CurPos.x;
	chess[i][j].Block.top = chess[i][j].CurPos.y;
	chess[i][j].Block.width = ChessSize;
	chess[i][j].Block.height = ChessSize;
	j++;
	for (; j < 16; j++)
	{
		chess[i][j].CurPos.x = ChessPoint.x + 2 * (j % 11) * BlockSize.x;
		chess[i][j].CurPos.y = ChessPoint.y + 3 * BlockSize.y;
		chess[i][j].PrePos.x = chess[i][j].CurPos.x;
		chess[i][j].PrePos.y = chess[i][j].CurPos.y;
		chess[i][j].Block.left = chess[i][j].CurPos.x;
		chess[i][j].Block.top = chess[i][j].CurPos.y;
		chess[i][j].Block.width = ChessSize;
		chess[i][j].Block.height = ChessSize;
	}
	//红棋坐标
	i = 1;
	for (j = 0; j < 9; j++)
	{
		chess[i][j].CurPos.x = ChessPoint.x + j * BlockSize.x;
		chess[i][j].CurPos.y = ChessPoint.y + 9 * BlockSize.y;
		chess[i][j].PrePos.x = chess[i][j].CurPos.x;
		chess[i][j].PrePos.y = chess[i][j].CurPos.y;
		chess[i][j].Block.left = chess[i][j].CurPos.x;
		chess[i][j].Block.top = chess[i][j].CurPos.y;
		chess[i][j].Block.width = ChessSize;
		chess[i][j].Block.height = ChessSize;
	}
	chess[i][j].CurPos.x = ChessPoint.x + 1 * BlockSize.x;
	chess[i][j].CurPos.y = ChessPoint.y + 7 * BlockSize.y;
	chess[i][j].PrePos.x = chess[i][j].CurPos.x;
	chess[i][j].PrePos.y = chess[i][j].CurPos.y;
	chess[i][j].Block.left = chess[i][j].CurPos.x;
	chess[i][j].Block.top = chess[i][j].CurPos.y;
	chess[i][j].Block.width = ChessSize;
	chess[i][j].Block.height = ChessSize;
	j++;
	chess[i][j].CurPos.x = ChessPoint.x + 7 * BlockSize.x;
	chess[i][j].CurPos.y = ChessPoint.y + 7 * BlockSize.y;
	chess[i][j].PrePos.x = chess[i][j].CurPos.x;
	chess[i][j].PrePos.y = chess[i][j].CurPos.y;
	chess[i][j].Block.left = chess[i][j].CurPos.x;
	chess[i][j].Block.top = chess[i][j].CurPos.y;
	chess[i][j].Block.width = ChessSize;
	chess[i][j].Block.height = ChessSize;
	j++;
	for (; j < 16; j++)
	{
		chess[i][j].CurPos.x = ChessPoint.x + 2 * (j % 11) * BlockSize.x;
		chess[i][j].CurPos.y = ChessPoint.y + 6 * BlockSize.y;
		chess[i][j].PrePos.x = chess[i][j].CurPos.x;
		chess[i][j].PrePos.y = chess[i][j].CurPos.y;
		chess[i][j].Block.left = chess[i][j].CurPos.x;
		chess[i][j].Block.top = chess[i][j].CurPos.y;
		chess[i][j].Block.width = ChessSize;
		chess[i][j].Block.height = ChessSize;
	}

	//设置棋子点击状态、已经被吃掉状态和黑红方状态写入
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 16; j++)
		{
			chess[i][j].isPressed = false;
			chess[i][j].isEaten = false;
			if (i == 0)
			{
				chess[i][j].player = Black;
			}
			else
			{
				chess[i][j].player = Red;
			}
			
		}
	}
	//设置区域的信息
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 9; k++)
		{
			Field[j][k].Pos.x = ChessPoint.x + k * BlockSize.x;
			Field[j][k].Pos.y = ChessPoint.y + j * BlockSize.y;
			Field[j][k].Block.top = Field[j][k].Pos.y;
			Field[j][k].Block.left = Field[j][k].Pos.x;
			Field[j][k].Block.width = ChessSize;
			Field[j][k].Block.height = ChessSize;
			Field[j][k].isOccupied = false;
		}
	}
	//Field的Occupied修正
	bool Equal=false;
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 9; k++)
		{
			//判断有没有棋子和Field数组坐标相等
			for (int m = 0; m < 2; m++)
			{
				for (int n = 0; n < 16; n++)
				{
					if (chess[m][n].CurPos.x == Field[j][k].Pos.x && chess[m][n].CurPos.y == Field[j][k].Pos.y)
					{
						Equal = true;
						break;
					}	
				}
				if (Equal) break;
			}
			if (Equal)
			{
				Field[j][k].isOccupied = true;
				Equal = false;
			}
		}
	}
	
}

void Game::LoadMediaData()				//加载媒体素材
{
	//load image
	if (!tLogo.loadFromFile("data/images/LOGO.png"))
		std::cout << "LOGO.png not found" << std::endl;
	if (!tBackground.loadFromFile("data/images/bg.png"))
		std::cout << "bg.png not found" << std::endl;

	if (!tRedChess.loadFromFile("data/images/RedChess.png"))
		std::cout << "RedChess.png not found" << std::endl;
	if (!tBlackChess.loadFromFile("data/images/BlackChess.png"))
		std::cout << "BlackChess.png not found" << std::endl;
	if (!tChessBoard.loadFromFile("data/images/board.png"))
		std::cout << "board.png not found" << std::endl;
	//if (!tButtons.loadFromFile("data/images/"))
	//	std::cout << "not found" << std::endl;
	//if (!tGameQuit.loadFromFile("data/images/"))
	//	std::cout << "not found" << std::endl;
	if (!tBackMenu.loadFromFile("data/images/jdback.png"))
		std::cout << "jdback.png not found" << std::endl;
	if (!tGameOver.loadFromFile("data/images/lose.png"))
		std::cout << "lose.png not found" << std::endl;
	if (!tSoundContinue.loadFromFile("data/images/sound.png"))
		std::cout << "sound.png not found" << std::endl;
	if (!tSoundPause.loadFromFile("data/images/sound1.png"))
		std::cout << "sound1.png not found" << std::endl;
	if (!tBattle.loadFromFile("data/images/battle.png"))
		std::cout << "battle.png not found" << std::endl;
	if (!tChallenge.loadFromFile("data/images/challenge.png"))
		std::cout << "challenge.png not found" << std::endl;
	if (!tMore.loadFromFile("data/images/more.png"))
		std::cout << "more.png not found" << std::endl;
	if (!tLose.loadFromFile("data/images/lose.png"))
		std::cout << "lose.png not found" << std::endl;
	if (!tWin.loadFromFile("data/images/win.png"))
		std::cout << "win.png not found" << std::endl;
	if (!tPlayAgain.loadFromFile("data/images/playagain.png"))
		std::cout << "playagain.png not found" << std::endl;
	if (!tRegret.loadFromFile("data/images/regret.png"))
		std::cout << "regret.png not found" << std::endl;
	if (!tRestart.loadFromFile("data/images/restart.png"))
		std::cout << "restart.png not found" << std::endl;
	if (!music.openFromFile("data/Sounds/music.ogg"))
	{
		std::cout << "Sounds not found" << std::endl;
	}
	
	
	sLogo.setTexture(tLogo);
	sLose.setTexture(tLose);
	sWin.setTexture(tWin);
	sBackground.setTexture(tBackground);
	sChessBoard.setTexture(tChessBoard);
	sSoundContinue.setTexture(tSoundContinue);
	sSoundPause.setTexture(tSoundPause);
	sRedChess.setTexture(tRedChess);
	sBlackChess.setTexture(tBlackChess);
	sGameStart.setTexture(tGameStart);
	sGameOver.setTexture(tGameOver);

	music.setVolume(20);
	music.play();			    //背景音乐播放
	music.setLoop(true);	    //背景音循环

}

void Game::Input()
{
	while (window.pollEvent(InputEvent))
	{
		if (InputEvent.type == Event::Closed)
		{
			window.close();//窗口如果要关闭，需要自己去调用 close()函数
			isGameQuit = true;

		}
		if (InputEvent.type == Event::EventType::KeyReleased && InputEvent.key.code == sf::Keyboard::Escape)
		{
			window.close();
			isGameQuit = true;
		}
		if (InputEvent.type == Event::EventType::MouseButtonPressed && InputEvent.mouseButton.button == Mouse::Left)
		{
			//获取点击位置
			MousePosition.x = InputEvent.mouseButton.x;
			MousePosition.y = InputEvent.mouseButton.y;
		}
		if (InputEvent.type == Event::EventType::MouseButtonReleased && InputEvent.mouseButton.button == Mouse::Left)
		{
			//已点击
			isClick = true;
			if (isNext)
			{
				isNextClick = true;
			}	
		}
	}
}

void Game::Logic()
{
	
	if (isClick)
	{
		Interaction();
		isClick = false;
	}

	GameOver();
}

void Game::Interaction()
{
	bool found = false;
	//游戏中棋子界面
	if (isGameStart)
	{
		if (ButtonBack.contains(MousePosition.x, MousePosition.y))
		{
			isGameStart = false;
			Initial();
		}
		if (ButtonRestart.contains(MousePosition.x, MousePosition.y))
		{
			Initial();
			isGameStart = true;
			isGameOver = false;
		}
		if (ButtonRegret.contains(MousePosition.x, MousePosition.y))
		{
			ChessRegret();
		}
		if (ButtonSoundPause.contains(MousePosition.x, MousePosition.y))
		{
			if (SoundPaused)
			{
				music.play();
				SoundPaused = false;
			}
			else
			{
				music.pause();
				SoundPaused = true;
			}
		}
		if (!isNext)//如果没有点击棋子
		{
			
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (chess[i][j].Block.contains(MousePosition.x, MousePosition.y))
					{
						if (chess[i][j].player !=Round)	// 找到棋子但是是对方的棋子，退出逻辑进行下一次寻找
						{
							std::cout << "It's opposite side's chess!" << std::endl;
							found = true;
							break;
						}
						std::cout << "Found the right chess!" << std::endl;

						chess[i][j].isPressed = true;	// 判断棋子被点击
						currentChess = chess[i][j];		// 当前移动和判断的棋子赋值

						isNext = true;					// 下一步函数执行
						found = true;					// 跳出循环
						break;
					}
				}
				if (found)//如果找到棋子
				{
					break;
				}
			}

		}
		else//上一步已经点击棋子
		{
			std::cout << "Tt's NextMove!" << std::endl;
			NextMove();
		}
		
	}
	//结束界面
	else if(isGameOver)
	{

	}
	//开始界面
	else
	{
		if (ButtonBattle.contains(MousePosition.x, MousePosition.y))
		{
			isGameStart = true;
		}
		//if()//挑战模式
	}
}

void Game::NextMove()					// 下一步判断
{
	bool found=false;	// 循环退出
	switch (currentChess.state)
	{
	case C:		// 车
		// 找到坐标
		for (int i = 0; i < 10; i++)	// 垂直移动
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y)&&(Field[i][j].Pos.x == currentChess.CurPos.x || Field[i][j].Pos.y == currentChess.CurPos.y))
				{
					std::cout << "C NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case M:		// 马
		// 找到坐标
		for (int i = 0; i < 10; i++)	// 日字型移动，横纵坐标差的绝对值的和为3
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && 
					(fabs(Field[i][j].Pos.x - currentChess.CurPos.x) + fabs(Field[i][j].Pos.y - currentChess.CurPos.y)) <= 3 * BlockSize.y &&
					(fabs(Field[i][j].Pos.x - currentChess.CurPos.x) + fabs(Field[i][j].Pos.y - currentChess.CurPos.y)) >= 3 * BlockSize.x)
				{
					std::cout << "M NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case X:		// 象 
		// 找到坐标
		for (int i = 0; i < 10; i++)	// 田字形移动，横纵坐标差的绝对值的均为2
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == (2 * BlockSize.x) && fabs(Field[i][j].Pos.y - currentChess.CurPos.y) == (2 * BlockSize.y))
				{
					std::cout << "X NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case S:		// 士 
	// 找到坐标
		for (int i = 0; i < 10; i++)	// 可以横竖走一格，也可以斜着走一格
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && (fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x || fabs(Field[i][j].Pos.y - currentChess.CurPos.y) == BlockSize.y))
				{
					std::cout << "S NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case J:		// 将
	// 找到坐标
		for (int i = 0; i < 10; i++)	// 只可以横竖走一格
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && (fabs(Field[i][j].Pos.x - currentChess.CurPos.x)+ fabs(Field[i][j].Pos.y - currentChess.CurPos.y)) < 2 * BlockSize.x &&
					(fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x  || fabs(Field[i][j].Pos.y - currentChess.CurPos.y) == BlockSize.y))
				{
					std::cout << "S NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case P:		// 炮
	// 找到坐标
		for (int i = 0; i < 10; i++)	// 垂直移动，隔山打牛
		{
			for (int j = 0; j < 9; j++)
			{
				if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && (Field[i][j].Pos.x == currentChess.CurPos.x || Field[i][j].Pos.y == currentChess.CurPos.y))
				{
					std::cout << "P NextMove has performed!" << std::endl;
					nextChess = currentChess;
					nextChess.PrePos = nextChess.CurPos;
					nextChess.CurPos = Field[i][j].Pos;
					nextChess.Block.top = Field[i][j].Pos.y;
					nextChess.Block.left = Field[i][j].Pos.x;
					found = true;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		break;
	case Z:		// 卒
	// 找到坐标
		for (int i = 0; i < 10; i++)	// 黑棋只能向上走，红棋只能向下走
		{
			for (int j = 0; j < 9; j++)
			{
				if (currentChess.player == Red)
				{
					if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && ((fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x && Field[i][j].Pos.y == currentChess.CurPos.y) ||	//横着走
						((Field[i][j].Pos.y - currentChess.CurPos.y) == - BlockSize.y && Field[i][j].Pos.x == currentChess.CurPos.x)))	// 竖着走
					{
						std::cout << "S NextMove has performed!" << std::endl;
						nextChess = currentChess;
						nextChess.PrePos = nextChess.CurPos;
						nextChess.CurPos = Field[i][j].Pos;
						nextChess.Block.top = Field[i][j].Pos.y;
						nextChess.Block.left = Field[i][j].Pos.x;
						found = true;
						break;
					}
				}
				else
				{
					if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && ((fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x && Field[i][j].Pos.y == currentChess.CurPos.y) ||	//横着走
						((Field[i][j].Pos.y - currentChess.CurPos.y) == BlockSize.y && Field[i][j].Pos.x == currentChess.CurPos.x)))	// 竖着走
					{
						std::cout << "S NextMove has performed!" << std::endl;
						nextChess = currentChess;
						nextChess.PrePos = nextChess.CurPos;
						nextChess.CurPos = Field[i][j].Pos;
						nextChess.Block.top = Field[i][j].Pos.y;
						nextChess.Block.left = Field[i][j].Pos.x;
						found = true;
						break;
					}
				}
				
			}
			if (found)
			{
				break;
			}
		}
		break;
	default:
		break;
	}
	if (found)
	{
		if (MoveJudge())		// 如果移动成功
		{
			ChessEat();
			isNext = false;
			ChessMove();		// 棋子移动

			if (Round == Red)	// 角色互换
			{
				Round = Black;
			}
			else
			{
				Round = Red;
			}
			return;
		}
		else
		{
			nextChess = currentChess;
			return;
		}
		
	}
	isNext = false;
}

bool Game::MoveJudge()					//棋子能否移动成功判断
{
	//for (int i = 0; i < 2; i++)	// 如果踩到自方的棋子上，move失败
	//{
	//	for (int j = 0; j < 16; j++)
	//	{
	//		if (nextChess.CurPos == chess[i][j].CurPos && nextChess.player == chess[i][j].player && chess[i][j].player == Round) return false;
	//	}
	//}

	//如果走成对方的棋子
	if (currentChess.player != Round)
	{
		isNext = false;
		return false;
	}
	
	//如果踩到己方棋子
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (nextChess.CurPos == chess[i][j].CurPos && nextChess.player == chess[i][j].player)
			{
				isNext = false;
				return false;
			}
		}
	}
	
	switch (currentChess.state)	// 不同的棋子，不同的移动规则
	{
	case C:	// 车，移动直线路途中不能有棋子
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (nextChess.CurPos.x == currentChess.CurPos.x && chess[i][j].CurPos.x == nextChess.CurPos.x)
				{
					if ((chess[i][j].CurPos.y < currentChess.CurPos.y && chess[i][j].CurPos.y > nextChess.CurPos.y) ||
						(chess[i][j].CurPos.y > currentChess.CurPos.y && chess[i][j].CurPos.y < nextChess.CurPos.y) )
					{
						std::cout << "C MoveJudge  has performed! " << std::endl;
						isNext = false;
						return false;
					}
						
				}
				else if(nextChess.CurPos.y == currentChess.CurPos.y && chess[i][j].CurPos.y == nextChess.CurPos.y)
				{
					if ((chess[i][j].CurPos.x < currentChess.CurPos.x && chess[i][j].CurPos.x > nextChess.CurPos.x) ||
						(chess[i][j].CurPos.x > currentChess.CurPos.x && chess[i][j].CurPos.x < nextChess.CurPos.x))
					{
						std::cout << "C MoveJudge  has performed!" << std::endl;
						isNext = false;
						return false;
					}
				}
			}
		}
		break;
	case M:	// 马，不能被阻碍，
		
		if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) == 2 * BlockSize.y)// 竖向被阻碍
		{
			if(nextChess.CurPos.y > currentChess.CurPos.y)
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 16; j++)
					{
						if (chess[i][j].CurPos.x == currentChess.CurPos.x && (chess[i][j].CurPos.y < nextChess.CurPos.y && chess[i][j].CurPos.y > currentChess.CurPos.y))
						
						{
							std::cout << "M Y MoveJudge  has performed!" << std::endl;
							isNext = false;
							return false;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 16; j++)
					{
						if (chess[i][j].CurPos.x == currentChess.CurPos.x && (chess[i][j].CurPos.y > nextChess.CurPos.y && chess[i][j].CurPos.y < currentChess.CurPos.y))

						{
							std::cout << "M Y MoveJudge  has performed!" << std::endl;
							isNext = false;
							return false;
						}
					}
				}
			}
		}
		if (fabs(nextChess.CurPos.x - currentChess.CurPos.x) == 2 * BlockSize.x)// 竖向被阻碍
		{
			if (nextChess.CurPos.x > currentChess.CurPos.x)
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 16; j++)
					{
						if (chess[i][j].CurPos.y == currentChess.CurPos.y && (chess[i][j].CurPos.x < nextChess.CurPos.x && chess[i][j].CurPos.x > currentChess.CurPos.x))
						{
							std::cout << "M X MoveJudge  has performed!" << std::endl;
							isNext = false;
							return false;
						}
					}
				}
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 16; j++)
					{
						if (chess[i][j].CurPos.y == currentChess.CurPos.y && (chess[i][j].CurPos.x > nextChess.CurPos.x && chess[i][j].CurPos.x < currentChess.CurPos.x))
						{
							std::cout << "M X MoveJudge  has performed!" << std::endl;
							isNext = false;
							return false;
						}
					}
				}
			}

		}
		break;
	case X:	// 象，竖直方向不能过河，水平方向不能过中线
		if (Round == Red)
		{
			if( nextChess.CurPos.y < (ChessPoint.y + 4 * BlockSize.y))// 竖直方向
			{
				std::cout << "X MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}	
		}
		else
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 5 * BlockSize.y))
			{
				std::cout << "X MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}

		if (currentChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.x > (ChessPoint.x + 4 * BlockSize.x) && currentChess.PrePos.x < (ChessPoint.x + 4 * BlockSize.x))// 水平方向
		{
			std::cout << "X LEFT MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		else if (currentChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.x < (ChessPoint.x + 4 * BlockSize.x) && currentChess.PrePos.x > (ChessPoint.x + 4 * BlockSize.x))// 水平方向右侧
		{
			std::cout << "X RIGHT MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		break;
	case S:	// 仕，田字内移动，在上下左右四个点不能斜着走
		if (nextChess.CurPos.x < (ChessPoint.x+ 3 * BlockSize.x) || nextChess.CurPos.x > (ChessPoint.x + 5 * BlockSize.x))// 水平方向
		{
			std::cout << "S MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		if (Round == Red)
		{
			if (nextChess.CurPos.y < (ChessPoint.y + 7 * BlockSize.y))// 不能出界
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// 不能斜着走
			if ((nextChess.CurPos.x == (ChessPoint.x + 3 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + 8 * BlockSize.y)) ||
				(nextChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + 9 * BlockSize.y)) ||
				(nextChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + 7 * BlockSize.y)) ||
				(nextChess.CurPos.x == (ChessPoint.x + 5 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + 8 * BlockSize.y)))
			{
				if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
				{
					std::cout << "S MoveJudge  has performed!" << std::endl;
					isNext = false;
					return false;
				}
			}
		}
		else
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 2 * BlockSize.y))// 不能出界
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// 不能斜着走
			if ((nextChess.CurPos.x == (ChessPoint.x + 3 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + BlockSize.y)) || 
				(nextChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.y == ChessPoint.y) ||
				(nextChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + 2 * BlockSize.y))||
				(nextChess.CurPos.x == (ChessPoint.x + 5 * BlockSize.x) && nextChess.CurPos.y == (ChessPoint.y + BlockSize.y)))
			{
				if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
				{
					std::cout << "S MoveJudge  has performed!" << std::endl;
					isNext = false;
					return false;
				}
			}
		}
		break;
	case J:	// 将，田字内移动，不能斜着走

		
		if (nextChess.CurPos.x < (ChessPoint.x + 3 * BlockSize.x) || nextChess.CurPos.x > (ChessPoint.x + 5 * BlockSize.x))// 水平方向
		{
			std::cout << "S X Out MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		if (Round == Red)
		{
			if (nextChess.CurPos.y < (ChessPoint.y + 7 * BlockSize.y))// 不能出界
			{
				std::cout << "S Y Out MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// 不能斜着走
			if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
			{
				std::cout << "S Incline wMoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}
		else
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 2 * BlockSize.y))// 不能出界
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// 不能斜着走
			if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}
		break;
	case P:	// 炮，移动直线路途中只能隔一个棋子,必须吃掉另一个棋子才能隔棋子移动
		int count;
		bool found;
		found = false;
		count = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				if (nextChess.CurPos.x == currentChess.CurPos.x && chess[i][j].CurPos.x == nextChess.CurPos.x)
				{
					if ((chess[i][j].CurPos.y < currentChess.CurPos.y && chess[i][j].CurPos.y > nextChess.CurPos.y) ||
						(chess[i][j].CurPos.y > currentChess.CurPos.y&& chess[i][j].CurPos.y < nextChess.CurPos.y))
					{
						count++;
					}
					if (chess[i][j].CurPos.y == nextChess.CurPos.y)// 隔棋子后吃掉棋子
					{
						found = true;
					}

				}
				else if (nextChess.CurPos.y == currentChess.CurPos.y && chess[i][j].CurPos.y == nextChess.CurPos.y)
				{
					if ((chess[i][j].CurPos.x < currentChess.CurPos.x && chess[i][j].CurPos.x > nextChess.CurPos.x) ||
						(chess[i][j].CurPos.x > currentChess.CurPos.x&& chess[i][j].CurPos.x < nextChess.CurPos.x))
					{
						count++;
					}
					if (chess[i][j].CurPos.x == nextChess.CurPos.x)// 隔棋子后吃掉棋子
					{
						found = true;
					}
				}
			}
		}
		if (count == 1)
		{
			if (!found)
			{
				std::cout << "P MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}
		else if (count > 1)
		{
			std::cout << "P MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		break;
	case Z:	// 卒，过河才能横向移动
		if (Round == Red)
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 4 * BlockSize.y))// 过河才能横向移动
			{
				if (nextChess.CurPos.x != currentChess.CurPos.x)
				{
					std::cout << "Z not cross the river" << std::endl;
					isNext = false;
					return false;
				}
			}
		}
		else if(Round == Black)
		{
			if (nextChess.CurPos.y < (ChessPoint.y + 5 * BlockSize.y))// 过河才能横向移动
			{
				if (nextChess.CurPos.x != currentChess.CurPos.x)
				{
					std::cout << "Z not cross the river" << std::endl;
					isNext = false;
					return false;
				}
			}
		}
		break;
	default:
		break;
	}
	std::cout << "MoveJudge  has performed! " << std::endl;
	return true;
}

void Game::ChessRegret()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (nextChess.CurPos == chess[i][j].CurPos)
			{
				chess[i][j] = currentChess;
				if (Round == Red)
				{
					Round = Black;
				}
				else
				{
					Round = Red;
				}
			}
		}
	}
}

void Game::ChessMove()					//棋子移动
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (currentChess.CurPos == chess[i][j].CurPos && (currentChess.player == chess[i][j].player))
			{
				chess[i][j].PrePos = chess[i][j].CurPos;
				chess[i][j] = nextChess;
			}
		}
	}
}

void Game::ChessEat()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (nextChess.CurPos == chess[i][j].CurPos && (currentChess.player != chess[i][j].player))
			{
				chess[i][j].isEaten = true;
				chess[i][j].CurPos = { -1,-1 };
				chess[i][j].Block = { 0, 0 , -1, -1};
			}
		}
	}
}

void Game::GameOver()                    //	胜负判定
{
	if (chess[0][4].isEaten)	//	保险机制
	{
		isGameOver = true;
		Winner = Red;
	}
	else if (chess[1][4].isEaten)
	{
		isGameOver = true;
		Winner = Black;
	}
	
	// 两将相见
	bool face;
	face = true;
	if (chess[0][4].CurPos.x == chess[1][4].CurPos.x)
	{
		if (Round == Black)	// 两将相遇，下一轮先走的获胜
		{
			for (int i = 0; i < 2; i++)	// 遍历是否将相见
			{
				for (int j = 0; j < 16; j++)
				{
					if (chess[0][4].CurPos.x == chess[i][j].CurPos.x && chess[i][j].CurPos.y > chess[0][4].CurPos.y && chess[i][j].CurPos.y < chess[1][4].CurPos.y)
					{
						face = false;
						break;
					}
				}
			}
			if (face)
			{
				Winner = Red;	//	下一轮是红色，下一轮红色将军
				isGameOver = true;
			}
		}
		else if (Round == Red)
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (chess[0][4].CurPos.x == chess[i][j].CurPos.x && chess[i][j].CurPos.y > chess[0][4].CurPos.y && chess[i][j].CurPos.y < chess[1][4].CurPos.y)
					{
						face = false;
						break;
					}
				}
			}
			if (face)
			{
				Winner = Black;	//	下一轮是红色，下一轮红色将军
				isGameOver = true;
			}
		}
	}
	

}

void Game::Draw()
{
	window.clear(); //清屏   
	//window.setSize(Vector2u(Window_width, Window_height));
	//window.setPosition(Vector2i(mCornPoint.x,mCornPoint.y));
	
	//绘制背景 
	DrawBG();

	//绘制舞台
	if (isGameStart)
	{
		DrawBoard();
		DrawChess();
	}
	
	DrawButton();

	if (isGameOver)
	{
		DrawBoard();
		DrawChess();
		DrawGameEnd();
	}

	window.display();               //把显示缓冲区的内容，显示在屏幕上。SFML 采用的是双缓冲机制 
}

void Game::DrawBG()                       
{
	//绘制窗口背景
	sBackground.setScale(BGSCALE, 1);
	sBackground.setPosition(0, 0);
	window.draw(sBackground);
	//绘制LOGO
	if (!isGameStart && !isGameOver)
	{
		Vector2i LeftCorner;
		int dx, dy;
		dx = (Window_Width - LOGOWIDTH) / 2;
		dy = 50;
		sLogo.setPosition(dx, dy);
		window.draw(sLogo);
	}
}

void Game::DrawBoard() 					//绘制棋盘
{
	sChessBoard.setScale(BOARDSCALE, BOARDSCALE);
	sChessBoard.setPosition(BoardPoint.x,BoardPoint.y);
	window.draw(sChessBoard);
}

void Game::DrawChess() 					//绘制棋子
{
	int i, j;
	//黑棋绘制
	i = 0;
	sBlackChess.setScale(CHESSSCALE, CHESSSCALE);
	for (j = 0; j < 16; j++)
	{
		if (!chess[i][j].isEaten)
		{
			sBlackChess.setTextureRect(IntRect(chess[i][j].state * CHESSSIZE, 0, CHESSSIZE, CHESSSIZE));
			sBlackChess.setPosition(chess[i][j].CurPos.x, chess[i][j].CurPos.y);
			window.draw(sBlackChess);
		}
	}
	//红棋绘制
	i++;
	sRedChess.setScale(CHESSSCALE, CHESSSCALE);
	for (j = 0; j < 16; j++)
	{
		if (!chess[i][j].isEaten)
		{
			sRedChess.setTextureRect(IntRect(chess[i][j].state * CHESSSIZE, 0, CHESSSIZE, CHESSSIZE));
			sRedChess.setPosition(chess[i][j].CurPos.x, chess[i][j].CurPos.y);
			window.draw(sRedChess);
		}
	}

}

void Game::DrawButton()                   //绘制交互按钮
{
	
	
	//游戏界面,返回键的绘制，游戏音量键的绘制
	if (isGameStart)
	{
		//绘制返回按键
		Vector2i LeftCorner;
		int ButtonWidth=86, ButtonHeight = 77;
		sButtons.setTexture(tBackMenu);//读取按钮的纹理区域
		sButtons.setPosition(0,0);								//设置按钮的位置坐标
		ButtonBack.left = 0;									//记录 按钮的位置区域
		ButtonBack.top = 0;
		ButtonBack.width = ButtonWidth;
		ButtonBack.height = ButtonHeight;
		window.draw(sButtons);
		//绘制音乐按钮
		LeftCorner.x = Window_Width - ButtonWidth;
		LeftCorner.y = 0;
		
		if(!SoundPaused)
		{
			sSoundContinue.setPosition(LeftCorner.x, LeftCorner.y);
			window.draw(sSoundContinue);
		}
		else
		{
			sSoundPause.setPosition(LeftCorner.x, LeftCorner.y);
			window.draw(sSoundPause);
		}
		
		ButtonSoundPause.left = LeftCorner.x;					//记录 按钮的位置区域
		ButtonSoundPause.top = LeftCorner.y;
		ButtonSoundPause.width = ButtonWidth;
		ButtonSoundPause.height = ButtonHeight;
		//绘制悔棋按钮
		ButtonWidth = 100, ButtonHeight = 40;
		LeftCorner.x = Window_Width / 2 - ButtonWidth;
		LeftCorner.y = ChessPoint.y + BOARDY + ButtonHeight * 2;
		sButtonRegret.setTexture(tRegret);							//读取按钮的纹理区域
		sButtonRegret.setPosition(LeftCorner.x, LeftCorner.y);								//设置按钮的位置坐标
		ButtonRegret.left = LeftCorner.x;									//记录 按钮的位置区域
		ButtonRegret.top = LeftCorner.y;
		ButtonRegret.width = ButtonWidth;
		ButtonRegret.height = ButtonHeight;
		window.draw(sButtonRegret);
		//绘制重新开始按钮
		ButtonWidth = 100, ButtonHeight = 40;
		LeftCorner.x = Window_Width / 2 + ButtonWidth - 25;
		LeftCorner.y = ChessPoint.y + BOARDY + ButtonHeight * 2;
		sButtonRestart.setTexture(tRestart);							//读取按钮的纹理区域
		sButtonRestart.setPosition(LeftCorner.x, LeftCorner.y);								//设置按钮的位置坐标
		ButtonRestart.left = LeftCorner.x;									//记录 按钮的位置区域
		ButtonRestart.top = LeftCorner.y;
		ButtonRestart.width = ButtonWidth;
		ButtonRestart.height = ButtonHeight;
		window.draw(sButtonRestart);
		
	}
	//结束界面
	else if (isGameOver)
	{
		std::cout << "GameOver Interface! " << std::endl;
		Vector2i LeftCorner;
		int ButtonWidth = 200;
		int ButtonHeight = 50;
		LeftCorner.x = (Window_Height - ButtonWidth) / 2;
		LeftCorner.y = Window_Height / 2 - 2 * ButtonHeight;//指定高度
		sButtons.setTexture(tRestart);							//读取按钮的纹理区域
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);								//设置按钮的位置坐标
		ButtonRegret.left = LeftCorner.x;									//记录 按钮的位置区域
		ButtonRegret.top = LeftCorner.y;
		ButtonRegret.width = ButtonWidth;
		ButtonRegret.height = ButtonHeight;
		window.draw(sButtons);
	}
	//开始界面
	else
	{
		Vector2i LeftCorner;
		//挑战
		//std::cout << "is Start Button!" << std::endl;
		int ButtonWidth = 250;
		int ButtonHeight = 63;
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LOGOHEIGHT +  ButtonHeight;
		sButtons.setTexture(tChallenge);								//读取按钮的纹理区域
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//设置按钮的位置坐标
		ButtonChallenge.left = LeftCorner.x;							//记录 按钮的位置区域
		ButtonChallenge.top = LeftCorner.y;
		ButtonChallenge.width = ButtonWidth;
		ButtonChallenge.height = ButtonHeight;
		window.draw(sButtons);
		//对弈
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LeftCorner.y + 2 * ButtonHeight;
		sButtons.setTexture(tBattle);								//读取按钮的纹理区域
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//设置按钮的位置坐标
		ButtonBattle.left = LeftCorner.x;							//记录 按钮的位置区域
		ButtonBattle.top = LeftCorner.y;
		ButtonBattle.width = ButtonWidth;
		ButtonBattle.height = ButtonHeight;
		window.draw(sButtons);
		//更多游戏
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LeftCorner.y + 2 * ButtonHeight;
		sButtons.setTexture(tMore);								//读取按钮的纹理区域
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//设置按钮的位置坐标
		ButtonMore.left = LeftCorner.x;							//记录 按钮的位置区域
		ButtonMore.top = LeftCorner.y;
		ButtonMore.width = ButtonWidth;
		ButtonMore.height = ButtonHeight;
		window.draw(sButtons);


	}
}

void Game::DrawGameEnd()                  //绘制游戏结束界面 
{
	if (Winner == Red)
	{
		Vector2i LeftCorner;
		int Width = 250;
		int dx, dy;
		dx = (Window_Width - Width) / 2 + 30;
		dy = ChessPoint.y + 6 * BlockSize.y;
		sWin.setPosition(dx, 200);
		sWin.setScale(0.8,0.8);
		window.draw(sWin);

		dy = ChessPoint.y + 1 * BlockSize.y;
		sLose.setPosition(dx, 450);
		window.draw(sLose);
	}
	else
	{
		Vector2i LeftCorner;
		int Width = 250;
		int dx, dy;
		dx = (Window_Width - Width) / 2 + 30;
		dy = ChessPoint.y + 6 * BlockSize.y;
		sLose.setPosition(dx, 200);
		window.draw(sLose);

		dy = ChessPoint.y + 1 * BlockSize.y;
		sWin.setScale(0.8, 0.8);
		sWin.setPosition(dx, 450);
		window.draw(sWin);
	}
}

void Game::Run()
{
	do
	{
		Initial();

		while (window.isOpen() && isGameQuit == false)
		{
			Input();

			Logic();

			Draw();
		}
	} while (!isGameQuit && window.isOpen());
}