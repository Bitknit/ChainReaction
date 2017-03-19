#ifndef CHAIN_REACTION_HEADER_H
#define CHAIN_REACTION_HEADER_H
#include "core.h"

int user[5][5];
int reac[5][5];

int clicked[3];

GtkWidget  *label;

GtkWidget *b[5][5];

GtkWidget *u1r;
GtkImage *u1s;
GtkImage *u1g;

GtkImage *u2r;
GtkImage *u2s;
GtkImage *u2g;

char imageName[10];
char prompt[100];
int userCurrent = 1;

void btn_clicked(GtkButton *button, gpointer *datam){
    int data = datam;
    int x = data / 10;
    int y = data % 10;
    int u = user[x][y];
    checkMove(x, y, u, button);
}

void init(GtkBuilder *builder){
    int i, j;
    char txt[3];
    int btnNo = 0;
    for(i=0; i<5; i++){
        for (j=0; j<5; j++){
            btnNo = i*10+j;
            sprintf(txt, "b%d%d", i, j);
            b[i][j] = GTK_WIDGET(gtk_builder_get_object(builder, txt));
            g_signal_connect(G_OBJECT(b[i][j]), "clicked", G_CALLBACK(btn_clicked), (gpointer) btnNo);
            user[i][j] = 0;
            reac[i][j] = 0;
            if((i==0 || i==4)){
                reac[i][j]++;
            }
            if((j==0 || j==4)){
                reac[i][j]++;
            }
        }
    }
    label = GTK_WIDGET(gtk_builder_get_object(builder, "playerLabel"));
}
#endif
