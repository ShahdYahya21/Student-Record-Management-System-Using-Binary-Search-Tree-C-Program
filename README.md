## Student Record Management System Using Binary Search Tree (C Program)

This C program implements a **Student Record Management System** using a **Binary Search Tree (BST)**. It allows efficient insertion, deletion, and searching of student records based on unique student IDs.

---

### Core BST Operations

- **`Insert(struct Node* root, int id, char* name, char* address, char* className, char* city)`**  
  - Inserts a new student record into the BST.

- **`Find(struct Node* root, int id)`**  
  - Searches for a student record by ID.

- **`FindMin(struct Node* root)`**  
  - Finds the student record with the smallest ID.

- **`FindMax(struct Node* root)`**  
  - Finds the student record with the largest ID.

- **`Delete(struct Node* root, int id)`**  
  - Deletes a student record by ID.

- **`PrintInOrder(struct Node* root)`**  
  - Displays all student records in ascending order of ID.

- **`DeleteTree(struct Node* root)`**  
  - Frees all memory allocated for the BST.

---

### Sorting & Filtering Operations

- **`toArrayOfStruct(struct Node* root, struct Student arr[], int* index)`**  
  - Converts BST data to an array for sorting.

- **`mergeSort(struct Student arr[], int left, int right)`**  
  - Sorts student records using **Merge Sort**.

- **`toArrayOfStructCity(struct Node* root, struct Student arr[], int* index, char* city)`**  
  - Filters student records by city and stores them in an array.

- **`toArrayOfStructClass(struct Node* root, struct Student arr[], int* index, char* className)`**  
  - Filters student records by class and stores them in an array.

---

### Features

- Uses **Binary Search Tree (BST)** for efficient record management.
- Supports **Insertion, Deletion, and Search** by Student ID.
- **In-Order Traversal** for displaying records in sorted order.
- Implements **Merge Sort** for sorting records by student names.
- Provides **filtering options** by city and class.
- Reads student records from a **file** and supports **manual entry**.
  
---

### Program Output Example
When running the program, the user is presented with the following menu:

#### Welcome to the School Program

#### Choose one of the selections:
1) Insert a student with all its associated data (studentID, studentName, address, classID, date of enrollment)  
2) Update the student info  
3) List all students in lexicographic order of their names  
4) Search for a city and list all students from that city in lexicographic order  
5) List all students by their class in lexicographic order of their names  
6) Delete a student  
7) Save all students in file `students.data`  
8) Exit  

---

#### If the User Chooses 1: Insert a Student  
#### Enter the data of the student:
- **Student ID:** `200`  
- **Name:** `Shahd`  
- **Address:** `Jenin`  
- **Class ID:** `4`  
- **Date of Enrollment:** `August28,2021`

#### Current Students List:  
- 121 Ahmad Ramallah 1 June22,2022  
- 200 Shahd Jenin 4 August28,2021  
- 292 Noor Ramallah 2 August24,2021  
- 323 Lana Jerusalem 3 May25,2021  
- 328 Amr Jerusalem 3 May25,2021  
- 344 Lona Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  

---

#### If the User Chooses 2: Update Student Info  
#### Enter the student ID:  
**292**  

#### Enter the new information of the student:  
- **Name:** `Rami`  
- **Address:** `Hebron`  
- **Class ID:** `4`  
- **Date of Enrollment:** `June25,2021`

#### Updated Students List:  
- 121 Ahmad Ramallah 1 June22,2022  
- 200 Shahd Jenin 4 August28,2021  
- 292 Rami Hebron 4 June25,2021  
- 323 Lana Jerusalem 3 May25,2021  
- 328 Amr Jerusalem 3 May25,2021  
- 344 Lona Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  

---

#### If the User Chooses 3: List All Students in Lexicographic Order  
#### No input required. The program automatically sorts the list:

- 121 Ahmad Ramallah 1 June22,2022  
- 328 Amr Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  
- 323 Lana Jerusalem 3 May25,2021  
- 344 Lona Jerusalem 3 May25,2021  
- 292 Rami Hebron 4 June25,2021  
- 200 Shahd Jenin 4 August28,2021  

---

#### If the User Chooses 4: Search for a City  
#### Enter the name of the city:  
**Jerusalem**  

#### Students from Jerusalem in Lexicographic Order:  
- 328 Amr Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  
- 323 Lana Jerusalem 3 May25,2021  
- 344 Lona Jerusalem 3 May25,2021  

---

#### If the User Chooses 5: List All Students by Class  
#### Enter the ID of the class:  
**3**  

#### Students in Class 3 (Sorted Lexicographically):  
- 328 Amr Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  
- 323 Lana Jerusalem 3 May25,2021   
- 344 Lona Jerusalem 3 May25,2021  

---

#### If the User Chooses 6: Delete a Student  
#### Enter the student ID:  
**323**  

#### Updated Students List After Deletion:  
- 121 Ahmad Ramallah 1 June22,2022  
- 328 Amr Jerusalem 3 May25,2021  
- 345 Anas Jerusalem 3 May25,2021  
- 344 Lona Jerusalem 3 May25,2021  
- 292 Rami Hebron 4 June25,2021  
- 200 Shahd Jenin 4 August28,2021  

---

#### If the User Chooses 7: Save All Students in File  
No input required. All students are saved in the file `students.data`.

---

#### If the User Chooses 8: Exit  
No input required. The user exits the school program.  

---

#### Special User Input Handling:
- **Validations**: Ensure the student ID, class ID, and dates follow the expected formats (e.g., `ID` as integers, `date` as `MonthDay,Year`).
- **Error Handling**: If invalid data is entered (e.g., non-existent student ID or incorrectly formatted date), prompt the user to re-enter valid information.
