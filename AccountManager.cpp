#include "AccountManager.h"

void AccountManager::addAccount(const Account& account) {
    accounts.push_back(account);
}

void AccountManager::showAllAccounts() {
    for (const auto& account : accounts) {
        account.showInformation();
        std::cout << std::endl;
    }
}

void AccountManager::deleteAccount(const std::string& username) {
    accounts.erase(std::remove_if(accounts.begin(), accounts.end(), [&username](const Account& account) {
        return account.getUsername() == username;
        }), accounts.end());
}

bool AccountManager::isUsernameExists(const std::string& username) const
{
    auto it = std::find_if(accounts.begin(), accounts.end(), [&username](const Account& account) {
        return account.getUsername() == username;
        });

    return it != accounts.end();
}