//
// Created by nick- on 10/23/2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {

private:
    std::string username;
    std::string password;
    double balance;

public:
    Account(std::string username, std::string password, double balance = 0);

    std::string getUsername();
    std::string getPassword();
    double getBalance();

    void setUsername(std::string username);
    void setPassword(std::string password);
    void setBalance(double balance);
};

#endif //ACCOUNT_H
