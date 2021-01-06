t.begin_fill()
    t.color(edg, bk)
    for k in range(n):
        t.forward(l)
        t.left(alpha)
    t.hideturtle()
    t.end_fill()
    t.done()