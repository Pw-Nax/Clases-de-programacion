

# Clases de Programacion -- Resumen 

### Tipos de variables
Los **tipos de variables** son las distintas categorías en las que se pueden clasificar los datos en programación. Los más comunes incluyen:
- **int**: Números enteros.
- **float**: Números decimales.
- **double**: Números decimales de mayor precisión.
- **char**: Caracteres individuales.
- **string**: Cadena de caracteres
- **bool**: Valores booleanos, como `true` o `false`.


```cpp
Para declarar una variable:
tipo de variable + nombre = valor de inicialización:
Ej:
int Mauri = 0;
```
  


### Inicialización de una variable.
`Preguntas frecuentes:`

¿Por qué deberiamos Inicializar una variable a `0`? En programación siempre buscamos tener el control total del programa y saber el resultado esperado que debería devolver el programa o almenos tener una aproximación, inicializar una variable en 0, implica conocer su valor desde el  inicio que se empieza a ejecutar.

### Cuándo inicializar una variable a `0`:
1. **Bucles y contadores**: Si estás usando una variable como contador, es común inicializarla a `0` antes de un ciclo.
   
   ```cpp
   int contador = 0;
   for (int i = 0; i < 10; i++) {
       contador++;
   }
   ```

2. **Acumuladores**: Cuando una variable va a almacenar una suma o acumulación de valores, se inicializa a `0` para evitar resultados incorrectos.

   ```cpp
   int suma = 0;
   for (int i = 0; i < 10; i++) {
       suma += i;
   }
   ```

3. **Buenas prácticas**: Aunque no siempre sea obligatorio, inicializar una variable a un valor conocido (como `0` o `null`) suele ser una buena práctica para evitar errores y hacer el código más legible.

    `¿Es necesario inicializar siempre una variable?`
    
    No es **estrictamente necesario** en todos los casos, pero **recomendable** en los siguientes:

- **Variables locales**: En lenguajes como C o C++, las variables locales (dentro de funciones o bloques de código) **no se inicializan automáticamente**. Si no las inicializas, contendrán un valor aleatorio.
  
  ```cpp
  int x;        // No inicializada, contiene un valor cualquiera
  cout << x;  // Comportamiento indefinido
  ```



### Conclusión:
No siempre es obligatorio inicializar una variable a `0`, pero es una buena práctica hacerlo en situaciones donde no tienes certeza del valor inicial o cuando vas a utilizar la variable como acumulador o contador. Además, en lenguajes como C y C++, inicializar variables es esencial para evitar errores debido a valores indeterminados.





### Operadores aritméticos
Los **operadores aritméticos** permiten realizar operaciones matemáticas con variables y constantes. Los principales son:
- `+`: Suma
- `-`: Resta
- `*`: Multiplicación
- `/`: División
- `%`: Módulo (devuelve el resto de una división entre enteros)

### Operadores lógicos
Los **operadores lógicos** se utilizan para realizar comparaciones y combinaciones de expresiones booleanas. Los más comunes son:
- `&&`: AND lógico, verdadero si ambos operandos son verdaderos.
- `||`: OR lógico, verdadero si al menos uno de los operandos es verdadero.
- `!`: NOT lógico, invierte el valor de la expresión (de verdadero a falso y viceversa).

### Los operadores más importantes
Algunos operadores clave en casi todos los lenguajes incluyen:
- **Aritméticos**: Suma, resta, multiplicación, división.
- **De asignación**: `=` (asigna un valor a una variable).
- **Relacionales**: `==` (igual), `!=` (distinto), `>` (mayor que), `<` (menor que).
- **Lógicos**: `&&`, `||`, `!` (para combinar expresiones booleanas).

### Condicionales: if - else y else if
- **if-else**: Permite ejecutar un bloque de código si una condición es verdadera (`if`) y otro bloque si la condición es falsa (`else`).
  
  ```cpp
  if (condicion) {
      // Bloque de instrucciones...
  } else {
      // Bloque de instrucciones...
  }
  ```

