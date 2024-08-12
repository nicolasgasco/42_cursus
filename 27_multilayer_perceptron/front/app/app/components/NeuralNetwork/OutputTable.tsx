import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";

interface OutputTableProps {
  data: NeuralNetworkData;
}

export const OutputTable = ({ data }: OutputTableProps) => {
  return (
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
    </table>
  );
};
