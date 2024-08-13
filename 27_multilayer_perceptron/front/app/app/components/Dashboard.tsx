import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { DashboardTile } from "./Dashboard/DashboardTile";
import { ListEntry } from "./Dashboard/ListEntry";

interface DashboardProps {
  data: NeuralNetworkData;
}

export const Dashboard = ({ data }: DashboardProps): JSX.Element => {
  return (
    <div className="w-fit flex justify-between gap-4 mx-auto mb-3">
      <DashboardTile
        title="Data points"
        tooltipProps={{
          id: "model-tooltip",
          description:
            "The data set is divided into two sets: a main set that is used for training and a smaller one for validation. Once the model has been trained, the validation set is used to check the model's performance on unknown data.",
        }}
      >
        <ListEntry
          title="Training set"
          description={data["data_points"].toString()}
        />
        <ListEntry
          title="Validation set"
          description={data["test_data_points"].toString()}
        />
      </DashboardTile>

      <DashboardTile
        title={"Batch"}
        tooltipProps={{
          id: "batch-tooltip",
          description:
            "While it is possible to train a neural network using the entire data set, it is more common to divide the data set into smaller batches, which can lead to faster convergence.",
        }}
      >
        <ListEntry
          title="Batch size"
          description={data["batch_size"].toString()}
        />
        <ListEntry
          title="Current batch"
          description={`${data["batch"] + 1}/${data["total_batches"]}`}
        />
      </DashboardTile>

      <DashboardTile
        title={"Loss"}
        tooltipProps={{
          id: "loss-tooltip",
          description:
            "Loss is a measure of how well the neural network is performing. The lower the loss, the better the model is at making predictions.",
        }}
      >
        <dl>
          <ListEntry
            title={"Train set"}
            description={data["loss"].toFixed(6)}
          />
          <ListEntry
            title={"Validation set"}
            description={data["test_loss"].toFixed(6)}
          />
        </dl>
      </DashboardTile>

      <DashboardTile
        title={"Accuracy"}
        tooltipProps={{
          id: "accuracy-tooltip",
          description:
            "Accuracy is the percentage of correct predictions made by the neural network. It is calculated by comparing the predicted values with the actual values.",
        }}
      >
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
      </DashboardTile>
    </div>
  );
};
