# 📚 Apunte: Arreglos (Arrays) en C++

Un **arreglo** es una estructura de datos que nos permite almacenar varios elementos del **mismo tipo** bajo un solo nombre. Imaginalo como una hilera de casilleros numerados en un pasillo.

## 1. Conceptos Clave

* **Índice:** Es la posición del elemento. **¡Importante!** En C++, el conteo siempre empieza en **0**.
* **Tamaño:** Es la cantidad total de elementos que puede guardar el arreglo.
* **Tipo de dato:** Todos los elementos dentro del arreglo deben ser iguales (todos `int`, todos `float`, y así.).

## 2. Declaración e Inicialización

Para crear un arreglo, especificamos el tipo, el nombre y el tamaño entre corchetes `[]`.

```cpp
int numeros[5]; // Declara un arreglo para 5 enteros (con basura de memoria)
int valores[] = {10, 20, 30, 40}; // Declara e inicializa (tamaño automático: 4)

```

> **⚠️ CUIDADO CON LOS LÍMITES:**
> Si declaras un arreglo de tamaño 5 (`int vec[5]`), los índices válidos son **0, 1, 2, 3 y 4**.
> Acceder a `vec[5]` es un error grave: estarás accediendo a un espacio de memoria que no le pertenece al arreglo, lo que causará valores basura o que el programa se cierre inesperadamente (Segmentation Fault).



## 3. Acceso a los elementos

Para leer o modificar un valor, usamos su índice:

```cpp
numeros[0] = 100; // Asigna 100 a la primera posición
cout << numeros[0]; // Imprime el valor

```

---

Para llenar un arreglo, no asignamos valores uno por uno manualmente; usamos un bucle `for` junto con `cin`.

```cpp
int notas[5];

cout << "Ingrese 5 notas:" << endl;
for(int i = 0; i < 5; i++) {
    cout << "Nota " << i << ": ";
    cin >> notas[i];  // El usuario guarda el valor directamente en la posición 'i'
}

```

## 4. Combinando con Estructuras de Control

Los arreglos alcanzan su máximo potencial cuando los usamos con **bucles** y **condicionales**.

### El bucle `for`: El mejor amigo de los arreglos

Se usa para recorrer el arreglo de principio a fin de forma eficiente.

```cpp
for(int i = 0; i < 5; i++) {
    cout << "Elemento en indice " << i << " es: " << numeros[i] << endl;
}

```

### `while` y `if`: Buscando datos

Podemos usar un `while` para buscar un elemento y un `if` para validar condiciones.

---

## 🛠️ Ejercicios de inicialización


### Nivel 1: El Contador de Positivos (Uso de `for` e `if/else`)

**Consigna:** Crea un arreglo de 10 números enteros ingresados por el usuario. Al final, muestra cuántos números fueron positivos, cuántos negativos y cuántos ceros.

### Nivel 2: El Centinela (Uso de `do-while` y `if`)

**Consigna:** Crea un arreglo con capacidad para 100 números. Pide al usuario que ingrese números uno por uno.

* Si el usuario ingresa un número negativo, la carga se detiene (aunque no haya llegado a 100).
* Al terminar, muestra la suma de todos los números ingresados.

### Nivel 3: El Buscador (Uso de `while` y `else if`)

**Consigna:** Dado un arreglo ya cargado con 10 números aleatorios (puedes definirlos tú):

1. Pide al usuario un número a buscar.
2. Usa un bucle `while` para recorrer el arreglo.
3. Si lo encuentra, muestra en qué posición está y detén la búsqueda.
4. Si llega al final y no lo encuentra, informa al usuario.

### Nivel 4: Menú de Promedios (Uso de `switch` o `if-else chain`)

**Consigna:** Carga un arreglo con las notas de 5 alumnos. Luego, muestra un menú:

* **Opción 1:** Mostrar el promedio general.
* **Opción 2:** Mostrar solo las notas aprobadas (>= 6).
* **Opción 3:** Salir.
*(Tip: Usa un `do-while` para que el menú se repita hasta que elijan salir).*

---

> **💡 Nota:** Tengan cuidado con los límites!!. Si un arreglo es de tamaño 5, el último índice válido es el 4. Acceder a `arreglo[5]` provocará un error de memoria o basura lo repito nuevamente ya que es muy importante!.




---

## 🛠️ Guía de Ejercicios Prácticos

### 🟢 Nivel: Fácil (Para entender la sintaxis)

1. **Suma Simple:** Declara un arreglo de 5 enteros, pídelos por teclado y muestra la suma total.
2. **Inversión:** Pide 5 números y muéstralos en el orden inverso al que fueron ingresados.
3. **El Duplicador:** Crea un arreglo con 10 números. Genera un segundo arreglo donde cada elemento sea el doble del primero.
4. **Buscador de Pares:** Pide 8 números y muestra por pantalla solo aquellos que sean pares.
5. **Inicialización Dinámica:** Pide al usuario el tamaño del arreglo (máximo 20), llénalo de números y muéstralo.

### 🟡 Nivel: Intermedio (Lógica con `if`, `while` y acumuladores)

6. **El Mayor de la Clase:** Pide 10 notas. Encuentra cuál es la nota más alta y en qué posición (índice) se encuentra.
7. **Promedio Condicional:** Carga 7 números. Calcula el promedio de los números que sean mayores a 10. Si no hay ninguno, avisa al usuario.
8. **El Centinela:** Crea un arreglo de hasta 50 posiciones. El usuario ingresa números hasta que ingrese un `0` o se llene el arreglo. Luego, muestra cuántos números ingresó en total.
9. **Contador de Rango:** Pide 10 números y cuenta cuántos están entre el rango de [10 y 20], cuántos son menores y cuántos mayores.
10. **Búsqueda con Éxito:** Pide al usuario que llene un arreglo de 10 posiciones. Luego pide un número extra y dile si ese número está en el arreglo o no (usa un `bool` para la bandera).

### 🔴 Nivel: Difícil (Lógica avanzada y algoritmos)

11. **Ordenamiento Burbuja:** Pide 5 números desordenados y programar el algoritmo para que los muestre ordenados de menor a mayor.
12. **Eliminar Duplicados:** Crea un arreglo de 10 números con valores repetidos. Crea un nuevo arreglo que contenga los mismos números pero sin repetir ninguno.
13. **Desplazamiento a la Derecha:** Pide 5 números. Mueve todos los elementos una posición hacia la derecha (el último pasa a ser el primero).
14. **Validación de Contraseñas:** Crea un arreglo de `char` o `int` que sea una "clave". Pide al usuario que intente adivinarla. Tiene solo 3 intentos (usa `do-while`).
15. **Frecuencia de Números:** Carga un arreglo de 10 elementos con números del 1 al 5. Indica cuántas veces aparece cada número (Ej: "El 1 aparece 3 veces, el 2 aparece 0 veces...").

---

**Sugerencia :** Para los ejercicios difíciles, El uso de "variables auxiliares" es clave para intercambiar valores o mantener conteos temporales.
