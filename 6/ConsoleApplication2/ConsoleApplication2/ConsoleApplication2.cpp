#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	cout << "LZ77 - algorytm kodowania\n";
	string tablica[5], wyjscie[10][3], text = "ababcbababaaaaaa";;
	int n = 4, m = 4;
	string slownik = "____"; //WSTĘPNY SŁOWNIK
	string bufor = text.substr(0, 4); //PIERWSZY BUFOR
	int przesuniecie = 0, calosc = 0;
	int dlugosc = 0, index = 0, zzz = 0;
	while (calosc <= text.length())
	{
		cout << " Slownik: " << slownik << " Bufor " << bufor << endl;
		przesuniecie = 0;
		int flaga = 0;
		for (int i = n; i > 0; i = i - 1)
		{
			/*
			WYSZUKIWANIE DOPASOWANIE BUFORA W SŁOWNIKU
			JEŻELI ZOSTANIE ZNALEZIONE, TO ZAPISUJE DŁUGOŚĆ I INDEX
			ORAZ ZOSTAJE PODNIESIONA FLAGA, ŻE ZNALEZIONO
			DALSZE WYSZUKIWANIE ZOSTAJE PRZERWANE BREAK I PĘTLA JEST ZAKOŃCZONA
			*/
			string bufor2 = bufor.substr(0, i);
			int found = slownik.find(bufor2);
			if (found != string::npos)
			{
				index = found;
				dlugosc = bufor2.length();
				flaga = 1;
				break;
			}
		}
		/*
		JEŻELI ZNALEZIONO DOPASOWANIE TO: 
		NA WYJŚCIE i PRZYPISZ INDEX
				   j przypisz dlugosc znalezionego ciagu
				   k przypisz cyfre za znalezionym ciagiem ze slownika

		*/
		if (flaga == 1)
		{
			wyjscie[zzz][0] = to_string(index);
			wyjscie[zzz][1] = to_string(dlugosc);
			wyjscie[zzz][2] = bufor[dlugosc];
			string stary_slownik = slownik + text.substr(calosc, text.length());
			przesuniecie = przesuniecie + dlugosc;
			calosc = calosc + przesuniecie + 1;
			for (int y = 0; y < n; y++)
				slownik[y] = stary_slownik[y + przesuniecie + 1];
			//JEŻELI SUMA WSZYSTKICH PRZESUNIĘĆ JEST WIĘKSZA OD DŁUGOŚCI
			//WPROWADZANEGO TEKSTU WÓWCZAS PROGRAM ZOSTAJE PRZERWANY
			if (calosc < text.length())
				bufor = text.substr(calosc, 4);
		}
		/*
		JEŻELI NIE ZNALEZIONO DOPASOWANIE TO:
		NA WYJŚCIE i PRZYPISZ 0
				   j przypisz 0
				   k przypisz pierwszą litere z buforu

		*/
		if (flaga == 0)
		{
			wyjscie[zzz][0] = "0";
			wyjscie[zzz][1] = "0";
			wyjscie[zzz][2] = bufor[0];
			string stary_slownik = slownik + text.substr(calosc, text.length());
			przesuniecie++;
			calosc = calosc + przesuniecie;
			for (int y = 0; y < n; y++)
				slownik[y] = stary_slownik[y + 1];
			//JEŻELI SUMA WSZYSTKICH PRZESUNIĘĆ JEST WIĘKSZA OD DŁUGOŚCI
			//WPROWADZANEGO TEKSTU WÓWCZAS PROGRAM ZOSTAJE PRZERWANY
			if (calosc < text.length())
				bufor = text.substr(calosc, 4);
		}
		zzz++;
	}
	//WYDRUK GOTOWEGO WYJSCIA
	for (int i = 0; i < 10; i++)
	{
		cout << wyjscie[i][0] << " " << wyjscie[i][1] << " " << wyjscie[i][2] << endl;
	}


	cout << "LZ77 - algorytm dekodowania\n";
	string tekst = "";
	string wejscie[10][3];
	//NAZWA PLIKU W KTÓRYM ZNAJDUJĄ SIĘ DANE
	ifstream plik("dane.txt");
	string linia;
	int aaa = 0;
	int i = 0, j = 0;
	string a, b, c;
	string k = "";
	slownik = "";
	while (getline(plik, linia)) \
	{
		a = linia[0];
		b = linia[2];
		k = linia[4];
		i = stoi(a); //INDEX 
		j = stoi(b); //DLUGOSC CIAGU
		slownik = linia.substr(6, 4);

		string wycinamy = slownik.substr(i, j);
		tekst = tekst + wycinamy + k;
		cout << i << " " << j << " " << k << " " << slownik << endl;
		aaa++;
	}
	cout << "Tekst: " << tekst << endl;
	plik.close();



}