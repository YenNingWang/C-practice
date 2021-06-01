#include "snake.h"

int main(){
	srand(time(NULL)); //變成隨機亂數 
	SetUp();
	while(!gameOver){
		Draw();
		Input();
		Algorithm();
	}
	return 0;
}
