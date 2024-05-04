import React from 'react';

function TableComponent() {
  return (
    <div>
      <h2>Table Component</h2>
      <table>
        <thead>
          <tr>
            <th>Header 1</th>
            <th>Header 2</th>
            <th>Header 3</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td>R1, C1</td>
            <td>R1, C2</td>
            <td>R1, C3</td>
          </tr>
          <tr>
            <td>R2, C1</td>
            <td>R2, C2</td>
            <td>R2, C3</td>
          </tr>
          <tr>
            <td>R3, C1</td>
            <td>R3, C2</td>
            <td>R3, C3</td>
          </tr>
        </tbody>
      </table>
    </div>
  );
}

export default TableComponent;
