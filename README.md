# Banking Management System

## Overview
This project is a simple Banking Management System implemented in C. It allows users to create accounts, perform transactions, and apply for various types of loans.

## Features
- Account creation with unique account numbers and PIN protection
- Deposit and withdrawal functionality
- Balance inquiry with PIN verification
- Loan application for different loan types
- Secure PIN authentication with limited attempts
- Display of all registered accounts

## Technologies Used
- C programming language
- Standard C libraries (stdio.h, stdlib.h, string.h, math.h)

## Installation & Compilation
1. Clone the repository:
   ```sh
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```sh
   cd Banking-Management-System
   ```
3. Compile the program using GCC:
   ```sh
   gcc bank_management.c -o bank_management -lm
   ```
4. Run the program:
   ```sh
   ./bank_management
   ```

## Usage
- Run the program and follow the menu prompts to create an account, check balance, perform transactions, or apply for a loan.
- Enter the correct PIN for authentication while checking balance or performing transactions.
- Loan options include house, educational, personal, gold, and vehicle loans.

## File Structure
```
Banking-Management-System/
│-- bank_management.c   # Main source file
│-- README.md           # Documentation
```

## Contributing
1. Fork the repository.
2. Create a new branch:
   ```sh
   git checkout -b feature-branch
   ```
3. Commit changes:
   ```sh
   git commit -m "Add new feature"
   ```
4. Push to the branch:
   ```sh
   git push origin feature-branch
   ```
5. Open a pull request.


