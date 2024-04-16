Trabajo Práctico N°2 de Testing de Software de Sistemas Embebidos
Cohorte CESE20

Testeo de software de driver genérico para manejo de leds de un puerto específico

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

1. pre-commit (https://pre-commit.com/#install)

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
pre-commit install
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc
```

Para compilar este proyecto se usa elsiguiente comando:

```
make all
```
Para realizar testeo del software con las fucniones implementadas en test_leds.c ejecute el comando, previa instalacion de ceedling:

```
ceedling