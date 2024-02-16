Descripción General
La calculadora es un programa simple desarrollado en C++ que permite calcular el salario total de un grupo de personas que trabajan en la creación de software, teniendo en cuenta el salario por hora y las horas de trabajo diarias de cada persona, así como las deducciones de impuestos como el IVA, el reteica y la retención en la fuente.

Parámetros de Entrada
cantidadPersonas: La cantidad de personas que trabajan en la creación de software.
salarioPorHora: El salario por hora de cada persona en el equipo.
horasTrabajoDiarias: La cantidad de horas de trabajo diarias por persona.
Funciones Utilizadas
double calcularSalarioTotal(int cantidadPersonas, double salarioPorHora, int horasTrabajoDiarias): Calcula el salario total antes de deducciones.

double calcularIVA(double salarioTotal): Calcula el valor del Impuesto al Valor Agregado (IVA) del salario total.

double calcularReteICA(double salarioTotal): Calcula el valor de la retención en la fuente por concepto de ReteICA.

double calcularRetencionFuente(double salarioTotal): Calcula el valor de la retención en la fuente.

Descripción de Funciones
calcularSalarioTotal: Esta función toma la cantidad de personas, el salario por hora y las horas de trabajo diarias como entrada y calcula el salario total multiplicando estos valores.

calcularIVA: Calcula el valor del IVA, que corresponde al 19% del salario total.

calcularReteICA: Calcula el valor de la retención en la fuente por concepto de ReteICA, que corresponde al 1% del salario total.

calcularRetencionFuente: Calcula el valor de la retención en la fuente, que corresponde al 11% del salario total.

Uso del Programa
El programa solicitará al usuario ingresar la cantidad de personas que trabajan en la creación de software, el salario por hora de cada persona y la cantidad de horas de trabajo diarias. Luego, imprimirá el salario total antes de deducciones, el IVA, el ReteICA, la retención en la fuente y el salario total después de deducciones.