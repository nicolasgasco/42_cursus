import numpy as np
import pandas as pd


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
