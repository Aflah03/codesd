recedit(){
FILE="s4csb1.txt"

# Function to display an error and exit
error_exit() {
    echo "Error: $1"
    exit 1
}

# Check if sufficient arguments are provided
if [ "$#" -lt 2 ]; then
    error_exit "Insufficient arguments. Usage: recedit <operation> <AdmnNo>"
fi

# Read operation and ID from arguments
OP=$1
ID=$2

# Validate ID
if ! [[ "$ID" =~ ^[0-9]+$ ]]; then
    error_exit "Invalid admission number. It must be numeric."
fi

# Ensure the file exists
if [ ! -f "$FILE" ]; then
    touch "$FILE"
fi

# Perform the specified operation
case "$OP" in
    add)
        # Check if the ID already exists
        if grep -q "^$ID," "$FILE"; then
            error_exit "A record with admission number $ID already exists."
        fi

        # Get student details
        echo "Enter Name:"
        read -r NAME
        echo "Enter Address:"
        read -r ADDRESS
        echo "Enter Phone Number:"
        read -r PHONE
        echo "Enter Email:"
        read -r EMAIL

        # Add the record to the file
        echo "$ID,$NAME,$ADDRESS,$PHONE,$EMAIL" >> "$FILE"
        echo "Record added successfully."
        ;;
    search)
        # Search for the student record
        RECORD=$(grep "^$ID," "$FILE")
        if [ -n "$RECORD" ]; then
            echo "Student Record: $RECORD"
        else
            error_exit "No record found for admission number $ID."
        fi
        ;;
    update)
        # Search for the student record
        if ! grep -q "^$ID," "$FILE"; then
            error_exit "No record found for admission number $ID."
        fi

        # Get new student details
        echo "Enter new Name:"
        read -r NAME
        echo "Enter new Address:"
        read -r ADDRESS
        echo "Enter new Phone Number:"
        read -r PHONE
        echo "Enter new Email:"
        read -r EMAIL

        # Update the record
        sed -i "/^$ID,/c\\$ID,$NAME,$ADDRESS,$PHONE,$EMAIL" "$FILE"
        echo "Record updated successfully."
        ;;
    delete)
        # Check if the ID exists
        if ! grep -q "^$ID," "$FILE"; then
            error_exit "No record found for admission number $ID."
        fi

        # Delete the record
        sed -i "/^$ID,/d" "$FILE"
        echo "Record deleted successfully."
        ;;
    *)
        error_exit "Invalid operation. Use one of: add, search, update, delete."
        ;;
esac

}
