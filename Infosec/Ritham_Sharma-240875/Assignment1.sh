#!/bin/bash


change_brightness() {
    if [[ $1 == "up" ]]; then
        brightnessctl set +10%
    elif [[ $1 == "down" ]]; then
        brightnessctl set 10%-
    else
        echo "Usage: $0 brightness up|down"
    fi
}


change_volume() {
    if [[ $1 == "up" ]]; then
        pactl set-sink-volume @DEFAULT_SINK@ +5%
    elif [[ $1 == "down" ]]; then
        pactl set-sink-volume @DEFAULT_SINK@ -5%
    else
        echo "Usage: $0 volume up|down"
    fi
}


if [[ $1 == "brightness" ]]; then
    change_brightness $2
elif [[ $1 == "volume" ]]; then
    change_volume $2
else
    echo "Usage: $0 brightness|volume up|down"
fi

