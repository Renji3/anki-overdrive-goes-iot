/*
 * Copyright (c) 9.11.2016 com2m GmbH.
 * All rights reserved.
 */

#include <QCoreApplication>

#include "headers/drivemode.h"
#include <signal.h>
#include <iostream>

DriveMode* driveMode;

void disconnectCars(int sig) {
    (void)sig;
    driveMode->quit();
    exit(0);
}

int main(int argc, char *argv[]) {
    printf("CAlled");
    QCoreApplication a(argc, argv);

    qRegisterMetaType<MqttMessage>("MqttMessage");

    driveMode = new DriveMode();

    signal(SIGINT, disconnectCars);

    return a.exec();
}
