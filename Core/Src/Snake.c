#include "Snake.h"

//==================================================

int DebugMode = 0;

// The array SnakeCoord saves the coordinates of every
// parts of the snake
Coordinate SnakeCoord[SNAKE_BOX_SIZE_X * SNAKE_BOX_SIZE_Y];

// Food coordinates
Coordinate Food;

// Stores the most recent snake's direction
int SnakeDirection = DIRECTION_UP;

// The box in which the snake lives
int Box[SNAKE_BOX_SIZE_X][SNAKE_BOX_SIZE_Y];

int quitGame = 0;
int pauseGame = 0;
int GameOver = 0;
int Score = 0;

// This variable keeps track of the snake's length
// Default value is 1;
int SnakeSize = 1;

// This function will randomly generate and return
// the position of the food
Coordinate SpawnFood() {
    Coordinate temp;
    int isValidCoord = 1;
    
    // Spawn random coordinates for the food
    // Food cannot be spawned on occupied slot
    // of the snake
    do {
        isValidCoord = 1;
        temp.x = Random(SNAKE_BOX_SIZE_X - 2);
        temp.y = Random(SNAKE_BOX_SIZE_Y - 2);

        // Check if the spawned position is occupied
        for (int i = 1; i <= SnakeSize; i++) {
            if ((SnakeCoord[i].x == temp.x &&
                SnakeCoord[i].y == temp.y) ||
                (Food.x == temp.x &&
                Food.y == temp.y)) {
                isValidCoord = 0;
                break;
            }
        }
    } while (!isValidCoord);

    return temp;
}

// This function will print the border
void BorderRender() {
	int loc_X, loc_Y;
	loc_X = PIXEL_SPACE;
	loc_Y = PIXEL_SPACE;

	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	for (int i = 0; i < SNAKE_BOX_SIZE_X; i++) {
		//HAL_Delay(2);
		BSP_LCD_FillRect(loc_X, loc_Y, PIXEL_SIZE, PIXEL_SIZE);
		loc_X += PIXEL_SPACE + PIXEL_SIZE;
	}

	loc_X = PIXEL_SPACE;
	loc_Y = PIXEL_SPACE * 2 + PIXEL_SIZE;

	for (int i = 0; i < SNAKE_BOX_SIZE_Y - 2; i++) {
		for (int j = 0; j < SNAKE_BOX_SIZE_X; j++) {
			// HAL_Delay(2);
			if (j == 0) BSP_LCD_FillRect(loc_X, loc_Y, PIXEL_SIZE, PIXEL_SIZE);
			if (j == SNAKE_BOX_SIZE_X - 1) BSP_LCD_FillRect(loc_X, loc_Y, PIXEL_SIZE, PIXEL_SIZE);
			loc_X += PIXEL_SPACE + PIXEL_SIZE;
		}
		loc_X = PIXEL_SPACE;
		loc_Y += PIXEL_SPACE + PIXEL_SIZE;
	}

	for (int i = 0; i < SNAKE_BOX_SIZE_X; i++) {
		// HAL_Delay(2);
		BSP_LCD_FillRect(loc_X, loc_Y, PIXEL_SIZE, PIXEL_SIZE);
		loc_X += PIXEL_SPACE + PIXEL_SIZE;
	}
}

// This function will render the screen
void BoxRender() {
	int loc_X, loc_Y;
	loc_X = PIXEL_SPACE + PIXEL_SIZE;
	loc_Y = PIXEL_SPACE + PIXEL_SIZE;

	// Reset matrix
    for (int y = 0; y < SNAKE_BOX_SIZE_Y; y++) {
        for (int x = 0; x < SNAKE_BOX_SIZE_X; x++) {
            Box[x][y] = BLANK;
        }
    }
    
    // Set snake's position in the box
    for (int i = 1; i <= SnakeSize; i++) {
        Box[SnakeCoord[i].x][SnakeCoord[i].y] = SNAKE;
    }

    // Set food's position on the box
    Box[Food.x][Food.y] = FOOD;
    
    // Print the matrix
    for (int y = 0; y < SNAKE_BOX_SIZE_Y - 2; y++) {
        for (int x = 0; x < SNAKE_BOX_SIZE_X - 2; x++) {
        	//HAL_Delay(2);
        	if (Box[x][y] == SNAKE)
        		BSP_LCD_SetTextColor(SNAKE_PIXEL);
        	else if (Box[x][y] == FOOD)
        		BSP_LCD_SetTextColor(FOOD_PIXEL);
        	else BSP_LCD_SetTextColor(BLANK_PIXEL);
        		BSP_LCD_FillRect(loc_X, loc_Y, PIXEL_SIZE, PIXEL_SIZE);
        	loc_X += PIXEL_SPACE + PIXEL_SIZE;
        }
        loc_X = PIXEL_SPACE + PIXEL_SIZE;
        loc_Y += PIXEL_SPACE + PIXEL_SIZE;
    }
}

