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
        int roomInput = reader.getInt(" ¿Que habitación desea?");
        if(roomInput < 0){
            System.out.println("El numero de la habitación debe ser positivo");
        }
        if(roomInput>=0 && roomInput<=100){
            guest.guestRoomNum= roomInput;
            //validateRooms
            OfferRoom();
        }
    }
    
    public void validateRooms(){
    	
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



}

