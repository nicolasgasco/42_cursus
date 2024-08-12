export const EllipsisRows = () => {
  return (
    <>
      {[0, 1].map((_, index) => {
        return (
          <tr key={index}>
            <td className="px-3 pb-1">...</td>
          </tr>
        );
      })}
    </>
  );
};
