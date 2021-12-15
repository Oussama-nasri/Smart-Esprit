#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>

typedef struct{
char cin[100];
char fname[100];
char name[100];
char block[100];
char level[100];
char phone[100];
char sex[100];
char date_of_birth[100];
}student;


void addd(char file_name [],student s);
void show_student(char filename[],GtkWidget *liste);
void delete_s(char file_name [],char id[]);
void search_student(char file_name [],char id[]);

void modifyo(student su,char id []);
void nbr_student_level(char filename []);
void clearr(GtkWidget *liste);
void Display_allo(GtkWidget *list,char filename[]);
int is_unique(char filename[], char id []);
//void show_level(char filename [],GtkWidget *liste);
void afficherniveau(char fname [],GtkWidget *liste);
void nbr_etudiant_niveau(char fname []);

