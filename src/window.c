#include "window.h"

GtkWidget *create_main_window()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GFortiClient");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_default_size(GTK_WINDOW(window), 150, 150);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_container_set_border_width(GTK_CONTAINER(window),20);

    GtkWidget *grdMenu = gtk_grid_new();
    gtk_grid_set_row_homogeneous(GTK_GRID(grdMenu), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grdMenu), FALSE);
    gtk_grid_set_column_spacing(GTK_GRID(grdMenu), 10);

    lblUser = gtk_label_new("User:");
    entUser = gtk_entry_new();

    lblPassword = gtk_label_new("Password:");
    entPassword = gtk_entry_new();

    lblServer = gtk_label_new("Server:");
    entServer = gtk_entry_new();

    lblPort = gtk_label_new("Port:");
    entPort = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grdMenu), lblUser, 0, 0, 2, 1);  
    gtk_grid_attach(GTK_GRID(grdMenu), entUser, 2, 0, 2, 1);  

    gtk_grid_attach(GTK_GRID(grdMenu), lblPassword, 0, 1, 2, 1);  
    gtk_grid_attach(GTK_GRID(grdMenu), entPassword, 2, 1, 2, 1);  

    gtk_grid_attach(GTK_GRID(grdMenu), lblServer, 0, 2, 1, 1);  
    gtk_grid_attach(GTK_GRID(grdMenu), entServer, 1, 2, 1, 1);  
    gtk_grid_attach(GTK_GRID(grdMenu), lblPort, 2, 2, 1, 1);  
    gtk_grid_attach(GTK_GRID(grdMenu), entPort, 3, 2, 1, 1);  

    gtk_container_add(GTK_CONTAINER(window), grdMenu);
   
    /* signals connect */
    g_signal_connect(G_OBJECT(window),
                     "delete_event",
                     G_CALLBACK(program_quit),
                     NULL);
    
    return window;
}

gboolean program_quit(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    gtk_main_quit();
    return TRUE;
}

