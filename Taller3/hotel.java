package Taller3;

public class hotel {
    
    static room room = new room();
    static String[] rooms = room.roomsInitializer();
    static guest guest = new guest();
    static reader reader = new reader();
    static receptionist receptionist = new receptionist();
    static double Revnue = 0;

    static void getIntro(){
        String answer = reader.getString("¿Eres el recepcionista o un guest?");
        if(answer.equals("recepcionista")){
            System.out.println("Hola señor recepcionista");
            receptionist.printOccupiedRooms();
            Revnue = receptionist.calculateTotalRevenue();
            System.out.println(Revnue);
        }
        if(answer.equals("guest")){
            guest.checkIn();
            receptionist.getRoomsState();   
        }
    }    

    public static void main(String[] args) {        
        getIntro();
    }
}