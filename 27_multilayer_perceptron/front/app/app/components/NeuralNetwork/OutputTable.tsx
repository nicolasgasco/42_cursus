import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";
import { TableLayout } from "../Table/TableLayout";
import { TableHeader } from "../Table/TableHeader";

interface OutputTableProps {
  data: NeuralNetworkData;
}

export const OutputTable = ({ data }: OutputTableProps) => {
  return (
    <TableLayout>
      <thead>
        <tr>
          <TableHeader style={{ width: 125 }}>Malignant</TableHeader>
          <TableHeader style={{ width: 125 }}>Benign</TableHeader>
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
                      className={value > 0.5 ? "text-yellow-300" : "font-light"}
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
    </TableLayout>
  );
};
