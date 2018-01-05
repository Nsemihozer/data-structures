# include <iostream>
# include <cstdlib>
using namespace std;


// Ba�l� Liste
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
node *root = NULL;

//S�n�f Yap�s�
class BST
{
public:
	void find(int, node **, node **);
	void insert(node *, node *);
	void del(int);
	void case_a(node *, node *);
	void case_b(node *, node *);
	void case_c(node *, node *);
	void preorder(node *);
	void inorder(node *);
	void postorder(node *);
	void display(node *, int);
	BST() // Constructor
	{
	}
	
};
int say;
int main()
{
	int  num;
	char choice;
	BST bst;
	node *temp;
	while (1) //MENU
	{
		cout << "-----------------" << endl;
		cout << "Ekle	-->E" << endl;
		cout << "Sil	-->D" << endl;
		cout << "Inorder	-->I" << endl;
		cout << "Pre	-->P" << endl;
		cout << "Post	-->O" << endl;
		cout << "Goster	-->G" << endl;
		cout << "Say	-->S" << endl;
		cout << "Cikis	-->C" << endl;
		cout << "-----------------" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		toupper(choice);
		switch (choice)
		{
		case 'E':
			temp = new node;
			cout << "Eklenecek sayi : ";
			cin >> temp->info;
			bst.insert(root, temp);
			break;
		case 'D':
			if (root == NULL)
			{
				cout << "Agac Bos" << endl;
				continue;
			}
			cout << "Silinecek sayiyi giriniz : ";
			cin >> num;
			bst.del(num);
			break;
		case 'I':
			cout << "Inorder listeleme:" << endl;
			bst.inorder(root);
			cout << endl;
			break;
		case 'P':
			cout << "Preorder listeleme:" << endl;
			bst.preorder(root);
			cout << endl;
			break;
		case 'O':
			cout << "Postorder listeleme" << endl;
			bst.postorder(root);
			cout << endl;
			break;
		case 'G':
			cout << "Goster BST:" << endl;
			bst.display(root, 1);
			cout << endl;
			break;
		case 'C':
			exit(1);
		case 'S':
			cout << "Elaman Sayisi:" << endl;
			cout << say << endl;
			break;
		default:
			cout << "Listeden eleman seciniz." << endl;
		}
	}
}

// Agactaki eleman� bulma
void BST::find(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if (root == NULL) // Agac Bo�sa
	{
		*loc = NULL;
		*par = NULL;

		return;
	}
	if (item == root->info) //Aranan eleman k�kse
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if (item < root->info) //Aranan eleman k�kten k���kse
	{
		ptr = root->left;
	}
	else // Aranan eleman k�kten b�y�kse
	{
		ptr = root->right;
	}
	ptrsave = root;
	while (ptr != NULL) // Eleman� bulana kadar gezinme O(n)
	{
		if (item == ptr->info) // Eleman bulunca yerini kaydetme
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info) // Sol �ocuklara bakma
		{
			ptr = ptr->left;
		}
		else         //Sag �ocuklara bakma
		{
			ptr = ptr->right;
		}
	}
	*loc = NULL; // Eleman yoksa
	*par = ptrsave;
}

// A�aca elaman ekleme
void BST::insert(node *tree, node *newnode)
{
	if (root == NULL)       // A�a� bo�sa k�ke ekleme
	{
		root = new node;
		root->info = newnode->info;
		root->left = NULL;
		root->right = NULL;
		cout << "Kok Eklendi" << endl;
		say = 1;
		return;
	}
	
	if (tree->info > newnode->info) // Eklenecek sayi ebeveynden k���kse
	{

		if (tree->left != NULL) // Ebeveynin solu bo� de�ilse rek�rsif ekleme i�lemi kayd�r�l�r O(n)
		{
			insert(tree->left, newnode);
		}
		else // Bo�sa Ekleme yap�l�r
		{
			say++;
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Sola eklendi" << endl;
			return;
		}
	}
	else //Eklenecek sayi ebeveynden b�y�kse
	{

		if (tree->right != NULL) // Ebeveynin sa�� bo� de�ilse rek�rsif ekleme i�lemi kayd�r�l�r O(n)
		{
			insert(tree->right, newnode);
		}
		else // Bo�sa Ekleme yap�l�r
		{
			say++;
			tree->right = newnode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << "Saga eklendi" << endl;
			return;
		}
	}
}

