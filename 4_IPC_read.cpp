#include <stdio.h>
#include "iostream"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

using namespace std;
#define BUFFER_SIZE PIPE_BUF

int main(int argc, char const *argv[]) {
  int pipe_fd, res = 0;
  char buffer[BUFFER_SIZE +1];

  // stop process if improper number of files are specified as args

  if (argc != 2) {
    std::cout << "improper useage" << '\n';
    return -1;
  }

  // try to open the pipe buffer file
  if (pipe_fd = open(argv[1],O_READONLY) != -1) {
    res = read(pipe_fd,buffer,BUFFER_SIZE);
    std::cout << "file contents are: " << buffer <<'\n';
  }
  else{
    std::cout << "error wile opening the pipe buffer file" << '\n';
    return -1;
  }
  std::cout << "finished reading by pid " << getpid() << '\n';
  return 0;
}
