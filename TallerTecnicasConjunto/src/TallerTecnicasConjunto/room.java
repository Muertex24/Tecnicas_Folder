package TallerTecnicasConjunto;

public class room {
    public int num;
    public int floor;
    public int price;
    public String state;
    public String stringObject;
    public int id;
    public static String[] rooms;
    public int index = -1;
    public room(){};


    public String[] roomsInitializer(){
        rooms = new String[100];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                room roomInitialized = new room();
                roomInitialized.num = j+1;
                roomInitialized.floor = i+1;
                roomInitialized.state = "Available";
                roomInitialized.price = roomInitialized.floor * 500000;
                roomInitialized.id = index+2;
                index++;
                stringObject = "La habitación: " + roomInitialized.id + " Se encuentra en el piso : " + roomInitialized.floor + " Es la habitación numero: " + roomInitialized.num +" se encuentra: " +roomInitialized.state +" y tiene un precio de: " + roomInitialized.price;
                rooms[index] = stringObject;
                
            }
        }
        return rooms;
    }
}