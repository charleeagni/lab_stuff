#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <iostream>
#include<sys/types.h>
#include<sys/stat.h>
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[]) {
  int pipe_fd;
  char buffer[BUFFER_SIZE + 1];

  // check if appropreate args are passes
  if (argc != 2) {
    std::cout << "imroper call" << '\n';
    return -1;
  }

  // trying to open the file
  if ((pipe_fd = open(argv[1],O_WRONLY)) != -1) {
    std::cout << "enter data:" << '\n';
    gets(buffer);

    if ((write(pipe_fd,buffer,BUFFER_SIZE)) != -1) {
      std::cout << "successfuly written into the file by pid " << getpid() << '\n';
      close(pipe_fd);
    }
    else{
      std::cout << "error while writing into the file" << '\n';
      return -1;
    }
  }
  else{
    std::cout << "error while opening the file" << '\n';
  }

  return 0;
}
