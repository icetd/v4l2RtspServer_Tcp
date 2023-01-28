#ifndef RTSP_SERVER_H
#define RTSP_SERVER_H

#include <iostream>

#define RECVMAXSIZE 1024
#define SENDMAXSIZE 1024
#define RTSP_SERVER_PORT 8554

#define SERVER_RTP_PORT 55532
#define SERVER_RTCP_PORT 55533


class RtspServer {
public:
	RtspServer(const char *ip, int port);
	virtual ~RtspServer();
	
	char client_ip[50];
	
	int initialize();
	int createTcpSocket();
	int bindSocketAddr();
	int acceptClient();

	void Run();

	static int handleCmd_OPTIONS(char *result, int cseq);
	static int handleCmd_DESCRIBE(char *reult, int cseq, char *url);
	static int handleCmd_SETUP(char *result, int cseq, int clientRtpPort);
	static int handleCmd_PLAY(char *result, int cseq);
	static void thr_play(char *deviceName, char *client_ip, int client_fd, int &serverRtpSockfd, int &serverRtcpSockfd,  int clientRtpPort, int clientRtcpPort);
private:

	int m_sockfd;
	int serverRtpSockfd;
	int serverRtcpSockfd;
	char *m_ip;
	int m_port;
	
	int client_fd = -1;
	int client_port;
};

#endif
