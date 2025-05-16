from gui import Root, SettingsPage


def render_train_settings(root: Root):
    root.frames["settings"] = SettingsPage(root)
    root.frames["settings"].pack(fill="both", expand=True)
