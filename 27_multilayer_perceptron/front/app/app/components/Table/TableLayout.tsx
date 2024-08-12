interface TableLayoutProps {
  children: React.ReactNode;
}

export const TableLayout = ({ children }: TableLayoutProps) => {
  return <table className="table-auto m-2 text-sm">{children}</table>;
};
