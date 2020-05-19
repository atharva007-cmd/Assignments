import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;

public class Main
{
	
	private static final String url = "jdbc:mysql://localhost:3306/jdbc";
	private static String username = "root";
	private static String password = "toor";
	private static final String driver = "com.mysql.cj.jdbc.Driver";
	static Scanner scanner = new Scanner(System.in);
	
	public static void main (String[] args)
	{
		int choice = 0;
		
		// Login
		while (true)
		{
			System.out.println("LOGIN");
			System.out.println("\nEnter Username: ");
			username = scanner.next();
			System.out.println("Enter Password: ");
			password = scanner.next();
			
			if (!username.equals("root") && !password.equals("toor"))
			{
				System.err.println("Wrong Username or Password");
				System.out.println("Please try again\n\n");
			}
			else break;
		}
		
		
		// Menu Driven Program
		while (choice != 7)
		{
			System.out.println("\nMENU\n1. Create\n2. Insert\n3. Delete\n4. Update\n5. Display\n6. Drop\n7. Exit\nChoice: ");
			choice = scanner.nextInt();
			
			switch (choice)
			{
				case 1:
				{ createTable("Employee"); break; }
				
				case 2:
				{ insertQuery("Employee"); break; }

				case 3:
				{ deleteQuery("Employee"); break; }

				case 4:
				{ updateQuery("Employee"); break; }
				
				case 5:
				{ displayTable("Employee"); break; }
				
				case 6:
				{ dropTable("Employee"); break; }
				
				case 7:
				{ System.out.println("Exiting ..."); break; }
				
				default:
				{ System.err.println("Unexpected value: " + choice); }
			}
		}
		scanner.close();
	}
	
	
	// Loads drivers and establishes connection with the database.
	public static Connection connect()
	{
		try
		{
			// Load Driver
			Class.forName(driver);
			
			// Establish Connection
			Connection connection = DriverManager.getConnection(url, username, password);

			return connection;
		}
		catch (Exception exception) { System.err.println(exception); }
		
		System.out.println("Connection Failed!");
		return null;
	}

	
	// Creates Table
	public static void createTable(String TableName)
	{
		try
		{
			Connection connection = connect();
			
			// Prepare Statement
			PreparedStatement CREATE = connection.prepareStatement(
					"CREATE TABLE IF NOT EXISTS " + TableName
					+ " (ID INT NOT NULL AUTO_INCREMENT,"
					+ " First VARCHAR(25),"
					+ " Last VARCHAR(25),"
					+ " PRIMARY KEY (ID));");
			
			// Process/Execute Statement
			CREATE.executeUpdate();
		}
		catch (Exception exception) { System.err.println(exception); }
		finally { System.out.println("Table Created successfully."); }
	}
	
	
	// Insert Query
	public static void insertQuery(String TableName)
	{
		if (tableExist(TableName))
		{
			System.out.println("Enter First Name: ");
			final String first = scanner.next();
			System.out.println("Enter Last Name: ");
			final String last = scanner.next();
			Connection connection = connect();
			try
			{
				PreparedStatement INSERT;
				INSERT = connection.prepareStatement("INSERT INTO "
						+ TableName + " (First, Last)"
						+ " VALUES ('" + first + "', '"
						+ last + "');");
				INSERT.executeUpdate();
				System.out.println("Entry added successfully.");
			}
			catch (Exception exception) { System.err.println(exception); }
		}
	}
	
	
	// Delete Query
	public static void deleteQuery(String TableName)
	{
		if (tableExist(TableName))
		{
			displayTable(TableName);
			Connection connection = connect();
			
			System.out.println("\nEnter ID whose entry you want to delete: ");
			int ID = scanner.nextInt();
			try
			{
				PreparedStatement DELETE;
				DELETE = connection.prepareStatement("DELETE FROM " + TableName + " WHERE ID=" + ID);
				DELETE.executeUpdate();
				System.out.println("Entry deleted successfully.");				
			}
			catch (Exception exception) { System.err.println(exception); }
		}
	}
	
	
	// Update Query
	public static void updateQuery(String TableName)
	{
		if (tableExist(TableName))
		{
			displayTable(TableName);
			Connection connection = connect();
			
			System.out.println("Enter ID which you want to update: ");
			final String ID = scanner.next();
			System.out.println("Enter First Name: ");
			final String first = scanner.next();
			System.out.println("Enter Last Name: ");
			final String last = scanner.next();
			try
			{
				PreparedStatement UPDATE;
				UPDATE = connection.prepareStatement("UPDATE " + TableName + 
						" SET First='" + first +
						"', Last='" + last +
						"' WHERE ID=" + ID);
				UPDATE.executeUpdate();
				System.out.println("Entry updated successfully.");
			}
			catch (Exception exception) { System.err.println(exception); }
		}
	}
	
	
	// Display Table
	public static void displayTable(String TableName)
	{
		if (tableExist(TableName))
		{
			try
			{
				Connection connection = connect();
				Statement SELECT = connection.createStatement();
				ResultSet result = SELECT.executeQuery("SELECT * FROM " + TableName);
				System.out.println("ID \tName");
				while (result.next())
				{
					String ID = result.getString("ID");
					String Name = result.getString("First") + " " + result.getString("Last");
					System.out.println(ID + "\t" + Name);
				}
			}
			catch (Exception exception) { System.err.println(exception); }
		}
	}

	
	// Drop Table
	public static void dropTable(String TableName)
	{
		if (tableExist(TableName))
		{
			try
			{
				Connection connection = connect();
				PreparedStatement DROP = connection.prepareStatement("DROP TABLE " + TableName);
				DROP.executeUpdate();
				System.out.println("Table deleted successfully.");
			}
			catch (Exception exception) { System.err.println(exception); }
		}
	}
	
	
	// Checks if table exists or not.
	public static boolean tableExist (String TableName)
	{
		boolean existence = false;
		try
		{
			Connection connection = connect();
			ResultSet result = connection.getMetaData().getTables(null, null, TableName, null);
			while (result.next())
			{
				String TName = result.getString("TABLE_NAME");
				if (TName!=null && TName.equals(TableName))
				{
					existence = true;
					break;
				}
			}
		}
		catch (Exception exception) { }
		return existence;
	}
}