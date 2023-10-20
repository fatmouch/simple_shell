# S I M P L E   S H E L L

## presentation: 🚀

The simple shell project is a collaboration between me and my partner, Software Engineering students , with which we can emulate the operation of a shell, which contains some of its most basic characteristics, such as : Handle `PATH`, Handle command lines with `arguments`.

## this project was done by :
**dahenane fatma zohra** & **melloud mohamed nassim**
List of allowed functions and system calls
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
## Testing:
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
## List of TASKS to be completed below:

Betty would be proud Write a beautiful code that passes the Betty checks

Simple shell 0.1 Write a UNIX command line interpreter.

Usage: simple_shell Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line. The prompt is displayed again each time a command has been executed. The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features. The command lines are made only of one word. No arguments will be passed to programs. If an executable cannot be found, print an error message and display the prompt again.

Simple shell 0.2 Simple shell 0.1 +
Handle command lines with arguments

Simple shell 0.3 Simple shell 0.2 +
Handle the PATH fork must not be called if the command doesn’t exist

Simple shell 0.4 Simple shell 0.3 +
Implement the exit built-in, that exits the shell Usage: exit You don’t have to handle any argument to the built-in exit

Simple shell 1.0 Simple shell 0.4 +
Implement the env built-in, that prints the current environment

Simple shell 0.1.1 Simple shell 0.1 +
Write your own getline function Use a buffer to read many chars at once and call the least possible the read system call You will need to use static variables You are not allowed to use getline

Simple shell 0.2.1 Simple shell 0.2 +
You are not allowed to use strtok

Simple shell 0.4.1 Simple shell 0.4 +
handle arguments for the built-in exit Usage: exit status, where status is an integer used to exit the shell

setenv, unsetenv Simple shell 1.0 +
Implement the setenv and unsetenv builtin commands

setenv Initialize a new environment variable, or modify an existing one Command syntax: setenv VARIABLE VALUE Should print something on stderr on failure unsetenv Remove an environment variable Command syntax: unsetenv VARIABLE Should print something on stderr on failure

cd Simple shell 1.0 +
Implement the builtin command cd:

Changes the current directory of the process. Command syntax: cd [DIRECTORY] If no argument is given to cd the command must be interpreted like cd $HOME You have to handle the command cd - You have to update the environment variable PWD when you change directory man chdir, man getcwd

; Simple shell 1.0 +
Handle the commands separator ;

&& and || Simple shell 1.0 +
Handle the && and || shell logical operators
