// risiko.c
// Include le librerie necessarie
#include "risiko.h"        // Libreria con le funzioni

/**
 * Restituisce il colore corrispondente al carattere in input (maiuscolo/minuscolo)
 * @param [in] c carattere rappresentante il colore
 * @return colore corrispondente al carattere
 * BLUE se il carattere è 'B' o 'b'
 * GREEN se il carattere è 'G' o 'g'
 * ORANGE se il carattere è 'O' o 'o'
 * PINK se il carattere è 'P' o 'p'
 * RED se il carattere è 'R' o 'r'
 * VIOLET se il carattere è 'V' o 'v'
 * WHITE se il carattere è 'W' o 'w'
 * YELLOW se il carattere è 'Y' o 'y'
 * supporre che il carattere in input sia sempre valido
**/
color get_color(char c) {
    // Confrontare il carattere con le lettere rappresentanti i colori
    switch (toupper(c))
    {
    case 'B':
        return BLUE;
    case 'G':
        return GREEN;
    case 'O':
        return ORANGE;
    case 'P':
        return PINK;
    case 'R':
        return RED;
    case 'V':
        return VIOLET;
    case 'W':
        return WHITE;
    case 'Y':
        return YELLOW;
    }
}

/**
 * Calcola il numero di giocatori 
 * @param [in] game sequenza di gioco
 * @return numero di giocatori
**/
int get_num_players(char game[]) {
    // Trova il primo numero nella sequenza di gioco
    int i = 0;
    // Iterare lungo la sequenza di gioco
    for (; game[i]!='\0'; i++) {
        // Se il carattere è un numero
        if (game[i] >= '0' && game[i] <= '9') {
            // restituire l'indice precedente
            return i - 1;
        }
    }
    // Se non è stato trovato alcun numero
    // restituire l'indice dell'ultimo carattere
    return i;
}

/**
 * Restituisce il numero di armate corrispodente al carattere in input (1 - 3)
 * @param [in] c carattere rappresentante il numero di armate
 * @return numero di armate corrispondente al carattere
 * supporre che il carattere in input sia sempre valido
**/
int get_armies(char c) {
    // Per convertire un carattere numerico in intero
    // basta sottrarre il carattere '0'
    return c - '0';
}

/**
 * Calcola di quanto incrementare le armate possedute dal giocatore che 
 * termina il suo turno in base al numero dei territori in suo possesso  
 * @param [in] territories numero di territori posseduti dal giocatore
 * @return numero di armate da incrementare
**/
int get_new_armies(int territories) {
    // Il numero di armate da incrementare è pari 
    // alla metà dei territori posseduti + 1
    return (territories / 2) + 1;
}

/**
 * Calcola l'indice colore del giocatore nell'array dei giocatori
 * @param [in] players array dei giocatori
 * @param [in] num_players numero di giocatori
 * @param [in] player colore del giocatore da cercare
 * @return indice del giocatore nell'array dei giocatori
**/
int get_player_index (struct Player players[], int num_players, color player) {
    // Iterare lungo l'array dei giocatori
    for (int i = 0; i < num_players; i++) {
        // Se il colore del giocatore corrisponde al colore cercato
        if (players[i].token == player) {
            // restituire l'indice
            return i;
        }
    }
}

/**
 * Calcola l'indice colore del vincitore nell'array dei giocatori
 * @param [in] players array dei giocatori
 * @param [in] num_players numero di giocatori
 * @return indice del vincitore nell'array dei giocatori
**/
int get_winner_index (struct Player players[], int num_players) {
    // Inizializzare il numero di territori massimo
    // con il numero di territori del primo giocatore
    int max_territories = players[0].territories;
    // Inizializzare l'indice del vincitore con 0
    int winner_index = 0;
    // Iterare lungo l'array dei giocatori
    for (int i = 1; i < num_players; i++) {
        // Se il numero di territori del giocatore corrente
        // è maggiore del numero di territori massimo
        if (players[i].territories > max_territories) {
            // aggiornare l'indice del vincitore
            winner_index = i;
            // e il numero di territori massimo
            max_territories = players[i].territories;
        }
    }
    // Restituire l'indice del vincitore
    return winner_index;
}

