# brazoRobot

## Diseño 3d

El diseño fue hecho principalmente en onshape, esto ayuda a que sea de acceso publico.

El diseño ensamblado esta aqui:
[ensamble](https://cad.onshape.com/documents/ea00d81eec46036dbb6d35f9/w/d4d8738e0bc5dfb0b9a700b8/e/afead2b773a76c8ac4ee3202)

![foto ensamblaje](https://i.imgur.com/oRL8MGC.png)

dentro de cada parte se encuentra un link para ver la pieza especifica en detalle

![Guia1](https://i.imgur.com/AOC7rim.png)

Sientanse libres de probarlo y proponer mejoras.

*NOTA:* Actualmente estan todos los diseños a ecepción de la garra, la cual sera agregada a la brevedad

## Electronica

Nuestro diseño esta basado por:

- 3 servomotores *SG90*
- 2 servomotores *MG 996R*
- 2 Ultrasonido *HC-SR04*
- 1 Arduino nano

### Observaciones de electronica

Hemos considerado que el mayor factor negativo del brazo fue la fuerza de los servomotores *SG90*, se recomienda usar el brazo con precaucion porque pueden dañar los servomotores y dejarlos inutilizables.

Debido a la cantidad de servos y la fuerza que estos realizan se recomienda no alimentar el circuito por un USB, puesto que de no haber suficiente corriente el arduino se reiniciara y volvera al estado inicial 

## Programación

El codigo esta dividido en la parte de arduino y la interfaz de flask, estara mejor comentado y documentado en la brevedad

*Nota:* fue necesario implementar una función en el arduino que mueva los servomotores poco a poco para reducir el daño a los servomotores

## Cosas por mejorar
- el agarre de la pinza puede mejorarse incrementando el toque de la garra
- cambiar la interfaz de la garra por un boton de abierto cerrado
- implementar retroalimentación de la posición del brazo
- reducir las consultas del servido a solo cuando una entrada es modificada
