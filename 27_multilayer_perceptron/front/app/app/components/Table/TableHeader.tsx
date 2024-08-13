interface TableHeaderProps {
  children: React.ReactNode;
  index?: number;
  style?: React.CSSProperties;
}

export const TableHeader = ({
  children,
  index,
  style,
  ...restProps
}: TableHeaderProps): JSX.Element => {
  return (
    <th key={index} className="px-6 pb-2 border-b-2" {...restProps}>
      {children}
    </th>
  );
};
