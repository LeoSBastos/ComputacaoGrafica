from rgb import RGB

if __name__ == "__main__":
    r = float(input("Digite seu R: "))
    g  = float(input("Digite seu G: "))
    b  = float(input("Digite seu B: "))
    rgb = RGB(r,g,b)
    rgb.calculeXYZ()
    rgb.imprime()