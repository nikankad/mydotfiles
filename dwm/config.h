/* See LICENSE file for copyright and license details. */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Ubuntu Mono: size=13", "fontawesome: size=11"};
static const char dmenufont[]       = "Ubuntu Mono:size=13";
// colors
static const char col_black[]       = "#1E2127";
static const char col_white[]       = "#abb2bf";
static const char col_blue[]       = "#61AFEF";
static const char col_red[]       = "#E45649";
static const char col_purple[]       = "#C678DD";
static const char col_green[]       = "#1DB954";
static const char col_yellow[]       = "#D19A66";



static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_black, col_black },
	[SchemeSel]  = { col_white, col_black,  col_blue  },
	[SchemeStatus]  = { col_white, col_black,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_white, col_black,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_white, col_black,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
/* tagging */
static const char *tags[] = { "", "", "", "", "一", "二", "三", "四", "五"};
//static const char *tags[] = { "www", "dev", "msg", "git", "一", "二", "三", "四", "五"};

/* tagging */

static const char *tagscolors[][4] = {
	/* fg        bg         fg_sel     bg_sel   */
	{ col_white, col_black, col_red, col_black },
	{ col_white, col_black, col_blue, col_black },
	{ col_white, col_black, col_green, col_black },
	{ col_white, col_black, col_yellow, col_black },
	{ col_white, col_black, col_blue, col_black },
	{ col_white, col_black, col_blue, col_black },
	{ col_white, col_black, col_blue, col_black },
	{ col_white, col_black, col_blue, col_black },
	{ col_white, col_black, col_blue, col_black },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  use tags mask to point an application to a specific workspace
	 */
	// n << p, if i want it to be on the 4th window it will be 1<<3 
	/* class                       instance    title      tags mask      isfloating   monitor */
	{ "Gimp",                      NULL,       NULL,       0,            0,           -1 },
	{ "discord",  NULL,       NULL,       1 << 2,            0,           0 },	
	//  { "spotify",  NULL,       NULL,       1 << 2,            1,           -1 },	
	{ "firefox",NULL,       NULL,       1 << 0,            0,           -1 },
	{ "code",NULL,       NULL,       1 << 1,            0,           -1 },
	{ "Skype",NULL,       NULL,       1 << 3,            0,           -1 },

	// { "Subl3",NULL,       NULL,       1 << 1,            0,           -1 },
	// { "Github Desktop",NULL,       NULL,       1 << 3,            0,           -1 },
	{ "GitHub Desktop" ,NULL,       NULL,       1 <<3,            0,           -1 },


};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	// { "[\\]",     dwindle },
	// { "H[]",      deck },
	// { "TTT",      bstack },
	// { "===",      bstackhoriz },
	// { "###",      nrowgrid },
	// { "---",      horizgrid },
	// { ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ "HHH",      grid },
	{ "[@]",      spiral },

	// { ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_blue, "-sb", col_black, "-sf", col_red, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *browser[] = {"firefox", NULL} ;
static const char *emacs[] = {"emacs", NULL};
static const char *code[] = {"code", NULL} ;
#include "selfrestart.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,     			        XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	// { MODKEY,                       XK_Tab,    view,           {0} },
	// { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },
	// { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,						XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	//custom
	{ MODKEY,						XK_w,		spawn,			{.v = browser} },
	{ MODKEY|ShiftMask,				XK_s,		spawn,			SHCMD("flameshot gui")},
    { MODKEY,                       XK_Tab,     view,           {.i = +1} },
    { MODKEY | ShiftMask, 			XK_e, 		spawn,		    {.v=emacs}},
    { MODKEY | ShiftMask, 			XK_c, 		spawn,		    {.v=code}},
    { MODKEY|ControlMask|ShiftMask, 			XK_q, 		spawn,		    SHCMD("poweroff")},


	//volume keybinds
	{ MODKEY,                       XK_F2, spawn, SHCMD("amixer -D default sset Master Playback 5%- |  kill -38 $(pidof dwmblocks)")  },
	{ MODKEY,                       XK_F4,  spawn, SHCMD("amixer -D default sset Master Playback 0% |  kill -38 $(pidof dwmblocks)")} ,
	{ MODKEY,                       XK_F3, spawn, SHCMD("amixer -D default sset Master Playback 5%+ |  kill -38 $(pidof dwmblocks)")},
	


	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },

	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
