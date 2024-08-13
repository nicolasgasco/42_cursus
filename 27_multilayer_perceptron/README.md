# Multilayer Perceptron

This project is a first approach to artificial neural networks.

It implements a multilayer perceptron in order to predict whether a cancer is malignant or benign on a real-life dataset of breast cancer diagnosis.

> The multilayer perceptron is a feedforward network (meaning that the data
> flows from the input layer to the output layer) defined by the presence of one or more
> hidden layers as well as an interconnection of all the neurons of one layer to the next.
> 
> <img width="400" alt="Screenshot 2024-06-22 at 16 27 39" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/682f245c-7359-4059-92a3-fffd3205d79d">

## Dataset
The dataset is a csv file of 32 columns, the column diagnosis being the label you want to learn given all the other features of an example,
it can be either the value M or B (for malignant or benign).
The features of the dataset describe the characteristics of a cell nucleus of breast mass extracted with fine-needle aspiration.

## Feature selection based on data visualization
- Histograms

  <img width="500" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/9c8b9d7d-1003-4d91-b761-57af9a267ea8" alt=""/>

  Features with the least overlap: 2, 4, 5, 8, 9, 22, 24, 25, 29.
- Pair plot

  <img width="500" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/3ce826eb-b265-4a63-bb22-668e29e18f60" alt=""/>

  Feature couples with too much correlation (pick one, not both): `4,2`, `5,2`, `5,4`, `24,22`, `25,22`, `25,24`  
- Correlation matrix

  <img width="400" src="https://github.com/nicolasgasco/42_cursus/assets/73175085/54cebfd1-e7fa-4c9e-9640-69e513c49300" alt=""/>

  Feature couple with too much correlation (pick one, not both): `2,4`, `2,5`, `2,22`, `2,24`, `2,25`, `3,23`, `4,2`, `4,5`, `4,22`, `4,24`, `4,25`, `5,2`, `5,4`, `5,22`, `5,24`, `5,25`...

## Configuration files
`split.json` can be used to configure the percentage of the data set that should be dedicated to validation, i.e. for evaluating the model's performance.
```javascript
// 27_multilayer_perceptron/app/settings/split.json
{
  "validation_percentage": 20
}
```

`train.json` can be used to fully customize the model, e.g. the number of hidden layers and neurons per hidden layers:
```javascript
// 27_multilayer_perceptron/app/settings/train.json
{
  "activation_function": "relu",
  "batch_size": 64,
  "epochs": 50,
  "frontend_data": true,
  "hidden_layer_neurons": 50,
  "hidden_layers": 2,
  "inputs_columns": [24, 29, 4, 8, 9],
  "learning_rate": 0.01,
  "outputs": ["M", "B"],
  "outputs_column": "1",
  "plot_loss": true
}
```

## Usage
run `access_app.sh` to run all containers and access the container where the model runs.

Inside the container, run:
- `python3 multilayer_perceptron/app/split.py` to split the data set
- `python3 multilayer_perceptron/app/train.py` to train the model
  <br/><img width="600" alt="Screenshot 2024-08-13 at 19 20 59" src="https://github.com/user-attachments/assets/bf74a863-d001-488c-ba17-ab585d69b54b">
- `python3 multilayer_perceptron/app/predict.py` to run the predictions on the validation data set

## Front-End interface
<img width="750" src="https://github.com/user-attachments/assets/14870980-af94-49f5-a4a0-2d813f6ce010" />

An interface was built to conveniently inspect the model's output throughout its training. It's available at http://localhost:3000/ whenever the containers are running.

To feed the interface, train the model with the `frontend_data` setting option (in `train.json` file) set to `true`. Once the training is complete, the data will be correctly stored in the Front-End application.
