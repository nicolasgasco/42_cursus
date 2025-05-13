# Learn2Slither

> A snake that learns how to behave in an environment through trial and error.

> This project is an artificial intelligence project about reinforcement learning.

## Execution

### Start project

The project is using rye to handle dependencies

```shell
$ source .venv/bin/activate
$ (env) rye sync
```

### Map generation

Generate a new map:

```shell
cd src/
python3 generate_map.py

```

Map can be configured in `settings/map.json`:

```json
{
  "file_name": "2025-05-09_W10_H10_map", # The map file expected by the training script
  "green_apples": 2, # Number of green apples (+1 length)
  "height": 12, # Height of map
  "randomized": true, # If true, object are spawned randomly
  "red_apples": 1, # Number of red apples
  "snake_length": 3, # Initial length of snake
  "width": 12, # Width of map
  "victory_length": 10 # Snake length to win a game
}
```

### Training

Start a fully automated training round:

```shell
cd src/
python3 loop.py
```

Training can be configured in `settings/train.json`:

```json
{
  "max_episodes": 200000 # The maximum number of training rounds
}
```

### Try out the game

If you want to play as if you were the agent:

```shell
cd src/
python3 loop.py --play
```
