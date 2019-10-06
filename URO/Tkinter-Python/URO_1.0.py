from tkinter import *
from tkinter import messagebox
from tkinter import ttk
from tkinter import filedialog
from tkinter.font import Font

def exit_function():
    if messagebox.askokcancel("Quit", "Do you really wish to quit?"):
        root.destroy()


def fav_function(x):
    if fav[x].cget("image") == "pyimage7":
        fav[x].config(image=imgFavY)
    else:
        fav[x].config(image=imgFav)


def btnHome_on_mouse_down(event):
    btnHome.config(bg="orchid3")
    color = "orchid2"
    btnFavorite.config(bg=color)
    btnOption.config(bg=color)
    btnExit.config(bg=color)

    for j in range(20):
        fav[j].pack_forget()
        main[j].pack_forget()
        icon[j].pack_forget()
        name[j].pack_forget()
        comment[j].pack_forget()
        user[j].pack_forget()
        msg[j].pack_forget()
        main[j].pack(side=TOP, fill=X, expand=1)
        icon[j].pack(side=LEFT)
        fav[j].pack(side=LEFT, fill=Y)
        name[j].pack(side=LEFT, fill=Y)
        comment[j].pack(side=LEFT, fill=BOTH, expand=1)
        user[j].pack(side=LEFT, fill=X, expand=1)
        msg[j].pack(side=LEFT, fill=Y)


def btnFavorite_on_mouse_down(event):
    btnFavorite.config(bg="orchid3")
    color = "orchid2"
    btnHome.config(bg=color)
    btnOption.config(bg=color)
    btnExit.config(bg=color)
    for i in range(20):
        if fav[i].cget("image") == "pyimage7":
            fav[i].pack_forget()
            main[i].pack_forget()
            icon[i].pack_forget()
            name[i].pack_forget()
            comment[i].pack_forget()
            user[i].pack_forget()
            msg[i].pack_forget()


# message window


def messagecanvasconfig(event):
    width = event.width - 4
    messagecanvas.itemconfigure("scrollFrame", width=width)
    scrollFrame.config(width=event.width - 4)
    msgonefull.config(width=event.width - 148)


def scrollframeconfig(event):
    messagecanvas.config(scrollregion=messagecanvas.bbox("all"))


def delete_function(x):
    messagewindow.destroy()
    fav[x].pack_forget()
    main[x].pack_forget()
    icon[x].pack_forget()
    name[x].pack_forget()
    comment[x].pack_forget()
    user[x].pack_forget()
    msg[x].pack_forget()


def open_emoji():
    global s
    if s:
        w.place_forget()
        s = False
    else:
        w.place(relx=0.06, rely=0.91, anchor=SW)
        s = True


