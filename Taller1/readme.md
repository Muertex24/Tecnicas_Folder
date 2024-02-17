# Salary Calculator

This is a simple C++ program that calculates the total salary of a group of people involved in software development, taking into account various deductions such as taxes.

## Features

- Calculates total salary based on the number of persons, hourly salary, and daily work hours.
- Deducts a 10% risk from the total salary.
- Calculates ReteICA (Industry and Commerce Tax) at a rate of 1%.
- Calculates withholding tax at a rate of 11%.
- Calculates Value Added Tax (VAT) at a rate of 19%.
- Provides a breakdown of deductions and the final salary after deductions.

## Usage

1. Run the program.
2. Enter the number of persons involved in software development.
3. Enter the hourly salary for each person.
4. Enter the daily work hours (not more than 12 hours).
5. Review the results, including total salary, deductions, and final salary after deductions.
6. Choose whether to perform another calculation.

## How to Compile and Run

You can compile and run the program using any C++ compiler. Here's how you can do it using g++:

```bash
g++ salary_calculator.cpp -o salary_calculator
./salary_calculator
```

## Example

```
Enter the number of persons: 5
Enter the hourly salary: $20
Enter the daily work hours (not more than 12 hours): 8

Results:
Total salary before deductions: $800
Risk (10%): $80
ReteICA (1%): $7.20
Withholding tax (11%): $79.20
VAT (19%): $142.80
Total deductions: $229.20
Total salary after deductions: $570.80

Do you want to perform another calculation? (Y/N): N
```

## Notes

- Ensure that the input values are valid to avoid unexpected results.
- Daily work hours should not exceed 12 hours.

---

