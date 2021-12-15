#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "function.h"
#include <string.h>
int se=1;
student su;
int choice[5]={0,0};
int choice1[5]={0,0};



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* cin;
gchar* fname;
gchar* name;
gchar* date_of_birth ;
gchar* block ;
gchar* level ;
gchar* phone ;
gchar* sex ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)){
//getting values of the selected line
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&fname,2,&name,3,&date_of_birth,4,&block,5,&level,6,&phone,7,&sex,-1);
//copying values in su student
strcpy(su.cin,cin);
strcpy(su.fname,fname);
strcpy(su.name,name);
strcpy(su.date_of_birth,date_of_birth);
strcpy(su.block,block);
strcpy(su.level,level);
strcpy(su.phone,phone);
strcpy(su.sex,sex);
}
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* cin;
gchar* fname;
gchar* name;
gchar* date_of_birth ;
gchar* block ;
gchar* level ;
gchar* phone ;
gchar* sex ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)){
//getting values of the selected line
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&cin,1,&fname,2,&name,3,&date_of_birth,4,&block,5,&level,6,&phone,7,&sex,-1);
//copying values in su student
strcpy(su.cin,cin);
strcpy(su.fname,fname);
strcpy(su.name,name);
strcpy(su.date_of_birth,date_of_birth);
strcpy(su.block,block);
strcpy(su.level,level);
strcpy(su.phone,phone);
strcpy(su.sex,sex);
}
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}





void
on_r_male_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
se=1;
}

void
on_r_fmale_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
se=0;
}


void
on_addo_clicked                        (GtkWidget       *button,
                                        gpointer         user_data)
{
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
int day,month,year;

GtkWidget *treeview,*treeviewb,*treeviewc;
treeview=lookup_widget(button,"treeview1");
treeviewb=lookup_widget(button,"treeview2");
treeviewc=lookup_widget(button,"treeview3");


GtkWidget * input1;
GtkWidget * input2;
GtkWidget * input3;
GtkWidget * input4;
GtkWidget * input5;
GtkWidget * input6;
GtkWidget * input7;
GtkWidget * input8;
GtkWidget * input9;
GtkWidget * error;
input1 = lookup_widget (button,"entry_cino");
input2 = lookup_widget (button,"entry_fnameo");
input3 = lookup_widget (button,"entry_nameo");
input4 = lookup_widget (button,"combobox_blocko");
input5 = lookup_widget (button,"combobox_levelo");
input6 = lookup_widget (button,"entry_phoneo");
//date
input7=lookup_widget (button,"spinbutton_dayo");
input8=lookup_widget (button,"spinbutton_montho");
input9=lookup_widget (button,"spinbutton_yearo");

error=lookup_widget(button,"labelerroro1");

strcpy (cin, gtk_entry_get_text (GTK_ENTRY (input1)));
strcpy (fname, gtk_entry_get_text (GTK_ENTRY (input2)));
strcpy (name, gtk_entry_get_text (GTK_ENTRY (input3)));
strcpy(block,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(level,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy (phone, gtk_entry_get_text (GTK_ENTRY (input6)));
//date
day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
month=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
year=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));

if (se==1) strcpy(sex,"Male");
else if (se==0) strcpy(sex,"Female");

student s;

strcpy(s.cin,cin);
strcpy(s.fname,fname);
strcpy(s.name,name);
strcpy(s.block,block);
strcpy(s.level,level);
strcpy(s.phone,phone);
strcpy(s.sex,sex);

sprintf(date_of_birth,"%d/%d/%d",day,month,year);

strcpy(s.date_of_birth,date_of_birth);

if (is_unique("student.txt",s.cin)==1)
{addd("student.txt",s);
gtk_label_set_text(GTK_LABEL(error),"Added successfully");}
else
{//message d'erreur
gtk_label_set_text(GTK_LABEL(error),"CIN already taken");
}
Display_allo(treeview,"student.txt");
Display_allo(treeviewb,"student.txt");

/*nbr_etudiant_niveau("student.txt");
vider(treeviewc);
afficherniveau("niveau.txt",treeviewc);*/

}



void
on_modifyo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *windowmodi;
windowmodi=lookup_widget(button,"windowmodi");
windowmodi=create_windowmodi();
gtk_widget_show(windowmodi);

}

