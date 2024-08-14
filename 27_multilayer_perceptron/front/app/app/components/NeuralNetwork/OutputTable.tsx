import { NeuralNetworkData, NeuralNetworkModelData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";
import { EllipsisRows } from "../Table/EllipsisRows";
import { TableRow } from "../Table/TableRow";

interface OutputTableProps {
  epochData: NeuralNetworkData;
  modelData: NeuralNetworkModelData
}

export const OutputTable = ({ epochData, modelData }: OutputTableProps) => {
  return (
    <TableLayout>
      <thead>
        <tr>
          {modelData["outputs"].map((output, index) => {
            return <TableHeader key={index}>{output}</TableHeader>;
          })}
        </tr>
      </thead>
      <tbody>
        {Object.entries(epochData["predictions"]).map(([_, value], index) => {
          return (
            <tr key={index}>
              {Object.values(value).map((innerValue, innerValueIndex) => {
                return (
                  <TableRow index={innerValueIndex} key={innerValueIndex}>
                    <span
                      className={innerValue === Math.max(...Object.values(value)) ? "text-yellow-300" : "font-light"}
                    >
                      {innerValue.toFixed(6)}
                    </span>
                  </TableRow>
                );
              })}
            </tr>
          );
        })}
        <EllipsisRows />
      </tbody>
    </TableLayout>
  );
};
