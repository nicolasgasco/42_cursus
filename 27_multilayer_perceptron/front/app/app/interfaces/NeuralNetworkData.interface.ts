export interface NeuralNetworkData {
  accuracy: number;
  activation_function: string;
  batch: number;
  batch_data: { [key: string]: number }[];
  batch_size: number;
  data_points: number;
  epoch: number;
  hidden_layers: { weights: number[][]; biases: number[] }[];
  loss: number;
  output_layer: { weights: number[][]; biases: number[] };
  outputs: string[];
  predictions: { [key: string]: number }[];
  test_accuracy: number;
  test_data_points: number;
  test_loss: number;
  total_batches: number;
  total_epoch: number;
  total_epochs: number;
}
