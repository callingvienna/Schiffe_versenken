//  Created by Christian Kersjes on 18.04.12.
//  Copyright (c) 2012 __Kersjes__. All rights reserved.
//

/*
 - Position der Schiffe manuell festlegen
 - Anschließend kann durch Angabe der Koordinaten auf ein Feld geschossen
 werden.
 - Meldungen ("Wasser", "Treffer", "Versenkt", "die gesamte Flotte ist
 vernichtet")
 
 
 Regeln:
 10×10 Kästchen
 - An den Seiten A bis J
 - Oben A bis J
 Zehn Schiffe
 - ein Schlachtschiff (5 Kästchen)
 - zwei Kreuzer (je 4 Kästchen)
 - drei Zerstörer (je 3 Kästchen)
 - vier U-Boote (je 2 Kästchen)
 Schiffe dürfen nicht aneinander stoßen
 Eingabe Schuss
 - Koordinate
 - z. B. Cj
 Da nur ein Spieler, darf hinter einander weg geschossen werden.
 
 Es wird von einer korrekten Eingabe ausgegangen und dem entsprechend werden
 keine Userangaben abgefangen.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>


using namespace std;


// Prototype der Funktionen
// notwendig, da ich zur besseren Übersicht, die Funktionen unter der main()
// erstellen will.

void tutorium(char spielfeld_schiff[11][11]);

void spielfeldErstellen(char spielfeld_schiff[11][11]);

void schiffeEintragen(char spielfeld_schiff[11][11], char start_x, char start_y, char ende_x, int kaestchen, int schiff);

int schussAuswerten(char spielfeld_schiff[11][11], char spielfeld_user[11][11], char schuss_x, char schuss_y, int schiffgroesse[10], int schiffcounter);

void spielfeldAusgabe(char spielfeld_schiff[11][11]);



int main()
{
    char schlachtschiff_start[4];
    char schlachtschiff_ende[4];
    
    char kreuzer1_start[4];
    char kreuzer2_start[4];
    char kreuzer1_ende[4];
    char kreuzer2_ende[4];
    
    char zerstoerer1_start[4];
    char zerstoerer2_start[4];
    char zerstoerer3_start[4];
    char zerstoerer1_ende[4];
    char zerstoerer2_ende[4];
    char zerstoerer3_ende[4];
    
    char uboot1_start[4];
    char uboot2_start[4];
    char uboot3_start[4];
    char uboot4_start[4];
    char uboot1_ende[4];
    char uboot2_ende[4];
    char uboot3_ende[4];
    char uboot4_ende[4];
    
    int kaestchen=0;
    
    char spielfeld_schiff[11][11];
    
    char spielfeld_user[11][11];
    
    spielfeld_user[0][0] = ' ';
    
    spielfeld_schiff[0][0] = ' ';
    
    char schuss[4];
    
    int schiff=0;
    
    int schiffgroesse[10];
    
    int schiffcounter = 10;
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Erstellung des spielfeld_schiff-------------------------
    // -----------------------------------------------------------------------------
    
    spielfeldErstellen(spielfeld_schiff);
    
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Erstellung des spielfeld_user---------------------------
    // -----------------------------------------------------------------------------
    
    spielfeldErstellen(spielfeld_user);
    
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Tutorium------------------------------------------------
    // -----------------------------------------------------------------------------
    
    tutorium(spielfeld_schiff);
    
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Flotteneingabe------------------------------------------
    // -----------------------------------------------------------------------------
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Schlachtschiff------------------------------------------
    
    cout << "Das Schlachtschiff belegt 5 Kaestchen." << endl;
    
    kaestchen = 5;
    
    
    cout << "Geben Sie die Startkoordinate für das Schlachtschiff ein: " << endl;
    
    cin.getline(schlachtschiff_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für das Schlachtschiff ein: " << endl;
    
    cin.getline(schlachtschiff_ende, 3);
    
    schiff = 1;
    schiffgroesse[1] = 5;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, schlachtschiff_start[0], schlachtschiff_start[1], schlachtschiff_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Kreuzer-------------------------------------------------
    
    cout << "Der Kreuzer belegt 4 Kaestchen." << endl;
    
    kaestchen = 4;
    
    
    cout << "Geben Sie die Startkoordinate für den Kreuzer 1 ein: " << endl;
    
    cin.getline(kreuzer1_start, 3);
    
    
    
    cout << "Geben Sie die Endkoordinate für den Kreuzer 1 ein: " << endl;
    
    cin.getline(kreuzer1_ende, 3);
    
    schiff = 2;
    
    schiffgroesse[2] = 4;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, kreuzer1_start[0], kreuzer1_start[1], kreuzer1_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für den Kreuzer 2 ein: " << endl;
    
    cin.getline(kreuzer2_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für den Kreuzer 2 ein: " << endl;
    
    cin.getline(kreuzer2_ende, 3);
    
    schiff = 3;
    
    schiffgroesse[3] = 4;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, kreuzer2_start[0], kreuzer2_start[1], kreuzer2_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Zerstoerer----------------------------------------------
    
    cout << "Der Zerstoerer belegt 3 Kaestchen." << endl;
    
    kaestchen = 3;
    
    cout << "Geben Sie die Startkoordinate für den Zerstoerer 1 ein: " << endl;
    
    cin.getline(zerstoerer1_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für den Zerstoerer 1 ein: " << endl;
    
    cin.getline(zerstoerer1_ende, 3);
    
    schiff = 4;
    
    schiffgroesse[4] = 3;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, zerstoerer1_start[0], zerstoerer1_start[1], zerstoerer1_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für den Zerstoerer 2 ein: " << endl;
    
    cin.getline(zerstoerer2_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für den Zerstoerer 2 ein: " << endl;
    
    cin.getline(zerstoerer2_ende, 3);
    
    schiff = 5;
    
    schiffgroesse[5] = 3;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, zerstoerer2_start[0], zerstoerer2_start[1], zerstoerer2_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für den Zerstoerer 3 ein: " << endl;
    
    cin.getline(zerstoerer3_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für den Zerstoerer 3 ein: " << endl;
    
    cin.getline(zerstoerer3_ende, 3);
    
    schiff = 6;
    
    schiffgroesse[6] = 3;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, zerstoerer3_start[0], zerstoerer3_start[1], zerstoerer3_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    // ---------------------U-Boot--------------------------------------------------
    
    cout << "Das U-Boot belegt 2 Kaestchen." << endl;
    
    kaestchen = 2;
    
    cout << "Geben Sie die Startkoordinate für das U-Boot 1 ein: " << endl;
    
    cin.getline(uboot1_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für das U-Boot 1 ein: " << endl;
    
    cin.getline(uboot1_ende, 3);
    
    schiff = 7;
    
    schiffgroesse[7] = 2;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, uboot1_start[0], uboot1_start[1], uboot1_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für das U-Boot 2 ein: " << endl;
    
    cin.getline(uboot2_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für das U-Boot 2 ein: " << endl;
    
    cin.getline(uboot2_ende, 3);
    
    schiff = 8;
    
    schiffgroesse[8] = 2;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, uboot2_start[0], uboot2_start[1], uboot2_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für das U-Boot 3 ein: " << endl;
    
    cin.getline(uboot3_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für das U-Boot 3 ein: " << endl;
    
    cin.getline(uboot3_ende, 3);
    
    schiff = 9;
    
    schiffgroesse[9] = 2;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, uboot3_start[0], uboot3_start[1], uboot3_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // -----------------------------------------------------------------------------
    
    cout << "Geben Sie die Startkoordinate für das U-Boot 4 ein: " << endl;
    
    cin.getline(uboot4_start, 3);
    
    
    cout << "Geben Sie die Endkoordinate für das U-Boot 4 ein: " << endl;
    
    cin.getline(uboot4_ende, 3);
    
    schiff = 0;
    
    schiffgroesse[0] = 2;
    
    // Schiff eintragen
    
    schiffeEintragen(spielfeld_schiff, uboot4_start[0], uboot4_start[1], uboot4_ende[0], kaestchen, schiff);
    
    spielfeldAusgabe(spielfeld_schiff);
    
    
    // "Clear Screen" Systemunabhängig
    cout << string( 100, '\n' );
    
    
    
    // -----------------------------------------------------------------------------
    // ---------------------Schiffe versenken---------------------------------------
    // -----------------------------------------------------------------------------
    
    
    // solange Schiffe vorhanden
    while (schiffcounter != 0)
    {
        spielfeldAusgabe(spielfeld_user);
        
        
        cout << "Geben Sie die Koordinate für den Schuss ein: " << endl;
        
        cin.getline(schuss, 3);
        
        
        schiffcounter = schussAuswerten(spielfeld_schiff, spielfeld_user, schuss[0], schuss[1], schiffgroesse, schiffcounter);
        
    }
    
    // alle Schiffe versenkt
    if (schiffcounter == 0)
    {
        cout << "Die gesamte Flotte wurde vernichtet!" << endl;
        
        spielfeldAusgabe(spielfeld_user);
    }
    
    
    
    return 0;
}




// -----------------------------------------------------------------------------
// ---------------------Funktionen----------------------------------------------
// -----------------------------------------------------------------------------



// Beide Spielfeldtypen erstellen
// Ansicht Schiffeingabe und
// Ansicht User
void spielfeldErstellen(char spielfeld_schiff[11][11])
{
    // Koordinaten erstellen
    char inhalt_x = 'A';
    char inhalt_y = 'a';
    
    for(; inhalt_x <= 'J';  )
    {
        for (int y= 1; y<11; y++)
        {
            
            spielfeld_schiff[0][y] = inhalt_x;
            spielfeld_schiff[y][0] = inhalt_y;
            inhalt_x++;
            inhalt_y++;
        }
        
    }
    
    // Vorausfüllen mit "Wasser" --> "."
    for (int x= 1; x<11; x++)
    {
        for (int y=1; y<11; y++)
        {
            spielfeld_schiff[x][y] = '.';
        }
    }
}


// Tutorium zum erläutern des Spielprinzip
void tutorium(char spielfeld_schiff[11][11])
{
    cout << "Spielfeld: 10×10 Kästchen" << endl
    << "- Oben A bis J" <<endl
    << "- An den Seiten a bis j" << endl << endl;
    
    // Ausgabe des spielfeld_schiffes
    for (int x= 0; x<11; x++)
    {
        for (int y=0; y<11; y++)
        {
            cout << spielfeld_schiff[x][y] <<" ";
        }
        cout << endl;
    }
    
    cout << "Koordinaten werden in der Form \"Cj\" eingeben." << endl<<endl;
    
    
    cout << "Es gibt 10 Schiffe." << endl
    << "- ein Schlachtschiff (5 Kästchen)" <<endl
    << "- zwei Kreuzer (je 4 Kästchen)" <<endl
    << "- drei Zerstörer (je 3 Kästchen)" <<endl
    << "- vier U-Boote (je 2 Kästchen)" <<endl
    << "Schiffe duerfen nicht aneinander stoßen" <<endl <<endl;
}



// Auswerten der Usersalven
// Wenn getroffen und Schiff versenkt, wird ein Counter zurück gegeben,
// welcher mir anzeigt wieviele Schiffe noch auf dem Feld sind.
int schussAuswerten(char spielfeld_schiff[11][11], char spielfeld_user[11][11], char schuss_x, char schuss_y, int schiffgroesse[10], int schiffcounter)
{
    int x_index=0;
    int y_index=0;
    
    // Umwandeln der Schuss Koordinaten in Int Werte, damit ich diese beim Array
    // als Indizä verwenden kann
    for(int al = 1, inhalt = 'a'; inhalt <= 'z'; al++, inhalt++)
    {
        if (schuss_y == inhalt)
        {
            x_index = al;
        }
    }
    
    for(int al = 1, inhalt = 'A'; inhalt <= 'Z'; al++, inhalt++)
    {
        if (schuss_x == inhalt)
        {
            y_index = al;
        }
    }
    
    
    // Umwandeln des Inhalts der Spielfeldmatrix, da meine Schiffe
    // Zahlenbezeichnungen haben
    stringstream ss (stringstream::in | stringstream::out);
    
    ss << spielfeld_schiff[x_index][y_index];
    
    int intTemp;
    
    ss >> intTemp;
    
    // Flag ob Treffer oder nicht
    bool treffer = false;
    
    // Durchgehen der 10 Schiffe
    for (int x=0; x<10; x++)
    {
        // Wenn Schiff getroffen
        if (intTemp == x && spielfeld_schiff[x_index][y_index] != '.')
        {
            // reduzieren der Schiffsgröße
            schiffgroesse[x]--;
            
            treffer = true;
            
            // Wenn das gerade getroffende Schiff auch versenkt wurde
            if (schiffgroesse[x] == 0)
            {
                // Ausgabe und in der Matrix markieren
                cout<<"Treffer und Versenkt"<<endl;
                
                spielfeld_user[x_index][y_index]= '*';
                
                // verbleibende Gesamtanzahl der Schiffe reduzieren
                schiffcounter--;
            }
            else
            {
                cout<<"Treffer"<<endl;
                
                spielfeld_user[x_index][y_index]= '*';
            }
            
        }
        
    }
    
    // Wenn kein Treffer vorhanden
    // Wasser getroffen
    if (treffer == false)
    {
        cout<<"Wasser"<<endl;
        
    }
    
    // Rückgabe der Gesamtanzahl der verbleibenen Schiffe
    return schiffcounter;
    
}




void spielfeldAusgabe(char spielfeld_schiff[11][11])
{
    // Ausgabe des Spielfeldes
    for (int x= 0; x<11; x++)
    {
        for (int y=0; y<11; y++)
        {
            if ((int)spielfeld_schiff[x][y] <= 9)
            {
                cout << (int)spielfeld_schiff[x][y] <<" ";
            }
            else
            {
                cout << spielfeld_schiff[x][y] <<" ";
            }
            
        }
        cout << endl;
    }
    cout<<endl;
}



// Eintragen der Schiffe (durch User eingegeben) in das Spielfeld
void schiffeEintragen(char spielfeld_schiff[11][11], char start_x, char start_y, char ende_x, int kaestchen, int schiff)
{
    // x=1 damit nicht die Legende befüllt wird
    for (int x=1; x<11; x++ )
    {
        if (spielfeld_schiff[0][x] == start_x)
        {
            for (int h=1; h<11; h++)
            {
                // Wenn das schiff horizontal eingetragen wurde
                if (start_x == ende_x)
                {
                    if (spielfeld_schiff[h][0] == start_y)
                    {
                        // kaestchen ist die Schiffslänge
                        for (int z=0; z<kaestchen; z++)
                        {
                            // Umwandeln von Int in Char
                            // Notwendig, da ich ein char array habe,
                            // in dem ich ein Int wert speichern möchte
                            // Schiffsname bei mir in Zahlenform
                            string s;
                            ostringstream outStream;
                            outStream << schiff;
                            s = outStream.str();
                            char temp;
                            
                            strcpy(&temp, s.c_str());
                            spielfeld_schiff[h+z][x] = temp;
                        }
                    }
                }
                else
                {
                    // Schiff wurde vertikal eingetragen
                    if (spielfeld_schiff[h][0] == start_y)
                    {
                        for (int z=0; z<kaestchen; z++)
                        {
                            string s;
                            ostringstream outStream;
                            outStream << schiff;
                            s = outStream.str();
                            char temp;
                            
                            strcpy(&temp, s.c_str());
                            spielfeld_schiff[h][x+z] = temp;
                        }
                    }
                }
            }
        }
    }
}

