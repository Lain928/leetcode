/*
�������˽��е���ز���
*/
#include <iostream>
#include <string>

#include <winsock2.h>  
#include <stdio.h>  
#include <tchar.h> // _T()���ڵ�ͷ�ļ�
#pragma comment(lib,"ws2_32.lib")  
using namespace std;

void add_exe()
{
	/*
	str ת LPCSTR ��ز���
	string str1 = "asd";
	LPCSTR str2 = str1.c_str();
	*/

	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = _T("D:\\Code\\c++ʵ��\\scoket_client\\Debug\\scoket_client.exe");
	ShExecInfo.lpParameters = _T("");
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW; //������ʾ���õ�exe����ļ�
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	// 	AfxGetApp()->BeginWaitCursor();
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	// 	AfxGetApp()->EndWaitCursor();
}

int main()
{
	//�����׽��֣�socketǰ��һЩ��鹤�����������������  
	WORD myVersionRequest;
	WSADATA wsaData;
	myVersionRequest = MAKEWORD(1, 1);
	int err;
	err = WSAStartup(myVersionRequest, &wsaData);
	if (!err)
	{
		printf("�Ѵ��׽���\n");
	}
	else
	{
		//��һ�����׽���  
		printf("Ƕ����δ��!");
		return 0;
	}
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, 0);//�����˿�ʶ���׽���  
	//��Ҫ�󶨵Ĳ�������Ҫ�Ǳ��ص�socket��һЩ��Ϣ��  
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//ip��ַ  
	addr.sin_port = htons(6000);//�󶨶˿�  

	bind(serSocket, (SOCKADDR*)&addr, sizeof(SOCKADDR));//�����  
	listen(serSocket, 5);//���еڶ������������ܹ����յ�����������  

	SOCKADDR_IN clientsocket;
	int len = sizeof(SOCKADDR);
	//�ڶ������֣�ͨ��accept�����ܶԷ����׽��ֵ���Ϣ
	while (1)
	{
		cout << "�ȴ��ͻ��˿�������" << endl;
		SOCKET serConn = accept(serSocket, (SOCKADDR*)&clientsocket, &len);//������ﲻ��accept����conection�Ļ������ͻ᲻�ϵļ��� 
		char sendBuf[100] = "this is server";
		//sprintf(sendBuf, "welcome %s to bejing", inet_ntoa(clientsocket.sin_addr));//�ҶԶ�Ӧ��IP���ҽ������ִ�ӡ������  
		//������Ϣ  
		send(serConn, sendBuf, strlen(sendBuf) + 1, 0);
		cout << "���տͻ��˷��͹�������Ϣ��" << endl;
		char receiveBuf[100];
		recv(serConn, receiveBuf, strlen(receiveBuf) + 1, 0);
		printf("%s\n", receiveBuf);
		closesocket(serConn);//�ر�  
		WSACleanup();//�ͷ���Դ�Ĳ���  

	}

	system("pause");
	return 0;
}
