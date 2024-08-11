import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { Tile } from "./Dashboard/Tile";
import { ListEntry } from "./Dashboard/ListEntry";

interface DashboardProps {
  data: NeuralNetworkData;
}

export const Dashboard = ({ data }: DashboardProps): JSX.Element => {
  return (
    <div className="flex justify-between gap-4 mb-12">
      <Tile title={"Batch"}>
        <ListEntry
          title="Num of data points"
          description={data["data_points"].toString()}
        />
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
          <ListEntry
            title={"Train"}
            description={data["loss"].toFixed(6)} />
          <ListEntry
            title={"Validation"}
            description={data["test_loss"].toFixed(6)} />
        </dl>
      </Tile>


      <Tile title={"Accuracy"}>
        <dl>
          <ListEntry
            title={"Train"}
            description={`${Math.round(data["accuracy"]).toString()}%`}
            statusValue={data["accuracy"]} />
          <ListEntry
            title={"Validation"}
            description={`${Math.round(data["test_accuracy"]).toString()}%`}
            statusValue={data["test_accuracy"]} />
        </dl>
      </Tile>
    </div>
  )
};