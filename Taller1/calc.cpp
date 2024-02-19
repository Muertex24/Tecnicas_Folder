#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
using namespace std;

int numberOfPersons;
double hourlySalary;
double dailyWorkHours;
char continueCalculation;
double totalSalary;
double risk;
double reteica;
double vat;
double withholdingTax;
double totalDeductions;
double totalSalaryAfterDeductions;

double calculateTotalSalary() {
    return numberOfPersons * hourlySalary * dailyWorkHours;
}

double calculateVAT(double totalSalaryAfterDeductions) {
    return totalSalaryAfterDeductions * 0.19;
}

double calculateReteICA(double totalSalaryAfterRisk){
    return totalSalaryAfterRisk * 0.01;
}

double calculateWithholdingTax(double totalSalaryAfterRisk) {
    return totalSalaryAfterRisk * 0.11;
}

double calculateRisk(double totalSalary) {
    return totalSalary * 0.10;
}

void getData(){
        cout << "Enter the number of persons: ";
    while (!(cin >> numberOfPersons)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the hourly salary: $";
    while (!(cin >> hourlySalary)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    do {
        cout << "Enter the daily work hours (not more than 12 hours): ";
        while (!(cin >> dailyWorkHours)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (dailyWorkHours > 12);
}

void showInfo(){
    cout << "\nResults:" << endl;
    cout << fixed << setprecision(2);
    cout << setw(40) << left << "Total salary before deductions:" << "$" << totalSalary << endl;
    cout << setw(40) << left << "Risk (10%):" << "$" << risk << endl;
    cout << setw(40) << left << "ReteICA (1%):" << "$" << reteica << endl;
    cout << setw(40) << left << "Withholding tax (11%):" << "$" << withholdingTax << endl;
    cout << setw(40) << left << "VAT (19%):" << "$" << vat << endl;
    cout << setw(40) << left << "Total deductions:" << "$" << totalDeductions << endl;
    cout << setw(40) << left << "Total salary after deductions:" << "$" << totalSalaryAfterDeductions << endl;
}

void doOperations (){
    totalSalary = calculateTotalSalary();
    risk = calculateRisk(totalSalary);
    reteica = calculateReteICA(totalSalary - risk);
    withholdingTax = calculateWithholdingTax(totalSalary - risk);
    vat = calculateVAT(totalSalary - (reteica + withholdingTax));
    totalDeductions = reteica + withholdingTax + vat;
    totalSalaryAfterDeductions = totalSalary - totalDeductions;
}

int main() {
    do {
        getData();
        doOperations();
        showInfo();

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'Y' || continueCalculation == 'y');

    return 0;
}
