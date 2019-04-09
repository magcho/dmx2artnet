# coding:utf-8

import serial
import re

from lib.StupidArtnet import StupidArtnet
import time

artn = StupidArtnet('127.0.0.1', 0, 512)
artn.start()
packet = bytearray(512)
for i in range(512):
    packet[i] = 0

artn.set(packet)

ser = serial.Serial('/dev/tty.usbserial-AH03GYSC', 9800)
print('connection')
while True:
    res = ser.readline().decode()
    dmxOneValue = str(res[:-2]).split(':')
    artn.set_single_value(int(dmxOneValue[0]), int(dmxOneValue[1]))
    print(dmxOneValue)