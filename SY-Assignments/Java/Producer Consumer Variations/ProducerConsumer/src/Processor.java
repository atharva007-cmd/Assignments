import java.util.LinkedList;

public class Processor {
	
	private final int LIMIT = 10;
	private LinkedList<Integer> products = new LinkedList<Integer>();
	private Object mutex = new Object();
	
	// Producer
	public void produce() throws Exception {
		int value = 0;
		
		while(true) {
			synchronized (mutex) {
				
				while (products.size() == LIMIT) {
					mutex.wait();
				}
				products.add(value++);
			}
		}
	}
			
			
	// Consumer
	public void consume() throws Exception {
		
		while(true) {
			synchronized (mutex) {
				
				while (products.size() == 0) {
					mutex.wait();
				}
				
				System.out.println("List Size: " + products.size());
				int value = products.removeFirst();
				System.out.println(value + " removed.\n");
				mutex.notify();
			}
			Thread.sleep(1000);
		}
	}
	
	
}
