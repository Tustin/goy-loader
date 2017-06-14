void draw_text(string text, int font, float x, float y, float size) {
    SET_TEXT_FONT(font);
    SET_TEXT_SCALE(size, size);
    SET_TEXT_COLOUR(255, 255, 255, 255);
    SET_TEXT_OUTLINE();
    BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
    END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void show_notification(string message) {
    BEGIN_TEXT_COMMAND_PRINT("STRING");
    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message);
    END_TEXT_COMMAND_PRINT(2000, 1);
}

void draw_menu_title(string title) {
    draw_text(title, 1, 0.779844, 0.191832, 0.7);
}

void draw_menu_option(string option, int index) {
    float temp = index * 0.026094;
    draw_text(option, 2, 0.729657, 0.25647797 + temp, 0.437500);
}

void draw_background(int items) {
    float tmpHeight = (float)items * 0.026094 + 0.030943;
    DRAW_RECT(0.840576, tmpHeight * 0.5, 0.249766, tmpHeight, 0, 0, 0, 255); //background
}