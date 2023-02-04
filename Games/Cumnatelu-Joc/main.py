from ui import UI
from gui import GUI
from domain import Board
from settings import Settings
try:
    Settings().valid()
    for _ in range(500):
        Board.random_ships()  # Checking for impossibilities regarding ship placements
    if Settings().ui() == "ui":
        UI().start()
    else:
        GUI().start()
except Exception as e:
    print(e)
