import { PercentageStatusIndicator } from "./PercentageStatusIndicator";

interface VisualizerTitleDescriptionListEntryProps {
  description: string;
  title: string;
  statusValue?: number;
}

export const VisualizerTitleDescriptionListEntry = ({ description, title, statusValue }: VisualizerTitleDescriptionListEntryProps) => {
  return (
    <div className="flex">
      <dt>{title}:</dt>
      <dd className="ml-auto">{description} {statusValue && <PercentageStatusIndicator percentage={statusValue} />}</dd>
    </div>
  )
};