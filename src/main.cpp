#include<iostream>
/*#include<fstream>
#include<algorithm>*/

#include "include/*.hpp"

/*class Chess
{
	public :
    int Initialize(int board);
      {
         int board [8][8];
                //Pawns         
         for(int = 0;i<8;i++)
            {
                 board[i][1] =  1;
                 board[i][6] = -1;
            }    
               //Elephants
                 board[0][0] =   2;
                 board[0][7] =  -2;
                 board[7][0] =   2;
                 board[7][7] =  -2;
               //Horses  
                 board[1][0] =   3;
                 board[1][7] =  -3;
                 board[6][0] =   3;
                 board[6][7] =  -3;
               //Camels  
                 board[2][0] =   4;
                 board[2][7] =  -4;
                 board[5][0] =   4;
                 board[5][7] =  -4;
               //Queens  
                 board[4][0] =   5;
                 board[4][7] =  -5;
               //Kings
                 board[3][0] =   6;
                 board[3][7] =  -6;               
      }
    int CalculateDamage();
    int CheckHorseMove();
    int CheckPawnMove();
    int CheckElephantMove();
    int CheckCheck();
    int CheckQueenMove();
    int CheckCamelMove();
    int CheckKingMove();
    int chessboard[8][8] = Initialize(chessboard);
};*/

namespace rpi
{
	int Move();
	int FeedChanges();
	int CameraStatus();
	int displayscore();
}
namespace camera
{
	float getstatus();
	float recognise();
	int SetBoardStatus();
}
namespace speech
{
	float getuserinput();
} 

int main()
{

	
}
