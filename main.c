#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node{
    int studentID;
    char studentName[100];
    char address[100];
    int classID;
    char date[100];
    struct Node* left;
    struct Node* right;
};

typedef struct Node* TNode;
TNode MakeEmpty(TNode T);
TNode FindMin(TNode T);
TNode FindMax(TNode T);
TNode Insert(TNode T,int studentID,char* studentName,char* address,int classID,char* date);
TNode Delete(int X, TNode T);
TNode Find(int studentID, TNode T);


// Function to make the tree empty
TNode MakeEmpty(TNode T){
    if(T != NULL){
        MakeEmpty(T -> left);
        MakeEmpty(T -> right);
        free(T);

    }
    return NULL;
}
// Function to find a node with a specific student ID
TNode Find(int studentID, TNode T){
    if(T == NULL)
        return NULL;

    else if(studentID <  T -> studentID)
        return Find(studentID, T -> left);

    else if(studentID > T -> studentID)
        return Find(studentID, T -> right);

    else return T;
}

// Function to find the node with the minimum value
TNode FindMin(TNode T){
    if(T == NULL)
        return NULL;

    else if(T -> left == NULL)
        return T;

    else return FindMin(T -> left);

}

// Function to find the node with the maximum value
TNode FindMax(TNode T){
    if(T == NULL)
        return NULL;

    else if(T -> right == NULL)
        return T;

    else return FindMax(T -> right);
}

// Function to insert a new node into the tree
TNode Insert(TNode T,int studentID,char* studentName,char* address,int classID,char* date) {
    if (T == NULL) {
        T = (struct Node*)malloc(sizeof(struct Node));
        if (T == NULL)
            printf("Out of space");
        else {
            T->studentID = studentID;
            strcpy(T -> studentName,studentName);
            strcpy(T -> address,address);
            T -> classID = classID;
            strcpy(T -> date,date);
            T->left = NULL;
            T->right = NULL;

        }
    }
    else if (studentID < T -> studentID)
        T->left = Insert(T->left,studentID, studentName, address, classID, date);
    else if (studentID > T -> studentID)
        T->right = Insert(T->right,studentID, studentName, address, classID, date);

    return T;

}

// Function to delete a node from the tree
TNode Delete(int studentID, TNode T){
    TNode TempCell;
    if(T == NULL) printf("element not found");

    else if(studentID < T -> studentID){
        T -> left = Delete(studentID, T -> left);

    }
    else if(studentID > T -> studentID){
        T -> right = Delete(studentID, T -> right);
    }
    else{
        if(T -> left && T -> right){
            TempCell = FindMin(T -> right);
            T -> studentID = TempCell -> studentID;
            T -> right = Delete(T -> studentID, T -> right);
        }

        else{
            TempCell = T;
            if(T -> left == NULL){
                T = T -> right;
            }
            else if(T -> right == NULL){
                T = T -> left;
            }
            free(TempCell);
        }
    }
    return T;
}

// Function to update the information of a node
void UpdateInfo(TNode T,char* Name,char* address,int classID,char* date){
    strcpy(T -> studentName,Name);
    strcpy(T -> address,address);
    T -> classID = classID;
    strcpy(T -> date,date);

}

// Function to perform an inorder traversal of the tree
void InorderTraversal(TNode T) {
    if (T != NULL) {
        InorderTraversal(T->left);
        printf("%d %s %s %d %s\n", T->studentID, T->studentName, T ->address, T->classID, T->date);
        InorderTraversal(T->right);
    }
}



//Struct named student have all the property of the student
struct students{
    int studentID;
    char studentName[100];
    char address[100];
    int classID;
    char date[100];
};
void merge(struct students* students, int low, int mid, int high);
void mergeSort(struct students* students, int low, int high);
void toArrayOfstruct(TNode T, struct students* arr, int* k);
void toArrayOfstructCity(TNode T, struct students* arr, int* k,char* city);
void toArrayOfstructClass(TNode T, struct students* arr, int* k,int classId);
void PrintOnFile(TNode T);


