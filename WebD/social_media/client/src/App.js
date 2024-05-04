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
    <h1 className="logo">Social Media</h1>
    <nav className="nav">
        <ul className="nav-list">
            <li className="nav-item"><a href="/" className="nav-link">Home</a></li>
            <li className="nav-item"><a href="/about" className="nav-link">About</a></li>
            <li className="nav-item"><a href="/contact" className="nav-link">Contact</a></li>
        </ul>
    </nav>
    </header>

    <div className="container">
    <h1 className="heading">Social Media Platform</h1>
    <form onSubmit={handleSubmit}>
        <input 
            type="text" 
            name="title" 
            value={title} 
            onChange={handleInputChange} 
            placeholder="Enter title" 
            className="input-field"
            required 
        />
        <textarea 
            name="content" 
            value={content} 
            onChange={handleInputChange} 
            placeholder="Enter content" 
            className="textarea-field"
            required
        ></textarea>
         <input
            type="file"
            accept="image/*" 
            className="image-input"
          />
        <button type="submit" className="submit-button">Add Post</button>
    </form>
    <ul className="post-list">
        {posts.map(post => (
            <li key={post._id} className="post-item">
              <img className='post-image' src="https://images.unsplash.com/photo-1575936123452-b67c3203c357?q=80&w=1000&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxzZWFyY2h8Mnx8aW1hZ2V8ZW58MHx8MHx8fDA%3D" alt="Image Description" />
                <h2 className="post-title">{post.title}</h2>
                <p className="post-content">{post.content}</p>
            </li>
        ))}
    </ul>
</div>

<footer className="footer">
            <p className="footer-text">© 2024 Social Media. All rights reserved.</p>
        </footer>
</>
  );
}

export default App;
