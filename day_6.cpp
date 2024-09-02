#include <bits/stdc++.h>
using namespace std;

struct Deque
{
	int front;
	int rear;
	int size;
    int *arr;
};

void create(struct Deque *Q, int n)
{
	Q->size=n;
	Q->front = Q->rear =-1;
	Q->arr = (int*) malloc(sizeof(int)*n);
	
}

void insertFront (struct Deque *q, int data)
{
	if((q->front == 0 && q->rear==q->size-1) || q->rear +1 == q->front )
	{
		cout <<"deque is full\n";
		return;
	}
	if(q->front == -1)
	q->front = q->rear = 0;
	else if(q->front ==0)
	q->front = q->size-1;
	else q->front--;
	
	q->arr[q->front]=data; 
}
int deleteFront(struct Deque *q)
{
	if(q->front == -1)
	{
		cout <<"deque is empty\n";
		return -999;
	}
	int x= q->arr[q->front];
	
	if(q->front == q->rear)
	q->front = q->rear =-1;
	
	else if(q->front == q->size-1)
	q->front =0;
	
	else q->front ++;
	
	return x;
}

void insertRear(struct Deque *q, int data)
{
	if((q->front == 0 && q->rear==q->size-1) || q->rear +1 == q->front )
	{
		cout <<"deque is full\n";
		return;
	}
	
	if(q->front == -1)
	q->front = q->rear =0;
	else if(q->rear == q->size-1)
	q->rear = 0;
	else q->rear ++;
	
	q->arr[q->rear]=data;
}

int deleteRear(struct Deque *q)
{
	if(q->front == -1)
	{
		cout <<"deque is empty\n";
		return -999;
	}
	
	int x= q->arr[q->rear];
	
	if(q->front == q->rear)
	q->front = q->rear =-1;
	else if (q->rear ==0 )
	q->rear = q->size-1;
	else q->rear--;
	
	return x;
}

void printQueue(struct Deque q)
{
	cout <<"i am printing from front of the deque to the rear of the deque\n";
	
	if(q.front == -1)
	cout << "empy deque\n";
	
	if(q.front <= q.rear)
	for(int i=q.front; i<=q.rear; i++)
	cout << q.arr[i] << " ";
	else{
		for(int i=q.front; i<q.size; i++)
		cout <<q.arr[i]<< " ";
		for(int i=0; i<=q.rear; i++)
		cout <<q.arr[i]<<" ";
	}
	
	cout << endl;
}

int main()
{
	cout <<"enter size of the queue\n";
	int n;
	cin >> n;
	
	
	struct Deque Q;
	create(&Q,n);
	
	insertRear(&Q,99);
	insertFront(&Q,14);
	insertFront(&Q,4);
	insertFront(&Q,6);
	
	printQueue(Q);
	
	insertRear(&Q,8);
	insertRear(&Q,48);
	insertRear(&Q,10);
	
	printQueue(Q);
	
	cout << "deleted data is: " << deleteFront(&Q) << endl;
//	cout << "deleted data is: " << deleteFront(&Q) << endl;
//	
//	printQueue(Q);
	
	cout << "deleted data is: " << deleteRear(&Q) << endl;
	cout << "deleted data is: " << deleteRear(&Q) << endl;
	
	printQueue(Q);
	
	insertRear(&Q,8);
	insertRear(&Q,48);
	//insertRear(&Q,10);
	
	printQueue(Q);
	
	
	
	
	/*
	
	periooood
	
	*/
	
	
	cout << "Enter size of array A:\n";
	
	cin >> n;
	
	int A[n];
	cout <<"fill the array one by one\n";
	for(int i=0;i<n; i++)
	cin >> A[i];
	
	cout <<"enter subarray size k\n";
	int k;
	cin >> k;
	
	
	struct Deque q;
	create(&q,n);
	
	
	for(int i=0 ; i<= n-1-(k-1); i++)
	{
		int index=i;//, flag=0;
		for(int j=1; j<=k; j++)
		{
			if(A[index]<0)
			{
				 insertRear(&q,A[index]);
				 goto here;
			}
			else index++;
		}
		insertRear(&q,0);
		here:;		
	}
	
	printQueue(q);

	
	
}
