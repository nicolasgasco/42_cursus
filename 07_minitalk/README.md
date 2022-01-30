# MINITALK

Description:
> The purpose of this project is to code a small data exchange program using UNIX signals.  
  
A server listens for signals (SIGUSR1 and SIGUSR2) emitted by a client. The client receives a string as a parameter, converts it into binary with bitwise operations, and sends it to the server in form of 0s (SIGUSR1) and 1s (SIGUSR2). The server receives the signals and convert them back to a string, which is then outputted in the console.

![Screenshot of completed project](https://res.cloudinary.com/ngasco/image/upload/v1635067508/42/Screenshot_from_2021-10-24_11-22-56_mfbq1j.png "Screenshot of Minitalk")
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
- **Server**
  ```
  ./server
  ```
- **Client**
  Read the PID from server and pass it as parameter along with a string of your choice.
  ```
  ./client PID "Example string"
  ```
Script works at best with strings below 1000 characters.
