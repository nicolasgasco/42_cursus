"use client"

import data from "../../../data/data.json"
import React from "react";
import { NeuralNetworkData } from "../interfaces/NeuralNetworkData.interface";
import { EpochSlider } from "./EpochSlider";
import { Dashboard } from "./Dashboard";
import { NeuralNetwork } from "./NeuralNetwork";

interface HomePageProps {
  data: NeuralNetworkData[];
}

const totalEpochs = data[0]['total_epochs'];

export const HomePage = ({ data }: HomePageProps): JSX.Element => {
  const [currentEpochData, setCurrentEpochData] = React.useState(data[0]);

  const handleEpochChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const epochIndex = parseInt(event.target.value);
    setCurrentEpochData(data[epochIndex]);
  }


  return (
    <div>
      <EpochSlider epoch={currentEpochData} handleEpochChange={handleEpochChange} />

      <Dashboard data={currentEpochData} />

      <NeuralNetwork data={currentEpochData} />
    </div>
  )
};