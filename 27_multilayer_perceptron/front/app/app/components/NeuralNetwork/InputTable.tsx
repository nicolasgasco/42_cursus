import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";
import { EllipsisRows } from "../Table/EllipsisRows";
import { TableRow } from "../Table/TableRow";

interface InputTableProps {
  epochData: NeuralNetworkData["batch_data"];
}

export const InputTable = ({ epochData }: InputTableProps): JSX.Element => {
  const headers = Object.keys(epochData[parseInt(Object.keys(epochData)[0])]);

  return (
    <TableLayout>
      <thead>
        <tr>
          {headers.map((columnName, index) => {
            return <TableHeader key={index}>{columnName}</TableHeader>;
          })}
        </tr>
      </thead>
      <tbody>
        {Object.entries(epochData).map(([_, value], index) => {
          return (
            <tr key={index}>
              {Object.values(value).map((value, valueIndex) => {
                return (
                  <TableRow index={valueIndex} key={valueIndex}>
                    {value.toFixed(6)}
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
