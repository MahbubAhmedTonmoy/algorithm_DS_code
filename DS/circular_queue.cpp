
/**
      f
queue ------
if remove front the space is empty not use another time
**/


#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

int Circular_Q[SIZE];
int front=-1,rear=-1;

 bool isFull(){
        if(front == 0 && rear == SIZE - 1){
            return true;
        }
        if(front == rear + 1) {
            return true;
        }
        return false;
    }

    bool is_Empty(){
        if(front == -1) return true;
        else return false;
    }

    void Enqueue(int element){
        if(isFull()){
            cout << "Queue is full";
        } else {
            if(front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            Circular_Q[rear] = element;
            cout << endl << "Inserted " << element << endl;
        }
    }

    int Dequeue(){
        int element;
        if(is_Empty()){
            cout << "Queue is empty" << endl;
            return(-1);
        } else {
            element = Circular_Q[front];
            if(front == rear){
                front = -1;
                rear = -1;
            } /* Q has only one element, so we reset the queue after deleting it. */
            else {
                front=(front+1) % SIZE;
            }
            return(element);
        }
    }

    void display()
    {
        /* Function to display status of Circular Queue */
        int i;
        if(is_Empty()) {
            cout << endl << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl << "Items -> ";
            for(i=front; i!=rear;i=(i+1)%SIZE)
                cout << Circular_Q[i];
            cout << Circular_Q[i];
            cout << endl << "Rear -> " << rear;
        }
    }
void peek(){
    if(is_Empty()) cout << "no element"<<endl;
    else{
        cout<<Circular_Q[front]<<endl;
    }
}
int main() {
   int ch, val;
   cout<<"1) insert in Queue"<<endl;
   cout<<"2) delete from Queue"<<endl;
   cout<<"3) Display Queue"<<endl;
   cout<<"4) Display front element"<<endl;
   cout<<"5) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            Enqueue(val);
            break;
         }
         case 2: {
            Dequeue();
            break;
         }
         case 3: {
            display();
            break;
         }
          case 4: {
            cout<<"front : ";
            peek();
            cout << endl;
            break;
         }
         case 5: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=5);
      return 0;
}
