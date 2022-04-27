#include "stdfx.h"
#include "CServerConn.h"
#include "CServerThread.h"


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
	printf("#                     SERVER SIDE                    \n");
	printf("#---------------------------------------------------#\n\n");
	Sleep(200);

	
	DWORD dwThreadId = 0;
	HANDLE hServerThread = ::CreateThread(nullptr, 0, ServerThread, nullptr, 0, &dwThreadId);


	while (TRUE)
	{
		DWORD ret = WaitForSingleObject(hServerThread, INFINITE);
	
		if (ret == WAIT_FAILED)
			return 0;
		else if (ret == WAIT_ABANDONED)
		{
			ResetEvent(hServerThread);
			continue;
		}
		else if (WAIT_TIMEOUT)
		{ continue; }
		else
		{
			ResetEvent(hServerThread);
			//하고 싶은거
			printf("TESTESTE");
		}
	}
	  

	system("pause");
	return 0;
}