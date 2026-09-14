#include <sys/types.h>
#include<sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#define MAX_TEXT 100
struct my_msg{
    long int msg_type;
    char some_text[MAX_TEXT];
};
int main(){
    int i=1, msgid;
    struct my_msg some_data;
    char buf[20];
    msgid=msgget((key_t)150504, 0666|IPC_CREAT);
    if(msgid==-1){
        printf("Error in creating queue.\n");
    }
    while(i){
        printf("Enter message: ");
        fgets(buf, 20, stdin);
        some_data.msg_type=1;
        strcpy(some_data.some_text, buf);
        if(msgsnd(msgid, (void*)&some_data, MAX_TEXT, 0)==-1){
            printf("Message not sent.\n");
        }
        else{
            printf("\nMessage sent successfully.\n");
        }
        if(strncmp(buf, "end", 3)==0){
            i=0;
            printf("Exiting.\n");
        }
    }
}
