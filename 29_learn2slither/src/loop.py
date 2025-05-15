from gui import Root
from loop import render_game_mode, render_landing


def main():

    root = Root()

    render_landing(root, render_game_mode)

    root.mainloop()


if __name__ == "__main__":
    main()
