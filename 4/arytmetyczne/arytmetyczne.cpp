#include <iostream>
#include <string>
using namespace std;

int zliczanie, kopia[100], kopia2[100];
double tab[26][4], suma = 0;

int main()
{
	//W CELU NAPISANIA PROGRAMU WSZYSTKO BYŁO ROBIONE
	//NA PODANYM PRZYKŁADZIE PODANYMM W PDF,
	//ZAWSZE MOŻNA WPROWADZAĆ SWOJE WARTOŚCI
	string tekst = "ABRAADABRA";

	//getline(cin, tekst);
	//ZEROWANIE TABLIC
	for (int i = 0; i < 26; i++)
	{
		tab[i][0] = 0;
		tab[i][1] = 0;
		tab[i][2] = 0;
		tab[i][3] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		kopia[i] = 0;
		kopia2[i] = 0;
	}
	//PRZYPISANIE TABLICOM POMOCNICZYM KOLEJNYCH LITER WPROWADZONEGO CIĄGU
	for (int i = 0; i < tekst.length(); i++)
	{
		kopia[i] = (int)tekst.at(i);
		kopia2[i] = (int)tekst.at(i);

	}
	//ZLICZANIE ILOŚCI WYSTĄPIEŃ POSZCZEGÓLNYCH LITER
	int miejsce = 0;
	for (int i = 0; i < tekst.length(); i++)
	{
		suma++;
		zliczanie = 0;
		for (int j = 0; j < tekst.length(); j++)
		{
			if (kopia[i] == kopia2[j])
			{
				kopia2[j] = 0;
				zliczanie++;
			}
		}
		if (zliczanie != 0)
		{
			tab[miejsce][0] = kopia[i];
			tab[miejsce][1] = zliczanie;
			miejsce++;
		}
	}
	//WYPISANIE LICZBY POSZCZEGÓLNYCH LITER
	for (int i = 0; i < 26; i++)
	{
		if (tab[i][1] != 0)
			cout << (char)tab[i][0] << " - " << tab[i][1] << endl;
	}

	cout << "Posortowane alfabetycznie" << endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = i + 1; j < 26; j++)
		{
			if (tab[i][0] > tab[j][0])
			{
				int temp = tab[i][0];
				int temp1 = tab[i][1];

				tab[i][1] = tab[j][1];
				tab[i][0] = tab[j][0];
				tab[j][0] = temp;
				tab[j][1] = temp1;

			}
		}

	}
	//WARTOSCI DLA PRZEDZIAŁU 0-1
	cout << "(0;1)" << endl;
	for (int i = 1; i < 26; i++)
	{
		if (tab[i][1] != 0)
		{
			tab[i][2] = tab[i - 1][3];
			tab[i][3] = 1 / suma * tab[i][1] + tab[i - 1][3];
		}


	}
	//WYPISANIE WARTOSCI DLA PRZEDZIAŁU 0-1
	for (int i = 0; i < 26; i++)
		if (tab[i][1] != 0)
			cout << (char)tab[i][0] << " - " << tab[i][1] << " - " << tab[i][2] << " - " << tab[i][3] << endl;
	cout << endl;
	
	for (int i = 0; i < tekst.length(); i++)
	{
		//POBIERANIE KAŻDEJ KOLEJNEJ LITERY CIĄGU
		int litera = (int)tekst.at(i);
		cout << (char)litera << " ";
		for (int j = 0; j < 26; j++)
		{

			if (litera == tab[j][0])
			{
				//WYPISANIE ZAKRESU DLA CAŁOŚCI
				cout << "(" << tab[j][2] << "; " << tab[j][3] << ")" << endl;
				double zakres = tab[j][3] - tab[j][2]; //DOSTEPNA PRZESTRZEŃ

				double wartosc = zakres / suma;
				for (int z = 0; z < 26; z++)
				{
					tab[z][3] = tab[j][2];
				}
				for (int z = 1; z < 26; z++)
				{
					if (tab[z][0] != 0)
					{
						tab[z][2] = tab[z - 1][3];
						tab[z][3] = (wartosc * tab[z][1]) + tab[z][2];
					}

				}

			}
		}
		//WYPISANIE PRZEDZIAŁÓW DLA POSZCZEGÓLNYCH LITER
		for (int i = 0; i < 26; i++)
			if (tab[i][1] != 0)
				cout << (char)tab[i][0] << " - " << tab[i][1] << " - " << tab[i][2] << " - " << tab[i][3] << endl;
		cout << endl;
	}


	// testu na tym: ABRAADABRA

	/*
	MUSIAŁEM SOBIE TO ROZPISAĆ
	Policz ile jest poszczegolnych liter
	A - 5
	B - 2
	D - 1
	R - 2
	Suma = 10
	Określ przedziały - w tabeli przechowuj dolny i górny zakeres
	A - 5/10 - 0 - 0.5
	B - 2/10 - 0.5 - 0.7
	D - 1/10 - 0.7 - 0.8
	R - 2/10 - 0.8 - 1

	A - 0.5
	B - 0.2
	D - 0.1
	R - 0.2
	Weź pierwszą litere ciagu - A. Od górnego przedziału, odejmij dolny i podziel to co uzyskałeś, na wszystkie litery.
	Przedział od 0 do 0.5
	0.5/10 = 0.05
	Masz 5 liter A wiec 5*0.05
	A - 0.25
	B - 0.1
	D - 0.05
	R - 0.1

	A - 5 - 0 - 0.25
	B - 2 - 0.25 - 0.35
	D - 1 - 0.35 - 0.4
	R - 2 - 0.4 - 0.5
	Weź drugą litere ciagu - B. Jej dolny przedział po pierwszym kroku to 0,25 a górny to 0,35 czyli 0.1.
	Tą wartość podziel na wszystkie liczby i dodaj do nich dolny przedział 0.25
	0.1/10=0.01
	5*0.01+0.25;
	A - 5 - 0.25 - 0.3
	B - 2 - 0.3 - 0.32
	D - 1 - 0.32 - 0.33
	R - 2 - 0.33 - 0.35

	i tak dalej i tak dalej
	*/
}
