recedit(){
# Check if sufficient arguments are provided
if [ $# -lt 2 ]; then
    echo "Usage: recedit <operation> <ID>"
    # exit 1
fi

operation=$1
id=$2
file="s4csb1.txt"

# Check if the file exists
if [ ! -f "$file" ]; then
    echo "Error: File '$file' does not exist."
    # exit 1
fi

# Function to check if a student exists
student_exists() {
    grep -q "^$id," "$file"
}

# Perform operations based on the first argument
case $operation in
    add)
        # Check if the student already exists
        if student_exists; then
            echo "Error: Student with ID $id already exists."
            exit 1
        fi
        # Get the other details
        echo "Enter Name:"
        read name
        echo "Enter Address:"
        read address
        echo "Enter Phone No:"
        read phone
        echo "Enter Email:"
        read email

        # Add the new record
        echo "$id,$name,$address,$phone,$email" >> "$file"
        echo "Student with ID $id added successfully."
        ;;
    search)
        # Search for the student
        if student_exists; then
            grep "^$id," "$file"
        else
            echo "Error: No student found with ID $id."
        fi
        ;;
    update)
        # Check if the student exists
        if ! student_exists; then
            echo "Error: No student found with ID $id."
            exit 1
        fi
        # Get the new details
        echo "Enter New Name:"
        read name
        echo "Enter New Address:"
        read address
        echo "Enter New Phone No:"
        read phone
        echo "Enter New Email:"
        read email

        # Update the record
        sed -i "/^$id,/c\\$id,$name,$address,$phone,$email" "$file"
        echo "Student with ID $id updated successfully."
        ;;
    delete)
        # Check if the student exists
        if ! student_exists; then
            echo "Error: No student found with ID $id."
            exit 1
        fi
        # Delete the record
        sed -i "/^$id,/d" "$file"
        echo "Student with ID $id deleted successfully."
        ;;
    *)
        echo "Error: Invalid operation. Use add, search, update, or delete."
        exit 1
        ;;
esac
}
