#include <iostream>
using namespace std;

void Tablerito(int tablerito[3][3]) {
	
    cout << "\nTablero: " <<endl;
    
	for (int i = 0; i < 3; i++) {
      
	    for (int j = 0; j < 3; j++) {
      
	        cout << tablerito[i][j] << " ";
      
	    }
        cout << endl;
    }
    cout << endl;
}


bool Ganas(int tablerito[3][3], int jugador) {
    
	for (int i = 0; i < 3; i++) {
    
	    if (tablerito[i][0] == jugador && tablerito[i][1] == jugador && tablerito[i][2] == jugador) {
    
	        return true;
    
	    }
    
	}
	

    for (int j = 0; j < 3; j++) {
       
	    if (tablerito[0][j] == jugador && tablerito[1][j] == jugador && tablerito[2][j] == jugador) {
       
	        return true;
       
	    }
    }

    if (tablerito[0][0] == jugador && tablerito[1][1] == jugador && tablerito[2][2] == jugador) {
       
	    return true;
    
	}
    

   
    if (tablerito[0][2] == jugador && tablerito[1][1] == jugador && tablerito[2][0] == jugador) {
   
        return true;
   
    }

    
	return false;

}

bool Empate(int tablerito[3][3]) {
	
    for (int i = 0; i < 3; i++) {
    
	    for (int j = 0; j < 3; j++) {
    
	        if (tablerito[i][j] == 0) {
    
	            return false;
    
	        }
    
	    }
    
	}
    
	return true;
}

int main() {
	
    int tablerito[3][3];
    
	int jugador = 1;
    
	int fila, columna;

    for (int i = 0; i < 3; i++) {
        
		for (int j = 0; j < 3; j++) {
        
		    tablerito[i][j] = 0;
        
		}
    
	}
	
	
cout << "=== Paul Inc. & Asociados ===" << endl;
    cout << "=== SUPER TRES EN RAYA ===" << endl;
    
    Tablerito(tablerito);

    while (true) {
    	
        cout << "Turno de jugador " << jugador << endl;
        
		cout << "Ingrese fila (use 0, 1 o 2): ";
        
		cin >> fila;
        
		cout << "Ingrese columna (use 0, 1 o 2): ";
        
        cin >> columna;

        if (fila < 0 or fila > 2 or columna < 0 or columna > 2) {
        	
            cout << "Posicion invalida. Escribe nuevamente.\n";
            
			continue;
        
		}

        if (tablerito[fila][columna] != 0) {
        	
			cout << "Casilla ocupada, intenta de nuevo.\n";
            
			continue;
        }

        tablerito[fila][columna] = jugador;
        Tablerito(tablerito);

        if (Ganas(tablerito, jugador)) {
        	
            cout << "El ganador es: " << jugador << endl;
            
			break;
        }

        if (Empate(tablerito)) {
        	
            cout << "Empataronnn! :D " << endl;
            
            break;
        }

        if (jugador == 1) {
        	
            jugador = 2;
            
        } else {
            
			jugador = 1;
        
		}
    }

    return 0;
}