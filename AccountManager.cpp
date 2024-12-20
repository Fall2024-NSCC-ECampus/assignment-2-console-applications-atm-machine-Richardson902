//
// Created by nick- on 11/2/2024.
//

#include "AccountManager.h"
#include "Atm.h"
#include <iostream>
#include <limits>

AccountManager::AccountManager(Atm& atm) : atm(atm), currentAccount(nullptr) {} // Initialize currentAccount to nullptr to indicate no account is currently logged in


void AccountManager::login() {
    std::string username, password;
    std::cout << "Please enter your username:";
    std::cin >> username;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Please enter your password:";
    std::cin >> password;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << std::endl;

    try
    {
        for (auto& account : accounts) {
          if(account.getUsername() == username && account.getPassword() == password) {
            std::cout << "Access Granted!" << std::endl;
            currentAccount = &account; // Set current account to the account that was found
            atm.mainMenu();
            return;
        }
      }
    throw std::runtime_error("LOGIN FAILED!");
    }
    catch (const std::runtime_error& e)
    {
        std::cout << "******** " << e.what() << " ********" << std::endl;
        std::cout << std::endl;
    }
}

void AccountManager::logout()
{
    if (currentAccount)
    {
        currentAccount = nullptr;
        std::cout << "You have been logged out." << std::endl;
        std::cout << std::endl;
    } else
    {
        throw std::runtime_error("No account currently logged in.");
    }
}

void AccountManager::createAccount() {
    std::string username, password;
    std::cout << "Please enter your username:";
    std::cin >> username;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "Please enter your password:";
    std::cin >> password;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << std::endl;

    try
    {
        for (auto& account : accounts)
        {
            if (account.getUsername() == username)
            {
                throw std::runtime_error("Username already exists. Please choose a different username.");
            }
        }

        Account newAccount(username, password);
        accounts.push_back(newAccount);
        std::cout << "Thank you! Your account has been created!" << std::endl;
        std::cout << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what()<< std::endl;
        std::cout << std::endl;
    }

}


Account* AccountManager::getCurrentAccount()
{
    return currentAccount;
}
