Here i have various issues to implement

Potions
- Mana Potions
- Health Potions

NPCs
- Quest
- non Quest

Quests
- types ?

Magic
- healing ?
- Mana ?
- AoE ?
- stuns ?
- special ?
- books to learn ?
- learning chance ?
- spell level ?

Items
- magic items ?

Character 
- stats like strength dex or smth?
  -> necessary or keep it simple ?
- MANA !

Trigger
- Traps ?
- open ways ?
- quest triggers ?
- when all or specific enemies are dead ?
- triggers to other places ?
  > door open.. ect..
- triggers that spawn enemies in the place ?
-> ghost out of chest e.g
-> enemies come in after you pulled a trigger for a door in another place.. e.g

New Ways (not only directions to go)
- doors ?
- gates ?
- maybe special "Way" - Class
- Should directions like north and south also be a way class ?
- Better one vector with all ways possible then just 4 integers for each direction !!
-> So endless possible ways !!
- here the map command also needs a huge update then
-> Inspect command will then need a certain text (maybe string in way object)
  -> e.g a Way door_place_1, description: a door that leads to the next room or smth

Combat
- get rid of speed or let it do something ?
- like D & D !
 -> better random values !




Map Command
- ASCII artwork ? maybe for each place ?
- Show enemies Yes or No ? and when yes.. how ?
- show name of place in the middle !
- Maybe the map how it is now will be only a minimap command
-> maybe a "world map ?"
  -> Map of all places near yours

Userfriendliness
- is help command good enough ?
- maybe help with parameters
 > to help with specific issues
- Maybe the "Open" - Command should be named "Examine" or something like this
- make an endl after each command ! like attack 

Code Specific
- More inheritance !!
- Items 
  > Equipment
  > Usables
- Exceptions !!!!!!!!!!!!!!!!!!!!!
-> catch bad alloc and bad cast !
  -> most important
-> Validate Error method in game needed !
-> Test everything in valgrind
  -> delete method to delete EVERYTHING in heap

 ~invent good story~

Bugs:
take something NUMBER -> you have to open smth
> should be "you cant do that"
> when you have no potions there should be: you have no potions
> a Container is empty when only no weapons are not in it !!!
  > has to check for usables too !