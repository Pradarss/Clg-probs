const express = require('express');
const mongoose = require('mongoose');
const cors = require("cors");

const app = express();
app.use(cors({
    origin: "http://localhost:3000",
    methods: "GET,HEAD,PUT,PATCH,POST,DELETE",
    credentials: true,
    optionsSuccessStatus: 204,
}));
app.use(express.json());

mongoose.connect('mongodb://localhost:27017/bookstore')
.then(() => console.log('Connected to MongoDB'))
.catch(err => console.error('Could not connect to MongoDB', err));

const bookSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true
    },
    author: {
        type: String,
        required: true
    },
    genre: {
        type: String,
        required: true
    },
    publishedYear: {
        type: Number,
        required: true
    },
    description: String,
    quantity: {
        type: Number,
        default: 1
    }
});

const Book = mongoose.model('Book', bookSchema);

app.get('/api/books', async (req, res) => {
    try {
        const books = await Book.find();
        res.send(books);
    } catch (error) {
        console.error(error);
        res.status(500).send('Error fetching books');
    }
});

app.post('/api/books/search', async (req, res) => {
    const { title } = req.body;
    try {
        const book = await Book.findOne({ title });
        res.send(book);
    } catch (error) {
        console.error(error);
        res.status(500).send('Error searching book');
    }
});

app.post('/api/books/add', async (req, res) => {
    const { title, author, genre, publishedYear, description } = req.body;
    try {
        const newBook = await Book.create({ title, author, genre, publishedYear, description });
        res.json(newBook);
    } catch (error) {
        console.error(error);
        res.status(500).send('Error adding book');
    }
});

const port = process.env.PORT || 5000;
app.listen(port, () => console.log(`Server running on port ${port}`));
