"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: MongoDb setup script

setup.py (c) 2021
Created:  2021-01-23T11:08:12.059Z
Modified: 2021-01-30T11:01:51.464Z
"""

import os


#TODO : Mongodb Installation
print("Démarrage installation Mongodb ...")
os.system("wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | sudo apt-key add -")
print("Fin de récupération de la clé publiquer")
os.system("echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.4.list")
print("Fin de la création de la liste pour mongodb")
os.system("sudo apt-get update")
print("Rechargement package de la base de données")
os.system("sudo apt-get install -y mongodb-org")
print("Fin installation MongoDb")
os.system("sudo systemctl start mongod")
print("Fin de démarrage de MongoDB")
os.system("sudo systemctl status mongod") #TODO check if mongodb has start
print("MongoDB a démarré ")


