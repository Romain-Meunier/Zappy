#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Player method
##

import visionMatrix
import Socket
import random
import sys

# Macros
N = 1
E = 2
S = 3
W = 4
MAX_PLAYER = 6

class Level_required:
    def __init__(self, nb, lin, der, sib, mend, phi, thys):
        self.required = {
            'nb players': nb,
            'linemate': lin,
            'deraumere': der,
            'sibur': sib,
            'mendiane': mend,
            'phiras': phi,
            'thystame': thys
        }

levelList= [0, Level_required(1, 1, 0, 0, 0, 0, 0),
    Level_required(2, 1, 1, 1, 0, 0, 0),
    Level_required(2, 2, 0, 1, 0, 2, 0),
    Level_required(4, 1, 1, 2, 0, 1, 0),
    Level_required(4, 1, 2, 1, 3, 0, 0),
    Level_required(6, 1, 2, 3, 0, 1, 0),
    Level_required(6, 2, 2, 2, 2, 2, 1)
    ]

ressourceLst = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]

class Pos:
    def __init__(self, x, y, O):
        self.X = x
        self.Y = y
        self.O = O

class Player:
    def __init__(self, port, name, machine):
        self.name = name
        self.port = port
        self.machine = machine
        self.socket = Socket(machine, port)
        self.level = 1
        self.life = 1260
        self.vision = Vision(1)
        self.objSeen = {}
        self.pos = Pos(0, 0, N)
        self.bag = Level_required(1, 0, 0, 0, 0, 0, 0)
        self.nbrPlayer = 1
        self.objFound = False
        self.objNeeded = ""
        self.caseDest = 0
        self.mapDest = Pos(0, 0, N)

    ### Communication with server ###
    def connect(self):
        self.socket.connect()
    
    def disconnect(self):
        self.socket.disconnect()

    def send_msg(self, msg):
        self.socket.send_msg(msg)

    def receive_msg(self):
        msg = self.socket.receive_msg()
        message = msg.split("\n")
        return (message[0])

    ### Action ###
    def forward(self):
        self.send_msg("Forward")
        while (True):
            msg = self.receive_msg()
            if (msg == "ok"):
                break
        if (self.pos.O == N):
            self.pos.Y += 1
        elif (self.pos.O == E):
            self.pos.X += 1
        elif (self.pos.O == S):
            self.pos.Y -= 1
        elif (self.pos.O == W):
            self.pos.X -= 1
        self.life -= 7
    
    def right(self):
        self.send_msg("Right")
        while (True):
            msg = self.receive_msg()
            if (msg == "ok"):
                break
        if (self.pos.O == N):
            self.pos.O = E
        elif (self.pos.O == E):
            self.pos.O = S
        elif (self.pos.O == S):
            self.pos.O = W
        elif (self.pos.O == W):
            self.pos.O = N
        self.life -= 7
    
    def left(self):
        self.send_msg("Left")
        while (True):
            msg = self.receive_msg()
            if (msg == "ok"):
                break
        if (self.pos.O == N):
            self.pos.O = W
        elif (self.pos.O == E):
            self.pos.O = S
        elif (self.pos.O == S):
            self.pos.O = E
        elif (self.pos.O == W):
            self.pos.O = N
        self.life -= 7

    def look(self):
        i = 0
        self.send_msg("Look")
        while (True):
            msg = self.receive_msg()
            if (msg != ""):
                break
        objLst = msg.split("[")
        objLst = objLst[1].split("]")
        objLst = objLst[0].split(",")
        for element in objLst:
            obj = element.split(" ")
            if (len(obj) > 1):
                objSeen[i] = [obj[0]]
                for j in range(1, len(obj)):
                    objSeen[i].append(obj[j])
            else:
                objSeen[i] = [element]
            i += 1
        self.life -= 7

    def inventory(self):
        self.send_msg("Inventory")
        while (True):
            msg = self.receive_msg()
            if (msg != ""):
                break
        stoneLst = msg.split("[")
        stoneLst = stoneLst[1].split("]")
        stoneLst = stoneLst[0].split(",")
        for element in stoneLst:
            stone = element.split(" ")
            if (stone[0] == "linemate" and int(stone[1]) != bag["linemate"]):
                bag["linemate"] += int(stone[1])
            elif (stone[0] == "deraumere" and int(stone[1]) != bag["deraumere"]):
                bag["deraumere"] += int(stone[1])
            elif (stone[0] == "sibur" and int(stone[1]) != bag["sibur"]):
                bag["sibur"] += int(stone[1])
            elif (stone[0] == "mendiane" and int(stone[1]) != bag["mendiane"]):
                bag["mendiane"] += 1
            elif (stone[0] == "phiras" and int(stone[1]) != bag["phiras"]):
                bag["phiras"] += 1
            elif (stone[0] == "thystame" and int(stone[1]) != bag["thystame"]):
                bag["thystame"] += 1
        self.life -= 1

    def fork(self):
        self.send_msg("Fork")
        while (True):
            msg = self.receive_msg()
            if (msg == "ok"):
                break
        self.nbrPlayer += 1
        self.life -= 42

    def eject(self):
        self.send_msg("Eject")
        while (True):
                msg = self.receive_msg()
                if (msg == "ok"):
                    break
        self.life -= 7
    
    def broadcast(self, message):
        self.send_msg("Broadcast " + message)
        while (True):
                msg = self.receive_msg()
                if (msg == "ok"):
                    break
        self.level -= 7
    
    def connect_nbr(self):
        self.send_msg("Connect_nbr")
        while (True):
                msg = self.receive_msg()
                if (msg == "ok"):
                    break

    def takeObject(self, objt):
        self.send_msg("Take_object " + objt)
        while (True):
                msg = self.receive_msg()
                if (msg == "ok" or msg == "ko"):
                    break
        if (msg == "ok"):
            for element in self.objSeen[self.caseDest]:
                if (element != "Food" and element == objt):
                    self.bag[element] += 1
                    self.objSeen.pop(self.caseDest)
                    break
                elif (element == "Food"):
                    self.life += 126
                    self.objSeen.pop(self.caseDest)
                    break
        self.objFound = False
        self.life -= 7

    def setObject(self, object):
        self.send_msg("Set_object")
        while (True):
                msg = self.receive_msg()
                if (msg == "ok" or msg == "ko"):
                    break
        if (msg == "ok"):
            if (object != "food"):
                self.bag[object] -= 1
        self.life -= 7

    def incantation(self):
        self.send_msg("Incantation")
        nbr_msg = 0
        while (nbr_msg != 3):
            while (True):
                msg = self.receive_msg()
                if (msg == "Elevation underway" or msg == "ko"):
                    nbr_msg += 1
                    break
                else:
                    buff = msg.split(":")
                    self.level = buff[1]
                    nbr_msg += 1
                    break
        self.life -= 300

    ### strategy ###
    def objectNeeded(self):
        self.inventory()
        for item, value in self.bag.items():
            if (value < levelList[self.level][item]):
                self.objNeeded = item
                return (item)
    
    def foodNeeded(self):
        if (self.life <= 260):
            self.objNeeded = "food"
        else:
            self.objNeeded = ""

    def sortObjSeen(self):
        for case, items in self.objSeen.items():
            for element in items:
                if (element == "player")
                    self.objSeen.pop(case)

    def pickUpCase(self):
        isNeeded = self.foodNeeded
        if (isNeeded != "food"):
            isNeeded = self.objectNeeded()
        for case, items in self.objSeen.items():
            for element in items:
                if (element == isNeeded):
                    self.objFound = True
                    return (case)
        if (self.objFound == False):
            for case, items in self.objSeen.items():
                for element in items:
                    self.objNeeded = random.choice(element)
                    return (case)

    def setDestination(self):
        self.look()
        self.sortObjSeen()
        self.caseDest = self.pickUpCase()
        self.mapDest.O = self.pos.O 

    def goToCase(self):
        coordCase = self.vision.look(self.caseDest)
        self.mapDest.X = coordCase[0]
        self.mapDest.Y = coordCase[1]
        for i in range(self.mapDest.Y):
            self.forward()
        nbrStep = self.vision.nbrCase(self.caseDest)
        if (nbrStep[0] == "Right"):
            self.right()
            for j in range(nbrStep):
                self.forward()
        elif (nbrStep[0] == "Left"):
            self.left()
            for j in range(nbrStep):
                self.forward()
        self.takeObject(self.objectNeeded())

    def enoughPlayer(self):
        if (self.nbrPlayer == levelList[self.level]["nb players"]):
            return (True)
        else:
            return (False)

    def checkRequirement(self):
        for case, value in self.bag.items():
            if (self.bag[case] == levelList[self.level][case]):
                continue
            else:
                return (False)
        return (True)

    def play(self):
        while (True):
            while (self.enoughPlayer() != True):
                self.fork()
            self.setDestination()
            self.goToCase()
            if (checkRequirement == True):
                self.broadcast("Join_me")
                self.incantation()
                self.level += 1

    def setting(self):
        self.connect()
        self.receive_msg()
        self.send_msg(self.name)
        self.receive_msg()
        self.receive_msg()

    def start(self):
        self.setting()
        self.play()

def get_info(arg):
    info = {
        "-p": ""
        "-n": ""
        "-h": ""
    }
    for i in range(1, len(arg) - 1):
        if (arg[i] == "-p"):
            info["-p"] = arg[i + 1]
        elif (arg[i] == "-n"):
            info["-n"] = arg[i + 1]
        elif (arg[i] == "-h"):
            info["-h"] = arg[i + 1]
    return (info)

def main(argv):
    if (len(argv) == 7):
        info = get_info(argv)
        player = Player(info["-p"], info["-n"], info["h"])
        player.start()
    else:
        sys.exit(84)

if __name__ == "__main__":
    main(sys.argv)