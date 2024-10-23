#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Account.h"

//TODO: *********** FOR PART B ***********
//TODO: Implement balance modification functions
//TODO: Encapsulate account management using AccountManager class to handle logging in and creating accounts
//TODO: Move the menu display logic to a separate ATM class to clean up the main function
//TODO: Implement exception handling and validation for future and current implementations

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

char menuInput;
std::vector<Account> accounts;

int main()
{
    std::cout << "Hi! Welcome to Nick's ATM Machine!" << std::endl;
    start();
    return 0;
}

void printIntroMenu()
{
    std::cout << "l -> Login" << std::endl;
    std::cout << "c -> Create New Account" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << ">";
}

void printMainMenu()
{
    std::cout << "d -> Deposit Money" << std::endl;
    std::cout << "w -> Withdraw Money" << std::endl;
    std::cout << "r -> Request Balance" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << ">";
}

void start()
{
    std::cout << "Please select an option from the menu below:" << std::endl;
    printIntroMenu();
    std::cin >> menuInput;

    switch (menuInput)
    {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            std::cout << "Quitting the application..." << std::endl;
            exit(0);
        default:
            std::cout << "Invalid input. Please try again." << std::endl;
    }
}

void login()
{
    std::string username, password;
    std::cout << "Please enter your username:";
    std::cin >> username;
    std::cout << "Please enter your password:";
    std::cin >> password;
    std::cout << std::endl;

    for (auto& account : accounts)
    {
        if(account.getUsername() == username && account.getPassword() == password)
        {
            std::cout << "Access Granted!" << std::endl;
            printMainMenu();
            return;
        }
    }
    std::cout << "******** LOGIN FAILED! ********" << std::endl;
    std::cout << std::endl;
    start();
}

void createAccount()
{
    std::string username, password;
    std::cout << "Please enter your username:";
    std::cin >> username;
    std::cout << "Please enter your password:";
    std::cin >> password;
    std::cout << std::endl;

    for (auto& account : accounts)
    {
        if (account.getUsername() == username)
        {
            std::cout << "Username already exists. Please choose a different username." << std::endl;
            start();
            return;
        }
    }

    Account newAccount(username, password);
    accounts.push_back(newAccount);
    std::cout << "Thank you! Your account has been created!" << std::endl;
    std::cout << std::endl;
    start();
}




