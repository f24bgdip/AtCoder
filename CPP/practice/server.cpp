#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET listenSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;
    int serverPort = 12345; // 待ち受けポート番号

    // Winsockの初期化
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // ソケットの作成
    listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket." << std::endl;
        WSACleanup();
        return 1;
    }

    // サーバーのアドレス設定
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // すべてのローカルアドレスからの接続を受け付ける
    serverAddr.sin_port = htons(serverPort);

    // ソケットをアドレスにバインド
    if (bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed." << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    // クライアントからの接続待ち
    listen(listenSocket, SOMAXCONN);

    std::cout << "Server listening on port " << serverPort << "..." << std::endl;

    // クライアントからの接続を受け付け
    int clientAddrSize = sizeof(clientAddr);
    clientSocket = accept(listenSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed." << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return 1;
    }

    // クライアントからのメッセージを受信
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        std::cout << "Received message from client: " << buffer << std::endl;
    }

    // ソケットのクローズとWinsockの終了
    closesocket(clientSocket);
    closesocket(listenSocket);
    WSACleanup();

    return 0;
}
