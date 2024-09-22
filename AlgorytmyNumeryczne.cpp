#include <cmath>
#include <iostream>
using namespace std;

double f(double x)
{
    return 3 * x * x * x - 2 * x * x + x - 5; //3x^3-2x^2+x-5
}

void przyblizonaWartoscPierwiastka();
void potegowanie();
void szybkiePotegowanie();
void najblizszaSredniej();
void najdluzszySpojnyMonotonicznyPodciag();
void najdluzszyNiespojnyMonotonicznyPodciag();
void miejscaZerowe();
void calkowanie();
void schematHornera();

int main()
{
    //przyblizonaWartoscPierwiastka();
    //potegowanie();
    //szybkiePotegowanie();
    //najblizszaSredniej();
    //najdluzszySpojnyMonotonicznyPodciag();
    //najdluzszyNiespojnyMonotonicznyPodciag();
    //miejscaZerowe();
    //calkowanie();
    //schematHornera();
}

void przyblizonaWartoscPierwiastka()
{
    double a, P, e = 0.000001; //e - dokladnosc
    cout << "Podaj wartosc z ktorej mam obliczy pierwiastek: ";
    cin >> P;
    
    a = P;
    while (abs(a - (P / a)) >= e)
    {
        a = (a + (P / a)) / 2.;
    }
    cout << a;
}

void potegowanie()
{
    int n, wykladnik, wynik = 1;
    cout << "Podaj liczbe do spotegowania: ";
    cin >> n;

    cout << "Podaj wykladnik potegi: ";
    cin >> wykladnik;

    cout << pow(n, wykladnik) << " = "; //z funkcjami matematycznymi

    if (wykladnik == 0)
    {
        cout << wynik; //1
        return;
    }

    for (int i = 0; i < wykladnik; i++)
    {
        wynik *= n;
    }
    cout << wynik; //bez tychze funkcji
}

void szybkiePotegowanie()
{
    int n, wykladnik, wynik = 1;
    cout << "Podaj liczbe do spotegowania: ";
    cin >> n;

    cout << "Podaj wykladnik potegi: ";
    cin >> wykladnik;

    cout << pow(n, wykladnik) << " = ";

    while (wykladnik > 0)
    {
        if (wykladnik % 2 == 1) //jesli bit jest = 1
        {
            wynik *= n;
        }
        n *= n;
        wykladnik /= 2; //skrócenie o jeden bit
    }
    cout<<wynik; //z szybkim potegowaniem
}

void najblizszaSredniej()
{
    double a, b, c;
    cout << "Podaj a, b, i c: ";
    cin >> a >> b >> c;

    double srednia = (a + b + c) / 3;

    if (abs(a - srednia) < abs(b - srednia) && abs(a - srednia) < abs(c - srednia)) cout << a;
    else if (abs(b - srednia) < abs(a - srednia) && abs(b - srednia) < abs(c - srednia)) cout << b;
    else cout << c;
}

void najdluzszySpojnyMonotonicznyPodciag()
{
    int tablica[10] = { 2, 3, 1, 4, 6, 7, 8, 2, 3, 9 };

    int najdluzszy = 1;
    int licznik = 1;

    for (int i = 1; i < 10; i++)
    {
        if (tablica[i - 1] < tablica[i]) // < rosnacy, > malejacy
        {
            licznik++;
        }
        else
        {
            if (licznik > najdluzszy) najdluzszy = licznik;
            licznik = 1;
        }
    }
    cout << najdluzszy;
}

void  najdluzszyNiespojnyMonotonicznyPodciag()
{
    int tablica[10] = {1, 2, 2, 4, 0, 4, 0, 0, 5, 6 };

    int najdluzszy = 0;
    int licznik = 1;

    for (int i = 0; i < 10; i++)
    {
        int kandydat = i;
        for (int j = i+1; j < 10; j++)
        {
            if (tablica[kandydat] < tablica[j]) // < rosnacy, > malejacy
            {
                licznik++;
                kandydat = j;
            } 
        }
        if (licznik > najdluzszy) najdluzszy = licznik;
        licznik = 1;
    }
    cout<< najdluzszy;
}

void miejscaZerowe()
{
    double prawy, lewy, srodek, e=0.0001; //e - dokladnosc
    cout << "Podaj lewe i prawe ograniczenie: ";
    cin >> lewy >> prawy; //lewy < prawy
    
    if (f(lewy) == 0.0) cout << lewy;
    if (f(prawy) == 0.0) cout << prawy;

    while(prawy - lewy >= e)
    {
        srodek = (prawy + lewy) / 2;

        if (f(srodek) == 0) break;

        if (f(lewy) * f(srodek) < 0.0)
            prawy = srodek;
        else
            lewy = srodek;
    }
    cout << srodek;
}

void calkowanie()
{
    double p, q, n;
    cout << "Podaj lewe i prawe ograniczenie wykresu: ";
    cin >> p >> q;
    cout << "Na ile przedzialow mam go podzielic: ";
    cin >> n;

    double d = fabs(q - p) / n;
    double calkaMetProstokatow = 0.0;
    double calkaMetTrapezow = 0.0;

    for (int i = 0; i < n; i++)
    {
        calkaMetProstokatow += d * f(p + i * d);

        calkaMetTrapezow += d/2.0 * (f(p + i * d) + f(p + (i + 1) * d));
    }

    cout << calkaMetProstokatow<<endl;
    cout << calkaMetTrapezow << endl;
}

void schematHornera()
{
    int stopien = 3; //najwysz potega;
    int wspolczynniki[4] = { 3, -2, 1, -5 }; //czyli to co stoi przed x-em, stopinew tym przypadku: 3x^3 -2x^2 +x -5
    int argument, wynik = wspolczynniki[0];
    cout << "Podaj argument dla ktorego bedziemy liczyli wartosc: ";
    cin >> argument;

    for (int i = 1; i < stopien; i++)
    {
        wynik = wynik * argument + wspolczynniki[i];
    }
    cout << "W(" << argument << ") = " << wynik;
}