#include <bits/stdc++.h>
using namespace std;

struct Queue 
{
	int front;
	int rear;
	int size;
	int *arr;
};
void initialise_q(struct Queue *q, int n)
{
	q->front = q->rear =-1;
	q->size= n;
	q->arr = (int*)malloc(sizeof(int) * n);
}
void enqueue(struct Queue *q, int x)
{
	if((q->front == 0 && q->rear == q->size-1) || q->rear +1 == q->front)
	{
		cout <<"overflow\n" ;
		return;
	}
	if(q->front == -1)
	q->front = q->rear = 0;
	else if(q->rear == q->size-1)
	q->rear=0;
	else q->rear++;
	
	q->arr[q->rear] =x;
}

int dequeue(struct Queue *q)
{
	if(q->front == -1)
	{
		cout <<"underflow\n";
		return -999;
	}
	int t = q->arr[q->front];
	
	if(q->front == q->rear)
	q->front = q->rear =-1;
	else if(q->front == q->size-1)
	q->front = 0;
	else q->front++;
	
	return t;
}
void printQueue(struct Queue q)
{
	if(q.front == -1)
	{
		cout <<"empty\n";
		return ;
	}
	if(q.front <= q.rear)
	{
        for(int i=q.front ; i<= q.rear ; i++)
	    cout << q.arr[i] <<" ";	
			
	    cout << endl;
	}
	else
	{
		for(int i=q.front ; i<= q.size-1; i++)
		cout << q.arr[i] << " ";
		for(int i=0 ;i<= q.rear ; i++)
		cout << q.arr[i] << " ";
		
		cout << endl;
	}
}


/*

pause


*/

struct STACK
{
	int x;
	int size;
	int top1, top2;
	int *arr;
};
void initialise_st(struct STACK *st, int m, int n)
{
	st->x=m;
	//st->y=n;
	st->size = m+n;
	
    st->top1 = -1;
    st->top2 = st->x -1;
    
    st->arr = (int*) malloc(sizeof(int) * st->size);
}
void push(int stackno, struct STACK *st, int data)
{
	if(stackno == 1)
	{
		if(st->top1 == st->x-1 )
		{
			cout << "stack 1 is full\n";
			return;
		}
		st->top1++;
		
		st->arr[st->top1] = data;
		
	} 
	else if (stackno == 2)
	{
		if(st->top2 == st->size-1)	
		{
			cout << "stack 2 is full\n";
			return;
		}	
		st->top2 ++;
		st->arr[st->top2] = data;
	}
	else
	{
		cout << "wrong stack no\n";
	}
}

int pop(int stackno, struct STACK *st)
{
	if(stackno ==1)
	{
		if(st->top1 == -1)
		{
			cout << "stack 1 is empty\n";
			return -999;
		}
		int data = st->arr[st->top1];
		st->top1--;
		
		return data;
	}
	else if(stackno ==2)
	{
		if(st->top2 == st->x-1)
		{
			cout << "stack 2 is empty\n";
			return -999;
		}
		int data = st->arr[st->top2];
		st->top2 --;
		
		return data;
		
	}
	else
	{
		cout <<"wrong stack no\n";
	}
}

void printStack(struct STACK st)
{
	cout << "stack 1: ";
	for(int i =0; i<= st.top1; i++)
	cout << st.arr[i] << " ";
	
	cout << "\nstack 2: ";
	for(int i=st.x; i<=st.top2 ; i++)
	cout << st.arr[i] << " ";
	
	cout << endl;
}


void isEmpty(struct STACK st)
{
	if(st.top1 == -1)
	cout << "stack 1 is empty\n";
	if(st.top2 == st.x-1)
	cout << "stack 2 is empty\n";
}

void isFull(struct STACK st)
{
	if(st.top1 == st.x-1)
	cout << "stack 1 is full\n";
	if(st.top2 == st.size-1)
	cout << "stack 2 is full\n";
}


int main()
{
	struct Queue cq;
	int n;
	cout <<"enter size of the queue:\n";
	cin >> n;
	
	initialise_q(&cq,n);
	//cout << cq.front <<endl;
	enqueue(&cq , 3);
	enqueue(&cq , 23);
	enqueue(&cq , 83);
	enqueue(&cq , 11);
	enqueue(&cq , 2);
	
	//cout << cq.front << endl;
	printQueue(cq);
	
	cout << "removed data: "<< dequeue(&cq) << endl;
	cout << "removed data: "<< dequeue(&cq) << endl;
	cout << "removed data: "<< dequeue(&cq) << endl;
	cout << "removed data: "<< dequeue(&cq) << endl;
	
	printQueue(cq);
	
	
	
	
	/*
	
	pause
	
	
	*/
	cout << endl ;
	
	
	struct STACK st;
	cout <<"enter array size for stack 1 and stack 2\n";
	int m;
	cin >> m>>n;
	
	initialise_st(&st, m ,n);
	
	//first parameter is the stack no whether s1 or s2
	
	push(1, &st, 3);
	push(1, &st, 23);
	push(1, &st, 26);
	push(1, &st, 7);
	
	//printStack(st);
	
	push(2, &st, 8);
	push(2, &st, 213);
	push(2, &st, 1);
	push(2, &st, 56);
	push(2, &st, 8);
	push(2, &st, 213);
	push(2, &st, 1);
	push(2, &st, 56);
	
	printStack(st);
	
	isFull(st);
	
	cout << "removed: "<<pop(1,&st) << endl;
	cout << "removed: "<<pop(1,&st) << endl;
	
	printStack(st);
	
	cout << "removed: "<<pop(2,&st) << endl;
	cout << "removed: "<<pop(2,&st) << endl;
	
	printStack(st);
	
	cout << "removed: "<<pop(1,&st) << endl;
	cout << "removed: "<<pop(1,&st) << endl;
	
	printStack(st);
	
	cout << "removed: "<<pop(1,&st) << endl;
	cout << "removed: "<<pop(1,&st) << endl;
	
	printStack(st);
	
	isFull(st);
	isEmpty(st);

}