void
on_save_clicked                 	(GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget* input2;
GtkWidget* input3;
GtkWidget* input4;
GtkWidget* input5;
GtkWidget* input6;
GtkWidget* input7;
GtkWidget* input8;
GtkWidget* input9;

input2= lookup_widget(objet_graphique, "entrynommo");
input3= lookup_widget(objet_graphique, "entryprenommo");
input4= lookup_widget(objet_graphique, "comboboxniveaumo");
input5= lookup_widget(objet_graphique, "comboboxblockmo");
input6= lookup_widget(objet_graphique, "entrytelephonemo");
input7= lookup_widget(objet_graphique, "spinbuttonjourmo");
input8= lookup_widget(objet_graphique, "spinbuttonmoismo");
input9= lookup_widget(objet_graphique, "spinbuttonanneemo");
char c [100];
char n [100];
char p  [100];
char sex [100];
char niv [100];
char b [100];
char tel [100];
int j;
int m;
int a;
char sj [100];
char sm [100];
char sa [100];
char dn [100];

strcpy(n,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(input3)));
if (m==0) strcpy(sex,"Female");
else strcpy(sex,"Male");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9));
sprintf(sj,"%d",j);
sprintf(sm,"%d",m);
sprintf(sa,"%d",a);
strcat(sj,"/");
strcat(sm,"/");
strcat(sm,sa);
strcat(sj,sm);
strcpy(dn,sj);
strcpy(niv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
strcpy(b,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input6)));

student ne;
strcpy(ne.cin,su.cin);
strcpy(ne.fname,n);
strcpy(ne.name,p);
strcpy(ne.sex,sex);
strcpy(ne.date_of_birth,dn);
strcpy(ne.level,niv);
strcpy(ne.block,b);
strcpy(ne.phone,tel);
modifyo(ne,su.cin);
}



void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choice[0]=1;

}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choice[1]=1;

}
}



void
on_searcho_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview;
treeview=lookup_widget(button,"treeview1");

if ((choice[0]==1)&&(choice[1]==0))
{
GtkWidget* input10;
char c [100];
input10= lookup_widget(button, "entrycinre");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input10)));
search_student("student.txt",c);


choice[0]=0;
choice[1]=0;}


else 
{
if ((choice[0]==0)&&(choice[1]==1))
{
GtkWidget* input11;
char b [100];
input11= lookup_widget(button, "entryblockre");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input11)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,b))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);


choice[0]=0;
choice[1]=0;
}

else 
{
if ((choice[0]==1)&&(choice[1]==1))
{
GtkWidget* input0;
GtkWidget* input1;
char CIN [100];
char BLOCK [100];
input0= lookup_widget(button, "entrycinre");
input1= lookup_widget(button, "entryblockre");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(BLOCK,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,BLOCK)==0)&&(strcmp(cin,CIN)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);

choice[0]=0;
choice[1]=0;
}
}
}
Display_allo(treeview,"searched_students.txt");

}


void
on_deleteo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
GtkWidget * error;
error=lookup_widget(button,"labelerroro3");

treeview=lookup_widget(button,"treeview2");
delete_s("student.txt",su.cin);
Display_allo(treeview,"student.txt");
gtk_label_set_text(GTK_LABEL(error),"Deleted successfully");

}


void
on_searcho2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{/*
GtkWidget *treeviewb;
treeviewb=lookup_widget(button,"treeview2");

if ((choice1[0]==1)&&(choice1[1]==0))
{
GtkWidget* input10;
char c [100];
input10= lookup_widget(button, "entrycinree");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input10)));
search_student("student.txt",c);


choice1[0]=0;
choice1[1]=0;}


else 
{
if ((choice1[0]==0)&&(choice1[1]==1))
{
GtkWidget* input11;
char b [100];
input11= lookup_widget(button, "entryblockree");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input11)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students2.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,b))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);

choice1[0]=0;
choice1[1]=0;
}

else 
{
if ((choice1[0]==1)&&(choice1[1]==1))
{
GtkWidget* input0;
GtkWidget* input1;
char CIN [100];
char BLOCK [100];
input0= lookup_widget(button, "entrycinree");
input1= lookup_widget(button, "entryblockree");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(BLOCK,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students2.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,BLOCK)==0)&&(strcmp(cin,CIN)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);

choice1[0]=0;
choice1[1]=0;
}
}
}
Display_allo(treeviewb,"searched_students2.txt");
*/
}




void
on_refresho1_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
treeview=lookup_widget(button,"treeview1");
Display_allo(treeview,"student.txt");
}


void
on_refresho2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{/*
GtkWidget *treeview;
treeview=lookup_widget(button,"treeview2");
Display_allo(treeview,"student.txt");*/
}

void
on_refresho3_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview;
	nbr_etudiant_niveau("student.txt");
	treeview=lookup_widget(button,"treeview3");
	//vider(treeview);
	afficherniveau("niveau.txt",treeview);
}


