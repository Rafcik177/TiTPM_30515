#include <iostream>
#include <string>
using namespace std;

int main()
{
	string tekst;
	int tab[26][3], zliczanie, kopia[100], kopia2[100], kod[26];
	getline(cin, tekst);
	for (int i = 0; i < 26; i++)
	{
		tab[i][0] = 0;
		tab[i][1] = 0;
		tab[i][2] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		kopia[i] = 0;
		kopia2[i] = 0;

	}
	for (int i = 0; i < tekst.length(); i++)
	{
		kopia[i] = (int)tekst.at(i);
		kopia2[i] = (int)tekst.at(i);

	}
	int miejsce = 0;
	for (int i = 0; i < tekst.length(); i++)
	{
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
	for (int i = 0; i < 26; i++)
	{
		if (tab[i][1] != 0)
			cout << tab[i][0] << " - " << tab[i][1] << endl;
	}
	cout <<"Posortowane od największej liczby wystąpień"<< endl;
	for (int i = 0; i < 25; i++)
	{
		for (int j = i+1; j < 26; j++)
		{
			if (tab[i][1] < tab[j][1])
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
	for (int i = 0; i < 26; i++)
		if (tab[i][1] != 0)
		cout << (char)tab[i][0] << " - " << tab[i][1] << endl;
	//mniej wiecej równy podział
	int lewo = 0, prawo = 0, podzial = 0, rozmiar=0,suma=0;
	for (int i = 0; i < 26; i++)
		if (tab[i][1] != 0)
		{
			suma += tab[i][1];
			rozmiar++;
		}
	int i = 0;
	int cc = 0;
	while (i<rozmiar)
	{
		if (lewo <= prawo)
		{
			lewo += tab[cc][1];
			cc++;
		}
		else prawo += tab[rozmiar-i][1];
		i++;
	}
	for (int j = 0; j < cc; j++)
	{
		tab[j][2] += 0;
	}
	for (int j = cc; j < rozmiar - 1; j++)
	{
		
		tab[j][2] += 1;
	}
	cout << lewo << " - " << prawo << endl;
	for (int z = 0; z < cc; z++)
	{
		tab[z][2] = 0;
		cout << tab[z][1] << " ";
	}
	
	for (int z = cc; z < rozmiar; z++)
	{
		tab[z][2] = 1;
		cout << tab[z][1] << " ";
	}
	cout << endl;
	// testu na tym: abcafdadcecedabadbbeffbbfaeaeeebddddebdd
		for (int i = 0; i < 26; i++)
			if (tab[i][1] != 0)
				cout << (char)tab[i][0] << " - " << tab[i][1]<<" - "<<tab[i][2] << endl;
}
