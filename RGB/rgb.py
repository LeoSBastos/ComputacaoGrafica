import numpy as np

class RGB():
    def __init__(self,r,g,b):
        self.rgb = np.array([round(r/2.55),round(g/2.55),round(b/2.55)])
        self.matriztransformacao = np.array([[0.4124, 0.3576, 0.1805],
[0.2126, 0.7152, 0.0722],
[0.0193, 0.1192, 0.9505]])
        self.w = max([r/255,g/255,b/255])
        self.c = (self.w -(r/255))/self.w
        self.m = (self.w -(g/255))/self.w
        self.y = (self.w -(b/255))/self.w
        self.k = 1 - self.w

    def calculeXYZ(self):
        self.XYZ = self.matriztransformacao * self.rgb

    def imprime(self):
        print("XYZ: {}\nCMYK: {}".format(self.XYZ[self.XYZ > 0],[self.c,self.m,self.y,self.k]))