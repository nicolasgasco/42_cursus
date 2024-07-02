# dslr

> In this Data Science project, you will implement a linear classification model: a logistic regression.
>
> Summarizing:
>
> - You will learn how to read a data set, to visualize it in different ways, to select and
  clean unnecessary information from your data.
> - You will train a logistic regression that will solve classification problem.


The aim of the project is creating a predictive model that works like Harry Potter's Sorting Hat: it predicts the House for new Hogwarts students based on their scores. (Which scores, if they're new students? Anyway...).

<img width="300" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/e053404f-5fe5-4c4e-8947-64a60cf63724" />

## Dataset
The given data set includes 1600 data points with the following shape:
| Index | Hogwarts House | First Name | Last Name | Birthday   | Best Hand | Arithmancy | Astronomy          | Herbology         | Defense Against the Dark Arts | Divination | Muggle Studies     | Ancient Runes       | History of Magic | Transfiguration     | Potions           | Care of Magical Creatures | Charms     | Flying |
|-------|----------------|------------|-----------|------------|-----------|------------|--------------------|-------------------|-------------------------------|------------|--------------------|---------------------|------------------|----------------------|-------------------|---------------------------|------------|--------|
| 0     | Ravenclaw      | Tamara     | Hsu       | 2000-03-30 | Left      | 58384.0    | -487.88608595139016 | 5.727180298550763 | 4.8788608595139005            | 4.7219999999999995 | 272.0358314131986 | 532.4842261151226   | 5.231058287281048 | 1039.7882807428462 | 3.7903690663529614 | 0.7159391270136213         | -232.79405 | -26.89 |

## Data visualization
- Score distribution for each subject through histograms:

  <img width="400" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/519e70a6-a099-464f-af7b-431a5e5fdeaa" />
- Similarity between subjects through a pair plot:

  <img width="1000" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/add49ae9-c384-42a2-a14b-9bd0c5777373" />

## Multi-classifier
In order to predict the House of each student, the model is trained to compute a:
- one-vs-all logistic regression: the probability is computed for each possible Hogwarts House
- with gradient descent: weigths and bias are tweaked iteratively until convergence is reached.

This is a visualization of how the multi-classifier works with two and three features:
|Two features|Three features|
|------------|--------------|
|![logistic_regression_2d](https://github.com/nicolasgasco/42_cursus/assets/73175085/452ef314-80e6-4709-84c8-b2a043793195)|![logistic_regression_3d](https://github.com/nicolasgasco/42_cursus/assets/73175085/303ffa8a-57d2-4363-921d-5ba2cb7cf42c)|

## Usage
A first program trains the model:

<img width="800" alt="Screenshot 2024-07-01 at 19 58 11" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/663f8b85-b3bd-40dc-9ba5-7167db9416bd">

A second program makes the predictions:
<img width="800" alt="Screenshot 2024-07-01 at 19 59 29" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/4fa61fd6-075e-4aec-a2e9-cee0dfe413f3">

Accuracy is computed with a provided script (not included in this repo):
<img width="500" alt="Screenshot 2024-07-01 at 20 00 22" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/353f918e-3d22-4495-918d-84b9428a4bd1">

