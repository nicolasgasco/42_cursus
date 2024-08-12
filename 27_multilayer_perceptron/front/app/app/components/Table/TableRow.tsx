interface TableRowProps {
  children: React.ReactNode;
  index?: number;
}

export const TableRow = ({ children, index, ...restProps }: TableRowProps) => {
  return (
    <td className="px-3 pb-1" {...restProps}>
      {children}
    </td>
  );
};
