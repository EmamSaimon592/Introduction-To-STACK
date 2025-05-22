#include<iostream>
using namespace std;

// create a basic node 
class Node{
public:
	int data;
	Node *next;

	Node(int value){
		data = value;
		next = NULL;
	}
};

// create a stack class

class Stack{
  Node *top;
  int size;  //actual size of stack

public:
	Stack(){
		top = NULL;
		size = 0;
	}
//push ==>
	void push(int value){
     Node *temp = new Node(value);
     	if(temp == NULL){
     		cout<<"stack overflow"<<endl;
     	}
     	else{
     		temp -> next = top;
     		top = temp;
     		size++;
     		cout<<"pushed "<<value<<" into the stack"<<endl;
     	}
	}

//pop
 void pop(){
 	if(top == NULL){
 		cout<<"stack unerflow"<<endl;
 		return;
 	}
 	else{
 		Node *temp = top;
 		cout<<"popped "<<top->data<<" from the stack"<<endl;
 		top = top -> next;
 		delete temp;
 		size--;
 	}
 }	

//peek
 int peek(){
 	if(top == NULL){
 		cout<<"stack is empty"<<endl;
 		return -1;
 	}
 	else{
 		return top->data;
 	}
 }
//IsEmpty
 bool IsEmpty(){
 	return top == NULL;

 }

//IsSize
int IsSize(){
	return size;
}	

};



int main(){
	Stack s;
	s.push(6);
	s.push(16);
	s.push(62);
	s.push(86);
	s.pop();

	cout<<s.peek()<<endl;
	cout<<s.IsSize()<<endl;
	cout<<s.IsEmpty()<<endl;


	return 0;
}