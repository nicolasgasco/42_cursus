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
