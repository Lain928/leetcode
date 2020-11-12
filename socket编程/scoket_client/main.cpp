#include <winsock2.h>                
#include <stdio.h>  
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")  


int main()
{
	//SOCKET前的一些检查，检查协议库的版本，为了避免别的版本的socket，并且通过  
	//WSAStartup启动对应的版本，WSAStartup的参数一个是版本信息，一个是一些详细的细节，注意高低位  
	//WSAStartup与WSACleanup对应  
	int err;
	WORD versionRequired;
	WSADATA wsaData;
	versionRequired = MAKEWORD(1, 1);
	err = WSAStartup(versionRequired, &wsaData);//协议库的版本信息  

	//通过WSACleanup的返回值来确定socket协议是否启动  
	if (!err)
	{
		printf("客户端嵌套字已经打开!\n");
	}
	else
	{
		printf("客户端的嵌套字打开失败!\n");
		return 0;//结束  
	}

	//第一步 建立套接字

	//创建socket这个关键词，这里想一下那个图形中的socket抽象层  
	//注意socket这个函数，他三个参数定义了socket的所处的系统，socket的类型，以及一些其他信息  
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	// 第二步 设置地址 要连接的地址

	//socket编程中，它定义了一个结构体SOCKADDR_IN来存计算机的一些信息，像socket的系统，  
	//端口号，ip地址等信息，这里存储的是服务器端的计算机的信息  
	SOCKADDR_IN clientsock_in;
	clientsock_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	clientsock_in.sin_family = AF_INET;
	clientsock_in.sin_port = htons(6000);

	while (1)
	{
		//第三步 建立连接

		//前期定义了套接字，定义了服务器端的计算机的一些信息存储在clientsock_in中，  
		//准备工作完成后，然后开始将这个套接字链接到远程的计算机  
		//也就是第一次握手  
		connect(clientSocket, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//开始连接  

		// 第四步 接收传输的数据信息

		char receiveBuf[101];
		//接收socket里面的内容  
		recv(clientSocket, receiveBuf, 101, 0);
		cout << "接收到的数据为：" << endl;
		printf("%s\n", receiveBuf);

		//发送socket数据  
// 		cout << "向服务器端发送信息" << endl;
// 		send(clientSocket, "hello,this is client", strlen("hello,this is client") + 1, 0);

		// 第五步 关闭套接字 完成一次传输

		//关闭套接字  
		closesocket(clientSocket);
		//关闭服务  
		WSACleanup();

	}

	char receiveBuf[101];
	//接收socket里面的内容  
	recv(clientSocket, receiveBuf, 101, 0);
	printf("%s\n", receiveBuf);

	system("pause");
	return 0;
}