import json as json
import os as os

from src.Layer import Layer


def save_params_to_json(hidden_layers: list[Layer],
                        output_layer: Layer) -> None:
    """
    Save the parameters of the neural network to a JSON file.
    Args:
      hidden_layers (list[Layer]): List of hidden layers in the neural network.
      output_layer (Layer): Output layer of the neural network.
    Returns:
      None
    """

    parameters = {}

    formatted_hidden_layers = []
    for hidden_layer in hidden_layers:
        formatted_hidden_layers.append({
            "weights": hidden_layer.weights.tolist(),
            "biases": hidden_layer.biases.tolist()
        })

    parameters["hidden_layers"] = formatted_hidden_layers
    parameters["output_layer"] = {
        "weights": output_layer.weights.tolist(),
        "biases": output_layer.biases.tolist()
    }

    with open(os.environ.get("PARAMETERS_PATH"), 'w') as json_file:
        json.dump(parameters, json_file, indent=4)
