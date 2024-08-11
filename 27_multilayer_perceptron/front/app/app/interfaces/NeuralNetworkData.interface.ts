export interface NeuralNetworkData {
  accuracy: number;
  batch: number;
  batch_data: { key_1: number; key_2: number }[];
  batch_size: number;
  data_points: number;
  epoch: number;
  hidden_layers: { weights: number[][]; biases: number[] }[];
  loss: number;
  output_layer: { weights: number[][]; biases: number[] };
  predictions: { key_1: number; key_2: number }[];
  test_accuracy: number;
  test_loss: number;
  total_batches: number;
  total_epoch: number;
  total_epochs: number;
}
