#include "window.h"

const char *fifo = "/tmp/gfrontfile";

GtkWidget *create_main_window()
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GFortiClient");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window),5);

    GtkWidget *vbxWindow = gtk_vbox_new (FALSE, 0);
    GtkWidget *tblMenu = gtk_table_new(4,2,FALSE);

    gtk_box_pack_start (GTK_BOX (vbxWindow),tblMenu, FALSE, FALSE, 0); 

    lblUser = gtk_label_new("User:");
    entUser = gtk_entry_new();

    lblPassword = gtk_label_new("Password:");
    entPassword = gtk_entry_new();

    lblServer = gtk_label_new("Server:");
    entServer = gtk_entry_new();

    lblPort = gtk_label_new("Port:");
    entPort = gtk_entry_new();

    gtk_table_attach(GTK_TABLE(tblMenu), lblUser, 0, 2, 0, 1, GTK_SHRINK,GTK_SHRINK,0,0);  
    gtk_table_attach(GTK_TABLE(tblMenu), entUser, 2, 4, 0, 1, GTK_EXPAND,GTK_SHRINK,0,0);  

    gtk_table_attach(GTK_TABLE(tblMenu), lblPassword, 0, 2, 1, 2, GTK_SHRINK,GTK_SHRINK,0,0);  
    gtk_table_attach(GTK_TABLE(tblMenu), entPassword, 2, 4, 1, 2, GTK_EXPAND,GTK_SHRINK,0,0);  

    gtk_table_attach(GTK_TABLE(tblMenu), lblServer, 0, 1, 2, 3, GTK_SHRINK,GTK_SHRINK,0,0);  
    gtk_table_attach(GTK_TABLE(tblMenu), entServer, 1, 2, 1, 2, GTK_EXPAND,GTK_SHRINK,0,0);  
    gtk_table_attach(GTK_TABLE(tblMenu), lblPort, 2, 3, 1, 2, GTK_SHRINK,GTK_SHRINK,0,0);  
    gtk_table_attach(GTK_TABLE(tblMenu), entPort, 3, 4, 1, 2, GTK_EXPAND,GTK_SHRINK,0,0);  

    gtk_container_add(GTK_CONTAINER(window), vbxWindow);
   
    if(access(fifo,F_OK) == -1){
        if(mkfifo(fifo,0666) != 0){
            g_print("error creating pipeline\n");
            gtk_main_quit();
        }
    }


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
    unlink(fifo);
    return TRUE;
}

