#include"Game.h"

int main()
{
	Game ChineseChess;
	
	while (ChineseChess.window.isOpen() && !ChineseChess.isGameOver)
	{
		ChineseChess.Run();
	}
	
	return 0;

}
