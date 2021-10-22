# MINITALK

Description:
>  The purpose of this project is to code a small data exchange program using UNIX signals.

## Run the scripts

Follow these instruction to see the project in action.

### Any OS able to compile C
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
Read the PID from server and pass it as parameter along with a string of your choice.
### Client
```
./client PID STRING
```
Script works at best with strings below 1000 characters.
