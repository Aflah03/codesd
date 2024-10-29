from flask import Flask, render_template
from pymongo import MongoClient

app = Flask(__name__)

# MongoDB Connection
client = MongoClient("mongodb://localhost:27017/")
db = client.school  # Connect to the "school" database

# Welcome page route
@app.route('/')
def index():
    return render_template('index.html')

# Students page route
@app.route('/students')
def get_students():
    # Use db.students.find() to get all student records
    # students = db.students.find()
    students = db.students.find({"age": {"$lt": 30}})

    # Convert the cursor to a list of dictionaries
    student_list = []
    for student in students:
        student['_id'] = str(student['_id'])  # Convert ObjectId to string
        student_list.append(student)

    # Render students.html and pass the student list
    return render_template('students.html', students=student_list)

if __name__ == '__main__':
    app.run(debug=True)
