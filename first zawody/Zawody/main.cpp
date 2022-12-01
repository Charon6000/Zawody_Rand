#include "zawody.h"
#include "Element.h"
#include "Uczestnik.h"
#include "Common.h"
#include "Trasa.h"


int main()
{
	Zawody game(5, 3, 1.0);
	gotoxy(32, 25);
	cout << "Kliknij cokolwiek, aby przejsc dalej . . . ";
	_getch();
	system("CLS");
	gotoxy(1, 1);
	while (true)
	{
		game.PokazUczestnikow();
		_getch();
	}
}