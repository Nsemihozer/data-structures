
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class AdjacencyMatrix
{
private:
	int n;
	int **adj;
	
public:
	AdjacencyMatrix(int n)   //Constructor O(n^2)
	{
		this->n = n;  //Size of matrix
		
		adj = new int*[n]; //Creating Dynamic Matrix  
		for (int i = 0; i < n; i++)
		{
			adj[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
	void add_node(int n) //Adding Node to Graph O(n^2)
	{
		int j, i;
		AdjacencyMatrix tmp(n);
		this->n = n;
		for ( i = 0; i < n-1; i++) // Adding old distance to new matrix
		{
			for ( j = 0; j < n-1; j++)
			{
				tmp.adj[i][j] = adj[i][j];
			}
		}
		j = n - 1;
		for ( i = 0; i < n; i++) // Initialize new nodes's distance
		{
			tmp.adj[i][j] = 0;
		}
		for ( i = 0; i < n; i++) //// Initialize new nodes's distance
		{
			tmp.adj[j][i] = 0;
		}
		adj = tmp.adj; 
	}
	void del_node(int n) //Deleting Node from Graph O(n^2)
	{
		int j, i;
		AdjacencyMatrix tmp(n);
		this->n = n;
		for (i = 0; i < n ; i++) // Adding old distance to new matrix
		{
			for (j = 0; j < n ; j++)
			{
				tmp.adj[i][j] = adj[i][j];
			}
		}
		adj = tmp.adj;
	}
	
	void add_edge(int origin, int destin)       // Adding Edge to Graph  O(1)
	{
		
		if (origin > n || destin > n || origin < 0 || destin < 0) 
		{
			cout << "Invalid edge!\n";
		}
		else
		{
			int x = rand() % 9 + 1; //Distance take a random number 
			adj[origin - 1][destin - 1] = x; //Distance adding matrix 2-sided path
			adj[destin - 1][origin - 1] = x;
		}
	}
	void del_edge(int origin, int destin) //Deleting edge from graph O(1)
	{
		if (origin > n || destin > n || origin < 0 || destin < 0)
		{
			cout << "Invalid edge!\n";
		}
		else
		{
			adj[origin - 1][destin - 1] = 0; //2-sided path clearing
			adj[destin - 1][origin - 1] = 0;
		}
	}
	
	void display(char a[]) //Print Adjacency Matrix O(n^2)
	{
		int i, j;
		
		for (i = 0; i < n; i++)
		{
			if (i == 0)
			{
				cout << "   ";
				for (int k = 0; k < n; k++)
				{
					cout <<a[k] << "  ";
				}
				cout << endl;
			}
			cout << a[i] << "  ";
			for (j = 0; j < n; j++)
			{
				cout << adj[i][j] << "  ";
			}
			cout << endl;
		}
	}
	void distance(int a, int b) //Setting new distance O(1)
	{
		int i;
		cout << "Enter new distance" << endl;
		cin >> i;
		adj[a - 1][b - 1] = i;
		adj[b - 1][a - 1] = i;
	}

};
void name(char a[], int b) //Setting new node name O(1)
{
	char x;
	cout << "Enter new name : ";
	cin >> x;
	a[b - 1] = x;
}



/*
 * Main
  */
int main()
{
	srand(time(NULL));
	char a[] = { 'A','B','C','D','E','F','G','H','K','L' },choice;
	int nodes, max_edges, origin, destin;
	cout << "Enter number of nodes: ";
	cin >> nodes;
	if (nodes > 10)
	{
		cout << "Enter lower from 10" << endl;
		cin >> nodes;
	}
	AdjacencyMatrix am(nodes);
	max_edges = nodes * (nodes - 1);
	for (int i = 0; i < max_edges; i++)
	{
		cout << "Enter edge (-1 -1 to exit): ";
		cin >> origin >> destin;
		if ((origin == -1) && (destin == -1))
			break;
		am.add_edge(origin, destin);
	}
	while (1)
	{
		cout << "-----------------" << endl;
		cout << "Node	Ekle	-->E" << endl;
		cout << "Path	Ekle	-->R" << endl;
		cout << "Distance	-->A" << endl;
		cout << "Name	-->S" << endl;
		cout << "Node	Delete-->N" << endl;
		cout << "Path	Delete-->P" << endl;
		cout << "Goster	-->D" << endl;
		cout << "Exit	-->Q" << endl;
		cout << "-----------------" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		choice=toupper(choice);
		switch (choice)
		{
		case 'E':
			nodes++;
			am.add_node(nodes);
			break;
		case 'R':
			cout << "Enter edge : ";
			cin >> origin >> destin;
			am.add_edge(origin, destin);		
			break;
		case 'A':
			cout << "Enter edge : ";
			cin >> origin >> destin;
			am.distance(origin, destin);
			break;
		case 'S':
			cout << "Enter Node : ";
			cin >> origin;
			name(a, origin);
			break;
		case 'N':
			nodes--;
			am.del_node(nodes);
			break;
		case 'P':
			cout << "Enter edge : ";
			cin >> origin >> destin;
			am.del_edge(origin, destin);
			break;
		case 'D':
			am.display(a);
			break;
		case 'Q':
			exit(1);
		default:
			cout << "Listeden eleman seciniz." << endl;
		}
	}
	system("pause");
}