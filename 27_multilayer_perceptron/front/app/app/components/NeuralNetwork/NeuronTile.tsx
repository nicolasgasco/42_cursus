interface NeuronTileProps {
  children: React.ReactNode
}

export const NeuronTile = ({ children, ...restProps }: NeuronTileProps): JSX.Element => {
  return (
    <div className="flex-auto bg-slate-700 rounded-md p-6" {...restProps}>
      {children}
    </div>
  )
};