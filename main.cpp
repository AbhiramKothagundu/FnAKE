#include <iostream>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <time.h>
using namespace std;
bool gameOver;

const int width = 20;
const int height = 15;

int x,y,fruitX,fruitY,score;

vector<pair<int,int>> snake;

enum eDirection {STOP = 0 , UP ,LEFT , RIGHT , DOWN};
eDirection dir;

void Mainmenu();

void Setup()
{
    srand(time(NULL));
    system("cls");

    gameOver = false;
    dir = STOP;
    x = width /2;
    y = height /2;

    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    Mainmenu();

}
void Draw()
{
    system("cls");
    for(int i=0 ; i<width+2 ;i++)
    {
        cout<<"#";
    }
    cout<<"  Score : "<<score<<endl;

    for(int i=0 ; i < height ; i++)
    {
        for(int j=0; j<width ; j++)
        {
            if(j == 0)
                cout<<"#";

            if(i == y && j == x)
            {
                cout<<"@";
            }else if(i == fruitY && j == fruitX)
            {
                cout<<"F";
            }else
            {
                bool print = false;
                for(int k=0 ; k< snake.size() ; k++)
                {
                    if(snake[k].first == j && snake[k].second == i)
                    {
                        cout<<"o";
                    }
                }
                if (!print) cout << " ";

            }



            if(j == width -1)
                cout<<"#";

        }
        cout<<endl;
    }
    for(int i=0 ; i<width +2;i++)
    {
        cout<<"#";
    }
    cout<<endl;

}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'd':
            dir = RIGHT;
            break;
        }
    }
}
void Logic()
{
    int prevX = x;
    int prevY = y;


    int tempX;
    int tempY;

    int temp2X = prevX;
    int temp2Y = prevY;

    for(int i=0 ; i<snake.size() ; i++)
    {
        tempX = snake[i].first;
        tempY = snake[i].second;
        snake[i].first = temp2X;
        snake[i].second = temp2Y;

        temp2X = tempX;
        temp2Y = tempY;

    }


    switch(dir)
    {
    case LEFT:
        x = (x - 1) %width;
        if(x <0)
        {
            x = width-1;
        }
        break;
    case DOWN:
        y = (y+1) % height;
        break;
    case UP:
        y = (y-1) % height;

        if(y < 0)
        {
            y = height-1;
        }
        break;
    case RIGHT:
        x = (x + 1) %width;
        break;
    }

    if(x == fruitX && y == fruitY)
    {
        score++;
        snake.push_back(make_pair(prevX,prevY));
        fruitX = rand()%width;
        fruitY = rand()%height;
    }

    for (int i = 0; i < snake.size(); i++)
    {
        if (x == snake[i].first && y == snake[i].second)
        {
            gameOver = true;
            break;
        }
    }
}

void Mainmenu()
{
    char key;
    do
    {
        for (int i = 0; i < width; i++) { cout << '#'; } cout << endl;

        cout << "FnAKE_fully Original Game" << endl;
        cout << "play : <space_bar>" << endl;
        cout << "exit : <e>" << endl;

        cout<<endl<<endl<<"made by Abhiram Kothagundu"<<endl;

        for (int i = 0; i < width; i++) { cout << '#'; } cout << endl;

        key = _getch();
        if (key == 'e')
        {
            gameOver = true;
            break;
        }

    } while (key != ' ');
}



int main()
{
    Setup();

    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    system("cls");
    cout<<"The End"<<endl;
    return 0;
}
