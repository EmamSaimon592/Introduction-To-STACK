//code 1
#include<iostream>
using namespace std;

//implement it with array
class Stack{
 int *arr;
 int size;
 int top;
public:
	bool flag;
	Stack(int s){
		size = s;
		top = -1;
		arr = new int[s];
		flag = 1;
	}

//push
void push(int value){
	 if(top == size -1){
	 	cout<<"stack overflow"<<endl;
	 }
	 else{
	 	top++;
	 	arr[top] = value;
	 	cout<<"pushed "<<value <<" into the stack\n";
	 	flag = 0;
	 }
}
//pop 
void pop(){
	 if(top ==  -1){
	 	cout<<"stack unerflow"<<endl;
	 }
	 else{
	 	cout<<"popped "<<arr[top] <<" from  the stack\n";
	 	top--;
	 	if(top == -1){
	 		flag = 1;
	 	}
	 }
}	
//top or peek
int peek(){
	if(top == -1){
		cout<<"stack is empty"<<endl;
		return -1;
	}
	else{
		return arr[top];
	}
}

//IsEmpty or empty
bool IsEmpty(){
	return top == -1;
}

//IsSize or size
int IsSize(){
	return top +1;
}

};

int main(){
	Stack s(5);
	// s.push(5);
	// s.push(6);
	// s.push(8);

	// s.pop();
	// cout<<s.peek()<<endl;
	// cout<<s.IsEmpty()<<endl;

	s.push(-1);
	int value = s.peek();
	if(s.flag ==0){
	cout<<value<<endl;	
	}
	
	return 0;
}
