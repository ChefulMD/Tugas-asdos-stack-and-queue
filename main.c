#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int choice;
char temp;

   struct Tumpukan{
            char data[5][50];
            int top;
        }tumpuk;

    struct Antrian{
        int head;
        int tail;
        int data[MAX];
    }antrian;

        void checkp(){
        printf("Press any key to continue....");
        getch();
        system("cls");
        }

        int isEmpty()
        {
            if(tumpuk.top == -1 && antrian.tail == -1)
            {
                return 1;
            }else{
                return 0;
            }
        }


        int isFull()
        {
            if(tumpuk.top == MAX-1 && antrian.tail == MAX -1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }

        void inisialisasi()
        {
            tumpuk.top = antrian.head = antrian.tail = -1;
        }

        void push()
        {
            char temp[30];
            if(isFull() != 1)
            {
                tumpuk.top++;
                printf("Masukkan data yang ingin diinput: ");
                scanf("%c",temp);//clear buffer...\n enter terus kebaca
                scanf("%[^\n]s",temp);
                strcpy(tumpuk.data[tumpuk.top],temp);
                printf("Data %s berhasil di input\n",tumpuk.data[tumpuk.top]);
            }else{
                printf("Data sudah penuh");
            }
           checkp();
        }

        void pop()
        {
            if(isEmpty() != 1)
            {
                printf("Data %s telah dibuang\n",tumpuk.data[tumpuk.top]);
                tumpuk.top--;

            }else{
                printf("Data masih kosong\n");
            }
            checkp();
        }

   void print_stack()
        {
            if(isEmpty() !=1)
            {
                for(int i=tumpuk.top;i>=0;i--)
                {
                    printf("Data ke - %d = %s\n",i+1,tumpuk.data[i]);
                }
            }else{
                printf("Data masih kosong\n");
            }
         checkp();
        }

     void enqueue(int data)
    {
        if(isEmpty()== 1)
        {
            antrian.head=  antrian.tail = 0;
            antrian.data[antrian.tail] = data;
            printf("Data %d berhasil diinput!\n",antrian.data[antrian.tail]);
        }
        else{


        if(isFull() == 0)
        {
            antrian.tail++;
            antrian.data[antrian.tail] = data;
            printf("data %d berhasil di input\n",antrian.data[antrian.tail]);
        }
        }
        checkp();
    }

     int dequeue()
    {
        if(isEmpty() == 1)
        {
            printf("Data masih kosong!\n");
            checkp();
        }
        else{
            int i;
            int e = antrian.data[antrian.head];
            printf("data %d telah dikeluarkan dari antiran\n",antrian.data[antrian.head]);
            for(i=antrian.head;i<=antrian.tail-1;i++)
            {
                antrian.data[i] = antrian.data[i+1];
            }
            antrian.tail--;
            checkp();
            return e;

        }
    }

    void clear()
    {
        antrian.head = antrian.tail = -1;
        printf("Data telah di hapus!\n");
        checkp();
    }

    void print_queue()
    {
        if(isEmpty() == 0)
        {
            for(int i=antrian.head;i<=antrian.tail;i++)
            {
                printf("data ke - %d = %d \n",i + 1,antrian.data[i]);

            }
            checkp();
        }else{
            printf("Data masih kosongg!\n");
            checkp();
        }
    }

    void stackfunction()
    {
        system("cls");
        do{
            choice = 0;
            printf("1.Push Stack\n");
            printf("2.Pop Stack\n");
            printf("3.Print Stack\n");
            printf("4.Delete Stack\n");
            printf("5.Return to main menu\n");
            printf("Input pilihan: ");
            scanf(" %d",&choice);
                switch(choice)
                {
                case 1:
                    system("cls");
                    push();
                    break;
                case 2:
                    system("cls");
                    pop();
                    break;
                case 3:
                    system("cls");
                    print_stack();
                    break;
                case 4:
                    system("cls");
                    if(isEmpty())
                    {
                        printf("Data masih kosong!,tidak bisa reset\n");
                    }
                    else{
                          inisialisasi();
                    printf("Data telah di hapus!\n");
                    }
                    checkp();
                    break;
                case 5:
                    goto* main();
                    break;
                }
              fflush(stdin);
        }while(choice >0 && choice < 6);
        stackfunction();
    }

    void queuefunction()
    {
        system("cls");
        int dt;
        do{
            choice = 0;
            printf("1.Enqueue Int\n");
            printf("2.Dequeue Int\n");
            printf("3.Print Queue\n");
            printf("4.Delete Queue\n");
            printf("5.Return to Main Menu\n");
            printf("Input pilihan: ");
            scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    system("cls");
                    if(isFull() !=1)
                    {
                        printf("Masukkan data : ");
                        scanf("%d",&dt);
                        enqueue(dt);
                    }else{
                        printf("data sudah penuh!\n");
                    }
                    break;
                case 2:
                    system("cls");
                    dequeue();
                    break;
                case 3:
                    system("cls");
                    print_queue();
                    printf("\n");
                    break;
                case 4:
                    system("cls");
                    clear();
                    break;
                case 5:
                    system("cls");
                    goto* main();
                    break;
                }
              fflush(stdin);
        }while(choice>0 && choice <6);
       queuefunction();
    }
int main(){
system("cls");
do{
printf(" =================================\n    Tugas Quiz Stack dan Queue\n =================================\n");
printf("   1. Stack String\n   2. Queue integer\n   3. Exit Program\n");
printf(" =================================\n");
printf("Input pilihan: ");
fflush(stdin);
scanf("%d",&choice);
switch(choice){
case 1:
    inisialisasi();
    stackfunction(0);
    break;
case 2:
    inisialisasi();
    queuefunction(0);
    break;
case 3:
    return 0;
    break;
default:
    system("cls");
    printf("Pilihan tidak ada...\n");
    checkp();
    main();
    break;
}
}while(choice > 0 && choice < 3);
return 0;
}
