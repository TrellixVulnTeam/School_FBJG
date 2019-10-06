from tkinter import *

tempOne = 0
tempTwo = 0
tempThree = 0
new = True
tempResult = 0
no = 0
haveDot = False
memR = 0


def number(num):
    global tempTwo
    global new

    if numbers.cget("text") == "0":
        text = num
        new = False
    elif new:
        text = num
        new = False
    else:
        text = numbers.cget("text") + num
    numbers.config(text=text)


def operation(op):
    global tempOne
    global tempTwo
    global new
    global tempResult, no, haveDot

    if numbers.cget("text") == "CANNOT DIVIDE BY ZERO":
        return

    tempOne = numbers.cget("text")
    haveDot = False
    if op == "sqr":
        temp.config(text=temp.cget("text")+" "+tempOne+"²")
        tmp = float(tempOne)**2
        tempOne = str(tmp)
        numbers.config(text=tempOne)
        no = 1
        return
    if op == "1/x":
        temp.config(text=tempOne+"/x")
        tmp = 1/float(tempOne)
        tempOne = str(tmp)
        numbers.config(text=tempOne)
        no = 1
        return
    if op == "sqrt":
        temp.config(text=tempOne+"/x")
        tmp = float(tempOne)**(1/2)
        tempOne = str(tmp)
        numbers.config(text=tempOne)
        no = 1
        return
    if op == "+-" and numbers.cget("text") != "0":
        tmp = -float(tempOne)
        tempOne = str(tmp)
        numbers.config(text=tempOne)
        return
    elif op == "+-":
        return

    if tempOne != 0:
        if tempTwo == 0:
            tempTwo = op
            if no == 0:
                temp.config(text=str(tempOne)+" "+op)
            else:
                temp.config(text=temp.cget("text")+" "+op)
            tempResult = tempOne
            no = 0
        else:
            if no == 0:
                temp.config(text=temp.cget("text")+" "+str(tempOne)+" "+op)
            else:
                temp.config(text=temp.cget("text")+" "+op)

            if tempTwo == "+":
                result = float(tempResult) + float(numbers.cget("text"))
                numbers.config(text=str(result))
            elif tempTwo == "-":
                result = float(tempResult) - float(numbers.cget("text"))
                numbers.config(text=str(result))
            elif tempTwo == "*":
                result = float(tempResult) * float(numbers.cget("text"))
                numbers.config(text=str(result))
            elif tempTwo == "/":
                if numbers.cget("text") == "0":
                    numbers.config(text="CANNOT DIVIDE BY ZERO")
                    temp.config(text=" ")
                    tempOne = 0
                    tempTwo = 0
                    tempResult = 0
                    return
                else:
                    result = float(tempResult) / float(numbers.cget("text"))
                    numbers.config(text=str(result))
            elif tempTwo == "%":
                result = float(tempResult) % float(numbers.cget("text"))
                numbers.config(text=str(result))
            tempTwo = op
            no = 0
            tempResult = result
        new = True


def equal():
    global tempResult
    global tempOne
    global tempTwo
    global tempThree
    global new

    if tempOne == 0:
        return
    if tempTwo !=0:
        tempThree = tempTwo
    tempTwo = 0
    if temp.cget("text") != " ":
        tempOne = numbers.cget("text")

    temp.config(text=" ")
    if tempThree == "+":
        tempResult = float(tempResult) + float(tempOne)
    elif tempThree == "-":
        tempResult = float(tempResult) - float(tempOne)
    elif tempThree == "*":
        tempResult = float(tempResult) * float(tempOne)
    elif tempThree == "/":
        if numbers.cget("text") == "0":
            tempResult = "CANNOT DIVIDE BY ZERO"
            tempOne = 0
            tempThree = 0
        else:
            tempResult = float(tempResult) / float(tempOne)
    elif tempThree == "%":
        tempResult = float(tempResult) % float(tempOne)
    numbers.config(text=str(tempResult))
    new = True


