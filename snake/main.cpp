#include "snake.h"

int main(){
	srand(time(NULL)); //�ܦ��H���ü� 
	SetUp();
	while(!gameOver){
		Draw();
		Input();
		Algorithm();
	}
	return 0;
}
