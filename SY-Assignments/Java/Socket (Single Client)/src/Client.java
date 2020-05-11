import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.DataOutputStream;
import java.net.Socket;


public class Client {
	
	public static void main (String[] args) throws Exception{
		Socket clientSocket = new Socket("localhost", 6969);
		DataOutputStream msgOutput = new DataOutputStream(clientSocket.getOutputStream());
		BufferedReader msgInput = new BufferedReader(new InputStreamReader(System.in));
		
		while (true) {
			String msg = msgInput.readLine();
			msgOutput.writeUTF(msg);
			if (msg.equalsIgnoreCase("exit")) {
				break;
			}
		}
		
		clientSocket.close();		
	}
}
