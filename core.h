#ifndef CHAIN_REACTION_CORE_H
#define CHAIN_REACTION_CORE_H

extern int user[5][5];
extern int reac[5][5];
extern int userCurrent;
extern GtkWidget *b[5][5];
extern GtkWidget *label;

GtkWidget *img;
char imageName[10];

void checkMove(int x, int y, int u, GtkWidget *button){
    if(user[x][y] == userCurrent || user[x][y] == 0){
        reac[x][y] = returnState(x, y);
        user[x][y] = userCurrent;
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y]), img);
        checkExplode();
        labelUpdate();
        userCurrent++;
    }
    else{
        gtk_label_set_text(label, "Wrong Move! Move in your own place!");
    }
    if(userCurrent > 2) userCurrent = 1;
}

void checkExplode(){
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(reac[i][j] > 3){
                propagate(i, j);
                i = 0;
                break;
            }
        }
    }
}
int propagate(int x, int y){
    GtkWidget *img;
    user[x][y] = 0;
    reac[x][y] = 0;
    char imageName[10];
    sprintf(imageName, "images/noEntry.svg");
    img = gtk_image_new_from_file(imageName);
    gtk_button_set_image(GTK_BUTTON(b[x][y]), img);

    if(x==0 && y==0){
        user[x+1][y] = userCurrent;
        reac[x+1][y] = returnState(x+1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);

        user[x][y+1] = userCurrent;
        reac[x][y+1] = returnState(x, y+1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);
        checkExplode();
        update();
        return 0;
    }

    if(x==4 && y==4){
        user[x-1][y] = userCurrent;
        reac[x-1][y] = returnState(x-1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

        user[x][y-1] = userCurrent;
        reac[x][y-1] = returnState(x, y-1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);
        checkExplode();
        update();
        return 0;
    }

    if(x==4 && y==0){
        user[x-1][y] = userCurrent;
        reac[x-1][y] = returnState(x-1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

        user[x][y+1] = userCurrent;
        reac[x][y+1] = returnState(x, y+1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);
        checkExplode();
        update();
        return 0;
    }

    if(x==0 && y==4){
        user[x+1][y] = userCurrent;
        reac[x+1][y] = returnState(x+1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);

        user[x][y-1] = userCurrent;
        reac[x][y-1] = returnState(x, y-1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);
        checkExplode();
        update();
        return 0;
    }

    if(y==0){
        user[x-1][y] = userCurrent;
        reac[x-1][y] = returnState(x-1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

        user[x][y+1] = userCurrent;
        reac[x][y+1] = returnState(x, y+1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);

        user[x+1][y] = userCurrent;
        reac[x+1][y] = returnState(x+1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);
        checkExplode();
        update();
        return 0;
    }

    if(y==4){
        user[x-1][y] = userCurrent;
        reac[x-1][y] = returnState(x-1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

        user[x][y-1] = userCurrent;
        reac[x][y-1] = returnState(x, y-1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);

        user[x+1][y] = userCurrent;
        reac[x+1][y] = returnState(x+1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);
        checkExplode();
        update();
        return 0;
    }


    if(x==0){
        user[x+1][y] = userCurrent;
        reac[x+1][y] = returnState(x+1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);

        user[x][y-1] = userCurrent;
        reac[x][y-1] = returnState(x, y-1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);

        user[x][y+1] = userCurrent;
        reac[x][y+1] = returnState(x, y+1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);
        checkExplode();
        update();
        return 0;
    }

    if(x==4){
        user[x-1][y] = userCurrent;
        reac[x-1][y] = returnState(x-1, y);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

        user[x][y-1] = userCurrent;
        reac[x][y-1] = returnState(x, y-1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);

        user[x][y+1] = userCurrent;
        reac[x][y+1] = returnState(x, y+1);
        sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
        img = gtk_image_new_from_file(imageName);
        gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);
        checkExplode();
        update();
        return 0;
    }

    user[x-1][y] = userCurrent;
    reac[x-1][y] = returnState(x-1, y);
    sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x-1][y]);
    img = gtk_image_new_from_file(imageName);
    gtk_button_set_image(GTK_BUTTON(b[x-1][y]), img);

    user[x][y-1] = userCurrent;
    reac[x][y-1] = returnState(x, y-1);
    sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y-1]);
    img = gtk_image_new_from_file(imageName);
    gtk_button_set_image(GTK_BUTTON(b[x][y-1]), img);

    user[x][y+1] = userCurrent;
    reac[x][y+1] = returnState(x, y+1);
    sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x][y+1]);
    img = gtk_image_new_from_file(imageName);
    gtk_button_set_image(GTK_BUTTON(b[x][y+1]), img);

    user[x+1][y] = userCurrent;
    reac[x+1][y] = returnState(x+1, y);
    sprintf(imageName, "images/user%d_%d.svg", userCurrent, reac[x+1][y]);
    img = gtk_image_new_from_file(imageName);
    gtk_button_set_image(GTK_BUTTON(b[x+1][y]), img);
    checkExplode();
    update();
    return 0;
}

void update(){
    int i, j;
    GtkWidget *img;
    char imageName[10];
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%d \t", reac[i][j]);
            if(user[i][j] !=0 && reac[i][j] > 0){
                sprintf(imageName, "images/user%d_%d.svg", user[i][j], reac[i][j]);
            }
            else {
                sprintf(imageName, "images/noEntry.svg");
                img = gtk_image_new_from_file(imageName);
                gtk_button_set_image(GTK_BUTTON(b[i][j]), img);
            }
        }
        printf("\n");
    }
    printf("\n------------------------------------------\n");
}

int returnState(int x, int y){
    int state = 0;
    if(reac[x][y] == 0){
        if(x == 0 || x ==4){
            state++;
        }
        if(y==0 || y==4){
            state++;
        }
        return (state + 1);
    }
    else{
        return reac[x][y] + 1;
    }
}

int checkGame(){
    int i, j;
    int c1=0, c2=0;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(user[i][j] == 1) c1++;
            if(user[i][j] == 2) c2++;
        }
    }
    if(c1==0 && c2 >1){
        return 2;
    }
    else if(c2 == 0 && c1 >1){
        return 1;
    }
    return 0;
}
void removeLabels(){
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            gtk_widget_set_sensitive(GTK_WIDGET(b[i][j]), 0);
        }
    }
}
void labelUpdate(){
    if(checkGame() !=0){
        char winner[10];
        removeLabels();
        sprintf(winner, "User %d won the game!", checkGame());
        gtk_label_set_text(label, winner);
    }
    else {
        char turnName[20];
        sprintf(turnName, "Turn: player %d", userCurrent);
        printf("\a");
        gtk_label_set_text(label, turnName);
    }
}
#endif
