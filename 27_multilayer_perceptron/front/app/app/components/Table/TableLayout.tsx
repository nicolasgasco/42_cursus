interface TableLayoutProps {
  children: React.ReactNode;
  style: React.CSSProperties;
}

export const TableLayout = ({ children, style }: TableLayoutProps) => {
  return (
    <table className="table-auto m-2 text-xs text-center" style={style}>{children}</table>
  );
};
