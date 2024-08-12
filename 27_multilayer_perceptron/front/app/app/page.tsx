import { HomePage } from "./components/HomePage";
import { NeuralNetworkData } from "./interfaces/NeuralNetworkData.interface";
import NEURAL_NETWORK_DATA from "../../data/data.json";

const neuralNetworkData: NeuralNetworkData[] = NEURAL_NETWORK_DATA;

export default function Home() {
  return (
    <main className="max-w-full flex flex-col items-center h-screen my-24">
      <h1 className="title-1 mb-12">Multilayer perceptron visualizer</h1>
      <HomePage data={neuralNetworkData} />
    </main>
  );
}
