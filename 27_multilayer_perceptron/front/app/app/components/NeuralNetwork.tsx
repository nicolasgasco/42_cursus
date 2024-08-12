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
    <div className="flex gap-4">
      <LayerTile title={"Input layer"} style={{ width: 410 }}>
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
                  <TableLayout>
                    <thead>
                      <tr>
                        <TableHeader>Weights</TableHeader>
                        <TableHeader>Bias</TableHeader>
                      </tr>
                    </thead>
                    <tbody>
                      {weight.map((weight, weightIndex) => {
                        return (
                          <tr key={weightIndex}>
                            <TableRow>{weight.toFixed(6)}</TableRow>
                            {weightIndex === 0 && (
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

      <LayerTile title={"Output layer"}>
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
                  {weight.map((weight, weightIndex) => {
                    return (
                      <tr key={weightIndex}>
                        <TableRow>{weight.toFixed(6)}</TableRow>
                        {weightIndex === 0 && (
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

      <LayerTile title={"Predictions"} style={{ width: 240 }}>
        <OutputTable data={data} />
      </LayerTile>
    </div>
  );
};
