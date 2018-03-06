/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    LineFollowerTest.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/09/09
 * @brief   Description: this file is sample code for Me line follower module.
 *
 * Function List:
 * 1. uint8_t MeLineFollower::readSensors(void)
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Mark Yan         2015/09/09    1.0.0            Rebuild the old lib.
 * </pre>
 */
#include "MeOrion.h"

/*MeLineFollower lineFinder(PORT_4); /* Line Finder module can only be connected to PORT_3, PORT_4, PORT_5, PORT_6 of base shield. */

MeUltrasonicSensor ultraSensor(PORT_4); /* Ultrasonic module can ONLY be connected to port 3, 4, 6, 7, 8 of base shield. */

MeDCMotor MOTEUR_AVANT(M2);       /*::::::::: Moteur Avant du robot                 ::::::::::::::*/
MeDCMotor MOTEUR_ARRIERE(M1);         /*::::::::: Moteur Arrière  du robot                   ::::::::::::::::*/
int VITESSE_MOTEUR_AV = 471;        /*::::::::: Vitesse déplacement de la roue avant    ::::::::::::::::*/
int VITESSE_MOTEUR_AR = -600;        /*::::::::: vitesse déplacement de la roue arrière  ::::::::::::::::*/

int DISTANCE_EVITEMENT = 12;
void setup()
//{
  Serial.begin(9600);
}

void loop()
{
  /*int sensorState = lineFinder.readSensors();*/
  int obstacleDistance = ultraSensor.distanceCm();

  if(obstacleDistance<DISTANCE_EVITEMENT){
    eviterObstacle();
  }
  else{
    Run();
  }
  delay(50);
}

void Run(){
          avant();
}
void eviterObstacle(){
  arret();  
}

void droite(){
          MOTEUR_AVANT.run(VITESSE_MOTEUR_AR); // --> Moteur Marche Arrière.
        MOTEUR_ARRIERE.stop(); // -----------> Moteur à l'Arrêt.
}

void gauche(){
          MOTEUR_AVANT.stop(); // -----------> Moteur à l'Arrêt.
        MOTEUR_ARRIERE.run(VITESSE_MOTEUR_AV); // ----> Moteur Marche Arrière.
}

void avant(){
          MOTEUR_AVANT.run(VITESSE_MOTEUR_AR/2); // ----> Moteur Marche Avant.
        MOTEUR_ARRIERE.run(VITESSE_MOTEUR_AV/2); // --> Moteur Marche Avant.
}

void arriere(){
          MOTEUR_AVANT.run(VITESSE_MOTEUR_AV/3); // --> Moteur Marche Arrière.
        MOTEUR_ARRIERE.run(VITESSE_MOTEUR_AR/3); // ----> Moteur Marche Arrière.
}

void arret(){
   MOTEUR_AVANT.stop(); // -----------> Moteur à l'Arrêt.
    MOTEUR_ARRIERE.stop(); // -----------> Moteur à l'Arrêt.
}



