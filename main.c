#include <stdlib.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;

  /* Initialize GTK+ */
  gtk_init (&argc, &argv);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title (GTK_WINDOW (win), "Hello World");
 // gtk_window_set_message(GTK_WINDOW (win), "ПРИВЕТ");


  /* Enter the main loop */
  gtk_widget_show_all (win);
  gtk_main ();
  return 0;
}
