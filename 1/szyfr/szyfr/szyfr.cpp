#include <iostream>
#include <string>

using namespace std;
int main()
{
	int wybor;
	string klucz, tekst, zaszyfrowany, odszyfrowany;
	int klucz_ascii = 0;
	cout << "1. Zaszyfruj tekst";
	cout << "\n2. Odszyfruj tekst\n";
	cin >> wybor;
	if (wybor == 1)
	{
		cout << "Podaj klucz (jeden wyraz bez polskich znakow) szyfrowania: \n";
		cin >> klucz;
		for (int i = 0; i < klucz.length(); i++)
		{
			char x = klucz.at(i);
			klucz_ascii += int(x);
		}
		cout << "\nPodaj tekst do zaszyfrowania\n";
		getline(cin >> ws, tekst);

		for (int i = 0; i < tekst.length(); i++)
		{
			int literaza = klucz_ascii + int(tekst.at(i))+i;
			zaszyfrowany += literaza;
		}
		cout << "Zaszyfrowany tekst: " << zaszyfrowany;

	}
	else if (wybor == 2)
	{
		cout << "Podaj tekst do odszyfrowania\n";
		getline(cin >> ws, zaszyfrowany);
		cout << "Podaj klucz (jeden wyraz bez polskich znakow) odszyfrowania: \n";
		cin >> klucz;
		for (int i = 0; i < klucz.length(); i++)
		{
			char x = klucz.at(i);
			klucz_ascii += int(x);
		}
		for (int i = 0; i < zaszyfrowany.length(); i++)
		{
			int literaza = (int(zaszyfrowany.at(i)) - klucz_ascii)-i;
			odszyfrowany += literaza;
		}
		cout << "Odszyfrowany tekst: " << odszyfrowany;
	}
	return 0;
}