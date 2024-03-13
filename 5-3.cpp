#include <iostream>
#include <iomanip>

// Function to print the header for the details report
void printDetailsHeader() {
    // Print the column headers with proper formatting
    std::cout << std::left << std::setw(8) << "Year"
              << std::setw(24) << "Year End Balance"
              << "Year End Earned Interest" << std::endl;
}

// Function to print the details of each year's investment
void printDetails(int year, double yearEndBalance, double interestEarned) {
    // Print the year, year-end balance, and year-end earned interest with proper formatting
    std::cout << std::left << std::setw(8) << year
              << std::fixed << std::setprecision(2)
              << "$" << std::setw(23) << yearEndBalance
              << "$" << std::setw(20) << interestEarned << std::endl;
}

// Function to calculate the year-end balance without monthly deposits
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
    // Calculate monthly interest rate
    double monthlyInterestRate = interestRate / 100 / 12;

    // Initialize variables for balance and interest earned
    double balance = initialInvestment;
    double interestEarnedThisYear;

    // Loop through each year
    for (int year = 1; year <= numberOfYears; year++) {
        // Calculate interest earned for this year
        interestEarnedThisYear = 0;

        // Loop through each month in the year
        for (int month = 0; month < 12; month++) {
            // Calculate interest earned for this month
            double interestEarnedThisMonth = balance * monthlyInterestRate;

            // Add interest earned to the balance
            balance += interestEarnedThisMonth;

            // Accumulate interest earned for the year
            interestEarnedThisYear += interestEarnedThisMonth;
        }

        // Print details for this year
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return the final balance
    return balance;
}

// Function to calculate the year-end balance with monthly deposits
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    // Calculate monthly interest rate
    double monthlyInterestRate = interestRate / 100 / 12;

    // Initialize variables for balance and interest earned
    double balance = initialInvestment;
    double interestEarnedThisYear = 0;

    // Loop through each year
    for (int year = 1; year <= numberOfYears; year++) {
        // Loop through each month in the year
        for (int month = 0; month < 12; month++) {
            // Calculate interest earned for this month
            double interestEarnedThisMonth = balance * monthlyInterestRate;

            // Add interest earned to the balance
            balance += interestEarnedThisMonth;

            // Accumulate interest earned for the year
            interestEarnedThisYear += interestEarnedThisMonth;
            
            // Add monthly deposit after interest calculation
            if (month != 11) // Exclude last month
                balance += monthlyDeposit;
        }

        // Add monthly deposit for the last month
        balance += monthlyDeposit;

        // Print details for this year
        printDetails(year, balance, interestEarnedThisYear);

        // Reset interest earned for the year for the next iteration
        interestEarnedThisYear = 0;
    }

    // Return the final balance
    return balance;
}

int main() {
    // Declare variables to store user input
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    // Prompt the user to enter initial investment amount
    std::cout << "Initial Investment Amount: $";
    // Read the initial investment amount from the user
    std::cin >> initialInvestment;

    // Prompt the user to enter monthly deposit amount
    std::cout << "Monthly Deposit: $";
    // Read the monthly deposit amount from the user
    std::cin >> monthlyDeposit;

    // Prompt the user to enter annual interest rate
    std::cout << "Annual Interest: ";
    // Read the annual interest rate from the user
    std::cin >> annualInterestRate;

    // Prompt the user to enter the number of years
    std::cout << "Number of Years: ";
    // Read the number of years from the user
    std::cin >> numberOfYears;

    // Print a newline for better formatting
    std::cout << std::endl;

    // Print the header for the report without monthly deposit
    std::cout << "Year-End Report Without Monthly Deposit:" << std::endl;
    // Call the function to calculate and print the year-end balance without monthly deposit
    printDetailsHeader();
    double balanceWithoutDeposit = calculateBalanceWithoutMonthlyDeposit(initialInvestment, annualInterestRate, numberOfYears);

    // Print a newline for better formatting
    std::cout << std::endl;

    // Print the header for the report with monthly deposit
    std::cout << "Year-End Report With Monthly Deposit:" << std::endl;
    // Call the function to calculate and print the year-end balance with monthly deposit
    printDetailsHeader();
    double balanceWithDeposit = balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterestRate, numberOfYears);

    // Return 0 to indicate successful execution of the program
    return 0;
}
