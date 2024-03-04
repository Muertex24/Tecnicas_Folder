package Taller3;

import java.util.Scanner;
public class reader {
    Scanner sc = new Scanner(System.in);

    public boolean checkInt(double num){
        return num % 1 == 0;
    }

    public int getInt(String mensaje) {
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
        }
        return dato;
    }

    public String getString(String mensaje){
        System.out.println(mensaje+": ");
        String dato = sc.next();
        return dato;
    }
}

