interface VisualizerTileProps {
  children: React.ReactNode
  title: string
}
export const VisualizerTile = ({ children, title }: VisualizerTileProps) => {
  return (
    <div className="flex-auto	bg-slate-700 rounded-md p-6">
      <h3 className="font-bold title-4">{title}</h3>
      {children}
    </div>
  )
}