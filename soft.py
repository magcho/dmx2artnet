# coding:utf-8

DEVICE_ID = 'AH03ICY5'



import serial
from lib.StupidArtnet import StupidArtnet

artNetIp = '127.0.0.1'
artNetPort = '6454(default)'
artn = StupidArtnet('127.0.0.1', 0, 512, 60)
print('ArtNet ip: ',artNetIp,'port: ', artNetPort)
artn.start()
packet = bytearray(512)
for i in range(512):
    packet[i] = 0

artn.set(packet)

deviceName = '/dev/tty.usbserial-' + DEVICE_ID
ser = serial.Serial(deviceName, 74880)
print('conected: ', deviceName)
while True:
    res = ser.readline().decode()
    dmxOneValue = str(res[:-2]).split(':')
    artn.set_single_value(int(dmxOneValue[0]), int(dmxOneValue[1]))
