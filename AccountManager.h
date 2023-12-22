#pragma once

#include "Account.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class AccountManager {
public:
    void addAccount(const Account& account);

    void showAllAccounts();

    void deleteAccount(const std::string& username);

    bool isUsernameExists(const std::string& username) const;

private:
    std::vector<Account> accounts;
};