- **else if**: Se usa cuando tienes múltiples condiciones que verificar. Si la primera condición es falsa, se evalúan otras con `else if`.

  ```cpp
  if (condicion1) {
      // Bloque de instrucciones si la condición es verdadera...
  } else if (condicion2) {
      // Bloque de instrucciones 2 si la condición es verdadera...
  } else {
      // Bloque de instrucciones... si ninguna es verdadera
  }
  ```

**Diferencia clave**: 
- **`else`** se ejecuta si todas las condiciones anteriores son falsas.
- **`else if`** te permite evaluar una nueva condición antes de ejecutar un bloque alternativo.

### Ciclo repetitivo FOR
-  Se usa cuando conoces de antemano cuántas veces deseas repetir un bloque de código. Generalmente se usa con contadores.

  ```cpp
  for (int i = 0; i < 10; i++) {
      // Código que se ejecuta 10 veces
  }
  ```

### Bucles WHILE - DO WHILE

- **WHILE**: Se ejecuta mientras una condición sea verdadera. Se usa cuando no se sabe cuántas iteraciones se necesitarán.

  ```cpp
  while (condicion) {
      // Código que se ejecuta mientras la condicion sea verdadera
  }
  ```

- **do-while**: Similar al `while`, pero la condición se evalúa después de ejecutar el bloque de código, asegurando que el ciclo se ejecute al menos una vez.

  ```cpp
  do {
      // Código que se ejecuta al menos una vez
  } while (condicion);
  ```

### Diferencias entre for, while y do-while
- **`for`**: Se usa cuando el número de iteraciones es conocido.
- **`while`**: Se usa cuando se quiere repetir un bloque mientras una condición es verdadera, y no necesariamente se conoce el número de iteraciones.
- **`do-while`**: Similar a `while`, pero garantiza que el ciclo se ejecute al menos una vez, ya que la condición se evalúa después del primer ciclo.

Este resumen cubre lo esencial de cada tema. Si tienes alguna duda o quieres más ejemplos, no duden en preguntarme.






