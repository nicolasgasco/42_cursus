import numpy as np
import pandas as pd


def binary_cross_entropy_error(y_pred: pd.DataFrame,
                               y_true: pd.DataFrame) -> float:
    """
        Calculate the binary cross entropy error
        between predicted and true values.

        Parameters:
        - y_pred (pd.DataFrame): The predicted values.
        - y_true (pd.DataFrame): The true values.

        Returns:
        - float: The binary cross entropy error.
        """
    loss = -np.mean(
        y_true * np.log(y_pred) + (1 - y_true) * np.log(1 - y_pred)
    )

    return loss


def calc_precision(train_data: pd.DataFrame,
                   outputs_columns: list[str],
                   y_pred: pd.DataFrame) -> int:
    """
    Calculates the precision of the predictions made
    by the multilayer perceptron model.

    Args:
      train_data (pd.DataFrame): The training data used for training the model.
      outputs_columns (list[str]): The list of output column names.
      y_pred (pd.DataFrame): The predicted values.

    Returns:
      int: The precision of the predictions as a percentage.
    """

    formatted_predictions = y_pred.idxmax(axis=1).apply(
        lambda x: "M" if x == 0 else "B").values
    x = train_data[outputs_columns].values.flatten()

    correct_predictions = sum(formatted_predictions == x)
    percentage_precision = correct_predictions / len(x) * 100

    return percentage_precision
