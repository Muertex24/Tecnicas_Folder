package Taller3;


public class receptionist {
    static room room = new room();
    static String[] rooms = room.roomsInitializer();
    static guest guest = new guest();
    static reader reader = new reader();

    public static void getGuestInfo(){
        System.out.println("hola " + guest.guestName);
    }
    public static void readAllRooms(){
        for (int i = 0; i < rooms.length; i++) {
            System.out.println(rooms[i]);
        }
    }
    public void getRoomsState(){
        readAllRooms();
        int roomInput = reader.getInt("¿Que habitación desea?");
        if(roomInput < 0){
            System.out.println("El numero de la habitación debe ser positivo");
        }
        if(roomInput>=0 && roomInput<=100 && !rooms[roomInput-1].contains("noAvailable")){
            guest.guestRoomNum= roomInput;
            OfferRoom();
        }else{
            System.out.println("Habitación ocupada");
        }
    }
    
    public static void printOccupiedRooms() {
        System.out.println("Habitaciones ocupadas:");
        for (int i = 0; i < rooms.length; i++) {
            if (rooms[i].contains("noAvailable")) {
                System.out.println("Habitación " + (i + 1));
            }
        }
    }

    public static double calculateTotalRevenue() {
        double totalRevenue = 0.0;

        for (int i = 0; i < rooms.length; i++) {
            if (rooms[i].contains("noAvailable")) {
                String input = rooms[i];
                int priceIndex = input.indexOf("y tiene un precio de:");
                if (priceIndex != -1) {
                    String priceInfo = input.substring(priceIndex + "y tiene un precio de:".length());
                    priceInfo = priceInfo.trim();
                    double roomPrice = Double.parseDouble(priceInfo);

                    totalRevenue += roomPrice;
                }
            }
        }

        return totalRevenue;
    }

 
    public static void getRoomPrice() {
            String input = rooms[guest.guestRoomNum-1];
            int priceIndex = input.indexOf("y tiene un precio de:");
    
            if (priceIndex != -1) {
                String priceInfo = input.substring(priceIndex + "y tiene un precio de:".length());
    
                priceInfo = priceInfo.trim();
    
                System.out.println(priceInfo);
            } else {
                System.out.println("No se encontró el precio de la habitación.");
            }
    }

    public static void OfferRoom(){
        String input = reader.getString("¿Desea tomar la habitación? (si/no)");
        switch (input) {
            case "si":
            	changeState();
            	System.out.println("Ahora la habitación " + guest.guestRoomNum + " no esta disponible");
            	hotel.getIntro();
                break; 
            case "no": 
                System.out.println("Entendible tenga buen dia");
                hotel.getIntro();
                break;
            default:
                System.out.println("Solo se aceptan respuestas si o no");
                System.out.println("Vuelva a intentar el proceso de check-in");
                hotel.getIntro();
                break;
        }
    }

    public static void changeState(){
        String updatedInput = rooms[guest.guestRoomNum-1].replace("Available", "noAvailable");
        rooms[guest.guestRoomNum-1] = updatedInput;
    }

    public static void performOptions() {
        boolean continuar = true;
  
        while(continuar) {
           System.out.println("Selecciona una opción:");
           System.out.println("1. Ver el estado de las habitaciones");
           System.out.println("2. Ver el dinero obtenido por las habitaciones");
           System.out.println("3. Ver habitaciones ocupadas");
           System.out.println("4. Terminar el turno");
           int opcion = reader.getInt("Ingrese el número de la opción deseada:");
           switch (opcion) {
              case 1:
                 readAllRooms();
                 break;
              case 2:
                 System.out.println(calculateTotalRevenue());
                 
                 break;
              case 3:
                 printOccupiedRooms();
                 break;
              case 4:
                 continuar = false;
                 System.out.println("!Hasta luego!");
                 break;
              default:
                 System.out.println("Opción no válida. Por favor, ingrese un número válido.");
           }
  
           if (opcion != 4) {
              continuar = reader.getBoolean("¿Desea continuar usando el servicio de recepcionista?", false);
           }
        }
  
     }


}

