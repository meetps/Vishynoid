#ifndef board
#define board
#include<list>
#include "position.hpp"
#include "move.hpp"
#include "piece.hpp"
class Board{
	public:
	list<Piece> whitePieces;
	list<Piece> blackPieces;
	int color;
	Move bestMove;
	Move optimalMove(){
		return Move(Position(), Position());
	}
	Board(list<Piece> white, list<Piece> black, int c){
		whitePieces=white;
		blackPieces=black;
		color=c;
		bestMove=optimalMove();
	}
	Board applyMove(Move m){
		return *this;
	}	
	list<Move> getMoves(){
		list<Move> ret;
		
		int arr[8][8];
		for(int i=0; i<=7; i++)
			for(int j=0; j<=7; j++)
				arr[i][j]=0;
		for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++)
			arr[(*w).pos.x][(*w).pos.y]=1;
		for(list<Piece>::iterator b=blackPieces.begin(); b!=blackPieces.end(); b++)
			arr[(*b).pos.x][(*b).pos.y]=-1;
			
			
			
		for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++){
			Piece temp=*w;
			temp.setBoard(arr);
			list<Move> wMoves= temp.getMoves();
			ret.splice(ret.end(),wMoves);
		}
		for(list<Piece>::iterator b=blackPieces.begin(); b!=blackPieces.end(); b++){
			Piece temp=*b;
			temp.setBoard(arr);
			list<Move> bMoves= temp.getMoves();
			ret.splice(ret.end(),bMoves);
		}
		return ret;
	}		
	int getBoardValue(){
		return 0;
	}
	
	Piece pieceAt(const Position p){
		for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++)
			if((*w).pos == p)
				return *w;
		for(list<Piece>::iterator b=blackPieces.begin(); b!=blackPieces.end(); b++)
			if((*b).pos == p)
				return *b;
		return Piece();
	}
};
#endif
