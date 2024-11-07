# ATM Machine

This project simulates an ATM where users can  can create accounts, log in, log out, deposit money, withdraw money, and check their balance.

## Features

- **Create Account**: Users can create a new account with a unique username and password.
- **Log In**: Users can log in to their account using their username and password.
- **Deposit Money**: Users can deposit money into their account.
- **Withdraw Money**: Users can withdraw money from their account, provided they have sufficient funds.
- **Check Balance**: Users can check their account balance.
- **Log Out**: Users can log out of their account.

## Usage

1. **Start the ATM:** Run the application to sstart the ATM.
2. **Intro Menu:** Choose from the following options:
    - 'l' -> Login
    - 'x' -> Logout
    - 'c' -> Create Account
    - 'q' -> Quit
3. **Main Menu**: After Logging in, choose from the following options:
    - 'd' -> Deposit Money
    - 'w' -> Withdraw Money
    - 'r' -> Request Balance
    - 'b' -> Back to Intro Menu
    - 'q' -> Quit

## How to Run

### Prerequisites

- A C++ compiler
- CMake (for building the project)

### Building the Project

1. Clone the repository:
    ```bash
   git clone https://github.com/Fall2024-NSCC-ECampus/assignment-2-console-applications-atm-machine-Richardson902
    cd assignment-2-console-applications-atm-machine-Richardson902
    ```
2. Create a build directory and navigate to it:
    ```bash
    mkdir build
    cd build
    ```
3. Run CMake to configure the project:
    ```bash
    cmake ..
    ```
4. Build the project:
    ```bash
    make
    ```
   
### Running the Application

After building the project, you can run the application from the build directory:
```bash
./atm_machine
```