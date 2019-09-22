#include <iostream>
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Label firstname;
    Gtk::Label lastname;
    Gtk::Entry entry;
    Gtk::Entry entry2;
    Gtk::Button button;
    Gtk::Label label;

    Window() {
        button.set_label("Combine names");
        firstname.set_text("First name");
        lastname.set_text("Last name");


        vbox.pack_start(firstname); //Add the widget entry to vbox
        vbox.pack_start(entry);  //Add the widget entry to vbox
        vbox.pack_start(lastname); //Add the widget entry to vbox
        vbox.pack_start(entry2); //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets
        button.set_sensitive(false);

        entry.signal_changed().connect([this]() {
            if(!entry.get_text().empty() && !entry2.get_text().empty()) button.set_sensitive();
            else button.set_sensitive(false);
        });

        entry2.signal_changed().connect([this](){
            if(!entry.get_text().empty() && !entry2.get_text().empty()) button.set_sensitive();
            else button.set_sensitive(false);
        });


        button.signal_clicked().connect([this]() {
            label.set_text("Names combined: " + entry.get_text() + " " + entry2.get_text());
        });
    }
};

int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
