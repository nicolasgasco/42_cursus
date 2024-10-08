import { NeuralNetworkModelData } from "../interfaces/NeuralNetworkData.interface";
import { NeuralNetworkepochData } from "../interfaces/NeuralNetworkepochData.interface";
import { InputTable } from "./NeuralNetwork/InputTable";
import { LayerTile } from "./NeuralNetwork/LayerTile";
import { NeuronTile } from "./NeuralNetwork/NeuronTile";
import { OutputTable } from "./NeuralNetwork/OutputTable";
import { TableHeader } from "./Table/TableHeader";
import { TableLayout } from "./Table/TableLayout";
import { TableRow } from "./Table/TableRow";

interface NeuralNetworkProps {
  epochData: NeuralNetworkepochData;
  modelData: NeuralNetworkModelData
}

export const NeuralNetwork = ({ epochData, modelData }: NeuralNetworkProps): JSX.Element => {
  return (
    <div className="py-6" style={{ maxWidth: "95%" }}>
      <div className="flex justify-center gap-3 min-w-fit">
        <LayerTile
          title="Input layer"
          tooltipProps={{
            id: "input-tooltip",
            description:
              "The input layer contains the data that is fed into the neural network. Each row represents a data point and each column a feature.",
          }}
        >
          <div
            style={{
              maxWidth: 370,
              overflowX: "auto",
            }}
          >
            <InputTable epochData={epochData["batch_data"]} />
          </div>
        </LayerTile>

        {epochData["hidden_layers"].map((layer, layerIndex) => {
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
          {epochData["output_layer"].weights.map((weight, weightIndex) => {
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
                              {epochData["output_layer"].biases[weightIndex].toFixed(
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
          title="Predictions"
          tooltipProps={{
            id: "predictions-tooltip",
            description:
              "Each column represents a feature, i.e. 'M' for malignant and 'B' for benign. The values represent the probability of the data point belonging to each class.",
          }}
        >
          <OutputTable epochData={epochData} modelData={modelData} />
        </LayerTile>

        <LayerTile
          title="Truth"
          tooltipProps={{
            id: "true-values-tooltip",
            description:
              "The actual values that the neural network is trying to predict. These values are used to calculate the accuracy of the model.",
          }}
        >
          <TableLayout>
            <thead>
              <tr>
                <TableHeader>Value</TableHeader>
                <TableHeader>Correct</TableHeader>
              </tr>
            </thead>
            <tbody>
              {epochData["true_values"].map((value, index) => {
                const predictions = epochData["predictions"][index];
                const strongestPredictionIndex = Object.keys(predictions).reduce((a, b) => predictions[a] > predictions[b] ? a : b);
                const predictedHouseName = modelData["outputs"][parseInt(strongestPredictionIndex)];
                return (
                  <tr key={index}>
                    <TableRow>{value}</TableRow>
                    <TableRow>{value.toLocaleLowerCase() === predictedHouseName.toLowerCase() ? "✅" : "❌"}</TableRow>
                  </tr>
                )
              })}
            </tbody>
          </TableLayout>
        </LayerTile>
      </div>
    </div>
  );
};
