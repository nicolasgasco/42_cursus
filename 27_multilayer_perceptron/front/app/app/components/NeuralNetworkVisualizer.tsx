"use client"

import data from "../../../data/data.json";
import React from "react";
import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { PercentageStatusIndicator } from "./PercentageStatusIndicator";
import { VisualizerTile } from "./VisualizerTile";
import { VisualizerTitleDescriptionListEntry } from "./VisualizerTileDescriptionListEntry";

interface NeuralNetworkVisualizerProps {
  data: NeuralNetworkData[];
}

const totalEpochs = data[0]['total_epochs'];

export const NeuralNetworkVisualizer = ({ data }: NeuralNetworkVisualizerProps): JSX.Element => {

  const [currentEpochData, setCurrentEpochData] = React.useState(data[0]);

  const handleEpochChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const epochIndex = parseInt(event.target.value);
    setCurrentEpochData(data[epochIndex]);
  }


  return (<div>
    <h2 className="mb-4">Use the slider below to see how the neural network performs over time</h2>
    <div className="mb-4">
      <div className="relative mb-12">
        <input id="range" type="range" min="1" max={totalEpochs - 1} step="1" value={currentEpochData["total_epoch"]} onInput={handleEpochChange} className="w-full h-3 bg-gray-200 rounded-lg appearance-none cursor-pointer range-lg dark:bg-gray-700" />
        <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-0 -bottom-6">1</span>
        <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-1/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">{totalEpochs / 4 * 1}</span>
        <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-2/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">{totalEpochs / 4 * 2}</span>
        <span className="text-sm text-gray-500 dark:text-gray-400 absolute start-3/4 -translate-x-1/2 rtl:translate-x-1/2 -bottom-6">{totalEpochs / 4 * 3}</span>
        <span className="text-sm text-gray-500 dark:text-gray-400 absolute end-0 -bottom-6">{totalEpochs}</span>
      </div>
      <label htmlFor="range" className="title-3 ">Epoch {currentEpochData["total_epoch"]}</label>
    </div>

    <div>
      <div className="flex justify-between gap-4">
        <VisualizerTile title={"Batch"}>
          <p>{currentEpochData["batch"] + 1}/{currentEpochData["total_batches"]}</p>
        </VisualizerTile>

        <VisualizerTile title={"Loss"}>
          <dl>
            <VisualizerTitleDescriptionListEntry
              title={"Train"}
              description={currentEpochData["loss"].toFixed(2)} />
            <VisualizerTitleDescriptionListEntry
              title={"Validation"}
              description={currentEpochData["test_loss"].toFixed(2)} />
          </dl>
        </VisualizerTile>


        <VisualizerTile title={"Accuracy"}>
          <dl>
            <VisualizerTitleDescriptionListEntry
              title={"Train"}
              description={Math.round(currentEpochData["accuracy"]).toString()}
              statusValue={currentEpochData["accuracy"]} />
            <VisualizerTitleDescriptionListEntry
              title={"Validation"}
              description={Math.round(currentEpochData["test_accuracy"]).toString()}
              statusValue={currentEpochData["test_accuracy"]} />
          </dl>
        </VisualizerTile>
      </div>
    </div>
  </div>)
};