void Snake_Init() {
    Coordinate temp;
    SnakeSize = 2;
    temp.x = SNAKE_BOX_SIZE_X / 2;
    temp.y = SNAKE_BOX_SIZE_Y / 2;
    SnakeCoord[1] = temp;
    temp.y = temp.y + 1;
    SnakeCoord[2] = temp;
    SnakeDirection = DIRECTION_UP;

    quitGame = 0;
    pauseGame = 0;
    GameOver = 0;
    Score = 0;

    BSP_LCD_Clear(LCD_COLOR_BLACK);

    // Spawn random coordinates for the food
    Food = SpawnFood();

    // Draw
    BorderRender();
    BoxRender();
    PrintScore();
}

// Checks if the snake can move up/down
int CanMoveUpDown() {
    if (SnakeCoord[1].y == SnakeCoord[2].y) return 1;
    else return 0;
}

// Checks if the snake can move left/right
int CanMoveLeftRight() {
    if (SnakeCoord[1].x == SnakeCoord[2].x) return 1;
    else return 0;
}

// Check if a position is the same as food's position
int isFoodPosition(Coordinate x) {
    if (Food.x == x.x && Food.y == x.y) return 1;
    else return 0;
}

// This function will check whether a position is
// one of the snake's or the wall
int isSnakeOrWall(Coordinate x) {
    // Check if the position is out of the box
    if (x.x > SNAKE_BOX_SIZE_X - 3 || x.y > SNAKE_BOX_SIZE_Y - 3 || x.x < 0 || x.y < 0) return 1;

    // Check if the position is already one of
    // the snake's aka the snake collides itself
    for (int i = 1; i <= SnakeSize; i++) {
        if (SnakeCoord[i].x == x.x &&
            SnakeCoord[i].y == x.y) return 1;
    }

    // None of these conditions are met
    return 0;
}

void PrintScore() {
	int Digit[20], Score_temp;

	Score_temp = Score;

	BSP_LCD_SetFont(&Font12);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 20, (uint8_t *) "SCORE:              ", LEFT_MODE);

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

// UNUSED
void PrintDebugInfo() {}

// This function will print a message to notify
// that the game is paused if option = 1
// otherwise, it'll delete the message
// UNUSED
void PrintPaused(int option) {
	BSP_LCD_SetFont(&Font12);
		if (option) {
			BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
			BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
			BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"GAME PAUSED", LEFT_MODE);
		}
	    else {
	    	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	    	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	    	BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"GAME PAUSED", LEFT_MODE);
	    }
}

// This function will print a message to notify
// that the game is over if option = 1
// otherwise, it'll delete the message
void PrintGameOver(int option) {
	BSP_LCD_SetFont(&Font12);
	if (option) {
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"GAME OVER", LEFT_MODE);
	}
    else {
    	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
    	BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"GAME OVER", LEFT_MODE);
    }
}

