#include <iostream>
#include <string>
using namespace std;
int main()
{
	string tekst, tab[26], ciag[100], ciag2[100];
	int tab1[26], zliczanie;
	getline(cin, tekst);
	for (int i = 0; i < 26; i++)
	{
		tab[i] = "";
		tab1[i] = 0;
	}
	for (int i = 0; i < tekst.length(); i++)
	{
		ciag[i] = tekst.at(i);
		ciag2[i] = tekst.at(i);
	}
	int miejsce = 0;
	for (int i = 0; i < tekst.length(); i++)
	{
		zliczanie = 0;
		for (int j = 0; j < tekst.length(); j++)
		{
			if (ciag[i] == ciag2[j])
			{
				ciag2[j] = "";
				zliczanie++;
			}
		}
		if (zliczanie != 0)
		{
			tab[miejsce] = ciag[i];
			tab1[miejsce] = zliczanie; \
				miejsce++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (tab[i] != "")
			cout << tab[i] << " - " << tab1[i] << endl;
	}
}