#!/bin/bash

rm moc_*.cpp
rm *.o
qmake-qt4
make

