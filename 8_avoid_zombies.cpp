#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[]) {
  int pr;
  if((pr = fork()) <0){
    std::cout << "error while forking" << '\n';
    return -1;
  }
  else if(pr > 0){
    std::cout << "child" << '\n';
    sleep(2);
    system("ps -o pid,ppid,tty,state,command");
  }
  else{
    sleep(5);
    std::cout << "parent created" << '\n';
    _exit(0);
  }

  return 0;
}
