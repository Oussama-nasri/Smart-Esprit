#include "function.h"
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>


void addd(char file_name [],student s)
{
FILE *f;
f=fopen(file_name,"a");
fprintf(f,"%s %s %s %s %s %s %s %s\n",s.cin,s.fname,s.name,s.block,s.level,s.phone,s.sex,s.date_of_birth);
fclose(f);
}

enum
{
CIN,
FIRSTNAME,
NAME,
SEX,
BLOCK,
LEVEL,
PHONE,
DATE_OF_BIRTH,
COLUMNS
};


void show_student(char filename[],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char cin [100];
char fname [100];
char name [100];
char date_of_birth [100];
char block [100];
char level [100];
char phone [100];
char sex [100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("First Name",renderer,"text",FIRSTNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Block",renderer,"text",BLOCK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Level",renderer,"text",LEVEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Phone",renderer,"text",PHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Date_of_birth",renderer,"text",DATE_OF_BIRTH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(filename,"r");
if (f==NULL)
{
return;
}
else
{f=fopen(filename,"a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
gtk_list_store_append(store,&iter);	 		     gtk_list_store_set(store,&iter,CIN,cin,FIRSTNAME,fname,NAME,name,BLOCK,block,LEVEL,level,PHONE,phone,DATE_OF_BIRTH,date_of_birth,SEX,sex,-1); 
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void delete_s(char file_name [],char id[])
{
char cin [100];
char fname [100];
char name [100];
char date_of_birth [100];
char block [100];
char level [100];
char phone [100];
char sex [100];
FILE *f,*temp;
f=fopen(file_name,"r");
temp=fopen("temp_del.txt","w");

while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{if (strcmp(cin,id)!=0)
fprintf(temp,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);}
fclose(f);
fclose(temp);
remove("student.txt");
rename("temp_del.txt","student.txt");

}


void clearr(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char cin [100];
char fname [100];
char name [100];
char block [100];
char level [100];
char phone [100];
char sex [100];
char date_of_birth [100];
store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("First Name",renderer,"text",FIRSTNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Block",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Level",renderer,"text",LEVEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Phone",renderer,"text",PHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Date of Birth",renderer,"text",DATE_OF_BIRTH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
}

void pos_car(char T[], char c, int *p_occ, int *d_occ)
{

int i;
    for(i=0;i<strlen(T);i++)
    {
        if (T[i]==c)
        {
            if (*p_occ==-1)
            {
                *p_occ=i;

            }
            else
            {
                *d_occ=i;
            }

        }

    }

}


void search_student(char file_name[],char id[])
{
char cin [100];
char fname [100];
char name [100];
char date_of_birth [100];
char block [100];
char level [100];
char phone [100];
char sex [100];
FILE *f,*temp;
f=fopen(file_name,"r");
temp=fopen("searched_students.txt","w");

while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,level,block,phone,sex,date_of_birth)!=EOF)
{
if (strcmp(cin,id)==0)
{
fprintf(temp,"%s %s %s %s %s %s %s %s\n",cin,fname,name,level,block,phone,sex,date_of_birth);

}
}


fclose(f);
fclose(temp);
}

void search_student2(char file_name[],char id[])
{
char cin [100];
char fname [100];
char name [100];
char date_of_birth [100];
char block [100];
char level [100];
char phone [100];
char sex [100];
FILE *f,*temp;
f=fopen(file_name,"r");
temp=fopen("searched_students2.txt","w");

while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,level,block,phone,sex,date_of_birth)!=EOF)
{
if (strcmp(cin,id)==0)
{
fprintf(temp,"%s %s %s %s %s %s %s %s\n",cin,fname,name,level,block,phone,sex,date_of_birth);

}
}


fclose(f);
fclose(temp);
}



void Display_allo(GtkWidget *list,char filename[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
student s;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(list);
if (store==NULL)
{////
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("First Name",renderer,"text",FIRSTNAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Name",renderer,"text",NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Block",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Level",renderer,"text",LEVEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Phone",renderer,"text",PHONE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Sex",renderer,"text",SEX,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("Date of Birth",renderer,"text",DATE_OF_BIRTH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(filename,"r");
if (f!=NULL)
{

	f=fopen(filename,"a+");
   while(fscanf(f,"%s %s %s %s %s %s %s %s",s.cin,s.fname,s.name,s.block,s.level,s.phone,s.sex,s.date_of_birth)!=EOF)///
{

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,CIN,s.cin,FIRSTNAME,s.fname,NAME,s.name,BLOCK,s.block,LEVEL,s.level,PHONE,s.phone,DATE_OF_BIRTH,s.date_of_birth,SEX,s.sex,-1);
		
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}		




void modifyo(student su,char id [])
{
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
FILE *f,*fw;
f=fopen("student.txt","r");
fw=fopen("dumpo.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if(strcmp(cin,id)!=0)
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
else
{
fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,su.fname,su.name,su.block,su.level,su.phone,su.sex,su.date_of_birth);
}
}
fclose(f);
fclose(fw);
remove("student.txt");
rename("dumpo.txt","student.txt");
}


int is_unique(char filename[], char id [])
{
FILE *f;
int x=1;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen(filename,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(cin,id))==0) x=-1;
}
return x;
}


void nbr_student_level(char filename [])
{/*
int c1=0,c2=0,c3=0,c4=0,c5=0,n;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100],s1[100],s2[100],s3[100],s4[100],s5[100];
FILE *f,*fw;
f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
n=atoi(level);
switch (n)
{

case 1 : c1+=1;
            break;

case 2 : c2+=1;
            break;

case 3 : c3+=1;
            break;

case 4 : c4+=1;
            break;

default : c5+=1;
            break;
}

}
fclose(f);
sprintf(s1,"%d",c1);
sprintf(s2,"%d",c2);
sprintf(s3,"%d",c3);
sprintf(s4,"%d",c4);
sprintf(s5,"%d",c5);
fw=fopen("level.txt","w");
fprintf(fw,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
fclose(fw);
*/}

enum
{
	col1,
	col2,
	col3,
	col4,
	col5,
	COL,
};

/*void show_level(char filename [],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char c1 [100];
char c2 [100];
char c3 [100];
char c4 [100];
char c5 [100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("1st Year",renderer,"text",col1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("2nd Year",renderer,"text",col2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("3rd Year",renderer,"text",col3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("4th Year",renderer,"text",col4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("5th Year",renderer,"text",col5,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen(filename,"r");
if (f==NULL)
{
return;
}
else
{f=fopen(filename,"a+");
	while(fscanf(f,"%s %s %s %s %s\n",c1,c2,c3,c4,c5)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,col1,c1,col2,c2,col3,c3,col4,c4,col5,c5,-1);	 		      
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}*/

void nbr_etudiant_niveau(char fname [])
{
int c1=0,c2=0,c3=0,c4=0,c5=0,n;
char cin[100],nom[100],prenom[100],sex[100],date_naissance[100],niveau[100],block[100],telephone[100],s1[100],s2[100],s3[100],s4[100],s5[100];
FILE *f,*fw;
f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,nom,prenom,block,niveau,telephone,sex,date_naissance)!=EOF)
{
n=atoi(niveau);
switch (n)
{

case 1 : c1+=1;
            break;

case 2 : c2+=1;
            break;

case 3 : c3+=1;
            break;

case 4 : c4+=1;
            break;

default : c5+=1;
            break;
}

}
fclose(f);
sprintf(s1,"%d",c1);
sprintf(s2,"%d",c2);
sprintf(s3,"%d",c3);
sprintf(s4,"%d",c4);
sprintf(s5,"%d",c5);
fw=fopen("niveau.txt","w");
fprintf(fw,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
fclose(fw);
}

void afficherniveau(char fname [],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char c1 [100];
char c2 [100];
char c3 [100];
char c4 [100];
char c5 [100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("1st Year",renderer,"text",col1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("2nd Year",renderer,"text",col2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("3rd Year",renderer,"text",col3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("4th Year",renderer,"text",col4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("5th Year",renderer,"text",col5,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("niveau.txt","r");
/*if (f==NULL)
{
return;
}*/

//f=fopen(fname,"r");
while(fscanf(f,"%s %s %s %s %s",c1,c2,c3,c4,c5)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,col1,c1,col2,c2,col3,c3,col4,c4,col5,c5,-1);	 		      
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
//
void vider(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


store=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("1st Year",renderer,"text",col1,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("2nd Year",renderer,"text",col2,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("3rd Year",renderer,"text",col3,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("4th Year",renderer,"text",col4,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();  
column=gtk_tree_view_column_new_with_attributes("5th Year",renderer,"text",col5,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}
store=gtk_list_store_new(COL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
}