student s;

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{

GtkWidget* widget1;
GtkWidget* widget2;
GtkWidget* widget3;
GtkWidget* widget4;
GtkWidget* widget5;
GtkWidget* widget6;
GtkWidget* widget7;
GtkWidget* widget8;
GtkWidget* widget9;
GtkWidget* widgeth;
GtkWidget* widgetf;




widget1=lookup_widget(widget, "entrynommo");
gtk_entry_set_text(GTK_ENTRY(widget1),su.fname);


widget2= lookup_widget(widget, "comboboxniveaumo");
widget3= lookup_widget(widget, "comboboxblockmo");
int n=0,b=0;
n=atoi(su.level);
b=atoi(su.block);


gtk_combo_box_set_active(GTK_COMBO_BOX(widget2),n-1);
gtk_combo_box_set_active(GTK_COMBO_BOX(widget3),b-1);


widget4=lookup_widget(widget, "entrytelephonemo");
gtk_entry_set_text(GTK_ENTRY(widget4),su.phone);

widget5=lookup_widget(widget, "entryprenommo");
gtk_entry_set_text(GTK_ENTRY(widget5),su.name);

widgeth=lookup_widget(widget, "rbhommemo");
widgetf=lookup_widget(widget, "rbfemmemo");

if(strcmp(su.sex,"male")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgeth),TRUE);
if(strcmp(su.sex,"female")==0) gtk_toggle_button_set_active(GTK_RADIO_BUTTON(widgetf),TRUE);


int p_occ=-1,d_occ=0;
pos_car(su.date_of_birth,'/',&p_occ,&d_occ);
int i;
char j [3];
for(i=0;i<p_occ;i++) j[i]=su.date_of_birth[i];
j[p_occ]='\0';
int ij=0;
ij=atoi(j);


widget7=lookup_widget(widget, "spinbuttonjourmo");
gtk_spin_button_set_value(widget7,ij);
char m [3];
for(i=p_occ+1;i<d_occ;i++) m[i-p_occ-1]=su.date_of_birth[i];
m[d_occ-p_occ-1]='\0';
int im=0;
im=atoi(m);


widget8=lookup_widget(widget, "spinbuttonmoismo");
gtk_spin_button_set_value(widget8,im);
char a [5];
for(i=d_occ+1;i<strlen(su.date_of_birth);i++) a[i-d_occ-1]=su.date_of_birth[i];
a[strlen(su.date_of_birth)-d_occ-1]='\0';
int ia=0;
ia=atoi(a);


widget9=lookup_widget(widget, "spinbuttonanneemo");
gtk_spin_button_set_value(widget9,ia);
}

int m=1;
void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=1;
}


void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) m=0;
}


void
on_entry_cino_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget* input0;
GtkWidget* input1;
GtkWidget* widget1;
input0= lookup_widget(widget, "combobox_levelo");
input1= lookup_widget(widget, "combobox_blocko");
gtk_combo_box_set_active(GTK_COMBO_BOX(input0),0);
gtk_combo_box_set_active(GTK_COMBO_BOX(input1),0);
}





void
on_checkbutton4o_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choice1[1]=1;

}
}



void
on_checkbutton3o_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
 choice1[0]=1;

}
}




void
on_searcho4_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewb;
treeviewb=lookup_widget(button,"treeview2");

if ((choice1[0]==1)&&(choice1[1]==0))
{
GtkWidget* input10;
char c [100];
input10= lookup_widget(button, "entrycinree");
strcpy(c,gtk_entry_get_text(GTK_ENTRY(input10)));
search_student2("student.txt",c);


choice1[0]=0;
choice1[1]=0;}


else 
{
if ((choice1[0]==0)&&(choice1[1]==1))
{
GtkWidget* input11;
char b [100];
input11= lookup_widget(button, "entryblockree");
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input11)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students2.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,b))==0) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);

choice1[0]=0;
choice1[1]=0;
}

else 
{
if ((choice1[0]==1)&&(choice1[1]==1))
{
GtkWidget* input0;
GtkWidget* input1;
char CIN [100];
char BLOCK [100];
input0= lookup_widget(button, "entrycinree");
input1= lookup_widget(button, "entryblockree");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input0)));
strcpy(BLOCK,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f, *fw;
char cin[100],fname[100],name[100],block[100],level[100],phone[100],sex[100],date_of_birth[100];
f=fopen("student.txt","r");
fw=fopen("searched_students2.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth)!=EOF)
{
if((strcmp(block,BLOCK)==0)&&(strcmp(cin,CIN)==0)) fprintf(fw,"%s %s %s %s %s %s %s %s\n",cin,fname,name,block,level,phone,sex,date_of_birth);
}
fclose(f);
fclose(fw);

choice1[0]=0;
choice1[1]=0;
}
}
}
Display_allo(treeviewb,"searched_students2.txt");

}


void
on_refresho4_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
treeview=lookup_widget(button,"treeview2");
Display_allo(treeview,"student.txt");
}

