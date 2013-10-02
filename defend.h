#include <iostream>
using namespace std;

void defend(List<string>& layouts, int size){
	string coord;
	while(true){
		cin>>coord;
		int hits=0, miss=0;
		string lay;
		for(int i=1; i<=getSize(layouts); i++){
			lay=getNth(layouts, i);
			if(lay[coordInt(coord, size)]=='X')
				miss++;
			else
				hits++;
		}
		if(miss>hits){
			cout<<"MISS"<<endl;
			List<string> newList;
			initialize(newList);
			for(int i=1; i<=getSize(layouts); i++){
				lay=getNth(layouts, i);
				if(lay[coordInt(coord, size)]=='X')
					append(newList,lay);
			}
			destroy(layouts);
			layouts=newList;
		}else{
			int count=0;
			List<string> newList;
			initialize(newList);
			for(int i=1; i<=getSize(layouts); i++){
				lay=getNth(layouts, i);
				if(lay[coordInt(coord, size)]=='O'){
					lay[coordInt(coord, size)]='X';
					for(int j=0; j<size*size; j++){
						if(lay[j]=='O'){
							append(newList, lay);
							count++;
							break;
						}
					}
				}
			}
			if(count==0){
				string id="";
				lay=getNth(layouts, 1);
				int l=lay.length();
				for(int i=size*size; i<l; i++)
					id+=lay[i];
				cout<<"LOSE "+id<<endl;
				destroy(newList);
				return;
			}
			destroy(layouts);
			layouts=newList;
			cout<<"HIT"<<endl;
		}
	}
}