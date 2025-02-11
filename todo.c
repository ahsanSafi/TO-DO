#include<stdio.h>
#include "todo.h"

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;
    num_tasks = load_tasks(tasks);

    clear_tasks_file();

    int choice;
    do {
        display_menu();
        int result = scanf(" %d", &choice);
        if (result != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                add_task(tasks, &num_tasks);
                break;
            case 2:
                list_tasks(tasks, num_tasks);
                break;
            case 3:
                complete_task(tasks, num_tasks);
                break;
            case 4:
                delete_task(tasks, &num_tasks);
                break;
            case 5:
                save_tasks(tasks, num_tasks);
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
