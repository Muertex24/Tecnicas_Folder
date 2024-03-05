package TallerTecnicasConjunto;

public class ReceptionistOptions {
    public static void performOptions(reader reader) {
        boolean continuar = true;
        while (continuar) {
            System.out.println("Selecciona una opción:");
            System.out.println("1. Ver el estado de la habitación");
            System.out.println("2. Ver el dinero obtenido por las habitaciones");
            System.out.println("3. Terminar el turno");
            
            int opcion = reader.getInt("Ingrese el número de la opción deseada:");

            switch (opcion) {
                case 1:
                    receptionist.readAllRooms();
                    break;
                case 2:
                    receptionist.getMoneyObtained();
                    break;
                case 3:
                    continuar = false;
                    System.out.println("¡Hasta luego!");
                    break;
                default:
                    System.out.println("Opción no válida. Por favor, ingrese un número válido.");
                    break;
            }

            if (opcion != 3) {
                continuar = reader.getBoolean("¿Desea continuar usando el servicio de recepcionista?", false);
            }
        }
    }
}