#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int pd;

  // 1: Maximum number of child processes
  if((pd = sysconf(_SC_CHILD_MAX)) != -1){  // the sysconf() returns -1 if there is an error
    std::cout << "// 1: Maximum number of child processes: "<<pd << '\n'; // print value if found
  }
  else{
    std::cout << "error generated" << '\n';
  }


  // 2: Maximum clock ticks : _SC_CLK_TCK

  if((pd = sysconf(_SC_CLK_TCK)) != -1){  // the sysconf() returns -1 if there is an error
    std::cout << "// 2: Maximum clock ticks: "<<pd << '\n'; // print value if found
  }
  else{
    std::cout << "error generated" << '\n';
  }


  // 3: maximum path length

  if((pd = pathconf("/",_PC_PATH_MAX)) != -1){  // pathconf() takes path as first parameter
  //               --^--     --> don't mess this up with single quotes
    std::cout << "// 3: maximum path length: "<<pd << '\n'; // print value if found
  }
  else{
    std::cout << "error generated" << '\n';
  }

  // 4: Maximum length of fileNAME
  if((pd = pathconf("/",_PC_NAME_MAX)) != -1){  // the sysconf() returns -1 if there is an error
    std::cout << "// 4: Maximum length of fileNAME: "<<pd << '\n'; // print value if found
  }
  else{
    std::cout << "error generated" << '\n';
  }

  // 5: maximum number of files that can be opened
  if((pd = sysconf(_SC_OPEN_MAX)) != -1){  // the sysconf() returns -1 if there is an error
    std::cout << "// 5: maximum number of files that can be opened: "<<pd << '\n'; // print value if found
  }
  else{
    std::cout << "error generated" << '\n';
  }

  return 0;
}
