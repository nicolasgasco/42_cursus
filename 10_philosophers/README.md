# PHILOSOPHERS

Description:
> In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex.


42's take on the classic [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). The mandatory part was done using the phtread API to execute n numbers of threads at once that eat, then sleep, then start eating again. Mutex was used to manage the limited resources availables. Given the right parameters (e.g. 5 800 200 200), philosophers keep repeating their cycle basically infinitely.

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
Execute program with parameters: n_philosophers time_before_death time_eat time_sleep [numbers_of_eats] (last parameter is optional)
```
./philo 4 410 200 200 1
```
Expected output
```
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 3 is sleeping
200 4 has taken a fork
200 4 has taken a fork
200 4 is eating
400 3 is thinking
400 4 is sleeping
400 1 has taken a fork
400 1 has taken a fork
400 1 is eating
600 4 is thinking
600 1 is sleeping
600 2 has taken a fork
600 2 has taken a fork
600 2 is eating
```
