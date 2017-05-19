#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>

int main(int argc, char const *argv[]) {
  // check if the number of files provided is right
  if (argc != 3) {
    std::cout << "improper file types" << '\n';
    return -1;
  }
  // try linking th files
  if ((link(argv[1],argv[2])) == -1) {
    std::cout << "error while linking" << '\n';
    return -1;
  }
  else{
    std::cout << "successfuly linked" << '\n';
    std::cout << "printing the Inode numbers of the linked files" << '\n';

    char buff[100];
    sprintf(buff,"ls -i1 %s %s",argv[1],argv[2]);
    system(buff);
  }
  return 0;
}
