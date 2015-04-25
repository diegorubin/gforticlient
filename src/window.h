#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <pthread.h>
#include <gtk/gtk.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

GtkWidget *window;
GtkWidget *create_main_window();

/* Window's widgets */
/* labels */
GtkWidget *lblUser;
GtkWidget *lblPassword;
GtkWidget *lblServer;
GtkWidget *lblPort;

/* entries */
GtkWidget *entUser;
GtkWidget *entPassword;
GtkWidget *entServer;
GtkWidget *entPort;

/* buttons */
GtkWidget *btnConnect;

/* Callbacks */
gboolean program_quit(GtkWidget *widget, GdkEvent *event, gpointer data);

#endif /*_WINDOW_H_*/

