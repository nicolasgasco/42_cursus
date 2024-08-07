import numpy as np
import pandas as pd


def binary_cross_entropy_error(y_pred: pd.DataFrame,
                               y_true: pd.DataFrame) -> float:
    """
    Calculates the binary cross entropy loss between predicted and true labels.

    Args:
        y_pred (pd.DataFrame): The predicted labels.
        y_true (pd.DataFrame): The true labels.

    Returns:
        float: The binary cross entropy loss.
    """

    N = y_true.shape[0]
    y_true = np.array(y_true)

    log_loss_component = y_true * np.log(y_pred)

    loss = np.mean(-(1/N) * np.sum(log_loss_component +
                   (1 - y_true) * np.log(1 - y_pred), axis=0))

    assert loss >= 0, "Loss should be greater than or equal to 0."

    return loss


def categorical_cross_entropy_error(y_pred: pd.DataFrame,
                                    y_true: pd.DataFrame) -> float:
    """
    Calculates the categorical cross-entropy error
    between predicted and true labels.

    Args:
        y_pred (pd.DataFrame): The predicted labels.
        y_true (pd.DataFrame): The true labels.

    Returns:
        float: The categorical cross-entropy error.
    """

    y_true = np.array(y_true)

    total_loss = np.sum(y_true * np.log(y_pred), axis=1)
    loss = -np.mean(total_loss)

    return loss


def mean_squared_error(y_pred: pd.DataFrame,
                       y_true: pd.DataFrame) -> float:
    """
    Calculates the mean squared error between predicted and true labels.

    Args:
        y_pred (pd.DataFrame): The predicted labels.
        y_true (pd.DataFrame): The true labels.

    Returns:
        float: The mean squared error.
    """

    loss = np.mean((y_pred - y_true) ** 2)

    return loss