int main() {
    FILE *ptr;
    ptr = fopen("/Users/shahdyahya/Desktop/datastructure/Project 3/Input", "r");
    if (ptr == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }
    // Initialize the tree
    TNode T = MakeEmpty(T);
    int studentID;
    char studentName[100];
    char address[100];
    int classID;
    char date[100];
    while (fscanf(ptr, "%d %s %s %d %s", &studentID, studentName, address,&classID, date) != EOF) {
        //Insert the data in the file in the tree
            T = Insert(T,studentID, studentName, address,classID, date);

    }
    fclose(ptr);




    printf("Welcome to the school program\nChoose one of the selections\n1)Insert a student with all its associated data(studentID,studentName,address,classID,date of enrollment)\n2)update the student info\n3)List all students in lexicographic order of their names\n4)Search for a city and list all students from that city in lexicographic order\n5)List all students by their class in lexicographic order of their names\n6)Delete a student\n7)Save all students in file students.data\n8)Exit\n");
    int choice;
    scanf("%d",&choice);
    bool start = true;
    while (true) {
        if(start == false){
            printf("Welcome to the school program\nChoose one of the selections\n1)Insert a student with all its associated data(studentID,studentName,address,classID,date of enrollment)\n2)update the student info\n3)List all students in lexicographic order of their names\n4)Search for a city and list all students from that city in lexicographic order\n5)List all students by their class in lexicographic order of their names\n6)Delete a student\n7)Save all students in file students.data\n8)Exit\n");
            scanf("%d",&choice);

        }
       start = false;
        if (choice == 1) {
            //Add new student
          printf("Enter the data of the students\n");
          scanf("%d %s %s %d %s",&studentID, studentName,address,&classID, date);
          Insert(T,studentID, studentName,address,classID, date);
            InorderTraversal(T);


        }
        //update the student info
        else if (choice == 2) {
            TNode T1 = NULL;
            printf("Enter the student ID\n");
            scanf("%d",&studentID);
            T1 = Find(studentID,T);
            //Check if the student to be added exist in the graph or not
            if(T1 == NULL) printf("there is no student with this id");
            else{

                printf("Enter the new information of the student(studentName,address,class ID,date)\n");
                scanf("%s %s %d %s",studentName,address,&classID,date);
                UpdateInfo(T1,studentName,address,classID,date);

            }
            InorderTraversal(T);

        }
        //To List all students in lexicographic order of their names
        else if (choice == 3) {
            // First we initialize an array of struct of students
            struct students* arr = (struct students*)malloc(1000 * sizeof(struct students));
            int k = 0;
            // I Fill an array with students info to sort it according to their names
            toArrayOfstruct(T,arr,&k);
            mergeSort(arr,0,k - 1);
            for(int i = 0; i < k; i++){
                printf("%d %s %s %d %s\n", arr[i].studentID, arr[i].studentName, arr[i].address, arr[i].classID, arr[i].date);

            }
        }
        //To sort the students according to their city
        else if (choice == 4) {
            // First we initialize an array of struct of students from a certain city
            struct students* arr = (struct students*)malloc(1000 * sizeof(struct students));
            char city[100];
            int k = 0;
            printf("Enter the name of the city\n");
            scanf("%s",city);
            // I Fill an array with students info to sort it according to their names
            toArrayOfstructCity(T, arr, &k,city);
            mergeSort(arr,0,k - 1);
            for(int i = 0; i < k; i++){
                printf("%d %s %s %d %s\n", arr[i].studentID, arr[i].studentName, arr[i].address, arr[i].classID, arr[i].date);

            }
            printf("\n");

        }
            //To sort the students according to their class
        else if (choice == 5) {
            // First we initialize an array of struct of students from a certain city
            struct students* arr = (struct students*)malloc(1000 * sizeof(struct students));
            printf("Enter the ID of the class\n");
            scanf("%d",&classID);
            int k = 0;
            // I Fill an array with students info to sort it according to their names
            toArrayOfstructClass(T, arr, &k,classID);
            mergeSort(arr,0,k - 1);
            for(int i = 0; i < k; i++){
                printf("%d %s %s %d %s\n", arr[i].studentID, arr[i].studentName, arr[i].address, arr[i].classID, arr[i].date);

            }
            printf("\n");



        }
        //Delete a student
        else if (choice == 6) {
            printf("Enter the student ID\n");
            scanf("%d",&studentID);
            Delete(studentID,T);

        }
         //Print the student info on the output file
        else if (choice == 7) {
            PrintOnFile(T);

        }
        //Exit
        else if(choice == 8){
               break;
         }

        else{
            printf("Invalid input\n");
        }


    }

    printf("the program ended");


}
// Function to convert the tree into an array of students
void toArrayOfstruct(TNode T, struct students* arr, int* k) {
    if (T != NULL) {
        toArrayOfstruct(T->left, arr, k);

        // Copy student information to the array
        arr[*k].studentID = T->studentID;
        strcpy(arr[*k].studentName, T->studentName);
        strcpy(arr[*k].address, T->address);
        arr[*k].classID = T->classID;
        strcpy(arr[*k].date, T->date);

        (*k)++; // Increment the pointer value to update the index
        toArrayOfstruct(T->right, arr, k);
    }
}

