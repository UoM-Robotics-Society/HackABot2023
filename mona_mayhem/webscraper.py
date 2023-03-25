
#webscraping
import math
import requests

#command line args
import sys

#visulaization
from tkinter import *

#window
window=Tk()
window.title('Fusbol')

local_server = "http://localhost:8080"
main_server = "http://192.168.4.1"

while True:
    if sys.argv[1] == "main":
        response = requests.get(main_server)
        html_content = response.text
        data = [x.strip().split(',') for x in html_content.split("<br>")[2:-1]]
    else:
        response = requests.get(local_server)
        html_content = response.text
        data = [x.strip().split(',') for x in html_content.split("<br>")[1:-1]]

    locations = {}
    for x in data:
        locations[x[0]] = [float(i) for i in x[1:]]

    print(locations)

    # window.geometry("1500x1000")

    # #Create a canvas object
    # c = Canvas(window,width=1500,height=1000)

    # boundry = 200
    # x_off = locations['C0'][0] - boundry
    # y_off = locations['C0'][1] - boundry
    # scale = 0.5

    # for k in locations:
    #     locations[k] = [(locations[k][0]-x_off)*scale, (locations[k][1]-y_off)*scale, locations[k][2]]

    # c.create_rectangle(locations["C0"][0],locations["C0"][1],locations["C1"][0],locations["C1"][1],outline = "black",fill = "green",width = 1)

    # print(locations)

r = 20
#Draw an Oval in the canvas
for i in range(len(locations.values())):
    l = list(locations.values())[i]
    k = list(locations.keys())[i]
    c.create_oval(l[0]-r, l[1]-r, l[0]+r, l[1]+r, outline = "black",fill = "black",width = 2)
    c.create_text(l[0], l[1], text=k, fill="white", font=('Helvetica 15 bold'))
    print(l[0], l[1], l[0]+math.cos(l[2]), l[1]+math.sin(l[2]))
    c.create_line(l[0], l[1], l[0]+math.cos(l[2])*50, l[1]+math.sin(l[2])*50, fill='red')
    c.pack()

window.mainloop()
