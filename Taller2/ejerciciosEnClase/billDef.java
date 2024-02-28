package ejerciciosEnClase;

public class billDef {
 
    static Lectura reader = new Lectura();

    static String name;
    static int age;
    static String nature;
    static int weight;

    static String[][] kindGarden = new String[6][6];
    static int index; 
    static int bounty;

    public static void addChild(){
        kindGarden[index][0] = name;
        kindGarden[index][1] = String.valueOf(age);
        kindGarden[index][2] = String.valueOf(weight);
        kindGarden[index][3] = nature;
        kindGarden[index][4] = Integer.toString(checkChildNature());
        index++;
    }
    public static void bounty(){
        for (int i = 0; i < index; i++) {
            bounty += Integer.parseInt(kindGarden[i][4]);
        }
        System.out.println("La parte de los programadores es: " + bounty*0.1);
    }
    public static void printKindergarden(){
        System.out.println("KinderGarden:");
        for (int i = 0; i < kindGarden.length -1; i++) {
            System.out.print("[ ");
            for (int j = 0; j < kindGarden[i].length - 1; j++) {
                System.out.print(kindGarden[i][j]);
                if (j < kindGarden[i].length - 1) {
                    System.out.print(", ");
                }
            };
            System.out.println(" ]");
        }
    }
    public static void getChildName(){
        name = reader.leerString("Por favor ingrese el nombre de su hijo");
    }
    
    public static void getChildAge(){
        age = reader.leerInt("Por favor ingrese la edad de su hijo en meses");
        checkChildAge();
    }

    public static void getChildWeight(){
        weight = reader.leerInt("Por favor ingrese el peso de su hijo");
        checkChildWeight();
    }

    public static void getChildNature(){
        nature = reader.leerString("Por favor ingrese el temperamento de su hijo, solo aceptamos niños tranquilos, entusiastas o muy entusiastas");
        checkChildNature();
    }

    public static String checkChildAge(){
        if(age > 60){
            System.out.println("No aceptamos niños mayores de 5 años");
            System.exit(1);
        }
        if(age==0){
            getChildAge();
            return "Por favor ingrese un dato valido";
        }
        if( age > 0 && age<60 ){
            return "Con esta edad podemos aceptar a su hijo, recuerde que pasado los 5 años, ya no podremos aceptarlo";
        }
        if(age < 0 ){
            System.out.println("La edad no puede ser negativa");
            getChildAge();
        }
        return "";
    }

    public static String checkChildWeight(){
        if(weight < 0){
            System.out.println("El peso no puede ser negativo");
            getChildWeight();
        }
        if(weight == 0){
            System.out.println("Por favor ingrese un dato valido");
            getChildWeight();
        }
        return "";
    }

    public static int checkChildNature(){
        switch(nature){
            case "tranquilo":
                return 300000;
            case "muy entusiasta":
                return 200000;
            case "entusiasta":
                return 100000;
            default:
            getChildNature();
            return 0;
        }
    }

    public static void makeABill(){     
        if(checkChildNature() == 0){
        nature = reader.leerString("Por favor ingrese el temperamento de su hijo, solo aceptamos niños tranquilos, entusiastas o muy entusiastas");
        }
        System.out.println("Le damos la bienvenida a su hijo " + name + ", el costo de la mensualidad sera de : " + checkChildNature());
    };
    
    public static void getKindergardenSpace(){
        if(index>=5){
            System.out.println("Lo sentimos no hay mas cupos");
            return;   
        }
        String answer = reader.leerString("¿Desearia ingresar su hijo a nuestra guarderia?");
        
        switch (answer) {
            case "si":
                createAChildObjData();
                break;
            case "no":
                System.out.println("Entendible, tenga un buen dia");
                bounty();
                printKindergarden();
            break;
            default:
                break;
        }
        
    }

    public static void createAChildObjData(){
        getChildName();
        getChildAge();
        getChildWeight();
        getChildNature();
        makeABill();
        addChild();
        getKindergardenSpace();
    }
    public static void main(String[] args){
       getKindergardenSpace();
    }
}
