#!/bin/python
import socket

skt = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)

skt.connect((socket.gethostbyname('dweet.io'), 80))

#"GET %s HTTP/1.1\nHost: %s\nUser-Agent: wget\n\nConnection: close\n\n", SUBDIR, HOSTNAME);
print(skt.send(bytes('GET /get/latest/dweet/for/E32_868T30D_Test HTTP/1.1\r\nHost: dweet.io\r\nUser-Agent: wget\r\nConnection: keep-alive\r\n\r\n','utf-8')))
data = skt.recv(10240)
print(data)
print(len(data))