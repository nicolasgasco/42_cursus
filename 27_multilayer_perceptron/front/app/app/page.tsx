import { HomePage } from "./components/HomePage";
import { NeuralNetworkData } from "./interfaces/NeuralNetworkData.interface";
import NEURAL_NETWORK_DATA from "../public/data.json";

const neuralNetworkData: NeuralNetworkData[] = NEURAL_NETWORK_DATA;

export default function Home() {
  return (
    <main className="max-w-full w-full  min-h-screen h-full flex flex-col items-center my-12 px-2">
      <h1 className="title-1 mb-4 text-center">Multilayer perceptron visualizer</h1>
      <HomePage data={neuralNetworkData} />
    </main>
  );
}
