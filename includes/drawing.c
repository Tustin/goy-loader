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
    float temp = (float)index * 0.026094;
    draw_text(option, 2, 0.729657, 0.25647797 + temp, 0.437500);
}

void draw_background(int items) {
    float tmpHeight = (float)items * 0.026094 + 0.030943;
    DRAW_RECT(0.840576, 0.248187 + tmpHeight * 0.5, 0.249766, tmpHeight, 0, 0, 0, 160); //background
}

void draw_scroll() {
    DRAW_RECT(0.840088, (float)currentOption * 0.026094 + 0.274141, 0.249023, 0.025708, 41, 128, 185, 80); //Scrollbar
}

void draw_header() {
    while (!HAS_STREAMED_TEXTURE_DICT_LOADED("CommonMenu")) {
        REQUEST_STREAMED_TEXTURE_DICT("CommonMenu", false);
        WAIT(0);
    }
    DRAW_SPRITE("CommonMenu", "gradient_nav", 0.840576, 0.218187, 0.249766, 0.062500, 0, 41, 128, 185, 255);
    DRAW_SPRITE("CommonMenu", "header_gradient_script", 0.840576, 0.218187, 0.249766, 0.062500, 0, 0, 0, 0, 255);
}