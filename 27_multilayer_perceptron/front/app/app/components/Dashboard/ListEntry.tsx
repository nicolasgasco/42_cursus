import { StatusIndicator } from "./StatusIndicator";

interface ListEntryProps {
  description: string;
  title: string;
  statusValue?: number;
}

export const ListEntry = ({
  description,
  title,
  statusValue,
}: ListEntryProps): JSX.Element => {
  return (
    <div className="flex gap-2">
      <dt>{title}:</dt>
      <dd className="ml-auto">
        {description}{" "}
        {statusValue && (
          <StatusIndicator className="ml-2" percentage={statusValue} />
        )}
      </dd>
    </div>
  );
};
