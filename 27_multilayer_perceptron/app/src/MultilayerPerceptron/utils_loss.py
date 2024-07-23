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
