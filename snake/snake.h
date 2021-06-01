#include <iostream>
#include <windows.h> //�|�Ψ�windows ��API 
#include <conio.h> //�����ϥΪ̪���L 
#include <cstdlib> //�ϥζü� 
#include <ctime> //�ήɶ���l�ƥ� 

using namespace std;

// �C���ܼƫŧi 
bool gameOver; //�P�_�C���O�_����
const int width = 25;
const int height = 15;
int x, y, coinX, coinY, score;
int nTail; // �����ثe�D������
int tailX[150]; int tailY[150]; //�s�D���骺�y�� 
int direction; //�μƦr�N��W�U���k���ʤ�V 
const int Stop = 0, Left = 1, Right = 2, Up = 3, Down = 4;


// ��� 
void Clear() //��s�e���ɧR���e���Ϊ� 
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = 0; //��Ц�m��l�� 
  scrn.Y = 0;
  SetConsoleCursorPosition(hOuput,scrn);
  return;
}


void SetUp(){ //��l�ƹC���ܼ� 
	gameOver = 0;
	direction = Stop;
	x = width/2;
	y = height/2;
	flag : 
	coinX = rand() % (width - 1)+1;
	coinY = rand() % (height - 1)+1;
	if (x == coinX && y == coinY){ //�קK�D���Y�@�}�l�N�������m�@�� 
		goto flag;
	}
	return;
}


void Draw(){ //���͹C���e�� 
	Sleep(100);  //���e���Ȱ� sleep���@�� 
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

 //������J�� 
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

//�]�t�C�����t��k 
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
