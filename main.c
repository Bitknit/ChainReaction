#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include "header.h"
#include "core.h"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *beginWin;

    GtkBuilder *builder;
    GtkWidget  *mainWin;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "begin.glade", NULL);
//
//
//    builder = gtk_builder_new();
//    gtk_builder_add_from_file(builder, "mainScreen.glade",NULL);
//
//    init(builder);
//    mainWin = GTK_WIDGET(gtk_builder_get_object(builder, "mainWin"));
//
//    g_signal_connect(G_OBJECT(mainWin), "destroy", G_CALLBACK(gtk_main_quit), NULL);
//
//    gtk_widget_show(mainWin);
    beginWin = GTK_WIDGET(gtk_builder_get_object(builder, "beginWin"));
    gtk_widget_show(beginWin);
    gtk_main();

    return 0;
}