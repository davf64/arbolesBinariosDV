# Arboles binarios con persistencia de datos

_Programa que permite la creacion de arboles binarios y realizar busquedas en ancestros comunes, se incluye persistencia de datos por medio de SQLILE3._

## Comenzando 🚀

_El codigo fuente se encuentra en el directorio "arbolesBinariosDV", el ejecutable se encuentra en el directorio "Release"._

### Pre-requisitos 📋

_Para compilar se requiere Visual Studio (C++), el ejecutable no tiene pre-requisitos, se debe descargar el contenido de repositorio y almacenarlo de manera local._

### Instalación 🔧

_Abrir Visual Studio, en menu Archivo -> Abrir -> Proyecto o Solucion_

_En la ventana emergente buscar el archivo "arbolesBinariosDV.sln, click en Abrir"_

_Click en el menu Compilar -> Compilar Solucion_

_Presionar F5 para iniciar la ejecucion, de igual manera se puede ejecutar el archivo "arbolesBinariosDV.exe" del directorio Release_

## Ejecutando el program ⚙️

_El programa presenta un menu con las siguientes opciones:_

```
======================================
Ingrese Una Opcion: 
======================================
(1) Crear/Modificar Arbol Binario
(2) Ver Arbol Binario
(3) Menor Ancestro
(4) Cargar Arbol Binario Almacenado
(5) Borrar Arbol Binario Almacenado
(6) Salir
```

_Se debe digitar el numero correspondiente a la opcion requerida y presionar Enter_

_La opcion 1: permite adicionar un nodo al arbol binario, si el arbol esta vacio el primer valor corresponderia a la raiz del arbol binario._
_De igual manera el nodo es agregado en una tabla en la Base de Datos para mantener la persistencia._

_La opcion 2: visualizar el arbol binario desde la raiz a las hojas de manera horizontal, ejemplo:_
```
      13
   10
      9
8
      7
   5
      2
```
_La opcion 3: dado dos numeros enteros se realiza la busqueda de su ancentro comun, por ejemplo de arbol anterior:_
```
Ancestro comun entre 2 y 7 es 5.
Ancestro comun entre 5 y 9 es 8.
Ancestro comun entre 7 y 11 retornaria un mensaje indicando que el numero 11 no se encuentra en el arbol.
```
_La opcion 4: Realiza la carga de los valores del arbol binario desde la base de datos, permitiendo recuperar el ultimo arbol binario generado._
_Si al ejecutar el programa se ingrea por esta opcion se carga en memoria el ultimo arbol binario generado por el programa._
_Si existia un arbol cargado en memoria, es reemplazado por el arbol binario reconstruido a partir de los datos almacenados._

_La opcion 5: Elimina el arbol binario (si ya existe uno) en la base de datos y en memoria._

_La opcion 6: Termina la ejecucion del programa._

### Pruebas Unitarias 🔩

_Dentro del repositorio se encuentra el documento de pruebas unitarias correspondiente_

## Construido con 🛠️
```
Visual Studio 2019
SQLite version 3
```

## Versionado 📌

Se a usado GIT para el versionado. https://github.com/davf64/arbolesBinariosDV.

## Autores ✒️

_Menciona a todos aquellos que ayudaron a levantar el proyecto desde sus inicios_

* **Diego Alfonso Vega Fernandez** - *Email davf64@yahoo.com* - (https://github.com/davf64/arbolesBinariosDV)

## Expresiones de Gratitud 🎁

* Es mi primer aporte, agradezco comentarios y criticas constructivas 📢
