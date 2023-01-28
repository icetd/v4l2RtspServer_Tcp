#include <log.h>
#include <RtspServer.h>

#define RTSP_PORT 8554

int LogLevel;

int main()
{	
	initLogger(NOTICE);
	RtspServer *server = new RtspServer("0.0.0.0", RTSP_PORT);
	LOG(NOTICE, "rtsp://127.0.0.1:%d/video<*>", RTSP_PORT);
	
	while (1)
	{
		server->acceptClient();
		server->Run();
	}

	LOG(INFO, "=============test=============");
	return 0;
}
