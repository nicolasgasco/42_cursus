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
```shell
docker compose up
docker exec -it python bash

# Inside container
cd ft_linear_regression/
python3 app/main.py

# When prompted, insert a mileage value to get a price prediction
```
