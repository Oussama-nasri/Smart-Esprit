/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *window1;
  GtkWidget *windowmodi;
	GtkWidget *treeview,*treeviewb,*treeviewc;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  window1 = create_window1 ();
  gtk_widget_show (window1);
  /*windowmodi = create_windowmodi ();
  gtk_widget_show (windowmodi);*/


	treeview=lookup_widget(window1,"treeview1");
	show_student("student.txt",treeview);
	treeviewb=lookup_widget(window1,"treeview2");
	show_student("student.txt",treeviewb);

	nbr_etudiant_niveau("student.txt");
	treeviewc=lookup_widget(window1,"treeview3");
	afficherniveau("niveau.txt",treeviewc);

  gtk_main ();
  return 0;
}

