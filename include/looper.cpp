#include "board.hpp"
int main(){
	Move m = Board::doEverything("boardFile.txt", "ipFile.txt");
	ofstream f("stepperMove.txt");
	f<<m.initial.x<<" "<<(7-m.initial.y)<<" "<<m.final.x<<" "<<(7-m.final.y)<<endl;
	f.close();
}
