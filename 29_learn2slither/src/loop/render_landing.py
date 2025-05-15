from gui import LandingPage


def render_landing(root, render_game_mode: callable):
    root.frames["landing"] = LandingPage(root)
    root.frames["landing"].pack(fill="both", expand=True)

    root.frames["landing"].play_button.config(
        command=lambda: [
            root.destroy_frame("landing"),
            render_game_mode(root, render_landing),
        ]
    )
