//Owen Moloney
//April 28th 2025
/* I am making a mulit-threaded web server
--> The purpose of the project is to make a HTTP server that can handle multiple requests using threads 
--> also to support concurrent file serving 
--> skills: network programing and multithreading
*/

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

using namespace std;

void handle_request(int client_fd) {
    // Request Buffer
    char buffer[1024];
    ssize_t read_size = read(client_fd, buffer, sizeof(buffer) - 1);
    if (read_size > 0) {
        buffer[read_size] = '\0';  // Null-terminate the buffer
        
        // Log the request
        cout << "Request received: " << endl;
        cout << buffer << endl;
        
        // HTTP Response
        string http_response = "HTTP/1.1 200 OK\r\n";
        http_response += "Content-Type: text/html\r\n";
        http_response += "Connection: close\r\n\r\n";
        http_response += "<html><body><h1>Hello, World!</h1></body></html>";
        
        // Send the response
        send(client_fd, http_response.c_str(), http_response.size(), 0);
    }

    // Close the client connection
    close(client_fd);
}

int main() {
    // Create a socket for the server
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // Set up server address structure
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        return -1;
    }

    cout << "Server listening on port " << PORT << "..." << endl;

    // Accept incoming client connections
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_fd;
    
    while (true) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client's request
        handle_request(client_fd);
    }

    // Close the server socket
    close(server_fd);
    return 0;
}
