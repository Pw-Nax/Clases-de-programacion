# Ejercicios de Lógica con Condicionales

Este documento reúne ejercicios de lógica para practicar el uso de condicionales en programación.  
Están organizados en niveles de dificultad, con ejemplos de entrada/salida para mayor claridad.  

---

## 📑 Índice

- [Nivel 1: Ejercicios con `if`](#nivel-1-ejercicios-con-if)
- [Nivel 2: Ejercicios con `if – else if – else`](#nivel-2-ejercicios-con-if--else-if--else)
- [Nivel 3: Ejercicios difíciles](#nivel-3-ejercicios-difíciles)

---

## 🔹 Nivel 1: Ejercicios con `if`

1. **Número positivo**  
   Leer un número entero e imprimir "Positivo" si es mayor que 0.  
   - Ejemplo:  
     - Entrada: `5` → Salida: `Positivo`  

2. **Número par**  
   Leer un número entero e imprimir "Par" si el número es divisible por 2.  
   - Ejemplo:  
     - Entrada: `4` → Salida: `Par`  

3. **Mayor de edad**  
   Leer la edad de una persona e imprimir "Mayor de edad" si la edad es mayor o igual a 18.  
   - Ejemplo:  
     - Entrada: `20` → Salida: `Mayor de edad`  

4. **Temperatura alta**  
   Leer la temperatura en °C e imprimir "Hace calor" si es mayor a 30.  
   - Ejemplo:  
     - Entrada: `35` → Salida: `Hace calor`  

5. **Contraseña correcta**  
   Leer una cadena de texto e imprimir "Acceso permitido" si la contraseña ingresada es igual a `"1234"`.  
   - Ejemplo:  
     - Entrada: `1234` → Salida: `Acceso permitido`  

6. **Descuento por compra**  
   Leer el monto de una compra e imprimir "Descuento aplicado" si supera los 10 000.  
   - Ejemplo:  
     - Entrada: `12000` → Salida: `Descuento aplicado`  

7. **Nota aprobada**  
   Leer una nota de examen e imprimir "Aprobado" si es mayor o igual a 6.  
   - Ejemplo:  
     - Entrada: `7` → Salida: `Aprobado`  

8. **Número múltiplo de 5**  
   Leer un número entero e imprimir "Múltiplo de 5" si es divisible por 5.  
   - Ejemplo:  
     - Entrada: `25` → Salida: `Múltiplo de 5`  

9. **Velocidad excedida**  
   Leer la velocidad de un auto e imprimir "Exceso de velocidad" si es mayor a 120 km/h.  
   - Ejemplo:  
     - Entrada: `150` → Salida: `Exceso de velocidad`  

10. **Luz encendida**  
   Leer el estado de un interruptor (0 apagado, 1 encendido) e imprimir "Luz encendida" si el valor es 1.  
   - Ejemplo:  
     - Entrada: `1` → Salida: `Luz encendida`  

11. **Número positivo o negativo o cero**  
   Pedir un número al usuario e indicar si es positivo, negativo o cero.  
   - Ejemplo:  
     - Entrada: `0` → Salida: `Cero`  

12. **Número par o impar**  
   Ingresar un número entero y mostrar si es par o impar.  
   - Ejemplo:  
     - Entrada: `7` → Salida: `Impar`  

13. **Comparar dos números**  
   Leer dos números e indicar cuál es mayor o si son iguales.  
   - Ejemplo:  
     - Entrada: `5 5` → Salida: `Son iguales`  

---

## 🔹 Nivel 2: Ejercicios con `if – else if – else`

1. **Clasificación de edades**  
   Leer la edad de una persona e imprimir:  
   - "Niño" si es menor de 12,  
   - "Adolescente" si está entre 12 y 17,  
   - "Adulto" si está entre 18 y 59,  
   - "Adulto mayor" si es 60 o más.  
   - Ejemplo:  
     - Entrada: `65` → Salida: `Adulto mayor`  

2. **Notas en letras**  
   Dada una nota (0–10), mostrar:  
   - "Insuficiente" si < 6,  
   - "Aprobado" si entre 6 y 7,  
   - "Notable" si entre 8 y 9,  
   - "Sobresaliente" si es 10.  
   - Ejemplo:  
     - Entrada: `8` → Salida: `Notable`  

3. **Clasificación de triángulos por lados**  
   Dados tres lados enteros:  
   - Si todos son iguales → "Equilátero".  
   - Si dos son iguales → "Isósceles".  
   - Si los tres son distintos → "Escaleno".  
   - Ejemplo:  
     - Entrada: `3 3 5` → Salida: `Isósceles`  

4. **Clasificación de números**  
   Leer un número entero e indicar si es:  
   - "Negativo",  
   - "Cero",  
   - "Positivo".  
   - Ejemplo:  
     - Entrada: `-2` → Salida: `Negativo`  

5. **Categoría de IMC**  
   Dado el índice de masa corporal (IMC):  
   - < 18.5 → "Bajo peso",  
   - 18.5–24.9 → "Normal",  
   - 25–29.9 → "Sobrepeso",  
   - 30 o más → "Obesidad".  
   - Ejemplo:  
     - Entrada: `22` → Salida: `Normal`  

6. **Conversión a calificación universitaria**  
   Dada una nota en porcentaje (0–100):  
   - 90–100 → "A",  
   - 80–89 → "B",  
   - 70–79 → "C",  
   - 60–69 → "D",  
   - Menos de 60 → "F".  
   - Ejemplo:  
     - Entrada: `75` → Salida: `C`  

7. **Días de la semana**  
   Ingresar un número (1–7) e imprimir el día correspondiente.  
   - Ejemplo:  
     - Entrada: `3` → Salida: `Miércoles`  

8. **Clasificación de velocidad**  
   Dada la velocidad de un auto en km/h:  
   - < 40 → "Muy lento",  
   - 40–79 → "Moderado",  
   - 80–119 → "Rápido",  
   - 120 o más → "Demasiado rápido".  
   - Ejemplo:  
     - Entrada: `100` → Salida: `Rápido`  

9. **Clasificación de números por divisibilidad**  
   Leer un número entero e indicar:  
   - Si es múltiplo de 2 y 3 → "Múltiplo de 6",  
   - Si solo de 2 → "Múltiplo de 2",  
   - Si solo de 3 → "Múltiplo de 3",  
   - Ninguno → "No es múltiplo de 2 ni de 3".  
   - Ejemplo:  
     - Entrada: `9` → Salida: `Múltiplo de 3`  

10. **Número dentro de un rango**  
    Leer un número y verificar si está en el rango entre 10 y 50 (inclusive).  
    - Ejemplo:  
      - Entrada: `25` → Salida: `Dentro del rango`  

11. **Clasificación de notas (detallada)**  
    Ingresar una nota del 0 al 10 e imprimir:  
    - 0–3 → "Insuficiente"  
    - 4–5 → "Regular"  
    - 6–7 → "Bueno"  
    - 8–9 → "Muy bueno"  
    - 10 → "Excelente"  
    - Ejemplo:  
      - Entrada: `4` → Salida: `Regular`  

12. **Año bisiesto**  
    Leer un año y verificar si es bisiesto:  
    - Es bisiesto si es divisible por 4, pero no por 100,  
    - Excepto si también es divisible por 400.  
    - Ejemplo:  
      - Entrada: `2000` → Salida: `Bisiesto`  

13. **Tarifas de estacionamiento**  
    Dado el número de horas que un auto permanece en el estacionamiento:  
    - 1–2 horas → $50,  
    - 3–5 horas → $100,  
    - 6–10 horas → $200,  
    - Más de 10 horas → $500.  
    - Ejemplo:  
      - Entrada: `7` → Salida: `$200`  

---

## 🔹 Nivel 3: Ejercicios difíciles

1. **Ordenar tres números**  
   Ingresar tres números distintos e imprimirlos en orden ascendente.  
   - Ejemplo:  
     - Entrada: `8 2 5` → Salida: `2 5 8`  

2. **Tipo de triángulo (avanzado)**  
   Ingresar tres lados y determinar si el triángulo es:  
   - Equilátero (todos iguales),  
   - Isósceles (dos lados iguales),  
   - Escaleno (todos diferentes).  
   - Ejemplo:  
     - Entrada: `5 5 5` → Salida: `Equilátero`  

3. **Validar contraseña**  
   Definir una contraseña correcta en el código (por ejemplo: `"admin123"`) y pedir al usuario que la ingrese. Verificar si es correcta o no.  
   - Ejemplo:  
     - Entrada: `admin123` → Salida: `Acceso permitido`  

4. **Verificación de entrada a un evento**  
   Un usuario puede entrar a un evento si:  
   - Tiene entrada (valor 1), y  
   - Tiene más de 18 años.  
   - Ejemplo:  
     - Entrada: `Entrada=1, Edad=20` → Salida: `Puede ingresar`  

---
