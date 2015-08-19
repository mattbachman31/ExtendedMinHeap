#include "minheap.h"

int main(int agrc, char** argv){
	string in(argv[1]);
	string out(argv[2]);
	ifstream inFile(in);
	string extract;
	getline(inFile,extract);
	int maxSize = atoi(extract.c_str());
	Heap myHeap(maxSize, out);
	int param1, param2;
	int innerInc = 0;
	while(getline(inFile, extract)){
		param1 = 0;
		param2 = 0;
		if(extract[0] == 'f'){
			innerInc = 16;
			while(extract[innerInc] != '>'){
				param1 *= 10;
				param1 += (extract[innerInc] - '0');
				innerInc++;
			}
			myHeap.findContestant(param1);
		}
		else if(extract[0] == 'i'){
			innerInc = 18;
			while(extract[innerInc] != '>'){
				param1 *= 10;
				param1 += (extract[innerInc] - '0');
				innerInc++;
			}
			innerInc += 3;
			while(extract[innerInc] != '>'){
				param2 *= 10;
				param2 += (extract[innerInc] - '0');
				innerInc++;
			}
			myHeap.insertContestant(param1, param2);
		}
		else if(extract[0] == 'c'){
			myHeap.crownWinner();
		}
		else if(extract[0] == 'l'){
			innerInc = 12;
			while(extract[innerInc] != '>'){
				param1 *= 10;
				param1 += (extract[innerInc] - '0');
				innerInc++;
			}
			innerInc += 3;
			while(extract[innerInc] != '>'){
				param2 *= 10;
				param2 += (extract[innerInc] - '0');
				innerInc++;
			}
			myHeap.losePoints(param1, param2);
		}
		else if(extract[0] == 'e'){
			if(extract[1] == 'a'){
				innerInc = 12;
				while(extract[innerInc] != '>'){
					param1 *= 10;
					param1 += (extract[innerInc] - '0');
					innerInc++;
				}
				innerInc += 3;
				while(extract[innerInc] != '>'){
					param2 *= 10;
					param2 += (extract[innerInc] - '0');
					innerInc++;
				}
				myHeap.earnPoints(param1, param2);
			}
			else if(extract[1] == 'l'){
				myHeap.eliminateWeakest();
			}
			else{
				cout << extract << " -- BAD INPUT" << endl;
				exit(1);
			}
		}
		else if(extract[0] == 's'){
			if(extract[4] == 'C'){
				myHeap.showContestants();
			}
			else if(extract[4] == 'H'){
				myHeap.showHandles();
			}
			else if(extract[4] == 'L'){
				innerInc = 14;
				while(extract[innerInc] != '>'){
					param1 *= 10;
					param1 += (extract[innerInc] - '0');
					innerInc++;
				}
				myHeap.showLocation(param1);
			}
			else{
				cout << extract << " -- BAD INPUT" << endl;
				exit(1);
			}
		}
		else{
			cout << extract << " -- BAD INPUT" << endl;
			exit(1);
		}
	}
	return 0;
}
