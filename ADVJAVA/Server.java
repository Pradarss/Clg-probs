import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        // Create a server socket on port 12345
        ServerSocket serverSocket = new ServerSocket(12345);
        System.out.println("Server listening on port 12345");
         // Continuously listen for client connections
        while (true) {
            
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket);

            // Handle client connection in a separate thread
            Thread thread = new Thread(new ClientHandler(clientSocket));
            thread.start();
        }
    }
}