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
      className="flex-auto bg-slate-800 rounded-md p-4"
      style={{ minWidth: 275 }}
      {...restProps}
    >
      <h3 className="title-5 mb-4">{title}</h3>
      {children}
    </div>
  );
};
