#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
    int key;
    } element;
element heap [ MAX_ELEMENTS ];
int n = 0;
void insert_heap(element x)
{
    int i;
    if(n == MAX_ELEMENTS) {
        cout << "The heap is full. \n";
    }
    i = ++n;
    while(1){
        if((i == 1) || (x.key >= heap[i/2].key)) 
            break;
        else {
        heap[i] = heap[i/2];
        i /= 2;
        }
    }
    heap[i] = x;
}

element delet_heap()
{
    int parent, child;
    element x, temp;

    if(!n)
        cout << "The heap is empty. \n";
    else{
        x = heap[1];
        temp = heap[n--];
        parent = 1;
        child = 2;
        while (child <= n){
            if(child >= heap[child+1].key)
                child++;
            if(temp.key <= heap[child].key)
                break;
            else{
                heap[parent] = heap[child];
                parent = child;
                child *= 2;
            }
            heap[parent] = temp;
            return x;
        }
    }
}

void print_heap()
{
    for (int i = 1; i<=n; i++)
        cout << heap[i].key << " ";
    cout << endl;
}
int search_heap(int x)
{
    for(int i = 1; i<=n; i++)
        if(heap[i].key == x) 
            return i;
}
element top()
{
    return heap[1];
}
void removePriority(int priority)
{
    int position, newPriority, parent, child;
    element item;
    position = search_heap(priority);
    item = top();
    item.key++;
    while(1){
        if((position == 1) || (item.key >= heap[position / 2].key ))
            break;
        else{
            heap[position] = heap[position / 2];
            position /= 2;
        }
        heap[position] = item;
        item = delet_heap();
    }
}
int main()
{
    int choice, y;
    element x;
    cout << "Choose a min heap operation. \n\n";
    cout << "1. Insert, 2. Delet, 0. Quit: ";
    cin >> choice;
    while (choice > 0)
    {
    switch(choice){
        case 1: cout << "Enter a number: ";
                cin >> x.key;
                insert_heap(x);
                print_heap();
                break;
        case 2: cout << "Enter a number: ";
                cin >> y;
                removePriority(y);
                print_heap();
                break;
    }
    cout << "1. Insert, 2. Delete, 0. Quit: ";
    cin >> choice;
    }
}

