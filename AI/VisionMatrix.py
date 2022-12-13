#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## Zappy
## File description:
## Matrix of vision and functions
##

limitVision = [0, (1,3), (4, 8), (9, 15), (16, 24), (25, 35), (36, 48), (49, 63), (64, 80)]

def createMatrix(level):
        u0 = 1
        un = u0 + 2 * level
        A = [[0 for x in range(un)] for y in range(level + 1)]
        x = 0
        space = un
        star = 0
        while (x < (level + 1)):
            if (star == 0):
                for i in range(un):
                    A[x][i] = " "
            else:
                y = 0
                un = un - 2
                for i in range(int(star/2)):
                    A[x][y] = "O"
                    y = y + 1
                for j in range(un):
                    A[x][y] = " "
                    y = y + 1
                for k in range(int(star/2)):
                    A[x][y] = "O"
                    y = y + 1
            x = x + 1
            star = 2 * x
        return (A)

class Vision:
    def __init__(self, level):
        self.level = level
        self.mat = createMatrix(level)

    def look(self, objNum):
        case = 0
        for i in reversed(range(len(self.mat))):
            for j in reversed(range(len(self.mat))):
                if (self.mat[i][j] == " "):
                    case += 1
                if (case == objNum):
                    return (i, j)
    
    def nbrStep(self, case):
        nbrCase = limitVision[self.level - 1][1] - limitVision[self.level - 1][0] + 1
        middleCase = nbrCase // 2 + limitVision[self.level - 1][0]
        if (limitVision[self.level - 1][0] <= case and middleCase > case):
            return (("Left", middleCase - case))
        elif (middleCase == case):
            return (("Middle", case))
        else:
            return (("Right", case - middleCase))
