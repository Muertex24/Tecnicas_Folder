#include <iostream>
#include <iomanip>
using namespace std;

double calculateTotalSalary(int numberOfPersons, double hourlySalary, int dailyWorkHours) {
    return numberOfPersons * hourlySalary * dailyWorkHours;
}

double calculateVAT(double totalSalaryAfterDeductions) {
    return totalSalaryAfterDeductions * 0.19;
}

double calculateReteICA(double totalSalaryAfterRisk) {
    return totalSalaryAfterRisk * 0.01;
}

double calculateWithholdingTax(double totalSalaryAfterRisk) {
    return totalSalaryAfterRisk * 0.11;
}

double calculateRisk(double totalSalary) {
    return totalSalary * 0.10;
}

int main() {
    char continueCalculation;
    do {
        int numberOfPersons;
        double hourlySalary;
        int dailyWorkHours;

        cout << "Enter the number of persons: ";
        cin >> numberOfPersons;

        cout << "Enter the hourly salary: $";
        cin >> hourlySalary;

        do {
            cout << "Enter the daily work hours (not more than 12 hours): ";
            cin >> dailyWorkHours;
        } while (dailyWorkHours > 12);

        double totalSalary = calculateTotalSalary(numberOfPersons, hourlySalary, dailyWorkHours);
        double risk = calculateRisk(totalSalary);
        totalSalary -= risk;

        double reteica = calculateReteICA(totalSalary);
        double withholdingTax = calculateWithholdingTax(totalSalary);
        totalSalary -= (reteica + withholdingTax);

        double vat = calculateVAT(totalSalary);

        cout << "\nResults:" << endl;
        cout << fixed << setprecision(2);
        cout << setw(40) << left << "Total salary before deductions:" << "$" << totalSalary << endl;
        cout << setw(40) << left << "Risk (10%):" << "$" << risk << endl;
        cout << setw(40) << left << "ReteICA (1%):" << "$" << reteica << endl;
        cout << setw(40) << left << "Withholding tax (11%):" << "$" << withholdingTax << endl;
        cout << setw(40) << left << "VAT (19%):" << "$" << vat << endl;

        double totalDeductions = reteica + withholdingTax + vat;
        double totalSalaryAfterDeductions = totalSalary - totalDeductions;
        cout << setw(40) << left << "Total deductions:" << "$" << totalDeductions << endl;
        cout << setw(40) << left << "Total salary after deductions:" << "$" << totalSalaryAfterDeductions << endl;

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'Y' || continueCalculation == 'y');

    return 0;
}
