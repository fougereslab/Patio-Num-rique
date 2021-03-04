"""
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: description

server.py (c) 2021
Created:  2021-03-04T22:30:10.014Z
"""

from flask import Flask
app = Flask(__name__)

@app.route('/')
def test():
    return "Hello world"

if __name__ == "__main__":
    app.run()
