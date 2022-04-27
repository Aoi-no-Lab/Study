#include "stdfx.h"

class CServerConn
{
private:

public:
	SOCKET hConnectionSocket;
	DWORD WINAPI ConnectionThread();
};
