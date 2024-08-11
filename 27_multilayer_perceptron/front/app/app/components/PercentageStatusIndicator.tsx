
interface PercentageStatusIndicatorProps {
  percentage: number
}

export const PercentageStatusIndicator = ({ percentage }: PercentageStatusIndicatorProps): JSX.Element => {
  if (percentage < 85) {
    return <span>🔴</span>
  } else if (percentage < 95) {
    return <span>🟡</span>
  } else {
    return <span>🟢</span>
  }
};