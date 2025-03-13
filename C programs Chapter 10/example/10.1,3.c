#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void load();
int menu();
void enter();
void author_search();
void title_search();
void save();
void display(int i);

struct catalog {
    char name[80];
    char title[80];
    char pub[80];
    unsigned date;
    unsigned char ed;
} cat[MAX];

int top = 0;

int main() {
    int choice;

    load();

    do {
        choice = menu();
        switch (choice) {
            case 1: enter(); break;
            case 2: author_search(); break;
            case 3: title_search(); break;
            case 4: save(); break;
        }
    } while (choice != 5);

    return 0;
}

void load() {
    FILE *fp = fopen("catalog", "rb");
    if (fp == NULL) {
        printf("Catalog file doesn't exist.\n");
        return;
    }
    if (fread(&top, sizeof(top), 1, fp) != 1) {
        printf("Error reading count.\n");
        exit(1);
    }
    if (fread(cat, sizeof(cat), 1, fp) != 1) {
        printf("Error reading catalog data.\n");
        exit(1);
    }
    fclose(fp);
}

int menu() {
    int i;
    char str[80];

    printf("\nCard catalog : \n");
    printf("\t1. Enter.\n");
    printf("\t2. Search by author.\n");
    printf("\t3. Search by title.\n");
    printf("\t4. Save catalog.\n");
    printf("\t5. Quit.\n");

    do {
        printf("Choose your selection : ");
        fgets(str, sizeof str, stdin);
        i = atoi(str);
    } while (i < 1 || i > 5);

    return i;
}

void enter() {
    int i;
    char temp[80];
    for (i = top; i < MAX; i++) {
        printf("\nEnter author name (Press Enter to quit) : ");
        fgets(cat[i].name, sizeof cat[i].name, stdin);
        if (!strcmp(cat[i].name, "\n")) break;

        printf("Enter title : ");
        fgets(cat[i].title, sizeof cat[i].title, stdin);
        printf("Enter publisher : ");
        fgets(cat[i].pub, sizeof cat[i].pub, stdin);
        printf("Enter copyright date : ");
        fgets(temp, sizeof temp, stdin);
        cat[i].date = (unsigned) atoi(temp);
        printf("Enter edition : ");
        fgets(temp, sizeof temp, stdin);
        cat[i].ed = (unsigned) atoi(temp);        
    }
    top = i;
}

void author_search() {
    char name[80];
    int i, found;
    printf("\nEnter name : ");
    fgets(name, sizeof name, stdin);

    found = 0;
    for (i = 0; i < top; i++) 
        if (!strcmp(name, cat[i].name)){
            display(i);
            found = 1;
        }
    if (!found) printf("Not found\n");
}
void display(int i) {
    printf("\n\tTitle : %s", cat[i].title);
    printf("\tAuthor : %s", cat[i].name);
    printf("\tPublisher : %s", cat[i].pub);
    printf("\tCopyright date : %u\n", cat[i].date);
}
void title_search() {
    char title[80];
    int i, found;
    printf("\nEnter title : ");
    fgets(title, sizeof title, stdin);

    found = 0;
    for (i = 0; i < top; i++) 
        if (!strcmp(title, cat[i].title)){
            display(i);
            found = 1;
        }
    if (!found) printf("Not found\n");
}
void save() {
    FILE *fp = fopen("catalog", "wb");
    if (fp == NULL) {
        printf("Can't open catalog file\n");
        exit(1);
    }
    if (fwrite(&top, sizeof top, 1, fp) != 1) {
        printf("Error writing count\n");
        exit(1);
    }
    if (fwrite(cat,sizeof cat, 1, fp) != 1) {
        printf("Error reading count\n");
        exit(1);
    }
}