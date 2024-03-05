package Taller3;

public class hotel {
    
    static room room = new room();
    static String[] rooms = room.roomsInitializer();
    static guest guest = new guest();
    static reader reader = new reader();
    static receptionist receptionist = new receptionist();

    static void getIntro(){
        String answer = reader.getString("¿Eres el recepcionista o un guest?");
        if(answer.equals("recepcionista")){
            System.out.println("Hola señor recepcionista");
        }
        if(answer.equals("guest")){
            
        }
    }    

    public static void main(String[] args) {        
        getIntro();
        guest.checkIn();
        receptionist.getRoomsState();
        // System.out.println(rooms[guest.guestRoomNum]);
    }
}