// A�a�tan eleman silme
void BST::del(int item)
{
	node *parent, *location;
	if (root == NULL) // A�a� Bo�sa
	{
		cout << "Agac Bos" << endl;
		return;
	}
	find(item, &parent, &location); // Silinecek Sayiyi arama 
	if (location == NULL)
	{
		cout << "Eleman agacta yok" << endl;
		return;
	}
	if (location->left == NULL && location->right == NULL) // Sol ve Sa� �ocuklar� yoksa
		case_a(parent, location);
	if (location->left != NULL && location->right == NULL) // Sol �ocu�u varsa
		case_b(parent, location);
	if (location->left == NULL && location->right != NULL) // Sa� �ocu�u varsa
		case_b(parent, location);
	if (location->left != NULL && location->right != NULL) // iki �ocu�uda varsa
		case_c(parent, location);
	free(location);
}



void BST::case_a(node *par, node *loc) // �ocuksuz
{
	if (par == NULL) // k�kse k�k� silme
	{
		root = NULL;
		say = 0;
	}
	else //de�ilse yapra�� silme
	{
		say--;
		if (loc == par->left) // Silinecek eleman sol �ocuksa ebeveyninin solunu siliyoruz
		{
			par->left = NULL;
		}
		else // Silinecek eleman sol �ocuksa ebeveyninin solunu siliyoruz
		{
			par->right = NULL;
		}
	}
}



void BST::case_b(node *par, node *loc) // Tek �ocuklu
{
	node *child;
	if (loc->left != NULL) // Sol �ocu�u varsa
	{
		child = loc->left;

	}
	else // Sa� �ocu�u varsa
	{
		child = loc->right;
	}
	if (par == NULL) //K�kse k�k� silip �ocu�u k�k yapma
	{
		root = child;
		say--;
	}
	else // K�k de�ilse
	{
		say--;
		if (loc == par->left) //Silinecek eleman sol �ocuksa ebeveynin solu eleman�n �ocu�u olur
		{
			par->left = child;
		}
		else //Silinecek eleman sa� �ocuksa ebeveynin sa�� eleman�n �ocu�u olur
		{
			par->right = child;
		}
	}
}


void BST::case_c(node *par, node *loc) // �ift �ocuklu
{
	node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->right;
	while (ptr->left != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == NULL && suc->right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if (par == NULL)
	{
		root = suc;

	}
	else
	{
		say--;
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
}

// PreOrder Listeleme
void BST::preorder(node *ptr) // �nce k�k yazd�r�l�r sonra �ocuklar O(n)
{
	if (root == NULL) // A�a� Bo�a
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->info << "  "; // K�k� yazd�rma
		preorder(ptr->left); // Sol �ocu�u yazd�rmak i�in kayd�rma
		preorder(ptr->right); // Sa� �ocu�u yazd�rmak i�in kayd�rma
	}
}

 // InOrder Listeleme

void BST::inorder(node *ptr) // �nce sol �ocuk yazd�r�l�r sonra k�k sonra sa� �ocuk O(n)
{
	if (root == NULL) // A�a� Bo�a
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL) 
	{
		inorder(ptr->left); // Sol �ocu�u yazd�rmak i�in kayd�rma
		cout << ptr->info << "  ";  // K�k� yazd�rma 
		inorder(ptr->right); // Sa� �ocu�u yazd�rmak i�in kayd�rma
	}
}

// PostOrder Listeleme
void BST::postorder(node *ptr) // �nce sol �ocuk yazd�r�l�r sonra sa� �ocuk sonra k�k  O(n)
{
	if (root == NULL)
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left); // Sol �ocu�u yazd�rmak i�in kayd�rma
		postorder(ptr->right); // Sa� �ocu�u yazd�rmak i�in kayd�rma
		cout << ptr->info << "  ";  // K�k� yazd�rma 
	}
}

// A�ac�n yap�s�n� g�sterme

void BST::display(node *ptr, int level)
{
	int i;
	if (root == NULL) // A�a� bo�sa
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		display(ptr->right, level + 1); // En sa�daki elemana gitme O(n)
		cout << endl;
		if (ptr == root) // G�sterilecek eleman k�kse
			cout << "Kok->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->info; // Eleman� yazd�rma
		display(ptr->left, level + 1); // Sol �ocuklar� yazd�rma
	}
}