/**
 * Gestisce i turni di gioco e al termine stampa il vincitore
 * @param [in] game sequenza di gioco
**/
void game_evolution(char game[]) {
    // Calcolare il numero di giocatori
    int num_players = get_num_players(game);
    // Definire l'array per tenere traccia dei giocatori
    struct Player players[num_players];
    // Popolare l'array con i dati iniziali dei giocatori
    for (int i = 0; i < num_players; i++) {
        // Prendere il colore del giocatore
        players[i].token = get_color(game[i]);
        // e initializzare il numero di armate e territori
        players[i].armies = INITIAL_ARMIES;
        players[i].territories = INITIAL_TERRITORIES;
    }
    // Definire una variabile per tenere traccia del turno
    int turn = 0;
    // Definire una variabile per tracciare l'indice del turno all'interno della sequenza di gioco
    int game_index = num_players + turn*TURN_LENGTH;
    // Definire una variabile per tenere traccia del turno del giocatore
    int player_turn = 0;
    // Iterare lungo la sequenza di gioco
    while (game[game_index]!='\0') {
        // determinare l'attaccante
        color attacker = get_color(game[player_turn]);
        // determinare il difensore
        color defender = get_color(game[game_index]);
        // Determinare il vincitore del combattimento
        int winner = 0;
        // Se il difensore è diverso dall'attaccante
        if (defender != attacker) {
            // il numero di armate in attacco
            int att_armies = get_armies(game[game_index+1]);
            // il numero di armate in difesa
            int def_armies = get_armies(game[game_index+2]);
            // Trovare l'indice dell'attaccante nell'array dei giocatori
            int attacker_index = get_player_index(players, num_players, attacker);
            // Trovare l'indice del difensore nell'array dei giocatori
            int defender_index = get_player_index(players, num_players, defender);
            // Determinare il vincitore del combattimento
            winner = get_winner(att_armies, def_armies);
            // Se l'attaccante ha vinto
            if (winner > 0) {
                // decrementare il numero di armate dell'attaccante
                players[attacker_index].armies -= att_armies - winner;
                // decrementare il numero di armate del difensore
                players[defender_index].armies -= def_armies;
                // aumentare il numero di territori dell'attaccante
                players[attacker_index].territories++;
                // decrementare il numero di territori del difensore
                players[defender_index].territories--;
                // se il carattere iniziale è maiuscolo
                if (isupper(game[game_index])) {    
                    // Calcolare il numero di armate da aggiungere all'attaccante
                    players[attacker_index].armies += get_surplus_armies();
                }
            // Se invece il difensore ha vinto
            } else {
                // decrementare il numero di armate dell'attaccante
                players[attacker_index].armies -= att_armies;
                // decrementare il numero di armate del difensore
                players[defender_index].armies -= def_armies + winner;
                // aggiornare il turno del giocatore
                player_turn = (player_turn + 1) % num_players;
            }
            // In ogni caso, aggiungere le armate alla conclusione 
            // del turno in base al numero di territori posseduti
            players[attacker_index].armies += get_new_armies(players[attacker_index].territories);
        // Se il difensore è uguale all'attaccante
        // l'attaccante cede il suo turno
        } else {
            // aggiornare solo il turno del giocatore
            player_turn = (player_turn + 1) % num_players;
        }
        // Stampare il risultato del turno
        print_turn_result(attacker, game, turn, winner);
        // in ogni caso aggiornare l'indice del turno
        turn++;
        // e aggiornare l'indice del turno nella sequenza di gioco
        game_index = num_players + turn*TURN_LENGTH;
    }
    // Conclusi i turni di gioco
    // determinare l'indice del vincitore
    int winner_index = get_winner_index(players, num_players);
    print_winner(players[winner_index]);
}