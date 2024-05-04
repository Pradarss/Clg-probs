const express = require('express');
const http = require('http');
const cors = require("cors");
const app = express();

app.use(cors({
    origin: "http://localhost:3000",
    methods: "GET,HEAD,PUT,PATCH,POST,DELETE",
    credentials: true,
    optionsSuccessStatus: 204,
}));

app.get('/api/weather', (req, res) => {
    const city = req.query.city;
    const apiKey = '43484b3ebe964d28bcd65048240405'; 
    const apiUrl = `http://api.weatherapi.com/v1/current.json?key=${apiKey}&q=${city}`;

    const request = http.get(apiUrl, (response) => {
        let data = '';

        response.on('data', (chunk) => {
            data += chunk;
        });

        response.on('end', () => {
            try {
                const weatherData = JSON.parse(data);
                const weather = {
                    city: weatherData.location.name,
                    temperature: weatherData.current.temp_c,
                    description: weatherData.current.condition.text
                };
                res.json(weather);
            } catch (error) {
                console.error(error);
                res.status(500).send('Error parsing weather data');
            }
        });
    });

    request.on('error', (error) => {
        console.error(error);
        res.status(500).send('Error fetching weather data');
    });
});

const port = process.env.PORT || 5000;
app.listen(port, () => console.log(`Server running on port ${port}`));
