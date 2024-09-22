#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void szukanieWzorca();
void palindromy();
void literyWielkieMale();
void sortowanieAlfabetyczne();
void anagramy();
void najdluzszyPodciag();
void algorithm();

int main()
{
	//szukanieWzorca();
	//palindromy();
	//literyWielkieMale();
	//sortowanieAlfabetyczne();
	//anagramy();
	//najdluzszyPodciag();
	algorithm();
}

void szukanieWzorca()
{
	string tekst, wzorzec;
	cout << "Podaj tekst: ";
	cin >> tekst;
	cout << "Podaj wzorzec: ";
	cin >> wzorzec;

	int dlugoscTekst = tekst.length();
	int dlugoscWzorzec = wzorzec.length();


	for (int i = 0; i < dlugoscTekst - dlugoscWzorzec + 1; i++)
	{
		int licznik = 0;
		for (int j = 0; j < dlugoscWzorzec; j++)
		{
			if (tekst[i + j] == wzorzec[j])
				licznik++;

			else licznik = 0;
		}
		if (licznik == dlugoscWzorzec)
			cout << "Od " << i + 1 << " pozycji";
	}
}

void palindromy()
{
	string wyraz;
	cout << "Podaj wyraz: ";
	cin >> wyraz;

	int dlugosc = wyraz.length();
	bool palindrom = true;
	
	for (int i = 0; i < dlugosc/2; i++)
	{
		if (wyraz[i] != wyraz[dlugosc - 1 - i])
			palindrom = false;
	}

	if (palindrom) cout << "Jest palindromem";
	else cout << "Nie jest palindromem";
}

void literyWielkieMale()
{
	char litera;
	cout << "Podaj litere: ";
	cin >> litera;

	if (toupper(litera) == litera) cout << "Duza litera";
	else cout << "Mala litera";
}

void sortowanieAlfabetyczne()
{
	string wyraz;
	cin >> wyraz;
	int d = wyraz.length();
	
	for (int i = 0; i < d; i++)
	{
		for (int j = 1; j < d - i - 1; j++)
		{
			if (wyraz[j-1] > wyraz[j])
				swap(wyraz[j-1], wyraz[j]);
		}
	}
	cout << wyraz;
}

void anagramy()
{
	string wyraz1, wyraz2;
	cout << "Podaj wyrazy do sprawdzenia: ";
	cin >> wyraz1 >> wyraz2;

	int dlugosc1 = wyraz1.length();
	int dlugosc2 = wyraz2.length();
	int ascii[127] = {};
	bool czyAnagram = true;

	if (dlugosc1 == dlugosc2)
	{
		for (int i = 0; i < dlugosc1; i++)
		{
			ascii[wyraz1[i]]++;
			ascii[wyraz2[i]]--;
		}
		for (int i = 0; i < 127; i++)
		{
			if (ascii[i] != 0) czyAnagram = false;
		}
		if (czyAnagram) cout << "Sa anagramami";
		else cout << "Nie sa anagramami";
	}
	else
	{
		cout << "Wyrazy nie sa rowne";
	}
 }

void najdluzszyPodciag()
{
	string wyraz1, wyraz2;
	cin >> wyraz1 >> wyraz2;
	int dlugosc1 = wyraz1.length();
	int dlugosc2 = wyraz2.length();

	int  globalMax = 0;

	for (int i = 0; i < dlugosc1; i++) //dlugosc1 > dlugosc2
	{
		for(int j=0; j<dlugosc2; j++)
		{ 
			int max = 0;

			int pom1 = i, pom2 = j;

			while (pom1 < dlugosc1 && pom2 < dlugosc2 && wyraz1[pom1] == wyraz2[pom2])
			{
				max++;
				pom1++;
				pom2++;
			}
			if (max > globalMax) globalMax = max;
		}
	}
	cout << globalMax;
}

void algorithm()
{
	string wyraz = "alamakota";

	sort(wyraz.begin(), wyraz.end());
	cout << wyraz;

	reverse(wyraz.begin(), wyraz.end());
	cout << wyraz;

	int a = wyraz.find('a'); //int
	cout << a+1; //tablica od 0

	
}
