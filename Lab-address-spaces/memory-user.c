#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
        int t = atoi( argv[1]) *1e6; 
        char *p = malloc(t);
    if(argc==2){
        for(int i = 0; i < t; i++){
            *(p + i) = 'a';
            if(i==(t-1)){
                i=0;
            }
        } 
    }else if(argc==1){
        return 0;
    }else{
        int pid = fork();
        if( pid == 0) {
            // Codigo hijo
            for(int i = 0; i < t; i++){ 
            *(p + i) = 'a';
                if(i==(t-1)){
                    i=0;
                }
            } 
        } else {
            // Codigo padre
            sleep(atoi( argv[2]));
            kill(pid, SIGKILL);            
        }
    }      
    
    return 0;
}