#ifndef MOVE
#define MOVE
#include "position.hpp"
#include<iostream>
using namespace std;
class Move{
	public:
	Position initial;
	Position final;
	bool isValid;
	Move(){
		initial=Position();
		final=Position();
		isValid=true;
	}
	Move(Position p1, Position p2){
		initial=p1;
		final=p2;
		isValid=true;
	}
	void display(){
		cout<<initial.x<<","<<initial.y<<" to "<<final.x<<","<<final.y<<endl;
	}
};

#endif
