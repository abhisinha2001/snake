#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
int dir;
const int height = 18;
const int width = 18;
int j;
int i;
int fx;
int fy;
int x;
int y;
int gameover = 0;
int score = 0;
int b = 0;
void fruit()
{

  randomize();
  fx = random(18) + 1;
  fy = random(18) + 1;
}

void init()
{
  x = width / 2;
  y = height / 2;
  randomize();
  fx = random(13) + 1;
  fy = random(13) + 1;
  // dir.left=dir.right=x;
  // dir.up=dir.down=y;
}
void Input()
{
  if (kbhit())
  {
    switch (getch())
    {
    case 'a':
      dir = 1;
      //	    x--;
      break;
    case 'w':
      dir = 2;
      // y--;
      break;
    case 's':
      dir = 3;
      // y++;

      break;
    case 'd':
      dir = 4;
      // x++;
      break;
    }
  }
  switch (dir)
  {
  case 1:
    x--;
    break;
  case 2:
    y--;
    break;
  case 3:
    y++;
    break;
  case 4:
    x++;
    break;
  }
}

void display()
{
  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      delay(1);
      if (i == 0)
        cout << "*";
      else if (i == height - 1)
        cout << "*";
      else if (j == 0)
        cout << "*";
      else if (j == width - 1)
        cout << "*";
      else if (x == height || y == width)
        gameover = 1;
      else if (x == -2 || y == -2)
        gameover = 1;

      else if (fx == j && fy == i)
        cout << "F";
      else
        cout << " ";
      for (int a = 0; a < b; a++) // meant for body segment
      {
        if (x == j && y == i - a)
          cout << "o";
      }
      if (x == j && y == i)
      {
        cout << "O";
      }

      if (fx == x && fy == y)
      {
        b += 1;
        x--;
        y--;
        fruit();
        score += 10;
        break;
      }
    }

    cout << endl;
  }
  cout << score << "\n";

  // cout<<fx<<"\t"<<fy;

  clrscr();
}

void main()
{
  clrscr();
  init();
  while (!gameover)
  {
    Input();
    display();
    // snake();
  }
}
