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
from flask import render_template

app = Flask(__name__)

@app.route('/')
def index():
    return render_template("./www/page/index.html")

if __name__ == "__main__":
    app.run(host='0.0.0.0')
