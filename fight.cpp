#include <iostream>
#include <fstream>
#include <sstream>
#include "p2list3.h"
#include "coord.h"
#include "defend.h"
#include "attack.h"
using namespace std;

int main(){
	//Various variables to be used in main function
	List<string> Layouts;
	char stance;
	int size;
	//File input section of code
	ifstream fin;
	string filename;
	cin>>filename;
	fin.open(filename.c_str());
	if(fin.is_open()){
		int numShip, numLay;
		fin>>size;
		fin>>numShip;
		string *sNames=new string[numShip];
		int *sSize=new int[numShip];
		for(int i=0; i<numShip; i++){
			fin>>sNames[i];
			fin>>sSize[i];
		}
		fin>>numLay;
		string trash;
		getline(fin, trash);
		initialize(Layouts);
		for (int i=0; i<numLay; i++){
			string ship, coord, layName, line, dir;
			string layout="";
			getline(fin, line);
			stringstream ss(line);
			ss>>layName;
			for(int k=0; k<size; k++)
				for(int j=0; j<size; j++)
					layout+="X";
			while(ss){
				ss>>ship>>coord>>dir;
				for(int j=0; j<numShip; j++){
					if(sNames[j]==ship){
						int place=coordInt(coord,size);
						if(dir=="H"){
							for(int k=0; k<sSize[j]; k++){
								layout[place+(k*size)]='O';
							}
						}else{
							for(int k=0; k<sSize[j]; k++){
								layout[place+k]='O';
							}
						}

					}
				}
			}
			layout+=layName;
			append(Layouts,layout);

			/*for(int k=0; k<size; k++){
				for(int j=0; j<size; j++)
					cout<<layout[k+(j*size)];
				cout<<endl;
			}
			cout<<endl;*/
		}
		delete [] sNames;
		delete [] sSize;
	}else{
		cout<<"Could not open file";
		return -1;
	}
	fin.close();
	cin>>stance;

	if(stance=='D'){
		defend(Layouts, size);
	}else if(stance=='A'){
		attack(Layouts, size);
	}
	destroy(Layouts);
}

