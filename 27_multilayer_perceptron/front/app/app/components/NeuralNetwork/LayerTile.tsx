interface LayerTileProps {
  children: React.ReactNode;
  title: string;
}

export const LayerTile = ({
  children,
  title,
  ...restProps
}: LayerTileProps): JSX.Element => {
  return (
    <div {...restProps}>
      <h3 className="title-4">{title}</h3>
      <div className="flex-auto flex flex-col border-solid border-4 border-slate-800 rounded-md p-3 gap-3">
        {children}
      </div>
    </div>
  );
};
