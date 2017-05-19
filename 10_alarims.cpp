#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <signal.h>

#define INTERVAL 2

void callme(int some_val) {
  std::cout << "alarm signal called and handled" << '\n';
}

int main(int argc, char const *argv[]) {
  struct sigaction action;
  action.sa_handler = callme;

  sigaction(SIGALRM, &action, 0);

  alarm(INTERVAL);
  sleep(INTERVAL);

  return 0;

}
