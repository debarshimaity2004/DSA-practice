//gfg potd 31 jan 2026
#include<bits/stdc++.h>
using namespace std;

class kQueues{
    int n, k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

public:

    kQueues(int n, int k){
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for(int i = 0; i < k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i = 0; i < n-1; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        freeSpot = 0;
    }

    bool isFull(){
        if(freeSpot == -1) return true;
        return false;
    }

    bool isEmpty(int i){
        if(front[i] == -1) return true;
        return false;
    }

    void enqueue(int x, int i){

        if(isFull()){
            return;
        }

        int index = freeSpot;

        freeSpot = next[index];

        if(front[i] == -1){
            front[i] = index;
        }
        else{
            next[rear[i]] = index;
        }

        next[index] = -1;

        rear[i] = index;

        arr[index] = x;
    }

    int dequeue(int i){

        if(isEmpty(i)){
            return -1;
        }

        int index = front[i];

        front[i] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main(){

    int n = 6;
    int k = 3;

    kQueues q(n, k);

    q.enqueue(10, 0);
    q.enqueue(20, 0);
    q.enqueue(30, 1);
    q.enqueue(40, 2);

    cout << q.dequeue(0) << "\n"; // 10
    cout << q.dequeue(1) << "\n"; // 30
    cout << q.isEmpty(2) << "\n"; // 0 (false)
    cout << q.isFull() << "\n";   // 0 (false)

    return 0;
}
