# 🏟️ Sistema IoT de Control Ambiental i Aforament per a Complex Esportiu

[![Placa - ESP32](https://img.shields.io/badge/Placa-ESP32-blue.svg)](https://espressif.com/)

## 📝 1. Descripció del Projecte

Aquest projecte consisteix en el disseny, desenvolupament i implementació d'un sistema automatitzat basat en l'**Internet de les Coses (IoT)** per gestionar la seguretat i el confort dins de les sales d'un complex esportiu. 

L'alta activitat física augmenta l'expulsió de CO₂ i la humitat ambient. Si la ventilació és deficient, disminueix el rendiment i augmenten els riscos respiratoris. Mitjançant una placa central **ESP32**, aquest sistema monitoritza constantment la qualitat de l'aire i l'aforament de l'espai en temps real, oferint un panell de control accessible des de qualsevol dispositiu connectat a la xarxa local.

---

## 🚀 2. Característiques Principals

* **Monitorització Ambiental Automatitzada:** Mesura continuada dels indicadors de qualitat de l'aire de la sala esportiva.
* **Control d'Aforament Dinàmic:** Comptatge automàtic per evitar aglomeracions i garantir el compliment de les normatives legals de seguretat.
* **Servidor Web Integrat (HTTP):** L'ESP32 actua com a propi servidor, allotjant un panell de control (Dashboard) sense dependre de serveis de pagament externs.
* **Refresc Automàtic en Temps Real:** Injecció estructural d'auto-refresh cada 2 segons directament via protocols web.
* **Codi de Colors Assistit per a Alertes:** Interfície dinàmica que canvia instantàniament a color vermell en cas de superar els llindars crítics establerts.

---

## 📂 3. Estructura del Repositori

El repositori s'organitza seguint els estàndards de desenvolupament de programari:


projecte_iot/
 ├── README.md               # Documentació principal i guia del projecte
 ├── src/
 │    └── projecte_final.ino # Codi font complet per a l'ESP32 (C++)
 └── doc/
      ├── document_tecnic.md # Memòria tècnica (Objectius, Proves i Resultats)
      └── incidencies.md     # Registre i justificació tècnica d'errors solucionats
