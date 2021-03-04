"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: MongoDb setup script

setup.py (c) 2021
Created:  2021-01-23T11:08:12.059Z
Modified: 2021-03-04T21:22:10.590Z
"""

import os


#TODO : Mongodb Installation
print("Démarrage installation Mongodb ...")
try:
    os.system("wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | sudo apt-key add -")
except BaseException as ex:
    print("Erreur : "+ repr(ex))
finally:
    print("Fin de récupération de la clé publique")
    try:
       os.system("echo \"deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse\" | sudo tee /etc/apt/sources.list.d/mongodb-org-4.4.list")
    except BaseException as ex:
        print("Erreur : " + repr(ex))
    finally:
        print("Fin de la création de la liste pour mongodb")
        try:
            os.system("sudo apt-get update")
        except BaseException as ex:
            print("Erreur : " + repr(ex))
        finally:
            print("Rechargement package de la base de données")
            try:
                os.system("sudo apt-get install -y mongodb-org")
            except BaseException as ex:
                print("Erreur : " + repr(ex))
            finally:
                print("Fin installation MongoDb")
                try:
                    os.system("sudo systemctl start mongod")
                except BaseException as ex:
                    print("Erreur : " + repr(ex))
                finally:
                    print("Fin de démarrage de MongoDB")
                    try:
                        os.system("sudo systemctl status mongod") #TODO check if mongodb has start
                    except BaseException as ex:
                        print("Erreur : " + repr(ex))
                    finally:
                        print("MongoDB a démarré ")
                        os.system("sudo systemctl enable mongod")
                        print("Démarrage de MongoDB automatique activé")


