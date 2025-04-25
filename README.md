# 🚗 Unidad 6 – MAVI

Ejercicios prácticos desarrollados en el marco de la materia **MAVI**, enfocados en la simulación de movimientos físicos (MRU, MRUV) y su aplicación en entornos interactivos.

## ⚙️ Tecnologías utilizadas

- **Lenguaje:** C++
- **Gráficos:** SFML

## 📚 Ejercicios

### 1️⃣ Fast & Furious

Simulación de un vehículo (círculo) que se mueve de izquierda a derecha con velocidad constante.  
Al salir por el borde derecho, reaparece por el izquierdo con **velocidad aumentada**.  
Se repite hasta alcanzar una velocidad final predefinida.

### 2️⃣ Space

Movimiento de un objeto con **aceleración variable controlada por el usuario**.  
Al presionar las teclas de dirección, el objeto acelera en esa dirección.  
Si se cambia de dirección, **primero desacelera**, se detiene, y luego acelera en sentido contrario.

### 3️⃣ Bounce

Esfera que cae afectada por la gravedad y rebota al tocar el suelo.  
El rebote puede simularse con:

- Velocidad constante
- Porcentaje de la velocidad previa a la colisión (rebote progresivamente menor)

### 4️⃣ Wild Physics

Versión física del TP “Wild Gang Shooter”.  
Ahora los enemigos se **mueven** en la pantalla con movimiento MRU o MRUV.  
Pueden caer desde arriba (pelotas) o desplazarse desde los laterales (disco).  
El jugador debe dispararles con el mouse para **sumar puntaje**.  
Se aplican conceptos de física y colisiones para mejorar la jugabilidad.

## 👨‍💻 Autor

**JulioCZ**  
2° Cuatrimestre – Año 2024  
Tecnicatura en Diseño y Programación de Videojuegos
