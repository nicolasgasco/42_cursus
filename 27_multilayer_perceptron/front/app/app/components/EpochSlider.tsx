import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { TooltipIcon } from "./TooltipIcon";

interface EpochSliderProps {
  epoch: NeuralNetworkData;
  handleEpochChange: (event: React.ChangeEvent<HTMLInputElement>) => void;
}

export const EpochSlider = ({
  epoch,
  handleEpochChange,
}: EpochSliderProps): JSX.Element => {
  const totalEpochs = epoch["total_epochs"];

  return (
    <div className="w-1/5 min-w-fit mx-auto relative">
      <h2 className="mb-4 text-center">
        Use the slider below to see how the neural network performs over time
      </h2>
      <div className="mb-4 flex flex-col sticky">
        <div className="relative mb-12">
          <input
            id="range"
            type="range"
            min="0"
            max={totalEpochs - 1}
            step="1"
            value={epoch["total_epoch"]}
            onInput={handleEpochChange}
            className="w-full h-3 bg-gray-200 rounded-lg appearance-none cursor-pointer range-lg dark:bg-gray-700"
          />

          <span className="text-xs text-gray-500 dark:text-gray-400 absolute start-0 -bottom-6">
            1
          </span>
          <span className="text-xs text-gray-500 dark:text-gray-400 absolute start-1/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 1)}
          </span>
          <span className="text-xs text-gray-500 dark:text-gray-400 absolute start-2/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 2)}
          </span>
          <span className="text-xs text-gray-500 dark:text-gray-400 absolute start-3/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 3)}
          </span>
          <span className="text-xs text-gray-500 dark:text-gray-400 absolute end-0 -bottom-6">
            {totalEpochs}
          </span>
        </div>

        <label
          htmlFor="range"
          className="text-center flex gap-2 items-baseline mx-auto"
        >
          <span className="title-4">
            Epoch {epoch["total_epoch"] + 1} of {totalEpochs}
          </span>
          <TooltipIcon
            id="epoch-tooltip"
            description="An epoch is a complete training round. The neural network computes its predictions and compares them with the actual values. It then adjusts weights and biases to minimize the error."
          />
        </label>
      </div>
    </div>
  );
};
