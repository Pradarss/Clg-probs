import React, { useState, useEffect } from 'react';

function App() {
  const [posts, setPosts] = useState([]);
  const [title, setTitle] = useState('');
  const [content, setContent] = useState('');
  
  useEffect(() => {
      fetchPosts();
  }, []);

  const fetchPosts = () => {
      fetch('http://localhost:5000/api/posts')
          .then(res => res.json())
          .then(data => setPosts(data))
          .catch(err => console.error(err));
  };

  const handleInputChange = (event) => {
      const { name, value } = event.target;
      if (name === 'title') setTitle(value);
      else if (name === 'content') setContent(value);
  };

  const handleSubmit = (event) => {
      event.preventDefault();
      fetch('http://localhost:5000/api/posts', {
          method: 'POST',
          headers: {
              'Content-Type': 'application/json',
          },
          body: JSON.stringify({ title, content }),
      })
      .then(() => {
          fetchPosts();
          setTitle('');
          setContent('');
      })
      .catch(err => console.error(err));
  };

  return (
<>
    <header className="header">
    <h1 className="logo">My Blog</h1>
    <nav className="nav">
        <ul className="nav-list">
            <li className="nav-item"><a href="/" className="nav-link">Home</a></li>
            <li className="nav-item"><a href="/about" className="nav-link">About</a></li>
            <li className="nav-item"><a href="/contact" className="nav-link">Contact</a></li>
        </ul>
    </nav>
    </header>

    <div className="container">
        <h1 className="title">Blogging Platform</h1>
        <form className="form" onSubmit={handleSubmit}>
            <input 
                type="text" 
                name="title" 
                value={title} 
                onChange={handleInputChange} 
                placeholder="Enter title" 
                required 
                className="input"
            />
            <textarea 
                name="content" 
                value={content} 
                onChange={handleInputChange} 
                placeholder="Enter content" 
                required 
                className="textarea"
            ></textarea>
            <button type="submit" className="button">Add Post</button>
        </form>
        <ul className="post-list">
            {posts.map(post => (
                <li key={post._id} className="post-item">
                    <h2 className="post-title">{post.title}</h2>
                    <p className="post-content">{post.content}</p>
                </li>
            ))}
        </ul>
    </div>

    <footer className="footer">
            <p className="footer-text">© 2024 My Blog. All rights reserved.</p>
        </footer>
  </>
  );
}

export default App;
