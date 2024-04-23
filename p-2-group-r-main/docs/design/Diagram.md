classDiagram
    GameManager -- RoomManager
    class GameManager {
        - roomManager : RoomManager
        + startGame() 
        + endGame() 
        + processPlayerInput(input: string) 
    }

    Player o-- Inventory
    class Player {
        - name: string
        - inventory: Inventory
        + getName() string
        + getInventory() Inventory
        + setName(name: string) 
    }

    RoomManager -- Room
    RoomManager -- Player
    RoomManager -- Item
    class RoomManager {
        - rooms: Room[]
        - items: Item[] //Shared_ptr
        - timeMachine : TimeMachineRoom
        - player : Player
        - currentRoom : Room*
        + getDescription() string
        + toggleLocation()
        + handleAction(action : string)
    }


    Room o-- Inventory
    Room --> Action : Allows
    Room *-- RoomState
    class Room {
        <<Abstract>>
        - name: string
        - state: RoomState
        - inventory: Inventory
        - actions : actions[]
        + doAction(input : string)
        + getName() string
        + getDescription() string
        + getItems() Item[]
        + doAction(action : string)
        ~ Room()
    }

    class RoomState {
        <<Abstract>>
        - description : string
        - maskDescription : string
        - interactions : Interaction[]
        + generateDescription() string
        ~RoomState()
    }

    RoomState -- Interaction
    class Interaction {
        - notCompletedText : string
        - completedText : string
        - name : string
        - value : bool
        + checkCompleted()
        + markCompleted()
    }

    Room <|-- NpcRoom
    class NpcRoom {
        - npc: NPC
    }

    Room <|-- PuzzleRoom
    class PuzzleRoom {
        - puzzleDescription : string
        - correctAnswer : string
        - failText : string
        - doPuzzle()
        + doAction(action : string)
    }

    Room <|-- TimeMachineRoom
    class TimeMachineRoom {
        - powerLevel : int
        + forwardTime()
        + reverseTime()
        + doAction(action : string)
    }

    NpcRoom o-- NPC
    class NPC {
        - name: string
        + getName() string
    }

    class Item {
        - name: string
        - description: string
        + getName() string
        + getDescription() string
    }

    Inventory --> Item : Contains
    class Inventory {
        - items: Item[]
        + addItem(item: Item) 
        + removeItem(item: Item) 
        + getItems() Item[]
        + printInventory() 
    }

    class Action {
        <<Abstract>>
        - name: string
        - result: string
        - failed : string
        - requirement : Interaction
        - interaction : Interaction
        + getName() string
        + execute() 
    }

    Action <|-- Look
    class Look {
        + execute() 
    }

    Action <|-- Pickup
    class Pickup {
        - item: Item
        + execute() 
    }

    Action <|-- Use
    class Use {
        - singleUse: bool
        - item: Item*
        + execute() 
    }

    Action <|-- talk
    class talk {
        - npc : NPC
        + execute()
    }
