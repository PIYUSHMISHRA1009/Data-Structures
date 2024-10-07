#include<iostream>
using namespace std;
class Queue{
	public:
		int size;
		int* arr;
		int qfront;
		int rear;
		
		Queue(){
			size=1001;
			arr=new int(size);
			qfront=0;
			rear=0;
		}
		int enuqueue(int ele){
		if(rear==size-1){
				cout<<"Queue is full"<<endl;
		}
		else {
			int ans=
			arr[rear]=ele;
			rear++;
		}
	}
		int dequeue(){
			if(qfront==rear){
				cout<<"Queue is empty"<<endl;
			}
			else{
				int ans=arr[qfront];
				arr[qfront]=-1;
				qfront++;
				if(qfront==rear){
					qfront=0;
					rear=0;
				}
				return ans;
			}
		}
		bool isEmpty(){
			if(rear==size-1){
				return true;
			}
			else{
				return false;
			}
		}
		void front(){
			if(qfront!=rear){
				cout<<arr[qfront]<<endl;
			}
			else{
				cout<<"Queue has nothing to print"<<endl;
			}
		}
		
};
int main(){
	Queue q;
	q.enuqueue(5);
	q.enuqueue(4);
	q.enuqueue(3);
	q.enuqueue(2);
	q.enuqueue(1);
	q.front();
}
