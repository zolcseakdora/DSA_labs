#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"
#include "../headers/book.h"

int main(void)
{
    Node* root = NULL;
    while (1)
    {
        printf("\nOpciok:"
            "\n\t0. Kilepes"
            "\n\t1. Konyvek beolvasasa"
            "\n\t2. Konyv kolcsonzese"
            "\n\t3. Konyv visszaadasa"
            "\n\t4. Konyvek listazasa"
            "\n\t5. Regi konyvek"
            "\nOpcio:"
        );
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            destroyBinaryTree(&root);
            exit(0);
        case 1:
            {
                printf("Konyvek beolvasasa...");
                FILE* in = fopen("../konyv.txt", "r");
                if (!in) { return -1; }
                while (!feof(in))
                {
                    Book b;
                    readBook(&b, in);
                    root = insert(root, b);
                    //printBook(b);
                }
                fclose(in);
                break;
            }
        case 2:
            {
                Node* result = search(root, "Edes Anna");
                if (result != NULL)
                {
                    if (result->info.status == 0)
                    {
                        result->info.status = 1;
                        printf("Kikolcsonozve\n");
                    }
                    else
                    {
                        printf("nem lehet kikolcsonozve\n");
                    }
                }
                break;
            }
        case 3:
            {
                Node* result = search(root, "Edes Anna");
                if (result != NULL)
                {
                    if (result->info.status == 1)
                    {
                        result->info.status = 0;
                        printf("visszaadva\n");
                    }
                    else
                    {
                        printf("nem lehet visszaadni\n");
                    }
                }
                break;
            }
        case 4:
            {
                inorderTraversal(root);
                break;
            }
        default:
            printf("Nem letezo opcio\n");
        }
    }
    return 0;
}
