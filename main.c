#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *display;
    GtkWidget *button_grid;


    window = gtk_application_window_new(app);

    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 500);

    // Create a vertical layout
    layout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Create the calculator display
    display = gtk_label_new("0");

    // Align the display to the right
    gtk_widget_set_halign(display, GTK_ALIGN_END);

    // Add some spacing around the display
    gtk_widget_set_margin_top(display, 30);
    gtk_widget_set_margin_end(display, 20);

    // Add the display to the layout
    gtk_box_append(GTK_BOX(layout), display);

    // Add the layout to the window
    gtk_window_set_child(GTK_WINDOW(window), layout);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new(
        "com.example.calculator",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}