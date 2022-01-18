# PHILOSOPHERS

Description:
> In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.


42's take on the classic [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). The mandatory part was done using the phtread API to execute n numbers of threads at once that eat, sleep, then start eating again. Mutex was used to manage the limited resources available.
Given the right parameters (e.g. `4 410 200 200`), philosophers keep repeating their cycle virtually forever, unless a maximum number of times each philosophers must eat before the simulation ends.

```
n_philosophers time_before_death time_eat time_sleep (time_eats)
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
One of the possible outputs 
```
0 4 has taken a fork
0 4 has taken a fork
0 4 is eating
0 2 has taken a fork
0 2 has taken a fork
0 2 is eating
200 4 is sleeping
200 1 has taken a fork
200 1 has taken a fork
200 1 is eating
200 3 has taken a fork
200 3 has taken a fork
200 3 is eating
200 2 is sleeping
```
