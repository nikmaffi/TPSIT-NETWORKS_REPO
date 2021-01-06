class Text:
    def __init__(self, txt, fontName, siz, textColor, centAlign, posX, posY, screenWidth, screenHeight):
        if size <= 0:
            raise Exception("Errore: La grandezza del font deve essere maggiore di 0!")
            
        self.txt = txt
        self.font = createFont(fontName, siz)
        self.siz = siz
        self.textColor = textColor
        self.centAlign = centAlign
        self.posX = posX
        self.posY = posY
        self.screenWidth = screenWidth
        self.screenHeight = screenHeight
        
    
    def setText(self, txt):
        self.txt = txt
        
    
    def write(self):
        if(self.centAlign):
            textAlign(CENTER, CENTER)
            self.posX = self.screenWidth / 2
            self.posY = self.screenHeight / 2
            
        textFont(self.font)
        textSize(self.siz)
        fill(self.textColor)
        text(self.txt, self.posX, self.posY)
        
