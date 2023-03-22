# Hola Quark!

Mi nombre es Erik Zakaryan, estoy acá de vuelta con mi segunda oportunidad para poder pasar el curso. Espero que esta vez me haya salido bien.
En este repositorio les dejo mi Proyecto final del curso de C++.
Espero que les guste!

Para poder ejecutar el programa, simplemente tienen que abrir el archivo .exe del proyecto, que se encuentra en:

<code>.\DesafioFinalQuark2\x64\Debug\DesafioFinalQuark2.exe </code>

## Introducción
Este programa es para poder administrar un poco una biblioteca.
Algunas de las funciones que tiene es:
- Crear socios
- Crear libros
- Crear ejemplares
- Ver ejemplares disponibles
- Ver el historial de los libros prestados o devueltos
- Prestar libros
- Hacer devoluciones

Vamos a explicar un poco en qué consiste en mas detalle.

### Crear socio

Al momento de crear socio, lo que nos va a pedir el programa es su nombre, apellido, nos pregunta si es un socio VIP y, en el caso de que sea VIP, la tarifa mensual que estaría pagando.

### Crear libros

En el programa, al crear libros, en realidad lo que se hace es crear una caja donde se guardan los ejemplares, y no se crean los libros en si, ya que un libro puede no tener ejemplares (Cosa que pasa apenas se crea un libro, ya que no se crearon ejemplares).

Al crear un libro, nos pide el Título, Código ISBN de 13 dígitos, y el Autor

La clase Libro internamente tiene su lista de ejemplares creados, que estos se van agregando o quitando a medida que se cree, preste o devuelvan ejemplares.

### Crear Ejemplares

Los ejemplares son los libros propiamente dichos, son los que tienen una editorial (Ya que de un mismo libro, puede haber diferentes editoriales) y una ubicación en la biblioteca, que si tuviéramos una biblioteca real, nos ayudaría a encontrarlos mas fácilmente.

### Ver ejemplares disponibles

Ya que los ejemplares se prestan, no siempre puede haber disponibles para un libro en particular, y podemos confirmarlo desde esta función.

### Ver el historial de los libros prestados o devueltos

Esto nos permite conocer un poco los movimientos que se realizan en la biblioteca, ver qué libros, de qué editorial se prestaron y cuándo, o incluso si se devuelve un libro, podemos identificar el dónde se devolvió, a qué ubicación de la biblioteca se encuentra

### Prestar libros

Esta función nos permite prestar los ejemplares disponibles a los socios que estén habilitados a recibirlos, ya que los socios tienen una máxima cantidad de libros que pueden pedir.
Lo que nos pide esta función es ingresar algunos datos del socio y el libro que queremos prestar. Automáticamente, si es que el socio esta habilitado, se toma algún ejemplar del libro y se presta.

### Devolver libros

Cuando un socio quiere devolver un libro, se ejecuta esta función, y lo que hace es pedir el libro que se quiere devolver, revisa que el socio tenga ese libro en posesión (Lo mismo para la editorial) y lo devuelve al mismo lugar de la biblioteca que fue asignado al crear el ejemplar

## Un poco del Código

Voy a explicar un poco de forma interna cómo funciona el programa.

El programa sigue el modelo MVP, tenemos una Vista, que es la encargada de mostrar en pantalla todo lo que solicita el usuario, y el encargado de recibir los datos ingresados.
El presentador es como un intermediario entre la Vista y el Modelo, es el encargado de recibir la información que trae la Vista, y devuelve lo que solicita. Este es el que puede ingresar a los datos del Modelo, que es el que tiene toda la información, tanto de los Libros, la Biblioteca, los Socios, etc.

## Library

Dentro de nuestro Modelo, tenemos una clase principal que seria la Library (Biblioteca).
Este tiene toda la lista de los Socios, los Libros y el Historial.
Muchas de las consultas que hace el Presentador, lo hace a Library

## Book

Es la clase del Libro, pero sería como nuestra cajita de ejemplares.
Es una clase que tiene nombre (O título), código ISBN y autor.
Esta clase es la encargada de agregar nuevos ejemplares a su lista, chequear si tiene ejemplares disponibles y eliminar el ejemplar que se prestó de su lista.

## Exemplary

Son los libros propiamente dichos, los ejemplares. Son los que se mueven entre los socios y la biblioteca. Se almacenan en una lista que tiene cada Libro, y en el inventario de los socios.

## History

Cuando se hace un nuevo movimiento de un libro que involucre un socio (Como prestar o devolver un libro) lo que se hace es crear una clase History. Pero no se crea de forma directa, sino que se crean alguna de sus clases Hijas, que son Loan (Préstamo) y Devolution (Devolución).
Estos cuando se generan, se guardan en la lista de la Biblioteca, y se leen cuando se pide el historial.

## Partner

Esta clase es donde se almacena la información del socio, tiene una lista donde se almacena los libros que tiene en posesión (Si es que tiene libros prestados).
Esta clase es padre de VIP, ya que VIP también es un socio, solo que de otro tipo, y las únicas diferencias que tiene con respecto a Partner, es que tiene una cantidad máxima de libros que puede solicitar, y una tarifa mensual.

## Presenter

Es la clase intermediaria entre el Modelo y la Vista, la que se encarga de poder leer al Modelo para poder responderle a la Vista con la información que solicita para mostrar al usuario.

## IView

Es la interfaz que usa el Presenter para poder comunicarse con el View

## View

Esta se encarga de mostrar en pantalla todo lo necesario para el usuario y recibir de él lo que solicite.

Esperemos que esto sea suficiente como para poder pasar el curso y poder seguir metiéndole con Unreal

Muchas gracias por su tiempo!
Saludos!

