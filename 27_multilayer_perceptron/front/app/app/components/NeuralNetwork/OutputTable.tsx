import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";
import { EllipsisRows } from "../Table/EllipsisRows";
import { TableRow } from "../Table/TableRow";

interface OutputTableProps {
  data: NeuralNetworkData;
}

export const OutputTable = ({ data }: OutputTableProps) => {
  return (
    <TableLayout>
      <thead>
        <tr>
          <TableHeader style={{ width: 92 }}>M</TableHeader>
          <TableHeader style={{ width: 92 }}>B</TableHeader>
        </tr>
      </thead>
      <tbody>
        {Object.entries(data["predictions"]).map(([_, value], index) => {
          return (
            <tr key={index}>
              {Object.values(value).map((value, valueIndex) => {
                return (
                  <TableRow index={valueIndex} key={valueIndex}>
                    <span
                      className={value > 0.5 ? "text-yellow-300" : "font-light"}
                    >
                      {value.toFixed(6)}
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
