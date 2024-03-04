package Taller3;

public class hotel {
    
    static room room = new room();
    static String[] rooms = room.roomsInitializer();
    static guest guest = new guest();
    static reader reader = new reader();
    static receptionist receptionist = new receptionist();

    

    public static void main(String[] args) {        
        guest.checkIn();
        receptionist.getRoomsState();
        System.out.println(rooms[guest.guestRoomNum]);
    }
}
