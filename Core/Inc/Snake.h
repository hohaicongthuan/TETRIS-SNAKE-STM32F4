#include "main.h"
//============================================================
// "extern" keyword is used to avoid multiple definitions
// it makes variables visible to other source files that want
// to use them but variables are only defined in one place
// In this case, these variables are defined in Snake.cpp

extern int SnakeDirection;
extern int quitGame;
extern int pauseGame;
extern int GameOver;
extern int Score;
extern int DebugMode;

// Functions define
void BorderRender();
void Snake_Init();
Coordinate SpawnFood();
void Snake_InputHandler();
int CanMoveUpDown();
int CanMoveLeftRight();
void MoveSnake(int Direction);
void BoxRender();
int isFoodPosition(Coordinate x);
int isSnakeOrWall(Coordinate x);
void PrintScore();
void PrintDebugInfo();
void PrintPaused(int option);
void PrintGameOver(int option);
void Snake_main();
