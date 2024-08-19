#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int* arr;
	struct  Node* link;
	
	int size;
	int stack_top;
    //struct Node* link_top;
};

struct Node* initialise(int n)
{
	struct Node* N = (struct Node*)malloc(sizeof(struct Node));
	
	N -> size= n;
	
	N-> stack_top =-1;
	
	N -> arr = (int*)malloc(sizeof(int)*n);
	
	N -> link = NULL;
	
}

void print_stack(struct Node *N)
{
	if(N==NULL)
	return;
	else
	{
		print_stack(N->link);
		
		for(int i=0; i<=N->stack_top ; i++)
		cout << N->arr[i] << " ";
		cout << endl;
	}
}

int count (struct Node *N)
{
	int c=0;
	
	while(N != NULL)
	{
		for(int i=0 ; i<= N->stack_top; i++)
		c++;
		N = N -> link; 
	}
}

bool isfull(struct Node* N)
{
	return (N -> stack_top == N->size -1);
}
bool isempty(struct Node* N)
{
	return N->stack_top ==-1;
}


void expand_push(struct Node** N, int x)
{
	if(isfull(*N) == false)//Not full
	{
		(*N) -> stack_top ++;
		(*N) -> arr[(*N) -> stack_top] = x;
	}
	else
	{
		struct Node* newnode = initialise((*N) -> size);
		newnode -> link = *N;
		
		*N= newnode;
		
//		(*N) -> link = initialise ((*N) -> size);
//		*N = (*N) -> link;
		
//		(*N) -> stack_top ++;
//		(*N) -> arr[(*N) -> stack_top] = x;

        expand_push(N, x);
	}
	
}

int shrink_pop(struct Node** N)
{
	if((*N) -> link == NULL && (*N)-> stack_top ==-1)//link list over
	{
		cout << "stack underflow\n";
		return -999;
	}
	else if(isempty(*N) == false)//not empty
	{
		int t = (*N) -> arr [(*N) -> stack_top];
		(*N) -> stack_top --;
		cout << "popped data is: " <<t << endl;
		return t;
	}
	else
	{
		struct Node* temp = *N;
		*N = (*N ) -> link;
		
		free(temp);
		
//		int t = (*N) -> arr [(*N) -> stack_top];
//		(*N) -> stack_top --;
//		cout << "popped data is: " <<t << endl;
//		return t;

        shrink_pop(N);
	}
	
}

int main()
{
	int n;
	cout << "enter array size\n";
	cin >> n;
	
	struct Node *link_top  = initialise(n);
	
	
	expand_push(&link_top , 34);
	expand_push(&link_top , 4);
	expand_push(&link_top , 94);
	expand_push(&link_top , 14);
	expand_push(&link_top , 34);
	expand_push(&link_top , 314);
	expand_push(&link_top , 40);
	expand_push(&link_top , 9);
	expand_push(&link_top , 124);
	expand_push(&link_top , 11);
	
	print_stack(link_top);
	cout << endl;
	
	cout << shrink_pop(&link_top) << endl;
    cout << shrink_pop(&link_top) << endl;
	cout << shrink_pop(&link_top) << endl;
	cout << shrink_pop(&link_top) << endl;
	print_stack(link_top);
	cout << endl;
	
	cout << shrink_pop(&link_top) << endl;
    cout << shrink_pop(&link_top) << endl;
	cout << shrink_pop(&link_top) << endl;
	cout << shrink_pop(&link_top) << endl;
	print_stack(link_top);
	cout << endl;	
	
	
	cout << shrink_pop(&link_top) << endl;
    cout << shrink_pop(&link_top) << endl;
    cout << endl;
	
    cout << shrink_pop(&link_top) << endl;
    cout << endl;

	
	
	
	
	return 0;
}


