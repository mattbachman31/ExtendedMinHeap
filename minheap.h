#ifndef HEAPS
#define HEAPS

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct{
    int id;
    int points;
}Contestant;
 
class Heap{
public:
    Heap(int arrSize, string out);
    void insertContestant(int id, int points);
    void eliminateWeakest(bool notCrownWinner = true);
    void showContestants();
    int getTop();
    void print();
    void crownWinner();
    void earnPoints(int root, int pointsEarned);
    void losePoints(int root, int pointsLost);
    void findContestant(int id);
    void showHandles();
    void showLocation(int id);
    ~Heap();
     
private:
    void heapify();
    void percolate_down(int root);
    void percolate_up(int child);
    Contestant* arr;
    int* handle;
    int size;
    int maxSize;
    string outString;
    ofstream myOut;
};

#endif
