#include <iostream>
using namespace std;

int coordInt(string coord, int size){
	char col=coord[0];
	int row=(int)coord[1]-48, tot;
	switch (col){
	case 'A':
		tot=0;
		break;
	case 'B':
		tot=1;
		break;
	case 'C':
		tot=2;
		break;
	case 'D':
		tot=3;
		break;
	case 'E':
		tot=4;
		break;
	case 'F':
		tot=5;
		break;
	case 'G':
		tot=6;
		break;
	case 'H':
		tot=7;
		break;
	case 'I':
		tot=8;
		break;
	case 'J':
		tot=9;
		break;
	default:
		return -1;
	}
	return tot+(size*row);
}