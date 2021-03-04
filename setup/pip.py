"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: description

pip.py (c) 2021
Created:  2021-03-04T20:31:56.992Z
"""

import subprocess

try:
    result = subprocess.run("sudo apt-get install python3-pip",stdout=subprocess.PIPE,shell=True)
except BaseException as ex:
    print("Erreur installation pip" + repr(ex))
else:
    print("Installation pip réussie")
