# MINITALK

Description:
>  The purpose of this project is to code a small data exchange program using UNIX signals and bitwise operations.
A server listens for signals (SIGUSR1 and SIGUSR2) emitted by a client. The client receives a string as a parameter, converts it into binary, and sends it to the server in form of 0s (SIGUSR1) and 1s (SIGUSR2). The server receives the signals and convert them back to a string, which is then outputted in the console.

## Run the scripts

Follow these instruction to see the project in action.

### UNIX
Clone the repo and open the corresponding folder
```
➜ git clone https://github.com/nicolasgasco/42_cursus.git
➜ cd 42_cursus/
➜ cd 07_minitalk/
```
Compile the programs
```
make all
```
Execute in two separate terminal tabs.
### Server
```
./server
```
### Client
Read the PID from server and pass it as parameter along with a string of your choice.
```
./client PID STRING
```
Script works at best with strings below 1000 characters.
