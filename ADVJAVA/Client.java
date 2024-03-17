import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
         // Connect to server running on localhost at port 12345
        Socket socket = new Socket("localhost", 12345);
        // Create input and output streams for server communication
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        // Send message to server
        out.println("Hello from client \n Name - Adarsh \n Enrollment number - 50213203121 \n Class - IT_2(FSD)");
        // Receive response from server
        String response = in.readLine();
        System.out.println("Server response: " + response);
        // Close streams and socket
        out.close();    
        in.close();
        socket.close();
    }
}