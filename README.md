# TL_Project_Week6

## Viikon 6 tavoite (arvosana max 3)
Toteuta K-means-luokittelija-algoritmi, joka mittaa kiihtyvyysanturilla **x, y, z -arvot** ja laskee tämän 3D-pisteen etäisyyden kaikkiin kuuteen keskipisteeseen, jotka opetettiin Pythonilla edellisellä viikolla.  
Keskipisteet tuodaan ohjelmaan `keskipisteet.h`-tiedostona.


## K-means-luokittelijan toteutus NRF5340DK-alustalla

### Vaiheet
1. Kloonaa GitHub-repositorio:  
   🔗 [https://github.com/kajyrkka/TL_Project_Week6](https://github.com/kajyrkka/TL_Project_Week6)
2. Käännä repositoryn mukana tullut NRF5340DK-ohjelma ja **selvitä annetun koodin toiminta**.  
3. Täydennä `confusion.c`-tiedoston puuttuvat aliohjelmat siten, että voit syntyneen ohjelman avulla:
    1) valita suuntamuuttujalle arvon 0,1,2,3,4,5 (=valittuSuunta)
    2) tehdä 100 kpl mittauksia kiihtyvyysanturista
    3) tehdä jokaiselle mitatulle kiihtyvyysanturitulokselle suuntaluokittelun 0,1,2,3,4,5 (=tunnistettuSuunta)
    4) tallettaa jokainen luokittelu taulukkoon confMatrix[valittuSuunta,tunnistettuSuunta] = confMatrix[valittuSuunta,tunnistettuSuunta] + 1
4. Suorita mittaukset omalla NRF5340DK-laitteellasi ja kiihtyvyysanturilla (sama anturi kuin viikoilla 2 ja 5).  
   Tee **noin 100 mittausta jokaiseen 6 suuntaan**.  
5. Tulosta syntynyt confusion matrix tieto sarjaportin kautta PC
6. Tee PC:llä Python ohjelma, joka lukee sarjaportin confusion matrix tiedon ja piirtää siitä kuvan.
7. Lisää confusion matrix kuva oman Github-repositoriosi Readme.md tiedostoon.
   

## Viikon 6 – lisätavoite (arvosanat max 4-5)

### CNN:n toteutus NRF5340DK-mikrokontrollerissa

Tässä lisätehtävässä toteutetaan aiemmin opetettu konvoluutioneuroverkko (CNN) **C-kielellä** Nordic Semiconductorin NRF5340DK-alustalle.


### Vaihe 1 – Muistin ja suoritusajan analyysi
Laadi **Excel-dokumentti**, jossa arvioit opettamasi CNN-mallin:
- Muistin tarpeen (parametrit, aktivointien määrä)
- Suoritusajan (arvio mikrokontrollerilla)


### Vaihe 2 – CNN:n toteutus Pythonilla (testidatan generointi)
Toteuta opettamasi CNN Pythonilla kerros kerrokselta (samaa tyyliä kuin "Koneoppimisen perusteet" -projektissa).  
Toteuta Colabissa Python ohjelma, joka tekee seuraavat tehtävät:

1. Luetaan viikolla 5 opetettu malli sisään (model_export.keras)
2. Valitaan mallista haluttu mallin kerros (layer), josta tulostetaan kahteen tiedostoon seuraavat tiedot:
    - **`input.h`** → sisältää testattavan kerroksen syötteen = input tähän kerroksen ja mallin tämän kerroksen parametrit  
    - **`output.h`** → sisältää testattavan kerroksen oikean output tuloksen  

Näitä tiedostoja käytetään C-kielisessä toteutuksessa tulosten vertailuun.  


### Vaihe 3 – CNN:n toteutus C-kielellä
Toteuta CNN-mallisi **C-kielellä**, kerros kerrokselta, alkaen luokittelukerroksista.  

Tee jokaisesta kerroksesta aliohjelma, jolle:
- Syötetään `input.h`-tiedoston data  
- Verrataan tulosta `output.h`-tiedoston oikeaan arvoon  

Tämä varmistaa, että C-toteutuksen laskenta vastaa Python-mallin tuloksia.

### Vaihe 4 
Toista vaiheita 2 ja 3 niin pitkälle kuin ehdit, kaikkia kerroksia ei tarvitse saada toteutettua hyväksyttyyn lisätehtävään.


