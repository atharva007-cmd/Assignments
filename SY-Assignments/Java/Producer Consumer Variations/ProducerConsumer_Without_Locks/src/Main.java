import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Main {
	
	private static BlockingQueue<Integer> queue = new ArrayBlockingQueue<Integer>(10);
	
	
	// Main 
	public static void main(String[] args) {
		
		Thread producerThread = new Thread(new Runnable() {
			public void run() {
				try { producer(); } 
				catch (Exception exception) { System.err.println(exception); }
			}
		});
		
		Thread consumerThread = new Thread(new Runnable() {
			public void run() {
				try { consumer(); } 
				catch (Exception exception) { System.err.println(exception); }
			}
		});
		
		producerThread.start();
		consumerThread.start();
		
		try {
			producerThread.join();
			consumerThread.join();
		} 
		catch (Exception exception) { System.err.println(exception); }
	}
	
	
	// Producer
	private static void producer() throws Exception {
		Random num = new Random();
		while (true) {
			int value = (num.nextInt(100)+1);
			queue.put(value);
		}
	}
	
	
	// Consumer
	private static void consumer() throws Exception {
		Random num = new Random();
		while (true) {
			Thread.sleep(500);
			if (num.nextInt(10) == 0) {
				Integer value = queue.take();
				System.out.println(value + " consumed!");
				System.out.println("Queue Size: " + queue.size());
				System.out.println(queue);
				System.out.println();
			}
		}
	}
}
