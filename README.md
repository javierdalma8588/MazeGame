# MazeGame
Maze Game Developer on Unreal Engine 4.22.3 using c++ by Javier Dalma
This code was wrote to develop a maze game where the user moves aroud collecting keys to open doors. The maze contains traps so the player should be careful where he walks. There are also checkpoints so if the player dies it can respawn further on the level.

Checkpoint Script: this scripts handles the checkpoints when the user collides with this object it will set the new spawn position and move the checkpoint down.

Door Script: check when the player collides with the door and if the player has a key to open it. If the player has a key the door disappear.

DoorKey Script:check when the player collides with the key and if the player then it adds a key to the player

Objective to Pick Script: this script access to the current gamemode and check how many objectives has the player completed

PlayerBase: controls every aspect of the player like the controlls, speed, amount of keys, etc

Practica1GameModeBase Script: handles if the player has completed the objective and sends him to a new scene

Vertical Trap Script: handles the trap movement up and down after a certain time, also damages the player on touch

More comments about the code and how it works are on every .cpp and .h files
