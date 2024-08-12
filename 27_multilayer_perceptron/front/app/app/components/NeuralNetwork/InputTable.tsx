import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";

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
            return (
              <TableHeader key={index} style={{ width: 92 }}>
                {columnName}
              </TableHeader>
            );
          })}
        </tr>
      </thead>
      <tbody>
        {Object.entries(data).map(([_, value], index) => {
          return (
            <tr key={index}>
              {Object.values(value).map((value, valueIndex) => {
                return (
                  <td
                    key={valueIndex}
                    className={`px-3 pb-1 ${index === 0 ? "pt-4" : ""}`}
                  >
                    {value.toFixed(6)}
                  </td>
                );
              })}
            </tr>
          );
        })}
        {[0, 1, 3].map((_, index) => {
          return (
            <tr key={index}>
              <td className="px-3 pb-1">...</td>
            </tr>
          );
        })}
      </tbody>
    </TableLayout>
  );
};
