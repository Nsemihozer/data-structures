# include <iostream>
# include <cstdlib>
using namespace std;


// Baðlý Liste
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
node *root = NULL;

//Sýnýf Yapýsý
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

// Agactaki elemaný bulma
void BST::find(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if (root == NULL) // Agac Boþsa
	{
		*loc = NULL;
		*par = NULL;

		return;
	}
	if (item == root->info) //Aranan eleman kökse
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if (item < root->info) //Aranan eleman kökten küçükse
	{
		ptr = root->left;
	}
	else // Aranan eleman kökten büyükse
	{
		ptr = root->right;
	}
	ptrsave = root;
	while (ptr != NULL) // Elemaný bulana kadar gezinme O(n)
	{
		if (item == ptr->info) // Eleman bulunca yerini kaydetme
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info) // Sol çocuklara bakma
		{
			ptr = ptr->left;
		}
		else         //Sag çocuklara bakma
		{
			ptr = ptr->right;
		}
	}
	*loc = NULL; // Eleman yoksa
	*par = ptrsave;
}

// Aðaca elaman ekleme
void BST::insert(node *tree, node *newnode)
{
	if (root == NULL)       // Aðaç boþsa köke ekleme
	{
		root = new node;
		root->info = newnode->info;
		root->left = NULL;
		root->right = NULL;
		cout << "Kok Eklendi" << endl;
		say = 1;
		return;
	}
	
	if (tree->info > newnode->info) // Eklenecek sayi ebeveynden küçükse
	{

		if (tree->left != NULL) // Ebeveynin solu boþ deðilse rekürsif ekleme iþlemi kaydýrýlýr O(n)
		{
			insert(tree->left, newnode);
		}
		else // Boþsa Ekleme yapýlýr
		{
			say++;
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Sola eklendi" << endl;
			return;
		}
	}
	else //Eklenecek sayi ebeveynden büyükse
	{

		if (tree->right != NULL) // Ebeveynin saðý boþ deðilse rekürsif ekleme iþlemi kaydýrýlýr O(n)
		{
			insert(tree->right, newnode);
		}
		else // Boþsa Ekleme yapýlýr
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

// Aðaçtan eleman silme
void BST::del(int item)
{
	node *parent, *location;
	if (root == NULL) // Aðaç Boþsa
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
	if (location->left == NULL && location->right == NULL) // Sol ve Sað çocuklarý yoksa
		case_a(parent, location);
	if (location->left != NULL && location->right == NULL) // Sol çocuðu varsa
		case_b(parent, location);
	if (location->left == NULL && location->right != NULL) // Sað çocuðu varsa
		case_b(parent, location);
	if (location->left != NULL && location->right != NULL) // iki çocuðuda varsa
		case_c(parent, location);
	free(location);
}



void BST::case_a(node *par, node *loc) // Çocuksuz
{
	if (par == NULL) // kökse kökü silme
	{
		root = NULL;
		say = 0;
	}
	else //deðilse yapraðý silme
	{
		say--;
		if (loc == par->left) // Silinecek eleman sol çocuksa ebeveyninin solunu siliyoruz
		{
			par->left = NULL;
		}
		else // Silinecek eleman sol çocuksa ebeveyninin solunu siliyoruz
		{
			par->right = NULL;
		}
	}
}



void BST::case_b(node *par, node *loc) // Tek çocuklu
{
	node *child;
	if (loc->left != NULL) // Sol çocuðu varsa
	{
		child = loc->left;

	}
	else // Sað çocuðu varsa
	{
		child = loc->right;
	}
	if (par == NULL) //Kökse kökü silip çocuðu kök yapma
	{
		root = child;
		say--;
	}
	else // Kök deðilse
	{
		say--;
		if (loc == par->left) //Silinecek eleman sol çocuksa ebeveynin solu elemanýn çocuðu olur
		{
			par->left = child;
		}
		else //Silinecek eleman sað çocuksa ebeveynin saðý elemanýn çocuðu olur
		{
			par->right = child;
		}
	}
}


void BST::case_c(node *par, node *loc) // Çift Çocuklu
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
void BST::preorder(node *ptr) // Önce kök yazdýrýlýr sonra çocuklar O(n)
{
	if (root == NULL) // Aðaç Boþa
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->info << "  "; // Kökü yazdýrma
		preorder(ptr->left); // Sol çocuðu yazdýrmak için kaydýrma
		preorder(ptr->right); // Sað çocuðu yazdýrmak için kaydýrma
	}
}

 // InOrder Listeleme

void BST::inorder(node *ptr) // Önce sol çocuk yazdýrýlýr sonra kök sonra sað çocuk O(n)
{
	if (root == NULL) // Aðaç Boþa
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL) 
	{
		inorder(ptr->left); // Sol çocuðu yazdýrmak için kaydýrma
		cout << ptr->info << "  ";  // Kökü yazdýrma 
		inorder(ptr->right); // Sað çocuðu yazdýrmak için kaydýrma
	}
}

// PostOrder Listeleme
void BST::postorder(node *ptr) // Önce sol çocuk yazdýrýlýr sonra sað çocuk sonra kök  O(n)
{
	if (root == NULL)
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left); // Sol çocuðu yazdýrmak için kaydýrma
		postorder(ptr->right); // Sað çocuðu yazdýrmak için kaydýrma
		cout << ptr->info << "  ";  // Kökü yazdýrma 
	}
}

// Aðacýn yapýsýný gösterme

void BST::display(node *ptr, int level)
{
	int i;
	if (root == NULL) // Aðaç boþsa
	{
		cout << "Agac Bos" << endl;
		return;
	}
	if (ptr != NULL)
	{
		display(ptr->right, level + 1); // En saðdaki elemana gitme O(n)
		cout << endl;
		if (ptr == root) // Gösterilecek eleman kökse
			cout << "Kok->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->info; // Elemaný yazdýrma
		display(ptr->left, level + 1); // Sol çocuklarý yazdýrma
	}
}