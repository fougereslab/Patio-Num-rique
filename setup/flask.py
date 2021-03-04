"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: description

flask.py (c) 2021
Created:  2021-03-04T20:12:19.274Z
"""

import subprocess
import sys

try:
    result = subprocess.run("pip3 install flask",stdout=subprocess.PIPE,shell=True)

except BaseException as ex:
    raise BaseException("Erreur installation flask" + repr(ex)) from ex
else:
    if(result.returncode == 0):
        print("\t\t Installation de flask réussi")
