document.getElementById('registrationForm').addEventListener('submit', async function(e) {
    e.preventDefault();
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;
    const event = document.getElementById('event').value;
    const response = await fetch('/api/register', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ name, email, phone, event })
    });
    let result = { success: false, message: 'Unknown error.' };
    try {
        result = await response.json();
    } catch (err) {
        result = { success: false, message: 'Server error or invalid response.' };
    }
    const messageDiv = document.getElementById('message');
    if (result.success) {
        messageDiv.innerHTML = '<div class="alert alert-success">Registration successful!</div>';
        document.getElementById('registrationForm').reset();
    } else {
        messageDiv.innerHTML = '<div class="alert alert-danger">' + result.message + '</div>';
    }
});
