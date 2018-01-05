#include<iostream>
using namespace std;


//   Creating a NODE Structure
struct node
{
	int data;
    node *next;
};
 node *top=NULL;
 node *ptr;


// PUSH Operation
void push()
{
	int value;
	
	cout << "\nPUSH Operationn";
	cout << "Enter a number to insert: ";
	cin >> value;
	ptr = new node;
	ptr->data = value;
	ptr->next = NULL;
	if (top != NULL)
		ptr->next = top;
	top = ptr;
	cout << "\nNew item is inserted to the stack!!!";

}

// POP Operation
void pop()
{
	
	if (top == NULL)
	{
		cout << "\nThe stack is empty!!!";
	}
	else
	{
		ptr = top;
		top = top->next;
		cout << "\nPOP Operation........\nPoped value is " << ptr->data;
		delete ptr;
	}
}

// Show stack
void show()
{
	ptr = top;
	cout << "\nThe stack is\n";
	while (ptr != NULL)
	{
		cout << ptr->data << " ->";
		ptr = ptr->next;
	}
	cout << "NULL\n";
}
void say()
{
	ptr = top;
	int c=0;
	cout << "\nThe stack is\n";
	while (ptr != NULL)
	{
		c++;
		ptr = ptr->next;
	}
	cout << c;
}

// Main function
int main()
{
	
	int choice;
	while (1)
	{
		cout << "\n-----------------------------------------------------------";
		cout << "\n\t\tSTACK USING LINKED LIST\n\n";
		cout << "1:PUSH\n2:POP\n3:DISPLAY STACK\n4:Count\n5:EXIT";
		cout << "\nEnter your choice(1-4): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			show();
			break;
		case 4:
			say();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "\nPlease enter correct choice(1-4)!!";
			break;
		}
	}
	return 0;
}