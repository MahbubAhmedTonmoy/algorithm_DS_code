#include<bits/stdc++.h>
using namespace std;
#define size 1000
int top=-1;
int Stack[size];
bool is_empty(){
    if(top==-1) return 1;
    else return 0;
}
bool is_full(){
    if(top == size-1) return 1;
    else return 0;
}
void push(int ele){
    if(is_full()) cout <<"stack is full" << endl;
    else{
        top++;
        Stack[top] = ele;
    }
}
void peek(){
    if(is_empty()) cout <<"empty";
    else{
        cout <<  Stack[top];
    }
}
int pop(){
    if(is_empty()) return 0;
    else{
        top--;
    }
}
int length(){
    cout << "length is"  << endl;
}
void display(){
    if(is_empty()) cout<<"empty stack"<<endl;
    else{
        cout << "stack :";
        for(int i=0;i<=top;i++){
            cout<< Stack[i] << " ";
        }
        cout << endl;
    }
}



int main() {
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Display top element"<<endl;
   cout<<"5) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
          case 4: {
            cout<<"top : ";
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

