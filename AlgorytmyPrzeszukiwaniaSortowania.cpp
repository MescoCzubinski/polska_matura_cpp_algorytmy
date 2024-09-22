#include <iostream>
using namespace std;

const int n = 10;
int tablicaPosortowana[n] = { -18, -7, 1, 9, 36, 43, 53, 72, 78, 91 };
int tablicaNieposortowana[n] = { 78, 43, 53, 1, 36, -7, 91, -18, 9, 72 };
int tablicaLider[n] = { 2, 1, 1, 1, 1, 3, 2, 1, 1, 2 };

void wypisz(int* tablica, int dlugosc)
{
    for (int i = 0; i < dlugosc; i++)
    {
        cout << tablica[i] << " ";
    }
}
void scal(int tablica[], int lewy, int srodek, int prawy)
{
    int i = lewy, j = srodek + 1, k = lewy;

    int tablicaPomocnicza[n];

    while (i <= srodek && j <= prawy)
    {
        if (tablica[i] <= tablica[j])
        {
            tablicaPomocnicza[k] = tablica[i];
            i++;
        }
        else
        {
            tablicaPomocnicza[k] = tablica[j];
            j++;
        }
        k++;
    }
    while (i <= srodek)
    {
        tablicaPomocnicza[k] = tablica[i];
        i++;
        k++;
    }
    while (j <= prawy)
    {
        tablicaPomocnicza[k] = tablica[j];
        j++;
        k++;
    }
    for (int i = lewy; i <= prawy; i++)
    {
        tablica[i] = tablicaPomocnicza[i];
    }
}

void wyszukiwanieLiniowe(int* tablica, int dlugosc);
void wyszukiwanieBinarne(int* tablica, int dlugosc);
void wyszukiwanieMinMax(int* tablica, int dlugosc);
void wyszukiwanieLider(int* tablica, int dlugosc);
void sortowanieBabelkowe(int* tablica, int dlugosc);
void sortowanieSelekcja(int* tablica, int dlugosc);
void sortowanieWstawianie(int* tablica, int dlugosc);
void sortowanieScalanie(int* tablica, int lewy, int prawy);
void sortowanieSzybkie(int* tablica, int lewy, int prawy);

int main()
{
    //wypisz(tablicaNieposortowana, n);
    //cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    //wyszukiwanieLiniowe(tablicaNieposortowana, n);
    //wyszukiwanieBinarne(tablicaPosortowana, n);
    //wyszukiwanieMinMax(tablicaNieposortowana, n);
     wyszukiwanieLider(tablicaLider, n);
    //sortowanieBabelkowe(tablicaNieposortowana, n);
    //sortowanieSelekcja(tablicaNieposortowana, n);
    //sortowanieWstawianie(tablicaNieposortowana, n);
    /*sortowanieScalanie(tablicaNieposortowana, 0, n - 1);
        wypisz(tablicaNieposortowana, n);*/ //funkcja rekurencyjna, nie ma jak inaczej wypisac
    /*sortowanieSzybkie(tablicaNieposortowana, 0, n - 1);
        wypisz(tablicaNieposortowana, n); //funkcja rekurencyjna, nie ma jak inaczej wypisac*/
}

void wyszukiwanieLiniowe(int* tablica, int dlugosc)
{
    int szukana;
    cout << "Podaj szukana: ";
    cin >> szukana;

    for (int i = 0; i < dlugosc; i++)
    {
        if (szukana == tablica[i]) cout << "Znalazlem na " << i+1 << "-tej pozycji";
    }
}

void wyszukiwanieBinarne(int* tablica, int dlugosc)
{
    int szukana;
    cout << "Podaj szukana: ";
    cin >> szukana;

    int lewy = 0;
    int prawy = dlugosc;
    int srodek;

    while (true)
    {
        srodek = (lewy + prawy) / 2;

        if (tablica[srodek] == szukana)
        { 
            cout << "Znalazlem na " << srodek + 1 << "-tej pozycji";
            break; 
        }
        else if (tablica[srodek] > szukana) prawy = srodek + 1;
        else if (tablica[srodek] < szukana) lewy = srodek - 1;
    }
}

