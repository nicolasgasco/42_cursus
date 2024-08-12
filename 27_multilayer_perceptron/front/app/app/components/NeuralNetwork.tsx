import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { InputTable } from "./NeuralNetwork/InputTable";
import { LayerTile } from "./NeuralNetwork/LayerTile";
import { NeuronTile } from "./NeuralNetwork/NeuronTile";
import { OutputTable } from "./NeuralNetwork/OutputTable";

interface NeuralNetworkProps {
  data: NeuralNetworkData;
}

export const NeuralNetwork = ({ data }: NeuralNetworkProps): JSX.Element => {
  console.table(data["predictions"]);
  return (
    <div className="flex gap-4">
      <LayerTile title={"Input layer"}>
        <InputTable data={data["batch_data"]} />
      </LayerTile>

      {data["hidden_layers"].map((layer, layerIndex) => {
        return (
          <LayerTile title={`Hidden layer ${layerIndex + 1}`} key={layerIndex}>
            {layer.weights.map((weight, weightIndex) => {
              return (
                <NeuronTile
                  key={weightIndex}
                  title={`Neuron ${weightIndex + 1}`}
                >
                  <table>
                    <thead>
                      <tr>
                        <th>Weights</th>
                        <th>Bias</th>
                      </tr>
                    </thead>
                    <tbody>
                      {weight.map((weight, weightIndex) => {
                        return (
                          <tr key={weightIndex}>
                            <td>{weight.toFixed(6)}</td>
                            {weightIndex === 0 && (
                              <td>{layer.biases[weightIndex].toFixed(6)}</td>
                            )}
                          </tr>
                        );
                      })}
                    </tbody>
                  </table>
                </NeuronTile>
              );
            })}
          </LayerTile>
        );
      })}

      <LayerTile title={"Output layer"}>
        {data["output_layer"].weights.map((weight, weightIndex) => {
          return (
            <NeuronTile key={weightIndex} title={`Neuron ${weightIndex + 1}`}>
              <table>
                <thead>
                  <tr>
                    <th>Weights</th>
                    <th>Bias</th>
                  </tr>
                </thead>
                <tbody>
                  {weight.map((weight, weightIndex) => {
                    return (
                      <tr key={weightIndex}>
                        <td>{weight.toFixed(6)}</td>
                        {weightIndex === 0 && (
                          <td>
                            {data["output_layer"].biases[weightIndex].toFixed(
                              6
                            )}
                          </td>
                        )}
                      </tr>
                    );
                  })}
                </tbody>
              </table>
            </NeuronTile>
          );
        })}
      </LayerTile>

      <LayerTile title={"Predictions"}>
        <OutputTable data={data} />
      </LayerTile>
    </div>
  );
};
