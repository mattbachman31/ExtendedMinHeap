#include "minheap.h"


using namespace std;


Heap::Heap(int arrSize, string out){
    outString = out;
    myOut.open(outString);
    size = 0;
    maxSize = arrSize;
    arr = new Contestant[maxSize+1];
    handle = new int[maxSize+1];
    for(int i=1; i<=maxSize; i++){
        handle[i] = -1;
    }
}

 
void Heap::heapify(){
    for(int i = size; i > 0; i--){
        percolate_down(i);
    }
}

void Heap::percolate_down(int root){
    int current = root;
    int child = 2*current;
    while(current < size){
        if((child + 1) <= size && arr[child].points > arr[child + 1].points){
            child++;
        }
        //swap
        if(child <= size && arr[current].points > arr[child].points){
            Contestant temp;
            int lowerHandle = handle[arr[current].id];
            handle[arr[current].id] = handle[arr[child].id];
            handle[arr[child].id] = lowerHandle;
            temp.points = arr[current].points;
            temp.id = arr[current].id;
            arr[current].points = arr[child].points;
            arr[current].id = arr[child].id;
            arr[child].points = temp.points;
            arr[child].id = temp.id;
            current = child;
            child = current*2;
        }
        else{
            break;
        }
    }
}

void Heap::percolate_up(int child){
    int current = child;
    int parent = current/2;
    while(current != 1 && arr[parent].points > arr[current].points){
        //swap
        int higherHandle = handle[arr[current].id];
        handle[arr[current].id] = handle[arr[parent].id];
        handle[arr[parent].id] = higherHandle;
        Contestant temp;
        temp.points = arr[current].points;
        temp.id = arr[current].id;
        arr[current].points = arr[parent].points;
        arr[current].id = arr[parent].id;
        arr[parent].points = temp.points;
        arr[parent].id = temp.id;
        current = parent;
        parent = current/2;
    }
}

void Heap::print(){
    for(int i=1; i<=size; i++){
        cout << arr[i].id << "/" << arr[i].points << "  ";
    }
    cout << endl;
}

void Heap::showContestants(){
    myOut << "showContestants" << endl;
    for(int i=1; i<=size; i++){
        if(handle[arr[i].id] != -1){myOut << "Contestant <" << arr[i].id << "> in extended heap location <" << i << "> with score <" << arr[i].points << ">." << endl;}       
    }
}
int Heap::getTop(){
    return arr[1].points;
}

void Heap::eliminateWeakest(bool notCrownWinner){
    if(notCrownWinner){
        myOut << "eliminateWeakest" << endl;
    }
    if(size < 1){
        if(notCrownWinner){myOut << "No contestant can be eliminated since the extended heap is empty." << endl;}
        return;
    }
    if(notCrownWinner){myOut << "Contestant <" << arr[1].id << "> with current lowest score <" << arr[1].points << "> eliminated." << endl;}
    handle[arr[1].id] = -1;
    arr[1] = arr[size];
    handle[arr[1].id] = 1;
    size--;
    percolate_down(1);
}

void Heap::crownWinner(){
    myOut << "crownWinner" << endl;
    while(size > 1){
        int top = getTop();
        eliminateWeakest(false); //should be false
    }
    myOut << "Contestant <" << arr[1].id << "> wins with score <" << arr[1].points << ">!" << endl;
}

void Heap::earnPoints(int root, int pointsEarned){
    myOut << "earnPoints <" << root << "> <" << pointsEarned << ">" << endl;
    if(handle[root] == -1){
        myOut << "Contestant <" << root << "> is not in the extended heap." << endl;
        return;
    }
    arr[handle[root]].points += pointsEarned;
    percolate_down(handle[root]);
    myOut << "Contestant <" << root << ">'s score increased by <" << pointsEarned << "> points to <" << arr[handle[root]].points << ">." << endl;
}

void Heap::losePoints(int root, int pointsLost){
    myOut << "losePoints <" << root << "> <" << pointsLost << ">" << endl;
    if(handle[root] == -1){
        myOut << "Contestant <" << root << "> is not in the extended heap." << endl;
        return;
    }
    arr[handle[root]].points -= pointsLost;
    percolate_up(handle[root]);
    myOut << "Contestant <" << root << ">'s score decreased by <" << pointsLost << "> points to <" << arr[handle[root]].points << ">." << endl;
}

void Heap::findContestant(int id){
    myOut << "findContestant <" << id << ">" << endl;
    if(handle[id] == -1){
        myOut << "Contestant <" << id << "> is not in the extended heap." << endl;
        return;
    }
    myOut << "Contestant <" << id << "> is in the extended heap with score <" << arr[handle[id]].points << ">." << endl;
}

void Heap::insertContestant(int id, int points){
    myOut << "insertContestant <" << id << "> <" << points << ">" << endl;
    size++;
    if(size <= maxSize){
        if(handle[id] == -1){
            arr[size].id = id;
            arr[size].points = points;
            myOut << "Contestant <" << id << "> inserted with initial score <" << points << ">." << endl;
            handle[id] = size;
            percolate_up(size);
        }
        else{
            size--;
            myOut << "Contestant <" << id << "> is already in the extended heap: cannot insert." << endl;
        }
    }
    else{
        size--;
        myOut << "Contestant " << id << " could not be inserted because the extended heap is full." << endl;
    }
}

void Heap::showHandles(){
    myOut << "showHandles" << endl;
    for(int i=1; i <= maxSize; i++){
        if(handle[i] == -1){
            myOut << "There is no Contestant <" << i << "> in the extended heap: handle[<" << i << ">] = -1." << endl;
        }
        else{
            myOut << "Contestant <" << i << "> stored in extended heap location <" << handle[i] << ">." << endl;
        }
    }
}

void Heap::showLocation(int id){
    myOut << "showLocation <" << id << ">" << endl;
    if(handle[id] == -1){
        myOut << "There is no Contestant <" << id << "> in the extended heap: handle[<" << id << ">] = -1." << endl; 
    }
    else{
        myOut << "Contestant <" << id << "> stored in extended heap location <" << handle[id] << ">." << endl;
    }
}

Heap::~Heap(){
    delete [] handle;
    delete [] arr;
}
