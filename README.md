# CSCI2270 Final Project: Tournament of the Gods

## Project Summary
Our project is a mythologial tournament that utilizes binary trees. There is a set list of Gods, with different attributes, that will fight in a tournament. The player has the option of fighting in the tournament, or watching it from the audience. If the player decides to play, then they can pick a preset God to play as, or they can create their own. They will then be able to choose the moves for their God or 'champion', and will have control over their champion until they die. After the player's champion dies, the rest of the tournament will be played automatically.

After each round, a new level of a tree will be created. This tree will be created from the bottom up. At the end of the tournament we will be able to traverse the tree and see the result of each fight.

####How to win
Based on your champion's stats and attribute, its abilities will change. During each round, two Gods will fight until one's health drops below zero. The God left standing will move on to play another winner, until there is only one god left. If the player chooses to play as a premade God, the stats and attribute will already be determined. If the player creates their own God, they will be able to choose their attribute, as well as their dominant and inferior stats (health, attack, or agility). In both cases, a random modifier will be applied to their stats so each tournament will be unique.

####Attributes
Each God is assigned an attribute (normal, fire, water, earth, or lightning). If the player chooses to create a God, then they get to choose their God's attribute. 

  Normal - no advantage or disadvantage against any God.
  
  Fire - gives an advantage when playing against an Earth God, but a disadvantage against a Water God.
  
  Water - gives an advantage when playing against a Fire God, but a disadvantage against a Lightning God.
  
  Earth - gives an advantage when playing against a Lightning God, but a disadvantage against a Fire God.
  
  Lightning - gives an advantage when playing against a Water God, but a disadvantage against an Earth God.

## How to Run
With Tournament.cpp, Tournament.h, and main.cpp in a project together, with gods.txt in the same directory, main.cpp can be run to start the start the game. 

## Dependencies 
This program has no third-party dependencies.

## System Requirements
This program will run with Windows, Mac, or Linux operating systems, but requires the use of C++11 or higher.

## Group Members
Lauren Raddatz and Mehdi Zarekani

## Contributors
None

## Open issues/bugs
None that we are aware of.
