//
// Created by nick- on 10/23/2024.
//

#include "Account.h"

Account::Account(std::string username, std::string password, double balance)
    : username(username), password(password), balance(balance) {}

std::string Account::getUsername()
{
    return username;
}

std::string Account::getPassword()
{
    return password;
}

double Account::getBalance()
{
    return balance;
}

void Account::setUsername(std::string username)
{
    this->username = username;
}

void Account::setPassword(std::string password)
{
    this->password = password;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