Ejercicios adicionales para realizar:

 ```cpp

  1) Invertir un número: Dado un número entero positivo, crea un programa que invierta sus dígitos. Por ejemplo, si el número es 1234, el programa debe devolver 4321. `

  2)  Contar dígitos de un número: Escribe un programa que cuente cuántos dígitos tiene un número entero positivo ingresado por el usuario. Por ejemplo, el número 56789 tiene 5 dígitos.

  3)  Determinar si un número es palíndromo: Crea un programa que verifique si un número entero es un palíndromo. Un número es palíndromo si se lee igual de izquierda a derecha que de derecha a izquierda (ejemplo: 1221).

  4) Suma de los dígitos de un número: Desarrolla un programa que tome un número entero positivo y calcule la suma de todos sus dígitos. Por ejemplo, si el número es 456, la suma sería 4 + 5 + 6 = 15.

  5) Pedir un número mayor a 100: Escribe un programa que pida al usuario que ingrese un número mayor a 100. Si el número es menor o igual a 100, sigue pidiéndolo hasta que el usuario ingrese un número válido.

  6)  Mostrar números pares del 1 al 100: Crea un programa que muestre todos los números pares entre 1 y 100. El programa debe imprimir los números en secuencia.

  7)  Sumar números hasta que el usuario ingrese un cero: Escribe un programa que permita al usuario ingresar varios números. El programa debe sumar todos los números ingresados hasta que el usuario ingrese un 0.

  8) Contar cuántos números son positivos, negativos o ceros: Desarrolla un programa que permita al usuario ingresar un conjunto de números indefinido. El programa debe contar cuántos números son positivos, cuántos son negativos y cuántos son ceros. Termina el proceso cuando el usuario ingrese un número negativo.

  9)  Generar una tabla de multiplicar: Crea un programa que pida al usuario ingresar un número y luego imprima la tabla de multiplicar de ese número, desde el 1 hasta el 10.

  10)  Adivinar un número secreto: Escribe un programa que seleccione un número secreto aleatorio entre 1 y 50. El usuario debe adivinar el número, y el programa debe darle pistas si el número es mayor o menor al ingresado. El programa continúa hasta que el usuario adivine el número.

  11)  Verificar si un número es primo: Desarrolla un programa que permita al usuario ingresar un número y determine si ese número es primo (solo divisible por 1 y por sí mismo).

  12)  Imprimir los primeros n múltiplos de un número: Crea un programa que pida al usuario ingresar un número y luego imprima los primeros n múltiplos de ese número, donde n es un valor dado por el usuario.

  13)  Sumar todos los números pares entre dos números dados: Escribe un programa que permita al usuario ingresar dos números y sume todos los números pares que existen entre ellos, incluidos los dos números si son pares.

  14)  Solicitar una contraseña hasta que sea correcta: Desarrolla un programa que le pida al usuario una contraseña. Si la contraseña es incorrecta, sigue pidiéndola hasta que el usuario ingrese la contraseña correcta.
  
  ```

### Ejercicios de Desarrollo completo.

Aquí tienes 3 ejercicios completos que combinan todo lo que has visto hasta ahora (variables, operadores, condicionales, ciclos) para desarrollarlos:

### Ejercicio 1: **Juego de Adivinar el Número**
Escribe un programa que elija un número secreto al azar entre 1 y 100, y permita al usuario adivinar cuál es el número. El programa debe indicar si el número ingresado es mayor o menor que el número secreto, y debe contar cuántos intentos ha tomado adivinar correctamente. Al final, el programa debe mostrar el número de intentos.

#### Requisitos:
1. Elige un número secreto al azar entre 1 y 100.
2. Solicita al usuario que ingrese un número.
3. Compara el número ingresado con el número secreto:
   - Si el número es mayor, muestra un mensaje que diga "El número es menor".
   - Si el número es menor, muestra un mensaje que diga "El número es mayor".
4. Continúa el proceso hasta que el usuario adivine el número.
5. Muestra cuántos intentos le tomó al usuario adivinar correctamente.

#### Ejemplo:
```
Adivina el número (entre 1 y 100): 50
El número es mayor.
Adivina el número (entre 1 y 100): 75
El número es menor.
Adivina el número (entre 1 y 100): 60
¡Correcto! Lo has adivinado en 3 intentos.
```

---

### Ejercicio 2: **Promedio de Calificaciones**
Desarrolla un programa que calcule el promedio de calificaciones ingresadas por el usuario. El programa debe permitir al usuario ingresar un número indefinido de calificaciones y detenerse cuando ingrese un valor negativo. Al final, el programa debe mostrar cuántas calificaciones fueron ingresadas, la suma total y el promedio.

#### Requisitos:
1. Solicita al usuario que ingrese una calificación.
2. Sigue pidiendo calificaciones hasta que se ingrese un número negativo.
3. Lleva un registro de cuántas calificaciones fueron ingresadas y la suma de todas ellas.
4. Calcula el promedio cuando se ingrese un valor negativo.
5. Muestra el número total de calificaciones, la suma y el promedio.

#### Ejemplo:
```
Ingrese una calificación (o un número negativo para salir): 85
Ingrese una calificación (o un número negativo para salir): 90
Ingrese una calificación (o un número negativo para salir): 78
Ingrese una calificación (o un número negativo para salir): -1

Número total de calificaciones: 3
Suma total de calificaciones: 253
Promedio: 84.33
```

---

### Ejercicio 3: **Tabla de Multiplicar**
Crea un programa que genere la tabla de multiplicar de un número ingresado por el usuario. El usuario debe ingresar el número para el cual quiere ver la tabla y también debe ingresar hasta qué número desea ver la tabla (por ejemplo, hasta el 12). El programa debe mostrar el resultado en formato tabla.

#### Requisitos:
1. Solicita al usuario ingresar el número para el cual desea ver la tabla de multiplicar.
2. Solicita al usuario ingresar hasta qué número desea que se muestre la tabla.
3. Genera y muestra la tabla de multiplicar en formato limpio y ordenado.

#### Ejemplo:
```
Ingrese un número para ver su tabla de multiplicar: 7
Ingrese hasta qué número desea ver la tabla: 10

Tabla de multiplicar del 7:
7 x 1 = 7
7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63
7 x 10 = 70
```

---

Estos ejercicios abarcan todo lo que has aprendido: uso de variables, operadores, ciclos, condicionales, y manejo de entrada del usuario. Mucha suerte !


`Si puedes imaginarlo, puedes programarlo ! `






# Autor:  Cabero , Mauro.
