
interface StatusIndicatorProps {
  percentage: number;
  className?: string;
}

export const StatusIndicator = ({ percentage, ...restProps }: StatusIndicatorProps): JSX.Element => {
  if (percentage < 80) {
    return <span {...restProps}>🔴</span>
  } else if (percentage < 90) {
    return <span {...restProps}>🟡</span>
  } else {
    return <span {...restProps}>🟢</span>
  }
};