void wyszukiwanieMinMax(int* tablica, int dlugosc)
{
    int min = 100, max = 0;


    for (int i = 0; i < dlugosc - 1; i += 2)
    {
        if (tablica[i] > tablica[i + 1])
        {
            if (tablica[i] > max)
                max = tablica[i];
            if (tablica[i + 1] < min)
                min = tablica[i+1];
        }
        else
        {
            if (tablica[i+1] > max)
                max = tablica[i+1];
            if (tablica[i] < min)
                min = tablica[i];
        }
    }

    if (dlugosc % 2 == 1) //jesli liczba elementów jest nieparzysta
    {
        if (tablica[dlugosc - 1] > max) 
            max = tablica[dlugosc - 1];
        if (tablica[dlugosc - 1] < min) 
            min = tablica[dlugosc - 1];
    }
    cout << "Max: "<< max << ", min: " << min;
}

void wyszukiwanieLider(int* tablica, int dlugosc)
{
    int lider = tablica[0], doPary = 1;

    for (int i = 1; i < dlugosc; i++)
    {
        if (doPary > 0)
        {
            if (tablica[i] == lider)
                ++doPary;
            else
                --doPary;
        }
        else
        {
            lider = tablica[i];
            ++doPary;
        }
    }

    if (doPary <= 0)
    {
        cout << "Brak lidera";
        return;
    }

    int ile = 0;
    for (int i = 0; i < dlugosc; i++)
    {
        if (tablica[i] == lider)
            ++ile;
    }

    if (ile > dlugosc / 2) cout <<"Lider: " << lider;
    else cout << "Brak lidera";
}

void sortowanieBabelkowe(int* tablica, int dlugosc)
{
    int pomocnicza;
    for (int i = 0; i < dlugosc; i++)
    {
        for (int j = 1; j < dlugosc - i; j++)
        {
            if (tablica[j - 1] > tablica[j]) // > rosnaco; < malejaco
            {
                //swap(tablica[j - 1], tablica[j]);
                
                pomocnicza = tablica[j];
                tablica[j] = tablica[j - 1];
                tablica[j - 1] = pomocnicza;
            }
        }
    }
    wypisz(tablica, dlugosc);
}

void sortowanieSelekcja(int* tablica, int dlugosc)
{
    int index;
    int pomocnicza;

    for (int i = 0; i < dlugosc; i++)
    {
        for (int j = 0; j < dlugosc; j++)
        {
            index = i;
            if (tablica[j] > tablica[index])// > rosnaco; < malejaco
            {
                index = j;
            }
            //swap(tablica[i], tablica[index]);

            pomocnicza = tablica[i];
            tablica[i] = tablica[index];
            tablica[index] = pomocnicza;
        }
    }
    wypisz(tablica, dlugosc);
}

void sortowanieWstawianie(int* tablica, int dlugosc)
{
    int pomocnicza, j;

    for (int i = 1; i < dlugosc; i++)
    {
        pomocnicza = tablica[i];
        j = i - 1;

        while (j >= 0 && tablica[j] > pomocnicza) // tablica[j] [ZNAK] pomocnicza > rosnaco; < malejaco
        {
            tablica[j + 1] = tablica[j];
            j--;
        }
        tablica[j + 1] = pomocnicza;
    }

    wypisz(tablica, dlugosc);
}

void sortowanieScalanie(int* tablica, int lewy, int prawy)
{
    if (lewy < prawy)
    {
        int srodek = (prawy + lewy) / 2;

        sortowanieScalanie(tablica, lewy, srodek);
        sortowanieScalanie(tablica, srodek + 1, prawy);

        scal(tablica, lewy, srodek, prawy);
    }
}

void sortowanieSzybkie(int* tablica, int lewy, int prawy)
{
    if (prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1,
        pivot = tablica[(lewy + prawy) / 2];

    while (1)
    {
        while (pivot > tablica[++i]);

        while (pivot < tablica[--j]);

        if (i <= j)
            swap(tablica[i], tablica[j]);
        else
            break;
    }

    if (j > lewy)
        sortowanieSzybkie(tablica, lewy, j);
    if (i < prawy)
        sortowanieSzybkie(tablica, i, prawy);
}