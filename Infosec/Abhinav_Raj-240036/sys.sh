#!/bin/bash

#To check the current sound levels 
amixer get Master

#To set the volume to 50%
amixer set Master 50%

#to shutdown the sys in 1 minute
shutdown -h 1

#Instant shutdown
shutdown -h 0
