//
// Created by nick- on 11/2/2024.
//

#ifndef ATM_H
#define ATM_H

#include "AccountManager.h"

class Atm {
  private:
    AccountManager accountManager;
    char menuInput;

  public:
    Atm();
    void printIntroMenu();
    void printMainMenu();
    void start();
    void mainMenu();
    void updateBalance(float amount, bool isDeposit);
    bool sufficientFunds(float amount);
    void requestBalance();
    float getValidInput(const std::string& prompt);
};

#endif //ATM_H
