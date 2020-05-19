
public class Main {

	public static void main(String[] args) {
		final Processor processor = new Processor();
		
		Thread producerThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try { processor.produce(); } 
				catch (Exception exception) { System.err.println(exception); }
			}
		});
		
		Thread consumerThread = new Thread(new Runnable() {
			@Override
			public void run() {
				try { processor.consume(); } 
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

}
