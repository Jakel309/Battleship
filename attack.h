#include <iostream>
using namespace std;

void attack(List<string>& layouts, int size){
	string coord="0";
	while(true){
		int bHit=0, hitC;
		for (int i=0; i<size*size; i++){
			string lay;
			hitC=0;
			for(int j=1; j<=getSize(layouts); j++){
				lay=getNth(layouts, j);
				if(lay[i]=='O'){
					hitC++;
				}
			}
			if(hitC>bHit){
				if(i%size==0){
					coord="A";
					coord+=(i/size)+'0';
				}else if(i%size==1){
					coord="B";
					coord+=(i/size)+'0';
				}else if(i%size==2){
					coord="C";
					coord+=(i/size)+'0';
				}else if(i%size==3){
					coord="D";
					coord+=(i/size)+'0';
				}else if(i%size==4){
					coord="E";
					coord+=(i/size)+'0';
				}else if(i%size==5){
					coord="F";
					coord+=(i/size)+'0';
				}else if(i%size==6){
					coord="G";
					coord+=(i/size)+'0';
				}else if(i%size==7){
					coord="H";
					coord+=(i/size)+'0';
				}else if(i%size==8){
					coord="I";
					coord+=(i/size)+'0';
				}else if(i%size==9){
					coord="J";
					coord+=(i/size)+'0';
				}
				bHit=hitC;
			}
		}
		cout<<coord<<endl;
		string effect;
		cin>>effect;
		if(effect[0]=='L'){
			cout<<"WIN";
			return;
		}
		if(coord!="0"){
			if(effect=="MISS"){
				List<string> newList;
				initialize(newList);
				string lay;
				for(int i=1; i<=getSize(layouts); i++){
					lay=getNth(layouts, i);
					if(lay[coordInt(coord, size)]=='X')
						append(newList,lay);
				}
				destroy(layouts);
				layouts=newList;
			}else{
				List<string> newList;
				initialize(newList);
				string lay;
				for(int i=1; i<=getSize(layouts); i++){
					lay=getNth(layouts, i);
					if(lay[coordInt(coord, size)]=='O'){
						lay[coordInt(coord, size)]='X';
						for(int j=0; j<size*size-1; j++){
							if(lay[j]=='O'){
								append(newList, lay);
								break;
							}
						}
					}
				}
				destroy(layouts);
				layouts=newList;
			}
		}
	}
}