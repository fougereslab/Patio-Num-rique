
Author: Mickaël Descamps - Mineyou
Email : mickael.descamps@mineyou.fr
Projet : Patio numérique
Organisation : FougèresLab
Desc: description

setup.sh (c) 2021
Created:  2021-02-24T20:11:07.557Z


echo "[First step]  make setup file executable"
sudo chmod +x ./python/setup.sh
sudo chmod +x ./git/setup.sh
echo "[Second step]   launch setup file"
sudo bash ./python/setup.sh
sudo bash ./git/setup.sh
sudo bash ./mqtt.sh
sudo bash ./pip.sh
sudo python3 ./mongoDbSetup/setup.py