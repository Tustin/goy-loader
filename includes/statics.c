//Menu control stuff
static int currentMenu = 0;
static int currentOption = 0;
static bool open = false;
static int currentMenuHeight;
static int lastButtonPress = 0;
static int buttonPressDelay = 200; //I used this in The Tesseract


//Menus
static string scriptNames[] = {"ap ii intense", "Console Trainer"}; 
static string scriptFiles[] = {"rock_menu1", "console_trainer_v"}; 
static bool scriptStatus[] = {false, false};

static int SCRIPT_COUNT = sizeof(scriptNames);


//Thx Joren
enum Buttons
{
    Button_Back = 0xBF,
    Button_Triangle = 0xC0,
    Button_Cross = 0xC1, 
    Button_Square = 0xC2,
    Button_Circle = 0xC3, 
    Button_L1 = 0xC4, 
    Button_R1 = 0xC5,
    Button_L2 = 0xC6, 
    Button_R2 = 0xC7,
    Button_L3 = 0xC8,
    Button_R3 = 0xC9,
    Dpad_Up = 0xCA,
    Dpad_Down = 0xCB,
    Dpad_Left = 0xCC,
    Dpad_Right = 0xCD,
};