# PUSH_SWAP

Description:
> This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

The two available stacks were managed with linked lists and the numbers were sorted using the Radix algorithm and bitwise operations. The output of the program is the list of movement necessary to sort the numbers.

![Screenshot of completed project](https://res.cloudinary.com/ngasco/image/upload/v1635067508/42/Screenshot_from_2021-10-24_11-22-56_mfbq1j.png "Screenshot of Minitalk")
## Run the scripts

Follow these instruction to see the project in action.

### UNIX
Clone the repo and open the corresponding folder
```
➜ git clone https://github.com/nicolasgasco/42_cursus.git
➜ cd 42_cursus/
➜ cd 08_push_swap/
```
Compile the program
```
make
```
Sort an array of integers without repetitions of your choice
```
ARG="-755254759 46382822 168313279 -712408378 -976005565 532734670 -658929270 -846861339"; ./push_swap $ARG
```
Expected output
```
ra
pb
ra
pb
ra
pb
ra
pb
pa
pa
pa
pa
ra
pb
pb
ra
ra
ra
pb
pb
pa
pa
pa
pa
ra
pb
pb
ra
ra
pb
pb
ra
pa
pa
pa
pa
ra
```
