import React from 'react';

function ChildComponent(props) {
  const { name, age } = props.data;

  return (
    <div>
      <h2>Name: {name}</h2>
      <p>Age: {age}</p>
    </div>
  );
}

export default ChildComponent;
