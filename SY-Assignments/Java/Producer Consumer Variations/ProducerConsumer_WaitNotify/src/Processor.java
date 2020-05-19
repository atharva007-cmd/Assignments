import java.util.Scanner;

public class Processor {
	
	// Producer
	public void produce() throws Exception {
		synchronized (this) {
			System.out.println("Producer Thread running ..");
			wait();
			System.out.println("Resumed.");
		}
	}
		
		
	// Consumer
	public void consume() throws Exception {
		Scanner scanner = new Scanner(System.in);
		Thread.sleep(1000);
		
		synchronized (this) {
			System.out.println("Waiting for return key.");
			scanner.nextLine();
			System.out.println("Return key pressed.");
			notify();
		}
	}
}