def message(o):
    title = name[o].cget("text")[:-2]

    global messagewindow, messagecanvas, scrollFrame, msgonefull, w, s
    messagewindow = Toplevel(root)
    messagewindow.title(title)
    messagewindow.minsize(800, 500)
    messagewindow.wm_iconbitmap('favicon.ico')
    messagewindow.config(bg="white")
    leftframe = Frame(messagewindow, bg="orchid2", width=40)
    leftframe.pack(fill=Y, side=LEFT)
    # btnExit = Button(leftframe, bg="orchid2", width=40, height=40, image=imgExit, border=0, command=messagewindow.destroy, activebackground=activeColor)
    # btnExit.pack(side=BOTTOM)
    # btnExit.bind("<Enter>", lambda event: btnExit.configure(state=ACTIVE))
    # btnExit.bind("<Leave>", lambda event: btnExit.configure(state=NORMAL))

    msgusername = Frame(messagewindow, bg="white", height=50)
    msgusername.pack(side=TOP, fill=X)
    iconm = Label(msgusername, bg="white", image=icon[o].cget("image"), height=60, width=60, bd=0)
    iconm.pack(side=LEFT)
    font = Font(size=16)
    label = Label(msgusername, text=title, bg="white", font=font)
    label.pack(side=LEFT)
    delete = Button(msgusername, bg="white", image=imgTrash, relief=FLAT, bd=0, activebackground="red2",
                    command=lambda: delete_function(o))
    delete.pack(side=RIGHT, padx=6)
    delete.bind("<Enter>", lambda event: delete.configure(state=ACTIVE, image=imgTrashOn))
    delete.bind("<Leave>", lambda event: delete.configure(state=NORMAL, image=imgTrash))
    edit = Button(msgusername, bg="white", image=imgEdit, relief=FLAT, bd=0, activebackground="grey90")
    edit.pack(side=RIGHT)
    edit.bind("<Enter>", lambda event: edit.configure(state=ACTIVE))
    edit.bind("<Leave>", lambda event: edit.configure(state=NORMAL))

    line = []

    mainmessage = Frame(messagewindow, bg="white")
    mainmessage.pack(side=TOP, fill=BOTH, expand=1)
    messagecanvas = Canvas(mainmessage, bg="white")

    scroll = Scrollbar(mainmessage, orient="vertical", command=messagecanvas.yview)
    scroll.pack(side=RIGHT, fill=Y)
    messagecanvas.pack(side=TOP, fill=BOTH, expand=1)
    messagecanvas.config(yscrollcommand=scroll.set)

    scrollFrame = Frame(messagecanvas, bg="white")
    scrollFrame.pack(side=TOP, fill=BOTH, expand=1)
    messagecanvas.create_window((0, 0), window=scrollFrame, anchor=N + W)

    messagecanvas.bind("<Configure>", messagecanvasconfig)
    scrollFrame.bind("<Configure>", scrollframeconfig)

    line.append(0)
    line[0] = Frame(scrollFrame, bg="white", width=200)
    line[0].pack(side=TOP, fill=X)
    msgone = Frame(line[0], bg="grey90", width=200)
    msgone.pack(side=LEFT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone, text="Your mum gay", wraplength=300, bg="grey90", anchor=W, justify=LEFT)
    msgonetext.pack(side=LEFT, fill=X, padx=10)
    msgonefull = Frame(line[0], bg="white", width=400)
    msgonefull.pack(side=LEFT, fill=X, padx=10, pady=10, ipady=10)

    line.append(1)
    line[1] = Frame(scrollFrame, bg="white", width=100)
    line[1].pack(side=TOP, fill=X)
    msgone = Frame(line[1], bg="orchid2")
    msgone.pack(side=RIGHT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone, text="No u", wraplength=300, bg="orchid2", anchor=W, justify=LEFT)
    msgonetext.pack(side=RIGHT, fill=X, padx=10)

    line.append(2)
    line[2] = Frame(scrollFrame, bg="white", width=100)
    line[2].pack(side=TOP, fill=X)
    msgone = Frame(line[2], bg="grey90")
    msgone.pack(side=LEFT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone, text="*cries*", wraplength=300, bg="grey90", anchor=W, justify=LEFT)
    msgonetext.pack(side=LEFT, fill=X, padx=10)

    line.append(2)
    line[2] = Frame(scrollFrame, bg="white", width=100)
    line[2].pack(side=TOP, fill=X)
    msgone = Frame(line[2], bg="grey90")
    msgone.pack(side=LEFT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone,
                       text="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec quis nibh at felis congue commodo. Vivamus porttitor turpis ac leo.",
                       wraplength=300, bg="grey90", anchor=W, justify=LEFT)
    msgonetext.pack(side=LEFT, fill=X, padx=10)

    line.append(1)
    line[1] = Frame(scrollFrame, bg="white", width=100)
    line[1].pack(side=TOP, fill=X)
    msgone = Frame(line[1], bg="orchid2")
    msgone.pack(side=RIGHT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone, text="Lorem ipsum dolor sit amet, consectetuer adipiscing elit.", wraplength=300,
                       bg="orchid2", anchor=W, justify=LEFT)
    msgonetext.pack(side=RIGHT, fill=X, padx=10)

    line.append(2)
    line[2] = Frame(scrollFrame, bg="white", width=100)
    line[2].pack(side=TOP, fill=X)
    msgone = Frame(line[2], bg="grey90")
    msgone.pack(side=LEFT, fill=X, padx=10, pady=10, ipady=10)
    msgonetext = Label(msgone,
                       text="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Donec quis nibh at felis congue commodo. Vivamus porttitor turpis ac leo.",
                       wraplength=300, bg="grey90", anchor=W, justify=LEFT)
    msgonetext.pack(side=LEFT, fill=X, padx=10)

    sendtext = Frame(messagewindow, bg="white", height=50)
    sendtext.pack(side=BOTTOM, fill=X, ipady=5, padx=5)
    emoji = Button(sendtext, command=open_emoji, image=imgFunny, bd=0, activebackground="grey90")
    emoji.pack(side=LEFT, ipady=6)
    emoji.bind("<Enter>", lambda event: emoji.configure(state=ACTIVE))
    emoji.bind("<Leave>", lambda event: emoji.configure(state=NORMAL))
    messagetext = Text(sendtext, height=2, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
    messagetext.pack(side=LEFT, fill=X, expand=1)
    send = Button(sendtext, text="Send", bg="orchid2", relief=FLAT, bd=0, activebackground=activeColor)
    send.pack(side=LEFT, ipady=8, ipadx=8)
    send.bind("<Enter>", lambda event: send.configure(state=ACTIVE))
    send.bind("<Leave>", lambda event: send.configure(state=NORMAL))

    w = Frame(messagewindow, bg="white", height=80, width=100)
    s = False
    funny = Button(w, image=imgFunny, bg="white", bd=0, command=lambda: open_emoji())
    funny.pack(side=LEFT)
    funny.bind("<Enter>", lambda event: funny.configure(state=ACTIVE))
    funny.bind("<Leave>", lambda event: funny.configure(state=NORMAL))
    admired = Button(w, image=imgAdmired, bg="white", bd=0, command=lambda: open_emoji())
    admired.pack(side=LEFT)
    admired.bind("<Enter>", lambda event: admired.configure(state=ACTIVE))
    admired.bind("<Leave>", lambda event: admired.configure(state=NORMAL))
    ok = Button(w, image=imgOk, bg="white", bd=0, command=lambda: open_emoji())
    ok.pack(side=LEFT)
    ok.bind("<Enter>", lambda event: ok.configure(state=ACTIVE))
    ok.bind("<Leave>", lambda event: ok.configure(state=NORMAL))


# message window END

# Options


def window_close():
    btnHome.config(bg="orchid3")
    color = "orchid2"
    btnFavorite.config(bg=color)
    btnOption.config(bg=color)
    btnExit.config(bg=color)
    window.destroy()


def save_form(login, email, password, passwordnew, passwordnewcon):
    global loginText, emailText, passwordText, pictureText

    if password.get() == "" and passwordnew.get() == "" and passwordnewcon.get() == "":
        loginText = login.get()
        emailText = email.get()
        pictureText = root.filename
        messagebox.showinfo("Save", "Save successful")
    elif passwordText == password.get():
        if passwordnew.get() == passwordnewcon.get() and passwordnew.get() != "" and passwordnewcon != "":
            loginText = login.get()
            emailText = email.get()
            pictureText = root.filename
            passwordText = passwordnew.get()
            password.delete(0, 'end')
            passwordnew.delete(0, 'end')
            passwordnewcon.delete(0, 'end')
            messagebox.showinfo("Save", "Save successful")
        else:
            messagebox.showinfo("password", "New password does not match!")
            return
    else:
        messagebox.showinfo("Wrong password", "Try again!")


def fileopen(picture):
    window.filename = filedialog.askopenfilename(title="Selection",
                                                 filetypes=[("All files", "*.*"), ("PNG files", "*.png")])

    picture.delete(0, 'end')
    picture.insert(0, window.filename)


def btnOption_on_mouse_down(logintext, emailtext, passwordtext, picturetext, varialbe):
    btnOption.config(bg="orchid3")
    color = "orchid2"
    btnHome.config(bg=color)
    btnFavorite.config(bg=color)
    btnExit.config(bg=color)

    global window
    window = Toplevel(root)
    window.grab_set()
    window.minsize(300, 500)
    window.title("Options")
    window.wm_iconbitmap('favicon.ico')
    window.resizable(False, False)
    window.config(bg="white")
    window.lift()

    f = Frame(window, height=20, bg="white")
    f.grid(row=0)
    login = Label(window, text="Login:", bg="white")
    login.grid(row=1, sticky=W, padx=150)
    loginentry = Entry(window, width=30, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
    loginentry.grid(row=2, ipady=2, padx=150)
    if loginentry.get() == "":
        loginentry.insert(0, logintext)
    email = Label(window, text="Email:", bg="white")
    email.grid(row=3, sticky=W, padx=150)
    emailentry = Entry(window, width=30, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
    emailentry.grid(row=4, ipady=2, padx=150)
    if emailentry.get() == "":
        emailentry.insert(0, emailtext)
    f3 = Frame(window, bg="white")
    f3.grid(row=6, sticky=W, padx=150, pady=10)
    picture = Label(f3, text="Picture:", bg="white", anchor=W, justify=LEFT, width=26)
    picture.pack()
    pictureentry = Entry(f3, width=27, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                         highlightthickness=1)
    pictureentry.pack(side=LEFT)
    if pictureentry.get() == "":
        pictureentry.insert(0, picturetext)
    picturebutton = Button(f3, relief=FLAT, image=imgpicture, command=lambda: fileopen(pictureentry),
                           activebackground="grey80")
    picturebutton.pack(side=LEFT)
    picturebutton.bind("<Enter>", lambda event: picturebutton.configure(state=ACTIVE))
    picturebutton.bind("<Leave>", lambda event: picturebutton.configure(state=NORMAL))
    password = Label(window, text="Change password:", bg="white")
    password.grid(row=7, sticky=W, padx=150)
    passwordentry = Entry(window, width=30, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                          highlightthickness=1, show="*")
    passwordentry.grid(row=8, padx=150, ipady=2)
    password = Label(window, text="New password:", bg="white")
    password.grid(row=9, sticky=W, padx=150)
    passwordnewentry = Entry(window, width=30, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                             highlightthickness=1, show="*")
    passwordnewentry.grid(row=10, padx=150, ipady=2)
    password = Label(window, text="New password again:", bg="white")
    password.grid(row=11, sticky=W, padx=150)
    passwordnewentrycon = Entry(window, width=30, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                                highlightthickness=1, show="*")
    passwordnewentrycon.grid(row=12, padx=150, ipady=2)

    country = Label(window, text="Country:", bg="white")
    country.grid(row=13, sticky=W, padx=150)
    option = ttk.Combobox(window, textvariable=variable, state="readonly", values=["Czech Republic", "Slovakia"])
    option.grid(row=14, pady=5, ipady=2, ipadx=22)
    save = Button(window, text="Save", relief=FLAT, bd=0,
                  command=lambda: save_form(loginentry, emailentry, passwordentry, passwordnewentry,
                                            passwordnewentrycon), activebackground="grey80")
    save.grid(row=15, pady=5, ipady=2, ipadx=78)
    save.bind("<Enter>", lambda event: save.configure(state=ACTIVE))
    save.bind("<Leave>", lambda event: save.configure(state=NORMAL))
    window.bind('<Return>',
                lambda event: save_form(loginentry, emailentry, passwordentry, passwordnewentry, passwordnewentrycon))
    close = Button(window, text="Close", relief=FLAT, bd=0, command=window_close, activebackground="grey80")
    close.grid(row=16, ipady=2, ipadx=75)
    close.bind("<Enter>", lambda event: close.configure(state=ACTIVE))
    close.bind("<Leave>", lambda event: close.configure(state=NORMAL))
    credit = Label(window, text="Lukáš Moravec 2018", bg="white")
    credit.grid(row=17, sticky=W, padx=150, ipadx=35)

    window.protocol("WM_DELETE_WINDOW", window_close)


# Options END


def btnExit_on_mouse_down(event):
    btnExit.config(bg="orchid3")
    color = "orchid2"
    btnHome.config(bg=color)
    btnFavorite.config(bg=color)
    btnOption.config(bg=color)


def frameconfig(event):
    canvas.config(scrollregion=canvas.bbox("all"))


def canvasconfig(event):
    width = event.width - 4
    canvas.itemconfigure("scrollableFrame", width=width)
    scrollableFrame.config(width=event.width - 4)
    for i in range(20):
        user[i].config(width=event.width - 708)


def mousewheel(event):
    if scrollableFrame.winfo_height() >= 500:
        canvas.yview_scroll(int(-1 * (event.delta / 120)), "units")


def add_user_save(o, a, textn):
    if textn == "":
        messagebox.showinfo("Error", "Username entry is empty")
        return
    main.append(i)
    fav.append(i)
    icon.append(i)
    name.append(i)
    comment.append(i)
    user.append(i)
    msg.append(i)

    main[i] = Frame(scrollableFrame, highlightbackground="grey90", highlightcolor="grey90", highlightthickness=1,
                    height=60, width=20, bd=0)
    main[i].pack(side=TOP, fill=X, expand=1)
    icon[i] = Label(main[i], bg="white", image=imgUser, height=60, width=60, bd=0)
    icon[i].pack(side=LEFT)

    fav[i] = Button(main[i], bg="white", image=imgFav, width=25, relief=FLAT, bd=0, activebackground="white",
                    command=lambda o=i: fav_function(o))
    fav[i].pack(side=LEFT, fill=Y)
    name[i] = Label(main[i], bg="white", text=textn+": ", bd=0, width=10)
    name[i].pack(side=LEFT, fill=Y)

    comment[i] = Label(main[i], bg="white", width=70,
                       text="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Proin mattis lacinia justo. Pellentesque sapien. Maecenas lorem. Nulla est. Duis ante orci, molestie vitae vehicula venenatis, tincidunt ac pede.",
                       fg="grey", bd=0, wraplength=breakLine, anchor=W, justify=LEFT)
    comment[i].pack(side=LEFT, fill=BOTH, expand=1)
    user[i] = Frame(main[i], bg="white", height=60, width=20, bd=0)
    user[i].pack(side=LEFT, fill=X, expand=1)
    msg[i] = Button(main[i], bg="white", image=imgMsg, width=50, relief=FLAT, bd=0, activebackground=activeColor,
                    command=lambda o=i: message(o))
    msg[i].pack(side=LEFT, fill=Y)
    msg[i].bind("<Enter>", lambda event, o=i: msg[o].configure(bg="gray90"))
    msg[i].bind("<Leave>", lambda event, o=i: msg[o].configure(bg="white"))
    a.destroy()


def add_user(i):
    i +=1

    add = Toplevel(root)
    add.title("Add contact")
    add.config(bg="white")
    add.minsize(165, 50)
    add.resizable(True, False)
    add.grab_set()

    addtext = Label(add, text="Add contact:", bg="white")
    addtext.pack(side=TOP)
    addtext = Entry(add, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
    addtext.pack(side=TOP)
    addbtn = Button(add, text="Add contact", bd=0, activebackground=activeColor, command=lambda: add_user_save(i, add, addtext.get()))
    addbtn.pack(side=TOP, pady=5)
    addbtn.bind("<Enter>", lambda event: addbtn.configure(state=ACTIVE))
    addbtn.bind("<Leave>", lambda event: addbtn.configure(state=NORMAL))


def logint():
    if logPassE.get() == passwordText and logNameE.get() == loginText:
        login.destroy()
    else:
       messagebox.showinfo("Wrong", "Wrong password or username")


root = Tk()
root.minsize(850, 480)
root.config(bg="white")
root.title("URO project")
root.wm_iconbitmap('favicon.ico')

login = Toplevel(root)
login.title("Login")
login.grab_set()
login.minsize(200, 90)
login.config(bg="white")

logName = Label(login, text="Username:", bg="white")
logName.pack()
logNameE = Entry(login, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
logNameE.pack()
logPass = Label(login, text="Password:", bg="white")
logPass.pack()
logPassE = Entry(login, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
logPassE.pack()
submit = Button(login, command=logint, text="Login", bd=0, activebackground="grey90")
submit.pack(pady=10, ipady=5, ipadx=10)
submit.bind("<Enter>", lambda event: submit.configure(state=ACTIVE))
submit.bind("<Leave>", lambda event: submit.configure(state=NORMAL))

leftFrame = Frame(root, bg="orchid2", width=60)
leftFrame.pack(fill=Y, side=LEFT)

i = 20

imgHome = PhotoImage(file="home.png")
imgFavorite = PhotoImage(file="favorite.png")
imgOption = PhotoImage(file="option.png")
imgExit = PhotoImage(file="shutdown.png")
imgUser = PhotoImage(file="user.png")
imgMsg = PhotoImage(file="msg.png")
imgFav = PhotoImage(file="fav.png")
imgFavY = PhotoImage(file="favY.png")
imgpicture = PhotoImage(file="upload.png")
imgTrash = PhotoImage(file="trash.png")
imgTrashOn = PhotoImage(file="trashon.png")
imgEdit = PhotoImage(file="edit.png")
imgAdd = PhotoImage(file="useradd.png")
imgFunny = PhotoImage(file="funny.png")
imgOk = PhotoImage(file="ok.png")
imgAdmired = PhotoImage(file="admired.png")
activeColor = "orchid"

btnHome = Button(leftFrame, bg="orchid3", width=40, height=40, image=imgHome, border=0, activebackground=activeColor)
btnHome.pack(side=TOP)
colorHome = btnHome.cget('bg')
btnHome.bind("<Enter>", lambda event: btnHome.configure(state=ACTIVE))
btnHome.bind("<Leave>", lambda event: btnHome.configure(state=NORMAL))
btnHome.bind("<ButtonPress-1>", btnHome_on_mouse_down)

btnFavorite = Button(leftFrame, bg="orchid2", width=40, height=40, image=imgFavorite, border=0,
                     activebackground=activeColor)
btnFavorite.pack(side=TOP)
colorFavorite = btnFavorite.cget('bg')
btnFavorite.bind("<Enter>", lambda event: btnFavorite.configure(state=ACTIVE))
btnFavorite.bind("<Leave>", lambda event: btnFavorite.configure(state=NORMAL))
btnFavorite.bind("<ButtonPress-1>", btnFavorite_on_mouse_down)

btnAdd = Button(leftFrame, bg="orchid2", width=40, height=40, image=imgAdd, border=0, activebackground=activeColor, command=lambda: add_user(i))
btnAdd.pack(side=TOP)
btnAdd.bind("<Enter>", lambda event: btnAdd.configure(state=ACTIVE))
btnAdd.bind("<Leave>", lambda event: btnAdd.configure(state=NORMAL))

loginText = "LOki"
emailText = "moravec.czech@gmail.com"
variable = StringVar(root)
variable.set("Czech Republic")  # default value
passwordText = "LOLnope"
pictureText = 'C:/Users/morav/PycharmProjects/URO/user.png'

btnOption = Button(leftFrame, bg="orchid2", width=40, height=40, image=imgOption, border=0,
                   activebackground=activeColor)
btnOption.pack(side=TOP)
colorOption = btnOption.cget('bg')
btnOption.bind("<Enter>", lambda event: btnOption.configure(state=ACTIVE))
btnOption.bind("<Leave>", lambda event: btnOption.configure(state=NORMAL))
btnOption.bind("<ButtonPress-1>",
               lambda event: btnOption_on_mouse_down(loginText, emailText, passwordText, pictureText, variable))

btnExit = Button(leftFrame, bg="orchid2", width=40, height=40, image=imgExit, border=0, command=exit_function,
                 activebackground=activeColor)
btnExit.pack(side=BOTTOM, pady=11)
colorExit = btnExit.cget('bg')
btnExit.bind("<Enter>", lambda event: btnExit.configure(state=ACTIVE))
btnExit.bind("<Leave>", lambda event: btnExit.configure(state=NORMAL))
btnExit.bind("<ButtonPress-1>", btnExit_on_mouse_down)

rightFrame = Frame(root, height=100)
rightFrame.pack(fill=BOTH, expand=1, side=RIGHT)

searchBarFrame = Frame(rightFrame, bg="white")
searchBarFrame.pack(side=TOP, fill=X, ipady=5)
lol = Frame(searchBarFrame, width=12, bg="white")
lol.pack(side=LEFT)
searchBar = Entry(searchBarFrame, width=50, relief=FLAT, highlightbackground="grey90", highlightcolor="black",
                       highlightthickness=1)
searchBar.pack(side=LEFT, fill=Y, pady=5)
searchBtn = Button(searchBarFrame, text="Search", relief=FLAT, bg="orchid2", bd=0, activebackground=activeColor)
searchBtn.pack(side=LEFT, fill=Y, pady=5, ipadx=5)
searchBtn.bind("<Enter>", lambda event: searchBtn.configure(state=ACTIVE))
searchBtn.bind("<Leave>", lambda event: searchBtn.configure(state=NORMAL))

canvas = Canvas(rightFrame, bg="purple")
canvas.pack(side=LEFT, fill=BOTH, expand=1)

scrollbar = Scrollbar(rightFrame, orient="vertical", command=canvas.yview)
scrollbar.pack(side=LEFT, fill=Y)
canvas.config(yscrollcommand=scrollbar.set)

scrollableFrame = Frame(canvas, bg="purple")
scrollableFrame.pack(side=TOP, fill=BOTH, expand=1)
canvas.create_window((0, 0), window=scrollableFrame, anchor=N + W)

canvas.bind("<Configure>", canvasconfig)
canvas.bind_all("<MouseWheel>", mousewheel)
scrollableFrame.bind("<Configure>", frameconfig)

fav = []
main = []
icon = []
name = []
comment = []
user = []
msg = []
breakLine = 480
text = ["Martin: ", "Ondra: ", "Karel: ", "Tonda: "]
n = 0
for i in range(20):
    main.append(i)
    fav.append(i)
    icon.append(i)
    name.append(i)
    comment.append(i)
    user.append(i)
    msg.append(i)

    main[i] = Frame(scrollableFrame, highlightbackground="grey90", highlightcolor="grey90", highlightthickness=1,
                    height=60, width=20, bd=0)
    main[i].pack(side=TOP, fill=X, expand=1)
    icon[i] = Label(main[i], bg="white", image=imgUser, height=60, width=60, bd=0)
    icon[i].pack(side=LEFT)

    fav[i] = Button(main[i], bg="white", image=imgFav, width=25, relief=FLAT, bd=0, activebackground="white",
                    command=lambda o=i: fav_function(o))
    fav[i].pack(side=LEFT, fill=Y)

    if n > 3:
        n = 0

    name[i] = Label(main[i], bg="white", text=text[n], bd=0, width=10)
    name[i].pack(side=LEFT, fill=Y)
    n += 1

    comment[i] = Label(main[i], bg="white", width=70,
                       text="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Proin mattis lacinia justo. Pellentesque sapien. Maecenas lorem. Nulla est. Duis ante orci, molestie vitae vehicula venenatis, tincidunt ac pede.",
                       fg="grey", bd=0, wraplength=breakLine, anchor=W, justify=LEFT)
    comment[i].pack(side=LEFT, fill=BOTH, expand=1)
    user[i] = Frame(main[i], bg="white", height=60, width=20, bd=0)
    user[i].pack(side=LEFT, fill=X, expand=1)
    msg[i] = Button(main[i], bg="white", image=imgMsg, width=50, relief=FLAT, bd=0, activebackground=activeColor,
                    command=lambda o=i: message(o))
    msg[i].pack(side=LEFT, fill=Y)
    msg[i].bind("<Enter>", lambda event, o=i: msg[o].configure(bg="gray90"))
    msg[i].bind("<Leave>", lambda event, o=i: msg[o].configure(bg="white"))

# root.protocol("WM_DELETE_WINDOW", exit_function)
root.mainloop()
