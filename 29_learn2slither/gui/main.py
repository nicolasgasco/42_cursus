import tkinter as tk


def main():
    root = tk.Tk()
    root.title("Learn2Slither")

    # Create a 10x10 grid of squares
    for i in range(10):
        for j in range(10):
            square = tk.Canvas(root, width=20, height=20)
            square.grid(row=i, column=j)

    root.mainloop()


if __name__ == "__main__":
    main()
