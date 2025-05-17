from gui import Root
from loop import (
    render_game_mode,
    render_landing,
    render_train_mode,
    render_train_settings,
)


def main():

    root = Root()

    render_landing(
        root,
        render_game_mode=render_game_mode,
        render_train_settings=render_train_settings,
        render_train_mode=render_train_mode,
    )

    root.mainloop()


if __name__ == "__main__":
    main()
