#include<iostream>

using namespace std;
struct list // Liste oluþturma
{
	int data;
	list *next;
};
list *front = NULL; // ilk elemaný tutacak pointer
list *rear = NULL;  // son elemaný tutacak pointer
list *np = NULL;  //yardýmcý pointeri
int a = 0;       // eleman sayisi
void enqueue(int x,int size)
{
	
	if (a == size) // Doluluk Kontrolü
	{
		cout << "Queue is Full" << endl;
	}
	else
	{
		np = new list;
		np->data = x;
		np->next = NULL;
		if (front == NULL) // Boþsa ilk baðlantý oluþturuluyor 
		{
			front = rear = np;
			rear->next = NULL;
			a++;
		}
		else // Diðer durumlar
		{
			rear->next = np;
			rear = np;
			rear->next = NULL;
			a++;
		}
	}
}

void dequeue() // Ýlk eleman çýkarma iþlemi
{
	
	if (front == NULL) // Boþ mu deðil mi ?
	{
		cout << "Empty Queue" << endl;
	}
	else // Doluysa frontu kaydýrýp ilk elemaný siliyoruz
	{
		np = front;		
		front = front->next;
		cout << "Dequeue Element:" << endl;
		cout << np->data;
		delete(np);
		a--;
	}
}
void say() //Eleman sayýsý
{
	np = front;
	
	cout << "Number of Element" << endl;
	cout << a << endl;
}

void listele() // Kuyruktaki elemanlarý listeleme
{
	if (front == NULL) // Boþ mu deðil mi?
	{
		cout << "Empty Queue"<<endl;
	}
	else
	{
		cout << "Queue" << endl;
		np = front;
		while (np != NULL) // karmaþýklýk n
		{
			cout << np->data << endl;
			np = np->next;

		}
	}
}

int main() {

	char ch;
	int  x, y;
	cout << "Enter The Size" << endl;
	cin >> x;
	



	for (;;) // KARMAÞIKLIK SONSUZ
	{
		cout << endl;
		cout << "--------------" << endl;
		cout << "ENQUEUE	--> E" << endl;   //MENU  
		cout << "COUNT	--> S " << endl;
		cout << "DEQUEUE	--> D" << endl;
		cout << "LIST	--> L" << endl;
		cout << "EXIT	--> C" << endl;
		cout << "--------------" << endl;
		cout << endl;
		cin >> ch;
		ch = toupper(ch);
		if (ch == 'C')
			break;
		switch (ch)
		{
		case 'E':
		{
			cout << endl << "Input the Value: ";
			cin >> y;
			enqueue(y,x);
		}
		break;

		case'S':
			say();
			break;

		case'D':
			dequeue();
			break;

		case'L':
			listele();
			break;


		default:
			cout << "Select a Character from List." << endl;
			break;

		}

	}

	system("PAUSE");


}