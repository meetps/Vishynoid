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
	Move optimalMove();
	Board(list<Piece> white, list<Piece> black, int c){
		//cout<<"Making a board\n";
		whitePieces=white;
		blackPieces=black;
		color=c;
		//bestMove=optimalMove();
	}
	Board applyMove(Move m){
		Piece p1 = pieceAt(m.initial);
		int c=p1.color;
		Piece p2 = pieceAt(m.final);
		list<Piece> w2 = whitePieces;
		list<Piece> b2 = blackPieces;
		if(c==1){
			w2.remove(p1);
			w2.push_back(Piece(m.final, 1, p1.type));
			if(p2.type !=empty){
				b2.remove(p2);
			}
		}
		if(c==-1)
		{
			b2.remove(p1);
			b2.push_back(Piece(m.final, -1, p1.type));
			if(p2.type!=empty){
				w2.remove(p2);
			}
		}
		return Board(w2, b2, -color);
	}

    void display()
	{  
	//cout<<"in display\n";
    	string wtf[8][8]; 
    	for(int i =0;i < 8;i++)
    		{
    			for(int j =0; j<8 ;j++)
    				{
    					wtf[i][j] = " ";
    				}
    		}		
    	for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++)
        {
			Piece temp=*w;
			switch(temp.type){
			   case pawn:
			  	 wtf[temp.pos.x][temp.pos.y]=/*"\u2569"*/ "p";
			  	 break;
			   case knight: 
			   	wtf[temp.pos.x][temp.pos.y]=/*"\u2568"*/ "k";
			   	break;
			   case rook:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u2566"*/ "r";
			   break;
			   case bishop:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u2567"*/ "b";
			   break;
			   case queen:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u2565"*/ "q";
			   break;
			   case king:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u2564"*/ "o";
			   break;}

		}
        for(list<Piece>::iterator w=blackPieces.begin(); w!=blackPieces.end(); w++)
        {
			Piece temp=*w;
			switch(temp.type){
			   case pawn:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256f"*/ "P";
			   break;
			   case knight: 
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256e"*/ "K";
			   break;
			   case rook:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256c"*/ "R";
			   break;
			   case bishop:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256d"*/ "B";
			   break;
			   case queen:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256b"*/ "Q";
			   break;
			   case king:
			   wtf[temp.pos.x][temp.pos.y]=/*"\u256a"*/ "O";
			   break;}
		}
		for(int j =7;j >=0;j--)
    		{
    			for(int i =0; i<8 ;i++)
    				{
    					cout << wtf[i][j] << " ";
    				}
    			cout << endl;	
    		}
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
			
			
		if(color == 1){	
			for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++){
				Piece temp=*w;
				temp.setBoard(arr);
				list<Move> wMoves= temp.getMoves();
				ret.splice(ret.end(),wMoves);
			}
		}
		else{
			for(list<Piece>::iterator b=blackPieces.begin(); b!=blackPieces.end(); b++){
				Piece temp=*b;
				temp.setBoard(arr);
				list<Move> bMoves= temp.getMoves();
				ret.splice(ret.end(),bMoves);
			}
		}	
		return ret;
	}		
	
	float getBoardValue(int POV){
        float materialScore = 0;
        float mobilityScore = 0;

        for(list<Piece>::iterator w=whitePieces.begin(); w!=whitePieces.end(); w++)
        {
			Piece temp=*w;
			mobilityScore -= temp.getMoves().size();
			materialScore -= temp.pieceValue;	
		}
        for(list<Piece>::iterator w=blackPieces.begin(); w!=blackPieces.end(); w++)
        {
			Piece temp=*w;
			mobilityScore += temp.getMoves().size();
			materialScore += temp.pieceValue;	
		}
		
		float total= materialScore + mobilityScore*0.1 ;
		if(POV == -1)
			return total;
		return -total;
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
float nodeScore(Board b, float parentAlpha, float parentBeta, int depth, int color){
	//if N is leaf: return score wrt black
	//N is MAX if depth (0 index) is even
	//else MIN
	if(depth == recursionDepth)
		return b.getBoardValue(color);
	float thisAlpha = -10000;
	float thisBeta  = +10000;
	if(depth%2 == 1){ //MIN node
		list<Move> moves=b.getMoves();
		for(list<Move>::iterator curMove=moves.begin(); curMove!=moves.end(); curMove++){
			float temp = nodeScore(b.applyMove(*curMove), parentAlpha, min(thisBeta, parentBeta), depth+1, color);
			thisBeta=min(temp,thisBeta);
			if(parentAlpha >= thisBeta)
				return thisBeta;
			}
		return thisBeta;
	}
	if(depth%2 == 0){ //MAX node
		list<Move> moves=b.getMoves();
		for(list<Move>::iterator curMove=moves.begin(); curMove!=moves.end(); curMove++){
			float temp = nodeScore(b.applyMove(*curMove), max(thisAlpha, parentAlpha), parentBeta, depth+1,color);
			thisAlpha=max(temp,thisAlpha);
			if(thisAlpha >= parentBeta)
				return thisAlpha;
			}
		return thisAlpha;
	}		
	return 0;
}
Move Board::optimalMove(){
	list<Move> moves=getMoves();
	int bestScore=-10000;
	Move bestMove=Move(Position(), Position());
	for(list<Move>::iterator curMove=moves.begin(); curMove!=moves.end(); curMove++){
		int i= nodeScore(applyMove(*curMove), -10000, +10000, 1, color);
		if(i>bestScore){
			bestScore=i;
			bestMove=*curMove;
		}
	}
	return bestMove;
}

#endif
