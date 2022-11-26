# Inception
> This project aims to broaden your knowledge of system administration by using Docker.
You will virtualize several Docker images, creating them in your new personal virtual
machine.

This project consists in having you set up a small infrastructure composed of different services under specific rules: mariadb, Wordpress, and nginx as reverse proxy.

<img width="550" alt="Screen Shot 2022-11-26 at 2 58 46 PM" src="https://user-images.githubusercontent.com/73175085/204092508-81c52dea-60bc-431d-a758-0e809e121f61.png">

## Run
Create a VM with a user called `ngasco` (`/home/ngasco` folder is required`).
Add `127.0.0.1  ngasco.42.fr` in `/etc/hosts`. That is the domain name that the project expects to work correctly.

Then, download the project folder and inside run:
```
make inception
```
Visit `https://ngasco.42.fr` on your browser and ignore the warning that the certificate is self-signed.

## Screenshots
![Screenshot 2022-11-14 at 21 36 49](https://user-images.githubusercontent.com/73175085/201761476-19de6ab5-e493-430e-91a8-cc8fecbf8d98.png)

![Screenshot 2022-11-14 at 21 36 56](https://user-images.githubusercontent.com/73175085/201761554-883fdd43-dc84-4e65-a463-d0844cad1d36.png)

![Screenshot 2022-11-14 at 21 41 09](https://user-images.githubusercontent.com/73175085/201761565-032f1dcb-e4aa-4432-8a2f-d73423fbe4e8.png)
