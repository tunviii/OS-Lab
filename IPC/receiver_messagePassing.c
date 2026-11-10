#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MAX_TEXT 100

struct my_msg{
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main(){
    int i=1, msgid;
    struct my_msg some_data;
    long int msg_to_rec=0;

    msgid=msgget((key_t)150504, 0666|IPC_CREAT);

    if(msgid==-1){
        printf("Error in creating queue.\n");
    }

    while(i){
        msgrcv(msgid, (void*)&some_data, MAX_TEXT, msg_to_rec, 0);

        printf("Data received: %s", some_data.some_text);

        if(strncmp(some_data.some_text, "end", 3)==0){
            i=0;
        }
    }
}