def dot():
    global haveDot
    global new
    if haveDot:
        return
    else:
        numbers.config(text=numbers.cget("text")+".")
        haveDot = True
        if numbers.cget("text") == "0":
            new = True


def clear(op):
    global tempOne
    global tempTwo
    if op == "CE":
        numbers.config(text="0")
    elif op == "C":
        numbers.config(text="0")
        temp.config(text=" ")
        tempOne = 0
        tempTwo = 0
    elif op == "DEL":
        if len(numbers.cget("text")) == 1:
            numbers.config(text="0")
        else:
            numbers.config(text=numbers.cget("text")[:-1])


root = Tk()
root.minsize(320, 410)
root.title("Calculator")
root.config(bg="gray20")
root.attributes('-alpha', 0.95)

display = Frame(root, bg="gray20")
display.grid(row=0, column=0, padx=0, sticky=W+E+N+S)
Grid.columnconfigure(root, 0, weight=1)
#Grid.rowconfigure(root, 0, weight=1)

temp = Label(display, text=" ", anchor="e", bg="gray20", fg="grey")
temp.grid(row=0, column=0, columnspan=6, sticky=W+E+N+S)
numbers = Label(display, text="0", anchor="e", bg="gray20", fg="white", height=4)
numbers.grid(row=1, column=0, columnspan=6, sticky=W+E+N+S)

