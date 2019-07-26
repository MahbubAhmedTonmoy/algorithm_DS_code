#include<bits/stdc++.h>
using namespace std;
#define size 1000
int front=0,rear=0;
int Queue[size];
bool is_empty(){
    if(rear==0) return 1;
    else return 0;
}
bool is_full(){
    if(rear == size-1) return 1;
    else return 0;
}
void Enqueue(int ele){
    if(is_full()) cout <<"stack is full" << endl;
    else{
        Queue[rear] = ele;
        rear++;
    }
}
void peek(){
    if(is_empty()) cout <<"empty";
    else{
        cout <<  Queue[front];
    }
}
int Dequeue(){
    if(is_empty()) return 0;
    else{
        front++;
    }
}
int length(){
    cout << "length is"  << endl;
}
void display(){
    if(is_empty()) cout<<"empty stack"<<endl;
    else{
        cout << "stack :";
        for(int i=front;i<rear;i++){
            cout<< Queue[i] << " ";
        }
        cout << endl;
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

