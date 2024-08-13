"use client";

import React from "react";
import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { EpochSlider } from "./EpochSlider";
import { Dashboard } from "./Dashboard";
import { NeuralNetwork } from "./NeuralNetwork";
import NEURAL_NETWORK_DATA from "../../public/data.json";

const neuralNetworkData: NeuralNetworkData[] = NEURAL_NETWORK_DATA;

const totalEpochs = neuralNetworkData[0]["total_epochs"];

export const HomePage = (): JSX.Element => {
  const [currentEpochData, setCurrentEpochData] = React.useState(neuralNetworkData[0]);

  const handleEpochChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const epochIndex = parseInt(event.target.value);
    setCurrentEpochData(neuralNetworkData[epochIndex]);
  };

  return (
    <div className="w-full max-w-full flex flex-col items-center">
      <EpochSlider
        epoch={currentEpochData}
        handleEpochChange={handleEpochChange}
      />

      <Dashboard data={currentEpochData} />

      <NeuralNetwork data={currentEpochData} />
    </div >
  );
};
