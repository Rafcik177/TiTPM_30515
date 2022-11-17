#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    //sproboj sobie calosc od nowa zrobic
    string tablica[5];
    string wyjscie[10][3];
    /*
    tablica [0] - reszta
    tablica [1] - słownik
    tablica [2] - bufor
    tablica [3] - pozostałe
    tablica [4] - wyjscie
    */
    cout << "LZ77 - algorytm\n";
    string text = "ababcbababaaaaaa";
    int n = 4;
    int m = 4;
    
    int calosc = 0;
    int flaga = 0;
    string slownik = "____";
    string bufor = text.substr(0,4);
    int dlugosc;
    int przesuniecie = 0;
    int index = 0;
    for (int zzz = 0; zzz < 10; zzz++)
    {
        bufor = text.substr(przesuniecie + calosc, 4);
        for (int i = n; i > 0; i = i - 1)
        {
            
            string bufor2 = text.substr(przesuniecie + calosc, i);
            
            size_t found = slownik.find(bufor2);
            if (found != string::npos)
            {
                cout << "index " << found << endl;
                index = found;
                dlugosc = bufor2.length();
                flaga = 1;
                przesuniecie = i+1;
                
                break;
            }
        }
        cout << " Slownik: " << slownik << " Bufor " << bufor  << endl;
        if (flaga == 1)
        {
            wyjscie[zzz][0] = to_string(przesuniecie-1);
            wyjscie[zzz][1] = to_string(dlugosc);
            wyjscie[zzz][2] = bufor.substr(dlugosc, dlugosc + 1);
            slownik = text.substr(calosc+index-2, 4);
            calosc++;
        }
        if (flaga == 0)
        {
            wyjscie[zzz][0] = "0";
            wyjscie[zzz][1] = "0";
            
            slownik[2 +calosc] = text.at(calosc);
            wyjscie[zzz][2] = slownik;
            calosc++;
            
            flaga = 0;
            
        }
        
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << wyjscie[i][0] << " " << wyjscie[i][1] << " " << wyjscie[i][2] << endl;
    }


}