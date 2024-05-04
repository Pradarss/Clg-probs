const express = require('express');
const cors = require("cors");
const mongoose = require('mongoose');

const app = express();
app.use(cors({
    origin: "http://localhost:3000",
    methods: "GET,HEAD,PUT,PATCH,POST,DELETE",
    credentials: true,
    optionsSuccessStatus: 204,
}));
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/task_management')
.then(() => console.log('Connected to MongoDB'))
.catch(err => console.error('Could not connect to MongoDB', err));

const taskSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true
    },
    completed: {
        type: Boolean,
        default: false
    }
});

const Task = mongoose.model('Task', taskSchema);

app.get('/api/tasks', async (req, res) => {
    try {
        const tasks = await Task.find();
        res.send(tasks);
    } catch (error) {
        console.error(error);
        res.status(500).send('Error fetching tasks');
    }
});

app.post('/api/tasks/add', async (req, res) => {
    const { title, completed } = req.body;
    try {
        const newTask = await Task.create({ title, completed });
        res.json(newTask);
    } catch (error) {
        console.error(error);
        res.status(500).send('Error adding task');
    }
});

const port = process.env.PORT || 5000;
app.listen(port, () => console.log(`Server running on port ${port}`));
