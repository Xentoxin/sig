#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void signa(int sig){
  if(sig == SIGINT){
    printf("interruption");
    exit(1);
  }
  if(sig == SIGUSR1){
    printf("Parent Process ID : %d\n", get ppid());
  }
}
int main(){
  signal(SIGINT, signa);
  signal(SIGUSR1, signa);
  while(1){
    sleep(1);
    printf("Process ID : %d\n", getpid());
  }
}
