#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
int gamestatus=0;//0�C���i�椤 1���a��� 2�q�����
int playerPoint=0;
int pcPoint=0;
char playerChoice;
int cardNum;
int DrawCard();//��P��� 
void play();//�C����� 

//�D�{�� 
int main() {
	play();
	return 0;
	} 
	
//��P���	
int DrawCard(){
	srand(time(NULL)); //��l�ƶü�
	cardNum=rand()%13+1;
	if(cardNum<11&cardNum>1){
		cout<<"�⤤"<< cardNum<<"�I"<<endl; 
		return cardNum;
	}
	else{
		switch(cardNum){
			case 1:
				cout<<"�⤤A"<<endl; 
				break;
			case 11:
				cout<<"�⤤J"<<endl; 
				break;
			case 12:
				cout<<"�⤤Q"<<endl; 
				break;
			case 13:
				cout<<"�⤤K"<<endl; 
				break;		
		} 
		cardNum=10;
		return cardNum;	
	}	
}


//�C����� ���a��->�q����->���� 
void play(){
	cout<<"�w��Ӫ�21�I ! "<<endl;
	cout<<"�{�b�}�l�o�P"<<endl;
	cout<<endl;
	
	//���a�� 
	do{
	
		cout<<"�z���^�X";
		int tmp=DrawCard();
		playerPoint=playerPoint+tmp;
		cout<<"�z�ثe��"<<playerPoint<<"�I"<<endl;
		if(playerPoint>21){
			cout<<"�z���F�A�z��F"<<endl;
			gamestatus=2;
			break;
		}
		
		else{
			cout<<"�O�_�n�~���P? Y/N"<<endl;
			cin>>playerChoice;	
		}
	}while(playerChoice=='Y');
	 
	//�q���� 
	while(gamestatus==0){ //�P�_�O�_�~��i��C�� 
		
		if(pcPoint<17){
			cout<<"�q�����^�X";
			int tmp2=DrawCard();
			pcPoint=pcPoint+tmp2;
			cout<<"�q���ثe��"<<pcPoint<<"�I"<<endl;
		}	
		else if (pcPoint>21){
		cout<<"�q���W�L21�I�z�P"<<endl;
		gamestatus=1;
		break;	
		}
		
		else{
			cout<<"�q������P�F"<<endl;
			cout<<"�q���ثe��"<<pcPoint<<"�I"<<endl;
			break;
		}
		
	}
	
	while(gamestatus==0){ 
		if(playerPoint>pcPoint){
			cout<<"���a��� !!! "<<endl;
			gamestatus==1;
			break;
		}	
		
		else if (playerPoint==pcPoint){
			cout<<"����"<<endl;
			gamestatus==3;
			break;
		}
		else{
			cout<<"�q����� !!! "<<endl;
			gamestatus==2;
		
				break;
		}
	}	
	
}
