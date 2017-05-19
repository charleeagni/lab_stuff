#include<stdio.h>
#include <unistd.h>
#include<iostream>

int main(int argc, char const *argv[]) {
  char **ptr;
  char extern **environ;
  for (ptr = environ; *ptr; ptr++) {
    std::cout << *ptr << '\n';
  }

  return 0;
}
