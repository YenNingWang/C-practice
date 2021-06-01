#include <iostream>
#include <windows.h> //會用到windows 的API 
#include <conio.h> //偵測使用者的鍵盤 
#include <cstdlib> //使用亂數 
#include <ctime> //用時間初始化它 

using namespace std;

// 遊戲變數宣告 
bool gameOver; //判斷遊戲是否結束
const int width = 25;
const int height = 15;
int x, y, coinX, coinY, score;
int nTail; // 紀錄目前蛇的長度
int tailX[150]; int tailY[150]; //存蛇身體的座標 
int direction; //用數字代表上下左右移動方向 
const int Stop = 0, Left = 1, Right = 2, Up = 3, Down = 4;


// 函數 
void Clear() //更新畫面時刪除畫面用的 
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = 0; //游標位置初始化 
  scrn.Y = 0;
  SetConsoleCursorPosition(hOuput,scrn);
  return;
}


void SetUp(){ //初始化遊戲變數 
	gameOver = 0;
	direction = Stop;
	x = width/2;
	y = height/2;
	flag : 
	coinX = rand() % (width - 1)+1;
	coinY = rand() % (height - 1)+1;
	if (x == coinX && y == coinY){ //避免蛇的頭一開始就跟錢幣位置一樣 
		goto flag;
	}
	return;
}


void Draw(){ //產生遊戲畫面 
	Sleep(100);  //讓畫面暫停 sleep單位毫秒 
	Clear();
	
	for(int i = 0; i < width+2; i++){
		cout << "#";
	}
	cout << endl;
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(j ==0){
				cout << "#";
			}	
			if(i == y && j == x){
				cout << "*";
		}
			else if(i == coinY && j == coinX){
				cout << "$";
			}
			else{
				bool printSnake = false;
				for(int k = 0; k < nTail; k++){
					if(tailX[k] == j && tailY[k] == i){
						cout << "*";
						printSnake = true;
					} 
					if(!printSnake){
					cout << " ";
					}
				}
			if(j == width-1){
				cout << "#";
				}
			}
	cout << endl;	
	}

	for(int i = 0; i < width+2; i++){
		cout << "#";
		}
	cout << endl;
	cout << "Score: " << score << endl; 
	
	return;
}} 

 //接收輸入值 
void Input(){
	if(kbhit()){
		switch(getch()){
			case 'a' :
				direction = Left;
				break;
			case 'd' :
				direction = Right;
				break;
			case 'w' :
				direction = Up;
				break;
			case 's' :
				direction = Down;
				break;
			case 'p' :
				direction = Stop;
				break;
		}
	}
		return;
}

//包含遊戲的演算法 
void Algorithm(){ 
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < nTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		
		tailX[i] = prevX;
		tailY[i] = prevY;
		
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch(direction){
		case Left:
			x--;
			break;
		case Right:
			x++;
			break;
		case Up:
			y--;
			break;
		case Down:
			y++;
			break;
	}
	
	if(x >= width){
		x = 0;
	}
	else if(x < 0){
		x = width - 1;
	}
	if(y >= height){
		y = 0;
	}
	else if(y < 0){
		y = height - 1;
	}
	
	for(int i = 0; i < nTail; i++){
		if(tailX[i] == x && tailY[i] == y){
			gameOver = true;
			return;
		}
	}
	
	if(x == coinX && y == coinY){
		score += 100;
			coinX = rand() % (width - 1)+1;
			coinY = rand() % (height - 1)+1;
			nTail ++;
	}
	
	return;
}
