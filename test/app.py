from flask import Flask
from pymongo import MongoClient

app = Flask(__name__)

# MongoDB connection
client = MongoClient("mongodb://localhost:27017/")
db = client.school  # Replace with your database name

@app.route('/')
def index():
    users = db.students.find()  # Fetching data from the 'users' collection
    return str(list(users))  # Display the users

if __name__ == '__main__':
    app.run(debug=True)

