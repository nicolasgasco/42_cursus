# Multilayer Perceptron

The goal of this project is to give you a first approach to artificial neural networks,
and to have you implement the algorithms at the heart of the training process.

In the language of your choice you are going to implement a multilayer
perceptron, in order to predict whether a cancer is malignant or benign on a dataset of
breast cancer diagnosis in the Wisconsin.

> The multilayer perceptron is a feedforward network (meaning that the data
> flows from the input layer to the output layer) defined by the presence of one or more
> hidden layers as well as an interconnection of all the neurons of one layer to the next.
> 
> <img width="500" alt="Screenshot 2024-06-22 at 16 27 39" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/682f245c-7359-4059-92a3-fffd3205d79d">

## Dataset
The dataset is a csv file of 32 columns, the column diagnosis being the label you want to learn given all the other features of an example,
it can be either the value M or B (for malignant or benign).
The features of the dataset describe the characteristics of a cell nucleus of breast mass extracted with fine-needle aspiration.

### Feature selection based on data visualization
- Histograms

  <img width="750" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/9c8b9d7d-1003-4d91-b761-57af9a267ea8" alt=""/>

  Features with the least overlap: 2, 4, 5, 8, 9, 22, 24, 25, 29.
- Pair plot

  <img width="750" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/3ce826eb-b265-4a63-bb22-668e29e18f60" alt=""/>

  Feature couples with too much correlation (pick one, not both): `4,2`, `5,2`, `5,4`, `24,22`, `25,22`, `25,24`  
- Correlation matrix

  <img width="600" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/54cebfd1-e7fa-4c9e-9640-69e513c49300" alt=""/>

  Feature couple with too much correlation (pick one, not both): `2,4`, `2,5`, `2,22`, `2,24`, `2,25`, `3,23`, `4,2`, `4,5`, `4,22`, `4,24`, `4,25`, `5,2`, `5,4`, `5,22`, `5,24`, `5,25`...
