#include<stdio.h>
#define MAXN 20020

long C, N;
long avaliable, sleep;

struct request{
    long id;
    long num;
    int is_sleep;
};
struct request request_queue[MAXN];
long request_size = 0;

struct request sendout_record[MAXN];
long sendout_size=0;

void delete_sendrecord(long index){
    long i;
    for(i=index; i<sendout_size-1; i++){
        sendout_record[i] = sendout_record[i+1];
    }
    sendout_size--;
}

void delete_reqrecord(long index){
    long i;
    for(i=index; i<request_size-1; i++){
        request_queue[i] = request_queue[i+1];
    }
    request_size--;
}

long send(long a, long b){

    if(b>C){
        if(avaliable == C){
            /*if all plane in base, update base*/
            C = b;
            /*send successful*/
            sendout_record[sendout_size].id = a;
            sendout_record[sendout_size].num = b;
            sendout_record[sendout_size].is_sleep = 0;
            sendout_size++;
            avaliable = 0;
            return b;
        }else{
            /*if not all plane in base, and plane not enough*/
            /*send failed*/
            request_queue[request_size].id = a;
            request_queue[request_size].num = b;
            request_size++;
            return 0;
        }
    }else{
        if(avaliable >= b){
            /*send successful*/
            sendout_record[sendout_size].id = a;
            sendout_record[sendout_size].num = b;
            sendout_record[sendout_size].is_sleep = 0;
            sendout_size++;
            avaliable -= b;
            return b;
        }else{
            /*send failed*/
            request_queue[request_size].id = a;
            request_queue[request_size].num = b;
            request_size++;
            return 0;
        }
        
    }
}

void back(long b){
    long i, still_out = 0;
    /*traverse the record in sendout_record*/
    for(i=0; i<sendout_size; i++){
        if(sendout_record[i].id!=b){
            /*if there's no earlier plane at out*/
            if(sendout_record[i].is_sleep==1 && still_out==0){
                avaliable += sendout_record[i].num;
                delete_sendrecord(i);
                i--;
            }else if(sendout_record[i].is_sleep==0){
                still_out = 1;
            }
        }else{
            /*if there's still earlier plane at out*/
            if(still_out == 1){
                sendout_record[i].is_sleep = 1;
            }else{
                /*if there's no earlier plane at out*/
                avaliable += sendout_record[i].num;
                delete_sendrecord(i);
                i--;
            }
        }
    }
    /*handle the pending request*/
    long send_sum = 0;
    for(i=0; i<request_size; i++){
        if(avaliable == C || avaliable >= b){
            send_sum += send(request_queue[i].id, request_queue[i].num);
            delete_reqrecord(i); i--;
        }else{
            break;
        }
    }
    printf("%ld\n", send_sum);
}


int main(){

    long  i, a, b;
    scanf("%ld %ld", &C, &N);
    avaliable = C; sleep = 0;

    for(i=0; i<N; i++){
        scanf("%ld %ld", &a, &b);
        /*if this is a send request, send b plane*/
        if(a>=0){
            printf("%ld\n", send(a, b));
        }else{
            back(b);
        }
    }


    return 0;
}