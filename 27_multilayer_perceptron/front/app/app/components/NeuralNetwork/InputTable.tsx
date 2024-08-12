import { NeuralNetworkData } from "@/app/interfaces/NeuralNetworkData.interface";

interface InputTableProps {
  data: NeuralNetworkData["batch_data"];
}

export const InputTable = ({ data }: InputTableProps): JSX.Element => {
  return (
    <table className="table-auto m-2 text-sm">
      <thead>
        <tr>
          {/* {Object.keys(data[0]).map((columnName, index) => {
            return (
              <th key={index} className="px-6 pb-2 border-b-2">
                {columnName}
              </th>
            )
          })} */}
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
    </table>
  );
};
