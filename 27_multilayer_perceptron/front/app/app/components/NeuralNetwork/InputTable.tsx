import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";
import { EllipsisRows } from "../Table/EllipsisRows";
import { TableRow } from "../Table/TableRow";

interface InputTableProps {
  data: NeuralNetworkData["batch_data"];
}

export const InputTable = ({ data }: InputTableProps): JSX.Element => {
  const headers = Object.keys(data[parseInt(Object.keys(data)[0])]);

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
        {Object.entries(data).map(([_, value], index) => {
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
