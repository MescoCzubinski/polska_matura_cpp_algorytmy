#include <iostream>
using namespace std;

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if((a * x) % m == 1)
            return x;
    }
    return -1; //gdy nie odwrotnosc modulo nie istnieje
}

bool ifPrime(int n)
{
    if (n < 2) return false;

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

bool ifRelativelyPrime(int a, int b)
{
    if (a == 0 || b == 0) return false;

    if (a == 1 || b == 1) return true;

    while (b != 0)
    {
        a %= b;
        swap(a, b);
    }
    if(a == 1) return true;

    return false;
}

int long kluczPubliczny;
int long kluczPrywatny;
int long modul;

void generateKeys(long int p, long int q, long int e)
{
    modul = p * q;
    int long phi = (p - 1) * (q - 1);

    if (!ifRelativelyPrime(phi, e))
    {
        cout << "Niepoprawna wartosc e";
    }
    kluczPrywatny = modInverse(e, phi);
    kluczPubliczny = e;

}

int szyfrujRSA(int liczba, int modul)
{
    int wynik = 1;
    liczba = liczba % modul;
    while (kluczPubliczny > 0)
    {
        if (kluczPubliczny % 2 == 1)
            wynik = (wynik * liczba) % modul;
        kluczPubliczny = kluczPubliczny >> 1;
        liczba = (liczba * liczba) % modul;
    }
    return wynik;
}


int main()
{
    long int p = 5, q = 7, e = 3;
    if (!ifPrime(p) || !ifPrime(q))
    {
        cout << "Niepoprawne wartosci p i q";
        return 0;
    }

    long int liczba; cout << "Podaj liczbe do zaszyfrowania: "; cin >> liczba;   
    generateKeys(p, q, e);

    int szyfrogram = szyfrujRSA(liczba, modul);
    cout << szyfrogram;
}
