#include <iostream>
#include <string>

class Server {
private:
    // Data members are usually private (Encapsulation)
    std::string ipAddress;
    int port;
    bool isRunning;

public:
    // Simple Constructor for initialization
    void init(std::string ip, int p) {
        // 'this' pointer resolves ambiguity between member and parameter
        this->ipAddress = ip;
        this->port = p;
        this->isRunning = false;
    }

    // Public method to modify state
    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "[LOG] Server started at " << ipAddress << ":" << port << "\n";
        }
    }

    // Public method to read state (Getter)
    bool getStatus() {
        return isRunning;
    }
};

int main() {
    // 1. Instantiation (Creating an object on the Stack)
    Server webServer;

    // 2. Accessing Public Interface
    // We cannot access 'webServer.port' directly because it is private.
    webServer.init("111.1.11.12", 8080);
    
    std::cout << "Server Status Before: " << webServer.getStatus() << "\n";
    
    webServer.start();

    std::cout << "Server Status After: " << webServer.getStatus() << "\n";

    // 3. Size demonstration
    std::cout << "Size of Server Object: " << sizeof(webServer) << " bytes\n";
    // Size will be roughly sizeof(string) + sizeof(int) + sizeof(bool) + padding

    return 0;
}