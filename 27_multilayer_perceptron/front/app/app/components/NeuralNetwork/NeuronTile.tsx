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
      className="flex-auto bg-slate-700 rounded-md p-6"
      style={{ minWidth: 275 }}
      {...restProps}
    >
      <h4 className="title-5 mb-4">{title}</h4>
      {children}
    </div>
  );
};
