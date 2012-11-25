env-monitor
===========

## environment monitor ##
Arduino based hardware to send various pieces fo data over a serial connection at semi-regular intervals.
Anything can be used to record this data as long as it can read the serial line, by default this will be using a python program to do so.

## Current Status ##
*Arduino Firmware
-Read raw input values from sensors
-Send data over serial connection
*Python data recorder
-open serial connection
-store serial data in a buffer
