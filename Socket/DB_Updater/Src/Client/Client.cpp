#include "stdfx.h"
#include "CConnClient.h"

struct ST_WSA_INITIALIZER
{
	WSAData wsa;
	ST_WSA_INITIALIZER(void)
	{
		WSAStartup(MAKEWORD(2, 2), &wsa);
	}
	~ST_WSA_INITIALIZER(void)
	{
		WSACleanup();
	}
};
ST_WSA_INITIALIZER g_WSAInitialize;






int main(void)
{
	printf("#---------------------------------------------------#\n");
	printf("#                     CLIENT SIDE                    \n");
	printf("#---------------------------------------------------#\n\n");

	std::vector<HANDLE> vecClientThread;
	for (int i = 0; i < 5; i++)
	{
		HANDLE hClientThread = CreateThread(nullptr, 0, ClientThread, nullptr, 0, nullptr);
		vecClientThread.push_back(hClientThread);
		Sleep(500);
	}

	for (size_t i = 0; i < vecClientThread.size(); i++)
		WaitForSingleObject(vecClientThread[i], INFINITE);

	system("pause");
	return 0;
}