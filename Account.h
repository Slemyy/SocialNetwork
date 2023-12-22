#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Account {
public:
    class Builder;

    Account(std::string name, std::string email, bool gender = true, bool administrator = false);

    void showInformation() const;

    std::string getUsername() const;

private:
    std::string name;
    std::string email;
    bool gender;
    bool administrator;
};

class Account::Builder {
public:
    Builder(std::string name, std::string email);

    Builder& isMale(bool value);

    Builder& setAdministrator(bool value);

    Account create();

private:
    std::string name;
    std::string email;
    bool gender = true;
    bool administrator = false;
};
