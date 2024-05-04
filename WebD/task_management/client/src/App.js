import React, { useState, useEffect } from 'react';

const TaskManagementTool = () => {
    const [tasks, setTasks] = useState([]);
    const [newTask, setNewTask] = useState('');

    useEffect(() => {
        fetch('http://localhost:5000/api/tasks')
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok');
                }
                return response.json();
            })
            .then(data => setTasks(data))
            .catch(error => console.error(error));
    }, []);

    const handleAddTask = () => {
        fetch('http://localhost:5000/api/tasks/add', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ title: newTask, completed: false })
        })
        .then(response => response.json())
        .then(data => {
            console.log('Task added:', data);
            setNewTask('');
            fetch('http://localhost:5000/api/tasks')
                .then(response => response.json())
                .then(data => setTasks(data))
                .catch(error => console.error('Error fetching tasks:', error));
        })
        .catch(error => console.error('Error adding task:', error));
    };

    const handleInputChange = (event) => {
        setNewTask(event.target.value);
    };

    return (
        <>
        <header className="header">
        <h1 className="logo">Task manager</h1>
        <nav className="nav">
            <ul className="nav-list">
                <li className="nav-item"><a href="/" className="nav-link">Home</a></li>
                <li className="nav-item"><a href="/about" className="nav-link">About</a></li>
                <li className="nav-item"><a href="/contact" className="nav-link">Contact</a></li>
            </ul>
        </nav>
        </header>
        <div className="container">
        <h1>Task Management Tool</h1>
        <div className="input-container">
          <input 
            type="text" 
            placeholder="Enter task" 
            value={newTask} 
            onChange={handleInputChange} 
          />
          <button className="add-button" onClick={handleAddTask}>Add Task</button>
        </div>
        <ul className="tasks-list">
          {tasks.map(task => (
            <li 
              key={task._id} 
              className={`task-item ${task.completed ? 'completed' : 'incomplete'}`}
            >
              {task.title}
            </li>
          ))}
        </ul>
      </div>
      <footer className="footer">
            <p className="footer-text">© 2024 Task manager. All rights reserved.</p>
        </footer>
</>
    );
};

export default TaskManagementTool;