// Function to convert the tree into an array of students from a specific city
void toArrayOfstructCity(TNode T, struct students* arr, int* k,char* city) {
    if (T != NULL) {
        toArrayOfstructCity(T->left, arr, k,city);
        // Check if the student's address matches the specified city
        if(strcmp(T->address, city) == 0) {
            // Copy student information to the array
            arr[*k].studentID = T->studentID;
            strcpy(arr[*k].studentName, T->studentName);
            strcpy(arr[*k].address, T->address);
            arr[*k].classID = T->classID;
            strcpy(arr[*k].date, T->date);
            (*k)++;
        }
        toArrayOfstructCity(T->right, arr, k,city);
    }
}
// Function to convert the tree into an array of students from a specific class
void toArrayOfstructClass(TNode T, struct students* arr, int* k,int classId) {
    if (T != NULL) {
        toArrayOfstructClass(T->left, arr, k,classId);
        // Check if the student's class matches the specified class ID
        if(T -> classID == classId) {
            // Copy student information to the array
            arr[*k].studentID = T->studentID;
            strcpy(arr[*k].studentName, T->studentName);
            strcpy(arr[*k].address, T->address);
            arr[*k].classID = T->classID;
            strcpy(arr[*k].date, T->date);
            (*k)++;
        }
        toArrayOfstructClass(T->right, arr, k,classId);
    }
}

// Function to perform merge sort on an array of students
void mergeSort(struct students* students, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(students, low, mid);
        mergeSort(students, mid + 1, high);
        merge(students, low, mid, high);
    }
}

// Function to merge two subarrays during merge sort
void merge(struct students* students, int low, int mid, int high) {
    int i, j, k;
    int sizeOfArr1 = mid - low + 1;
    int sizeOfArr2 = high - mid;

    // Create temporary arrays to store the subarrays
    struct students* leftArray = (struct students*)malloc(sizeOfArr1 * sizeof(struct students));
    struct students* rightArray = (struct students*)malloc(sizeOfArr2 * sizeof(struct students));

    // Copy data to the temporary arrays
    for (i = 0; i < sizeOfArr1; i++) {
        leftArray[i].studentID = students[low + i].studentID;
        strcpy(leftArray[i].studentName, students[low + i].studentName);
        strcpy(leftArray[i].address, students[low + i].address);
        leftArray[i].classID = students[low + i].classID;
        strcpy(leftArray[i].date, students[low + i].date);
    }

    for (j = 0; j < sizeOfArr2; j++) {
        rightArray[j].studentID = students[mid + 1 + j].studentID;
        strcpy(rightArray[j].studentName, students[mid + 1 + j].studentName);
        strcpy(rightArray[j].address, students[mid + 1 + j].address);
        rightArray[j].classID = students[mid + 1 + j].classID;
        strcpy(rightArray[j].date, students[mid + 1 + j].date);
    }

    // Merge the temporary arrays back into the original array
    i = 0;
    j = 0;
    k = low;

    while (i < sizeOfArr1 && j < sizeOfArr2) {
        if (strcmp(leftArray[i].studentName, rightArray[j].studentName) <= 0) {
            students[k] = leftArray[i];
            i++;
        } else {
            students[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of leftArray, if any
    while (i < sizeOfArr1) {
        students[k] = leftArray[i];
        i++;
        k++;
    }
    // Copy the remaining elements of rightArray, if any
    while (j < sizeOfArr2) {
        students[k] = rightArray[j];
        j++;
        k++;
    }
    // Free the temporary arrays

}
// Function to print the students' information to a file
void PrintOnFile(TNode T) {
    if (T != NULL) {
        FILE* outputFile = fopen("/Users/shahdyahya/Desktop/datastructure/Project 3/student.Data", "a");
        if (outputFile == NULL) {
            printf("Failed to open output file\n");
            return;
        }
        PrintOnFile(T->left);
        fprintf(outputFile, "%d %s %s %d %s\n", T->studentID, T->studentName, T->address, T->classID, T->date);
        fclose(outputFile);
        PrintOnFile(T->right);
    }
}

