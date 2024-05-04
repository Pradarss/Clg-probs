import React, { useState, useEffect } from 'react';

function App() {
    const [books, setBooks] = useState([]);
    const [searchTerm, setSearchTerm] = useState('');
    const [searchResult, setSearchResult] = useState(null);
    const [newBook, setNewBook] = useState({
        title: '',
        author: '',
        genre: '',
        publishedYear: '',
        description: ''
    });

    useEffect(() => {
        fetchBooks();
    }, []);

    const fetchBooks = () => {
        fetch('http://localhost:5000/api/books')
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok');
                }
                return response.json();
            })
            .then(data => setBooks(data))
            .catch(error => console.error(error));
    };

    const handleSearch = () => {
        const result = books.find(book => book.title.toLowerCase() === searchTerm.toLowerCase());
        setSearchResult(result);
    };

    const handleInputChange = (e) => {
        const { name, value } = e.target;
        setNewBook(prevState => ({
            ...prevState,
            [name]: value
        }));
    };

    const handleAddBook = () => {
        fetch('http://localhost:5000/api/books/add', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(newBook)
        })
        .then(response => response.json())
        .then(data => {
            console.log('Book added:', data);
            setNewBook({
                title: '',
                author: '',
                genre: '',
                publishedYear: '',
                description: ''
            });
            fetchBooks();
        })
        .catch(error => console.error('Error adding book:', error));
    };

    return (
        <>
    <header className="header">
    <h1 className="logo">Stock keeper</h1>
    <nav className="nav">
        <ul className="nav-list">
            <li className="nav-item"><a href="/" className="nav-link">Home</a></li>
            <li className="nav-item"><a href="/about" className="nav-link">About</a></li>
            <li className="nav-item"><a href="/contact" className="nav-link">Contact</a></li>
        </ul>
    </nav>
    </header>
        <div className="container">
            <h1 className="heading">Bookstore Library</h1>
            <h2>User Interface</h2>
            <div className="input-container">
                <input 
                    type="text" 
                    className="search-input" 
                    placeholder="Search book by title" 
                    value={searchTerm}
                    onChange={(e) => setSearchTerm(e.target.value)}
                />
                <button className="button" onClick={handleSearch}>Search</button>
            </div>
            {searchResult ? (
                <div className="book-details">
                    <h2>Book found!</h2>
                    <p>Title: {searchResult.title}</p>
                    <p>Author: {searchResult.author}</p>
                </div>
            ) : (
                <p className="no-book">No book found.</p>
            )}
            <h2>Admin Interface</h2>
            <h2 className="sub-heading">Add New Book</h2>
            <div className="input-container">
                <input 
                    type="text" 
                    className="input" 
                    placeholder="Title" 
                    name="title"
                    value={newBook.title}
                    onChange={handleInputChange}
                />
                <input 
                    type="text" 
                    className="input" 
                    placeholder="Author" 
                    name="author"
                    value={newBook.author}
                    onChange={handleInputChange}
                />
                <input 
                    type="text" 
                    className="input" 
                    placeholder="Genre" 
                    name="genre"
                    value={newBook.genre}
                    onChange={handleInputChange}
                />
                <input 
                    type="text" 
                    className="input" 
                    placeholder="Published Year" 
                    name="publishedYear"
                    value={newBook.publishedYear}
                    onChange={handleInputChange}
                />
                <input 
                    type="text" 
                    className="input" 
                    placeholder="Description" 
                    name="description"
                    value={newBook.description}
                    onChange={handleInputChange}
                />
                <button className="button" onClick={handleAddBook}>Add Book</button>
            </div>
        </div>

        <footer className="footer">
            <p className="footer-text">© 2024 Stock keeper. All rights reserved.</p>
        </footer>
</>
    );
}

export default App;
