# Arboles binarios con persistencia de datos

_Programa que permite la creación de árboles binarios y realizar búsquedas en ancestros comunes, se incluye persistencia de datos por medio de SQLite3._

## Comenzando 🚀

_El código fuente se encuentra en el directorio "arbolesBinariosDV", el ejecutable se encuentra en el directorio "Release"._

### Pre-requisitos 📋

_Para compilar se requiere Visual Studio (C++), el ejecutable no tiene pre-requisitos, se debe descargar el contenido de repositorio y almacenarlo de manera local. _

### Instalación 🔧

_Abrir Visual Studio, en menú Archivo -> Abrir -> Proyecto o Solución_

_En la ventana emergente buscar el archivo "arbolesBinariosDV.sln, click en Abrir"_

_Click en el menú Compilar -> Compilar Solución_

_Presionar F5 para iniciar la ejecución, de igual manera se puede ejecutar directamente el archivo "arbolesBinariosDV.exe" del directorio Release_

## Ejecutando el programa ⚙️

_El programa presenta un menú con las siguientes opciones:_

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

_Se debe digitar el número correspondiente a la opción requerida y presionar Enter_

_La opción 1: permite adicionar un nodo al árbol binario, si el árbol está vacío el primer valor correspondería a la raíz del árbol binario. _
_De igual manera el nodo es agregado en una tabla en la Base de Datos para mantener la persistencia. _

_La opción 2: visualizar el árbol binario desde la raíz a las hojas de manera horizontal, ejemplo:_
```
      13
   10
      9
8
      7
   5
      2
```
_La opción 3: dado dos números enteros se realiza la búsqueda de su ancestro común, por ejemplo, de árbol anterior: _
```
Ancestro común entre 2 y 7 es 5.
Ancestro común entre 5 y 9 es 8.
Ancestro común entre 7 y 11 retornaría un mensaje indicando que el numero 11 no se encuentra en el árbol.
```
_La opción 4: Realiza la carga de los valores del árbol binario desde la base de datos, permitiendo recuperar el ultimo árbol binario generado. _
_Si al ejecutar el programa se ingresa por esta opción se carga en memoria el ultimo árbol binario generado por el programa. _
_Si existía un árbol cargado en memoria, es reemplazado por el árbol binario reconstruido a partir de los datos almacenados. _

_La opción 5: Elimina el árbol binario (si ya existe uno) en la base de datos y en memoria. _

_La opción 6: Termina la ejecución del programa. _

### Pruebas Unitarias 🔩

_Dentro del repositorio se encuentra el documento de pruebas unitarias correspondiente_

## Construido con 🛠️
```
Microsoft Visual C++ 2019, Versión 16.9.6
SQLite3
```

## Versionado 📌

Se a usado GIT para el versionado. https://github.com/davf64/arbolesBinariosDV.

## Autores ✒️

_Menciona a todos aquellos que ayudaron a levantar el proyecto desde sus inicios_

* **Diego Alfonso Vega Fernandez** - *Email davf64@yahoo.com* - (https://github.com/davf64/arbolesBinariosDV)

## Expresiones de Gratitud 🎁

* Es mi primer aporte, agradezco comentarios y críticas constructivas 📢
