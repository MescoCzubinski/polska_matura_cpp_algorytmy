#include <iostream>
#include <cmath>
using namespace std;

void zDziesietnego();
void naDziesietny();
void EuklidesNWD();
void EuklidesNWDZopt();
void NWW();
void rozkladNaCzynnikiPierwsze();
void rozkladNaCyfry();
void liczbaDoskonala();
void czyPierwsza();
void EratostenesSito();
int wypiszLiczbeFibonacci(int n);
void wypiszCiagFibonacciego();
void resztaMetZachlanna();
void resztaMetDynamiczna();

int main()
{
    //zDziesietnego();
    //naDziesietny();
    //EuklidesNWD();
    //EuklidesNWDZopt();
    //NWW();
    //rozkladNaCzynnikiPierwsze();
    //rozkladNaCyfry();
    //liczbaDoskonala();
    //czyPierwsza();
    //EratostenesSito();
    //cout<<wypiszLiczbeFibonacci(7); //rekurencja
    //wypiszCiagFibonacciego();
    //resztaMetZachlanna();
    //resztaMetDynamiczna();
}

void zDziesietnego()
{
    int system;
    cout << "Na jaki system zamienic: ";
    cin >> system;

    int liczba;
    cout << "Podaj liczbe do zamiany: ";
    cin >> liczba;

    int i = 0, poKonwersji = 0;
    do {
        poKonwersji += (liczba % system) * pow(10, i);
        liczba = liczba / system;
        i++;
    } while (liczba != 0);

    cout << "Po konwersji: " << poKonwersji;
}

void naDziesietny()
{
    int system;
    cout << "Z jakiego systemu zamieniac: ";
    cin >> system;

    int liczba;
    cout << "Podaj liczbe do zamiany na dziesietny: ";
    cin >> liczba;

    int dec = 0, rem, i = 0;
    while (liczba != 0)
    {
        rem = liczba % 10;
        liczba /= 10;
        dec += rem * pow(system, i);
        ++i;
    }
    cout << "Po konwersji: " << dec;
}

void EuklidesNWD()
{
    int a, b;
    cout << "Podaj dwie liczby: "<<endl;
    cin >> a;
    cin >> b;

    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    cout << "NWD: " << a;
}

void EuklidesNWDZopt()
{
    int a, b;
    cout << "Podaj dwie liczby: "<<endl;
    cin >> a;
    cin >> b;

    int pom;
    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    cout << "NWD: " << a;
}

void NWW()
{
    int a, b;
    cout << "Podaj dwie liczby: " << endl;
    cin >> a;
    cin >> b;

    int ab = a * b;

    int pom;
    while (b != 0)
    {
        pom = b;
        b = a % b;
        a = pom;
    }

    cout << "NWW: " << ab / a; //ab/NWD(a, b)
}

void rozkladNaCzynnikiPierwsze()
{
    int liczba, i;

    cout << "Podaj liczbe: ";
    cin >> liczba;

    i = 2;
    while (liczba > 1)
    {
        while (liczba % i == 0)
        {
            cout << i << " ";
            liczba = liczba / i;
        }
        i++;
    }
}

void rozkladNaCyfry()
{
    int liczba;
    cout << "Podaj liczbe do rozlozenia na cyfry: ";
    cin >> liczba;

    cout << "Rozklad " << liczba << ": ";
    int cyfra = 0;

    while(liczba > 1)
    {
        cyfra = liczba % 10;
        liczba = (liczba - cyfra) / 10;
        cout << cyfra << " ";
    }
}

void liczbaDoskonala() //suma dzielnikow jest rowna liczbie
{
int liczba;
cout << "Podaj liczbe do sprawdzenia: "; //     > 0
cin >> liczba;

int sumaDzielnikow = 0;
for (int i = 1; i <= (liczba / 2); i++)
    {
    if (liczba % i == 0) //sprawdzanie podzielnosci
        sumaDzielnikow += i;
    }

if (liczba ==  sumaDzielnikow) cout << liczba << " jest doskonala";
else cout << liczba << " nie jest doskonala";
}

void czyPierwsza()
{
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    bool czyPierwsza = true;

    if (liczba < 2) czyPierwsza = false;

    for (int i = 2; i * i <= liczba; i++)
    {
        if (liczba % i == 0)
            czyPierwsza = false;
    }

    if (czyPierwsza) cout << liczba << " jest pierwsza.";
    else cout << liczba << " nie jest pierwsza.";
}

void EratostenesSito()
{
    const int n = 50; //do ktorej liczby bedziemy sprawdzac
    int t[n] = {};

    //0 - pierwsza, 1 - nie pierwsza
    t[1] = 1; t[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
            t[j] = 1;
    }

    for (int i = 0; i < n; i++) if (t[i] == 0) cout << i << " ";
}

int wypiszLiczbeFibonacci(int n)
{
if(n == 0) return 0;
if(n == 1) return 1;
return wypiszLiczbeFibonacci(n-1)+ wypiszLiczbeFibonacci(n-2);
}

void wypiszCiagFibonacciego()
{
    int n;
    cout << "Ile liczb wypisac? ";
    cin >> n;

    long int a = 1, b = 1;
    cout << "Ciag fibonacciego: " << a << " ";
    for (int i = 0; i < n - 1; i++)
    {
        b += a;
        a = b - a;
        cout << a << " ";
    }
}

void resztaMetZachlanna()
{
    int nominaly[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int liczbaNominaly = 0;

    int reszta;
    cout << "Ile reszty wydac: ";
    cin >> reszta;

    for (int i = 0; i < 9; i++)
    {
        while (reszta - nominaly[i] >= 0)
        {
            reszta = reszta - nominaly[i];
            liczbaNominaly++;
        }
        cout << endl << nominaly[i] << " " << liczbaNominaly;
        liczbaNominaly = 0;
    }
}

void resztaMetDynamiczna()
{
    int nominaly[9] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int indexNominaly = 0, liczbaNominaly = 0;

    int reszta;
    cout << "Ile reszty wydac: ";
    cin >> reszta; 


}