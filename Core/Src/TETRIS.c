// TETRIS GAME BY CONG THUAN HO HAI & KIEU TRANG HA
// Well's size (Matrix size) 20 x 20
// 100% console interface

//============================================================

#include "main.h"
#include "TETRIS.h"
#include "Tetromino.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"

//============================================================

int tetris[30][30]; // Khai báo mảng

int TETRIS_Score = 0, HighScore = 0,
    tetrominoLocX = 0, tetrominoLocY = 0, // Tetromino Location X & Y
    DelayTime = 1, count = 0,
    ASCIIValue,
    dem = 1,
    Level = 1,
    FallingSpeed = 50000;

unsigned short int	CurrentState = 0,
                    NextPiece = 0,
                    colour;

// Quy ước các trạng thái của tetrominoes
// Vì "switch... case" không hỗ trợ dữ liệu chuỗi
// nên đành phải quy ước thành số nguyên

    // 'I1' = 1		'L4' = 10
    // 'I2' = 2		'S1' = 11
    // 'J1' = 3		'S2' = 12
    // 'J2' = 4		'T1' = 13
    // 'J3' = 5		'T2' = 14
    // 'J4' = 6		'T3' = 15
    // 'L1' = 7		'T4' = 16
    // 'L2' = 8		'Z1' = 17
    // 'L3' = 9		'Z2' = 18

char	key; // Stores keys that user pressed

bool	NewTetromino = true,
        CanMoveRight = true,
        CanMoveLeft = true,
        CanMoveDown = true,
        CanRotate = true,
        Pause = false,
        fullrow = false,
        GamePlay = false, // Checks whether the programme is in gameplay state or not
        disable = false; //để tạm dừng màn hình bên trái

//============================================================

void ArrayReset()
{
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++)
            tetris[j][i] = 0;

    for (int i = 0; i <= 21; i++)
    {
        tetris[i][22] = 1;
        tetris[21][i] = 1;
        tetris[0][i] = 1;
    }
}

void PrintArray(int x, int y) // In mảng bắt đầu từ vị trí có toạ độ (x, y)
{
    for (int i = 1; i <= 21; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            switch (tetris[j][i])
            {
            case 0: { Colour(0); PrintXY(j, i); break; }
            case 1: { Colour(1); PrintXY(j, i); break; }
            case 2: { Colour(2); PrintXY(j, i); break; }
            case 3: { Colour(3); PrintXY(j, i); break; }
            case 4: { Colour(4); PrintXY(j, i); break; }
            case 5: { Colour(5); PrintXY(j, i); break; }
            case 6: { Colour(6); PrintXY(j, i); break; }
            }
        }
    }
}

void ArrayDebug() // Print the actual array storing information
{
}

// Check full rows
// and delete full rows
// and return a value of deleted rows

void DeleteRow(int n)
{
    for (int i = 1; i <= 20; i++) tetris[i][n] = 0;
}

void MoveAllRowAbove(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 20; j >= 1; j--)
        {
            tetris[j][i] = tetris[j][i - 1];
        }
    }
}

int CheckFullRow() // Function that checks and returns a number of full rows
{
    int FullRow = 0;
    bool t = false;
    fullrow = false;
    for (int i = 1; i <= 21; i++)
    {
        for (int j = 1; j <= 21; j++)
        {
            if (tetris[j][i] == 0)
            {
                t = false;
                fullrow = t;
                break;
            }
            t = true;
            fullrow = t;
        }
        if (t)
        {
            FullRow++;
            DeleteRow(i);
            MoveAllRowAbove(i);
        }
    }
    return FullRow;
}

void PrintVariables()
{
}

void Refresh()
{
    PrintArray(1, 1);
    Colour(colour);
    PrintTetromino();
    Colour(6);

    PrintVariables();

    // Print score

    //Print next piece
    // PrintNextPiece(30, 4);

    // Print level
}

void InputProcess() // Function processing user's input
{
    if (isUSERKey() == 1) {
    	while (isUSERKey() == 1);
    	TETRIS_Snake = 1;
    }
	if (isLeftKey() == 1 && !Pause) // Moves current tetromino to the left if the 'a' key is pressed
    {
        while (isLeftKey() == 1) {
        	if (isKeyHold >= KEY_HOLD_TIME) break;
        	else isKeyHold++;
        }
    	if (CanMoveLeft) tetrominoLocX--;
        Refresh();
        if (isLeftKey() == 0) isKeyHold = 0;
    }
    if (isRightKey() == 1 && !Pause) // Moves current tetromino to the right if the 'd' key is pressed
    {
        while (isRightKey() == 1) {
        	if (isKeyHold >= KEY_HOLD_TIME) break;
        	else isKeyHold++;
        }
    	if (CanMoveRight) tetrominoLocX++;
        Refresh();
        if (isRightKey() == 0) isKeyHold = 0;
    }
    if (isDownKey() == 1 && !Pause) // Moves current tetromino down if the 's' key is pressed
    {
        // while (isDownKey() == 1);
    	if (CanMoveDown) if (tetrominoLocY < 20) tetrominoLocY++;
        Refresh();
    }
    if (isUpKey() == 1 && !Pause) // Change state of a tetromino when 'w' key is pressed
    {
        while (isUpKey() == 1);
    	if (CanRotate)
            switch (CurrentState)
            {
            case 1: { CurrentState = 2; break; }
            case 2: { CurrentState = 1; break; }
            case 3: { CurrentState = 4; break; }
            case 4: { CurrentState = 5; break; }
            case 5: { CurrentState = 6; break; }
            case 6: { CurrentState = 3; break; }
            case 7: { CurrentState = 8; break; }
            case 8: { CurrentState = 9; break; }
            case 9: { CurrentState = 10; break; }
            case 10: { CurrentState = 7; break; }
            case 11: { CurrentState = 12; break; }
            case 12: { CurrentState = 11; break; }
            case 13: { CurrentState = 14; break; }
            case 14: { CurrentState = 15; break; }
            case 15: { CurrentState = 16; break; }
            case 16: { CurrentState = 13; break; }
            case 17: { CurrentState = 18; break; }
            case 18: { CurrentState = 17; break; }
            }
        Refresh();
    }
}

