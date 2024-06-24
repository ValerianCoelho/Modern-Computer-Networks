import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        Socket socket = null;
        PrintWriter out = null;
        BufferedReader in = null;

        try {
            socket = new Socket("localhost", 12345); // Connect to server at localhost on port 12345
            System.out.println("Connected to the server.");
            
            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            String inputLine, outputLine;

            // Send message to server and receive response
            while ((inputLine = stdIn.readLine()) != null) {
                out.println(inputLine);
                if ("bye".equals(inputLine)) {
                    break;
                }

                outputLine = in.readLine();
                System.out.println("Server: " + outputLine);
                if ("bye".equals(outputLine)) {
                    break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
