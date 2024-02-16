#include <iostream>
#include <iomanip>
using namespace std;

double calcularSalarioTotal(int cantidadPersonas, double salarioPorHora, int horasTrabajoDiarias) {
    return cantidadPersonas * salarioPorHora * horasTrabajoDiarias;
}

double calcularIVA(double salarioTotal) {
    return salarioTotal * 0.19;
}

double calcularReteICA(double salarioTotal) {
    return salarioTotal * 0.01;
}

double calcularRetencionFuente(double salarioTotal) {
    return salarioTotal * 0.11;
}

int main() {
    char continuar;
    do {
        int cantidadPersonas;
        double salarioPorHora;
        int horasTrabajoDiarias;

        cout << "Ingrese la cantidad de personas que trabajan creando el software: ";
        cin >> cantidadPersonas;

        cout << "Ingrese el salario por hora de cada persona: ";
        cin >> salarioPorHora;

        cout << "Ingrese la cantidad de horas de trabajo diarias: ";
        cin >> horasTrabajoDiarias;

        double salarioTotal = calcularSalarioTotal(cantidadPersonas, salarioPorHora, horasTrabajoDiarias);

        double iva = calcularIVA(salarioTotal);
        double reteica = calcularReteICA(salarioTotal);
        double retencionFuente = calcularRetencionFuente(salarioTotal);

        cout << "\nResultados:" << endl;
        cout << fixed << setprecision(2);
        cout << setw(40) << left << "Salario total antes de deducciones:" << "$" << salarioTotal << endl;
        cout << setw(40) << left << "IVA (19%):" << "$" << iva << endl;
        cout << setw(40) << left << "ReteICA (1%):" << "$" << reteica << endl;
        cout << setw(40) << left << "Retención en la fuente (11%):" << "$" << retencionFuente << endl;

        double salarioTotalDespuesDeducciones = salarioTotal - iva - reteica - retencionFuente;
        cout << "Salario total despues de deducciones: $" << salarioTotalDespuesDeducciones << endl;

        cout << "Desea realizar otro calculo? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
