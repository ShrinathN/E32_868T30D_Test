#!/bin/python

import tkinter
import threading
import os

def make():
	b_make['background'] = 'red'
	os.system('make clean')
	os.system('make')
	try:
		os.listdir('user_main-0x10000.bin')
	except NotADirectoryError: #if compilation was successful
		b_make['background'] = 'green'
		b_make['text'] = 'Make - DONE!'
	except FileNotFoundError: #if compilation was not successful
		b_make['background'] = 'green'
		b_make['text'] = 'Make - ERROR!'

def flash():
	b_flash['background'] = 'red'
	os.system('make flash')
	b_flash['background'] = 'green'

tintr = tkinter.Tk()
tintr.title('ESP Flasher v1.3')
b_make = tkinter.Button(tintr, background="green" , command=lambda : threading.Thread(target=make, args=()).start(), font=('',30), text='Make')
b_make.pack()
b_flash = tkinter.Button(tintr, background="green", command=lambda : threading.Thread(target=flash, args=()).start(), font=('',30), text='Flash')
b_flash.pack()
tkinter.Button(tintr, command=exit, font=('',30), text='Close').pack()
tintr.mainloop()