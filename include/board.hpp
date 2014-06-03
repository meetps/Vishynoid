#ifndef board
#define board
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include "position.hpp"
#include "move.hpp"
#include "piece.hpp"
class Board {
public:
	vector<Piece> whitePieces;
	vector<Piece> blackPieces;
	char color;
	Move bestMove;
	Move optimalMove(bool);
	Board(vector<Piece> white, vector<Piece> black, char c) {
		//cout<<"Making a board\n";
		whitePieces = white;
		blackPieces = black;
		color = c;
		//bestMove=optimalMove();
	}
	Board applyMove(Move m) {
		Piece p1 = pieceAt(m.initial);
		char c = p1.color;
		Piece p2 = pieceAt(m.final);
		vector<Piece> w2 = whitePieces;
		vector<Piece> b2 = blackPieces;
		if (c == 1) {
			//p1 should now be at final, not initial; search in white
			//w2.remove(p1);
			//w2.push_back(Piece(m.final, 1, p1.type));
			for (vector<Piece>::iterator it = w2.begin(); it != w2.end(); it++)
				if (*it == p1)
					it->pos = m.final;

			//set p2 to dead; search in black
			for (vector<Piece>::iterator it = b2.begin(); it != b2.end(); it++)
				if (*it == p2)
					it->alive = false;
		}
		if (c == -1) {
			//p1 should now be at final, not initial; search in black
			//b2.remove(p1);
			//b2.push_back(Piece(m.final, -1, p1.type));
			for (vector<Piece>::iterator it = b2.begin(); it != b2.end(); it++)
				if (*it == p1)
					it->pos = m.final;

			//set p2 to dead; search in white
			for (vector<Piece>::iterator it = w2.begin(); it != w2.end(); it++)
				if (*it == p2)
					it->alive = false;
		}
		return Board(w2, b2, -color);
	}

	void display() {
		cout << (color == 1 ? "white" : "black") << " to play!\n";
		
		string wtf[8][8];
		for (char i = 0; i < 8; i++) {
			for (char j = 0; j < 8; j++) {
				wtf[i][j] = "\xe2\x98\x90";
			}
		}
		for (vector<Piece>::iterator w = whitePieces.begin();
				w != whitePieces.end(); w++) {
			Piece temp = *w;
		   if(temp.alive)
 			{	
			switch (temp.type) 
				{
			case pawn:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x99";
				break;
			case knight:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x98";
				break;
			case rook:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x96";
				break;
			case bishop:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x97";
				break;
			case queen:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x95";
				break;
			case king:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x94";
				break;
				}
			}

		}
		for (vector<Piece>::iterator w = blackPieces.begin();
				w != blackPieces.end(); w++) {
			Piece temp = *w;
			if(temp.alive)
			{
			switch (temp.type) 
					{
			case pawn:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9f";
				break;
			case knight:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9e";
				break;
			case rook:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9c";
				break;
			case bishop:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9d";
				break;
			case queen:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9b";
				break;
			case king:
				wtf[temp.pos.x][temp.pos.y] = "\xe2\x99\x9a";
				break;
					}
			}

		}
		cout << " ";
		cout << "________________\n|";
		for (char j = 7; j >= 0; j--)

		{
			for (char i = 0; i < 8; i++) {
				cout << wtf[i][j] << " ";
			}
			
			cout << "|"<<(int)j;
			cout << endl;
			if (j != 0)
				cout << "|";
		}
		cout << " ";
		for (char k = 0; k < 16; k++) {
			cout << "\xe2\x80\xbe";
		}
		cout<<"\n 0 1 2 3 4 5 6 7\n";
		
		cout << "\n";
	}

