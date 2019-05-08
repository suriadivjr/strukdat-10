/*
Author    		: SURIADI VAJRAKARUNA
NPM		        : 140810180038
Deskripsi	    : strukdat-10, exercise-01, Circular Queue using Array
Tahun           : 2019
*/

#include<iostream>
#include <windows.h>
using namespace std;

const int maxElement=5;

struct Queue
{
	char isi[maxElement];
	int Head;
	int Tail;
};

void createQueue (Queue& Q)
{
	Q.Head=0;
	Q.Tail=-1;
};

void push (Queue& Q, char element)
{
	if (Q.Tail==maxElement-1)
	{
		Q.Tail=Q.Head;
		Q.Head++;
		Q.isi[Q.Tail]=element;
	}
	else
	{
		Q.Tail=Q.Tail+1;
		Q.isi[Q.Tail]=element;
	}
}

void pop (Queue& Q, char& elementHapus)
{
	if (Q.Head==-1) cout << "Antrian kosong.";
	else 
	{
		elementHapus=Q.isi[Q.Head];
		for (int i=0; i<Q.Tail; i++)
		{
			Q.isi[i]=Q.isi[i+1];
		}
		
		Q.Tail=Q.Tail-1;
	}
}

void printQueue (Queue Q)
{
	if (Q.Head<Q.Tail)
	{
		for (int i=0; i<=Q.Tail; i++)
		{	
			cout << Q.isi[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i=Q.Head; i<maxElement; i++)
		{
			cout << Q.isi[i] << " ";
		}
		for (int i=0; i<=Q.Tail; i++)
		{
			cout << Q.isi[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Queue Q;
	char element,elementHapus,pil;
	int menu;
	
	createQueue(Q);

	do
	{
		system("cls");
		cout << "Menu:\n1. Insert\n2. Pop\n3. View All\nChoice: "; cin >> menu;
		switch(menu)
		{
			case 1: cout << "Char: "; 
					cin >> element; 
					push(Q,element); 
					break;
			case 2: pop(Q,elementHapus); 
					break;
			case 3: printQueue(Q);
					break;
			default: cout << "Wrong Option.\n"; 
					 break;
		}
		cout << "Again? (Y/N) "; cin >> pil;
	} while (pil=='Y' || pil=='y');
}
