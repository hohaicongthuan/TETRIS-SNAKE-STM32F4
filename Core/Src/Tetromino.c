#include "main.h"
#include "Tetromino.h"
#include "TETRIS.h"

// Functions that draw Tetrominoes

void BlockI1(int x, int y)
{
	// Print the block on the screen
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 3, y + 1);

	CurrentState = 1;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	// Statement checks whether the tetromino could move left
	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0		&&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	//Statement checks whether the tetromino could move right
	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0	&&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 4][tetrominoLocY + 1] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	//Statement checks whether the tetromino could rotate (or switch state technically)
	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 3, tetrominoLocY + 2); cout << char(248);
}

void BlockI2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x + 1, y + 3);

	CurrentState = 2;

	if (tetrominoLocY >= 18 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 4] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] = colour;
	}
	else CanMoveDown = true;

	if (	tetris[tetrominoLocX][tetrominoLocY + 1]	== 0	&&
			tetris[tetrominoLocX][tetrominoLocY] 		== 0	&&
			tetris[tetrominoLocX][tetrominoLocY + 2]	== 0	&&
			tetris[tetrominoLocX][tetrominoLocY + 3]	== 0
		)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (	tetris[tetrominoLocX + 2][tetrominoLocY + 1]	== 0	&&
			tetris[tetrominoLocX + 2][tetrominoLocY] 		== 0	&&
			tetris[tetrominoLocX + 2][tetrominoLocY + 2]	== 0	&&
			tetris[tetrominoLocX + 2][tetrominoLocY + 3]	== 0
		)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY - 1); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 4); cout << char(248);
}

void BlockJ1(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 2, y + 2);
	PrintXY(x + 2, y + 1);

	CurrentState = 3;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0		&&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0	&&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0	&&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 	&&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0	&&
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockJ2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x, y + 2);

	CurrentState = 4;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
}

void BlockJ3(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x, y);
	PrintXY(x + 2, y + 1);

	CurrentState = 5;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockJ4(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 2, y);
	PrintXY(x + 1, y + 2);

	CurrentState = 6;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 1); cout << char(248);
}

void BlockL1(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x, y + 2);

	CurrentState = 7;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockL2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x + 2, y + 2);

	CurrentState = 8;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockL3(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 2, y);

	CurrentState = 9;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockL4(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x, y);

	CurrentState = 10;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 1); cout << char(248);
}

void BlockO(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 1, y + 2);
	PrintXY(x + 2, y + 2);

	CurrentState = 0;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	CanRotate = true;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockS1(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 1, y + 2);
	PrintXY(x, y + 2);

	CurrentState = 11;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockS2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 2, y + 2);

	CurrentState = 12;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockT1(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 2, y + 1);
	PrintXY(x + 1, y + 2);

	CurrentState = 13;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x + 2, y + 1);

	CurrentState = 14;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT3(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 2, y + 1);

	CurrentState = 15;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT4(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x + 1, y + 2);
	PrintXY(x, y + 1);

	CurrentState = 16;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockZ1(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x, y + 1);
	PrintXY(x + 1, y + 2);
	PrintXY(x + 2, y + 2);

	CurrentState = 17;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//PrintXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockZ2(int x, int y)
{
	PrintXY(x + 1, y + 1);
	PrintXY(x + 1, y);
	PrintXY(x, y + 1);
	PrintXY(x, y + 2);

	CurrentState = 18;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		while (isDownKey() == 1);
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] == 0
	)
		CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0
	)
		CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//PrintXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//PrintXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void PrintTetromino()
{
	switch (CurrentState)
	{
	case 0: { BlockO(tetrominoLocX, tetrominoLocY); break; }
	case 1: { BlockI1(tetrominoLocX, tetrominoLocY); break; }
	case 2: { BlockI2(tetrominoLocX, tetrominoLocY); break; }
	case 3: { BlockJ1(tetrominoLocX, tetrominoLocY); break; }
	case 4: { BlockJ2(tetrominoLocX, tetrominoLocY); break; }
	case 5: { BlockJ3(tetrominoLocX, tetrominoLocY); break; }
	case 6: { BlockJ4(tetrominoLocX, tetrominoLocY); break; }
	case 7: { BlockL1(tetrominoLocX, tetrominoLocY); break; }
	case 8: { BlockL2(tetrominoLocX, tetrominoLocY); break; }
	case 9: { BlockL3(tetrominoLocX, tetrominoLocY); break; }
	case 10: { BlockL4(tetrominoLocX, tetrominoLocY); break; }
	case 11: { BlockS1(tetrominoLocX, tetrominoLocY); break; }
	case 12: { BlockS2(tetrominoLocX, tetrominoLocY); break; }
	case 13: { BlockT1(tetrominoLocX, tetrominoLocY); break; }
	case 14: { BlockT2(tetrominoLocX, tetrominoLocY); break; }
	case 15: { BlockT3(tetrominoLocX, tetrominoLocY); break; }
	case 16: { BlockT4(tetrominoLocX, tetrominoLocY); break; }
	case 17: { BlockZ1(tetrominoLocX, tetrominoLocY); break; }
	case 18: { BlockZ2(tetrominoLocX, tetrominoLocY); break; }
	}
}

void PrintNextPiece(int x, int y)
{
	// Delete previous printed NEXT PIECE
	Colour(0);
	PrintXY(29, 4); PrintXY(30, 4); PrintXY(31, 4); PrintXY(32, 4); PrintXY(33, 4);
	PrintXY(29, 5); PrintXY(30, 5); PrintXY(31,5); PrintXY(32, 5); PrintXY(33, 5);
	PrintXY(29, 6); PrintXY(30, 6); PrintXY(31, 6); PrintXY(32, 6); PrintXY(33, 6);
	PrintXY(29, 7); PrintXY(30, 7); PrintXY(31, 7); PrintXY(32, 7); PrintXY(33, 7);
	PrintXY(29, 8); PrintXY(30, 8); PrintXY(31, 8); PrintXY(32, 8); PrintXY(33, 8);
	Colour(6);

	switch (NextPiece)
	{
	case 0:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 1, y + 2);
		PrintXY(x + 2, y + 2);
		break;
	}
	case 1:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 3, y + 1);
		break;
	}
	case 2:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x + 1, y + 3);
		break;
	}
	case 3:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 2, y + 2);
		PrintXY(x + 2, y + 1);
		break;
	}
	case 4:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x, y + 2);
		break;
	}
	case 5:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x, y);
		PrintXY(x + 2, y + 1);
		break;
	}
	case 6:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 2, y);
		PrintXY(x + 1, y + 2);
		break;
	}
	case 7:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x, y + 2);
		break;
	}
	case 8:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x + 2, y + 2);
		break;
	}
	case 9:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 2, y);
		break;
	}
	case 10:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x, y);
		break;
	}
	case 11:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 1, y + 2);
		PrintXY(x, y + 2);
		break;
	}
	case 12:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 2, y + 2);
		break;
	}
	case 13:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 2, y + 1);
		PrintXY(x + 1, y + 2);
		break;
	}
	case 14:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x + 2, y + 1);
		break;
	}
	case 15:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 2, y + 1);
		break;
	}
	case 16:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x + 1, y + 2);
		PrintXY(x, y + 1);
		break;
	}
	case 17:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x, y + 1);
		PrintXY(x + 1, y + 2);
		PrintXY(x + 2, y + 2);
		break;
	}
	case 18:
	{
		PrintXY(x + 1, y + 1);
		PrintXY(x + 1, y);
		PrintXY(x, y + 1);
		PrintXY(x, y + 2);
		break;
	}
	}
}
