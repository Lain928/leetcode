/*
服务器端进行的相关操作
*/
#include <iostream>
#include <string>

#include <winsock2.h>  
#include <stdio.h>  
#include <tchar.h> // _T()所在的头文件
#pragma comment(lib,"ws2_32.lib")  
using namespace std;

void add_exe()
{
	/*
	str 转 LPCSTR 相关操作
	string str1 = "asd";
	LPCSTR str2 = str1.c_str();
	*/

	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = _T("D:\\Code\\c++实验\\scoket_client\\Debug\\scoket_client.exe");
	ShExecInfo.lpParameters = _T("");
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW; //用于显示调用的exe相关文件
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	// 	AfxGetApp()->BeginWaitCursor();
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	// 	AfxGetApp()->EndWaitCursor();
}

int main()
{
	//创建套接字，socket前的一些检查工作，包括服务的启动  
	WORD myVersionRequest;
	WSADATA wsaData;
	myVersionRequest = MAKEWORD(1, 1);
	int err;
	err = WSAStartup(myVersionRequest, &wsaData);
	if (!err)
	{
		printf("已打开套接字\n");
	}
	else
	{
		//进一步绑定套接字  
		printf("嵌套字未打开!");
		return 0;
	}
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, 0);//创建了可识别套接字  
	//需要绑定的参数，主要是本地的socket的一些信息。  
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//ip地址  
	addr.sin_port = htons(6000);//绑定端口  

	bind(serSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));//绑定完成  
	listen(serSocket, 5);//其中第二个参数代表能够接收的最多的连接数  

	SOCKADDR_IN clientsocket;
	int len = sizeof(SOCKADDR);
	//第二次握手，通过accept来接受对方的套接字的信息
	while (1)
	{
		cout << "等待客户端开启服务" << endl;
		SOCKET serConn = accept(serSocket, (SOCKADDR*)&clientsocket, &len);//如果这里不是accept而是conection的话。。就会不断的监听 
		char sendBuf[100] = "this is server";
		//sprintf(sendBuf, "welcome %s to bejing", inet_ntoa(clientsocket.sin_addr));//找对对应的IP并且将这行字打印到那里  
		//发送信息  
		send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
		cout << "接收客户端发送过来的消息：" << endl;
		char receiveBuf[100];
		recv(serConn, receiveBuf, strlen(receiveBuf) + 1, 0);
		printf("%s\n", receiveBuf);
		closesocket(serConn);//关闭  
		WSACleanup();//释放资源的操作  

	}

	system("pause");
	return 0;
}
