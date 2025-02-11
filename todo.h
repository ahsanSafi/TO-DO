#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100

typedef struct {
    char description[100];
    int completed;
} Task;

// Function Definitions (All in the header file - Bad Practice)

void display_menu() {
    printf("\nTo-Do List Manager\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Complete Task\n");
    printf("4. Delete Task\n");
    printf("5. Save Tasks\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void add_task(Task tasks[], int *num_tasks) {
    if (*num_tasks < MAX_TASKS) {
        printf("Enter task description: ");
        scanf(" %[^\n]s", tasks[*num_tasks].description);
        tasks[*num_tasks].completed = 0;
        (*num_tasks)++;
        printf("Task added.\n");
        while (getchar() != '\n'); // Clear buffer
    } else {
        printf("Task list is full.\n");
    }
}

void list_tasks(Task tasks[], int num_tasks) {
    if (num_tasks == 0) {
        printf("No tasks yet.\n");
        return;
    }
    printf("\nTo-Do List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].completed ? "Done" : "Pending");
    }
}

void complete_task(Task tasks[], int num_tasks) {
    list_tasks(tasks, num_tasks);
    if (num_tasks == 0) return;

    int task_num;
    printf("Enter the task number to complete: ");
    int result = scanf(" %d", &task_num);
    if (result != 1 || task_num < 1 || task_num > num_tasks) {
        printf("Invalid task number.\n");
        while (getchar() != '\n'); // Clear buffer
        return;
    }
    tasks[task_num - 1].completed = 1;
    printf("Task completed.\n");
    while (getchar() != '\n'); // Clear buffer
}

void delete_task(Task tasks[], int *num_tasks) {
    list_tasks(tasks, *num_tasks);
    if (*num_tasks == 0) return;

    int task_num;
    printf("Enter the task number to delete: ");
    int result = scanf(" %d", &task_num);
    if (result != 1 || task_num < 1 || task_num > *num_tasks) {
        printf("Invalid task number.\n");
        while (getchar() != '\n'); // Clear buffer
        return;
    }
    for (int i = task_num - 1; i < *num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*num_tasks)--;
    printf("Task deleted.\n");
    while (getchar() != '\n'); // Clear buffer
}

void save_tasks(Task tasks[], int num_tasks) {
    FILE *file = fopen("tasks.txt", "w"); // "w" to overwrite
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d\n", num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        fprintf(file, "%s\n%d\n", tasks[i].description, tasks[i].completed);
    }
    fclose(file);
    printf("Tasks saved.\n");
}

int load_tasks(Task tasks[]) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        return 0;
    }
    int num_tasks = 0;
    fscanf(file, "%d", &num_tasks);
    for (int i = 0; i < num_tasks; i++) {
        fgets(tasks[i].description, sizeof(tasks[i].description), file);
        tasks[i].description[strcspn(tasks[i].description, "\n")] = 0;
        fscanf(file, "%d", &tasks[i].completed);
        fgetc(file);
    }
    fclose(file);
    return num_tasks;
}

void clear_tasks_file() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        perror("Error opening file to clear");
        return;
    }
    fclose(file);
    printf("Tasks file cleared.\n");
}

#endif
