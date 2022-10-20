Software Development II - Course Project
The project source-code is found in the game-source-code file.
The project test code is found in the test-source-code file. 
The execution files are provided in a zip file attatched to the release. 

The Game Consists of:
A splash screen with instructions on how to play.
A game object (Frostbite) that moves across the screen.
Two enemy objects that move across the screen.
Collisions on either side of the screen are dealt with to prevent Frostbite from moving off the screen.
Iceberg objects that move across the screen.
A safe zone for Frostbite.
An Igloo that is built when Frostbite lands on an Iceberg.
Life, level and score counter.
The temperature decreases per second, starting at 45.
Frostbite can change the row direction.

Game:
If Frostbite lands on the iceberg he will move with it.
If Frostbite hits an enemy, he will respawn and lose a life
If he lands in the water he will respawn and lose a life.
If Frostbite is swept to the side of the screen, he will not be able to move and eventually fall off the Iceberg.
If the temperature reaches 0 degrees, a message screen will be displayed and a life is lost.
If the player runs out of lives, the player will lose. A message screen will be displayed and prompt to restart.
The igloo will finish building if the player lands on 16 new icebergs.
If the player is on the safe zone, he can enter the iceberg to win (only when in line with entrance).
The player can change the directioon of their current Iceberg row at the cost of one Igloo block.

Testing:
Movement of Frostbite.
Movement of Icerows.
Movement of Enemyrows.
Movement of IceSystem.
Moevement of EnemySystem
Screen Collisions and limitations.
Overlapping of objects.
Basic functionality of temperature.
Temperature resetting.
Score functionality.
Igloo building.
Collisions with Enemies
Collisions with Icebergs
