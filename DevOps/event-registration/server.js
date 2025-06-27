const express = require('express');
const mysql = require('mysql2');
const path = require('path');
const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json());
app.use(express.static(path.join(__dirname)));

const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'password', // Change as needed
    database: 'eventdb'
});

db.connect((err) => {
    if (err) throw err;
    console.log('Connected to MySQL');
});

app.post('/api/register', (req, res) => {
    const { name, email, phone, event } = req.body;
    if (!name || !email || !phone || !event) {
        return res.json({ success: false, message: 'All fields are required.' });
    }
    const sql = 'INSERT INTO registrations (name, email, phone, event) VALUES (?, ?, ?, ?)';
    db.query(sql, [name, email, phone, event], (err, result) => {
        if (err) {
            return res.json({ success: false, message: 'Database error.' });
        }
        res.json({ success: true });
    });
});

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
