import java.util.Scanner;

class Main {
    public static void main(String[] args) throws Exception {
        Dictionary myDick = new Dictionary();
        Scanner scan = new Scanner(System.in);

        myDick.setFileName();
        myDick.dickInit();

        int input = 0;
        while (input != 3) {  
            System.out.println("\n1. Word\n2. Print\n3. Exit\nChoice: ");
            input = scan.nextInt();
            System.out.println();
            
            switch (input) {
                case 1: {
                    System.out.println("Enter Word: ");
                    String word = scan.next();
                    myDick.wordProcessing(word.toLowerCase());
                    scan.close();
                    break;
                }
                case 2: {
                    myDick.displayDictionary();
                    break;
                }
                case 3: {
                    System.out.println("\nExiting ..");
                    scan.close();
                    break;
                }
                default: {
                    System.out.println("Wrong Choice!");
                }
            }
        }
    }
}