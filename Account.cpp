#include "Account.h"

Account::Account(std::string name, std::string email, bool gender, bool administrator)
    : name(name), email(email), gender(gender), administrator(administrator) {}

void Account::showInformation() const {
    std::cout << "Username: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Gender: " << (gender ? "Male" : "Famele") << std::endl;
    std::cout << "Administrator: " << (administrator ? "Yes" : "No") << std::endl;
}

std::string Account::getUsername() const {
    return this->name;
}

Account::Builder::Builder(std::string name, std::string email) : name(name), email(email) {}

Account::Builder& Account::Builder::isMale(bool value) {
    gender = value;
    return *this;
}

Account::Builder& Account::Builder::setAdministrator(bool value) {
    administrator = value;
    return *this;
}

Account Account::Builder::create() {
    return Account(name, email, gender, administrator);
}
