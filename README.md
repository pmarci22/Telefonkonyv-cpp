# Telefonkönyv Alkalmazás

Tervezzen meg egy egyszerűsített objektummodellt egy telefonkönyv alkalmazáshoz, majd valósítsa azt meg! A telefonkönyvben kezdetben az alábbi adatokat akarjuk tárolni, de később bővíteni akarunk:

- Név (vezetéknév, keresztnév)
- Becenév
- Cím
- Munkahelyi telefonszám
- Magán telefonszám

Az alkalmazással legalább a következő műveleteket kívánjuk elvégezni:

- Adatok felvétele
- Adatok törlése
- Adatok listázása

A rendszer lehet bővebb funkcionalitású (pl. módosítás, keresés), ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét. Demonstrálja a működést külön modulként fordított tesztprogrammal! A megoldáshoz ne használjon STL tárolót!

# Phonebook Application

Design a simplified object model for a phonebook application, then implement it! Initially, in the phonebook, we want to store the following data, but we aim to expand it later:

- Name (last name, first name)
- Nickname
- Address
- Work phone number
- Private phone number

With the application, we intend to perform at least the following operations:

- Add data
- Delete data
- List data

The system could have more extensive functionality (e.g., modification, search), so it is crucial to define the objects and their responsibilities well. Demonstrate the operation with a separate test program compiled as a module! Please refrain from using STL containers for the solution.

# Használat (Building Instructions)

## Szükséges Szoftverek (Softwares needed)
A projekt futtatásához a következő szoftverekre van szükség:

- C++ compiler / C++ fordító: A project forráskódjának fordításához.
- make: Az építési folyamat automatizálásához.

Kövesd a következő lépéseket: / To build the project, follow these steps:

1. Klónozd a repositoryt / Clone the repository.
2. Navigálj a projekt mappájába / Navigate to the project directory.
3. Futtasd a make parancsot a projekt buildeléséhez / Run make to build the project.
4. Indítsd el a .exe fájlt! / Run the .exe file!

```bash
git clone github.com/pmarci22/Telefonkonyv-cpp
```
```bash
cd Telefonkonyv-cpp
```
```bash
make
```
```bash
./telefonkonyv
```
## License

This project is licensed under the terms of the MIT license. See the LICENSE file for details.

Ez a projekt a MIT licenc feltételei alapján van licenszelve. További részletekért tekintsd meg a LICENSE fájlt.
