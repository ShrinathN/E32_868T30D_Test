#!/bin/python
import serial
import threading

x = serial.Serial('/dev/ttyUSB0', baudrate=9600)


def f():
	while(True):
		try:
			print(str(x.readline(), 'utf-8'), end='')
		except:
			continue

threading.Thread(target=f, args=()).start()

while(True):
	x.write(bytes(input(), 'utf-8'))
