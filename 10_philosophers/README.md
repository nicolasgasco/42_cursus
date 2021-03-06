# PHILOSOPHERS

Description:
> In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.


42's take on the classic [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). The mandatory part was done using the phtread API to execute n numbers of threads at once that eat, sleep, then start eating again. Mutex was used to manage the limited resources available.
Given the right parameters, philosophers keep repeating their cycle virtually forever, unless a maximum number of times each philosopher must eat before the simulation ends is given.
Examples:

```
n_philosophers  time_before_death time_eat  time_sleep  [time_eats]
4 410 200 200
5 800 200 200 5
```

Here's an example (first number is timestamp in milliseconds):
![Screenshot of completed project](https://res.cloudinary.com/ngasco/image/upload/v1639432723/42/Screenshot_from_2021-12-13_22-57-45_jy9pa7.png "Screenshot of Philosophers")
## Run the scripts

Follow these instruction to see the project in action.

### UNIX
Clone the repo and open the corresponding folder
```
➜ git clone https://github.com/nicolasgasco/42_cursus.git
➜ cd 42_cursus/
➜ cd 10_philosophers/
```
Compile the program
```
make
```
Execute program with parameters: `n_philosophers time_before_death time_eat time_sleep [numbers_of_eats]` (last parameter is optional)
```
./philo 4 410 200 200 1
```
Expected output:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 3 is sleeping
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 4 has taken a fork
200 4 has taken a fork
200 4 is eating
200 2 is eating
```