// This function will move the snake in a direction
// Consume food if it's in the way
void MoveSnake(int Direction) {
    Coordinate temp;
    
    switch (Direction) {
    case DIRECTION_UP:
        temp = SnakeCoord[1];
        temp.y = temp.y - 1;
        
        // If the snake moves towards the wall or itself
        // the game is over
        if (isSnakeOrWall(temp) == 1) {
            GameOver = 1;
            PrintGameOver(1);
        }

        if (isFoodPosition(temp) == 1) {
            SnakeSize++;
            Food = SpawnFood();
            Score += 5;
            PrintScore();
        }

        // Shift a the snake's pixel up
        // (lower part's coordinates = upper part's coordinates)
        for (int i = SnakeSize; i > 1; i--) {
            SnakeCoord[i] = SnakeCoord[i - 1];
        }

        // Set new head coordinates
        SnakeCoord[1] = temp;

        // Set snake's direction
        SnakeDirection = DIRECTION_UP;

        break;
    case DIRECTION_DOWN:
        temp = SnakeCoord[1];
        temp.y = temp.y + 1;

        // If the snake moves towards the wall or itself
        // the game is over
        if (isSnakeOrWall(temp) == 1) {
            GameOver = 1;
            PrintGameOver(1);
        }

        if (isFoodPosition(temp) == 1) {
            SnakeSize++;
            Food = SpawnFood();
            Score += 5;
            PrintScore();
        }

        // Shift a the snake's pixel up
        // (lower part's coordinates = upper part's coordinates)
        for (int i = SnakeSize; i > 1; i--) {
            SnakeCoord[i] = SnakeCoord[i - 1];
        }

        // Set new head coordinates
        SnakeCoord[1] = temp;

        // Set snake's direction
        SnakeDirection = DIRECTION_DOWN;

        break;
    case DIRECTION_LEFT:
        temp = SnakeCoord[1];
        temp.x = temp.x - 1;

        // If the snake moves towards the wall or itself
        // the game is over
        if (isSnakeOrWall(temp) == 1) {
            GameOver = 1;
            PrintGameOver(1);
        }

        if (isFoodPosition(temp) == 1) {
            SnakeSize++;
            Food = SpawnFood();
            Score += 5;
            PrintScore();
        }

        // Shift a the snake's pixel up
        // (lower part's coordinates = upper part's coordinates)
        for (int i = SnakeSize; i > 1; i--) {
            SnakeCoord[i] = SnakeCoord[i - 1];
        }

        // Set new head coordinates
        SnakeCoord[1] = temp;

        // Set snake's direction
        SnakeDirection = DIRECTION_LEFT;

        break;
    case DIRECTION_RIGHT:
        temp = SnakeCoord[1];
        temp.x = temp.x + 1;

        // If the snake moves towards the wall or itself
        // the game is over
        if (isSnakeOrWall(temp) == 1) {
            GameOver = 1;
            PrintGameOver(1);
        }

        if (isFoodPosition(temp) == 1) {
            SnakeSize++;
            Food = SpawnFood();
            Score += 5;
            PrintScore();
        }

        // Shift a the snake's pixel up
        // (lower part's coordinates = upper part's coordinates)
        for (int i = SnakeSize; i > 1; i--) {
            SnakeCoord[i] = SnakeCoord[i - 1];
        }

        // Set new head coordinates
        SnakeCoord[1] = temp;

        // Set snake's direction
        SnakeDirection = DIRECTION_RIGHT;

        break;
    }
}

void Snake_InputHandler() {
	if (isUSERKey() == 1) { while (isUSERKey() == 1); TETRIS_Snake = 0; }
	if (isUpKey() == 1 && CanMoveUpDown() == 1) MoveSnake(DIRECTION_UP);
	if (isDownKey() == 1 && CanMoveUpDown() == 1) MoveSnake(DIRECTION_DOWN);
	if (isLeftKey() == 1 && CanMoveLeftRight() == 1) MoveSnake(DIRECTION_LEFT);
	if (isRightKey() == 1 && CanMoveLeftRight() == 1) MoveSnake(DIRECTION_RIGHT);
}

void Snake_main() {
	bool Initial = true;
	int Delay = 0;
	while (TETRIS_Snake == 1) {
		if (Initial) {
			Snake_Init();
			Initial = false;
		}
		if (GameOver != 1) {
			// Reset delay if some key is hit
			if (isAnyKeyPressed() == 1) Delay = 0;
			Snake_InputHandler();
			if (pauseGame != 1) {
	  	    	Delay++;
	  	    	BoxRender();
	  	    	if (Delay >= SNAKE_DELAY) {
	  	    		MoveSnake(SnakeDirection);
	  	    		BoxRender();
	  	    		Delay = 0;
	  	    	}
	  	    }
	  	 }
	  	 else {
	  	    if (isAnyKeyPressed() == 1) {
	  	    	// BSP_LCD_Clear(LCD_COLOR_BLACK);
	  	    	Snake_Init();
	  	    	PrintGameOver(0);
	  	    	GameOver = 0;
	  	    }
	  	}
	}
}
