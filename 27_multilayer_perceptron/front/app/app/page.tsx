import { NeuralNetworkVisualizer } from "./components/NeuralNetworkVisualizer";
import { NeuralNetworkData } from "./interfaces/NeuralNetworkData.interface";
import NEURAL_NETWORK_DATA from "../../data/data.json"

const neuralNetworkData: NeuralNetworkData[] = NEURAL_NETWORK_DATA;

export default function Home() {

  return (
    <main className="flex flex-col items-center h-screen my-24">
      <h1 className="title-1">Multilayer perceptron visualizer</h1>
      <NeuralNetworkVisualizer data={neuralNetworkData} />
    </main>
  );
}
