#include <bits/stdc++.h>
using namespace std;

struct Student
{
	int roll;
	//int rollNO;
	//string house;
	int marks[3];
};

void insertion (vector<struct Student> &arr)
{
	int size= arr.size();
	
	for(int i=1; i<size; i++)
	{
		struct Student key= arr[i];
		int j= i-1;
		
		
		while(j>=0 && key.roll<arr[j].roll)
		{
			arr[j+1]=arr[j];
			j--;
		}
		
		arr[j+1]= key;
	}
	
}

int partition(vector<struct Student> &arr, int start, int end)
{
	int pivot = arr[start].roll;
	
	int left= start-1;
	int right= end+1;
	
	while(true)
	{
		do
		{
			left++;
		}while(arr[left].roll<pivot);
		
		do
		{
			right--;
		}while(arr[right].roll>pivot);
		
		if(left>=right) return right;
		
		struct Student temp = arr[left];
		arr[left]=arr[right];
		arr[right]= temp;
	}
}

void QUICKSORT(vector<struct Student> &arr, int start, int end)
{
	if(start<end)
	{
		int pivot = partition(arr, start, end);
		
		QUICKSORT(arr,start,pivot);
		QUICKSORT(arr, pivot+1, end);
	}
}
void quicksort(vector<struct Student> &arr)
{
	QUICKSORT(arr,0,arr.size()-1);
}

void displayStruct(struct Student st)
{
	cout << st.roll <<"\t";
		
	switch(st.roll/10000)
	{
		case 10: cout <<"Gryffindor" <<"\t";break;
		case 11: cout <<"Hufflepuff"<<"\t";break;
		case 12: cout <<"Ravenclaw" <<"\t";break;
		default: cout << "Slytherin" <<"\t"; break;
	}
	
	for(int k=0;k<3;k++)
	{
		cout << st.marks[k];
		cout << "(00"<<k+1<<")" << "\t";
	}
	
	cout << endl;
}
void displayList(vector<struct Student> arr)
{
	int len = arr.size();
	
	for(int i=0;i<len ;i++)
	{
//		cout << arr[i].roll <<"\t";
//		
//		switch(arr[i].roll/10000)
//		{
//			case 10: cout <<"Gryffindor" <<"\t";break;
//			case 11: cout <<"Hufflepuff"<<"\t";break;
//			case 12: cout <<"Ravenclaw" <<"\t";break;
//			default: cout << "Slytherin" <<"\t"; break;
//		}
//		
//		for(int k=0;k<3;k++)
//		{
//			cout << arr[i].marks[k];
//			cout << "(001)" << "\t";
//		}
//		
//		cout << endl;

        displayStruct(arr[i]);
	}
}

void BinSearch(vector<struct Student> arr, int r)
{
	int start =0;
	int end= arr.size()-1;
	
	//int index=-1;
	
	while(start <= end)
	{
		int mid = (start+end)/2;
		
		if(arr[mid].roll == r)
		{
			cout <<"FOUND!\n";
			displayStruct(arr[mid]);
			return;
		}
		else if(r< arr[mid].roll)
		end = mid-1;
		else start = mid+1;
		
	}
	
	cout <<"no such roll no\n";
}

int main()
{
	cout << "enter no of students:\n";
	int n;
	cin>>n;
	
	vector<struct Student> record(n);
	
	for(int i=0; i<n; i++)
	{
		cout <<"For student"<< i+1 <<": \n";
		
		cout <<"roll no: \n";
		cin>> record[i].roll;
		
		//record[i].rollNO = record[i].roll % 10000;
		
		cout <<"Enter marks for 3 subjects respectively:\n";
		for(int k=0;k<3;k++)
		cin>>record[i].marks[k];
		
	}
	
	//displayList(record);
	
	cout <<endl;
	quicksort(record);
	displayList(record);
	
	
	cout<<"enter no of bunches of 3 additonal ips:\n";
	int bunch;
	cin>>bunch;
	while(bunch--){
	for(int i=1; i<=3; i++)
	{
		struct Student st;
		
		cout <<"roll no: \n";
		cin>> st.roll;
		
		//record[i].rollNO = record[i].roll % 10000;
		
		cout <<"Enter marks for 3 subjects respectively:\n";
		for(int k=0;k<3;k++)
		cin>>st.marks[k];
		
		record.push_back(st);
		
	}
    }
    
	cout << endl;
	displayList(record);
	cout << endl; 
	
	cout <<"after insertion sort;\n";
	insertion(record);
	displayList(record);
	
	
	int R;
	cout << "enter roll no to search:\n";
	cin>>R;
	
	BinSearch(record,R);
	
}

/*
100001 85 72 76
110002 80 71 46
120001 39 72 96
130011 35 92 44
150011 35 92 44
130012 35 92 44

100001 85 72 76
110002 80 71 46
120001 39 72 96
130011 35 92 44
130012 35 92 44
150011 35 92 44
100252 96 31 4
130008 9 4 1
120404 63 41 88
102020 20 20 20
133333 22 96 41
110200 3 1 4
*/
