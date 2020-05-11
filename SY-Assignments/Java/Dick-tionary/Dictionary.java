import java.io.File;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

class Dictionary {
    
    private HashMap<String, LinkedList<String>> dictionary = new HashMap<String, LinkedList<String>>();
    private String yourFile;
    Scanner scan = new Scanner(System.in);

    void setFileName() {
        System.out.print("Name your Dictionary: ");
        yourFile = scan.next();
        while(yourFile.equals("Basic") == true) {
            System.out.println("\nTry another name!");
            System.out.print("Name your Dictionary: ");
            yourFile = scan.next();
        }
        yourFile = yourFile + ".txt";
        scan.close();
    }
    
    void dickInit() throws Exception {
        FileWriter fw = new FileWriter(yourFile, true);
        try {
            FileReader fr = new FileReader("Basic.txt");
            BufferedReader br = new BufferedReader(fr);
            String str;
            while ((str=br.readLine()) != null) {
                str = str.toLowerCase();
                String firstLetter = str.substring(0, 1);
                List<String> wordsList = dictionary.get(firstLetter);
                if (wordsList==null) {
                    wordsList = new LinkedList<String>();
                    dictionary.put(firstLetter, (LinkedList)wordsList);
                }
                if (!dictionary.get(firstLetter).contains(str)) {
                    wordsList.add(str);
                    fw.write(str);
                    fw.write("\n");
                }
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        fw.close();
    } 

    void wordProcessing(String word) throws Exception{
        String firstLetter = word.substring(0, 1);
        List<String> wordsList = dictionary.get(firstLetter);
        FileWriter fw = new FileWriter(yourFile, true);

        if (wordsList==null) {
            wordsList = new LinkedList<String>();
            dictionary.put(firstLetter, (LinkedList)wordsList);
        }

        if (!dictionary.get(firstLetter).contains(word)) {
            wordsList.add(word);
            fw.write(word);
            fw.write("\n");
        } else {
            System.out.println("Word already exists!");
        }
        fw.close();
    }

    void displayDictionary() {
        System.out.println("\nDICTIONARY:\n");
        Iterator mapIterator = dictionary.entrySet().iterator();
        while (mapIterator.hasNext()) {
            Map.Entry mEntry = (Map.Entry)mapIterator.next();
            System.out.println("Letter: " + mEntry.getKey().toString().toUpperCase());
            System.out.println(mEntry.getValue());
            System.out.println();
        }
    }

}