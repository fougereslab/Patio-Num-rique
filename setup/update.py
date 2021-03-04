"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: description

update.py (c) 2021
Created:  2021-03-04T21:27:19.374Z
"""

import subprocess
import sys

try:
    result = subprocess.run("sudo git fetch",stdout=subprocess.PIPE,shell=True)
except BaseException as ex:
    print("Erreur lors de la mise à jour")
else:
    if(result.returncode == 0):
        print("Succès de la mise à jour")