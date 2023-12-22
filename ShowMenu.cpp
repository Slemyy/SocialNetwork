#include "ShowMenu.h"

using namespace std;

extern string PREFIX;

void showMenu()
{
	cout << "============ " << PREFIX << " ============" << endl;
	cout << "1. Удалить пользователя" << endl;
	cout << "2. Вывести всех пользователей" << endl;
	cout << "3. Очистка консоли" << endl;
	cout << "4. Выход из программы" << endl;
	cout << "=========================================" << endl;
}