#include <winsock2.h>                
#include <stdio.h>  
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")  


int main()
{
	//SOCKETǰ��һЩ��飬���Э���İ汾��Ϊ�˱����İ汾��socket������ͨ��  
	//WSAStartup������Ӧ�İ汾��WSAStartup�Ĳ���һ���ǰ汾��Ϣ��һ����һЩ��ϸ��ϸ�ڣ�ע��ߵ�λ  
	//WSAStartup��WSACleanup��Ӧ  
	int err;
	WORD versionRequired;
	WSADATA wsaData;
	versionRequired = MAKEWORD(1, 1);
	err = WSAStartup(versionRequired, &wsaData);//Э���İ汾��Ϣ  

	//ͨ��WSACleanup�ķ���ֵ��ȷ��socketЭ���Ƿ�����  
	if (!err)
	{
		printf("�ͻ���Ƕ�����Ѿ���!\n");
	}
	else
	{
		printf("�ͻ��˵�Ƕ���ִ�ʧ��!\n");
		return 0;//����  
	}

	//��һ�� �����׽���

	//����socket����ؼ��ʣ�������һ���Ǹ�ͼ���е�socket�����  
	//ע��socket�������������������������socket��������ϵͳ��socket�����ͣ��Լ�һЩ������Ϣ  
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	// �ڶ��� ���õ�ַ Ҫ���ӵĵ�ַ

	//socket����У���������һ���ṹ��SOCKADDR_IN����������һЩ��Ϣ����socket��ϵͳ��  
	//�˿ںţ�ip��ַ����Ϣ������洢���Ƿ������˵ļ��������Ϣ  
	SOCKADDR_IN clientsock_in;
	clientsock_in.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	clientsock_in.sin_family = AF_INET;
	clientsock_in.sin_port = htons(6000);

	while (1)
	{
		//������ ��������

		//ǰ�ڶ������׽��֣������˷������˵ļ������һЩ��Ϣ�洢��clientsock_in�У�  
		//׼��������ɺ�Ȼ��ʼ������׽������ӵ�Զ�̵ļ����  
		//Ҳ���ǵ�һ������  
		connect(clientSocket, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//��ʼ����  

		// ���Ĳ� ���մ����������Ϣ

		char receiveBuf[101];
		//����socket���������  
		recv(clientSocket, receiveBuf, 101, 0);
		cout << "���յ�������Ϊ��" << endl;
		printf("%s\n", receiveBuf);

		//����socket����  
// 		cout << "��������˷�����Ϣ" << endl;
// 		send(clientSocket, "hello,this is client", strlen("hello,this is client") + 1, 0);

		// ���岽 �ر��׽��� ���һ�δ���

		//�ر��׽���  
		closesocket(clientSocket);
		//�رշ���  
		WSACleanup();

	}

	char receiveBuf[101];
	//����socket���������  
	recv(clientSocket, receiveBuf, 101, 0);
	printf("%s\n", receiveBuf);

	system("pause");
	return 0;
}