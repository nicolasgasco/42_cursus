import { TooltipIcon, TooltipIconProps } from "../TooltipIcon";

interface TileProps {
  children: React.ReactNode;
  title: string;
  tooltipProps?: TooltipIconProps;
}
export const Tile = ({
  children,
  title,
  tooltipProps,
}: TileProps): JSX.Element => {
  return (
    <div
      className="flex-auto	bg-slate-700 rounded-md p-4"
      style={{ width: 275 }}
    >
      <div className="flex items-center justify-between	gap-2 mb-4">
        <h3 className="font-bold title-5">{title}</h3>
        {tooltipProps && <TooltipIcon {...tooltipProps} />}
      </div>
      <div className="text-sm">{children}</div>
    </div>
  );
};