void TETRIS_main() {
	if (1) {
		// Initialising
		ArrayReset();
		Colour(6); // Set default text colour to white
		NextPiece = Random(18); // Generate the first tetromino
		Level = 1;
		tetrominoLocX = Random(16) + 2;
		tetrominoLocY = 1;
		colour = Random(5) + 1;
		CurrentState = NextPiece;

		BSP_LCD_Clear(LCD_COLOR_BLACK);
		khung();

		while (TETRIS_Snake == 0) // Infinite loop (or game loop, technically)
		{
			InputProcess();
			// Statement checks whether a new tetromino should be generated
			if (NewTetromino && !Pause)
			{
				tetrominoLocX = Random(16) + 2;
				tetrominoLocY = 1;
				colour = Random(5) + 1;
				CurrentState = NextPiece;
				NextPiece = Random(18);
				TETRIS_Score += CheckFullRow() * 5;
				NewTetromino = false;

				khung();
				Refresh();

				// Print score
				TETRIS_PrintScore();

				// Print next piece
				BSP_LCD_SetFont(&Font12);
				BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
				BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
				BSP_LCD_DisplayStringAt(150, 15, (uint8_t *) "NEXT PIECE", LEFT_MODE);
				PrintNextPiece(30, 5);

				// Print level

				//Statement increases level
				if (TETRIS_Score % 10 == 0 && TETRIS_Score > 0 && fullrow)
				{
					Level++;
					FallingSpeed -= 20;
				}

			}

			// Statement controls the dropping speed of tetrominoes
			// The bigger the value, the slower the tetrominoes will drop
			if (DelayTime == FallingSpeed && !Pause)
			{
				tetrominoLocY++;
				DelayTime = 0;

				Refresh();
			}
			else if (!Pause) DelayTime++;

			// Statement ends the current game
			// A.K.A "GAME OVER"
			for (int i = 1; i <= 20; i++)
				if (tetris[i][2] != 0)
				{
					// Print "Game Over"
					BSP_LCD_SetFont(&Font12);
					BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
					BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
					BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 35, (uint8_t *)"GAME OVER", LEFT_MODE);
					Pause = true;
					if (isAnyKeyPressed() == 1) {
						// Delete "Game Over"
						BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
						BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
						BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 35, (uint8_t *)"GAME OVER", LEFT_MODE);
						Pause = false;
						ArrayReset();
						PrintArray(1, 1);
						TETRIS_Score = 0;
						Level = 1;
						NextPiece = Random(18);
						NewTetromino = true;
					}
				}
		}
	}
}

void khung() {
	for (int i = 0; i < 22; i++) {
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		PrintXY(i, 0);
	}

	for (int y = 0; y < 22; y++) {
		for (int x = 0; x < 22; x++) {
			if (x == 0 || x == 21) {
				BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
				PrintXY(x, y);
			}
		}
	}

	for (int i = 0; i < 22; i++) {
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			PrintXY(i, 22);
		}
}

void TETRIS_PrintScore() {
	int Digit[20], Score_temp;

	Score_temp = TETRIS_Score;

	BSP_LCD_SetFont(&Font12);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "SCORE:                ", LEFT_MODE);

	if (Score_temp == 0) {
		BSP_LCD_DisplayStringAt(49, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "0", LEFT_MODE);
	} else {
		int n = 0;
		while (Score_temp != 0) {
			Digit[n] = Score_temp % 10;
			n++;
			Score_temp /= 10;
		}
		int j = 0;
		for (int i = n - 1; i >= 0; i--) {
			switch (Digit[i]) {
			case 0:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "0", LEFT_MODE);
				j++;
				break;
			case 1:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "1", LEFT_MODE);
				j++;
				break;
			case 2:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "2", LEFT_MODE);
				j++;
				break;
			case 3:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "3", LEFT_MODE);
				j++;
				break;
			case 4:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "4", LEFT_MODE);
				j++;
				break;
			case 5:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "5", LEFT_MODE);
				j++;
				break;
			case 6:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "6", LEFT_MODE);
				j++;
				break;
			case 7:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "7", LEFT_MODE);
				j++;
				break;
			case 8:
				BSP_LCD_DisplayStringAt(49 + j, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "8", LEFT_MODE);
				j++;
				break;
			case 9:
				BSP_LCD_DisplayStringAt(49 + j*7, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "9", LEFT_MODE);
				j++;
				break;
			}
		}
	}
}
//============================================================
