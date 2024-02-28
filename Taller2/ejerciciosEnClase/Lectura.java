package ejerciciosEnClase;

import java.util.Scanner;
public class Lectura {
    Scanner sc = new Scanner(System.in);

    public boolean checkInt(double num){
        return num % 1 == 0;
    }

    public int leerInt(String mensaje) {
        System.out.println(mensaje + ": ");
        int dato=0;
        return validateInt(dato);
    }

    public int validateInt(int dato){
        if (!sc.hasNextInt()) {
            System.out.println("No ingresó un número válido.");
            dato = 0;
            sc.next();
        } else {
            dato = sc.nextInt();
            if (checkInt(dato)) {
                System.out.println("El número ingresado es un entero: " + dato);
            }
        }
        return dato;
    }

    public String leerString(String mensaje){
        System.out.println(mensaje+": ");
        String dato = sc.next();
        return dato;
    }

}
