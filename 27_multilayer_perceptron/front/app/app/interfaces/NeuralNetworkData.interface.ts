export interface NeuralNetworkModelData {
  activation_function: string;
  batch_size: number;
  data_points: number;
  outputs: string[];
  test_data_points: number;
  total_batches: number;
  total_epochs: number;
}

export interface NeuralNetworkEpochData {
  accuracy: number;
  batch: number;
  batch_data: { [key: string]: number }[];
  epoch: number;
  hidden_layers: { weights: number[][]; biases: number[] }[];
  loss: number;
  output_layer: { weights: number[][]; biases: number[] };
  predictions: { [key: string]: number }[];
  test_accuracy: number;
  test_loss: number;
  total_epoch: number;
  true_values: string[];
}

export interface NeuralNetworkData {
  data: NeuralNetworkModelData;
  epochs_data: NeuralNetworkEpochData[];
}
