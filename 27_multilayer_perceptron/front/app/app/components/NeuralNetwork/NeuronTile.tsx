interface NeuronTileProps {
  children: React.ReactNode;
  title: string;
}

export const NeuronTile = ({
  children,
  title,
  ...restProps
}: NeuronTileProps): JSX.Element => {
  return (
    <div
      className="flex-auto flex flex-col items-center bg-slate-800 rounded-md p-2"
      style={{ minWidth: 220 }}
      {...restProps}
    >
      <h3 className="title-5 mb-2 self-start">{title}</h3>
      {children}
    </div>
  );
};
