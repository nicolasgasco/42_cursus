# ft_linear_regression

The aim of this project is to introduce you to the basic concept behind machine learning.
For this project, you will have to create a program that predicts the price of a car by
using a linear function train with a gradient descent algorithm.

Given a data set with 25 data points, linear regression is computed:

<img src="https://github.com/nicolasgasco/42_cursus/assets/73175085/355159d8-5fbf-45b0-86d5-793425463d15" width="500" />

The use of library that do the heavy lifting in computing linear regression (e.g. python's `numpy.polyfit`) is forbidden.

## Features
- Computation of linear regression with a gradient descent algorithm
- Creation of a plot that visualize both data and linear regression
- Measurement of prediction accuracy

## Execution

Start Docker container:
```shell
docker compose up -d
```

Access Docker container:
```shell
sh access_docker_container.sh
```

Inside container:
```shell
cd ft_linear_regression/app/
```

Train model:

<img width="500" alt="Screenshot 2024-06-30 at 21 52 37" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/912b42b9-db87-4618-ab9f-d212be471752">


Launch prediction program:

<img width="500" alt="Screenshot 2024-06-30 at 21 53 48" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/db1d24db-ada2-4be7-9c42-5a24db94c337">
