// SocialNetwork.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include "ShowMenu.h"
#include "Account.h"
#include "AccountManager.h"

using namespace std;

string PREFIX = "TitaniumNetwork";
const char* SYSTEM_CLEAR = "cls";

int main()
{
	system("chcp 1251 > nul");

	// Создаем аккаунты
	Account slemyy = Account::Builder("slemyy", "slemyy@gmail.com").setAdministrator(true).create();
	Account kuzaka20 = Account::Builder("kuzaka20", "kuzaka20@mail.ru").create();
	Account ympa_lumpa = Account::Builder("ympa_lumpa", "katya@vk.com").isMale(false).create();
	Account dister = Account::Builder("dister", "dister@gmail.com").create();
	Account maru = Account::Builder("maru", "maru@ok.ru").isMale(false).setAdministrator(true).create();

	// Добавляем их в базу
	AccountManager accountManager;
	accountManager.addAccount(slemyy);
	accountManager.addAccount(kuzaka20);
	accountManager.addAccount(ympa_lumpa);
	accountManager.addAccount(dister);
	accountManager.addAccount(maru);

    showMenu();

	while (true)
	{
		cout << "\nВыберите необходимое действие (введите соответствующую цифру) >> ";
		try
		{
			string input;
			cin >> input;

			// Переводим input в число.
			int choise = stoi(input);

			switch (choise)
			{

			case 1:
			{
				string username;
				cout << "\n" << "[" << PREFIX << "] Введите ник: ";
				cin >> username;

				if (accountManager.isUsernameExists(username)) {
					accountManager.deleteAccount(username);
					cout << "[" << PREFIX << "] Пользователь успешно удален." << endl;
				}

				else
				{
					cout << "[" << PREFIX << "] Ошибка: Данного пользователя не существует." << endl;
				}

				break;
			}

			case 2:
			{
				cout << endl;
				accountManager.showAllAccounts();
				break;
			}

			case 3:
			{
				system(SYSTEM_CLEAR);
				cout << "[" << PREFIX << "] Консоль успешно очищена.\n" << endl;
				showMenu();
				break;
			}

			case 4:
			{
				system("pause");
				return 0;
			}

			default:
				cerr << "\n[" << PREFIX << "] Некорректный выбор. Попробуйте снова.";
				break;
			}
		}
		catch (const exception& e) { cerr << "\n[" << PREFIX << "] Ошибка: " << e.what(); }
		catch (...) { cerr << "\n[" << PREFIX << "] Ошибка: Неизвестная ошибка :("; }
	}

	return 0;
}