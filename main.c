#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include "core.h"

void playFunct();
void credFunct();

GtkBuilder *builder;
GtkWidget  *beginWin;
GtkWidget  *instWin;
GtkWidget  *credWin;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);


    GtkWidget  *giffer;
    GtkWidget  *playBtn;
    GtkWidget  *credBtn;
    GtkWidget  *instBtn;


    GtkImage   *anim;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "begin.glade", NULL);

    beginWin = GTK_WIDGET(gtk_builder_get_object(builder, "beginWin"));
    playBtn = GTK_WIDGET(gtk_builder_get_object(builder, "playBtn"));
    credBtn = GTK_WIDGET(gtk_builder_get_object(builder, "credBtn"));
    instBtn = GTK_WIDGET(gtk_builder_get_object(builder, "instBtn"));
    giffer   = GTK_WIDGET(gtk_builder_get_object(builder, "giffer"));

    g_signal_connect(G_OBJECT(playBtn), "clicked", G_CALLBACK(playFunct), NULL);
    g_signal_connect(G_OBJECT(credBtn), "clicked", G_CALLBACK(credFunct), NULL);
//    g_signal_connect(G_OBJECT(playBtn), "clicked", G_CALLBACK(playFunct), NULL);
//    g_signal_connect(G_OBJECT(playBtn), "clicked", G_CALLBACK(playFunct), NULL);

    gtk_widget_show(beginWin);
    gtk_main();

    return 0;
}
void playFunct(){

    GtkWidget  *mainWin;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "mainScreen.glade",NULL);

    init(builder);
    mainWin = GTK_WIDGET(gtk_builder_get_object(builder, "mainWin"));

    g_signal_connect(G_OBJECT(mainWin), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(mainWin);

}
void credFunct(){

    GtkWidget  *credWin;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "credWin.glade",NULL);

    init(builder);
    credWin = GTK_WIDGET(gtk_builder_get_object(builder, "credWin"));

    gtk_widget_show(credWin);

}