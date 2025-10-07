 //Design a program for creating, editing, and deleting the contents of the file.


 #include <stdio.h>
int main() {
    FILE *fp;
    char filename[50], content[200];
    int choice;
    while (1) {
        printf("\n===== File Operations =====\n");
        printf("1. Create and Write File\n");
        printf("2. Edit (Append) File\n");
        printf("3. Display File Contents\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer
        if (choice == 1) {  // Create & Write
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Error creating file!\n");
                continue;
            }
            printf("Enter content to write: ");
            getchar(); // clear newline
            fgets(content, sizeof(content), stdin);
            fputs(content, fp);
            fclose(fp);
            printf("File created and written successfully.\n");
        } else if (choice == 2) {  // Append
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "a");
            if (fp == NULL) {
                printf("File does not exist!\n");
                continue;
            }
            printf("Enter content to append: ");
            getchar(); // clear newline
            fgets(content, sizeof(content), stdin);
            fputs(content, fp);
            fclose(fp);
            printf("Content appended successfully.\n");
        } else if (choice == 3) {  // Display
            printf("Enter filename: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("File not found!\n");
                continue;
            }
            printf("\n--- File Contents ---\n");
            while (fgets(content, sizeof(content), fp) != NULL) {
                printf("%s", content);
            }
            fclose(fp);
            printf("\n--- End of File ---\n");
        } else if (choice == 4) {  // Delete
            printf("Enter filename to delete: ");
            scanf("%s", filename);
            if (remove(filename) == 0)
                printf("File deleted successfully.\n");
            else
                printf("Unable to delete file.\n");
        } else if (choice == 5) {  // Exit
            printf("Exiting program.\n");
            return 0;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
