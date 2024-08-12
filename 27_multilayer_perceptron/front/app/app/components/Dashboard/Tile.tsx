interface TileProps {
  children: React.ReactNode;
  title: string;
}
export const Tile = ({ children, title }: TileProps): JSX.Element => {
  return (
    <div
      className="flex-auto	bg-slate-700 rounded-md p-6"
      style={{ width: 275 }}
    >
      <h3 className="font-bold title-4 mb-4">{title}</h3>
      {children}
    </div>
  );
};
