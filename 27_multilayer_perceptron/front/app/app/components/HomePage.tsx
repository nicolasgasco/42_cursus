"use client";

import React from "react";
import { NeuralNetworkData, NeuralNetworkEpochData } from "../interfaces/NeuralNetworkData.interface";
import { EpochSlider } from "./EpochSlider";
import { Dashboard } from "./Dashboard";
import { NeuralNetwork } from "./NeuralNetwork";
import NEURAL_NETWORK_DATA from "../../public/data.json";

const neuralNetworkData: NeuralNetworkEpochData[] = NEURAL_NETWORK_DATA["epochs_data"];

export const HomePage = (): JSX.Element => {
  const [currentEpochData, setCurrentEpochData] = React.useState(neuralNetworkData[0]);
  const modelData: NeuralNetworkData["data"] = NEURAL_NETWORK_DATA["data"];

  const handleEpochChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const epochIndex = parseInt(event.target.value);
    setCurrentEpochData(neuralNetworkData[epochIndex]);
  };

  return (
    <div className="w-full max-w-full flex flex-col items-center">
      <EpochSlider
        epoch={currentEpochData}
        modelData={modelData}
        handleEpochChange={handleEpochChange}
      />

      <Dashboard epochData={currentEpochData} modelData={modelData} />

      <NeuralNetwork epochData={currentEpochData} modelData={modelData} />
    </div >
  );
};