MC = Button(display, text="MC", border=2, bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", state=DISABLED)
if MC.cget("state") != DISABLED:
    MC.bind("<Enter>", lambda event: MC.configure(state=ACTIVE))
    MC.bind("<Leave>", lambda event: MC.configure(state=NORMAL))
MC.grid(row=2, column=0, padx=2, sticky=W+E+N+S)
MR = Button(display, text="MR", bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", state=DISABLED)
MR.grid(row=2, column=1, padx=2, sticky=W+E+N+S)
if MR.cget("state") != DISABLED:
    MR.bind("<Enter>", lambda event: MR.configure(state=ACTIVE))
    MR.bind("<Leave>", lambda event: MR.configure(state=NORMAL))
MP = Button(display, text="M+", bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white")
MP.grid(row=2, column=2, padx=2, sticky=W+E+N+S)
MP.bind("<Enter>", lambda event: MP.configure(state=ACTIVE))
MP.bind("<Leave>", lambda event: MP.configure(state=NORMAL))
MM = Button(display, text="M-", bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white")
MM.grid(row=2, column=3, padx=2, sticky=W+E+N+S)
MM.bind("<Enter>", lambda event: MM.configure(state=ACTIVE))
MM.bind("<Leave>", lambda event: MM.configure(state=NORMAL))
MS = Button(display, text="MS", bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white")
MS.grid(row=2, column=4, padx=2, sticky=W+E+N+S)
MS.bind("<Enter>", lambda event: MS.configure(state=ACTIVE))
MS.bind("<Leave>", lambda event: MS.configure(state=NORMAL))
MV = Button(display, text="Mˇ", bg="gray20", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", state=DISABLED)
MV.grid(row=2, column=5, padx=2, sticky=W+E+N+S)
if MV.cget("state") != DISABLED:
    MV.bind("<Enter>", lambda event: MV.configure(state=ACTIVE))
    MV.bind("<Leave>", lambda event: MV.configure(state=NORMAL))

for x in range(6):
    Grid.columnconfigure(display, x, weight=1)

for y in range(2):
    Grid.rowconfigure(display, y, weight=1)

keyboard = Frame(root, bg="gray20")
keyboard.grid(row=1, column=0, padx=2, pady=4, sticky=W+E+N+S)

Grid.rowconfigure(root, 1, weight=1)

MOD = Button(keyboard, text="%", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("%"), border=0)
MOD.grid(row=0, column=0, padx=2, pady=2, sticky=W+E+N+S)
MOD.bind("<Enter>", lambda event: MOD.configure(state=ACTIVE))
MOD.bind("<Leave>", lambda event: MOD.configure(state=NORMAL))
sqrt = Button(keyboard, text="√", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("sqrt"), border=0)
sqrt.grid(row=0, column=1, padx=2, pady=2, sticky=W+E+N+S)
sqrt.bind("<Enter>", lambda event: sqrt.configure(state=ACTIVE))
sqrt.bind("<Leave>", lambda event: sqrt.configure(state=NORMAL))
sqr = Button(keyboard, text="x²", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("sqr"), border=0)
sqr.grid(row=0, column=2, padx=2, pady=2, sticky=W+E+N+S)
sqr.bind("<Enter>", lambda event: sqr.configure(state=ACTIVE))
sqr.bind("<Leave>", lambda event: sqr.configure(state=NORMAL))
DIVX = Button(keyboard, text="1⁄x", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("1/x"), border=0)
DIVX.grid(row=0, column=3, padx=2, pady=2, sticky=W+E+N+S)
DIVX.bind("<Enter>", lambda event: DIVX.configure(state=ACTIVE))
DIVX.bind("<Leave>", lambda event: DIVX.configure(state=NORMAL))

CE = Button(keyboard, text="CE", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: clear("CE"), border=0)
CE.grid(row=1, column=0, padx=2, pady=2, sticky=W+E+N+S)
CE.bind("<Enter>", lambda event: CE.configure(state=ACTIVE))
CE.bind("<Leave>", lambda event: CE.configure(state=NORMAL))
C = Button(keyboard, text="C", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: clear("C"), border=0)
C.grid(row=1, column=1, padx=2, pady=2, sticky=W+E+N+S)
C.bind("<Enter>", lambda event: C.configure(state=ACTIVE))
C.bind("<Leave>", lambda event: C.configure(state=NORMAL))
DEL = Button(keyboard, text="DEL", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: clear("DEL"), border=0)
DEL.grid(row=1, column=2, padx=2, pady=2, sticky=W+E+N+S)
DEL.bind("<Enter>", lambda event: DEL.configure(state=ACTIVE))
DEL.bind("<Leave>", lambda event: DEL.configure(state=NORMAL))
DIV = Button(keyboard, text="÷", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("/"), border=0)
DIV.grid(row=1, column=3, padx=2, pady=2, sticky=W+E+N+S)
DIV.bind("<Enter>", lambda event: DIV.configure(state=ACTIVE))
DIV.bind("<Leave>", lambda event: DIV.configure(state=NORMAL))

SEVEN = Button(keyboard, text="7", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("7"), border=0)
SEVEN.grid(row=2, column=0, padx=2, pady=2, sticky=W+E+N+S)
SEVEN.bind("<Enter>", lambda event: SEVEN.configure(state=ACTIVE))
SEVEN.bind("<Leave>", lambda event: SEVEN.configure(state=NORMAL))
EIGHT = Button(keyboard, text="8", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("8"), border=0)
EIGHT.grid(row=2, column=1, padx=2, pady=2, sticky=W+E+N+S)
EIGHT.bind("<Enter>", lambda event: EIGHT.configure(state=ACTIVE))
EIGHT.bind("<Leave>", lambda event: EIGHT.configure(state=NORMAL))
NINE = Button(keyboard, text="9", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("9"), border=0)
NINE.grid(row=2, column=2, padx=2, pady=2, sticky=W+E+N+S)
NINE.bind("<Enter>", lambda event: NINE.configure(state=ACTIVE))
NINE.bind("<Leave>", lambda event: NINE.configure(state=NORMAL))
MUL = Button(keyboard, text="×", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("*"), border=0)
MUL.grid(row=2, column=3, padx=2, pady=2, sticky=W+E+N+S)
MUL.bind("<Enter>", lambda event: MUL.configure(state=ACTIVE))
MUL.bind("<Leave>", lambda event: MUL.configure(state=NORMAL))

FOUR = Button(keyboard, text="4", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("4"), border=0)
FOUR.grid(row=3, column=0, padx=2, pady=2, sticky=W+E+N+S)
FOUR.bind("<Enter>", lambda event: FOUR.configure(state=ACTIVE))
FOUR.bind("<Leave>", lambda event: FOUR.configure(state=NORMAL))
FIVE = Button(keyboard, text="5", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("5"), border=0)
FIVE.grid(row=3, column=1, padx=2, pady=2, sticky=W+E+N+S)
FIVE.bind("<Enter>", lambda event: FIVE.configure(state=ACTIVE))
FIVE.bind("<Leave>", lambda event: FIVE.configure(state=NORMAL))
SIX = Button(keyboard, text="6", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("6"), border=0)
SIX.grid(row=3, column=2, padx=2, pady=2, sticky=W+E+N+S)
SIX.bind("<Enter>", lambda event: SIX.configure(state=ACTIVE))
SIX.bind("<Leave>", lambda event: SIX.configure(state=NORMAL))
MINUS = Button(keyboard, text="-", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("-"), border=0)
MINUS.grid(row=3, column=3, padx=2, sticky=W+E+N+S)
MINUS.bind("<Enter>", lambda event: MINUS.configure(state=ACTIVE))
MINUS.bind("<Leave>", lambda event: MINUS.configure(state=NORMAL))

ONE = Button(keyboard, text="1", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("1"), border=0)
ONE.grid(row=4, column=0, padx=2, pady=2, sticky=W+E+N+S)
ONE.bind("<Enter>", lambda event: ONE.configure(state=ACTIVE))
ONE.bind("<Leave>", lambda event: ONE.configure(state=NORMAL))
TWO = Button(keyboard, text="2", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("2"), border=0)
TWO.grid(row=4, column=1, padx=2, pady=2, sticky=W+E+N+S)
TWO.bind("<Enter>", lambda event: TWO.configure(state=ACTIVE))
TWO.bind("<Leave>", lambda event: TWO.configure(state=NORMAL))
THREE = Button(keyboard, text="3", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("3"), border=0)
THREE.grid(row=4, column=2, padx=2, pady=2, sticky=W+E+N+S)
THREE.bind("<Enter>", lambda event: THREE.configure(state=ACTIVE))
THREE.bind("<Leave>", lambda event: THREE.configure(state=NORMAL))
PLUS = Button(keyboard, text="+", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("+"), border=0)
PLUS.grid(row=4, column=3, padx=2, pady=2, sticky=W+E+N+S)
PLUS.bind("<Enter>", lambda event: PLUS.configure(state=ACTIVE))
PLUS.bind("<Leave>", lambda event: PLUS.configure(state=NORMAL))

PorM = Button(keyboard, text="±", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: operation("+-"), border=0)
PorM.grid(row=5, column=0, padx=2, pady=2, sticky=W+E+N+S)
PorM.bind("<Enter>", lambda event: PorM.configure(state=ACTIVE))
PorM.bind("<Leave>", lambda event: PorM.configure(state=NORMAL))
ZERO = Button(keyboard, text="0", bg="black", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: number("0"), border=0)
ZERO.grid(row=5, column=1, padx=2, pady=2, sticky=W+E+N+S)
ZERO.bind("<Enter>", lambda event: ZERO.configure(state=ACTIVE))
ZERO.bind("<Leave>", lambda event: ZERO.configure(state=NORMAL))
DOT = Button(keyboard, text=",", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: dot(), border=0)
DOT.grid(row=5, column=2, padx=2, pady=2, sticky=W+E+N+S)
DOT.bind("<Enter>", lambda event: DOT.configure(state=ACTIVE))
DOT.bind("<Leave>", lambda event: DOT.configure(state=NORMAL))
RES = Button(keyboard, text="=", bg="gray12", fg="white", relief=FLAT, activebackground="gray30", activeforeground="white", command=lambda: equal(), border=0)
RES.grid(row=5, column=3, padx=2, pady=2, sticky=W+E+N+S)
RES.bind("<Enter>", lambda event: RES.configure(state=ACTIVE))
RES.bind("<Leave>", lambda event: RES.configure(state=NORMAL))

for x in range(4):
    Grid.columnconfigure(keyboard, x, weight=1)
for y in range(6):
    Grid.rowconfigure(keyboard, y, weight=1)

root.mainloop()
