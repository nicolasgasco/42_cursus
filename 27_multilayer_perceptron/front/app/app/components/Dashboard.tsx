import { NeuralNetworkEpochData, NeuralNetworkModelData } from "../interfaces/NeuralNetworkData.interface";
import { DashboardTile } from "./Dashboard/DashboardTile";
import { ListEntry } from "./Dashboard/ListEntry";

interface DashboardProps {
  epochData: NeuralNetworkEpochData;
  modelData: NeuralNetworkModelData
}

export const Dashboard = ({ epochData, modelData }: DashboardProps): JSX.Element => {
  return (
    <div className="w-fit flex justify-between flex-wrap gap-4 mx-auto mb-3">
      <DashboardTile
        title="Data points"
        tooltipProps={{
          id: "model-tooltip",
          description:
            "The main set is used for training the model while the validation set is used to check the model's performance on unknown data.",
        }}
      >
        <ListEntry
          title="Training set"
          description={modelData["data_points"].toString()}
        />
        <ListEntry
          title="Validation set"
          description={modelData["test_data_points"].toString()}
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
          description={modelData["batch_size"].toString()}
        />
        <ListEntry
          title="Current batch"
          description={`${epochData["batch"] + 1}/${modelData["total_batches"]}`}
        />
      </DashboardTile>

      <DashboardTile
        title={"Activation"}
        tooltipProps={{
          id: "activation-tooltip",
          description:
            "The activation function determines the output of a neuron. It introduces non-linearity to the neural network, allowing it to learn complex patterns in the data.",
        }}
      >
        <ListEntry
          title="Function"
          description={modelData["activation_function"]}
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
            description={epochData["loss"].toFixed(6)}
          />
          <ListEntry
            title={"Validation set"}
            description={epochData["test_loss"].toFixed(6)}
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
            description={`${parseFloat(epochData["accuracy"].toFixed(2)).toString()}%`}
            statusValue={epochData["accuracy"]}
          />
          <ListEntry
            title={"Validation"}
            description={`${parseFloat(epochData["test_accuracy"].toFixed(2)).toString()}%`}
            statusValue={epochData["test_accuracy"]}
          />
        </dl>
      </DashboardTile>
    </div>
  );
};
