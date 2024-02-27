#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


bool gameOver = false;
const int width = 20;
const int height = 20;
int x, y, FruitX, FruitY, score;
int tailX[100], tailY[100];
int nTail;
enum DIRECTION {STOP = 0, LEFT, RIGHT, UP, DOWN};
DIRECTION dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    srand(0);
    FruitX = rand() % 20;
    FruitY = rand() % 21;
    score = 0;
}
void Draw()
{
    system("cls");

    for (int i = 0; i <= width+1; i++)
    {
        cout << '#';
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++) 
        {
            if (j == 0)
            {
                cout << '#';
            }

            if (j == x && i == y)
            {
                cout << '0';
            }
            else if (j == FruitX && i == FruitY)
            {
                cout << 'F';
            }
            else
            {
                bool print = false;
                
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << 'o';
                        print = true;

                    }
                    
                    
                }
                
                    if (!print) {
                        cout << ' ';
                    } 

            }

            if (j == width)  
            {
                cout << '#';
            }
        }
        cout << endl;
    }


    for (int i = 0; i <= width+1; i++)
    {
        cout << '#';
    }
    cout << endl;

    cout << endl << score << "    " << FruitX << "     " << FruitY << endl;
    cout << endl << x << "    " << y << "\n";
}
void Input()
{
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    int prev2X, prev2Y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    if (x == FruitX && y == FruitY)
    {
        
        score+=10;
        FruitX = rand() % 19;
        FruitY = rand() % 19;
        nTail++;
        
    }
    switch (dir) 
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width -1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
       
        Draw();
        Input();
        Logic();
        Sleep(10);

        
    }

    return 0;
}

