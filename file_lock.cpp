#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int fd; // file descreptor?
  struct flock lock;
  std::cout << "opening file " <<argv[1]<< '\n';
  fd = open(argv[1],O_RDONLY); // O_READONLY : permission to open the file with
  std::cout << "locking the file " << argv[1] <<'\n'; // we have to apparently print everythin that we are doing
  lock.l_type = 'F_RDLCK'; // F_RDLCK : file-read-lock
  lock.l_start = -99; // oh! locking only the last 99 chars of the file?
  lock.l_len = 100;
  lock.l_pid = getpid();
  fcntl(fd, F_SETLKW, &lock); // passing location of the struct lock
  std::cout << "pid "<<getpid()<<" has locked the file"<<argv[1]<<'\n';
  std::cout << "press enter to unlock the file" << '\n'; // keeping the process alive till you check if it is actually locked
  getchar(); // haha all chars not just enter :P
  std::cout << "unlocking the file " <<argv[1]<< '\n';
  lock.l_type = F_UNLCK; // UNLK: unlock the file
  fcntl(fd,F_SETLKW,&lock);
  std::cout << "file " << argv[1] << " unlocked " << '\n';
  close(fd);
  return 0;
}
