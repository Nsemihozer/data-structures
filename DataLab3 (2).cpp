#include<iostream>

using namespace std;
class Kuyruk // Liste oluþturma
{
	int data, front, rear, size, noItems, *dizi;
public:
	Kuyruk(int x)
	{
		size = x;
		dizi = new int[size];
		front = rear = noItems = 0;

	}
	bool isEmpty()
	{
		return noItems == 0;
	}
	bool isFull()
	{
		return noItems == size;
	}
	void enqueue(int x)
	{

		if (isFull())
			cout << "Dolu" << endl;
		else
		{
			dizi[rear] = x;
			rear++;
			if (rear == size) rear = 0;
			noItems++;

		}
	}
	void dequeue() // Ýlk eleman çýkarma iþlemi
	{

		if (isEmpty())
			cout << "Bos" << endl;
		else
		{
			cout << dizi[front];
			front++; if (front == size) front = 0;
			
			noItems--;

		}
	}
	void listele() // Kuyruktaki elemanlarý listeleme
	{
		if (isEmpty()) // Boþ mu deðil mi?
		{
			cout << "Empty Queue" << endl;
		}
		else
		{
			for(int i = front;i<noItems;i++)
			{
				if (i == size)
					i = 0;
				cout << dizi[i];
			}
		}
	}
	void say() //Eleman sayýsý
	{
		cout << noItems;
	}
};








int main() {

	char ch;
	int  x, y;
	cout << "Enter The Size" << endl;
	cin >> x;
	Kuyruk k(x);



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
			k.enqueue(y);
		}
		break;

		case'S':
			k.say();
			break;

		case'D':
			k.dequeue();
			break;

		case'L':
			k.listele();
			break;


		default:
			cout << "Select a Character from List." << endl;
			break;

		}

	}

	system("PAUSE");


}