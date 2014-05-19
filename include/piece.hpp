#ifndef PIECE
#define PIECE
#include<list>
#include "constants.hpp"
#include "move.hpp"
#include "position.hpp"
using namespace std;
enum pieceType {empty, pawn, rook, bishop, knight, queen, king};

class Piece{
	public:
	pieceType type;
	int pieceValue;
	Position pos;
	int color;	
	bool alive;
	Piece(Position p, int pc){
		pos=p;
		alive=true;
		color=pc;
	}
	virtual list<Move> getMoves(const int board[8][8])=0;
};
class Empty:public Piece{
	Empty(Position p, int pc=0):Piece(p,pc){
		alive=false;
	}
	list<Move> getMoves(const int board[8][8]){
		list<Move> ret;
		return ret;
	}
};
class Pawn:public Piece{
	Pawn(Position p, int pc):Piece(p,pc){
		type=pawn;
		pieceValue=pawnValue;
	}
	list<Move> getMoves(const int board[8][8]){
		list<Move> ret;
		int x=pos.x;
		int y=pos.y;
		int change= color==1 ? 1 : -1;
		if(board[x][y+change]==0) //one step ahead
			ret.push_front(Move(pos, Position(x,y+change))); 
		if((y==1 && color== 1 || y==6 && color==-1) && board[x][y+2*change]==0)//two steps ahead
			ret.push_front(Move(pos, Position(x, y+2*change)));
		if(x!=7 && board[x+1][y+change]== (-color))//one step ahead, and one to the right
			ret.push_front(Move(pos, Position(x+1,y+change)));
		if(x!=0 && board[x-1][y+change]== (-color))//one step ahead and one to the left
			ret.push_front(Move(pos, Position(x-1, y+change)));
		return ret;
	}
};
#endif
