# Compila el programa de la ecuacion del resorte

g++ -std=c++11 OlivellaJuan_S6C1.cpp 


#Ejecuta el programa de la ecuacion del resorte

./a.out > datosNoFriccionFuerza.dat


# Genera el grafico de la ecuacion del resorte

python OlivellaJuan_plotODE2.py

rm a.out

rm datosNoFriccionFuerza.dat


# Compila el programa de la ecuacion del resorte

g++ -std=c++11 OlivellaJuan_S6C1Friccion.cpp 


#Ejecuta el programa de la ecuacion del resorte

./a.out > datosNoFuerza.dat


# Genera el grafico de la ecuacion del resorte

python OlivellaJuan_plotODE2Friccion.py

rm a.out

rm datosNoFuerza.dat

