#!/bin/bash

echo "building read_button.cpp"
config-pin p8.16 gpio_pu
g++ read_button.cpp GPIO.cpp -o read_button.cgi -lcgicc -pthread
echo "building finished"
