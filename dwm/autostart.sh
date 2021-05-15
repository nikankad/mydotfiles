#!/bin/bash

function run {
 if ! pgrep $1 ;
  then
    $@&
  fi
}


picom -b  --config ~/.config/arco-dwm/picom.conf &
#run applications from startup

run "discord"
run "firefox"

# run "st spt"
run dwmblocks &

compton &
# spotifyd --no-daemon
spotify
nitrogen --restore
