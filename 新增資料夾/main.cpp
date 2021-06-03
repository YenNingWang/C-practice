#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
int gamestatus=0;//0遊戲進行中 1玩家獲勝 2電腦獲勝
int playerPoint=0;
int pcPoint=0;
char playerChoice;
int cardNum;
int DrawCard();//抽牌函數 
void play();//遊戲函數 

//主程式 
int main() {
	play();
	return 0;
	} 
	
//抽牌函數	
int DrawCard(){
	srand(time(NULL)); //初始化亂數
	cardNum=rand()%13+1;
	if(cardNum<11&cardNum>1){
		cout<<"抽中"<< cardNum<<"點"<<endl; 
		return cardNum;
	}
	else{
		switch(cardNum){
			case 1:
				cout<<"抽中A"<<endl; 
				break;
			case 11:
				cout<<"抽中J"<<endl; 
				break;
			case 12:
				cout<<"抽中Q"<<endl; 
				break;
			case 13:
				cout<<"抽中K"<<endl; 
				break;		
		} 
		cardNum=10;
		return cardNum;	
	}	
}


//遊戲函數 玩家抽->電腦抽->結算 
void play(){
	cout<<"歡迎來玩21點 ! "<<endl;
	cout<<"現在開始發牌"<<endl;
	cout<<endl;
	
	//玩家玩 
	do{
	
		cout<<"您的回合";
		int tmp=DrawCard();
		playerPoint=playerPoint+tmp;
		cout<<"您目前有"<<playerPoint<<"點"<<endl;
		if(playerPoint>21){
			cout<<"爆掉了，您輸了"<<endl;
			gamestatus=2;
			break;
		}
		
		else{
			cout<<"是否要繼續抽牌? Y/N"<<endl;
			cin>>playerChoice;	
		}
	}while(playerChoice=='Y');
	 
	//電腦玩 
	while(gamestatus==0){ //判斷是否繼續進行遊戲 
		
		if(pcPoint<17){
			cout<<"電腦的回合";
			int tmp2=DrawCard();
			pcPoint=pcPoint+tmp2;
			cout<<"電腦目前有"<<pcPoint<<"點"<<endl;
		}	
		else if (pcPoint>21){
		cout<<"電腦超過21點爆牌"<<endl;
		gamestatus=1;
		break;	
		}
		
		else{
			cout<<"電腦不抽牌了"<<endl;
			cout<<"電腦目前有"<<pcPoint<<"點"<<endl;
			break;
		}
		
	}
	
	while(gamestatus==0){ 
		if(playerPoint>pcPoint){
			cout<<"玩家獲勝 !!! "<<endl;
			gamestatus==1;
			break;
		}	
		
		else if (playerPoint==pcPoint){
			cout<<"平手"<<endl;
			gamestatus==3;
			break;
		}
		else{
			cout<<"電腦獲勝 !!! "<<endl;
			gamestatus==2;
		
				break;
		}
	}	
	
}
