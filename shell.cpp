/****************
LE1: Introduction to Unnamed Pipes
****************/
#include <unistd.h> // pipe, fork, dup2, execvp, close
using namespace std;

int main () {
    // lists all the files in the root directory in the long format
    char* cmd1[] = {(char*) "ls", (char*) "-al", (char*) "/", nullptr};
    // translates all input from lowercase to uppercase
    char* cmd2[] = {(char*) "tr", (char*) "a-z", (char*) "A-Z", nullptr};

    // TODO: add functionality
    // Create pipe

    // Create child to run first command
    // In child, redirect output to write end of pipe
    // Close the read end of the pipe on the child side.
    // In child, execute the command

    // Create another child to run second command
    // In child, redirect input to the read end of the pipe
    // Close the write end of the pipe on the child side.
    // Execute the second command.

    // Reset the input and output file descriptors of the parent.


   //save original stdin and stdout
   dup(0); //stdin is now at 3
   dup(1); //stdout is now at 4

   //creating pipe
    int pfd[2];
    pipe(pfd);
    int pro1 = fork();
    if(pro1 == 0){
        dup2(pfd[1],1);
        close(pfd[0]);
        execvp("ls",cmd1);
    }
    int pro2 = fork();
    if(pro2 == 0){
        dup2(pfd[0],0);
        close(pfd[1]);
        execvp("tr",cmd2);
    }
    
    //overrwite in/out with saved
    dup2(0,3);
    dup2(1,4);

}