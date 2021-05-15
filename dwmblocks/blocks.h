// #define PATH(name)			"/home/yigit/.local/bin/status-bar/"name
// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    // {"", "/home/nikan/.config/dwmblocks/scripts/network.sh",	2,
    // 0},

    {"", "/home/nikan/.config/dwmblocks/scripts/spotify.sh", 1, 6},
    // {"", "/home/nikan/.config/dwmblocks/scripts/memory.sh",	10,
    // 0},
    {"", "/home/nikan/.config/dwmblocks/scripts/crypto.py", 600, 5},
    //{"", "/home/nikan/.config/dwmblocks/scripts/network.sh",5,7},
    {"", "/home/nikan/.config/dwmblocks/scripts/volume.sh", 0, 4},
    {"", "/home/nikan/.config/dwmblocks/scripts/weather.py", 3600, 3},
    // {"", "/home/nikan/.config/dwmblocks/scripts/packages.sh",	7200,
    // 0},
    {"", "/home/nikan/.config/dwmblocks/scripts/wifi.sh", 5, 2},
    {"", "/home/nikan/.config/dwmblocks/scripts/time.sh", 1, 1},

};

// sets delimeter between status commands. NULL character ('\0') means no
// delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
