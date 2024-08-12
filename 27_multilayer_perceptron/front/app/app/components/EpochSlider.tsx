import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";

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
    <div className="w-3/5 min-w-fit mx-auto mb-12">
      <h2 className="mb-4">
        Use the slider below to see how the neural network performs over time
      </h2>
      <div className="mb-4">
        <div className="relative mb-12">
          <input
            id="range"
            type="range"
            min="1"
            max={totalEpochs - 1}
            step="1"
            value={epoch["total_epoch"]}
            onInput={handleEpochChange}
            className="w-full h-3 bg-gray-200 rounded-lg appearance-none cursor-pointer range-lg dark:bg-gray-700"
          />

          <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-0 -bottom-6">
            1
          </span>
          <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-1/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 1)}
          </span>
          <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-2/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 2)}
          </span>
          <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-3/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">
            {Math.round((totalEpochs / 4) * 3)}
          </span>
          <span className="text-sm text-gray-500 dark:text-gray-400 absolute end-0 -bottom-6">
            {totalEpochs}
          </span>
        </div>

        <label htmlFor="range" className="title-3">
          Epoch {epoch["total_epoch"]} of {totalEpochs}
        </label>
      </div>
    </div>
  );
};
