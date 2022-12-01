#pragma once
#include "Common.h"
#include "Uczestnik.h"
#include "Trasa.h"

//pula imion i nazwisk
string tab[2][5] = { {"Jan","Dzban","Adam","Mariusz", "Dariusz"},{"Pancel","Adamowicz","Pawlak","Geleciak","Globus"} };



class Zawody
{
	
	vector<Uczestnik*> _uczestnicy; //lista zawodników
	Trasa *_trasa; //obiekt trasy
	int _iloscKom=0; //ilosc linijek tekstu komentatora

public:

	Zawody(int dlugosc, int ilosc, int trudnosc)
	{
		srand(time(NULL));
		if (ilosc < 1)
			ilosc = 1;
		for (int i = 0; i < ilosc; i++)
		{
			string temp = "";
			temp += tab[0][rand() % 5];
			temp += " ";
			temp += tab[1][rand() % 5];
			_uczestnicy.push_back(new Uczestnik(temp, rand() % 20 + 10, rand() % 100, rand() % 100, rand() % 100));
			gotoxy(1, i*2 + 3);
		}

		gotoxy(2, ilosc + 7);
		_trasa = new Trasa(dlugosc, trudnosc); //generowanie trasy

		//---------------------DEBUG LINE----------------//
		//_uczestnicy[0]->addProgres(36);
		//_uczestnicy[0]->addZal();

	}

	//dodaje komentarz do komentatora
	void dodajKomentarz(string what)
	{
		_iloscKom += 1;
		gotoxy(1, 9+_iloscKom);
		cout << what;
		if (_iloscKom > 25)
			_iloscKom = 0;
	}

	//nastepna runda 
	void NastepnaRunda()
	{

		//tu wstawiæ kod



	}

	//wyswietla wszystkich uczestnikow
	void PokazUczestnikow()
	{
		for (int i = 0; i < _uczestnicy.size(); i++)
		{
			gotoxy((i + 1) * 20, 2);
			cout << _uczestnicy[i]->getName();
			gotoxy((i + 1) * 20, 3);
			cout << "Trasa: ";
			for (int j = 0; j < _trasa->getLen(); j++)
			{
				if (j < _uczestnicy[i]->getZal())
					cout << char(178);
				else
					cout << char(176);
			}

			gotoxy((i + 1) * 20, 4);
			cout << "Element: ";
			for (int j = 0; j < 10; j++)
			{
				if (j < _uczestnicy[i]->getProgr()/_trasa->getEl(_uczestnicy[i]->getZal()).dlugosc)
					cout << char(178);
				else
					cout << char(176);
			}

		}

		gotoxy(1, 8);
		cout << "_____________________________________________________________________________________________";
	}


};