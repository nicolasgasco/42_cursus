import Image from "next/image";
import { Tooltip as ReactTooltip } from "react-tooltip";

export interface TooltipIconProps {
  id: string;
  description: string;
}

export const TooltipIcon = ({
  description,
  id,
}: TooltipIconProps): JSX.Element => {
  return (
    <div className="inline cursor-help">
      <Image
        src="/question-mark.svg"
        width={20}
        height={20}
        alt={description}
        data-tooltip-id={id}
      />
      <ReactTooltip
        id={id}
        place="top"
        content={description}
        style={{ width: 350 }}
      />
    </div>
  );
};
