unsigned int Colunas[] = {1,2,3,4,5,6,7,8,9};
unsigned int Andares[] = {10,11,12};
unsigned int MatrizPinos [3][3] = {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};

void setup(){
  // Definição dos Pinos de I/O
  int i, j;
  for (i = 0; i < sizeof(Colunas)/sizeof(int); i++) {
    pinMode(Colunas[i], OUTPUT);
  }    
  for (j = 0; j < sizeof(Andares)/sizeof(int); j++){
    pinMode(Andares[j], OUTPUT); 
  }
}

// funcao que implementa delay em ms
void delay_ms(uint16_t x)
{
  uint8_t y, z;
  for ( ; x > 0 ; x--){ // decrementa o valor do tempo
    for ( y = 0 ; y < 60; y++){
      for ( z = 0 ; z < 60 ; z++){
        asm volatile ("nop");
      }
    }
  }
}

void config_MatrizCubo(int op){
  
  bool MatrizCubo[3][3];
  
  int i, j;

  switch (op){
    // Padrao 1
    case 1:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i%2 == 0 and j%2 == 0){ MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else{ MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    // Padrao 2
    case 2:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i == j){ MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else{ MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
     break;
    
   // Padrao 4
    case 3:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i%2 == 0 and j%2 == 0){ MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else{ MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      } 
    break;
    
    // Padrao 4
    case 4:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i < j){ MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
   // Padrao 5
   case 5:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i > j){ MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    // Padrao 6
    case 6:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i != j) {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    
    //Padrao 7
    case 7:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(j == 1) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    
    //Padrao 8
    case 8:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i+j == 2) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
   
    //Padrao 9
    case 9:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i == 1) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    // Padrao 10
    case 10:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i != j) {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    //Padrao 11
    case 11:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(j == 1) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
     //Padrao 12
    case 12:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(abs(i-j) == 1) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
    //Padrao 13
    case 13:
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(abs(i-j) != 1) {MatrizCubo[i][j] = 0; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
          else {MatrizCubo[i][j] = 1; digitalWrite(MatrizPinos[i][j], MatrizCubo[i][j]);}
        }
      }
    break;
   // Padrao 14
    case 14:
      for(j = 0; j < 3; j++){
        for(i = 0; i < 10; i++){
          digitalWrite(Andares[j], HIGH);
          digitalWrite(Colunas[i], HIGH);
          delay_ms(3e2);
          digitalWrite(Colunas[i], LOW);
          if(j > j-1)
          digitalWrite(Andares[j], LOW);
        }
      }
     break; 
 
    
     /*
      // Efeito Random
      case 15:
      for(j = 0; j < 3; j++){
        //j = random(0,3);
        digitalWrite(Andares[j], LOW);
        for (int i = 0 ; i < 10; i++){
          i = random(0,10);
          digitalWrite(Colunas[i], HIGH);
          delay_ms(5e2);
          digitalWrite(Colunas[i], LOW);
        }
        digitalWrite(Andares[j], HIGH);
      }
     break;
     // 1 andar por vez
    case 16:
      for(i = 0; i < 3; i++){
        digitalWrite(Andares[i], HIGH);
        delay_ms(5e2);
        digitalWrite(Andares[i], LOW);
        delay_ms(5e2);
      } 
    break;
    // 1 led e 1 andar por vez
    case 17:
      for(j = 0; j < 3; j++){
        digitalWrite(Andares[j], HIGH);
        for(i = 0; i < 10; i++){
          digitalWrite(Colunas[i], HIGH);
          delay_ms(5e2);
          digitalWrite(Colunas[i], LOW);
        }
        digitalWrite(Andares[j], LOW);
      }
    break;
    */
  }
}



void loop(){
// Declaração de Variáveis 
  int i, j;
  int flag = 0;
  
  for(int op = 1; op < 15; op++){  
    for(int k = 0; k < 3; k++){
      if(flag == 0){  // Se o andar está desabilitado
        digitalWrite(Andares[k],HIGH); // Habilito o andar
        flag = 1; 
        if(flag == 1){ // Se o andar está habilitado
          config_MatrizCubo(op); // Configura a Animação do Cubo de Led 3x3x3
          flag = 0;
          delay_ms(5e2); //500*1e-03s = 0.5s
          digitalWrite(Andares[k],LOW);
        }
      }
    }
     delay_ms(5e2);
  }
}
