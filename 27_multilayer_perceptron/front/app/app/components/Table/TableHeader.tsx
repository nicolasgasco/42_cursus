interface TableHeaderProps {
  children: React.ReactNode;
  style?: React.CSSProperties;
}

export const TableHeader = ({
  children,
  style,
  ...restProps
}: TableHeaderProps): JSX.Element => {
  return (
    <th className="px-6 pb-2 border-b-2" {...restProps}>
      {children}
    </th>
  );
};
