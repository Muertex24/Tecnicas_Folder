package Taller3;


public class receptionist {
    static room room = new room();
    static String[] rooms = room.roomsInitializer();
    static guest guest = new guest();


    public static void getGuestInfo(){
        System.out.println("hola " + guest.guestName);
    }
    public static void main(String[] args) {
        guest.checkIn();
        getGuestInfo();
    }
}
