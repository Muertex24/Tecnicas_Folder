package Taller3;

public class room {
    public int roomNum;
    public int roomFloor;
    public int roomPrice;
    public String roomState;
    public String stringObject;
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
                index++;
                stringObject = "RoomNum: " + roomInitialized.roomNum + " RoomFloor: " + roomInitialized.roomFloor + " RoomState: " + roomInitialized.roomState + " RoomPrice: " + roomInitialized.roomPrice;
                rooms[index] = stringObject;
            }
        }
        return rooms;
    }
}
