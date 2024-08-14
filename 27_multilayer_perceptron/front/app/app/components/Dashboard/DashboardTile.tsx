import { TooltipIcon, TooltipIconProps } from "../TooltipIcon";

interface DashboardTileProps {
  children: React.ReactNode;
  title: string;
  tooltipProps?: TooltipIconProps;
}
export const DashboardTile = ({
  children,
  title,
  tooltipProps,
}: DashboardTileProps): JSX.Element => {
  return (
    <div
      className="flex-auto flex flex-col justify-between bg-slate-700 rounded-md p-4"
      style={{ minWidth: 215 }}
    >
      <div className="flex items-center justify-between	gap-2 mb-4">
        <h3 className="font-bold title-5">{title}</h3>
        {tooltipProps && <TooltipIcon {...tooltipProps} />}
      </div>
      <div className="text-sm">{children}</div>
    </div>
  );
};
