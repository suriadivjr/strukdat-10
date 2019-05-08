/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-10, exercise-02, Circular Queue using Linked List
Tahun           : 2019
*/

#include<iostream>
using namespace std;

struct charQueue
{
	char info;
	charQueue* next;
};
typedef charQueue* pointer;
typedef pointer List;

struct Queue
{
	List Head;
	List Tail;
};
Queue Q;

void createQueue (Queue& Q)
{
	Q.Head=Q.Tail=NULL;
}

void createElmnt (pointer& pBaru)
{
	pBaru=new charQueue;
	cout << "Masukkan huruf: "; cin >> pBaru->info;
	pBaru->next=NULL;
}

void push(Queue& Q, pointer pBaru)
{
	if (Q.Head==NULL && Q.Tail == NULL)
	{
		Q.Head=pBaru;
		Q.Tail=pBaru;
	}
	else
	{
		Q.Tail->next=pBaru;
		Q.Tail=pBaru;
	}
}

void pop(Queue& Q, pointer pHapus)
{
	if (Q.Head==NULL && Q.Tail==NULL)
	{
		pHapus=NULL;
		cout << "List queue kosong." << endl;
	}
	else if (Q.Head->next==NULL)
	{
		pHapus=Q.Head;
		Q.Head=NULL;
		Q.Tail=NULL;
	}
	else 
	{
		pHapus=Q.Head;
		Q.Head=Q.Head->next;
		pHapus->next=NULL;
	}
}

void printQueue(Queue Q)
{
	pointer pBantu;
	if(Q.Head==NULL && Q.Tail==NULL ) cout << "List queue kosong." << endl;
	else
	{	
		pBantu=Q.Head;
		do 
		{
			cout << pBantu->info << " ";
			pBantu=pBantu->next;
		} 
		while (pBantu!=NULL);
	}
	cout << endl;
}

int main()
{
	Queue Q;
	pointer p, pHapus;
	char pil;
	int menu;
	
	createQueue(Q);

	do
	{
		system("cls");
		cout << "Menu:\n1. Insert\n2. Pop\n3. View All\nChoice: "; cin >> menu;
		switch(menu)
		{
			case 1: createElmnt(p);
					push(Q,p); 
					break;
			case 2: pop(Q,pHapus); 
					break;
			case 3: printQueue(Q);
					break;
			default: cout << "Wrong Option.\n"; 
					 break;
		}
		cout << "Again? (Y/N) "; cin >> pil;
	} while (pil=='Y' || pil=='y');
}


