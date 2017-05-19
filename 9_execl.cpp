#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

void sys(const char *cmd) {
  int pid = fork();
  if(pid<0){
    std::cout << "error while forking" << '\n';
    exit(-1);
  }
  if (pid == 0) {
    execl("/bin/bash" ,"bash" ,"-c" ,cmd ,NULL );
  }
  else{
    waitpid(pid,NULL,0);
  }
}

int main(int argc, char const *argv[]) {
  for (int i = 1; i < argc; i++) {
    std::cout << "executing command " << argv[i] <<'\n';
    sys(argv[i]);
  }
  return 0;
}
