import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { InputTable } from "./NeuralNetwork/InputTable";
import { LayerTile } from "./NeuralNetwork/LayerTile";
import { NeuronTile } from "./NeuralNetwork/NeuronTile";
import { OutputTable } from "./NeuralNetwork/OutputTable";
import { TableHeader } from "./Table/TableHeader";
import { TableLayout } from "./Table/TableLayout";
import { TableRow } from "./Table/TableRow";

interface NeuralNetworkProps {
  data: NeuralNetworkData;
}

export const NeuralNetwork = ({ data }: NeuralNetworkProps): JSX.Element => {
  console.table(data["predictions"]);
  return (
    <div className="flex justify-center gap-3 px-12 py-6 w-full overflow-x-auto">
      <LayerTile
        title={"Input layer"}
        tooltipProps={{
          id: "input-tooltip",
          description:
            "The input layer contains the data that is fed into the neural network. Each row represents a data point and each column represents a feature.",
        }}
      >
        <InputTable data={data["batch_data"]} />
      </LayerTile>

      {data["hidden_layers"].map((layer, layerIndex) => {
        return (
          <LayerTile
            title={`Hidden layer ${layerIndex + 1}`}
            key={layerIndex}
            tooltipProps={{
              id: `input-tooltip-${layerIndex}`,
              description:
                "Hidden layers are the layers between the input and output layers. They are responsible for learning the underlying patterns in the data.",
            }}
          >
            {layer.weights.map((weight, weightIndex) => {
              return (
                <NeuronTile
                  key={weightIndex}
                  title={`Neuron ${weightIndex + 1}`}
                >
                  <TableLayout>
                    <thead>
                      <tr>
                        <TableHeader>Weights</TableHeader>
                        <TableHeader>Bias</TableHeader>
                      </tr>
                    </thead>
                    <tbody>
                      {weight.map((weight, innerWeightIndex) => {
                        return (
                          <tr key={innerWeightIndex}>
                            <TableRow>{weight.toFixed(6)}</TableRow>
                            {innerWeightIndex === 0 && (
                              <TableRow>
                                {layer.biases[weightIndex].toFixed(6)}
                              </TableRow>
                            )}
                          </tr>
                        );
                      })}
                    </tbody>
                  </TableLayout>
                </NeuronTile>
              );
            })}
          </LayerTile>
        );
      })}

      <LayerTile
        title={"Output layer"}
        tooltipProps={{
          id: "output-tooltip",
          description:
            "The output layer computes the final predictions of the neural network. The number of neurons in the output layer matches the number of classes in the data set.",
        }}
      >
        {data["output_layer"].weights.map((weight, weightIndex) => {
          return (
            <NeuronTile key={weightIndex} title={`Neuron ${weightIndex + 1}`}>
              <TableLayout>
                <thead>
                  <tr>
                    <TableHeader>Weights</TableHeader>
                    <TableHeader>Bias</TableHeader>
                  </tr>
                </thead>
                <tbody>
                  {weight.map((weight, innerWeightIndex) => {
                    return (
                      <tr key={innerWeightIndex}>
                        <TableRow>{weight.toFixed(6)}</TableRow>
                        {innerWeightIndex === 0 && (
                          <TableRow>
                            {data["output_layer"].biases[weightIndex].toFixed(
                              6
                            )}
                          </TableRow>
                        )}
                      </tr>
                    );
                  })}
                </tbody>
              </TableLayout>
            </NeuronTile>
          );
        })}
      </LayerTile>

      <LayerTile
        title={"Predictions"}
        tooltipProps={{
          id: "predictions-tooltip",
          description:
            "Each column represents a feature, i.e. 'M' for malignant and 'B' for benign. The values represent the probability of the data point belonging to each class.",
        }}
        style={{ width: 240 }}
      >
        <OutputTable data={data} />
      </LayerTile>
    </div>
  );
};
