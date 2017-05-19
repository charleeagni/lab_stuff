#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

static void print_stuff(char *str) {
  char *ptr;
  int c;

  setbuf(stdout, NULL);
  for (ptr = str; (c = *ptr++) != 0;)
    putc(c, stdout);
}

int main(int argc, char const *argv[]) {
  int pd;
  if((pd = fork()) == -1) {
    std::cout << "error while forking" << '\n';
    return -1;
  }
  else if(pd >0) {
    print_stuff("child process\n");
  }
  else{
    print_stuff("parent is calling\n");
  }
  _exit(0);
}
