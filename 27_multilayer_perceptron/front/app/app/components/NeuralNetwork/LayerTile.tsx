import { TooltipIcon, TooltipIconProps } from "../TooltipIcon";

interface LayerTileProps {
  children: React.ReactNode;
  style?: React.CSSProperties;
  title: string;
  tooltipProps?: TooltipIconProps;
}

export const LayerTile = ({
  children,
  title,
  tooltipProps,
  style,
  ...restProps
}: LayerTileProps): JSX.Element => {
  return (
    <div style={style} {...restProps}>
      <div className="flex items-center gap-2 mb-1">
        <h2 className="title-5">{title}</h2>
        {tooltipProps && <TooltipIcon {...tooltipProps} />}
      </div>
      <div className="flex-auto flex flex-col border-solid border-2 border-slate-800 rounded-md p-2 gap-2">
        {children}
      </div>
    </div>
  );
};
