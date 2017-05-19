#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  int fd; // file descreptor?
  struct flock lock;
  char buff[100]; // hold the locked content
  std::cout << "opening file " <<argv[1]<< '\n';
  fd = open(argv[1],O_RDONLY); // O_READONLY : permission to open the file with


  // this might be stupid
  // doubt you need to set these things when you are gettin the locked contents
  // I'm gonna do it anyways to see if it is really nesscary

  lock.l_type = 'F_WRLCK'; // F_RDLCK : file-read-lock
  lock.l_start = -99; // oh! locking only the last 99 chars of the file?
  lock.l_len = 100;
  lock.l_pid = getpid();
  std::cout << "checking the lock status of the file" << '\n';
  printf("Trying to get lock...\n");
  if ((fcntl(fd, F_SETLKW, &lock)) == -1) {
    fcntl(fd, F_GETLK, &lock);
    printf("\nFile already locked by Process ID: %d\n", lock.l_pid);
    return -1;
  }
  fcntl(fd,F_SETLK,&lock);
  std::cout << "pring the lock status" << '\n';

  if(lock.l_type == F_UNLCK){
      std::cout << "file is unlocked" << '\n';
      std::cout << "reading the last 50bytes from the file" << argv[1] << '\n';
      lseek(fd,-99,SEEK_END);
      int num = read(fd,buff,50);
      buff[num] = '\0';
      std::cout << "last 50 chars are:" << '\n'<< buff;
      std::cout << "byee :*" << '\n';
  }
  else {
    if (lock.l_type == F_WRLCK) {
      std::cout << "file is \"F\" locked" << '\n';
    }
    else {
      std::cout << lock.l_type << '\n';
      std::cout << F_RDLCK << '\n';
      std::cout << "file is \"R\" locked" << '\n';
    }
  }

  close(fd);
  return 0;
}
