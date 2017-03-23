#include <gtk-3.0/gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include "core.h"

void playFunct();
void instFunct();
void credFunct();

GtkBuilder *builder;
GtkWidget  *beginWin;
GtkWidget  *instWin;
GtkWidget  *credWin;

static int helpState = 0;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget  *giffer;
    GtkWidget  *playBtn;
    GtkWidget  *credBtn;
    GtkWidget  *exitBtn;
    GtkWidget  *instBtn;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "begin.glade", NULL);

    beginWin = GTK_WIDGET(gtk_builder_get_object(builder, "beginWin"));
    playBtn = GTK_WIDGET(gtk_builder_get_object(builder, "playBtn"));
    credBtn = GTK_WIDGET(gtk_builder_get_object(builder, "credBtn"));
    instBtn = GTK_WIDGET(gtk_builder_get_object(builder, "instBtn"));
    exitBtn = GTK_WIDGET(gtk_builder_get_object(builder, "exitGame"));
    giffer   = GTK_WIDGET(gtk_builder_get_object(builder, "giffer"));

    g_signal_connect(G_OBJECT(playBtn), "clicked", G_CALLBACK(playFunct), NULL);
    g_signal_connect(G_OBJECT(credBtn), "clicked", G_CALLBACK(credFunct), NULL);
    g_signal_connect(G_OBJECT(instBtn), "clicked", G_CALLBACK(instFunct), NULL);

    g_signal_connect(G_OBJECT(beginWin), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(exitBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL);
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

    gtk_widget_show(mainWin);

}
void credFunct(){

    GtkWidget  *credWin;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "credWin.glade",NULL);

    credWin = GTK_WIDGET(gtk_builder_get_object(builder, "credWin"));

    gtk_widget_show(credWin);

}

void instFunct(){

    GtkWidget *label1;
    GtkWidget *img1;
    GtkWidget *imgContent;
    GtkWidget *nextBtn;
    char inst1[250] = {
            "Atoms have a certain reactivity. When you click on an empty cell, \nyou place your atom on the cell. Then, when you click on your \natom, you increase the reactivity of that atom."
    };

    char inst2[250] = {
            "When you click on the most reactive atom, you split it, and it \nwill occupy the neighbouring four cells. The cells will be occupied\n by the atoms of the same type. Make all the cells the same \n color to win the game!"
    };

        builder = gtk_builder_new();
        gtk_builder_add_from_file(builder, "instWin.glade",NULL);

        instWin = GTK_WIDGET(gtk_builder_get_object(builder, "instWin"));
        label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
        img1 = GTK_WIDGET(gtk_builder_get_object(builder, "image"));
        nextBtn = GTK_WIDGET(gtk_builder_get_object(builder, "nextbtn"));

        gtk_widget_show(instWin);

    if(helpState == 0){

        gtk_image_set_from_file(GTK_IMAGE(img1), "images/inst_1.svg");
        gtk_label_set_text(GTK_LABEL(label1), inst1);
        gtk_label_set_text(GTK_LABEL(nextBtn), "Page 2 >");
        helpState = 1;

    }
    else if(helpState == 1){

        gtk_image_set_from_file(GTK_IMAGE(img1), "images/inst_2.svg");
        gtk_label_set_text(GTK_LABEL(label1), inst2);
        helpState = 0;
    }

    g_signal_connect(G_OBJECT(nextBtn), "clicked", G_CALLBACK(instFunct), NULL);
}