//
// Created by nick- on 11/2/2024.
//

#include "Atm.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits>

Atm::Atm() : accountManager(*this) {} // Pass reference to this object to AccountManager

void Atm::printIntroMenu() {
    std::cout << "l -> Login" << std::endl;
    std::cout << "x -> logout" << std::endl;
    std::cout << "c -> Create New Account" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << ">";
}

void Atm::printMainMenu() {
    std::cout << "d -> Deposit Money" << std::endl;
    std::cout << "w -> Withdraw Money" << std::endl;
    std::cout << "r -> Request Balance" << std::endl;
    std::cout << "b -> Back to Intro Menu" << std::endl;
    std::cout << "q -> Quit" << std::endl;
    std::cout << ">";
}

void Atm::start() {
    while (true)
    {
        std::cout << "Please select an option from the menu below:" << std::endl;
        printIntroMenu();
        std::cin >> menuInput;
        menuInput = tolower(menuInput);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // clears the input buffer to prevent multiple inputs

        try
        {
            switch (menuInput)
            {
                case 'l':
                    accountManager.login();
                    break;
                case 'x':
                    accountManager.logout();
                    break;
                case 'c':
                    accountManager.createAccount();
                    break;
                case 'q':
                    std::cout << "Quitting the application..." << std::endl;
                    exit(0);
                default:
                    std::cout << "Invalid input. Please try again." << std::endl;
                    std::cout << std::endl;
            }
        } catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void Atm::mainMenu()
{
    while (true)
    {
        printMainMenu();
        std::cin >> menuInput;
        menuInput = tolower(menuInput);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        try
        {
            switch (menuInput)
            {
            case 'd':
                updateBalance(getValidInput("How much would you like to deposit?"), true);
                break;
            case 'w':
                updateBalance(getValidInput("How much would you like to withdraw?"), false);
                break;
            case 'r':
                requestBalance();
                break;
            case 'b':
                std::cout << std::endl;
                start();
                break;
            case 'q':
                std::cout << "Quitting the application..." << std::endl;
                exit(0);
            default:
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cout << std::endl;
            }
        } catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

void Atm::requestBalance()
{
    if (Account* account = accountManager.getCurrentAccount())
    {
        std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
        std::cout << "Your balance is: " << account->getBalance() << std::endl;
        std::cout << std::endl;
    } else
    {
        throw std::runtime_error("Error: No account currently logged in.");
    }
}

void Atm::updateBalance(float amount, bool isDeposit)
{
    if (Account* account = accountManager.getCurrentAccount())
    {
        double newBalance = isDeposit ? account->getBalance() + amount : account->getBalance() - amount;
        if (!isDeposit && !sufficientFunds(amount))
        {
            throw std::runtime_error("Insufficient funds.");
        }
        account->setBalance(newBalance);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << (isDeposit ? "Deposit" : "Withdrawal") << " successful! Your new balance is: " << newBalance << std::endl;
        std::cout << std::endl;
    } else
    {
        throw std::runtime_error("No account currently logged in.");
    }
}

float Atm::getValidInput(const std::string& prompt)
{
    float amount;
    while (true)
    {
        std::cout << prompt << std::endl;
        try
        {
            if (std::cin >> amount && amount > 0)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                return amount;
            } else
            {
                throw std::invalid_argument("Invalid input. Please enter a positive number.");
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Discard invalid input
            std::cout << e.what() << std::endl;
            std::cout << std::endl;
        }
    }
}

bool Atm::sufficientFunds(float amount)
{
    Account* account = accountManager.getCurrentAccount();
    return account->getBalance() >= amount;
}



