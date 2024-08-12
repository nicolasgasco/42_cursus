interface TableHeaderProps {
  children: React.ReactNode;
  key?: number;
}

export const TableHeader = ({
  key,
  children,
  ...restProps
}: TableHeaderProps): JSX.Element => {
  return (
    <th key={key} className="px-6 pb-2 border-b-2" {...restProps}>
      {children}
    </th>
  );
};
