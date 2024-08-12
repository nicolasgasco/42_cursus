import { TooltipIcon, TooltipIconProps } from "../TooltipIcon";

interface LayerTileProps {
  children: React.ReactNode;
  title: string;
  tooltipProps?: TooltipIconProps;
}

export const LayerTile = ({
  children,
  title,
  tooltipProps,
  ...restProps
}: LayerTileProps): JSX.Element => {
  return (
    <div {...restProps}>
      <div className="flex items-center gap-2 mb-1">
        <h3 className="title-4">{title}</h3>
        {tooltipProps && <TooltipIcon {...tooltipProps} />}
      </div>
      <div className="flex-auto flex flex-col border-solid border-4 border-slate-800 rounded-md p-3 gap-3">
        {children}
      </div>
    </div>
  );
};
