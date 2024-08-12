import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { InputTable } from "./NeuralNetwork/InputTable";
import { LayerTile } from "./NeuralNetwork/LayerTile";
import { NeuronTile } from "./NeuralNetwork/NeuronTile";

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
                <NeuronTile key={weightIndex}>
                  <h4 className="title-5">Neuron {weightIndex + 1}</h4>
                  <p>
                    Weights: [
                    {weight.map((weight) => weight.toFixed(6)).join(", ")}]
                  </p>
                  <p>Bias: {layer.biases[weightIndex].toFixed(6)}</p>
                </NeuronTile>
              );
            })}
          </LayerTile>
        );
      })}

      <LayerTile title={"Output layer"}>
        {data["output_layer"].weights.map((weight, weightIndex) => {
          return (
            <NeuronTile key={weightIndex}>
              <h4 className="title-5">Neuron {weightIndex + 1}</h4>
              <p>
                Weights: [{weight.map((weight) => weight.toFixed(6)).join(", ")}
                ]
              </p>
              <p>Bias: {data["output_layer"].biases[weightIndex].toFixed(6)}</p>
            </NeuronTile>
          );
        })}
      </LayerTile>

      <LayerTile title={"Predictions"}>
        <table className="table-auto m-4">
          <thead>
            <tr>
              <th className="px-6 pb-2 border-b-2" style={{ width: 125 }}>
                Malignant
              </th>
              <th className="px-6 pb-2 border-b-2" style={{ width: 125 }}>
                Benign
              </th>
            </tr>
          </thead>
          <tbody>
            {Object.entries(data["predictions"]).map(([_, value], index) => {
              return (
                <tr key={index}>
                  {Object.values(value).map((value, valueIndex) => {
                    return (
                      <td
                        key={valueIndex}
                        className={`px-6 pb-1 ${index === 0 ? "pt-4" : ""}`}
                      >
                        <span
                          className={
                            value > 0.5 ? "text-yellow-300" : "font-light"
                          }
                        >
                          {value.toFixed(6)}
                        </span>
                      </td>
                    );
                  })}
                </tr>
              );
            })}
            {[0, 1, 3].map((_, index) => {
              return (
                <tr key={index}>
                  <td className="px-6 pb-1">...</td>
                </tr>
              );
            })}
          </tbody>
        </table>
      </LayerTile>
    </div>
  );
};
