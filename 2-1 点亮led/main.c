// Light LED
#include <REGX52.H>

void main(){
	P2 = 0xFE; //binary 1111 1110 --> dex(16) 0->ON 1->OFF
	while(1) { //Prevent always write P2
		
	}
}