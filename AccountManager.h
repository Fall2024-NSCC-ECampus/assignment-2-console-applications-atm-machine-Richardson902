//
// Created by nick- on 11/2/2024.
//

#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <vector>
#include "Account.h"

class Atm; // Forward declaration

class AccountManager {

  private:
    std::vector<Account> accounts;
    Atm& atm; // Reference to Atm object - Dependency Injection
    Account* currentAccount; // Pointer to current account

  public:
    AccountManager(Atm& atm);
    void login();
    void logout();
    void createAccount();
    Account* getCurrentAccount(); // Return pointer to current account
};

#endif //ACCOUNTMANAGER_H
