#include<iostream>


using namespace std;


int main(){

	int base,time;

	flag:

	cout<<"�п�J�h��(���_��):";

	cin>>base;

	if(base%2 == 1){

	}

	else{

		cout<<"��J���~!"<<endl;

		goto flag; 

	}

	cout<<"�п�J�`������:";

	cin>>time;

	int a,b,c,d;

	for(a=base/2+1;a>0;a--){

		for(d=1;d<=time;d++){

			for(c=base/2+1-a;c>0;c--){

			cout<<" ";

		}

			for(b=a*2-1;b>0;b--){

			cout<<"*";

		}	

			for(c=base/2+1-a;c>0;c--){

			cout<<" ";

		}

			

	}

	cout<<endl;

	}

	

	for(a=1;a<=base/2;a++){

		for(d=1;d<=time;d++){

			for(c=a;c<base/2;c++){

				cout<<" ";

			}

			for(b=a*2-1;b>=-1;b--){

				cout<<"*";

			}

			for(c=a;c<base/2;c++){

				cout<<" ";

			}	

		}

		cout<<endl;

	}

	

	system("pause");

	return 0;

} 
