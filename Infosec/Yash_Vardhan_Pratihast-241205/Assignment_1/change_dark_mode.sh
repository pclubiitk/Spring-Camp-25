#!/bin/bash


CURRENT_THEME=$(gsettings get org.gnome.desktop.interface gtk-theme)


if [[ "$CURRENT_THEME" == *"dark"* ]]; then
    echo "Switching to light mode..."
    gsettings set org.gnome.desktop.interface gtk-theme "Adwaita"
    gsettings set org.gnome.desktop.interface color-scheme "default"
else
    echo "Switching to dark mode..."
    gsettings set org.gnome.desktop.interface gtk-theme "Adwaita-dark"
    gsettings set org.gnome.desktop.interface color-scheme "prefer-dark"
fi
