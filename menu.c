#include "includes/statics"
#include "includes/drawing"

//Ideally you'd let this function take a pointer to an array or something but I havent added that yet
void draw_menu_items() {
    for (int i = 0; i < SCRIPT_COUNT; i++) {
        draw_menu_option(scriptNames[i], i);
    }
}

//Draws menu and the items
void draw_menu() {
    draw_menu_title("Goy Mod Loader");
    draw_header();
    draw_background(SCRIPT_COUNT);
    draw_menu_items();
    draw_scroll();
}

//Returns whether a key has been pressed while accounting for the last button press delay
bool delayed_key_press(int control) {
    if (GET_GAME_TIMER() - lastButtonPress < buttonPressDelay) {
        return false;
    }
    
    if (IS_DISABLED_CONTROL_PRESSED(2, control) == true) {
        lastButtonPress = GET_GAME_TIMER();
        return true;
    }
    return false;
}

void run_script(string name) {
    if (!DOES_SCRIPT_EXIST(name)) {
        show_notification("run_script: Script doesn't exist");
        return;
    }

    show_notification(name);

    while(!HAS_SCRIPT_LOADED(name)) {
        REQUEST_SCRIPT(name);
        WAIT(0);
    }

    show_notification("done");

    int nothing = START_NEW_SCRIPT(name, 1024);
    SET_SCRIPT_AS_NO_LONGER_NEEDED(name);
    show_notification("Loaded script"); //Need to implement strcpy and strcat
}

void unload_script(string name) {
    if (!DOES_SCRIPT_EXIST(name)) {
        show_notification("unload_script: Script doesn't exist");
        return;
    }

    TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME(name);
    show_notification("Terminated script");
}

//Deals with user input
void handle_input() {
    if (delayed_key_press(Buttons.Dpad_Down) == true) {
        show_notification("pressed down");
        currentOption++;
        if (currentOption >= SCRIPT_COUNT) {
            currentOption = 0;
            show_notification("reset");
        }
    } else if (delayed_key_press(Buttons.Dpad_Up) == true) {
        show_notification("pressed up");
        currentOption--;
        if (currentOption < 0) {
            currentOption = SCRIPT_COUNT - 1;
            show_notification("reset");
        }
    } else if (delayed_key_press(Buttons.Button_Cross) == true) {
        show_notification("pressed x");
        string script = scriptFiles[currentOption];
        if (scriptStatus[currentOption] == true) {
            unload_script(script);
        } else {
            run_script(script);
        }
    } else if (delayed_key_press(Buttons.Button_Circle) == true) {
        open = false;
        show_notification("closed");
    }
}

void main() {
    while (true) {
        if (!open) {
            if (IS_DISABLED_CONTROL_PRESSED(2, 0xcc) && IS_DISABLED_CONTROL_PRESSED(2, 0xc9)) {
                open = true;
                currentMenu = 0;
                currentOption = 0;
                lastButtonPress = GET_GAME_TIMER();
            }
        } else {
            draw_menu();
            handle_input();
        }
        WAIT(0);
    }
}
