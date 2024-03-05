package Taller3;

public class guest {
    String guestName;
    int guestId;
    int guestPhone;
    String guestAddress;
    int guestRoomNum;
    String[][] guestInfo;
    reader reader = new reader();

    public String[][] checkIn(){

        guestName = reader.getString("Hola ingrese su nombre");
        guestId = reader.getInt("Ingrese su numero de identificación");
        guestPhone = reader.getInt("Ingrese su numero de telefono");

        return guestInfo;
    }
}
