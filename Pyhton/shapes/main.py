import turtle
import math

def draw_shape(n, bk, edg):
    alpha = 360 / n
    l = 900 / n
    t = turtle.Turtle()

    t.goto(0 - l / 2, 0 - math.sin(turtle.radians(((180 - alpha) / 2))) * (l / 2) / math.cos(turtle.radians(((180 - alpha) / 2))))

    t.begin_fill()
    t.color(edg, bk)
    for k in range(n):
        t.forward(l)
        t.left(alpha)
        
    t.hideturtle()
    t.end_fill()
    t.done()


def main():
    nLati = int(input("\nInsert the shape edges number: "))

    if nLati <= 2 or nLati > 40:
        print("\nThe edges number must be between 3 and 40.\n\n")
        input("Press any key to quit.\n\n")
        return

    bkColor = input("Insert the shape color: ")
    lnColor = input("Insert the edges color: ")

    draw_shape(nLati, bkColor, lnColor)

    input("\nPress any key to quit.\n\n")


if __name__ == "__main__":
    main()