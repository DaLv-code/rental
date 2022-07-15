#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>

#define BUF_SIZE 1024
using namespace std;

void *handle_clnt(void *arg);
void error_handling(const char *msg);
int clnt_cnt = 0;
int sockList[5];
int serverList;

pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock, str_len;
    char msg[BUF_SIZE];
    struct sockaddr_in serv_adr, clnt_adr;
    unsigned int clnt_adr_sz;
    pthread_t t_id;

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutx, NULL); //뮤텍스 정의
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    while (1)
    {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

        pthread_mutex_lock(&mutx);
        read(clnt_sock, msg, sizeof(msg));
        if(strcmp(msg,"server")==0)   
        {
            serverList=clnt_sock;  
            cout<<"서버입니다"<<endl;
        }                          
        else if(strcmp(msg,"client")==0)
            cout<<"클라이언트 입니다"<<endl;
            
        sockList[clnt_cnt++]=clnt_sock;
        pthread_mutex_unlock(&mutx);

        printf("현재 연결된 인원수 : %d\n", clnt_cnt);
        printf("클라이언트 IP : %s\n", inet_ntoa(clnt_adr.sin_addr));
        printf("클라이언트 소켓 : %d번\n\n", clnt_sock);

        pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock); //클라이언트에서 정보를 받는 쓰레드
        pthread_detach(t_id);
    }
    close(serv_sock);

    return 0;
}

void *handle_clnt(void *arg)
{
    int clnt_sock = *((int *)arg);
    int str_len = 0;
    char msg[BUF_SIZE];
    int read_len;
             
    while(read_len=read(clnt_sock, msg, sizeof(msg)))
    {        
        if(read_len==-1)
        {
            for(int i=0; i<clnt_cnt; i++)
                {
                    if(sockList[i]==clnt_sock)                    
                        sockList[i]=0;                    
                }
        }
        if(read_len>0) 
        {
            cout<<"메세지"<<msg<<endl;        
            if(strcmp(msg,"request")==0)
            {
                write(serverList, "chatting", sizeof("chatting"));  
            }
            else
            {
                for(int i=0; i<clnt_cnt; i++)
                {
                    if(sockList[i]!=clnt_sock && sockList[i]!=0)
                    {
                        write(sockList[i], msg, sizeof(msg));
                    }
                }
            }            
            memset(msg, 0, sizeof(msg)); 
        }        
    }    
}

void error_handling(const char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}