#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void insertFirst(struct Node **N, int x)
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = *N;
    *N = newnode;

}
void displayNode(struct Node *N)
{
    if(N==NULL)
    return;
    else
    {
        cout << N->data <<"->";
        displayNode(N->next);
    }
}
int countNodes(struct Node* N)
{
	int c=0;
	struct Node* temp= N;
	while(temp!=NULL)
	{
		c++;
		temp =temp->next;
	}
	return c;
}
void insertT1(struct Node **arr, int size, int x)
{
    int hashval = x % size;
    int collide=0;

    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data =x;
    newnode ->next =NULL;

    if(arr[hashval] == NULL)
    {
    	arr[hashval] = newnode;
    	cout <<"no of collisions: "<< collide<< endl;
	}
    else 
	{
		cout << "no of collisions: "<< countNodes(arr[hashval])<< endl;
		insertFirst(&arr[hashval],x);		
	}
	
}

void printHashTableT1(struct Node** N, int size)
{
    for(int i=0;i<size;i++)
    {
        cout << "row" << (i+1) << ": ";
        displayNode(N[i]);

        cout << endl;
    }
}

bool found(struct Node* N, int x)
{
    struct Node *temp =N;
    while(temp != NULL)
    {
        if(x==temp->data)
        return true;
        temp = temp ->next;
    }
    return false;
}
bool searchT1(struct Node **arr, int size, int x)
{
    int hashval= x % size;

    if(arr[hashval]->data == x)
    return true;
    else
    {
        return found(arr[hashval], x);
    }
}

void deleteNode(struct Node **N, int x)
{
    struct Node* temp = *N;

    if(temp -> data == x)
    {
        (*N) = (*N) -> next;
        free (temp);
    }
    else
    {
        //temp = temp -> next;
        while(temp->next !=NULL)
        {
            if((temp -> next)-> data ==x)
            {
                struct Node* copy = temp->next;
                temp -> next = copy->next;
                free(copy);
            }
            temp = temp->next;

        }
    }
}

void DeleteT1(struct Node **arr, int size, int x)
{
    int hashval= x % size;
    deleteNode(&arr[hashval], x);
}




/*





interval.....



*/


void insertT2(int *arr, int size, int x)
{
	int hashval = x % size;
	int iter = hashval;
	int collide=0;
	
	if(arr[iter]==-1)
	{
		arr[hashval] = x;	
		cout << "no of collision= " << collide << endl;
	    return;
	}
	else 
	{
		iter++;
		collide++;
		if(iter == size)
	        {
	    	    iter =0;
		    }
		    
		while(iter != hashval && arr[iter] !=-1 && arr[iter]!= -99)
		{
			collide++;
	        if(iter == size)
	        {
	    	    iter =0;
		    }
		    else iter ++;
		}
		
		if(arr[iter] == -1 || arr[iter] == -99)
		{
			arr[iter] = x;
			cout << "no of collision= " << collide << endl;
		    return;
		}
		else
		{
			cout <<"array's full\n";
			return;
		}
			
	}
}
void printHashTableT2(int *a, int size)
{
	for(int i=0;i<size; i++)
	cout << a[i] << " ";
	cout << endl;
}

bool searchT2(int *arr, int size, int x)
{
	int hashval = x % size;
	int iter = hashval;
	
	if(arr[iter]==x)
	return true;
	else
	{
		do
		{
			iter++;
			if(iter == size)
			iter =0;
			
			if(arr[iter] == x)
			{
				return true;
			}
		}
		while (iter!= hashval || arr[iter]==-1);
	}
	
	return false;
	
}

void DeleteT2(int *arr, int size, int x)
{
	int hashval = x % size;
	int iter = hashval;
	
	if(arr[iter]==x)
	{
		arr[iter]=-99;
		return;
	}
	else
	{
		do
		{
			iter++;
			if(iter == size)
			iter =0;
			
			if(arr[iter] == x)
			{
				arr[iter]=-99;
				return;
			}
		}
		while (iter!= hashval || arr[iter]==-1);
	}
	cout <<"given data not there\n";
}


int main()
{
	int sizeT1;
    cout <<"enter size of table T1\n";
    cin >> sizeT1;

    struct Node **table = (struct Node**) malloc(sizeof(struct Node*)*sizeT1);
    for(int i=0;i<sizeT1; i++)
    table[i]= NULL;
    
    
    int sizeT2;
    cout << "enter size of table T2\n";
    cin >> sizeT2;
    
    int arr[sizeT2];
	
	for(int i=0; i<sizeT2; i++)
	arr[i]= -1;
	
	while(true)
	{
		cout << "1.insert at T1 \T 2.insert at T2 \t 3.delete at T1 \t 4.delete at T2\n";
		cout << "5.search at T1 \t 6.search at T2 \t 7.print T1 \t 8.print T2 \t 9.press any othwer key to exit\n ";
		
		cout <<"enter your choice:\n";
		int choice;
		cin >> choice;
		
//		cout << "enter the value:\n";
		int x;
		
		
		switch(choice)
		{
			case 1: cout << "insert at T1:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			insertT1(table, sizeT1, x);
			break;
			
			case 2: cout << "insert at T2:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			insertT2(arr, sizeT2, x);
			break;
			
			case 3: cout << "delete at T1:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			DeleteT1(table, sizeT1, x);
			break;
			
			case 4: cout << "delete at T2:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			DeleteT2(arr, sizeT2, x);
			break;
			
			case 5: cout << "to search at T1:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			if(searchT1(table,sizeT1,x))
			cout <<"found\n";
			else cout <<"not found\n";
			
			break;
			
			case 6: cout << "to search at T2:\n";
			//int x;
			cout <<"enter value:\n";
			cin >> x;
			
			if(searchT2(arr, sizeT2, x))
			cout <<"found\n";
			else cout << "not found\n";
			break;
			
			case 7: cout <<"T1:\n";
			printHashTableT1(table,sizeT1);
			cout << endl;
			break;
			
			case 8: cout <<"T2:\n";
			printHashTableT2(arr,sizeT2);
			cout << endl;
			break;
			
			default: cout <<"wrong choice ;(\n";
			exit(1);
			
			
		}
	}
    
}
