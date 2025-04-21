#include <gtk/gtk.h>

static void on_button_clicked(GtkButton *button, gpointer user_data) {
    g_print("Voce clicou no botao!\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "App GTK 4");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *button = gtk_button_new_with_label("Clique aqui");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_window_set_child(GTK_WINDOW(window), button);

    gtk_widget_set_visible(window, TRUE);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.exemplo.GTKApp", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
