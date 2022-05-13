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
	Round = Red;// �췽����


	IniData();
	LoadMediaData();
}

void Game::IniData()						//��Ϸ���ݳ�ʼ��
{
	//��������λ��
	BoardPoint.x = (Window_Width - BOARDX) / 2;
	BoardPoint.y = (Window_Height - BOARDY) / 2;

	//��һ������λ��
	ChessPoint.x = BoardPoint.x + 1;
	ChessPoint.y = BoardPoint.y + 1;

	//���û�������
	//����
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
	//����
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
	
	//�������ӵ�ǰ�������һ������
	//��������
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
	//��������
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

	//�������ӵ��״̬���Ѿ����Ե�״̬�ͺں췽״̬д��
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
	//�����������Ϣ
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
	//Field��Occupied����
	bool Equal=false;
	for (int j = 0; j < 10; j++)
	{
		for (int k = 0; k < 9; k++)
		{
			//�ж���û�����Ӻ�Field�����������
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

void Game::LoadMediaData()				//����ý���ز�
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
	music.play();			    //�������ֲ���
	music.setLoop(true);	    //������ѭ��

}

void Game::Input()
{
	while (window.pollEvent(InputEvent))
	{
		if (InputEvent.type == Event::Closed)
		{
			window.close();//�������Ҫ�رգ���Ҫ�Լ�ȥ���� close()����
			isGameQuit = true;

		}
		if (InputEvent.type == Event::EventType::KeyReleased && InputEvent.key.code == sf::Keyboard::Escape)
		{
			window.close();
			isGameQuit = true;
		}
		if (InputEvent.type == Event::EventType::MouseButtonPressed && InputEvent.mouseButton.button == Mouse::Left)
		{
			//��ȡ���λ��
			MousePosition.x = InputEvent.mouseButton.x;
			MousePosition.y = InputEvent.mouseButton.y;
		}
		if (InputEvent.type == Event::EventType::MouseButtonReleased && InputEvent.mouseButton.button == Mouse::Left)
		{
			//�ѵ��
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
	//��Ϸ�����ӽ���
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
		if (!isNext)//���û�е������
		{
			
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (chess[i][j].Block.contains(MousePosition.x, MousePosition.y))
					{
						if (chess[i][j].player !=Round)	// �ҵ����ӵ����ǶԷ������ӣ��˳��߼�������һ��Ѱ��
						{
							std::cout << "It's opposite side's chess!" << std::endl;
							found = true;
							break;
						}
						std::cout << "Found the right chess!" << std::endl;

						chess[i][j].isPressed = true;	// �ж����ӱ����
						currentChess = chess[i][j];		// ��ǰ�ƶ����жϵ����Ӹ�ֵ

						isNext = true;					// ��һ������ִ��
						found = true;					// ����ѭ��
						break;
					}
				}
				if (found)//����ҵ�����
				{
					break;
				}
			}

		}
		else//��һ���Ѿ��������
		{
			std::cout << "Tt's NextMove!" << std::endl;
			NextMove();
		}
		
	}
	//��������
	else if(isGameOver)
	{

	}
	//��ʼ����
	else
	{
		if (ButtonBattle.contains(MousePosition.x, MousePosition.y))
		{
			isGameStart = true;
		}
		//if()//��սģʽ
	}
}

void Game::NextMove()					// ��һ���ж�
{
	bool found=false;	// ѭ���˳�
	switch (currentChess.state)
	{
	case C:		// ��
		// �ҵ�����
		for (int i = 0; i < 10; i++)	// ��ֱ�ƶ�
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
	case M:		// ��
		// �ҵ�����
		for (int i = 0; i < 10; i++)	// �������ƶ������������ľ���ֵ�ĺ�Ϊ3
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
	case X:		// �� 
		// �ҵ�����
		for (int i = 0; i < 10; i++)	// �������ƶ������������ľ���ֵ�ľ�Ϊ2
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
	case S:		// ʿ 
	// �ҵ�����
		for (int i = 0; i < 10; i++)	// ���Ժ�����һ��Ҳ����б����һ��
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
	case J:		// ��
	// �ҵ�����
		for (int i = 0; i < 10; i++)	// ֻ���Ժ�����һ��
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
	case P:		// ��
	// �ҵ�����
		for (int i = 0; i < 10; i++)	// ��ֱ�ƶ�����ɽ��ţ
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
	case Z:		// ��
	// �ҵ�����
		for (int i = 0; i < 10; i++)	// ����ֻ�������ߣ�����ֻ��������
		{
			for (int j = 0; j < 9; j++)
			{
				if (currentChess.player == Red)
				{
					if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && ((fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x && Field[i][j].Pos.y == currentChess.CurPos.y) ||	//������
						((Field[i][j].Pos.y - currentChess.CurPos.y) == - BlockSize.y && Field[i][j].Pos.x == currentChess.CurPos.x)))	// ������
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
					if (Field[i][j].Block.contains(MousePosition.x, MousePosition.y) && ((fabs(Field[i][j].Pos.x - currentChess.CurPos.x) == BlockSize.x && Field[i][j].Pos.y == currentChess.CurPos.y) ||	//������
						((Field[i][j].Pos.y - currentChess.CurPos.y) == BlockSize.y && Field[i][j].Pos.x == currentChess.CurPos.x)))	// ������
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
		if (MoveJudge())		// ����ƶ��ɹ�
		{
			ChessEat();
			isNext = false;
			ChessMove();		// �����ƶ�

			if (Round == Red)	// ��ɫ����
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

bool Game::MoveJudge()					//�����ܷ��ƶ��ɹ��ж�
{
	//for (int i = 0; i < 2; i++)	// ����ȵ��Է��������ϣ�moveʧ��
	//{
	//	for (int j = 0; j < 16; j++)
	//	{
	//		if (nextChess.CurPos == chess[i][j].CurPos && nextChess.player == chess[i][j].player && chess[i][j].player == Round) return false;
	//	}
	//}

	//����߳ɶԷ�������
	if (currentChess.player != Round)
	{
		isNext = false;
		return false;
	}
	
	//����ȵ���������
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
	
	switch (currentChess.state)	// ��ͬ�����ӣ���ͬ���ƶ�����
	{
	case C:	// �����ƶ�ֱ��·;�в���������
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
	case M:	// �����ܱ��谭��
		
		if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) == 2 * BlockSize.y)// �����谭
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
		if (fabs(nextChess.CurPos.x - currentChess.CurPos.x) == 2 * BlockSize.x)// �����谭
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
	case X:	// ����ֱ�����ܹ��ӣ�ˮƽ�����ܹ�����
		if (Round == Red)
		{
			if( nextChess.CurPos.y < (ChessPoint.y + 4 * BlockSize.y))// ��ֱ����
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

		if (currentChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.x > (ChessPoint.x + 4 * BlockSize.x) && currentChess.PrePos.x < (ChessPoint.x + 4 * BlockSize.x))// ˮƽ����
		{
			std::cout << "X LEFT MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		else if (currentChess.CurPos.x == (ChessPoint.x + 4 * BlockSize.x) && nextChess.CurPos.x < (ChessPoint.x + 4 * BlockSize.x) && currentChess.PrePos.x > (ChessPoint.x + 4 * BlockSize.x))// ˮƽ�����Ҳ�
		{
			std::cout << "X RIGHT MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		break;
	case S:	// �ˣ��������ƶ��������������ĸ��㲻��б����
		if (nextChess.CurPos.x < (ChessPoint.x+ 3 * BlockSize.x) || nextChess.CurPos.x > (ChessPoint.x + 5 * BlockSize.x))// ˮƽ����
		{
			std::cout << "S MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		if (Round == Red)
		{
			if (nextChess.CurPos.y < (ChessPoint.y + 7 * BlockSize.y))// ���ܳ���
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// ����б����
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
			if (nextChess.CurPos.y > (ChessPoint.y + 2 * BlockSize.y))// ���ܳ���
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// ����б����
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
	case J:	// �����������ƶ�������б����

		
		if (nextChess.CurPos.x < (ChessPoint.x + 3 * BlockSize.x) || nextChess.CurPos.x > (ChessPoint.x + 5 * BlockSize.x))// ˮƽ����
		{
			std::cout << "S X Out MoveJudge  has performed!" << std::endl;
			isNext = false;
			return false;
		}
		if (Round == Red)
		{
			if (nextChess.CurPos.y < (ChessPoint.y + 7 * BlockSize.y))// ���ܳ���
			{
				std::cout << "S Y Out MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// ����б����
			if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
			{
				std::cout << "S Incline wMoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}
		else
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 2 * BlockSize.y))// ���ܳ���
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
			// ����б����
			if (fabs(nextChess.CurPos.y - currentChess.CurPos.y) >= BlockSize.y && fabs(nextChess.CurPos.x - currentChess.CurPos.x) >= BlockSize.x)
			{
				std::cout << "S MoveJudge  has performed!" << std::endl;
				isNext = false;
				return false;
			}
		}
		break;
	case P:	// �ڣ��ƶ�ֱ��·;��ֻ�ܸ�һ������,����Ե���һ�����Ӳ��ܸ������ƶ�
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
					if (chess[i][j].CurPos.y == nextChess.CurPos.y)// �����Ӻ�Ե�����
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
					if (chess[i][j].CurPos.x == nextChess.CurPos.x)// �����Ӻ�Ե�����
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
	case Z:	// �䣬���Ӳ��ܺ����ƶ�
		if (Round == Red)
		{
			if (nextChess.CurPos.y > (ChessPoint.y + 4 * BlockSize.y))// ���Ӳ��ܺ����ƶ�
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
			if (nextChess.CurPos.y < (ChessPoint.y + 5 * BlockSize.y))// ���Ӳ��ܺ����ƶ�
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

void Game::ChessMove()					//�����ƶ�
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

void Game::GameOver()                    //	ʤ���ж�
{
	if (chess[0][4].isEaten)	//	���ջ���
	{
		isGameOver = true;
		Winner = Red;
	}
	else if (chess[1][4].isEaten)
	{
		isGameOver = true;
		Winner = Black;
	}
	
	// �������
	bool face;
	face = true;
	if (chess[0][4].CurPos.x == chess[1][4].CurPos.x)
	{
		if (Round == Black)	// ������������һ�����ߵĻ�ʤ
		{
			for (int i = 0; i < 2; i++)	// �����Ƿ����
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
				Winner = Red;	//	��һ���Ǻ�ɫ����һ�ֺ�ɫ����
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
				Winner = Black;	//	��һ���Ǻ�ɫ����һ�ֺ�ɫ����
				isGameOver = true;
			}
		}
	}
	

}

void Game::Draw()
{
	window.clear(); //����   
	//window.setSize(Vector2u(Window_width, Window_height));
	//window.setPosition(Vector2i(mCornPoint.x,mCornPoint.y));
	
	//���Ʊ��� 
	DrawBG();

	//������̨
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

	window.display();               //����ʾ�����������ݣ���ʾ����Ļ�ϡ�SFML ���õ���˫������� 
}

void Game::DrawBG()                       
{
	//���ƴ��ڱ���
	sBackground.setScale(BGSCALE, 1);
	sBackground.setPosition(0, 0);
	window.draw(sBackground);
	//����LOGO
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

void Game::DrawBoard() 					//��������
{
	sChessBoard.setScale(BOARDSCALE, BOARDSCALE);
	sChessBoard.setPosition(BoardPoint.x,BoardPoint.y);
	window.draw(sChessBoard);
}

void Game::DrawChess() 					//��������
{
	int i, j;
	//�������
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
	//�������
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

void Game::DrawButton()                   //���ƽ�����ť
{
	
	
	//��Ϸ����,���ؼ��Ļ��ƣ���Ϸ�������Ļ���
	if (isGameStart)
	{
		//���Ʒ��ذ���
		Vector2i LeftCorner;
		int ButtonWidth=86, ButtonHeight = 77;
		sButtons.setTexture(tBackMenu);//��ȡ��ť����������
		sButtons.setPosition(0,0);								//���ð�ť��λ������
		ButtonBack.left = 0;									//��¼ ��ť��λ������
		ButtonBack.top = 0;
		ButtonBack.width = ButtonWidth;
		ButtonBack.height = ButtonHeight;
		window.draw(sButtons);
		//�������ְ�ť
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
		
		ButtonSoundPause.left = LeftCorner.x;					//��¼ ��ť��λ������
		ButtonSoundPause.top = LeftCorner.y;
		ButtonSoundPause.width = ButtonWidth;
		ButtonSoundPause.height = ButtonHeight;
		//���ƻ��尴ť
		ButtonWidth = 100, ButtonHeight = 40;
		LeftCorner.x = Window_Width / 2 - ButtonWidth;
		LeftCorner.y = ChessPoint.y + BOARDY + ButtonHeight * 2;
		sButtonRegret.setTexture(tRegret);							//��ȡ��ť����������
		sButtonRegret.setPosition(LeftCorner.x, LeftCorner.y);								//���ð�ť��λ������
		ButtonRegret.left = LeftCorner.x;									//��¼ ��ť��λ������
		ButtonRegret.top = LeftCorner.y;
		ButtonRegret.width = ButtonWidth;
		ButtonRegret.height = ButtonHeight;
		window.draw(sButtonRegret);
		//�������¿�ʼ��ť
		ButtonWidth = 100, ButtonHeight = 40;
		LeftCorner.x = Window_Width / 2 + ButtonWidth - 25;
		LeftCorner.y = ChessPoint.y + BOARDY + ButtonHeight * 2;
		sButtonRestart.setTexture(tRestart);							//��ȡ��ť����������
		sButtonRestart.setPosition(LeftCorner.x, LeftCorner.y);								//���ð�ť��λ������
		ButtonRestart.left = LeftCorner.x;									//��¼ ��ť��λ������
		ButtonRestart.top = LeftCorner.y;
		ButtonRestart.width = ButtonWidth;
		ButtonRestart.height = ButtonHeight;
		window.draw(sButtonRestart);
		
	}
	//��������
	else if (isGameOver)
	{
		std::cout << "GameOver Interface! " << std::endl;
		Vector2i LeftCorner;
		int ButtonWidth = 200;
		int ButtonHeight = 50;
		LeftCorner.x = (Window_Height - ButtonWidth) / 2;
		LeftCorner.y = Window_Height / 2 - 2 * ButtonHeight;//ָ���߶�
		sButtons.setTexture(tRestart);							//��ȡ��ť����������
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);								//���ð�ť��λ������
		ButtonRegret.left = LeftCorner.x;									//��¼ ��ť��λ������
		ButtonRegret.top = LeftCorner.y;
		ButtonRegret.width = ButtonWidth;
		ButtonRegret.height = ButtonHeight;
		window.draw(sButtons);
	}
	//��ʼ����
	else
	{
		Vector2i LeftCorner;
		//��ս
		//std::cout << "is Start Button!" << std::endl;
		int ButtonWidth = 250;
		int ButtonHeight = 63;
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LOGOHEIGHT +  ButtonHeight;
		sButtons.setTexture(tChallenge);								//��ȡ��ť����������
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//���ð�ť��λ������
		ButtonChallenge.left = LeftCorner.x;							//��¼ ��ť��λ������
		ButtonChallenge.top = LeftCorner.y;
		ButtonChallenge.width = ButtonWidth;
		ButtonChallenge.height = ButtonHeight;
		window.draw(sButtons);
		//����
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LeftCorner.y + 2 * ButtonHeight;
		sButtons.setTexture(tBattle);								//��ȡ��ť����������
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//���ð�ť��λ������
		ButtonBattle.left = LeftCorner.x;							//��¼ ��ť��λ������
		ButtonBattle.top = LeftCorner.y;
		ButtonBattle.width = ButtonWidth;
		ButtonBattle.height = ButtonHeight;
		window.draw(sButtons);
		//������Ϸ
		LeftCorner.x = (Window_Width - ButtonWidth) / 2;
		LeftCorner.y = LeftCorner.y + 2 * ButtonHeight;
		sButtons.setTexture(tMore);								//��ȡ��ť����������
		sButtons.setPosition(LeftCorner.x, LeftCorner.y);				//���ð�ť��λ������
		ButtonMore.left = LeftCorner.x;							//��¼ ��ť��λ������
		ButtonMore.top = LeftCorner.y;
		ButtonMore.width = ButtonWidth;
		ButtonMore.height = ButtonHeight;
		window.draw(sButtons);


	}
}

void Game::DrawGameEnd()                  //������Ϸ�������� 
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