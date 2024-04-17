#include <iostream>
#include <string>
using namespace std;

void checktype() { //check which type of poker hand player have
	check = 1;
	suited();//check player have flush 
		straightflush();//checl if straight flush
	if check = 0 { //if it is straight flush, check = 0, no need to check for other type
		break;
	}
	quads();
	if check = 0 {//if it is quads, check = 0, no need to check for other type
		break;
	}
	
}
