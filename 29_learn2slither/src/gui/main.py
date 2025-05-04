import tkinter as tk
from MapBlock import MapBlock

def main():
    root = tk.Tk()
    root.title("Learn2Slither")
    root.configure(bg="black")

    # Create a 10x10 grid of squares
    for i in range(10):
        for j in range(10):
            square = MapBlock({
                "block": "HEAD"
            })
            square.grid(row=i, column=j)

    root.mainloop()


if __name__ == "__main__":
    main()
