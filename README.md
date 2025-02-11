# TO-DO
# C To-Do List Manager

This is a simple command-line To-Do List Manager written in C. It allows you to add, list, complete, and delete tasks, as well as save and load your to-do list from a file.

## Features

*   Add new tasks with descriptions.
*   List all pending and completed tasks.
*   Mark tasks as complete.
*   Delete tasks.
*   Save the to-do list to a file (tasks.txt).
*   Load the to-do list from a file on startup.
*   Clear the task file.

## How to Compile and Run

1.  Make sure you have a C compiler (like GCC) installed.
2.  Save the code files (`todo.h`, `todo.c`, `main.c`) in the same directory.
3.  Open a terminal or command prompt and navigate to that directory.
4.  Compile the code using the following command:

    ```bash
    gcc main.c todo.c -o todo
    ```

5.  Run the executable:

    ```bash
    ./todo
    ```

## How to Use

1.  Run the program.
2.  The program will display a menu of options.
3.  Enter the number corresponding to the action you want to perform.
4.  Follow the prompts to add, list, complete, or delete tasks.
5.  Choose option 5 to save your tasks to the "tasks.txt" file.
6.  Choose option 6 to exit the program.

## File Format (tasks.txt)

The `tasks.txt` file stores the tasks in the following format:
