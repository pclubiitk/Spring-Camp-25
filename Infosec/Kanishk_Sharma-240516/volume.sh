#!/bin/bash
case $1 in
	up)
		amixer -D pulse sset Master 5%+
		;;
	down)
		amixer -D pulse sset Master 5%-
		;;
	mute)
		amixer -D pulse sset Master toggle
		;;
	*)
		echo "Usage: $0 {Up|Down|Mute}"
		;;
	esac



















































































