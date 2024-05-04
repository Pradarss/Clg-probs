import React, { useState, useEffect } from 'react';

function App() {
  const [weather, setWeather] = useState(null);
  const [city, setCity] = useState('');

  const fetchWeather = () => {
    if (city) {
      fetch(`http://localhost:5000/api/weather?city=${city}`)
        .then(response => {
          if (!response.ok) {
            throw new Error('Network response was not ok');
          }
          return response.json();
        })
        .then(data => {
          setWeather(data);
        })
        .catch(error => {
          console.error('Error fetching weather data:', error);
        });
    }
  };

  useEffect(() => {
    fetchWeather();
  }, [city]);

  const handleInputChange = (event) => {
    setCity(event.target.value);
  };

  return (
    <>
    <header className="header">
    <h1 className="logo">Weather app</h1>
    <nav className="nav">
        <ul className="nav-list">
            <li className="nav-item"><a href="/" className="nav-link">Home</a></li>
            <li className="nav-item"><a href="/about" className="nav-link">About</a></li>
            <li className="nav-item"><a href="/contact" className="nav-link">Contact</a></li>
        </ul>
    </nav>
    </header>
    <div className="container">
    <h1>Weather Forecasting App</h1>
    <div className="input-container">
      <input type="text" placeholder="Enter city" onChange={handleInputChange} />
    </div>
    {weather && (
      <div className="weather-details">
        <h2>{weather.city}</h2>
        <p>Temperature: {weather.temperature}</p>
        <p>Weather: {weather.description}</p>
      </div>
    )}
  </div>
  <footer className="footer">
            <p className="footer-text">© 2024 weather app. All rights reserved.</p>
        </footer>
</>
  );
}

export default App;
