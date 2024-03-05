package Taller3;

public class guest {
    String guestName;
    int guestId;
    int guestPhone;
    int guestRoomNum;
    String[][] guestInfo;
    reader reader = new reader();

    public String[][] checkIn(){
        getName();
        getId();
        validateId();
        getPhone();
        validatePhone();
        return guestInfo;
    }
    public void getId(){
        guestId = reader.getInt("Ingrese su numero de identificación");
    }
    public void getName(){
        guestName = reader.getString("Hola ingrese su nombre");
    }
    public void getPhone(){
        guestPhone = reader.getInt("Ingrese su numero de telefono");
    }
    public void validateId(){
        if(guestId==0){
            getId();
        }
    }
    public void validatePhone(){
        if(guestPhone == 0){
            getPhone();
        }
    }

    public int checkOut(int roomPrice,int foodConsumed, int daysInRoom){
        return  roomPrice*daysInRoom+foodConsumed;
    }
}
