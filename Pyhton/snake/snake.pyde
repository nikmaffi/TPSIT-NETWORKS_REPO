import Text

cellSize = 0
matrixRows = 0
matrixCols = 0

rowField = 0
colField = 1

grassColor = "#9ea26b"
grassCode = 0
snake = 0
food = 0
matrixField = 0
eaten = False
run = True
scoreTxt = 0
gameOverTxt = 0


def putFood():
    global food, matrixField, eaten
    
    if(not eaten):
        while True:
            food["row"] = int(random(matrixRows))
            food["col"] = int(random(matrixCols))
            
            if matrixField[food["row"]][food["col"]] != snake["code"]:
                break

        eaten = not eaten

    matrixField[food["row"]][food["col"]] = food["code"]
    fill(food["color"])
    circle(food["col"] * cellSize + cellSize / 2, food["row"] * cellSize + cellSize / 2, cellSize)
    
    
def moveSnake():
    global matrixField, snake, eaten, run, scoreTxt

    matrixField[snake["body"][-1][rowField]][snake["body"][-1][colField]] = grassCode

    for idx in range(len(snake["body"]) - 1, 0, -1):
        snake["body"][idx][rowField] = snake["body"][idx - 1][rowField]
        snake["body"][idx][colField] = snake["body"][idx - 1][colField]

    if snake["direction"] == "UP":
        snake["body"][0][rowField] -= 1
    elif snake["direction"] == "DOWN":
        snake["body"][0][rowField] += 1
    elif snake["direction"] == "RIGHT":
        snake["body"][0][colField] += 1
    elif snake["direction"] == "LEFT":
        snake["body"][0][colField] -= 1
        
    if snake["body"][0][rowField] >= matrixRows or snake["body"][0][rowField] < 0 or snake["body"][0][colField] >= matrixCols or snake["body"][0][colField] < 0 or matrixField[snake["body"][0][rowField]][snake["body"][0][colField]] == snake["code"]:
           run = not run
           return

    if matrixField[snake["body"][0][rowField]][snake["body"][0][colField]] == food["code"]:
        snake["body"].append([snake["body"][0][rowField], snake["body"][0][colField]])
        snake["length"] += 1
        eaten = not eaten
        scoreTxt.setText("Pt: " + str(snake["length"] - 1))

    for idx, el in enumerate(snake["body"]):
        matrixField[el[rowField]][el[colField]] = snake["code"]
        fill(snake["color"])
        rect(el[colField] * cellSize, el[rowField] * cellSize, cellSize, cellSize)
        
    delay(80)


def settings():
    size(1026, 770)


def setup():
    global cellSize, matrixRows, matrixCols, snake, food, matrixField, scoreTxt, gameOverTxt
    
    cellSize = 16
    matrixRows = (height - 2) / cellSize
    matrixCols = (width - 2) / cellSize
    
    snake = {
        "length"    : 1,
        "direction" : "RIGHT",
        "body"      : [[1, 1]],
        "color"     : "#31639c",
        "code"      : 1
    }
    
    food = {
        "row"   : 0,
        "col"   : 0,
        "color" : "#b95b6d",
        "code"  : 2
    }
    
    try:
        scoreTxt = Text.Text("Pt: " + str(snake["length"] - 1), "Alien Encounters", 45, color(0, 0, 255), False, 30, 45, width - 2, height - 2)
        gameOverTxt = Text.Text("GAME OVER", "Alien Encounters", 90, color(0, 0, 255), True, 0, 0, width - 2, height - 2)
    except AssertionError as error:
        print(error)
        exit()
    
    matrixField = [[0 for col in range(matrixCols)] for row in range(matrixRows)]


def draw():
    background(grassColor)
    
    if run:
        putFood()
        scoreTxt.write()
        moveSnake()
    else:
        gameOverTxt.write()


def keyTyped():
    global snake
    
    if key == 'w' or key == 'W':
        if snake["direction"] != "DOWN":
            snake["direction"] = "UP"
    elif key == 's' or key == 'S':
        if snake["direction"] != "UP":
            snake["direction"] = "DOWN"
    elif key == 'a' or key == 'A':
        if snake["direction"] != "RIGHT":
            snake["direction"] = "LEFT"
    elif key == 'd' or key == 'D':
        if snake["direction"] != "LEFT":
            snake["direction"] = "RIGHT"
