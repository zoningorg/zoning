/*
 * MIT License
 * 
 * Copyright (c) 2021 Uriel Rivas
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * https://github.com/Garz4/zoning/blob/master/LICENSE
 */

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include "SocketDatagrama.h"
#include "Mensaje.h"
#include <string.h>

class Solicitud {
 public:
  ~Solicitud();
  Solicitud();
  char* doOperation(char* IP, int puerto, char* solicitud);
  char* getIP();

 private:
  SocketDatagrama* socketLocal;
  struct mensaje Recibido;
  struct mensaje Enviar;
  char* dirIP;
  char request;
};

#endif
