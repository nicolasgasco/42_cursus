import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { Tile } from "./Dashboard/Tile";
import { ListEntry } from "./Dashboard/ListEntry";

interface DashboardProps {
  data: NeuralNetworkData;
}

export const Dashboard = ({ data }: DashboardProps): JSX.Element => {
  return (
    <div className="w-fit flex justify-between gap-4 mx-auto mb-12">
      <Tile title="Model">
        <div className="mb-4">
          <ListEntry
            title="Training data points"
            description={data["data_points"].toString()}
          />
          <ListEntry
            title="Validation data points"
            description={data["test_data_points"].toString()}
          />
        </div>
        <ListEntry
          title="Activation function"
          description={data["activation_function"].toString()}
        />
      </Tile>

      <Tile title={"Batch"}>
        <ListEntry
          title="Batch size"
          description={data["batch_size"].toString()}
        />
        <ListEntry
          title="Current batch"
          description={`${data["batch"] + 1}/${data["total_batches"]}`}
        />
      </Tile>

      <Tile title={"Loss"}>
        <dl>
          <ListEntry title={"Train"} description={data["loss"].toFixed(6)} />
          <ListEntry
            title={"Validation"}
            description={data["test_loss"].toFixed(6)}
          />
        </dl>
      </Tile>

      <Tile title={"Accuracy"}>
        <dl>
          <ListEntry
            title={"Train"}
            description={`${Math.round(data["accuracy"]).toString()}%`}
            statusValue={data["accuracy"]}
          />
          <ListEntry
            title={"Validation"}
            description={`${Math.round(data["test_accuracy"]).toString()}%`}
            statusValue={data["test_accuracy"]}
          />
        </dl>
      </Tile>
    </div>
  );
};
