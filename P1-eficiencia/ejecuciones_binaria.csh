#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = busqueda_binaria
set salida = tiempos_ordenacion_binario.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
