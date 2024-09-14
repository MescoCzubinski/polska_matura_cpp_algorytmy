#include <iostream>
#include <cmath>
#include<string>
using namespace std;

void szyfrCezar();
void szyfrPrzestawieniowy();
void szyfrKolumonowy();
void szyfrowaniePlotkowy();

int main()
{
    //szyfrCezar();
    //szyfrPrzestawieniowy();
    //szyfrKolumonowy();
}

void szyfrCezar()
{
    string tekstJawny, szyfrogram;
    cout << "Podaj tekst jawny: ";
    cin >> tekstJawny;
    szyfrogram = tekstJawny;

    int klucz;
    cout << "Podaj klucz: ";
    cin >> klucz;
    klucz = klucz % 26;
    
    //szyfrowanie
    int pomocnicza;
    for (int i = 0; i < tekstJawny.length(); i++)
    {
        pomocnicza = (int)tekstJawny[i] + klucz;
        
        if (pomocnicza > 'Z' && tekstJawny[i] <= 'Z') pomocnicza -= 26;
        if (pomocnicza > 'z') pomocnicza -= 26;

        szyfrogram[i] = (char)pomocnicza;
    }
    cout << szyfrogram <<endl;

    //deszyfrowanie
    for (int i = 0; i < szyfrogram.length(); i++)
    {
        pomocnicza = (int)szyfrogram[i] - klucz;

        if (pomocnicza < 'A' && szyfrogram[i] <= 'Z') pomocnicza += 26;
        else if (pomocnicza < 'a' && szyfrogram[i] >= 'a') pomocnicza += 26;

        tekstJawny[i] = (char)pomocnicza;
    }
    cout << tekstJawny << endl;
}

void szyfrPrzestawieniowy()
{
    string tekstJawny;
    cout << "Podaj tekst jawny: ";
    cin >> tekstJawny;

    int dlugosc = tekstJawny.length();
    char pomocnicza;
    for (int i = 0; i < dlugosc - 1; i += 2)
    {
        pomocnicza = tekstJawny[i];
        tekstJawny[i] = tekstJawny[i + 1];
        tekstJawny[i + 1] = pomocnicza;
    }
    cout << tekstJawny;
}

void szyfrKolumonowy()
{
    string tekstJawny; 
    cout << "Podaj tekst do zaszyfrowania: "; getline(cin, tekstJawny);

    int x;
    cout << "Podaj liczbe kolumn: "; cin >> x;
    int* klucz = new int[x];

    int kolejnosc;
    for (int i = 0; i < x; i++)
    {
        cout << "Ktora tabele zaszyfrowac jako " << i+1 << ".: "; cin >> kolejnosc;
        klucz[i] = kolejnosc;
    }

    int y = ceil(tekstJawny.length() / 3.0);

    char** tabela = new char*[y];
    for (int i = 0; i < y; i++)
        tabela[i] = new char[x];

    int index =0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            tabela[i][j] = '0';
            tabela[i][j] = tekstJawny[index];
            cout << tabela[i][j];
            index++;
        }
        cout << endl;
    }
}


