# https://www.tcl.tk/man/tcl8.4/TkCmd/keysyms.htm


import turtle


def moveRobotUp():
    global pointing
    len = 100

    if rbt.ycor() + len > h / 2:
        len = h / 2 - rbt.ycor() - 5
    
    if pointing == 0:
        rbt.left(90)
    elif pointing == 180:
        rbt.right(90)
    elif pointing == 270:
        rbt.left(180)

    rbt.forward(len)
    pointing = 90


def moveRobotDown():
    global pointing
    len = 100

    if rbt.ycor() - len < -1 * h / 2:
        len = h / 2 + rbt.ycor() - 10
    
    if pointing == 0:
        rbt.right(90)
    elif pointing == 180:
        rbt.left(90)
    elif pointing == 90:
        rbt.right(180)
        
    rbt.forward(len)
    pointing = 270


def moveRobotLeft():
    global pointing
    len = 100

    if rbt.xcor() - len < -1 * w / 2:
        len = w / 2 + rbt.xcor() - 5
    
    if pointing == 0:
        rbt.left(180)
    elif pointing == 270:
        rbt.right(90)
    elif pointing == 90:
        rbt.left(90)
        
    rbt.forward(len)
    pointing = 180


def moveRobotRight():
    global pointing
    len = 100

    if rbt.xcor() + len > w / 2:
        len = w / 2 - rbt.xcor() - 10
    
    if pointing == 270:
        rbt.left(90)
    elif pointing == 180:
        rbt.right(180)
    elif pointing == 90:
        rbt.right(90)
        
    rbt.forward(len)
    pointing = 0


def initGame():
    wdw.title("Main Window")
    wdw.setup(width=w, height=h)
    wdw.bgcolor("green")
    rbt.left(pointing)
    rbt.setx(0)
    rbt.sety(0)


def main():
    initGame()

    wdw.listen()
    wdw.onkey(moveRobotUp, "Up")
    wdw.onkey(moveRobotDown, "Down")
    wdw.onkey(moveRobotLeft, "Left")
    wdw.onkey(moveRobotRight, "Right")

    wdw.mainloop()


if __name__ == "__main__":
    wdw = turtle.Screen()
    rbt = turtle.Turtle()
    h = 500
    w = 900
    pointing = 0
    main()

"""
"__" = dunder
"""