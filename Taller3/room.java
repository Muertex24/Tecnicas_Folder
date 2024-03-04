package Taller3;

public class room {
    public int roomNum;
    public int roomFloor;
    public int roomPrice;
    public String roomState;
    public String stringObject;
    public int roomId;
    public static String[] rooms;
    public int index = -1;
    public room(){};


    public String[] roomsInitializer(){
        rooms = new String[100];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                room roomInitialized = new room();
                roomInitialized.roomNum = j+1;
                roomInitialized.roomFloor = i+1;
                roomInitialized.roomState = "Available";
                roomInitialized.roomPrice = roomInitialized.roomFloor * 500000;
                roomId = index+2;
                index++;
                stringObject = "Numero de la habitación: " + roomInitialized.roomNum + " Se encuentra en el piso : " + roomInitialized.roomFloor + " Se encuentra: " + roomInitialized.roomState +" el identificador de la habitación es: " + roomId +" y tiene un precio de: " + roomInitialized.roomPrice;
                rooms[index] = stringObject;
                
            }
        }
        return rooms;
    }
}
