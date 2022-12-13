#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## AI server
##

import socket
import sys

class Socket:
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connected = False

    def send_msg(self, messageg):
        if (self.connected == True):
            print("Sending...\n", message)
            self.socket.sendall(message.encode('ascii'))

    def receive_msg(self):
        if (self.connected == True):
            message = self.socket.recv(1024).decode('ascii')
            print("Receiving...\n", message)
            return (message)
    
    def connect(self):
        try:
            self.socket.connect(self.host, self.port)
            self.connected = True
            print("Connected to", host, "to", port)
        except Exception as e:
            print("Connection error: %s" % str(e), file=sys.stderr)
            sys.exit(84)
    
    def disconnect(self):
        try:
            self.socket.close()
            self.connected = False
            print("Disconnection")
        except Exception as e:
            print("Disconnection error: %s" % str(e), file=sys.stderr)
            sys.exit(84)