from gui import Root, SettingsPage


def render_train_settings(
    root: Root,
    *,
    render_landing: callable,
    render_game_mode: callable,
    render_train_mode: callable,
):
    root.frames["settings"] = SettingsPage(
        root,
        {
            "handle_go_back": lambda: [
                root.destroy_frame("settings"),
                render_landing(
                    root,
                    render_game_mode=render_game_mode,
                    render_train_settings=render_train_settings,
                    render_train_mode=render_train_mode,
                ),
            ],
        },
    )
    root.frames["settings"].pack(fill="both", expand=True)
