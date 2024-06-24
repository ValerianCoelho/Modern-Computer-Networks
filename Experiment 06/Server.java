import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        ServerSocket serverSocket = null;
        Socket socket = null;
        PrintWriter out = null;
        BufferedReader in = null;
        
        try {
            serverSocket = new ServerSocket(12345); // Start server on port 12345
            System.out.println("Server started. Waiting for a client...");
            socket = serverSocket.accept(); // Wait for a client
            System.out.println("Client connected.");

            out = new PrintWriter(socket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
            String inputLine, outputLine;
            
            // Read from client and respond
            while ((inputLine = in.readLine()) != null) {
                System.out.println("Client: " + inputLine);
                if ("bye".equalsIgnoreCase(inputLine)) {
                    break;
                }

                System.out.print("Server: ");
                outputLine = stdIn.readLine();
                out.println(outputLine);
                if ("bye".equalsIgnoreCase(outputLine)) {
                    break;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (out != null) out.close();
                if (in != null) in.close();
                if (socket != null) socket.close();
                if (serverSocket != null) serverSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