	vector<Move> getMoves() {
		vector<Move> ret;

		char arr[8][8];
		for (char i = 0; i <= 7; i++)
			for (char j = 0; j <= 7; j++)
				arr[i][j] = 0;
		for (vector<Piece>::iterator w = whitePieces.begin();
				w != whitePieces.end(); w++)
			if (isValid(w->pos.x, w->pos.y))
				arr[(*w).pos.x][(*w).pos.y] = 1;
		for (vector<Piece>::iterator b = blackPieces.begin();
				b != blackPieces.end(); b++)
			if (isValid(b->pos.x, b->pos.y))
				arr[(*b).pos.x][(*b).pos.y] = -1;

		if (color == 1) {
			for (vector<Piece>::iterator w = whitePieces.begin();
					w != whitePieces.end(); w++) {
				Piece temp = *w;
				vector<Move> wMoves = temp.getMoves(arr);
				ret.insert(ret.end(), wMoves.begin(), wMoves.end());
			}
		} else {
			for (vector<Piece>::iterator b = blackPieces.begin();
					b != blackPieces.end(); b++) {
				Piece temp = *b;
				vector<Move> bMoves = temp.getMoves(arr);
				ret.insert(ret.end(), bMoves.begin(), bMoves.end());
			}
		}
		for (vector<Move>::iterator m = ret.begin(); m != ret.end(); m++) {
			m->value = pieceAt(m->final).piecePositionValue()
					+ pieceAt(m->initial).piecePositionValue();
		}
		return ret;
	}
	bool isCheck(int c){
		int original=color;
		color=-c;
		vector<Move> moves=getMoves();
		for(vector<Move>::iterator curMove=moves.begin(); curMove!= moves.end(); curMove++){
			Piece temp = pieceAt(curMove->final);
			if(temp.type == king && temp.color==1){
				color=original;
				return true;
			}
		}
		color=original;
		return false;
	}
	float getBoardValue(char POV) {
		float materialScore = 0;
		float mobilityScore = 0;
		char arr[8][8];
		bool whiteCheck = false, blackCheck = false;
		for (char i = 0; i <= 7; i++)
			for (char j = 0; j <= 7; j++)
				arr[i][j] = 0;
		for (vector<Piece>::iterator w = whitePieces.begin();
				w != whitePieces.end(); w++)
			if (w->alive)
				arr[(*w).pos.x][(*w).pos.y] = 1;
		for (vector<Piece>::iterator b = blackPieces.begin();
				b != blackPieces.end(); b++)
			if (b->alive)
				arr[(*b).pos.x][(*b).pos.y] = -1;
		vector<Move> cur;
		for (vector<Piece>::iterator w = whitePieces.begin();
				w != whitePieces.end(); w++) {
			Piece temp = *w;
			cur = temp.getMoves(arr);
			mobilityScore -= cur.size();
			materialScore -= temp.piecePositionValue();
		}
		for (vector<Piece>::iterator w = blackPieces.begin();
				w != blackPieces.end(); w++) {
			Piece temp = *w;
			cur = temp.getMoves(arr);
			mobilityScore += cur.size();
			materialScore += temp.piecePositionValue();
		}
		
		float total = materialScore + mobilityScore * 0.1;
		if (POV == -1)
			return total;
		return -total;
	}

	Piece pieceAt(const Position p) {
		if (!isValid(p.x, p.y))
			return Piece();
		for (vector<Piece>::iterator w = whitePieces.begin();
				w != whitePieces.end(); w++)
			if ((*w).pos == p)
				return *w;
		for (vector<Piece>::iterator b = blackPieces.begin();
				b != blackPieces.end(); b++)
			if ((*b).pos == p)
				return *b;
		return Piece();
	}
};
float nodeScore(Board b, float parentAlpha, float parentBeta, char depth,
		char color, bool display = false) {
	//if N is leaf: return score wrt black
	//N is MAX if depth (0 index) is even
	//else MIN
	//int thisValue = b.getBoardValue(color);
	if (depth == recursionDepth)
		return b.getBoardValue(color);
	float thisAlpha = -INFY;
	float thisBeta = +INFY;
	int branchingFactor = 0;
	
	//move ordering
	vector<Move> moves = b.getMoves();
	sort(moves.begin(), moves.end()); //based on pieceValues at beginning and end
	for (vector<Move>::iterator curMove = moves.begin(); curMove != moves.end();
			curMove++)
		curMove->value = b.applyMove(*curMove).getBoardValue(color);
	sort(moves.begin(), moves.end());

	if (depth % 2 == 0) //MAX nodes want biggest first
		reverse(moves.begin(), moves.end());

	if (depth % 2 == 1) { //MIN node
		for (vector<Move>::iterator curMove = moves.begin();
				curMove != moves.end(); curMove++) {
			Board tempBoard=b.applyMove(*curMove);
			if(tempBoard.isCheck(-tempBoard.color))
				continue;
			float temp = nodeScore(tempBoard, parentAlpha,
					min(thisBeta, parentBeta), depth + 1, color, display);
			thisBeta = min(temp, thisBeta);
			if (parentAlpha >= thisBeta) {
				if (display)
					cout << branchingFactor << endl;
				return thisBeta;
			}
			branchingFactor++;
		}
		if (display)
			cout << branchingFactor << endl;
		return thisBeta;
	}
	if (depth % 2 == 0) { //MAX node
		for (vector<Move>::iterator curMove = moves.begin();
				curMove != moves.end(); curMove++) {
			Board tempBoard=b.applyMove(*curMove);
			if(tempBoard.isCheck(-tempBoard.color))
				continue;
			float temp = nodeScore(tempBoard,
					max(thisAlpha, parentAlpha), parentBeta, depth + 1, color,
					display);
			thisAlpha = max(temp, thisAlpha);
			if (thisAlpha >= parentBeta) {
				if (display)
					cout << branchingFactor << endl;
				return thisAlpha;
			}
			branchingFactor++;
		}
		if (display)
			cout << branchingFactor << endl;
		return thisAlpha;
	}
	return b.getBoardValue(color);
}
Move Board::optimalMove(bool display = false) {
	vector<Move> moves = getMoves();
	int bestScore = -INFY;
	Move bestMove = Move(Position(), Position());
	for (vector<Move>::iterator curMove = moves.begin(); curMove != moves.end();
			curMove++) {
		Board tempBoard=applyMove(*curMove);
		if(tempBoard.isCheck(-tempBoard.color))
			continue;
		int i = nodeScore(tempBoard, -INFY, +INFY, 1, color,
				display);
		cout<<"Node score: "<<i<<" ";
		curMove->display();
		if (i > bestScore) {
			bestScore = i;
			bestMove = *curMove;
		}
	}
	return bestMove;
}

#endif
