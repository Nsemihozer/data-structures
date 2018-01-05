#include <iostream>
using namespace std;

int toplam(int para[], int banknot[])
{
	// Elimizdeki toplam paray� hesaplama fonksiyonu
	int toplamPara = 0;
	for (int i = 0; i < 6; i++)
	{
		toplamPara += para[i] * banknot[i];
	}
	return toplamPara;
}

//En Az banknotla verilen miktara ula�ma fonksiyonu
void EnAzBanknot(int para[], int banknot[]) 
{
	int miktar;
	int adet[6] = { 0,0,0,0,0,0 };
	if (toplam(para, banknot) < 5) // Elimizde para olup olmad���n�n ko�ulu
	{
		cout << "Para yok" << endl;
		return;
	}
	cout << "Eldeki para : " << toplam(para, banknot) << endl;
	cout << "Miktar giriniz : ";
	cin >> miktar;
	while (toplam(para, banknot) < miktar || miktar < 0)   // miktar�n 0 dan b�y�k ve toplam param�zdan k���k olmas� i�in d�ng�
	{
		cout << "Miktar sifirdan kucuk ve ya toplam paradan buyuk olamaz." << endl;
		cout << "Miktari giriniz : ";
		cin >> miktar;
	}
	cout << miktar << " TL en az banknotla" << endl << endl;

	if (miktar % 5 != 0) // Tam gelmiyorsa fazla verebilmek i�in
	{
		miktar = miktar - (miktar % 5) + 5;
	}
	for (int i = 5; i >= 0; i--) // elimizde olmayan banknotlar� miktara ekliyoruz ki en az banknotu bulabilelim
	{
		if (para[i] == 0)
		{
			miktar += banknot[i];
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 6;) // 
	{
		if (miktar >= banknot[i] && para[i] > adet[i]) // miktar baknottan b�y�kse ve elimizde o banknottan varsa veriyoruz
		{
			adet[i]++;
			miktar -= banknot[i];
		}
		else
		{
			i++;
		}
	}

	

	cout << "HESAPLANAN :" << endl;
	cout << "|200 TL|  x" << adet[0] << " =	" << adet[0] * banknot[0] << endl;
	cout << "|100 TL|  x" << adet[1] << " =	" << adet[1] * banknot[1] << endl;
	cout << "|50  TL|  x" << adet[2] << " =	" << adet[2] * banknot[2] << endl;
	cout << "|20  TL|  x" << adet[3] << " =	" << adet[3] * banknot[3] << endl;
	cout << "|10  TL|  x" << adet[4] << " =	" << adet[4] * banknot[4] << endl;
	cout << "|5   TL|  x" << adet[5] << " =	" << adet[5] * banknot[5] << endl << endl << endl;

}



void EnCokBanknot(int para[], int banknot[])
{
	int miktar;
	int adet[6];
	if (toplam(para, banknot) < 5) // Elimizde para olup olmad���n�n ko�ulu
	{
		cout << "Para yok" << endl; 
		return;
	}
	cout << "Eldeki para : " << toplam(para, banknot) << endl;
	cout << "Miktari giriniz : ";
	cin >> miktar;
	while (toplam(para, banknot) < miktar || miktar < 0) // miktar�n 0 dan b�y�k ve toplam param�zdan k���k olmas� i�in d�ng�
	{
		cout << "Miktar sifirdan kucuk ve ya toplam paradan buyuk olamaz." << endl;
		cout << "Miktari giriniz : ";
		cin >> miktar;
	}

	cout << miktar << " TL en �ok banknotla" << endl << endl;

	if (miktar % 5 != 0) // Tam gelmiyorsa fazla verebilmek i�in
	{
		miktar = miktar - (miktar % 5) + 5;
	}

	for (int i = 0; i < 6; i++)
	{
		adet[i] = para[i];
	}

	for (int i = 0; i < 6;) 
	{
		if (toplam(adet, banknot) - banknot[i] >= miktar && adet[i] > 0) // e�er o banknot olmamas�na ra�men ula�abiliyorsak o banknotu ��kart�yoruz
		{                                                                // ki en fazla banknotu verebilelim
			adet[i]--;
		}
		else
		{
			i++;
		}
	}

	
	cout << "HESAPLANAN :" << endl;
	cout << "|200 TL|  x" << adet[0] << " =	" << adet[0] * banknot[0] << endl;
	cout << "|100 TL|  x" << adet[1] << " =	" << adet[1] * banknot[1] << endl;
	cout << "|50  TL|  x" << adet[2] << " =	" << adet[2] * banknot[2] << endl;
	cout << "|20  TL|  x" << adet[3] << " =	" << adet[3] * banknot[3] << endl;
	cout << "|10  TL|  x" << adet[4] << " =	" << adet[4] * banknot[4] << endl;
	cout << "|5   TL|  x" << adet[5] << " =	" << adet[5] * banknot[5] << endl << endl << endl;

}



void EnBuyukBanknot(int para[], int banknot[]) {
	int miktar;
	int adet[6] = { 0,0,0,0,0,0 };

	if (toplam(para, banknot) < 5)  // Elimizde para olup olmad���n�n ko�ulu
	{
		cout << "Para yok" << endl;
		return;
	}
	cout << "Eldeki para : " << toplam(para, banknot) << endl;
	cout << "Miktari giriniz : ";
	cin >> miktar;
	while (toplam(para, banknot) < miktar || miktar < 0)  // miktar�n 0 dan b�y�k ve toplam param�zdan k���k olmas� i�in d�ng�
	{
		cout << "Miktar sifirdan kucuk ve ya toplam paradan buyuk olamaz." << endl;
		cout << "Miktari giriniz : ";
		cin >> miktar;
	}

	cout << miktar << " TL en buyuk banknotlarla" << endl << endl;

	for (int i = 0; i < 6;) 
	{
		if (miktar > 0 && para[i] > adet[i]) // en b�y�k banknotlardan vermeye ba�l�yoruz miktar� a��nca dur
		{
			miktar -= banknot[i];
			adet[i]++;
		}
		else
		{
			i++;
		}
	}
	cout << "HESAPLANAN :" << endl;
	cout << "|200 TL|  x" << adet[0] << " =	" << adet[0] * banknot[0] << endl;
	cout << "|100 TL|  x" << adet[1] << " =	" << adet[1] * banknot[1] << endl;
	cout << "|50  TL|  x" << adet[2] << " =	" << adet[2] * banknot[2] << endl;
	cout << "|20  TL|  x" << adet[3] << " =	" << adet[3] * banknot[3] << endl;
	cout << "|10  TL|  x" << adet[4] << " =	" << adet[4] * banknot[4] << endl;
	cout << "|5   TL|  x" << adet[5] << " =	" << adet[5] * banknot[5] << endl << endl << endl;

}

void EnKucukBanknot(int para[], int banknot[]) {
	int miktar;
	int adet[6] = { 0,0,0,0,0,0 };

	if (toplam(para, banknot) < 5) // Elimizde para olup olmad���n�n ko�ulu
	{
		cout << "Para yok" << endl;
		return;
	}
	cout << "Eldeki para : " << toplam(para, banknot) << endl;
	cout << "Miktari giriniz : ";
	cin >> miktar;
	while (toplam(para, banknot) < miktar || miktar < 0)  // miktar�n 0 dan b�y�k ve toplam param�zdan k���k olmas� i�in d�ng�
	{
		cout << "Miktar sifirdan kucuk ve ya toplam paradan buyuk olamaz." << endl;
		cout << "Miktari giriniz : ";
		cin >> miktar;
	}

	cout << miktar << " TL en kucuk banknotlarla" << endl << endl;

	for (int i = 5; i >= 0;)
	{
		if (miktar > 0 && para[i] > adet[i]) // en k���k banknotlardan vermeye ba�l�yoruz miktar� a��nca dur
		{
			miktar -= banknot[i];
			adet[i]++;
		}
		else
		{
			i--;
		}
	}
	cout << "HESAPLANAN :" << endl;
	cout << "|200 TL|  x" << adet[0] << " =	" << adet[0] * banknot[0] << endl;
	cout << "|100 TL|  x" << adet[1] << " =	" << adet[1] * banknot[1] << endl;
	cout << "|50  TL|  x" << adet[2] << " =	" << adet[2] * banknot[2] << endl;
	cout << "|20  TL|  x" << adet[3] << " =	" << adet[3] * banknot[3] << endl;
	cout << "|10  TL|  x" << adet[4] << " =	" << adet[4] * banknot[4] << endl;
	cout << "|5   TL|  x" << adet[5] << " =	" << adet[5] * banknot[5] << endl << endl << endl;

}

int main() 
{
	int banknot[] = { 200,100,50,20,10,5 };
	int miktar[6];

	for (int i = 0; i < 6; i++)
	{
		cout << banknot[i] << " tl miktari: ";
		cin >> miktar[i];
	}

	char choice;

	while (1) {
		cout << "-------------------" << endl;
		cout << "ANA MENU" << endl;
		cout << "A- EN  AZ BANKNOT" << endl;
		cout << "C- EN COK BANKNOT" << endl;
		cout << "B- EN BUYUK BANKNOT" << endl;
		cout << "K- EN KUCUK BANKNOT" << endl;
		cout << "Q- CIKIS" << endl;
		cout << "-------------------" << endl;
		cin >> choice;
		choice=toupper(choice);
		switch (choice)
		{
		case 'A':
			EnAzBanknot(miktar, banknot);
			break;
		case 'C':
			EnCokBanknot(miktar, banknot);
			break;
		case 'B':
			EnBuyukBanknot(miktar, banknot);
			break;
		case 'K':
			EnKucukBanknot(miktar, banknot);
			break;
		case 'Q':
			exit(1);
		default:
			break;
		}

	}

}